// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// A positive integer is called a cool number of power A if it can be separated into exactly A groups of consecutive digits, where the digits in each group form an arithmetic progression.  An arithmetic progression is a sequence of numbers in which the difference between any two consecutive numbers is the same.  A positive integer is called a mega cool number of power A if it is a cool number of power A, not a cool number of power A-1, and all its digits are in non-decreasing order.

Determine the number of mega cool numbers of power A that contain exactly N digits (with no leading zeroes).  Return this number modulo 1,000,000,007.

DEFINITION
Class:MegaCoolNumbers
Method:count
Parameters:int, int
Returns:int
Method signature:int count(int N, int A)


CONSTRAINTS
-A and N will be between 1 and 1,000, inclusive. 


EXAMPLES

0)
1
1

Returns: 9

There 9 such numbers: 1, 2, 3, 4, 5, 6, 7, 8, 9.

1)
2
1

Returns: 45

Any two-digit number with non-decreasing digits will be a mega cool number of power 1.

2)
2
2

Returns: 0

There are no such numbers.

3)
10
3

Returns: 7502



*/
// END CUT HERE

#line 58 "MegaCoolNumbers.cpp"
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

class MegaCoolNumbers {
 public:
  int count(int N, int A) {
	
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
	int N = 1; 
	int A = 1; 
	int RetVal = 9; 
	return verify_case(RetVal, MegaCoolNumbers().count(N, A)); }
int Test_(Case_<1>) {
	timer_clear();
	int N = 2; 
	int A = 1; 
	int RetVal = 45; 
	return verify_case(RetVal, MegaCoolNumbers().count(N, A)); }
int Test_(Case_<2>) {
	timer_clear();
	int N = 2; 
	int A = 2; 
	int RetVal = 0; 
	return verify_case(RetVal, MegaCoolNumbers().count(N, A)); }
int Test_(Case_<3>) {
	timer_clear();
	int N = 10; 
	int A = 3; 
	int RetVal = 7502; 
	return verify_case(RetVal, MegaCoolNumbers().count(N, A)); }

template<int N> void Run_() { cerr << "Test Case #" << N << "..." << flush; Test_(Case_<N>()); Run_<sizeof(Test_(Case_<N+1>()))==1 ? -1 : N+1>(); }
template<>      void Run_<-1>() {}
int main() { Run_<0>(); }
// END CUT HERE

