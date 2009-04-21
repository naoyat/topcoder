// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
You are writing a simple text editor that supports only the following two commands: 

"type c" where c is a character: Append character c to the end of the current text.
"undo t" where t is an integer: Undo all operations that were performed in the previous t seconds in reverse order.



All quotes are for clarity only.  The text in the editor is initially empty.


For example, consider the following sequence of commands:


Second 1: type a
Second 2: type b
Second 3: type c
Second 5: undo 3


At the end of second 3, the text is "abc".  At second 5, all commands performed in the previous 3 seconds are undone in reverse order.  This means 'c' is removed, and then 'b' is removed.  The text becomes just "a".


Note that "undo" commands can also be undone.  For example:


Second 1: type a
Second 2: type b
Second 3: undo 2
Second 4: undo 2


After second 2, the text is "ab".  After second 3, everything is undone, and the text becomes empty.  At second 4, the previous "undo" is undone, so the text becomes "ab" again.  Then, the "type b" is also undone and the text becomes just "a".


You are given a vector <string> commands and a vector <int> time.  Each element of commands is a single command, and commands[i] is performed at time[i].  The commands are given in chronological order.  Return the text after all the commands are executed.


DEFINITION
Class:Undo
Method:getText
Parameters:vector <string>, vector <int>
Returns:string
Method signature:string getText(vector <string> commands, vector <int> time)


CONSTRAINTS
-commands will contain between 1 and 50 elements, inclusive.
-Each element of commands will be either "type c" where c is a lowercase letter ('a'-'z') or "undo t" where t is an integer between 1 and 10^9, inclusive, with no leading zeroes (quotes for clarity only).
-time will contain the same number of elements as commands.
-Each element of time will be between 1 and 10^9, inclusive.
-The elements of time will be in strictly ascending order.


EXAMPLES

0)
{"type a", "type b", "type c", "undo 3"}
{1, 2, 3, 5}

Returns: "a"

The first example from the problem statement.

1)
{"type a", "type b", "undo 2", "undo 2"}
{1,2,3,4}

Returns: "a"

The second example from the problem statement.

2)
{"type a", "undo 1", "undo 1"}
{1,2,3}

Returns: "a"



3)
{"type a", "type b", "type c", "undo 10"}
{1, 2, 3, 1000}

Returns: "abc"

Note that "undo" can undo nothing if it is too late.

4)
{"undo 1"}
{1}

Returns: ""



*/
// END CUT HERE

#line 104 "Undo.cpp"
#include <string>
#include <vector>
// BEGIN CUT HERE
#include <iostream>
// END CUT HERE
#include <sstream>
using namespace std;

#define NOP_CMD 0
#define TYPE_CMD 1
#define UNDO_CMD 2

class Command {
  int mType;
  int mOperand;
  int mTime;
public:
  Command() { mType = NOP_CMD; }

  void set(string command, int time) {
	if (command.at(0) == 't') {
	  mType = TYPE_CMD;
	  mOperand = command.at(5); 
	} else {
	  mType = UNDO_CMD;
	  mOperand = atoi(command.c_str() + 5);
	}
	mTime = time;
  }
  int type() { return mType; }
  int operand() { return mOperand; }
  int time() { return mTime; }
  void nop() { mType = NOP_CMD; }
// BEGIN CUT HERE
  void dump() {
	switch (mType) {
	case TYPE_CMD:
	  cout << mTime << ") type " << mOperand << endl;
	  break;
	case UNDO_CMD:
	  cout << mTime << ") undo " << mOperand << endl;
	  break;
	case NOP_CMD:
	  cout << mTime << ") --- " << endl;
	  break;
	}
  }
// END CUT HERE
};

class Undo {
	public:
	string getText(vector<string> commands, vector<int> time) {
	  int cs = commands.size();
	  // vector<Command> cmd(cs);
	  Command cmd[cs];

	  for (int i=0; i<cs; i++) cmd[i].set( commands[i], time[i] );

	  for (int i=cs-1; i>=0; i--) {
		if (cmd[i].type() == UNDO_CMD) {
		  int since = cmd[i].time() - cmd[i].operand();
		  for (int j=i; j>=0; j--) {
			if (cmd[j].time() >= since) cmd[j].nop();
		  }
		}
	  }
	  
// BEGIN CUT HERE
	  for (int i=0; i<cs; i++) cmd[i].dump();
// END CUT HERE
	  char buf[cs+1], *p = buf;
	  for (int i=0; i<cs; i++) {
		if (cmd[i].type() == TYPE_CMD) {
		  *p++ = cmd[i].operand();
		}
		*p = 0;
	  }
	  string result = buf;
	  return result;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"type a", "type b", "type c", "undo 3"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 2, 3, 5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "a"; verify_case(0, Arg2, getText(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"type a", "type b", "undo 2", "undo 2"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,2,3,4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "a"; verify_case(1, Arg2, getText(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"type a", "undo 1", "undo 1"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,2,3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "a"; verify_case(2, Arg2, getText(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"type a", "type b", "type c", "undo 10"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 2, 3, 1000}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "abc"; verify_case(3, Arg2, getText(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"undo 1"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = ""; verify_case(4, Arg2, getText(Arg0, Arg1)); }
  void test_case_5() { string Arr0[] = {"type a", "undo 1000000000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = ""; verify_case(5, Arg2, getText(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	Undo ___test;
	___test.run_test(-1);
}
// END CUT HERE
