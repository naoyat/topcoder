package tangentz;

import java.util.HashMap;
import java.util.Map;

import com.topcoder.client.contestant.ProblemComponentModel;
import com.topcoder.shared.language.Language;
import com.topcoder.shared.problem.*;


/**
 * @author TangentZ
 *
 * This tester class is for C++ only.  It is based on PopsProcessor which is written for Java.
 * It reads in all the given examples for a problem and generates the equivalent C++ code
 * to test all the cases.  The accumulated running time is 8 seconds, but it is easy to
 * selectively run a specific case only.
 *
 * This tester will define three tags that can be embedded within PopsEdit/FileEdit code template:
 *    $WRITERCODE$ - place holder for writer code - will be blank if none found
 *    $PROBLEM$ - place holder for problem description as plain text
 *    $RUNTEST$ - place holder for where to put the code that starts the test
 *    $TESTCODE$ - place holder for where to put the test code
 */
public class TZTester
    {
    // Map used to store my tags
    private HashMap<String,String> m_Tags = new HashMap<String,String>();
	
    // Constants
    private static final String k_WRITERCODE    = "$WRITERCODE$";
    private static final String k_PROBLEM       = "$PROBLEM$";
    private static final String k_RUNTEST       = "$RUNTEST$";
    private static final String k_TESTCODE      = "$TESTCODE$";
    private static final String k_VERSION       = "\n// Powered by TZTester 1.01 [25-Feb-2003] customized by cafelier, timer support by naoya_t";
    
    // Cut tags
    private static final String k_BEGINCUT      = "// BEGIN CUT HERE\n";
    private static final String k_ENDCUT        = "// END CUT HERE\n";

    // Problem-related variables
    private ProblemComponentModel   m_Problem   = null;
    private Language                m_Language  = null;
    
    /**
     * PreProcess the source code
     * 
     * First determines if it is saved code, writer code, or nothing and stores it in $WRITERCODE$ tag
     * Secondly builds a main method with default test cases
     */
    public String preProcess(String Source, ProblemComponentModel Problem, Language Lang, Renderer Render)
        {
        // Set defaults for the tags in case we exit out early
        m_Tags.put(k_WRITERCODE, "");
        m_Tags.put(k_PROBLEM, "");
        m_Tags.put(k_RUNTEST, "");
        m_Tags.put(k_TESTCODE, "");
        
        // If there is source and the source is NOT equal to the default solution, return it
        if ((Source.length() > 0) && !Source.equals(Problem.getDefaultSolution()))
            return Source;
        // end if
        
        // Check to see if the component has any signature 
        if (!Problem.hasSignature())
            {
            m_Tags.put(k_RUNTEST, "// *** WARNING *** Problem has no signature defined for it");
            m_Tags.put(k_TESTCODE, "// *** WARNING *** Problem has no signature defined for it");
            return "";
            }
        // end if
        
        // Get the test cases
        TestCase[] TestCases = Problem.getTestCases();

        // Check to see if test cases are defined
        if ((TestCases == null) || (TestCases.length == 0))
            {
            m_Tags.put(k_RUNTEST, "// *** WARNING *** No test cases defined for this problem");
            m_Tags.put(k_TESTCODE, "// *** WARNING *** No test cases defined for this problem");
            return "";
            }
        // end if
        
        // Re-initialize the tags
        m_Tags.clear();
        m_Tags.put(k_WRITERCODE, Problem.getDefaultSolution());
        try { m_Tags.put(k_PROBLEM, Render.toPlainText(m_Language)); } catch (Exception Ex) { }

        m_Problem = Problem;
        m_Language = Lang;

        // Generate the code to run test cases
        generate_run_test_code();

        // Generate the test cases
        generate_test_code();

        return "";
        }
    // end of preProcess

    /**
     * This method will cut the test methods above out
     */
    public String postProcess(String Source, Language Lang)
        {
        StringBuffer Buffer = new StringBuffer(Source);

        // Insert a version string
        Buffer.append(k_VERSION);

        return Buffer.toString();
        }
    // end of postProcess

    /**
     * This method will return my tags.  This method is ALWAYS called after preProcess()
     * 
     * @return a map of my tags
     */
    public Map getUserDefinedTags()
        {
        return m_Tags;
        }
    // end of getUserDefinedTags

    /**
     * This method will generate the code to run the test cases.
     */
    private void generate_run_test_code()
        {
        StringBuffer Code = new StringBuffer();

        // Use a static variable to avoid infinite recursion
        Code.append("\t\tstatic bool s_FirstTime = true; if (s_FirstTime) { s_FirstTime = false; run_test(-1); }");

        // Insert the cut tags
        Code.insert(0, k_BEGINCUT);
        Code.append(k_ENDCUT);

        m_Tags.put(k_RUNTEST, Code.toString());
        }
    // end of generate_run_test_code

    /**
     * This method will generate the code for the test cases.
     */
    private void generate_test_code()
        {
        int I;
        DataType[] ParamTypes = m_Problem.getParamTypes();
        DataType ReturnType = m_Problem.getReturnType();
        TestCase[] Cases = m_Problem.getTestCases();
        StringBuffer Code = new StringBuffer();

        // <<modified by naoya_t>> : timer
        Code.append("#include <time.h>\n");
        Code.append("clock_t start_time;\n");
        Code.append("void timer_clear() { start_time = clock(); }\n");
        Code.append("string timer() { clock_t end_time = clock(); double interval = (double)(end_time - start_time)/CLOCKS_PER_SEC; ostringstream os; os << \" (\" << interval*1000 << \" msec)\"; return os.str(); }\n");
        Code.append("\n");

        // <<modified by cafelier>> : new test code template

        // Generate the vector output function
        Code.append("template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << \"{ \"; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << \'\\\"\' << *iter << \"\\\",\"; os << \" }\"; return os.str(); }\n");

        // Generate the verification function
        generate_verification_code(Code, ReturnType);

        // Generate the individual test cases
        Code.append("\n");
        Code.append("template<int N> struct Case_ {};\n");
        Code.append("char Test_(...);\n");
        for (I = 0; I < Cases.length; ++I)
            generate_test_case(I, Code, ParamTypes, ReturnType, Cases[I]);
        Code.append("\n");

        // Generate the test runner
        Code.append("template<int N> void Run_() { cerr << \"Test Case #\" << N << \"...\" << flush; Test_(Case_<N>()); Run_<sizeof(Test_(Case_<N+1>()))==1 ? -1 : N+1>(); }\n" );
        Code.append("template<>      void Run_<-1>() {}\n");
        Code.append("int main() { Run_<0>(); }\n" );

/*
        Code.append("\tpublic:\n");

        //
        // Generate the test wrapper function that can call
        // either all or individual test cases.  (-1 for all)
        //
        Code.append("\tvoid run_test(int Case) { ");

        // Check which case should be called
        for (I = 0; I < Cases.length; ++I)
            Code.append("if ((Case == -1) || (Case == " + I + ")) test_case_" + I + "(); ");
        // next

        Code.append("}\n");

        Code.append("\tprivate:\n");

        // Generate the vector output function
        Code.append("\ttemplate <typename T> string print_array(const vector<T> &V) { ostringstream os; os << \"{ \"; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << \'\\\"\' << *iter << \"\\\",\"; os << \" }\"; return os.str(); }\n");

        // Generate the verification function
        generate_verification_code(Code, ReturnType);

        // Generate the individual test cases
        for (I = 0; I < Cases.length; ++I)
            generate_test_case(I, Code, ParamTypes, ReturnType, Cases[I]);
        // next
*/
        // Insert the cut tags
        Code.insert(0, k_BEGINCUT);
        Code.append(k_ENDCUT);

        m_Tags.put(k_TESTCODE, Code.toString());
        }
    // end of generate_run_test_code

    /**
     * This method will generate the code for verifying test cases.
     */
    private void generate_verification_code(StringBuffer Code, DataType ReturnType)
        {
        String TypeString = ReturnType.getDescriptor(m_Language);

        // <<modified by cafelier>> : new test code template
        Code.append("int verify_case(const " + TypeString + " &Expected, const " + TypeString + " &Received) { ");
/*
        Code.append("\tvoid verify_case(int Case, const " + TypeString + " &Expected, const " + TypeString + " &Received) { ");

        Code.append("cerr << \"Test Case #\" << Case << \"...\"; ");
*/
        // Print "PASSED" or "FAILED" based on the result
		if (TypeString.equals("double")) {
			Code.append("double diff = Expected - Received; if (diff < 0) diff = -diff; ");
			Code.append("if (diff < 1e-9) cerr << \"PASSED\" << timer() << endl; ");
		} else {
			Code.append("if (Expected == Received) cerr << \"PASSED\" << timer() << endl; ");
		}
        Code.append("else { cerr << \"FAILED\" << timer() << endl; ");

        if (ReturnType.getDimension() == 0)
            {
            Code.append("cerr << \"\\tExpected: \\\"\" << Expected << \'\\\"\' << endl; ");
            Code.append("cerr << \"\\tReceived: \\\"\" << Received << \'\\\"\' << endl; }");
            }
        else
            {
            Code.append("cerr << \"\\tExpected: \" << print_array(Expected) << endl; ");
            Code.append("cerr << \"\\tReceived: \" << print_array(Received) << endl; }");
            }
        // end if

        // <<modified by cafelier>> : new test code template
        Code.append(" return 0;}\n");
        }
    // end of generate_verification_code

    /**
     * This method will generate the code for one test case.
     */
    private void generate_test_case(int Index, StringBuffer Code, DataType[] ParamTypes, DataType ReturnType, TestCase Case)
        {
        int I;
        String[] Inputs = Case.getInput();
        String Output = Case.getOutput();
        String Desc = ReturnType.getDescription();

        /*
         * Generate code for setting up individual test cases
         * and calling the method with these parameters.
        */

        // <<modified by cafelier>> : new test code template
        Code.append("int Test_(Case_<" + Index + ">) {\n");
        Code.append("\ttimer_clear();\n");
        // Generate each input variable separately
        for (I = 0; I < Inputs.length; ++I) {
            Code.append("\t");
            generate_parameter(I, Code, ParamTypes[I], Inputs[I]);
            Code.append("\n");
        }
        // Generate the output variable as the last variable
        Code.append("\t");
        generate_parameter(-1, Code, ReturnType, Output);
        Code.append("\n");
/*
        Code.append("void test_case_" + Index + "() { ");

        // Generate each input variable separately
        for (I = 0; I < Inputs.length; ++I)
            generate_parameter(I, Code, ParamTypes[I], Inputs[I]);
        // next

        // Generate the output variable as the last variable
        generate_parameter(Inputs.length, Code, ReturnType, Output);
*/

        // <<modified by cafelier>> : new test code template
        Code.append("\treturn verify_case(RetVal, "
          + m_Problem.getClassName() + "()."
          + m_Problem.getMethodName() + "(");
/*
        Code.append("verify_case(" + Index + ", Arg" + Inputs.length + ", " + m_Problem.getMethodName() + "(");
*/
        // Generate the function call list
        for (I = 0; I < Inputs.length; ++I)
            {
              Code.append(m_Problem.getParamNames()[I]);
//            Code.append("Arg" + I);

            if (I < (Inputs.length - 1))
                Code.append(", ");
            // end if
            }
        // next

        Code.append(")); }\n");
        }
    // end of generate_run_test_code

    /**
     * This method will generate the required parameter as a unique variable.
     */
    private void generate_parameter(int Index, StringBuffer Code, DataType ParamType, String Input)
        {
        String Desc = ParamType.getBaseName();

        // <<modified by cafelier>> : new code template
        String Name = (Index==-1 ? "RetVal" : m_Problem.getParamNames()[Index]);
        if(Index==-1) Index=9;

        if (ParamType.getDimension() == 0)
            {
            // Just a scalar value, simply initialize it at declaration (long integers need an 'L' tagged on)
            if (Desc.equals("long") || Desc.equals("Long"))
                Code.append(ParamType.getDescriptor(m_Language) + " " + Name + " = " + Input + "LL; ");
            else
                Code.append(ParamType.getDescriptor(m_Language) + " " + Name + " = " + Input + "; ");
            // end if
            }
        else
            {
              // <<modified by cafelier>> : empty array
              if( Input.matches("^[\\s\\{\\}]*$") )
              {
                Code.append(ParamType.getDescriptor(m_Language) + " " + Name + "; ");
              }
              else
              {
                // Arrays need to be converted to vector<type> before passing
                Code.append(ParamType.getBaseName().toLowerCase() + " " + Name + "_[] = " + Input + ";\n\t");
                Code.append("  "+ParamType.getDescriptor(m_Language) + " " + Name + "(" + Name + "_, " + Name + "_+sizeof("+Name+"_)/sizeof(*"+Name+"_)); ");
              }
            }
        // end if
        }
    // end of generate_parameter
    }
// end of TZTester

