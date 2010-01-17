// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
A lame knight is located at the bottom-left corner of a height x width chessboard.  Unlike a healthy knight, a lame knight can only make moves where he goes to the right.  The only possible moves are:


2 cells up, 1 cell right;
1 cell up, 2 cells right;
1 cell down, 2 cells right;
2 cells down, 1 cell right.


The knight will make one trip, and he wants to maximize the number of visited cells.  The knight's starting cell counts toward this number.
There is also one restriction for the knight's trip: it must contain each kind of a move at least once, unless it is shorter than 4 moves. If the knight makes less than 4 moves (thus visiting less than 5 cells), his moves are not limited in any way. Return the maximal number of cells the knight can visit during one trip, including the initial cell.



DEFINITION
Class:LameKnight
Method:maxCells
Parameters:int, int
Returns:int
Method signature:int maxCells(int height, int width)


CONSTRAINTS
-height will be between 1 and 2,000,000,000, inclusive.
-width will be between 1 and 2,000,000,000, inclusive.


EXAMPLES

0)
100
50

Returns: 48

1 move of kind 2, 1 move of kind 3, 23 moves of kind 1 and 22 moves of kind 4.

1)
1
1

Returns: 1

There are no possible moves here, so the only visited cell is the starting cell.


2)
17
5

Returns: 4

It's possible to visit 5 cells (making 4 moves of kind 1 for example), but it's impossible to make it by 4 different moves. So, the best strategy here is to make 3 moves (thus visiting 4 cells).

3)
2
4

Returns: 2

4)
20
4

Returns: 4

4 cells can be visited using 2 moves of kind 1 and 1 move of kind 4.

*/
// END CUT HERE

#line 77 "LameKnight.cpp"
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

// BEGIN CUT HERE
#define sz(a)  int((a).size())
#define pb  push_back
#define all(c)  (c).begin(),(c).end()
#define tr(c,i)  for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); i++)
#define rep(var,n)  for(int var=0;var<(n);var++)
#define found(s,e)  ((s).find(e)!=(s).end())
#define remove_(c,val) (c).erase(remove((c).begin(),(c).end(),(val)),(c).end())
// END CUT HERE

class LameKnight {
 public:
  int maxCells(int height, int width) {
    if(height==1 || width==1) return 1;
    if(height==2) return min(1+(width-1)/2, 4);
    if(height>=3 && width<7) return min(width,4);
    return width-2;
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
	int height = 100; 
	int width = 50; 
	int RetVal = 48; 
	return verify_case(RetVal, LameKnight().maxCells(height, width)); }
int Test_(Case_<1>) {
	timer_clear();
	int height = 1; 
	int width = 1; 
	int RetVal = 1; 
	return verify_case(RetVal, LameKnight().maxCells(height, width)); }
int Test_(Case_<2>) {
	timer_clear();
	int height = 17; 
	int width = 5; 
	int RetVal = 4; 
	return verify_case(RetVal, LameKnight().maxCells(height, width)); }
int Test_(Case_<3>) {
	timer_clear();
	int height = 2; 
	int width = 4; 
	int RetVal = 2; 
	return verify_case(RetVal, LameKnight().maxCells(height, width)); }
int Test_(Case_<4>) {
	timer_clear();
	int height = 20; 
	int width = 4; 
	int RetVal = 4; 
	return verify_case(RetVal, LameKnight().maxCells(height, width)); }

template<int N> void Run_() { cerr << "Test Case #" << N << "..." << flush; Test_(Case_<N>()); Run_<sizeof(Test_(Case_<N+1>()))==1 ? -1 : N+1>(); }
template<>      void Run_<-1>() {}
int main() { Run_<0>(); }
// END CUT HERE

