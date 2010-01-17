#line 2 "StairsColoring.cpp"
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

class StairsColoring {
	public:
	int coloringCount(int N, int K) {
		
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
	int N = 3; 
	int K = 2; 
	int RetVal = 32; 
	return verify_case(RetVal, StairsColoring().coloringCount(N, K)); }
int Test_(Case_<1>) {
	timer_clear();
	int N = 2; 
	int K = 2; 
	int RetVal = 4; 
	return verify_case(RetVal, StairsColoring().coloringCount(N, K)); }
int Test_(Case_<2>) {
	timer_clear();
	int N = 1; 
	int K = 1; 
	int RetVal = 1; 
	return verify_case(RetVal, StairsColoring().coloringCount(N, K)); }
int Test_(Case_<3>) {
	timer_clear();
	int N = 4; 
	int K = 5; 
	int RetVal = 103514887; 
	return verify_case(RetVal, StairsColoring().coloringCount(N, K)); }
int Test_(Case_<4>) {
	timer_clear();
	int N = 7; 
	int K = 77; 
	int RetVal = 747707397; 
	return verify_case(RetVal, StairsColoring().coloringCount(N, K)); }

template<int N> void Run_() { cerr << "Test Case #" << N << "..." << flush; Test_(Case_<N>()); Run_<sizeof(Test_(Case_<N+1>()))==1 ? -1 : N+1>(); }
template<>      void Run_<-1>() {}
int main() { Run_<0>(); }
// END CUT HERE


// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// A very rich sultan built an enormous luxurious two-story palace containing several staircases.  According to an old tradition, each staircase must:


contain exactly N steps
have a right angle in its base
be built using exactly N rectangular blocks of arbitrary size


Staircases can be built using many different arrangements of blocks.  For example, there are 5 ways to build a staircase with 3 steps:


To ensure that his palace is really the most luxurious in the world, the sultan decided to build one staircase for each possible arrangement of blocks.

The sultan is now preparing for a staircase coloring festival.  He wants to paint each of the staircases in the palace in one of K different colors.  Multiple staircases can be painted the same color, and it is not necessary to use all K colors.  Help the sultan by calculating the total number of different ways he can color his staircases.  The answer can be large, so return the count modulo 1000000123.

DEFINITION
Class:StairsColoring
Method:coloringCount
Parameters:int, int
Returns:int
Method signature:int coloringCount(int N, int K)


CONSTRAINTS
-N will be between 1 and 1000000000, inclusive.
-K will be between 1 and 1000000000, inclusive.


EXAMPLES

0)
3
2

Returns: 32

As shown in the picture above, there are exactly 5 different ways to build a staircase with 3 steps.  Each staircase can be painted in one of 2 different colors, for a total of 32 possible color combinations.


1)
2
2

Returns: 4

2)
1
1

Returns: 1

Here, there is only one staircase and one color to paint it.

3)
4
5

Returns: 103514887

4)
7
77

Returns: 747707397

*/
// END CUT HERE
