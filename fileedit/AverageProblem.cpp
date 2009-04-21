#line 2 "AverageProblem.cpp"
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <cctype>
#include <algorithm>
#include <string>
#include <vector>
#include <deque>
#include <stack>
#include <queue>
#include <list>
#include <map>
#include <set>
// BEGIN CUT HERE
#include "cout.h"
// END CUT HERE
using namespace std;
#define sz(a)  int((a).size())
#define pb  push_back
#define all(c)  (c).begin(),(c).end()
#define tr(c,i)  for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); i++)
#define rep(var,n)  for(int var=0;var<(n);var++)
#define found(s,e)  ((s).find(e)!=(s).end())

vector<string> split(string str, int delim=' ')
{
  vector<string> result;

  const char *s = str.c_str();
  if (delim == ' ') {
    for (const char *p=s; *p; p++) {
      if (*p == delim)
        s++;
      else
        break;
    }
    if (!*s) return result;

    for (const char *p=s; *p; p++) {
      if (*p == delim) {
        if (s < p) {
          string a(s,p-s);
          result.push_back(a);
        }
        s = p + 1;
      }
    }
    if (*s) result.push_back(s);
  } else {
    for (const char *p=s; *p; p++) {
      if (*p == delim) {
        string a(s,p-s);
        result.push_back(a);
        s = p + 1;
        if (*s == '\0') result.push_back("");
      }
    }
    if (*s) result.push_back(s);
  }

  return result;
}

class AverageProblem {
 public:
  int numberOfParticipants(vector<string> marks) {
    set<int> s;
	tr(marks,it){
      vector<string> m_ = split(*it);
      tr(m_,jt) s.insert((int)(1000 * atof(jt->c_str()) + 0.5));
    }

// BEGIN CUT HERE
    //    cout << s << endl;
// END CUT HERE
    for(int ps=1;;ps++){
      set<int> s_;
      // 0-10, ps
      double u = 1000.0 / ps;
      for(int i=0;i<=ps*10;i++) s_.insert((int)(u*i+0.0000001));
      //for(int i=0;i<=ps*10;i++) s_.insert((int)(1.0 * i / ps));
// BEGIN CUT HERE
      //      cout << "ps=" << ps << ", " << s_ << endl;
// END CUT HERE
      tr(s,it){
        if (!found(s_,*it)) goto next;
      }
      return ps;
   next:;
    }
  }
};

// BEGIN CUT HERE
#include <time.h>
clock_t start_time;
void timer_clear() { start_time = clock(); }
string timer() { clock_t end_time = clock(); double interval = (double)(end_time - start_time)/CLOCKS_PER_SEC; ostringstream os; os << " (" << interval*1000 << " msec)"; return os.str(); }

template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
int verify_case(const int &Expected, const int &Received) { if (Expected == Received) cerr << "PASSED" << timer() << endl; else { cerr << "FAILED" << timer() << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } return 0;}

template<int N> struct Case_ {};
char Test_(...);
int Test_(Case_<0>) {
	timer_clear();
	string marks_[] = {"0.000"};
	  vector <string> marks(marks_, marks_+sizeof(marks_)/sizeof(*marks_)); 
	int RetVal = 1; 
	return verify_case(RetVal, AverageProblem().numberOfParticipants(marks)); }
int Test_(Case_<1>) {
	timer_clear();
	string marks_[] = {"0.500 0.250", "0.125"};
	  vector <string> marks(marks_, marks_+sizeof(marks_)/sizeof(*marks_)); 
	int RetVal = 8; 
	return verify_case(RetVal, AverageProblem().numberOfParticipants(marks)); }
int Test_(Case_<2>) {
	timer_clear();
	string marks_[] = {"0.500","0.300"};
	  vector <string> marks(marks_, marks_+sizeof(marks_)/sizeof(*marks_)); 
	int RetVal = 10; 
	return verify_case(RetVal, AverageProblem().numberOfParticipants(marks)); }
int Test_(Case_<3>) {
	timer_clear();
	string marks_[] = {"0.500","0.301"};
	  vector <string> marks(marks_, marks_+sizeof(marks_)/sizeof(*marks_)); 
	int RetVal = 106; 
	return verify_case(RetVal, AverageProblem().numberOfParticipants(marks)); }
int Test_(Case_<4>) { // 7
	timer_clear();
	string marks_[] = {"1.234 5.678","9.876"};
    vector <string> marks(marks_, marks_+sizeof(marks_)/sizeof(*marks_)); 
	int RetVal = 252; 
	return verify_case(RetVal, AverageProblem().numberOfParticipants(marks)); }
int Test_(Case_<5>) { // 65
	timer_clear();
	string marks_[] = {"1.513 9.249"};
    vector <string> marks(marks_, marks_+sizeof(marks_)/sizeof(*marks_)); 
	int RetVal = 253;
	return verify_case(RetVal, AverageProblem().numberOfParticipants(marks)); }
int Test_(Case_<6>) { // 28
	timer_clear();
	string marks_[] = {"2.623 8.492", "1.460 0.146 0.720 1.313", "3.376 7.181", "2.649 7.039", "7.733 6.750", "4.218 1.046", "1.957 9.674 4.282 0.847 2.360 9.012 6.381", "7.552 6.885"};
    vector <string> marks(marks_, marks_+sizeof(marks_)/sizeof(*marks_)); 
	int RetVal = 804;
	return verify_case(RetVal, AverageProblem().numberOfParticipants(marks)); }

template<int N> void Run_() { cerr << "Test Case #" << N << "..." << flush; Test_(Case_<N>()); Run_<sizeof(Test_(Case_<N+1>()))==1 ? -1 : N+1>(); }
template<>      void Run_<-1>() {}
int main() { Run_<0>(); }
// END CUT HERE


// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// You are given the results of a sociological survey containing several questions.  Each participant was required to answer each question with an integer between 0 and 10, inclusive.  You are given the average answer for each question, but the decimal portion of each average is truncated after the first three digits.  For example, if there were three participants and their answers to a particular question were 4, 6 and 10, the average for that question would be given to you as 6.666.

You are given a vector <string> marks.  Each element of marks is a single space delimited list of numbers.  Each number in marks is the average answer for a survey question.  Return the minimum possible number of participants that could have taken this survey.

DEFINITION
Class:AverageProblem
Method:numberOfParticipants
Parameters:vector <string>
Returns:int
Method signature:int numberOfParticipants(vector <string> marks)


CONSTRAINTS
-marks will contain between 1 and 50 elements, inclusive.
-Each element of marks will contain between 5 and 50 characters, inclusive.
-Each element of marks will be a single space separated list of numbers, where each number is between 0 and 10, inclusive, contains no extra leading zeroes, and contains exactly one decimal point followed by exactly 3 digits.
-marks will contain between 1 and 50 numbers, inclusive.


EXAMPLES

0)
{"0.000"}

Returns: 1

There will always be at least one participant. In this case, the smallest number of participants that could have produced this result is 1.

1)
{"0.500 0.250", "0.125"}

Returns: 8



2)
{"0.500","0.300"}

Returns: 10



3)
{"0.500","0.301"}

Returns: 106



*/
// END CUT HERE
