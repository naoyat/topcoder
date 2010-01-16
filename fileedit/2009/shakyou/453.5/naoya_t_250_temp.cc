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
	//priority_queue<i_ii> pq;
    vector<vector<int> > vd(N,vector<int>(M,INT_MAX)); int vdc=0;
    //pq.push(cons(0,cons(startRow,startCol)));
    //while(pq.empty()){
    vector<vector<i_i> > v(2,vector<i_i>(0));
    v[0].pb( cons(startRow,startCol) );
    //int step=0;
    for(int i=0;;i++){
      int i0=i%2, i1=(i+1)%2;
      v[i1].clear();
      tr(v[i0],it){
        int r=it->first, c=it->second;
        //printf("> %d (%d,%d)\n", i,r,c);
        if (maze[r][c]=='X') continue;
        if (vd[r][c]<i) continue;
        if (vd[r][c]==INT_MAX) vdc++;
        vd[r][c]=i;
        if (vdc == NM) break;
        rep(z,Z){
          //step++;
          int r2 = r + moveRow[z]; if (r2 < 0 || N <= r2) continue;
          int c2 = c + moveCol[z]; if (c2 < 0 || M <= c2) continue;
          v[i1].pb( cons(r2,c2) );
        }
      }
      if (sz(v[i1])==0) break;
    }
    //printf("step=%d\n", step);
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
#include "cout.h"
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

template<int N> void Run_() { cerr << "Test Case #" << N << "..." << flush; Test_(Case_<N>()); Run_<sizeof(Test_(Case_<N+1>()))==1 ? -1 : N+1>(); }
template<>      void Run_<-1>() {}
int main() { Run_<0>(); }
