#line 2 "RepaintTheChessboard.cpp"
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
typedef vector<long long> vll;
#define sz(a)  int((a).size())
#define all(c)  (c).begin(),(c).end()
#define tr(c,i)  for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); i++)
#define rep(var,n)  for(int var=0;var<(n);var++)

class RepaintTheChessboard {
  int h,w;
 public:
  ll s2ll(string st, int si){
    ll x=0,m=1;
    rep(i,w){
      int b=(st[i]=='B')?1:0;
      if (i&1) b=1-b;
      if (si&1) b=1-b;
      if (b) x |= m;
      m<<=1;
    }
    return x;
  }
  int minimumChanges(vector<string> board) {
	h=sz(board),w=sz(board[0]);
    vector<ll> bd(h);
    rep(j,h) bd[j] = s2ll(board[j],j);

    int minp=64;
    for(int j=0;j<=h-8;j++){
      for(ll i=0;i<=w-8;i++){
        int tt = 0;
        rep(jj,8) tt += __builtin_popcountll((bd[j+jj] >> i) & 0x00ffLL);
        if (tt>=32) tt=64-tt;
        if (tt<minp) minp=tt;
      }
    }
    return minp;
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
	string board_[] = {"BWBWBWBW",
 "WBWBWBWB",
 "BWBWBWBW",
 "WBWBWBWB",
 "BWBWBWBW",
 "WBWBWBWB",
 "BWBWBWBW",
 "WBWBWBWB"}
;
	  vector <string> board(board_, board_+sizeof(board_)/sizeof(*board_)); 
	int RetVal = 0; 
	return verify_case(RetVal, RepaintTheChessboard().minimumChanges(board)); }
int Test_(Case_<1>) {
	timer_clear();
	string board_[] = {"WBWBWBWB",
 "BWBWBWBW",
 "WBWBWBWB",
 "BWBBBWBW",
 "WBWBWBWB",
 "BWBWBWBW",
 "WBWBWBWB",
 "BWBWBWBW"};
	  vector <string> board(board_, board_+sizeof(board_)/sizeof(*board_)); 
	int RetVal = 1; 
	return verify_case(RetVal, RepaintTheChessboard().minimumChanges(board)); }
int Test_(Case_<2>) {
	timer_clear();
	string board_[] = {"BBBBBBBBBBBBBBBBBBBBBBB",
 "BBBBBBBBBBBBBBBBBBBBBBB",
 "BBBBBBBBBBBBBBBBBBBBBBB",
 "BBBBBBBBBBBBBBBBBBBBBBB",
 "BBBBBBBBBBBBBBBBBBBBBBB",
 "BBBBBBBBBBBBBBBBBBBBBBB",
 "BBBBBBBBBBBBBBBBBBBBBBB",
 "BBBBBBBBBBBBBBBBBBBBBBB",
 "BBBBBBBBBBBBBBBBBBBBBBW"}
;
	  vector <string> board(board_, board_+sizeof(board_)/sizeof(*board_)); 
	int RetVal = 31; 
	return verify_case(RetVal, RepaintTheChessboard().minimumChanges(board)); }
int Test_(Case_<3>) {
	timer_clear();
	string board_[] = {"BBBBBBBBBB",
 "BBWBWBWBWB",
 "BWBWBWBWBB",
 "BBWBWBWBWB",
 "BWBWBWBWBB",
 "BBWBWBWBWB",
 "BWBWBWBWBB",
 "BBWBWBWBWB",
 "BWBWBWBWBB",
 "BBBBBBBBBB"};
	  vector <string> board(board_, board_+sizeof(board_)/sizeof(*board_)); 
	int RetVal = 0; 
	return verify_case(RetVal, RepaintTheChessboard().minimumChanges(board)); }
int Test_(Case_<4>) {
	timer_clear();
	string board_[] = {"WBWBWBWB",
 "BWBWBWBW",
 "WBWBWBWB",
 "BWBBBWBW",
 "WBWBWBWB",
 "BWBWBWBW",
 "WBWBWWWB",
 "BWBWBWBW"};
	  vector <string> board(board_, board_+sizeof(board_)/sizeof(*board_)); 
	int RetVal = 2; 
	return verify_case(RetVal, RepaintTheChessboard().minimumChanges(board)); }
int Test_(Case_<5>) {
	timer_clear();
	string board_[] = {"BWWBWWBWWBWW",
 "BWWBWBBWWBWW",
 "WBWWBWBBWWBW",
 "BWWBWBBWWBWW",
 "WBWWBWBBWWBW",
 "BWWBWBBWWBWW",
 "WBWWBWBBWWBW",
 "BWWBWBWWWBWW",
 "WBWWBWBBWWBW",
 "BWWBWBBWWBWW",
 "WBWWBWBBWWBW"}
;
	  vector <string> board(board_, board_+sizeof(board_)/sizeof(*board_)); 
	int RetVal = 15; 
	return verify_case(RetVal, RepaintTheChessboard().minimumChanges(board)); }

template<int N> void Run_() { cerr << "Test Case #" << N << "..." << flush; Test_(Case_<N>()); Run_<sizeof(Test_(Case_<N+1>()))==1 ? -1 : N+1>(); }
template<>      void Run_<-1>() {}
int main() { Run_<0>(); }
// END CUT HERE


// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
In the attic of your house you found an M×N board, divided into MN unit squares. Some of the squares are black and the others are white. You decided that you will make a chessboard out of the board by cutting out an 8×8 region and throwing away the rest of the board.



The only problem is that the board is not painted in the alternate black/white pattern you need for the chessboard. Thus after you cut out the 8×8 chessboard, you will have to repaint some of the squares. Of course, you can pick which 8×8 region to cut out.



You are given the current colors of the squares as a vector <string> board. Character c in element r of board is 'W' if the cell at coordinates (r,c) is white, and 'B' if it is black. Your task is to find the minimum number of squares you will need to repaint after cutting out the 8×8 region.


DEFINITION
Class:RepaintTheChessboard
Method:minimumChanges
Parameters:vector <string>
Returns:int
Method signature:int minimumChanges(vector <string> board)


NOTES
-On a correctly colored chessboard each square is either black or white, and no two squares that share a side have the same color.   (Note that according to this definition there are two valid colorings: one with a white, the other with a black square in the upper left corner.)


CONSTRAINTS
-board will contain between 8 and 50 elements, inclusive.
-Each element of board will contain between 8 and 50 characters, inclusive.
-All elements of board will have the same length.
-Each character in each element of board will be either 'B' or 'W'.


EXAMPLES

0)
{"BWBWBWBW",
 "WBWBWBWB",
 "BWBWBWBW",
 "WBWBWBWB",
 "BWBWBWBW",
 "WBWBWBWB",
 "BWBWBWBW",
 "WBWBWBWB"}


