#line 2 "MazeMaker.cpp"
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
#define found(s,e)  ((s).find(e)!=(s).end())

typedef pair<int,int> i_i;
typedef pair<int,pair<int,int> > i_ii;
#define cons(x,y) make_pair((x),(y))
#define car(x) ((x).first)
#define cdr(x) ((x).second)
#define cadr(x) (x).second.first
#define cddr(x) (x).second.second

class MazeMaker {
 public:
  int longestPath(vector <string> maze, int startRow, int startCol, vector <int> moveRow, vector <int> moveCol) {
    int N=sz(maze), M=sz(maze[0]), NM=0, Z=sz(moveRow);
    rep(r,N)rep(c,M) if(maze[r][c]=='.')NM++;
	priority_queue<i_ii> pq;
    vector<vector<int> > vd(N,vector<int>(M,INT_MAX)); int vdc=0;
    pq.push(cons(0,cons(startRow,startCol)));
    while(!pq.empty()){
      i_ii t = pq.top(); pq.pop();
      int i=-car(t), r=cadr(t), c=cddr(t);
      //printf("> %d (%d,%d)\n", i,r,c);
      if (maze[r][c]=='X') continue;
      if (vd[r][c]<i) continue;
      if (vd[r][c]==INT_MAX) vdc++;
      vd[r][c]=i;
      if (vdc == NM) break;
      rep(z,Z){
        int r2 = r + moveRow[z]; if (r2 < 0 || N <= r2) continue;
        int c2 = c + moveCol[z]; if (c2 < 0 || M <= c2) continue;
        pq.push(cons(-(i+1),cons(r2,c2)));
      }
    }
    //printf("- %d : %d\n", vdc,NM);
    if (vdc < NM) return -1;
    int mx=0;
    rep(r,N)rep(c,M) {
      if (vd[r][c]==INT_MAX) continue;
      if (vd[r][c]>mx)mx=vd[r][c];
    }
    return mx<INT_MAX ? mx : -31;
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
	string maze_[] = {"...",
 "...",
 "..."};
	  vector <string> maze(maze_, maze_+sizeof(maze_)/sizeof(*maze_)); 
	int startRow = 0; 
	int startCol = 1; 
	int moveRow_[] = {1,0,-1,0};
	  vector <int> moveRow(moveRow_, moveRow_+sizeof(moveRow_)/sizeof(*moveRow_)); 
	int moveCol_[] = {0,1,0,-1};
	  vector <int> moveCol(moveCol_, moveCol_+sizeof(moveCol_)/sizeof(*moveCol_)); 
	int RetVal = 3; 
	return verify_case(RetVal, MazeMaker().longestPath(maze, startRow, startCol, moveRow, moveCol)); }
int Test_(Case_<1>) {
	timer_clear();
	string maze_[] = {"...",
 "...",
 "..."};
	  vector <string> maze(maze_, maze_+sizeof(maze_)/sizeof(*maze_)); 
	int startRow = 0; 
	int startCol = 1; 
	int moveRow_[] = {1, 0, -1, 0, 1, 1, -1, -1};
	  vector <int> moveRow(moveRow_, moveRow_+sizeof(moveRow_)/sizeof(*moveRow_)); 
	int moveCol_[] = {0, 1, 0, -1, 1, -1, 1, -1};
	  vector <int> moveCol(moveCol_, moveCol_+sizeof(moveCol_)/sizeof(*moveCol_)); 
	int RetVal = 2; 
	return verify_case(RetVal, MazeMaker().longestPath(maze, startRow, startCol, moveRow, moveCol)); }
int Test_(Case_<2>) {
	timer_clear();
	string maze_[] = {"X.X",
 "...",
 "XXX",
 "X.X"};
	  vector <string> maze(maze_, maze_+sizeof(maze_)/sizeof(*maze_)); 
	int startRow = 0; 
	int startCol = 1; 
	int moveRow_[] = {1, 0, -1, 0};
	  vector <int> moveRow(moveRow_, moveRow_+sizeof(moveRow_)/sizeof(*moveRow_)); 
	int moveCol_[] = {0, 1, 0, -1};
	  vector <int> moveCol(moveCol_, moveCol_+sizeof(moveCol_)/sizeof(*moveCol_)); 
	int RetVal = -1; 
	return verify_case(RetVal, MazeMaker().longestPath(maze, startRow, startCol, moveRow, moveCol)); }
int Test_(Case_<3>) {
	timer_clear();
	string maze_[] = {".......",
 "X.X.X..",
 "XXX...X",
 "....X..",
 "X....X.",
 "......."};
	  vector <string> maze(maze_, maze_+sizeof(maze_)/sizeof(*maze_)); 
	int startRow = 5; 
	int startCol = 0; 
	int moveRow_[] = {1, 0, -1, 0,-2, 1};
	  vector <int> moveRow(moveRow_, moveRow_+sizeof(moveRow_)/sizeof(*moveRow_)); 
	int moveCol_[] = {0, -1, 0, 1, 3, 0};
	  vector <int> moveCol(moveCol_, moveCol_+sizeof(moveCol_)/sizeof(*moveCol_)); 
	int RetVal = 7; 
	return verify_case(RetVal, MazeMaker().longestPath(maze, startRow, startCol, moveRow, moveCol)); }
int Test_(Case_<4>) {
	timer_clear();
	string maze_[] = {"......."};
	  vector <string> maze(maze_, maze_+sizeof(maze_)/sizeof(*maze_)); 
	int startRow = 0; 
	int startCol = 0; 
	int moveRow_[] = {1, 0, 1, 0, 1, 0};
	  vector <int> moveRow(moveRow_, moveRow_+sizeof(moveRow_)/sizeof(*moveRow_)); 
	int moveCol_[] = {0, 1, 0, 1, 0, 1};
	  vector <int> moveCol(moveCol_, moveCol_+sizeof(moveCol_)/sizeof(*moveCol_)); 
	int RetVal = 6; 
	return verify_case(RetVal, MazeMaker().longestPath(maze, startRow, startCol, moveRow, moveCol)); }
int Test_(Case_<5>) {
	timer_clear();
	string maze_[] = {"..X.X.X.X.X.X."};
	  vector <string> maze(maze_, maze_+sizeof(maze_)/sizeof(*maze_)); 
	int startRow = 0; 
	int startCol = 0; 
	int moveRow_[] = {2,0,-2,0};
	  vector <int> moveRow(moveRow_, moveRow_+sizeof(moveRow_)/sizeof(*moveRow_)); 
	int moveCol_[] = {0,2,0,-2};
	  vector <int> moveCol(moveCol_, moveCol_+sizeof(moveCol_)/sizeof(*moveCol_)); 
	int RetVal = -1; 
	return verify_case(RetVal, MazeMaker().longestPath(maze, startRow, startCol, moveRow, moveCol)); }

template<int N> void Run_() { cerr << "Test Case #" << N << "..." << flush; Test_(Case_<N>()); Run_<sizeof(Test_(Case_<N+1>()))==1 ? -1 : N+1>(); }
template<>      void Run_<-1>() {}
int main() { Run_<0>(); }
// END CUT HERE


// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
Mike Mazemeister has recently built a large maze in his backyard.  The j-th character of the i-th element of maze is 'X' if the square is an impassable bush; otherwise, it is a '.'.  Mike wants his friend, Jumping Jim, to solve the maze.  Jim will start in row startRow in column startCol.

Unlike typical maze solvers, Jim has the ability to jump through the maze, rather than simply walking.  Jim's possible moves are described in moveRow and moveCol.  The i-th element corresponds to a move Jim can make in which his current row is changed by moveRow[i], and his current column is changed by moveCol[i].  For example, if moveRow = {1, 0, -1} and moveCol = {3, -2, 5}, Jim's legal moves are (1,3), (0, -2), and (-1, 5).  However, Jim cannot move outside the boundary of the maze, and he cannot land on an impassable bush.

Mike wants to make the maze impossible for Jim to exit, and can place the exit in any cell containing a '.' in the maze.  If this turns out to be impossible, then Mike wants to make Jim's trip take as long as possible.  Jim is smart, and he will always exit the maze in the minimum number of jumps that he can.  Return the maximum number of jumps that Jim will make to exit the maze; if it is impossible for him to exit the maze, return -1 instead.


DEFINITION
Class:MazeMaker
Method:longestPath
Parameters:vector <string>, int, int, vector <int>, vector <int>
Returns:int
Method signature:int longestPath(vector <string> maze, int startRow, int startCol, vector <int> moveRow, vector <int> moveCol)


CONSTRAINTS
-maze will contain between 1 and 50 elements, inclusive.
-Each element of maze will contain between 1 and 50 characters, inclusive.
-Each element of maze will contain the same number of characters.
-Each character of maze will be either 'X' or '.'.
-maze will contain at least 2 '.' characters.
-startRow will be between 0 and N-1, inclusive, where N is the number of elements in maze.
-startCol will be between 0 and M-1, inclusive, where M is the number of characters in each element of maze.
-maze[startRow][startCol] will be '.'.
-moveRow will contain between 1 and 50 elements, inclusive.
-moveCol will contain the same number of elements as moveRow.
-Each element of moveRow and moveCol will be between -50 and 50, inclusive.


EXAMPLES

0)
{"...",
 "...",
 "..."}
