#line 2 "JumpingBoard.cpp"
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

#define xy(x,y) (((x)<<6)|(y))
#define x_of(xy) ((xy)>>6)
#define y_of(xy) ((xy)&63)
#define num(c) ((c)=='H')?-1:((c)-'0')

class JumpingBoard {
 public:
  int maxJumps(vector<string> board) {
    int h=sz(board),w=sz(board[0]); // 1-50,1-50,[1-9H]
    set<int> hy;
    queue<pair<int,int> > q;
    q.push(make_pair(0,0));
    int mv=0;
    while(!q.empty()){
      pair<int,int> t=q.front(); q.pop();
      mv=t.first;
      int loc=t.second;
      if(found(hy,loc)) return -1;
      hy.insert(loc);

      int x=x_of(loc), y=y_of(loc);
      int a=num(board[y][x]);

      if(x-a>=0 && board[y][x-a]!='H') q.push(make_pair(mv+1,xy(x-a,y)));
      if(x+a<w && board[y][x+a]!='H') q.push(make_pair(mv+1,xy(x+a,y)));
      if(y-a>=0 && board[y-a][x]!='H') q.push(make_pair(mv+1,xy(x,y-a)));
      if(y+a<h && board[y+a][x]!='H') q.push(make_pair(mv+1,xy(x,y+a)));
    }
    return mv+1;
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
	string board_[] = {"3942178",
 "1234567",
 "9123532"}
;
	  vector <string> board(board_, board_+sizeof(board_)/sizeof(*board_)); 
	int RetVal = 5; 
	return verify_case(RetVal, JumpingBoard().maxJumps(board)); }
int Test_(Case_<1>) {
	timer_clear();
	string board_[] = {"2H3HH4HHH5"};
	  vector <string> board(board_, board_+sizeof(board_)/sizeof(*board_)); 
	int RetVal = 4; 
	return verify_case(RetVal, JumpingBoard().maxJumps(board)); }
int Test_(Case_<2>) {
	timer_clear();
	string board_[] = {"3994",
 "9999",
 "9999",
 "2924"}
;
	  vector <string> board(board_, board_+sizeof(board_)/sizeof(*board_)); 
	int RetVal = -1; 
	return verify_case(RetVal, JumpingBoard().maxJumps(board)); }
int Test_(Case_<3>) {
	timer_clear();
	string board_[] = {"123456",
 "234567",
 "345678",
 "456789"}
;
	  vector <string> board(board_, board_+sizeof(board_)/sizeof(*board_)); 
	int RetVal = 4; 
	return verify_case(RetVal, JumpingBoard().maxJumps(board)); }
int Test_(Case_<4>) {
	timer_clear();
	string board_[] = {"9"}
;
	  vector <string> board(board_, board_+sizeof(board_)/sizeof(*board_)); 
	int RetVal = 1; 
	return verify_case(RetVal, JumpingBoard().maxJumps(board)); }
int Test_(Case_<5>) {
	timer_clear();
	string board_[] = {"2H9HH11",
 "HHHHH11",
 "9HHHH11"}
;
	  vector <string> board(board_, board_+sizeof(board_)/sizeof(*board_)); 
	int RetVal = 2; 
	return verify_case(RetVal, JumpingBoard().maxJumps(board)); }
int Test_(Case_<6>) { // 8
	timer_clear();
	string board_[] = {"4HHH12H12H12H12H12H12H12H12H12H12H12H12H12H12H12H1", "HH21H21H21H21H21H21H21H21H21H21H21H21H21H21H21HHH4", "HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH", "H51HHH12H12H12H12H12H12H12H12H12H12H12H12H12H12H1H", "HHHHH1H21H21H21H21H21H21H21H21H21H21H21H21H21HHH4H", "HHH1H2HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH3HH", "HHH3HH2H12H12H12H12H12H12H12H12H12H12H12H12H12H1HH", "12HH4H21H21H21H21H21H21H21H21H21H21H21H21H21H2HHHH", "HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH1HHHH5HH", "H12H12H12H12H12H12H12H12H12H12H12H12H12H12H12H12H1", "HH21H21H21H21H21H21H21H21H21H21H21H21H21H21H21HHH4", "HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH", "6H1HHH12H12H12H12H12H12H12H12H12H12H12H12H12H12H1H", "1H2HH1H21H21H21H21H21H21H21H21H21H21H21H21H21HHH4H", "HHH1H2HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH3HH", "HHH3HH2H12H12H12H12H12H12H12H12H12H12H12H12H12H1HH", "12HH4H21H21H21H21H21H21H21H21H21H21H21H21H21H2HHHH", "HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH1HHHH5HH", "H12H12H12H12H12H12H12H12H12H12H12H12H12H12H12H12H1", "HH21H21H21H21H21H21H21H21H21H21H21H21H21H21H21HHH4", "HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH", "6H1HHH12H12H12H12H12H12H12H12H12H12H12H12H12H12H1H", "1H2HH1H21H21H21H21H21H21H21H21H21H21H21H21H21HHH4H", "HHH1H2HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH3HH", "HHH3HH2H12H12H12H12H12H12H12H12H12H12H12H12H12H1HH", "12HH4H21H21H21H21H21H21H21H21H21H21H21H21H21H2HHHH", "HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH1HHHH5HH", "H12H12H12H12H12H12H12H12H12H12H12H12H12H12H12H12H1", "HH21H21H21H21H21H21H21H21H21H21H21H21H21H21H21HHH4", "HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH", "6H1HHH12H12H12H12H12H12H12H12H12H12H12H12H12H12H1H", "1H2HH1H21H21H21H21H21H21H21H21H21H21H21H21H21HHH4H", "HHH1H2HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH3HH", "HHH3HH2H12H12H12H12H12H12H12H12H12H12H12H12H12H1HH", "12HH4H21H21H21H21H21H21H21H21H21H21H21H21H21H2HHHH", "HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH1HHHH5HH", "H12H12H12H12H12H12H12H12H12H12H12H12H12H12H12H12H1", "HH21H21H21H21H21H21H21H21H21H21H21H21H21H21H21HHH4", "HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH", "6H1HHH12H12H12H12H12H12H12H12H12H12H12H12H12H12H1H", "1H2HH1H21H21H21H21H21H21H21H21H21H21H21H21H21HHH4H", "HHH1H2HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH3HH", "HHH3HH2H12H12H12H12H12H12H12H12H12H12H12H12H12H1HH", "12HH4H21H21H21H21H21H21H21H21H21H21H21H21H21H2HHHH", "HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH1HHHH5HH", "H12H12H12H12H12H12H12H12H12H12H12H12H12H12H12H12H1", "HH21H21H21H21H21H21H21H21H21H21H21H21H21H21H21HHH4", "HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH", "6H1HHH12H12H12H12H12H12H12H12H12H12H12H12H12H12H1H", "1H2HH1H21H21H21H21H21H21H21H21H21H21H21H21H21HHH4H"};
    vector <string> board(board_, board_+sizeof(board_)/sizeof(*board_)); 
	int RetVal = 1057;
	return verify_case(RetVal, JumpingBoard().maxJumps(board)); }


template<int N> void Run_() { cerr << "Test Case #" << N << "..." << flush; Test_(Case_<N>()); Run_<sizeof(Test_(Case_<N+1>()))==1 ? -1 : N+1>(); }
template<>      void Run_<-1>() {}
int main() { Run_<0>(); }
// END CUT HERE


// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
You are given a rectangular board where each cell contains either an integer between 1 and 9, inclusive, or a hole.



Place a token into the cell in the upper left corner of the board.
Now you can play a simple game. The game consists of moves, and each move
looks as follows:



Look at the number X written in the cell where your token is placed.
Choose one of the four basic directions (up, down, left, or right).
Move your token exactly X cells in the chosen direction.  You can jump over all intermediate holes in the path.



The game ends after a move that lands the token in a hole or outside the board.
Your goal is to make as many moves as possible.



The board is given as a vector <string> board.
Characters '1' to '9' represent cells containing the corresponding integer, and
letters 'H' represent holes.
The upper left corner of the
board corresponds to the first character of the first element of board.



Write a method that will compute the maximum number of moves you can make on the
given board. If it is possible to make an arbitrarily large number of moves,
your method should return -1.



DEFINITION
Class:JumpingBoard
Method:maxJumps
Parameters:vector <string>
Returns:int
Method signature:int maxJumps(vector <string> board)


CONSTRAINTS
-board will contain between 1 and 50 elements, inclusive.
-Each element of board will contain between 1 and 50 characters, inclusive.
-All elements of board will be of the same length.
-Each element of board will only contain characters from the string "123456789H" (quotes for clarity).
-The first character of the first element of board will not be 'H'.


EXAMPLES

0)
{"3942178",
 "1234567",
 "9123532"}


Returns: 5

In the first move you have to move the token to the right. In the second move you
have three choices. Moves to the left and to the right would bring you to cells
with a 9 and a 7, respectively, forcing you to end the game in the third move. 
The optimal strategy is to make the second move down, the third one to the right,
and the fourth one up or to the left. In the last fifth move you are forced to leave
the board.


1)
{"2H3HH4HHH5"}

Returns: 4

Remember that you are allowed to jump over holes.  Only landing in a hole is bad.

2)
{"3994",
 "9999",
 "9999",
 "2924"}


Returns: -1

Make the first move down, and then you can jump left and right as many times as you wish.


3)
{"123456",
 "234567",
 "345678",
 "456789"}


Returns: 4

On this board, all moves that don't end the game lead to the right or down.
In the best solution, the first three moves are: right, down, right.


4)
{"9"}


Returns: 1

There is no real choice here.  The game will always end after the first move.

5)
{"2H9HH11",
 "HHHHH11",
 "9HHHH11"}


Returns: 2



*/
// END CUT HERE
