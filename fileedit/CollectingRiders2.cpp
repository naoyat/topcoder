// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// A rider is a fantasy chess piece that can jump like a knight several times in a single move. (See notes for a description of how a knight jumps.) A rider that can perform a maximum of K jumps during a single move is denoted as a K-rider. For example, a 2-rider can jump once or twice during a single move, and a 1-rider is a traditional knight.



There are some riders of different types on a chessboard.  You are given a vector <string> board representing the layout of the pieces.  The j-th character of the i-th element of board is the content of the square at row i, column j.  If the character is a digit K between '1' and '9', the square contains a K-rider.  Otherwise, if the character is a '.', the square is empty. Return the minimal total number of moves necessary to move all the riders to the same square. Only one piece can move during each move. Multiple riders can share the same squares at all times during the process. Return -1 if it is impossible. 

DEFINITION
Class:CollectingRiders
Method:minimalMoves
Parameters:vector <string>
Returns:int
Method signature:int minimalMoves(vector <string> board)


NOTES
-A traditional knight has up to 8 moves from a square with coordinates (x,y) to squares (x+1,y+2), (x+1,y-2), (x+2,y+1), (x+2,y-1), (x-1,y+2), (x-1,y-2), (x-2,y+1), (x-2,y-1), and can not move outside the chessboard.


CONSTRAINTS
-board will contain between 1 and 10 elements, inclusive.
-Each element of board will contain between 1 and 10 characters, inclusive.
-All elements of board will have the same length.
-board will contain only positive digits ('1'-'9') and '.' characters.
-board will contain at least one digit.


EXAMPLES

0)
{"...1",
 "....",
 "2..."}

Returns: 2

The 2-rider can jump from (2,0) to (0,1) in the first move, and then from (0,1) to (2,2) to (0,3) in the second.

1)
{"........",
 ".1......",
 "........",
 "....3...",
 "........",
 "........",
 ".7......",
 "........"}

Returns: 2

In 2 moves, we can move all the pieces to the cell initially occupied by the 1-rider.

2)
{"..",
 "2.",
 ".."}

Returns: 0

No moves are necessary.

3)
{".1....1."}

Returns: -1



4)
{"9133632343",
 "5286698232",
 "8329333369",
 "5425579782",
 "4465864375",
 "8192124686",
 "3191624314",
 "5198496853",
 "1638163997",
 "6457337215"}

Returns: 121

Kind of maximal test.

*/
// END CUT HERE

#line 91 "CollectingRiders.cpp"
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

#define sz(a)  int((a).size())
#define pb  push_back
#define all(c)  (c).begin(),(c).end()
#define tr(c,i)  for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); i++)
#define rep(var,n)  for(int var=0;var<(n);var++)
#define found(s,e)  ((s).find(e)!=(s).end())
#define remove_(c,val) (c).erase(remove((c).begin(),(c).end(),(val)),(c).end())

class CollectingRiders {
  int w,h;
  vector<int> dx,dy;

  set<pair<int,int> > moves(int x, int y, int k){
    vector<vector<bool> > b(w);
    rep(i,w) { b[i].resize(h);
      rep(j,h) b[i][j] = false;
    }
    b[x][y]=true;
    rep(t,k){
      rep(i,w) {
        rep(j,h) {
          if (!b[i][j]) continue;
          rep(o,8){
            int x_=i+dx[o], y_=j+dy[o];
            if(0<=x_ && x_<w && 0<=y_ && y_<h){
              b[x_][y_] = true;
            }
          }
        }
      }
    }
    if(k==1) b[x][y]=false;

    set<pair<int,int> > s;
    rep(i,w) rep(j,h) if(b[i][j]) s.insert(make_pair(i,j));
    printf("moves(%d,%d,%d) => ", x,y,k); cout << s << endl;
    return s;
  }
  
