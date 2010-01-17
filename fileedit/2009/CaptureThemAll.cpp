#line 2 "CaptureThemAll.cpp"
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

int ds[8][2] = { {2,1}, {1,2}, {-1,2}, {-2,1}, {-2,-1}, {-1,-2}, {1,-2}, {2,-1} };

class CaptureThemAll {
  inline int pii(int c,int r){ return (c<<3)|r; }
  inline int piic(int p){ return p>>3; }
  inline int piir(int p){ return p&7; }
  
  int cell(string cr){
    int c = (cr[0] - 'a') & 0x07;
    int r = (cr[1] - '1') & 0x07;
    return pii(c,r);
  }
// BEGIN CUT HERE
  void cellpp(int cell){
    int c=piic(cell), r=piir(cell);
    printf("%c%c (%d,%d)", ('a'+c),('1'+r),c,r);
  }
  void pp(int kn,int ro,int qu){
    cout << endl << "  a b c d e f g h " << endl;
    cout << " +-+-+-+-+-+-+-+-+" << endl;
    rep(r,8){
      cout << (1+r) << "|";
      rep(c,8){
        int cr=pii(c,r);
        int ch=((kn==cr)?4:0)+((ro==cr)?2:0)+((qu==cr)?1:0);
        switch(ch){
          case 0: cout << " |"; break;
          case 1: cout << "Q|"; break;
          case 2: cout << "R|"; break;
          case 3: cout << "RQ"; break;
          case 4: cout << "K|"; break;
          case 5: cout << "KQ"; break;
          case 6: cout << "KR"; break;
          case 7: cout << "*|"; break;
        }
      }
      cout << endl << " +-+-+-+-+-+-+-+-+" << endl;
    }
  }
  void boardpp(int board[][8]){
    cout << "    a  b  c  d  e  f  g  h " << endl;
    cout << "  +--+--+--+--+--+--+--+--+" << endl;
    rep(r,8){
      cout << (1+r) << " |";
      rep(c,8){
        int sc=board[c][r];
        if(sc>64) cout << "  |";
        else printf("%2d|",sc);
      }
      cout << endl << "  +--+--+--+--+--+--+--+--+" << endl;
    }
  }
// END CUT HERE

