#line 2 "KnightsTour.cpp"
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

//int knight[8][2] = { {-2,-1}, {-2,1}, {-1,-2}, {-1,2}, {1,-2}, {1,2}, {2,-1}, {2,1} };
int knight[8][2] = { {-1,-2}, {1,-2}, {-2,-1}, {2,-1}, {-2,1}, {2,1}, {-1,2}, {1,2} };

class KnightsTour {
  bool vi[8][8];

 public:
  int an(int kr,int kc){
    int v=0;
    rep(i,8){
      int r_=kr+knight[i][0],
          c_=kc+knight[i][1];
      if (r_<0||7<r_||c_<0||7<c_) continue;
      if(!vi[r_][c_]) v++;
    }
    return v;
  }
  int visitedPositions(vector<string> board) {
    //    int an[8][8], vc=1;
	int kr,kc;
    rep(r,8){
      rep(c,8){
        //an[r][c]=0;
        switch(board[r][c]){
          case '.':
            vi[r][c]=false; break;
          case 'K':
            vi[kr=r][kc=c]=true; break;
          case '*':
            vi[r][c]=true; break;
        }
      }
    }

    for(int s=1;;s++){
// BEGIN CUT HERE
      //      printf("s=%d; knight at (%d,%d)\n", s,kr,kc);
// END CUT HERE
      priority_queue<pair<int,int> > pq;
      rep(i,8){
        int r_=kr+knight[i][1],
            c_=kc+knight[i][0];
// BEGIN CUT HERE
        //        printf(" #%d (%d,%d)+(%d,%d)=%d,%d ..",i,
        //               kr,kc, knight[i][1],knight[i][0], r_,c_);
// END CUT HERE
        if (r_<0||7<r_||c_<0||7<c_) continue;
        if(vi[r_][c_]) continue;
// BEGIN CUT HERE
        // cout << " pq << " << make_pair(-an(r,c),-i) << endl;
// END CUT HERE
        pq.push(make_pair(-an(r_,c_),-i));
      }
      if (pq.empty()) {
// BEGIN CUT HERE
        //        cout << " // empty " << endl;
// END CUT HERE
        return s;
      }
      int j=-pq.top().second;

// BEGIN CUT HERE
      /*
      while(!pq.empty()){
                cout << " " << pq.top() ;
        pq.pop();
      }
            printf(" ... i=%d (%d,%d);;; \n",j, knight[j][1],knight[j][0]);
      */
// END CUT HERE
      
      kr+=knight[j][1]; kc+=knight[j][0];
      vi[kr][kc]=true;
    }
    return 64;
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
	string board_[] = {"........"
,".*.*...."
,".*......"
,"..K...*."
,"*...*..."
,"...*...."
,"...*.*.."
,"........"};
	  vector <string> board(board_, board_+sizeof(board_)/sizeof(*board_)); 
	int RetVal = 39; 
	return verify_case(RetVal, KnightsTour().visitedPositions(board)); }
int Test_(Case_<1>) {
	timer_clear();
	string board_[] = {"K......."
,"........"
,"........"
,"........"
,"........"
,"........"
,"........"
,"........"};
	  vector <string> board(board_, board_+sizeof(board_)/sizeof(*board_)); 
	int RetVal = 64; 
	return verify_case(RetVal, KnightsTour().visitedPositions(board)); }
int Test_(Case_<2>) {
	timer_clear();
	string board_[] = {"********"
,"*******."
,"********"
,"**.***.*"
,"********"
,"***.*.**"
,"********"
,"****K***"};
	  vector <string> board(board_, board_+sizeof(board_)/sizeof(*board_)); 
	int RetVal = 3; 
	return verify_case(RetVal, KnightsTour().visitedPositions(board)); }
int Test_(Case_<3>) {
	timer_clear();
	string board_[] = {"*.*....*"
,".......*"
,"**...*.."
,"..***..."
,".**.*..."
,"..*.*..K"
,"..***.*."
,"**...*.."};
	  vector <string> board(board_, board_+sizeof(board_)/sizeof(*board_)); 
	int RetVal = 17; 
	return verify_case(RetVal, KnightsTour().visitedPositions(board)); }
int Test_(Case_<4>) {
	timer_clear();
	string board_[] = {"..*...*."
,"**.....*"
,"*..*...."
,"*..*...."
,".....*.."
,"....*..K"
,"**.*...*"
,"..**...."};
	  vector <string> board(board_, board_+sizeof(board_)/sizeof(*board_)); 
	int RetVal = 27; 
	return verify_case(RetVal, KnightsTour().visitedPositions(board)); }

template<int N> void Run_() { cerr << "Test Case #" << N << "..." << flush; Test_(Case_<N>()); Run_<sizeof(Test_(Case_<N+1>()))==1 ? -1 : N+1>(); }
template<>      void Run_<-1>() {}
int main() { Run_<0>(); }
// END CUT HERE


// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// Facebook engineers love playing chess. They also like to play other games on the chessboard. Today, they were wondering how many cells a knight would visit on the chessboard if it followed some predefined algorithm.

You are given a vector <string> board describing a standard 8x8 chessboard, where the c-th character of the r-th element corresponds to the cell in row r, column c.  Some cells are blocked and cannot be jumped into. These will be represented with a '*'. All other cells are marked with a '.', except for the starting position of the knight, which is marked with a 'K'.

A valid jump for a knight consists of shifting one square along one axis and two squares along the other axis.  A cell is "accessible" if it is not blocked and it has not been visited by the knight before.  The starting position of the knight is considered to be visited, and each time the knight jumps into a new cell, that cell becomes visited.  The accessibility number of a cell is the number of accessible cells that the knight can make a valid jump to from that cell.  Note that accessibility numbers of cells may change as the knight moves through the board and visits more cells.

The knight will use the following simple algorithm to traverse the board.  On each move, it will make a valid jump into the accessible cell with the lowest accessibility number.  In case of a tie, it will choose the one with the lowest row number, and if there is still a tie, it will choose the one among them with the lowest column number.  The knight will stop moving when it can no longer make a valid jump into an accessible cell.

Return the number of cells that the knight will visit (including the starting cell).

DEFINITION
Class:KnightsTour
Method:visitedPositions
Parameters:vector <string>
Returns:int
Method signature:int visitedPositions(vector <string> board)


CONSTRAINTS
-board will contain exactly 8 elements.
-Each element of board will contain exactly 8 characters '.', 'K' or '*'.
-Character 'K' will appear exactly once in board.


EXAMPLES

0)
{"........"
,".*.*...."
,".*......"
,"..K...*."
,"*...*..."
,"...*...."
,"...*.*.."
,"........"}

