// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
Division is an expensive operation for a computer to perform, compared to addition, subtraction, and even multiplication.
The exception is when dividing by powers of 2, because this can be done either with a bit shift (for a fixed-point value) or by subtracting 1 from the exponent (for a floating-point value).
In this problem, we will approximate the quotient of two numbers using only addition, multiplication, and division by powers of 2.


Consider the following identity:



     1      1      c^0     c^1     c^2
    --- = ----- = ----- + ----- + ----- + ...
     b     t-c     t^1     t^2     t^3


If t is a power of 2, then the denominator of each term will be a power of 2.


Given integers a, b, and terms, approximate a/b by computing the first terms terms of the identity above, and multiplying the result by a.
Select t to be the smallest power of 2 greater than or equal to b.


DEFINITION
Class:ApproximateDivision
Method:quotient
Parameters:int, int, int
Returns:double
Method signature:double quotient(int a, int b, int terms)


NOTES
-Your return value must have an absolute or relative error less than 1e-9.


CONSTRAINTS
-b will be between 1 and 10000, inclusive.
-a will be between 0 and b, inclusive.
-terms will be between 1 and 20, inclusive.


EXAMPLES

0)
2
5
2

Returns: 0.34375

In this case t is chosen to be 8, and therefore c is 3.  The first two terms are 1/8 and 3/64.

1)
7
8
5

Returns: 0.875

If b is a power of two, the first term is equal to exactly 1/b, and all other terms are zero.

2)
1
3
10

Returns: 0.33333301544189453

3)
1
10000
2

Returns: 8.481740951538086E-5

4)
1
7
20

Returns: 0.14285714285714285

5)
0
4
3

Returns: 0.0



6)
50
50
1

Returns: 0.78125



*/
// END CUT HERE

#line 107 "ApproximateDivision.cpp"
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

class ApproximateDivision {
public:
  double quotient(int a, int b, int terms) {
	int t=1;
	while(1){ if(t<b) t*=2; else break; }
	int c=t-b;
	double d=0, e=1.0/t, r=1.0*c/t;
// BEGIN CUT HERE
	//printf("a=%d,b=%d,a/b=%g, terms=%d, t=%d,c=%d\n",a,b,1.0*a/b,terms,t,c);
// END CUT HERE
	rep(i,terms) {d+=e; e*=r;}
	return d*a;
  }
};

// BEGIN CUT HERE
#include <time.h>
clock_t start_time;
void timer_clear() { start_time = clock(); }
string timer() { clock_t end_time = clock(); double interval = (double)(end_time - start_time)/CLOCKS_PER_SEC; ostringstream os; os << " (" << interval*1000 << " msec)"; return os.str(); }

template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
int verify_case(const double &Expected, const double &Received) { double diff = Expected - Received; if (diff < 0) diff = -diff; if (diff < 1e-9) cerr << "PASSED" << timer() << endl; else { cerr << "FAILED" << timer() << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } return 0;}

template<int N> struct Case_ {};
char Test_(...);
int Test_(Case_<0>) {
	timer_clear();
	int a = 2; 
	int b = 5; 
	int terms = 2; 
	double RetVal = 0.34375; 
	return verify_case(RetVal, ApproximateDivision().quotient(a, b, terms)); }
int Test_(Case_<1>) {
	timer_clear();
	int a = 7; 
	int b = 8; 
	int terms = 5; 
	double RetVal = 0.875; 
	return verify_case(RetVal, ApproximateDivision().quotient(a, b, terms)); }
int Test_(Case_<2>) {
	timer_clear();
	int a = 1; 
	int b = 3; 
	int terms = 10; 
	double RetVal = 0.33333301544189453; 
	return verify_case(RetVal, ApproximateDivision().quotient(a, b, terms)); }
int Test_(Case_<3>) {
	timer_clear();
	int a = 1; 
	int b = 10000; 
	int terms = 2; 
	double RetVal = 8.481740951538086E-5; 
	return verify_case(RetVal, ApproximateDivision().quotient(a, b, terms)); }
int Test_(Case_<4>) {
	timer_clear();
	int a = 1; 
	int b = 7; 
	int terms = 20; 
	double RetVal = 0.14285714285714285; 
	return verify_case(RetVal, ApproximateDivision().quotient(a, b, terms)); }
int Test_(Case_<5>) {
	timer_clear();
	int a = 0; 
	int b = 4; 
	int terms = 3; 
	double RetVal = 0.0; 
	return verify_case(RetVal, ApproximateDivision().quotient(a, b, terms)); }
int Test_(Case_<6>) {
	timer_clear();
	int a = 50; 
	int b = 50; 
	int terms = 1; 
	double RetVal = 0.78125; 
	return verify_case(RetVal, ApproximateDivision().quotient(a, b, terms)); }

template<int N> void Run_() { cerr << "Test Case #" << N << "..." << flush; Test_(Case_<N>()); Run_<sizeof(Test_(Case_<N+1>()))==1 ? -1 : N+1>(); }
template<>      void Run_<-1>() {}
int main() { Run_<0>(); }
// END CUT HERE

