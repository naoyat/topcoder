#line 2 "DoubleXor.cpp"
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

class DoubleXor {
  void set(int *c, int x){
    for(int i=6;i>=0;i--){
      c[i]=x%10; x/=10;
    }
  }
  int get(int *c){
    int x=0;
    rep(i,7){
      x*=10; x+=c[i];
    }
    return x;
  }
  void aa(int *a, int *b){
    rep(i,7) a[i] = (a[i] ^ b[i]) % 10;
  }
 public:
  int calculate(int N) {
    int a[7],b[7];
    set(a,N);
    for(int i=N-1;i>=1;i--){
      set(b,i);
      aa(a,b);
    }
    
    return get(a);
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
	int RetVal = 1; 
	return verify_case(RetVal, DoubleXor().calculate(N)); }
int Test_(Case_<1>) {
	timer_clear();
	int N = 2; 
	int RetVal = 3; 
	return verify_case(RetVal, DoubleXor().calculate(N)); }
int Test_(Case_<2>) {
	timer_clear();
	int N = 7; 
	int RetVal = 0; 
	return verify_case(RetVal, DoubleXor().calculate(N)); }
int Test_(Case_<3>) {
	timer_clear();
	int N = 10; 
	int RetVal = 11; 
	return verify_case(RetVal, DoubleXor().calculate(N)); }
int Test_(Case_<4>) {
	timer_clear();
	int N = 102; 
	int RetVal = 103; 
	return verify_case(RetVal, DoubleXor().calculate(N)); }
int Test_(Case_<5>) {
	timer_clear();
	int N = 1000000; 
	int RetVal = 1000000; 
	return verify_case(RetVal, DoubleXor().calculate(N)); }

template<int N> void Run_() { cerr << "Test Case #" << N << "..." << flush; Test_(Case_<N>()); Run_<sizeof(Test_(Case_<N+1>()))==1 ? -1 : N+1>(); }
template<>      void Run_<-1>() {}
int main() { Run_<0>(); }
// END CUT HERE


// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// Let us introduce a new operation called double xor, and use the operator ^^ to denote it.  For two integers A and B, A ^^ B is calculated as follows.  Take the decimal representations of A and B.  If they have different lengths, prepend the shorter one with leading zeros until they both have the same length.  Then, label the digits of A as a1, a2, Åc, an (from left to right) and the digits of B as b1, b2, ... , bn (from left to right).  C = A ^^ B will consist of the digits c1, c2, ... , cn (from left to right), where ci = (ai ^ bi) % 10, where ^ is the usual bitwise XOR operator (see notes for exact definition) and x % y is the remainder of x divided by y.  If C happens to have any extra leading zeroes, they are ignored.

For example, 8765 ^^ 2309 = 462 (c1 = (8 ^ 2) % 10 = 10 % 10 = 0, c2 = (7 ^ 3) % 10 = 4 % 10 = 4, c3 = (6 ^ 0) % 10 = 6 % 10 = 6, c4 = (5 ^ 9) % 10 = 12 % 10 = 2), and 5 ^^ 123 = 126 ("5" is prepended with two leading zeros to become "005").

When multiple ^^ operations occur in an expression, they must be evaluated from left to right.  For example, A ^^ B ^^ C means (A ^^ B) ^^ C.

You are given an int N.  Return the value of N ^^ (N - 1) ^^ (N - 2) ^^ Åc ^^ 1.

DEFINITION
Class:DoubleXor
Method:calculate
Parameters:int
Returns:int
Method signature:int calculate(int N)


NOTES
-If a and b are single bits then a ^ b is defined as (a + b) % 2. For two integers, A and B, in order to calculate A ^ B, they need to be represented in binary: A = (an...a1)2, B = (bn...b1)2 (if the lengths of their representations are different, the shorter one is prepended with the necessary number of leading zeroes). Then A ^ B = C = (cn...c1)2, where ci = ai ^ bi. For example, 10 ^ 3 = (1010)2 ^ (0011)2 = (1001)2 = 9.


CONSTRAINTS
-N will be between 1 and 1,000,000, inclusive.


EXAMPLES

0)
1

Returns: 1

This is simply 1.

1)
2

Returns: 3

2^^1=3

2)
7

Returns: 0

7^^6^^5^^4^^3^^2^^1=0

3)
10

Returns: 11

4)
102

Returns: 103



*/
// END CUT HERE