  int chase(int p0,int p1){
// BEGIN CUT HERE
    cout << "chase: "; cellpp(p0); cout << " => "; cellpp(p1); cout << endl;
// END CUT HERE
    int board[8][8];
    rep(c,8) rep(r,8) board[c][r]=INT_MAX;
    int p0c=piic(p0),p0r=piir(p0), p1c=piic(p1),p1r=piir(p1);
    board[p0c][p0r]=0;
    priority_queue<pair<int,int> > pq;
    pq.push(make_pair(0,p0));
    while(!pq.empty()){
      int sc=-pq.top().first, at=pq.top().second;
      pq.pop();
      int atc=piic(at),atr=piir(at);
      rep(i,8){
        int c_=atc+ds[i][0], r_=atr+ds[i][1];
        if(c_<0 || 7<c_ || r_<0 || 7<r_) continue;
        int sc_=sc+1;
        if (c_==p1c && r_==p1r) {
          board[c_][r_]=sc_;
// BEGIN CUT HERE
          boardpp(board); cout << "sc=" << sc_ << endl;
// END CUT HERE
          return sc_;
        }
        if (board[c_][r_]>sc_) {
          board[c_][r_]=sc_;
          pq.push(make_pair(-sc_,pii(c_,r_)));
        }
      }
    }
    return 64;
  }
 public:
  int fastKnight(string knight, string rook, string queen) {
    int kn=cell(knight), ro=cell(rook), qu=cell(queen);
// BEGIN CUT HERE
    /*
    cout << "knight: "; cellpp(kn); cout << endl;
    cout << "  rook: "; cellpp(ro); cout << endl;
    cout << " queen: "; cellpp(qu); cout << endl;
    */
    pp(kn,ro,qu);
// END CUT HERE
    return min( chase(kn,ro)+chase(ro,qu), chase(kn,qu)+chase(qu,ro) );
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
	string knight = "a1"; 
	string rook = "b3"; 
	string queen = "c5"; 
	int RetVal = 2; 
	return verify_case(RetVal, CaptureThemAll().fastKnight(knight, rook, queen)); }
int Test_(Case_<1>) {
	timer_clear();
	string knight = "b1"; 
	string rook = "c3"; 
	string queen = "a3"; 
	int RetVal = 3; 
	return verify_case(RetVal, CaptureThemAll().fastKnight(knight, rook, queen)); }
int Test_(Case_<2>) {
	timer_clear();
	string knight = "a1"; 
	string rook = "a2"; 
	string queen = "b2"; 
	int RetVal = 6; 
	return verify_case(RetVal, CaptureThemAll().fastKnight(knight, rook, queen)); }
int Test_(Case_<3>) {
	timer_clear();
	string knight = "a5"; 
	string rook = "b7"; 
	string queen = "e4"; 
	int RetVal = 3; 
	return verify_case(RetVal, CaptureThemAll().fastKnight(knight, rook, queen)); }
int Test_(Case_<4>) {
	timer_clear();
	string knight = "h8"; 
	string rook = "e2"; 
	string queen = "d2"; 
	int RetVal = 6; 
	return verify_case(RetVal, CaptureThemAll().fastKnight(knight, rook, queen)); }

template<int N> void Run_() { cerr << "Test Case #" << N << "..." << flush; Test_(Case_<N>()); Run_<sizeof(Test_(Case_<N+1>()))==1 ? -1 : N+1>(); }
template<>      void Run_<-1>() {}
int main() { Run_<0>(); }
// END CUT HERE


// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// Harry is playing magical chess. In this version of the game, all pieces move the same way as in regular chess, but players can cast some magical spells. Unfortunately, Harry's opponent, Joe, has captured all of Harry's pieces except one knight; Joe, on the other hand, still has a queen and a rook. The only chance Harry has to win this game is to cast a spell, "Haste", that will allow Harry's knight to make several moves in a row. You should determine the minimal number of moves the knight needs to capture both the rook and the queen, assuming neither of them moves.  You may capture them in either order - rook first or queen first.

You will be given a string, knight, containing information about the knight. You will also be given a string, queen, and a string, rook, giving you information about Joe's pieces. knight, rook and queen will be formatted as "cr", where c is a character between 'a' and 'h', inclusive, determining the column on the board ('a' is the first column, 'h' is the last), and r is a digit between '1' and '8', inclusive, determining the row (1 is the lowest, 8 is the highest).


DEFINITION
Class:CaptureThemAll
Method:fastKnight
Parameters:string, string, string
Returns:int
Method signature:int fastKnight(string knight, string rook, string queen)


NOTES
-A knight's jump moves him 2 cells along one of the axes, and 1 cell along the other one. In other words, if knight is in the (0,0) now, it can be in (-2, -1), (-2, 1), (2, -1), (2, 1), (-1, -2), (1, -2), (-1, 2) or (1, 2) after his move.
-The knight will capture one of Joe's pieces if it ends its move in the cell that the piece occupies.
-The knight cannot jump out of the board.
-A chessboard has 8 rows and 8 columns.


CONSTRAINTS
-knight, rook and queen will all be distinct.
-knight, rook and queen will be formatted as "cr", where c is a lowercase character between 'a' and 'h', inclusive, and r is a digit between '1' and '8', inclusive.


EXAMPLES

0)
"a1"
"b3"
"c5"

Returns: 2

From "a1", the knight can move directly to "b3" and capture the rook.  From there, the knight can move directly to "c5" and capture the queen.

1)
"b1"
"c3"
"a3"

Returns: 3

The rook and the queen are both 1 move away from the knight.  Once the knight captures one of them (it doesn't matter which one), it can return to its starting location, and capture the other piece in one more move.

2)
"a1"
"a2"
"b2"

Returns: 6

The rook and the queen are close, but it takes 6 moves to capture them.

3)
"a5"
"b7"
"e4"

Returns: 3

4)
"h8"
"e2"
"d2"

Returns: 6

*/
// END CUT HERE
