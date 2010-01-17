#line 2 "MagicalSource.cpp"
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
#define sz(a)  int((a).size())
#define pb  push_back
#define all(c)  (c).begin(),(c).end()
#define rep(var,n)  for(int var=0;var<(n);var++)

class MagicalSource {
 public:
  long long calculate(long long x) {
    for(ll dn=111111111111LL; dn>=1LL; dn/=10LL) {
      if (x < dn) continue;
      if (x % dn == 0LL) return x/dn;
    }
    return x;
  }
};

// BEGIN CUT HERE
#include <time.h>
clock_t start_time;
void timer_clear() { start_time = clock(); }
string timer() { clock_t end_time = clock(); double interval = (double)(end_time - start_time)/CLOCKS_PER_SEC; ostringstream os; os << " (" << interval*1000 << " msec)"; return os.str(); }

template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
int verify_case(const long long &Expected, const long long &Received) { if (Expected == Received) cerr << "PASSED" << timer() << endl; else { cerr << "FAILED" << timer() << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } return 0;}

template<int N> struct Case_ {};
char Test_(...);
int Test_(Case_<0>) {
	timer_clear();
	long long x = 1371110974LL; 
	long long RetVal = 1234LL; 
	return verify_case(RetVal, MagicalSource().calculate(x)); }
int Test_(Case_<1>) {
	timer_clear();
	long long x = 111111LL; 
	long long RetVal = 1LL; 
	return verify_case(RetVal, MagicalSource().calculate(x)); }
int Test_(Case_<2>) {
	timer_clear();
	long long x = 10989LL; 
	long long RetVal = 99LL; 
	return verify_case(RetVal, MagicalSource().calculate(x)); }
int Test_(Case_<3>) {
	timer_clear();
	long long x = 120LL; 
	long long RetVal = 120LL; 
	return verify_case(RetVal, MagicalSource().calculate(x)); }
int Test_(Case_<4>) {
	timer_clear();
	long long x = 109999999989LL; 
	long long RetVal = 99LL; 
	return verify_case(RetVal, MagicalSource().calculate(x)); }
int Test_(Case_<5>) {
	timer_clear();
	long long x = 1LL; 
	long long RetVal = 1LL; 
	return verify_case(RetVal, MagicalSource().calculate(x)); }


template<int N> void Run_() { cerr << "Test Case #" << N << "..." << flush; Test_(Case_<N>()); Run_<sizeof(Test_(Case_<N+1>()))==1 ? -1 : N+1>(); }
template<>      void Run_<-1>() {}
int main() { Run_<0>(); }
// END CUT HERE


// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// Rick firmly believes that there are magical patterns related to some numbers. This belief is the result of his own tendency to find odd patterns everywhere. He has recently thought that some numbers have a "magical source". For example, the number 1371110974 has a magical source equal to 1234 because of the following process:


        1234
+      12340
+     123400
+    1234000
+   12340000
+  123400000
+ 1234000000
------------
  1371110974

Formally, 1234 is a magical source of 1371110974 because there exists a number n such that the sum of a sequence of n numbers, where the i-th number (0-indexed) is 1234 multipled by 10^i, is equal to 1371110974. Note that by this definition, a positive number is a magical source of itself.

Given a positive long long x, return its  minimum positive magical source.

DEFINITION
Class:MagicalSource
Method:calculate
Parameters:long long
Returns:long long
Method signature:long long calculate(long long x)


CONSTRAINTS
-x will be between 1 and 1000000000000 (10^12), inclusive.


EXAMPLES

0)
1371110974

Returns: 1234

This is the example from the statement.

1)
111111

Returns: 1



2)
10989

Returns: 99



3)
120

Returns: 120

Note that a number is always a magical source of itself.

4)
109999999989

Returns: 99



*/
// END CUT HERE
