// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
	You are helping your brother with his homework assignment.  His teacher gave him two distinct numbers x 
	and y, and asked him to use those numbers to form as many different expressions as possible.  
	Each expression must satisfy all of the following rules:

	
		The only allowed operators are '+', '-' and '*'.
	
	
		x and y must each appear exactly twice.  No other numbers are allowed.
	
	
		The result of the expression must be equal to val.
	




	In other words, each expression can be written in the form "a op1 b op2 c op3 d", where each of op1, op2 and op3 
	is '+', '-' or '*', and among the numbers a, b, c and d, exactly two are equal to x and the other two are 
	equal to y.  Please note that the unary minus is not allowed (see example 0).  Expressions are calculated from 
	left to right, and there is no operator precedence.  For example, to calculate the result of 
	"2 + 2 * 3 + 3", you would first calculate 2 + 2, then multiply the result by 3, and then add 3 to get 15.



	Return the total number of different expressions that can be formed.  Two expressions are considered 
	different if their string notations (as described in the previous paragraph) are different.  For example, 
	the expressions "2 + 3 - 2 - 3", "2 - 2 + 3 - 3" and "2 - 3 - 2 + 3" are all different.



DEFINITION
Class:CountExpressions
Method:calcExpressions
Parameters:int, int, int
Returns:int
Method signature:int calcExpressions(int x, int y, int val)


CONSTRAINTS
-x and y will each be between -100 and 100, inclusive.
-x and y will be different.
-val will be between -100000000 and 100000000, inclusive.


EXAMPLES

0)
7
8
16

Returns: 9

The possible expressions are:
8 + 8 + 7 - 7
8 + 7 + 8 - 7
7 + 8 + 8 - 7
8 + 8 - 7 + 7
8 + 7 - 7 + 8
7 + 8 - 7 + 8
8 - 7 + 8 + 7
8 - 7 + 7 + 8
7 - 7 + 8 + 8

Please note that the unary minus is not allowed, so "-7 + 7 + 8 + 8" is not a valid expression.

1)
3
5
7

Returns: 5

The possible expressions are:
3 * 5 - 3 - 5
5 * 3 - 3 - 5
3 * 5 - 5 - 3
5 * 3 - 5 - 3
5 - 3 * 5 - 3

2)
99
100
98010000

Returns: 6

3)
-99
42
-1764

Returns: 2

-99 - (-99) - 42 * 42
-99 - 42 - (-99) * 42


4)
100
-100
-100000000

Returns: 0

There are no valid expressions.

5)
1
2
5

Returns: 17



*/
// END CUT HERE

#line 126 "CountExpressions.cpp"
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

class CountExpressions {
  int op(int x,int y,int opid){
	int val=0;
	switch(opid){
	case 0: val=x+y;break;
	case 1: val=x-y;break;
	case 2: val=x*y;break;
	}
	return val;
  }
public:
  int calcExpressions(int x, int y, int val) {
	//3:05:16 3:16:30 (11:14)
	int cnt=0;
	vector<int> n(4); n[0]=n[1]=min(x,y); n[2]=n[3]=max(x,y);
	while(1){
	  int a=n[0];
	  rep(op1,3) {
		int k=a;
		a=op(a,n[1],op1);
		rep(op2,3) {
		  int j=a;
		  a=op(a,n[2],op2);
		  rep(op3,3) {
			int i=a;
			a=op(a,n[3],op3);
			if (a==val) cnt++;
			a=i;
		  }
		  a=j;
		}
		a=k;
	  }
	  if(!next_permutation(all(n)))break;
	}
	return cnt;
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
	int x = 7; 
	int y = 8; 
	int val = 16; 
	int RetVal = 9; 
	return verify_case(RetVal, CountExpressions().calcExpressions(x, y, val)); }
int Test_(Case_<1>) {
	timer_clear();
	int x = 3; 
	int y = 5; 
	int val = 7; 
	int RetVal = 5; 
	return verify_case(RetVal, CountExpressions().calcExpressions(x, y, val)); }
int Test_(Case_<2>) {
	timer_clear();
	int x = 99; 
	int y = 100; 
	int val = 98010000; 
	int RetVal = 6; 
	return verify_case(RetVal, CountExpressions().calcExpressions(x, y, val)); }
int Test_(Case_<3>) {
	timer_clear();
	int x = -99; 
	int y = 42; 
	int val = -1764; 
	int RetVal = 2; 
	return verify_case(RetVal, CountExpressions().calcExpressions(x, y, val)); }
int Test_(Case_<4>) {
	timer_clear();
	int x = 100; 
	int y = -100; 
	int val = -100000000; 
	int RetVal = 0; 
	return verify_case(RetVal, CountExpressions().calcExpressions(x, y, val)); }
int Test_(Case_<5>) {
	timer_clear();
	int x = 1; 
	int y = 2; 
	int val = 5; 
	int RetVal = 17; 
	return verify_case(RetVal, CountExpressions().calcExpressions(x, y, val)); }

template<int N> void Run_() { cerr << "Test Case #" << N << "..." << flush; Test_(Case_<N>()); Run_<sizeof(Test_(Case_<N+1>()))==1 ? -1 : N+1>(); }
template<>      void Run_<-1>() {}
int main() { Run_<0>(); }
// END CUT HERE