0
1
{1,0,-1,0}
{0,1,0,-1}

Returns: 3

Here Jim can move up, down, left and right.  Mike will set the exit in one of the bottom corners, which take Jim 3 steps to reach.

1)
{"...",
 "...",
 "..."}
0
1
{1, 0, -1, 0, 1, 1, -1, -1}
{0, 1, 0, -1, 1, -1, 1, -1}

Returns: 2

This is the same problem, but now Jim can move diagonally.  With this, he can reach any section in at most two steps.

2)
{"X.X",
 "...",
 "XXX",
 "X.X"}
0
1
{1, 0, -1, 0}
{0, 1, 0, -1}

Returns: -1

Here Mike can place the exit in the empty section of the bottom row; Jim can never reach it.

3)
{".......",
 "X.X.X..",
 "XXX...X",
 "....X..",
 "X....X.",
 "......."}
5
0
{1, 0, -1, 0,-2, 1}
{0, -1, 0, 1, 3, 0}

Returns: 7



4)
{"......."}
0
0
{1, 0, 1, 0, 1, 0}
{0, 1, 0, 1, 0, 1}

Returns: 6



5)
{"..X.X.X.X.X.X."}
0
0
{2,0,-2,0}
{0,2,0,-2}

Returns: -1

Since Jim can only jump (and can't move to the side), Mike can place the exit anywhere except the start to prevent Jim from winning.

*/
// END CUT HERE
