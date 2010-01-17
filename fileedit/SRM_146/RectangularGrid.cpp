// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// Given the width and height of a rectangular grid, return the total number of rectangles (NOT counting squares) that can be found on this grid.
For example, width = 3, height = 3 (see diagram below):

 __ __ __
|__|__|__|
|__|__|__|
|__|__|__|

In this grid, there are 4 2x3 rectangles, 6 1x3 rectangles and 12 1x2 rectangles. Thus there is a total of 4 + 6 + 12 = 22 rectangles. Note we don't count 1x1, 2x2 and 3x3 rectangles because they are squares.


DEFINITION
Class:RectangularGrid
Method:countRectangles
Parameters:int, int
Returns:long long
Method signature:long long countRectangles(int width, int height)


NOTES
-rectangles with equals sides (squares) should not be counted.


CONSTRAINTS
-width and height will be between 1 and 1000 inclusive.


EXAMPLES

0)
3
3

Returns: 22

See above

1)
5
2

Returns: 31


 __ __ __ __ __
|__|__|__|__|__|
|__|__|__|__|__|

In this grid, there is one 2x5 rectangle, 2 2x4 rectangles, 2 1x5 rectangles, 3 2x3 rectangles, 4 1x4 rectangles, 6 1x3 rectangles and 13 1x2 rectangles. Thus there is a total of 1 + 2 + 2 + 3 + 4 + 6 + 13 = 31 rectangles.

2)
10
10

Returns: 2640

3)
1
1

Returns: 0

4)
592
964

Returns: 81508708664

*/
// END CUT HERE

#line 76 "RectangularGrid.cpp"
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
#define FOR(var,from,to) for(int var=(from);var<=(to);var++)

class RectangularGrid {
 public:
  long long countRectangles(int width, int height) {
	ll cnt=0LL;
    FOR(w,1,width)FOR(h,1,height) if(w!=h)cnt+=(1LL+width-w)*(1LL+height-h);
    return cnt;
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
	int width = 3; 
	int height = 3; 
	long long RetVal = 22LL; 
	return verify_case(RetVal, RectangularGrid().countRectangles(width, height)); }
int Test_(Case_<1>) {
	timer_clear();
	int width = 5; 
	int height = 2; 
	long long RetVal = 31LL; 
	return verify_case(RetVal, RectangularGrid().countRectangles(width, height)); }
int Test_(Case_<2>) {
	timer_clear();
	int width = 10; 
	int height = 10; 
	long long RetVal = 2640LL; 
	return verify_case(RetVal, RectangularGrid().countRectangles(width, height)); }
int Test_(Case_<3>) {
	timer_clear();
	int width = 1; 
	int height = 1; 
	long long RetVal = 0LL; 
	return verify_case(RetVal, RectangularGrid().countRectangles(width, height)); }
int Test_(Case_<4>) {
	timer_clear();
	int width = 592; 
	int height = 964; 
	long long RetVal = 81508708664LL; 
	return verify_case(RetVal, RectangularGrid().countRectangles(width, height)); }

template<int N> void Run_() { cerr << "Test Case #" << N << "..." << flush; Test_(Case_<N>()); Run_<sizeof(Test_(Case_<N+1>()))==1 ? -1 : N+1>(); }
template<>      void Run_<-1>() {}
int main() { Run_<0>(); }
// END CUT HERE

