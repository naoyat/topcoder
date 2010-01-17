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

vector<set<pair<int,int> > > moves(10);
vector<pair<int,int> > d(8);

class Piece{
 public:
  int x, y, k;
  Piece(int x_, int y_, int k_){x=x_;y=y_;k=k_;}
  /*
  void desc(){
    printf("%d-mover at (%d,%d)\n", k,x,y);
  }
  set<pair<int,int> > possible_moves() {
    set<pair<int,int> > v;
    for(int i=1;i<=k;i++){
      tr(moves[i],it){
        int dx=it->first, dy=it->second;
        int x_=x+dx, y_=y+dy;
        if (0<=x_ && x_<w && 0<=y_ && y_<h){
          v.insert(make_pair(x_,y_));
        }
      }
    }
    return v;
  }
  */
};

class CollectingRiders {
  int w,h;
  int gx,gy;
  bool bd[10][10], bdt[10][10], bdv[10][10];
  
  int moves_needed(int xp,int yp){
    rep(x,w) rep(y,h) bd[x][y]=bdv[x][y]=false;
    int time=0;
    bd[xp][yp]=bdv[xp][yp]=true;
    while (true) {
      int cnt=0;
      rep(x,w) rep(y,h) bdt[x][y]=false;
      rep(x,w) rep(y,h) {
        if (!bd[x][y]) continue;
        rep(i,8){
          int x_=x+d[i].first, y_=y+d[i].second;
          if ((0<=x_ && x_<w) && (0<=y_ && y_<h)) {
            bdt[x_][y_]=true;
            if(!bdv[x_][y_]){ bdv[x_][y_]=true; cnt++; }
          }
        }
      }
      time++;
      if (bdt[gx][gy]) return time;

      rep(x,w) rep(y,h) bd[x][y]=bdt[x][y];
      if (cnt==0) return INT_MAX;
    }
  }
    
 public:
  int minimalMoves(vector<string> board) {
    cout << board << endl;
	h=sz(board), w=board[0].length();

    d[0].first = 2; d[0].second = 1;
    d[1].first = 1; d[1].second = 2;
    d[2].first = -1; d[2].second = 2;
    d[3].first = -2; d[3].second = 1;
    d[4].first = -2; d[4].second = -1;
    d[5].first = -1; d[5].second = -2;
    d[6].first = 1; d[6].second = -2;
    d[7].first = 2; d[7].second = -1;

    moves[0].insert(make_pair(0,0));
    for (int i=1;i<=9;i++){
      tr(moves[i-1],it){
        int x=it->first,y=it->second;
        rep(j,8){
          int dx=d[j].first, dy=d[j].second;
          moves[i].insert(make_pair(x+dx,y+dy));
        }
      }
    }

    vector<Piece*> pieces;
    rep(y,h) rep(x,w){
      int c = board[y][x]; if (c!='.') pieces.pb(new Piece(x,y,c-'0'));
    }

    int minmov=INT_MAX;
    for(gx=0;gx<w;gx++) {
      for(gy=0;gy<h;gy++) {
        tr(pieces,it) {
          Piece* p = *it;
          int mn = moves_needed(p->x,p->y);
          if (mn < 0) goto next_xy;
          int mn_max=mn, mn_min=(mn - 1 + p->k)/p->k;
          if (mn_min<=minmov){
            printf("min (%d..%d) at (%d,%d,k=%d) => (%d,%d)\n", mn_min,mn_max, p->x,p->y,p->k, gx,gy);
          }
          minmov = min(minmov,mn_min);
        }
     next_xy:
        ;
      }
      //next:
      ;
    }
    
    return (minmov==INT_MAX) ? -1 : minmov;
    //tr(pieces,p) (*p)->desc();
    tr(pieces,p) delete *p;
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

