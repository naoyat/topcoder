// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// You are given two strings s1 and s2. Each string contains some letters and exactly one asterisk ('*').

You must replace each asterisk with a sequence of letters (possibly of zero length). The resulting two strings must be equal.

Return the shortest possible resulting string. If it is impossible to make the strings equal, return "impossible" (quotes for clarity) instead.

DEFINITION
Class:TwoStringMasks
Method:shortestCommon
Parameters:string, string
Returns:string
Method signature:string shortestCommon(string s1, string s2)


CONSTRAINTS
-s1 will contain between 1 and 50 characters, inclusive.
-s2 will contain between 1 and 50 characters, inclusive.
-s1 and s2 will contain only uppercase letters ('A'-'Z') and asterisks ('*').
-s1 and s2 will contain exactly one asterisk each.


EXAMPLES

0)
"TOPC*DER"
"T*PCODER"

Returns: "TOPCODER"

Each of the asterisks should be replaced with an "O".

1)
"HELLO*"
"HI*"

Returns: "impossible"

No matter how you replace the asterisks, the second characters of the strings will differ. So it is impossible to make the strings equal.

2)
"GOOD*LUCK"
"*"

Returns: "GOODLUCK"

The first asterisk should be replaced with an empty string.

3)
"*SAMPLETEST"
"THIRDSAMPLE*"

Returns: "THIRDSAMPLETEST"



4)
"*TOP"
"*CODER"

Returns: "impossible"



5)
"*"
"A*"

Returns: "A"



6)
"*A"
"B*"

Returns: "BA"



7)
"LASTCASE*"
"*LASTCASE"

Returns: "LASTCASE"



*/
// END CUT HERE

#line 95 "TwoStringMasks.cpp"
#include <string>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <algorithm>
// BEGIN CUT HERE
#include <iostream>
#include "cout.h"
// END CUT HERE
#include <sstream>
#include <cmath>
using namespace std;

#define sz(a)  int((a).size())
#define pb  push_back
#define all(c)  (c).begin(),(c).end()
#define tr(c,i)  for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); i++)
#define rep(var,n)  for(int var=0;var<(n);var++)
#define found(s,e)  ((s).find(e)!=(s).end())
#define remove_(c,val) (c).erase(remove((c).begin(),(c).end(),(val)),(c).end())

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

class TwoStringMasks {
public:
  string shortestCommon(string s1, string s2) {
    vector<string> v1 = split(s1,'*'), v2 = split(s2,'*');
    int l1a=v1[0].length(), l1b=v1[1].length(),
      l2a=v2[0].length(), l2b=v2[1].length();
    int coma=min(l1a,l2a), comb=min(l1b,l2b);
    if(coma>0){
      if (v1[0].substr(0,coma)!=v2[0].substr(0,coma)) return "impossible";
    }
    if(comb>0){
      if (v1[1].substr(l1b-comb)!=v2[1].substr(l2b-comb)) return "impossible";
    }

    string prefix = v1[0].substr(0,coma), suffix = v1[1].substr(l1b-comb);
    v1[0]=v1[0].substr(coma); l1a-=coma;
    v2[0]=v2[0].substr(coma); l2a-=coma;
    v1[1]=v1[1].substr(0,l1b-comb); l1b-=comb;
    v2[1]=v2[1].substr(0,l2b-comb); l2b-=comb;
    string a=(l1a>l2a)?v1[0]:v2[0], b=(l1b>l2b)?v1[1]:v2[1];
    if ((l1a>=l2a && l1b>=l2b) || (l1a<l2a && l1b<l2b)) return prefix + a + b + suffix;

    int al=a.length(), bl=b.length();
    for(int l=min(al,bl);l>0;l--) {
      if (a.substr(al-l)==b.substr(0,l))
        return prefix + a + b.substr(l) + suffix;
    }
    return prefix + a + b + suffix;
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
	string s1 = "TOPC*DER"; 
	string s2 = "T*PCODER"; 
	string RetVal = "TOPCODER"; 
	return verify_case(RetVal, TwoStringMasks().shortestCommon(s1, s2)); }
int Test_(Case_<1>) {
	timer_clear();
	string s1 = "HELLO*"; 
	string s2 = "HI*"; 
	string RetVal = "impossible"; 
	return verify_case(RetVal, TwoStringMasks().shortestCommon(s1, s2)); }
int Test_(Case_<2>) {
	timer_clear();
	string s1 = "GOOD*LUCK"; 
	string s2 = "*"; 
	string RetVal = "GOODLUCK"; 
	return verify_case(RetVal, TwoStringMasks().shortestCommon(s1, s2)); }
int Test_(Case_<3>) {
	timer_clear();
	string s1 = "*SAMPLETEST"; 
	string s2 = "THIRDSAMPLE*"; 
	string RetVal = "THIRDSAMPLETEST"; 
	return verify_case(RetVal, TwoStringMasks().shortestCommon(s1, s2)); }
int Test_(Case_<4>) {
	timer_clear();
	string s1 = "*TOP"; 
	string s2 = "*CODER"; 
	string RetVal = "impossible"; 
	return verify_case(RetVal, TwoStringMasks().shortestCommon(s1, s2)); }
int Test_(Case_<5>) {
	timer_clear();
	string s1 = "*"; 
	string s2 = "A*"; 
	string RetVal = "A"; 
	return verify_case(RetVal, TwoStringMasks().shortestCommon(s1, s2)); }
int Test_(Case_<6>) {
	timer_clear();
	string s1 = "*A"; 
	string s2 = "B*"; 
	string RetVal = "BA"; 
	return verify_case(RetVal, TwoStringMasks().shortestCommon(s1, s2)); }
int Test_(Case_<7>) {
	timer_clear();
	string s1 = "LASTCASE*"; 
	string s2 = "*LASTCASE"; 
	string RetVal = "LASTCASE"; 
	return verify_case(RetVal, TwoStringMasks().shortestCommon(s1, s2)); }
int Test_(Case_<8>) {
	timer_clear();
	string s1 = "ADFSD*DFGDFF";
	string s2 = "ADF*DFF";
	string RetVal = "ADFSDDFGDFF";
	return verify_case(RetVal, TwoStringMasks().shortestCommon(s1, s2)); }
int Test_(Case_<9>) {
  timer_clear();
  string s1 = "ABCDB*XY";
  string s2 = "ABC*AXY";
  string RetVal = "ABCDBAXY";
  return verify_case(RetVal, TwoStringMasks().shortestCommon(s1, s2)); }

template<int N> void Run_() { cerr << "Test Case #" << N << "..." << flush; Test_(Case_<N>()); Run_<sizeof(Test_(Case_<N+1>()))==1 ? -1 : N+1>(); }
template<>      void Run_<-1>() {}
int main() { Run_<0>(); }
// END CUT HERE

