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

vector<bool> ok;//(NM,false);

const int infty = INT_MAX;

template <typename T> T infsum(T a, T b){
  return (a == infty || b == infty)? infty : (a + b);
}

template <typename T> pair<vector<T>,vector<int> >
dijkstra_core(const vector<vector<T> >& arclength, int start_v)
{
  int N = arclength.size();
  //
  cout << "N: " << N << endl;
  cout << "arclength: " << endl;
  rep(i,N){
    rep(j,N){
      putchar(' ');
      if (i==j) putchar(ok[i]?'.':'x');//putchar(i==start ? 'S' : maze[i/M][i%M]);
      else if (arclength[i][j]==infty) putchar('-');
      else putchar('0'+arclength[i][j]);
    }
    cout << endl;
  }
  cout << "start: " << start_v << endl;

  set<int> S;
  vector<T> distance(N, infty); // inftyは適当な大きな数
  vector<int> predecessor(N, -1);

  S.insert(start_v);
  distance[start_v] = 0;

  rep(v,N){
    if (v == start_v) continue;
    if (arclength[start_v][v] == infty) continue;
    
    distance[v] = arclength[start_v][v];
    predecessor[v] = start_v;
  }
  //cout << ":1" << endl;
  while (S.size() < N) { // 各点へ
    // find v* from V\S with distance(v*) = min{distance(v):v from V\S}
    int v_ = -1;
    T d_ = infty;
    //cout << ":20" << endl;
    rep(v,N){
      if (found(S,v)) continue;
      if (distance[v] < d_) { d_ = distance[v]; v_ = v; }
    }
    if (v_==-1) break;
    S.insert(v_);

    //cout << ":22" << endl;
    rep(v,N){ // FOR ALL v from V\S DO
      if (found(S,v)) continue;
      T d_ = infsum(distance[v_], arclength[v_][v]);
      if (d_ < distance[v]) {
        distance[v] = d_;
        predecessor[v] = v_;
      }
    }
    // cout << v_ << " - " << distance << endl;
    //cout << ":29" << endl;
  }

  return make_pair(distance,predecessor);
}