Returns: 0

This is a perfect chessboard, no repainting (and no cutting) necessary.

1)
{"WBWBWBWB",
 "BWBWBWBW",
 "WBWBWBWB",
 "BWBBBWBW",
 "WBWBWBWB",
 "BWBWBWBW",
 "WBWBWBWB",
 "BWBWBWBW"}

Returns: 1

This is almost a perfect chessboard, except for one square.

(Using 0-based indices, the incorrectly colored square is element 3, character 3 of board.)

2)
{"BBBBBBBBBBBBBBBBBBBBBBB",
 "BBBBBBBBBBBBBBBBBBBBBBB",
 "BBBBBBBBBBBBBBBBBBBBBBB",
 "BBBBBBBBBBBBBBBBBBBBBBB",
 "BBBBBBBBBBBBBBBBBBBBBBB",
 "BBBBBBBBBBBBBBBBBBBBBBB",
 "BBBBBBBBBBBBBBBBBBBBBBB",
 "BBBBBBBBBBBBBBBBBBBBBBB",
 "BBBBBBBBBBBBBBBBBBBBBBW"}


Returns: 31

If we take the 8×8 piece in the lower right corner, we will have one white square, and we will only need 31 more.

3)
{"BBBBBBBBBB",
 "BBWBWBWBWB",
 "BWBWBWBWBB",
 "BBWBWBWBWB",
 "BWBWBWBWBB",
 "BBWBWBWBWB",
 "BWBWBWBWBB",
 "BBWBWBWBWB",
 "BWBWBWBWBB",
 "BBBBBBBBBB"}

Returns: 0

Here we have a perfect chessboard in the middle of the given board.

4)
{"WBWBWBWB",
 "BWBWBWBW",
 "WBWBWBWB",
 "BWBBBWBW",
 "WBWBWBWB",
 "BWBWBWBW",
 "WBWBWWWB",
 "BWBWBWBW"}

Returns: 2

For this board the minimum number of changes is 2: We need to change one black square into a white one, and one white square into a black one.

5)
{"BWWBWWBWWBWW",
 "BWWBWBBWWBWW",
 "WBWWBWBBWWBW",
 "BWWBWBBWWBWW",
 "WBWWBWBBWWBW",
 "BWWBWBBWWBWW",
 "WBWWBWBBWWBW",
 "BWWBWBWWWBWW",
 "WBWWBWBBWWBW",
 "BWWBWBBWWBWW",
 "WBWWBWBBWWBW"}


Returns: 15



*/
// END CUT HERE