Returns: 39

From its starting cell K, the knight can jump to cells A, B and C, which have accessibility numbers of 3, 6 and 4, respectively (see first image below).  It will jump to cell A because it has the lowest accessibility number.

From cell A, it can then jump to cells D, E and F, which have accessibility numbers of 1, 3 and 4, respectively (see second image).  It will choose cell D.  It will continue in this fashion and visit a total of 39 cells.

  


1)
{"K......."
,"........"
,"........"
,"........"
,"........"
,"........"
,"........"
,"........"}

Returns: 64

If no cells are blocked, then the knight will end up visiting every cell by following the given algorithm.

2)
{"********"
,"*******."
,"********"
,"**.***.*"
,"********"
,"***.*.**"
,"********"
,"****K***"}

Returns: 3

From its starting cell K, the knight can jump to cells A and B, which have accessibility numbers of 1 (see the image). Both A and B have the same accessibility number and the same row number, so it will jump to A because it has the lowest column number. It will then jump to C and stop, visiting a total of 3 cells.

  


3)
{"*.*....*"
,".......*"
,"**...*.."
,"..***..."
,".**.*..."
,"..*.*..K"
,"..***.*."
,"**...*.."}

Returns: 17



4)
{"..*...*."
,"**.....*"
,"*..*...."
,"*..*...."
,".....*.."
,"....*..K"
,"**.*...*"
,"..**...."}

Returns: 27



*/
// END CUT HERE
