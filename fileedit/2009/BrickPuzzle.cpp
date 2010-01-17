#line 2 "BrickPuzzle.cpp"
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

class BrickPuzzle {
	public:
	int leastShapes(vector <string> board) {
		
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
	string board_[] = {"..X....",
 "..XXXXX"};
	  vector <string> board(board_, board_+sizeof(board_)/sizeof(*board_)); 
	int RetVal = 2; 
	return verify_case(RetVal, BrickPuzzle().leastShapes(board)); }
int Test_(Case_<1>) {
	timer_clear();
	string board_[] = {".X",
 "..",
 "X."};
	  vector <string> board(board_, board_+sizeof(board_)/sizeof(*board_)); 
	int RetVal = -1; 
	return verify_case(RetVal, BrickPuzzle().leastShapes(board)); }
int Test_(Case_<2>) {
	timer_clear();
	string board_[] = {"..XX....",
 "....X..X",
 "XX..XXXX"};
	  vector <string> board(board_, board_+sizeof(board_)/sizeof(*board_)); 
	int RetVal = 4; 
	return verify_case(RetVal, BrickPuzzle().leastShapes(board)); }
int Test_(Case_<3>) {
	timer_clear();
	string board_[] = {"X..XXXX",
 "X.....X",
 "....XX.",
 "X......"};
	  vector <string> board(board_, board_+sizeof(board_)/sizeof(*board_)); 
	int RetVal = 5; 
	return verify_case(RetVal, BrickPuzzle().leastShapes(board)); }

template<int N> void Run_() { cerr << "Test Case #" << N << "..." << flush; Test_(Case_<N>()); Run_<sizeof(Test_(Case_<N+1>()))==1 ? -1 : N+1>(); }
template<>      void Run_<-1>() {}
int main() { Run_<0>(); }
// END CUT HERE


// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// NOTE: This problem statement contains images that may not display properly if viewed outside of the applet.
Howard Benson loves puzzles and is always eager to invent new ones. He has recently invented a new puzzle based on the old puzzles that involved placing various tetrominoes inside a rectangle. For this puzzle, Howard picked four kinds of tetrominoes and made pieces with their shapes. The player can use as many pieces of each kind as necessary.  The pieces he made available are shown in the following image:




Another component of the puzzle is the board, which is a square grid composed of white and black cells. The objective of the game is to cover all the white cells by placing a minimum number of pieces on the board. There are many rules regarding the placement of the pieces:
The pieces may not overlap.
Every piece must lie completely inside the board.
The pieces must be aligned to the grid.
The orientation of each piece must be the same as the orientation in the picture above.
Black cells in the board may be covered if necessary.


For example, the following picture shows a board configuration and a solution using a minimum number of pieces:



You are given the board as a  vector <string> board. The j-th character of the i-th element of board is 'X' if the cell at column j, row i is black and '.' if the cell is white. Return the minimum number of shapes that are required to cover all the white cells by following the aforementioned rules. If it is impossible to cover all the white cells following the rules, return -1.



DEFINITION
Class:BrickPuzzle
Method:leastShapes
Parameters:vector <string>
Returns:int
Method signature:int leastShapes(vector <string> board)


CONSTRAINTS
-board will contain between 1 and 22 elements, inclusive.
-Each element of board will contain between 1 and 22 characters, inclusive.
-All elements of board will contain the same number of characters.
-Each element of board will contain only the characters '.' and uppercase 'X'.


EXAMPLES

0)
{"..X....",
 "..XXXXX"}

Returns: 2



1)
{".X",
 "..",
 "X."}

Returns: -1

Note that the pieces cannot be rotated.

2)
{"..XX....",
 "....X..X",
 "XX..XXXX"}

Returns: 4



3)
{"X..XXXX",
 "X.....X",
 "....XX.",
 "X......"}

Returns: 5

This is the example from the statement.

*/
// END CUT HERE