 public:
  int minimalMoves(vector<string> board) {
    cout << board << endl;
	h=sz(board), w=board[0].length();

    dx.resize(8); dy.resize(8);
    dx[0] =  2; dy[0] =  1;
    dx[1] =  1; dy[1] =  2;
    dx[2] = -1; dy[2] =  2;
    dx[3] = -2; dy[3] =  1;
    dx[4] = -2; dy[4] = -1;
    dx[5] = -1; dy[5] = -2;
    dx[6] =  1; dy[6] = -2;
    dx[7] =  2; dy[7] = -1;

    int np=0;
    vector<int> px, py, pk;
    rep(y,h) rep(x,w){
      int c = board[y][x]; if (c!='.') {
        px.pb(x); py.pb(y); pk.pb(c-'0');
        printf("px[%d]=%d, py[%d]=%d, pk[%d]=%d\n",
               np,px[np], np,py[np], np,pk[np]);
        np++;
      }
    }

    printf("width=%d, height=%d, pieces=%d\n", w,h,np);

    vector<vector<vector<bool> > > b(np), bt(np), bv(np);
    vector<int> g(np,0);
    rep(i,np){
      b[i].resize(w); bt[i].resize(w); bv[i].resize(w);
      rep(x,w){
        b[i][x].resize(h); bt[i][x].resize(h); bv[i][x].resize(h);
        rep(y,h){
          b[i][x][y] = bv[i][x][y] = false;
        }
      }
    }
    rep(i,np) b[i][px[i]][py[i]] = true;
    /*rep(i,np) {printf("b[%d][px[%d]=%d][py[%d]=%d] = true, pk[%d]=%d;\n",
      i, i,px[i],  i,py[i], i,pk[i]);}*/

    int time=0;
    while(true){
      cout << "time:" << time << endl;
      rep(x,w) {
        rep(y,h) {
          rep(i,np){
            if (!b[i][x][y]) goto next_piece;
          }
          printf("meeting at (%d,%d)\n", x, y);
          return time;
       next_piece:
          ;
        }
      }

      time++;

      //int g=0;
      rep(i,np) {
        printf("piece #%d:\n", i);
        rep(x,w) rep(y,h) bt[i][x][y] = false;

        rep(x,w) rep(y,h){
          if (!b[i][x][y]) continue;
          //for(int k=pk[i];k>=1;k--){
          //for(int k=pk[i];k>=1;k--) {
          set<pair<int,int> > ms = moves(x,y,pk[i]);
          tr(ms,m) {
            int x_ = m->first, y_ = m->second;
            printf("  (%d,%d) => (%d,%d)\n", x,y, m->first,m->second);
            bt[i][x_][y_] = true;
            if(!bv[i][x_][y_]){
              bv[i][x_][y_]=true;
              //g++;
            }
          }
        }
        //if(g[i]==0) return -1;
        rep(x,w) rep(y,h) b[i][x][y] = bt[i][x][y];
      }
      //if (g==0) return -1;
      if (time>121) break;
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
	string board_[] = {"...1",
 "....",
 "2..."};
	  vector <string> board(board_, board_+sizeof(board_)/sizeof(*board_)); 
	int RetVal = 2; 
	return verify_case(RetVal, CollectingRiders().minimalMoves(board)); }
int Test_(Case_<1>) {
	timer_clear();
	string board_[] = {"........",
 ".1......",
 "........",
 "....3...",
 "........",
 "........",
 ".7......",
 "........"};
	  vector <string> board(board_, board_+sizeof(board_)/sizeof(*board_)); 
	int RetVal = 2; 
	return verify_case(RetVal, CollectingRiders().minimalMoves(board)); }
int Test_(Case_<2>) {
	timer_clear();
	string board_[] = {"..",
 "2.",
 ".."};
	  vector <string> board(board_, board_+sizeof(board_)/sizeof(*board_)); 
	int RetVal = 0; 
	return verify_case(RetVal, CollectingRiders().minimalMoves(board)); }
int Test_(Case_<3>) {
	timer_clear();
	string board_[] = {".1....1."};
	  vector <string> board(board_, board_+sizeof(board_)/sizeof(*board_)); 
	int RetVal = -1; 
	return verify_case(RetVal, CollectingRiders().minimalMoves(board)); }
int Test_(Case_<4>) {
	timer_clear();
	string board_[] = {"9133632343",
 "5286698232",
 "8329333369",
 "5425579782",
 "4465864375",
 "8192124686",
 "3191624314",
 "5198496853",
 "1638163997",
 "6457337215"};
	  vector <string> board(board_, board_+sizeof(board_)/sizeof(*board_)); 
	int RetVal = 121; 
	return verify_case(RetVal, CollectingRiders().minimalMoves(board)); }

template<int N> void Run_() { cerr << "Test Case #" << N << "..." << flush; Test_(Case_<N>()); Run_<sizeof(Test_(Case_<N+1>()))==1 ? -1 : N+1>(); }
template<>      void Run_<-1>() {}
int main() { Run_<0>(); }
// END CUT HERE

