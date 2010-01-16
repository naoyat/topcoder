#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

#define SIZE(X) ((int)(X.size()))
#define LENGTH(X) ((int)(X.length()))
#define MP(X,Y) make_pair(X,Y)
template<class T> inline void checkmax(T &a,T b){if(b>a) a=b;}
typedef pair<int,int> ipair;

//
typedef pair<int,int> i_i;
#define sz(X) ((int)(X.size()))
#define pb push_back
#define rep(var,n)  for(int var=0;var<(n);var++)
//

class MazeMaker
{
public:
  int longestPath(vector<string> G, int sX, int sY, vector<int> mX, vector<int> mY)
      //G: maze
      //sX,sY: startRow, startCol
      //mX,mY: moveRow, moveCol
  {
    vector<i_i> Q;

    int D[60][60];
    memset(D,255,sizeof(D)); // D<60,60> initialized with -1;
    
    int sizeX=sz(G); // X=rows
    int sizeY=sz(G[0]); // Y=cols
    
    D[sX][sY]=0; // D<startpos> = 0
    
    Q.pb(MP(sX,sY)); // Q.pb (cons sX sY)
    rep(cl,sz(Q)){ // for each Q(到達地点リスト) |x,y|
      // 動的にforループの終了地点を調べることができますね
      // てか これってBFSの常套手段？
      // とするとQってqueueか！！！
      // 常に最後尾に足す = 自分の階層より後に実行されることが保証されてる
      printf("cl=%d. sz(Q)=%d",cl,sz(Q));
      int x=Q[cl].first;
      int y=Q[cl].second; // (x . y) = Q[cl]
      rep(i,sz(mX)){ // for each move |mX,mY|
        int x2=x+mX[i];
        int y2=y+mY[i]; // (x2 . y2) = (x . y) + (mX . mY)[i]
        if (x2>=0 && x2<sizeX && y2>=0 && y2<sizeY && D[x2][y2]<0 && G[x2][y2]=='.'){
          D[x2][y2]=D[x][y]+1; //D<x,y>はスタート地点からの距離。-1なら未踏
          Q.pb(MP(x2,y2)); // Q.pb (cons x2 y2)
        }
      }
      printf(" => %d\n",sz(Q));
    }
    int R=0;
    rep(i,sizeX) rep(j,sizeY)
        if (G[i][j]=='.') // for each (i,j) where G[i][j]=='.'
          if (D[i][j]<0) // たどりつけない
            return -1;
          else
            checkmax(R,D[i][j]); // if (R<something) R=something;
    return R;
  }
};
/////////////
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
