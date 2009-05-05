#line 2 "PouringWater.cpp"
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

class PouringWater {
 public:
  int getMinBottles(int N, int K) {
    for(int i=N,c=0;;i++,c++){
      if(__builtin_popcount(i)<=K) return c;
    }
    return -1;
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
	int K = 1; 
	int RetVal = 1; 
	return verify_case(RetVal, PouringWater().getMinBottles(N, K)); }
int Test_(Case_<1>) {
	timer_clear();
	int N = 13; 
	int K = 2; 
	int RetVal = 3; 
	return verify_case(RetVal, PouringWater().getMinBottles(N, K)); }
int Test_(Case_<2>) {
	timer_clear();
	int N = 1000000; 
	int K = 5; 
	int RetVal = 15808; 
	return verify_case(RetVal, PouringWater().getMinBottles(N, K)); }
int Test_(Case_<3>) {
	timer_clear();
	int N = 1000000;
	int K = 1000; 
	int RetVal = 15808; 
	return verify_case(RetVal, PouringWater().getMinBottles(N, K)); }
int Test_(Case_<4>) {
	timer_clear();
	int N = 1;
	int K = 1000; 
	int RetVal = 15808; 
	return verify_case(RetVal, PouringWater().getMinBottles(N, K)); }

template<int N> void Run_() { cerr << "Test Case #" << N << "..." << flush; Test_(Case_<N>()); Run_<sizeof(Test_(Case_<N+1>()))==1 ? -1 : N+1>(); }
template<>      void Run_<-1>() {}
int main() { Run_<0>(); }
// END CUT HERE


// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// You have N bottles, each with unlimited capacity.  Initially, each bottle contains exactly 1 liter of water.  You want to carry these bottles to another location, but you can only carry K bottles at a time.  You don't want to waste any water and you don't want to make more than one trip, so you decide to redistribute the contents of the bottles until you end up with no more than K non-empty bottles.

You are only allowed to redistribute your water using the following method.  First, pick two bottles that contain an equal amount of water.  Then, pour the entire content of one of those bottles into the other.  Repeat this process as many times as necessary.

Because of this restriction, it may be impossible to end up with no more than K non-empty bottles using only the N bottles that you have initially.  Fortunately, you can also buy more bottles.  Each bottle that you buy will contain exactly 1 liter of water and have unlimited capacity.  For example, consider the case where N is 3 and K is 1.  It's impossible to get from 3 bottles to 1.  If you pour one bottle into another, you end up with one 2 liter bottle and one 1 liter bottle.  At that point, you're stuck.  However, if you then buy another bottle, you can pour that bottle into the 1 liter bottle, and pour the resulting 2 liter bottle into the other 2 liter bottle to end up with just one 4 liter bottle. 

Return the minimum number of additional bottles you must buy in order to achieve your goal.  If it's impossible, return -1 instead.

DEFINITION
Class:PouringWater
Method:getMinBottles
Parameters:int, int
Returns:int
Method signature:int getMinBottles(int N, int K)


CONSTRAINTS
-N will be between 1 and 10^7, inclusive.
-K will be between 1 and 1000, inclusive.


EXAMPLES

0)
3
1

Returns: 1

The example from the problem statement.

1)
13
2

Returns: 3

If you have 13, 14, or 15 bottles, you can't end up with one or two bottles. With 16 bottles, you can end up with one bottle.

2)
1000000
5

Returns: 15808



*/
// END CUT HERE
