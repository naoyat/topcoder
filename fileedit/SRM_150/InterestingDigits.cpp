#line 2 "InterestingDigits.cpp"
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
#define pb  push_back

class InterestingDigits {
  int b;
  bool p(int n){
    // b*b % n, b % n, 1 % n
    if (b*b % n == 1 && b % n == 1) return true;
    return false;
  }
 public:
  vector <int> digits(int base) {
    b=base;
	vector<int> res;
    for(int n=1;n<base;n++) if (p(n)) res.pb(n);
    return res;
  }
};// 241.50

// BEGIN CUT HERE
#include <time.h>
clock_t start_time;
void timer_clear() { start_time = clock(); }
string timer() { clock_t end_time = clock(); double interval = (double)(end_time - start_time)/CLOCKS_PER_SEC; ostringstream os; os << " (" << interval*1000 << " msec)"; return os.str(); }

template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
int verify_case(const vector <int> &Expected, const vector <int> &Received) { if (Expected == Received) cerr << "PASSED" << timer() << endl; else { cerr << "FAILED" << timer() << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } return 0;}

template<int N> struct Case_ {};
char Test_(...);
int Test_(Case_<0>) {
	timer_clear();
	int base = 10; 
	int RetVal_[] = { 3,  9 };
	  vector <int> RetVal(RetVal_, RetVal_+sizeof(RetVal_)/sizeof(*RetVal_)); 
	return verify_case(RetVal, InterestingDigits().digits(base)); }
int Test_(Case_<1>) {
	timer_clear();
	int base = 3; 
	int RetVal_[] = { 2 };
	  vector <int> RetVal(RetVal_, RetVal_+sizeof(RetVal_)/sizeof(*RetVal_)); 
	return verify_case(RetVal, InterestingDigits().digits(base)); }
int Test_(Case_<2>) {
	timer_clear();
	int base = 9; 
	int RetVal_[] = { 2,  4,  8 };
	  vector <int> RetVal(RetVal_, RetVal_+sizeof(RetVal_)/sizeof(*RetVal_)); 
	return verify_case(RetVal, InterestingDigits().digits(base)); }
int Test_(Case_<3>) {
	timer_clear();
	int base = 26; 
	int RetVal_[] = { 5,  25 };
	  vector <int> RetVal(RetVal_, RetVal_+sizeof(RetVal_)/sizeof(*RetVal_)); 
	return verify_case(RetVal, InterestingDigits().digits(base)); }
int Test_(Case_<4>) {
	timer_clear();
	int base = 30; 
	int RetVal_[] = { 29 };
	  vector <int> RetVal(RetVal_, RetVal_+sizeof(RetVal_)/sizeof(*RetVal_)); 
	return verify_case(RetVal, InterestingDigits().digits(base)); }

template<int N> void Run_() { cerr << "Test Case #" << N << "..." << flush; Test_(Case_<N>()); Run_<sizeof(Test_(Case_<N+1>()))==1 ? -1 : N+1>(); }
template<>      void Run_<-1>() {}
int main() { Run_<0>(); }
// END CUT HERE


// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
The digits 3 and 9 share an interesting property.  If you take any multiple of 3 and sum its digits, you get another multiple of 3.
For example, 118*3 = 354 and 3+5+4 = 12, which is a multiple of 3.  Similarly, if you take any multiple of 9 and sum its digits, 
you get another multiple of 9.  For example, 75*9 = 675 and 6+7+5 = 18, which is a multiple of 9.  Call any digit for which this 
property holds interesting, except for 0 and 1, for which the property holds trivially.



A digit that is interesting in one base is not necessarily interesting in another base.  For example, 3 is interesting in base 10
but uninteresting in base 5.  Given an int base, your task is to return all the interesting digits for that base
in increasing order.  To determine whether a particular digit is interesting or not, you need not consider all multiples of the digit.  You can be certain that, if
the property holds for all multiples of the digit with fewer than four digits, then it also holds for multiples with more digits.
For example, in base 10, you would not need to consider any multiples greater than 999.



DEFINITION
Class:InterestingDigits
Method:digits
Parameters:int
Returns:vector <int>
Method signature:vector <int> digits(int base)


NOTES
-When base is greater than 10, digits may have a numeric value greater than 9.  Because integers are displayed in base 10 by default, do not be alarmed when such digits appear on your screen as more than one decimal digit.  For example, one of the interesting digits in base 16 is 15.


CONSTRAINTS
-base is between 3 and 30, inclusive.


EXAMPLES

0)
10

Returns: { 3,  9 }

All other candidate digits fail for base=10.  For example, 2 and 5 both fail on 100, for which 1+0+0=1.  Similarly, 4 and 8 both fail on 216, for which 2+1+6=9, and 
6 and 7 both fail for 126, for which 1+2+6=9.

1)
3

Returns: { 2 }

2)
9

Returns: { 2,  4,  8 }

3)
26

Returns: { 5,  25 }

4)
30

Returns: { 29 }

*/
// END CUT HERE
