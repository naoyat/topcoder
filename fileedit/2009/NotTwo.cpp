#line 2 "NotTwo.cpp"
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
#define rep(var,n)  for(int var=0;var<(n);var++)

int m[4][4] = { {1,1,0,0},{1,1,0,0},{0,0,1,1},{0,0,1,1} };
class NotTwo {
 public:
  int maxStones(int width, int height) {
    int st=0;
    rep(r,height){
      rep(c,width){
        st += m[r%4][c%4];
      }
    }
    return st;
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
	int width = 3; 
	int height = 2; 
	int RetVal = 4; 
	return verify_case(RetVal, NotTwo().maxStones(width, height)); }
int Test_(Case_<1>) {
	timer_clear();
	int width = 3; 
	int height = 3; 
	int RetVal = 5; 
	return verify_case(RetVal, NotTwo().maxStones(width, height)); }
int Test_(Case_<2>) {
	timer_clear();
	int width = 8; 
	int height = 5; 
	int RetVal = 20; 
	return verify_case(RetVal, NotTwo().maxStones(width, height)); }

template<int N> void Run_() { cerr << "Test Case #" << N << "..." << flush; Test_(Case_<N>()); Run_<sizeof(Test_(Case_<N+1>()))==1 ? -1 : N+1>(); }
template<>      void Run_<-1>() {}
int main() { Run_<0>(); }
// END CUT HERE


// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// Bob has a width x height rectangular board divided into 1 x 1 cells. Rows of the board are numbered 0 to height-1 and columns are numbered 0 to width-1.


Each cell can contain at most one stone, and the Euclidean distance between each pair of stones must not equal 2. The Euclidean distance between cell in row x1, column y1 and cell in row x2, column y2 is defined as the square root from (x1-x2) * (x1-x2) + (y1-y2) * (y1-y2).


Return the maximal number of stones he can place on the board.


DEFINITION
Class:NotTwo
Method:maxStones
Parameters:int, int
Returns:int
Method signature:int maxStones(int width, int height)


CONSTRAINTS
-width will be between 1 and 1000, inclusive.
-height will be between 1 and 1000, inclusive.


EXAMPLES

0)
3
2

Returns: 4

He can place four stones on the board. Here is one possible arrangement:
- * *
* * -


1)
3
3

Returns: 5

* - -
* * -
- * *


2)
8
5

Returns: 20



*/
// END CUT HERE