class MazeMaker {
 public:
  int longestPath(vector <string> maze, int startRow, int startCol, vector <int> moveRow, vector <int> moveCol) {
    int N=sz(maze), M=sz(maze[0]), NM=N*M, Z=sz(moveRow);
    printf("N=%d, M=%d, NM=%d, Z=%d\n", N,M,NM,Z);
    cout << "maze: " << endl;
    rep(r,N){
      rep(c,M){
        putchar(r==startRow && c==startCol ? 'S' : maze[r][c]);
      }
      cout << endl;
    }

    //    vector<int> move(Z);
    //    rep(z,Z) move[z] = M*moveRow[z] + moveCol[z];
    //vector<ii> move(Z);
    //rep(z,Z) move[z] = cons(moveRow[z],moveCol[z]);
    /*
    rep(z,Z){
      printf("(%d,%d) = %d.%d + %d = %d\n", moveCol[z],moveRow[z], M,moveRow[z],moveCol[z], move[z]);
    }
    cout << "move: " << move << endl;
    */
    //vector<bool> ok(NM,false);
    ok.resize(NM); rep(i,NM) ok[i]=false;
    rep(r,N)rep(c,M) if(maze[r][c]=='.') ok[M*r + c] = true;
    cout << "ok: " << ok << endl;
    
    vector<vector<int> > ar(NM,vector<int>(NM,infty));
    int start=M*startRow + startCol;

    rep(ri,N)rep(ci,M){
      int i = M*ri + ci; if (!ok[i]) continue;
      rep(z,Z){
        int rj=ri+moveRow[z], cj=ci+moveCol[z];
        if(0<=rj && rj<N && 0<=cj && cj<M){
          int j = M*rj + cj; ar[i][j]=1;
        }
      }
    }
    /**      
    rep(i,NM){
      if(!ok[i]) continue;
      rep(z,Z){
        int j=i+move[z];
        if (0<=j && j<NM && ok[j]) ar[i][j]=1;
        //printf("  %d,%d) %d + %d = %d, %d\n", i,z, i,move[z], j, ar[i][j]);
      }
    }
    **/
    pair<vector<int>,vector<int> > res = dijkstra_core(ar, start);
    vector<int> distances = res.first;
    cout << "distances: " << distances << endl;
    int dmax=0;
    rep(i,NM){
      if (i==start || !ok[i]) continue;
      int d=distances[i]; if (d==infty) return -1;
      if (d>dmax) dmax=d;
    }
    return dmax;
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

/*
int Test_(Case_<6>) { // #30
	timer_clear();
	string maze_[] =
        {"XXXX.X.XXXX...XXXX..XX.....XXXX...XX..X.XXXXXXXX",
         "XXXXXXXX.XX...XXX..X.XX...X..XX.XX...X..X.X.X..X",
         "X.X..X.X..X..XX.XX...XX...X.XX..XX.....X..X...XX",
         "X.X.X.XX.XXX..XX.X..XX..XX..X..X..X.XX....XXX..X",
         ".X...X..X.....XXX.X......X.XXX..X....X...XX.XXX.",
         "..XX.X...X...X..XX..XXXX.X.XXXXXX..X.X.XX.XXX..X",
         "X..XXXX.X..X.XX.XX.XXXXX..XX.X...X..XX.XXX...X.X",
         "XX.X..XXXX.XXX.XX.X.XX..XXXXX.XX...XX.X......XX.",
         "XXX.XX.X.XX.X....XXX..XXX.XXXX..X......X.X.X..X.",
         "XXXX.X.XXXX....X..XXX.X.....XXXX.X.X..XX...XX...",
         "XX..XX.XX.XX.XXXXXXX.XX..X.X.X.XXX.XXXXX.XX..X..",
         "X.X.X..XX...X.X.XXX.X...XX....X.X..X...X...XXX.X",
         "X.X.XX..XXX.X.XX..XX....XXXX.X..XX..XXX.X.X.X...",
         "XX.....XX..X.XX...XXXX..X....XX.XX..XXX...XXXX.X",
         "XX.X...XXX...XXXXXX.....X.X..X....X.X...XX.XX.X.",
         "..XXX..X..XXX.XX..XXXXX...X...X.XX..X.XX.X.XXXX.",
         "XX.X.X..XXX..X.XX.XXX...XXXXX.X...X.X.X.XX.X..X.",
         ".XX.XX..X.XXX.XX...X.XX....X..XX.XXX.XXX.X.X.X.X",
         "..X...XX....X..X....XXXX...X..XX.X.X.X...XXXX.XX",
         "X....X...XXX.XX.XX.....XXXX..X.XX...XX...X.X....",
         ".XX....X..XXXXXX.X..XX..XX.X.X.XXXX..XXX.X.X..XX",
         "X.....XXXX..X...X..X..X.X....XXXXXXXX.X.X...X.XX",
         "XXXX.XX.X.XXXX..X.X.X.XXX.......XXXXX..X..XX....",
         ".XXX..X.XX.X..X....XXX.X.X.X.XXX..XXX.XXX.X.XX..",
         "XX..X..XXXXX..XX...X.X.....X.X.XX.XX.....XXX.XXX",
         "...X..XXXX...XXXX...X...X..X...X...X.....XX..XXX",
         "X.X.XXXX...XXX....XXX..XX.X...X..X.XXX..X..X....",
         "X..XX.....X..XXX..X.X.X...XXXXXX...XX..XX.XX..XX",
         ".X...X....X.X...XX......XXX............X..X...X.",
         "X.X..XX..XXXX.XX..X......X.XX..X.X..XXX.XXXXXX.." };
    vector <string> maze(maze_, maze_+sizeof(maze_)/sizeof(*maze_)); 
    int startRow = 28;
    int startCol = 14;
    int moveRow_[] = {0, 0, 4, 5, -1, 5, -3, -2, 3, 4, -5, 4, -2, 5, -5, -4, 0, 3, -4, -2, -1, -2, 2, 1, 4, -1, -2, 5, -3, 3};
    vector <int> moveRow(moveRow_, moveRow_+sizeof(moveRow_)/sizeof(*moveRow_)); 
    int moveCol_[] = {-7, 8, 8, -10, 0, 2, -9, -6, -7, 1, -2, 6, -2, -1, -2, -8, 6, 9, -9, 6, 0, 4, -2, -5, -9, -6, 4, -10, -9, -4};
    vector <int> moveCol(moveCol_, moveCol_+sizeof(moveCol_)/sizeof(*moveCol_)); 
	int RetVal = 11; 
	return verify_case(RetVal, MazeMaker().longestPath(maze, startRow, startCol, moveRow, moveCol)); }
*/
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
