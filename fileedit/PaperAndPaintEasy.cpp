#line 2 "PaperAndPaintEasy.cpp"
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

class PaperAndPaintEasy {
	public:
	long long computeArea(int width, int height, int xfold, int cnt, int x1, int y1, int x2, int y2) {
		
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
	int width = 5; 
	int height = 6; 
	int xfold = 2; 
	int cnt = 2; 
	int x1 = 1; 
	int y1 = 1; 
	int x2 = 3; 
	int y2 = 2; 
	long long RetVal = 21LL; 
	return verify_case(RetVal, PaperAndPaintEasy().computeArea(width, height, xfold, cnt, x1, y1, x2, y2)); }
int Test_(Case_<1>) {
	timer_clear();
	int width = 3; 
	int height = 13; 
	int xfold = 1; 
	int cnt = 0; 
	int x1 = 1; 
	int y1 = 8; 
	int x2 = 2; 
	int y2 = 12; 
	long long RetVal = 35LL; 
	return verify_case(RetVal, PaperAndPaintEasy().computeArea(width, height, xfold, cnt, x1, y1, x2, y2)); }
int Test_(Case_<2>) {
	timer_clear();
	int width = 12; 
	int height = 12; 
	int xfold = 7; 
	int cnt = 3; 
	int x1 = 3; 
	int y1 = 1; 
	int x2 = 6; 
	int y2 = 2; 
	long long RetVal = 124LL; 
	return verify_case(RetVal, PaperAndPaintEasy().computeArea(width, height, xfold, cnt, x1, y1, x2, y2)); }
int Test_(Case_<3>) {
	timer_clear();
	int width = 4; 
	int height = 5; 
	int xfold = 4; 
	int cnt = 0; 
	int x1 = 0; 
	int y1 = 0; 
	int x2 = 1; 
	int y2 = 1; 
	long long RetVal = 19LL; 
	return verify_case(RetVal, PaperAndPaintEasy().computeArea(width, height, xfold, cnt, x1, y1, x2, y2)); }
int Test_(Case_<4>) {
	timer_clear();
	int width = 4; 
	int height = 8; 
	int xfold = 4; 
	int cnt = 3; 
	int x1 = 0; 
	int y1 = 1; 
	int x2 = 2; 
	int y2 = 2; 
	long long RetVal = 24LL; 
	return verify_case(RetVal, PaperAndPaintEasy().computeArea(width, height, xfold, cnt, x1, y1, x2, y2)); }
int Test_(Case_<5>) {
	timer_clear();
	int width = 4; 
	int height = 8; 
	int xfold = 3; 
	int cnt = 0; 
	int x1 = 1; 
	int y1 = 1; 
	int x2 = 3; 
	int y2 = 2; 
	long long RetVal = 30LL; 
	return verify_case(RetVal, PaperAndPaintEasy().computeArea(width, height, xfold, cnt, x1, y1, x2, y2)); }

template<int N> void Run_() { cerr << "Test Case #" << N << "..." << flush; Test_(Case_<N>()); Run_<sizeof(Test_(Case_<N+1>()))==1 ? -1 : N+1>(); }
template<>      void Run_<-1>() {}
int main() { Run_<0>(); }
// END CUT HERE


// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// Onise likes to play with paper and paint.  He has a piece of paper with dimensions width x height.  He does the following steps with the paper:


Fold the paper along the line x = xfold (the left side of the paper is folded over the right side).
Divide the paper vertically into cnt+1 equal sections.  Then, cnt times, take the topmost section and fold it over the section below it.
Paint a rectangle with the lower-left corner at (x1, y1) and the upper-right corner at (x2, y2).  Note that (0, 0) is now the lower-left corner of the paper in its current folded state, not its original state.  The paint will seep through all the layers of the folded paper.  See the image below for clarification.
Unfold the paper.


For example, let's say Onise has a piece of paper that is 5 x 6.  He performs the described steps where xfold is 2, cnt is 2, and the coordinates of the painted rectangle's corners are (1, 1) and (3, 2).  The following will happen (note that the paper starts out blue in the images and gets painted white):

 
 
 
 
 


You are given ints width and height, and ints xfold, cnt, x1, y1, x2 and y2.  Return the total area of of the paper that is not covered in paint after Onise is done.

DEFINITION
Class:PaperAndPaintEasy
Method:computeArea
Parameters:int, int, int, int, int, int, int, int
Returns:long long
Method signature:long long computeArea(int width, int height, int xfold, int cnt, int x1, int y1, int x2, int y2)


CONSTRAINTS
-width and height will be between 1 and 10^9, inclusive.
-xfold will be between 0 and width, inclusive.
-cnt will be between 0 and 1000, inclusive.
-cnt+1 will be a divisor of height.
-0 <= x1 < x2 <= max(xfold, width-xfold) and 0 <= y1 < y2 <= height/(cnt+1).


EXAMPLES

0)
5
6
2
2
1
1
3
2

Returns: 21

The example from the problem statement.

1)
3
13
1
0
1
8
2
12

Returns: 35

2)
12
12
7
3
3
1
6
2

Returns: 124

3)
4
5
4
0
0
0
1
1

Returns: 19

4)
4
8
4
3
0
1
2
2

Returns: 24

5)
4
8
3
0
1
1
3
2

Returns: 30

*/
// END CUT HERE
