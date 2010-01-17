// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
You are given two positive integers x and k. Return the k-th smallest positive integer y (where k is 1-based) for which the following equation holds:
x + y = x | y
where '|' denotes the bitwise OR operator.



DEFINITION
Class:BitwiseEquations
Method:kthPlusOrSolution
Parameters:int, int
Returns:long long
Method signature:long long kthPlusOrSolution(int x, int k)


CONSTRAINTS
-x will be between 1 and 2,000,000,000, inclusive.
-k will be between 1 and 2,000,000,000, inclusive.


EXAMPLES

0)
5
1

Returns: 2

The first positive integer for which the equation holds is 2.
You can check that 5+2=7 as well as 5|2=7. Both plus and bitwise OR look like the following:

 101
+ 10
 ---
 111



1)
5
5

Returns: 18

The fifth number for which the equation 5 + y = 5 | y holds is 18. The first four solutions are 2,8,10,16.
The binary sum for 18 looks like the following:

   101
+10010
 -----
 10111


2)
10
3

Returns: 5

The third solution is 5. The first two solutions are 1 and 4.


3)
1
1000000000

Returns: 2000000000



*/
// END CUT HERE

#line 78 "BitwiseEquations.cpp"
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

vector<int> to_bin(long long x)
{
  vector<int> bin;
  while (x > 0) {
	bin.push_back(x & 1); x >>= 1;
  }
  return bin;
}

class BitwiseEquations {
public:
  long long kthPlusOrSolution(int x, int k) {
	vector<int> xb = to_bin(x);
	vector<int> kb = to_bin(k);
// BEGIN CUT HERE
	//cout << "xb:" << xb << endl;
	//cout << "kb:" << kb << endl;
	//vector<int> ab(64,0);
// END CUT HERE
	long long a=0, m=1;
	int i = 0, j = 0;
	while (j < kb.size()) {
	  if (i >= xb.size() || xb[i++] == 0) {
		if (kb[j++]) a |= m;
	  }
	  m <<= 1;
		
	  //if (j > ki) break;
	}
	return a;
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
	int x = 5; 
	int k = 1; 
	long long RetVal = 2LL; 
	return verify_case(RetVal, BitwiseEquations().kthPlusOrSolution(x, k)); }
int Test_(Case_<1>) {
	timer_clear();
	int x = 5; 
	int k = 5; 
	long long RetVal = 18LL; 
	return verify_case(RetVal, BitwiseEquations().kthPlusOrSolution(x, k)); }
int Test_(Case_<2>) {
	timer_clear();
	int x = 10; 
	int k = 3; 
	long long RetVal = 5LL; 
	return verify_case(RetVal, BitwiseEquations().kthPlusOrSolution(x, k)); }
int Test_(Case_<3>) {
	timer_clear();
	int x = 1; 
	int k = 1000000000; 
	long long RetVal = 2000000000LL; 
	return verify_case(RetVal, BitwiseEquations().kthPlusOrSolution(x, k)); }
int Test_(Case_<4>) {
	timer_clear();
	int x = 1; 
	int k = 1; 
	long long RetVal = 2LL; 
	return verify_case(RetVal, BitwiseEquations().kthPlusOrSolution(x, k)); }
int Test_(Case_<5>) {
	timer_clear();
	int x = 2000000000;
	int k = 2000000000;
	long long RetVal = 16383165351936LL; 
	return verify_case(RetVal, BitwiseEquations().kthPlusOrSolution(x, k)); }

template<int N> void Run_() { cerr << "Test Case #" << N << "..." << flush; Test_(Case_<N>()); Run_<sizeof(Test_(Case_<N+1>()))==1 ? -1 : N+1>(); }
template<>      void Run_<-1>() {}
int main() { Run_<0>(); }
// END CUT HERE

