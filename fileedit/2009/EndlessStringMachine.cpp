#line 2 "EndlessStringMachine.cpp"
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
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<string> vs;
typedef vector<long long> vll;
#define sz(a)  int((a).size())
#define pb  push_back
#define all(c)  (c).begin(),(c).end()
#define mset(arr,val)  memset(arr,val,sizeof(arr))
#define tr(c,i)  for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); i++)
#define rep(var,n)  for(int var=0;var<(n);var++)
#define forr(var,from,to) for(int var=(from);var<=(to);var++) 
#define found(s,e)  ((s).find(e)!=(s).end())
#define remove_(c,val) (c).erase(remove((c).begin(),(c).end(),(val)),(c).end())
#define lastc(str) (*((str).end()-1))

class EndlessStringMachine {
  int inlen,prlen,dols,rest;
 public:
  string getFragment(string input, string program, int s, int mn, int mx) {
    cout << "getFragment(" << input << ", " << program << ", " << s << ", " << mn << ", " << mx << endl;
	inlen=sz(input), prlen=sz(program), dols=0,rest=prlen;
    rep(i,inlen) if(program[i]=='$'){dols++;rest--;}
    int w=inlen;

    int wne;
    rep(i,1000000){
      wne=dols*w + rest;
      //printf("s:%d; %d => %d\n",i, w,wne);
      w=wne;
    }
    printf(" %d => %d\n",w,wne);
    return "";
  }
};

// BEGIN CUT HERE
#include <time.h>
clock_t start_time;
void timer_clear() { start_time = clock(); }
string timer() { clock_t end_time = clock(); double interval = (double)(end_time - start_time)/CLOCKS_PER_SEC; ostringstream os; os << " (" << interval*1000 << " msec)"; return os.str(); }

template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
int verify_case(const string &Expected, const string &Received) { if (Expected == Received) cerr << "PASSED" << timer() << endl; else { cerr << "FAILED" << timer() << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } return 0;}

template<int N> struct Case_ {};
char Test_(...);
int Test_(Case_<0>) {
	timer_clear();
	string input = "a"; 
	string program = "$meric$"; 
	int s = 6; 
	int min = 1; 
	int max = 35; 
	string RetVal = "americamericamericamericamericameri"; 
	return verify_case(RetVal, EndlessStringMachine().getFragment(input, program, s, min, max)); }
int Test_(Case_<1>) {
	timer_clear();
	string input = "top"; 
	string program = "$coder"; 
	int s = 1; 
	int min = 1; 
	int max = 20; 
	string RetVal = "topcoder------------"; 
	return verify_case(RetVal, EndlessStringMachine().getFragment(input, program, s, min, max)); }
int Test_(Case_<2>) {
	timer_clear();
	string input = "abc"; 
	string program = "$x$y$z$"; 
	int s = 10; 
	int min = 30; 
	int max = 50; 
	string RetVal = "bcyabcxabcyabczabczab"; 
	return verify_case(RetVal, EndlessStringMachine().getFragment(input, program, s, min, max)); }
int Test_(Case_<3>) {
	timer_clear();
	string input = "xy"; 
	string program = "$a$bb"; 
	int s = 12; 
	int min = 5000; 
	int max = 5099; 
	string RetVal = "xybbbbaxyaxybbaxyaxybbbbbbbbaxyaxybbaxyaxybbbbaxyaxybbaxyaxybbbbbbaxyaxybbaxyaxybbbbaxyaxybbaxyaxybb"; 
	return verify_case(RetVal, EndlessStringMachine().getFragment(input, program, s, min, max)); }

int Test_(Case_<4>) {
	timer_clear();
	string input   = "abcdefghijklmnopqrstuvwxyabcdefghijklmnopqrstuvwxy";
	string program = "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$";
	int s   = 1000000000;
	int min = 1000000000;
	int max = 1000000099;
	string RetVal = "xybbbbaxyaxybbaxyaxybbbbbbbbaxyaxybbaxyaxybbbbaxyaxybbaxyaxybbbbbbaxyaxybbaxyaxybbbbaxyaxybbaxyaxybb"; 
	return verify_case(RetVal, EndlessStringMachine().getFragment(input, program, s, min, max)); }

template<int N> void Run_() { cerr << "Test Case #" << N << "..." << flush; Test_(Case_<N>()); Run_<sizeof(Test_(Case_<N+1>()))==1 ? -1 : N+1>(); }
template<>      void Run_<-1>() {}
int main() { Run_<0>(); }
// END CUT HERE


// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// A certain theoretical machine works by executing a program exactly s times.  The first time it is executed, the program is given the String input as its input.  For each subsequent execution, the program uses the output of the previous execution as its input.

The initial input is a string containing only lowercase letters.  A program is defined as a string containing lowercase letters and '$' characters.  The output of a program is simply this string with all instances of the '$' character replaced by the program's input.  For example, if the input is "a" and the program is "$meric$", the first output would be "america".  The second time it is executed, it will use "america" as its input, and its output will be "americamericamerica".  This process is repeated s times, so for a large s, the output would be: "americamericamericamericamericamericamericamericamericamericamericamericamericamericamerica...".

Given the input, the program and s, return the substring of the machine's final output starting at index min and ending at index max, where min and max are inclusive 1-based indices.  If an index between min and max exceeds the bounds of the final output, put a placeholder '-' character in its place.



DEFINITION
Class:EndlessStringMachine
Method:getFragment
Parameters:string, string, int, int, int
Returns:string
Method signature:string getFragment(string input, string program, int s, int min, int max)


CONSTRAINTS
-input will contain between 1 and 50 characters, inclusive.
-program will contain between 2 and 50 characters, inclusive.
-Each character in input will be a lowercase letter ('a'-'z').
-Each character in program will be '$' or a lowercase letter ('a'-'z').
-The first character in program will be '$'.
-s will be between 1 and 1000000000, inclusive.
-min will be between 1 and 1000000000, inclusive.
-max will be between min and min+99, inclusive.


EXAMPLES

0)
"a"
"$meric$"
6
1
35

Returns: "americamericamericamericamericameri"

This is the example from the statement.

1)
"top"
"$coder"
1
1
20

Returns: "topcoder------------"

One execution is not enough to cover all 20 requested characters. Use the placeholder - character for the indexes that exceed the final output's size.

2)
"abc"
"$x$y$z$"
10
30
50

Returns: "bcyabcxabcyabczabczab"



3)
"xy"
"$a$bb"
12
5000
5099

Returns: "xybbbbaxyaxybbaxyaxybbbbbbbbaxyaxybbaxyaxybbbbaxyaxybbaxyaxybbbbbbaxyaxybbaxyaxybbbbaxyaxybbaxyaxybb"



*/
// END CUT HERE
