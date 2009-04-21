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
// BEGIN CUT HERE
#define tr(c,i)  for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); i++)
#define rep(var,n)  for(int var=0;var<(n);var++)
#define forr(var,from,to) for(int var=(from);var<=(to);var++) 
#define remove_(c,val) (c).erase(remove((c).begin(),(c).end(),(val)),(c).end())
#define lastc(str) (*((str).end()-1))
// END CUT HERE
#define found(s,e)  ((s).find(e)!=(s).end())
#define xy(x,y) (((x)<<6)|(y))
#define x_of(xy) ((xy)>>6)
#define y_of(xy) ((xy)&63)
#define num(c) ((c)=='H')?-1:((c)-'0')

class JumpingBoard {
  vs orig;
  bool bd[50][50];
  int h,w;
  map<int,int> memo;
  
  int sub(int mv,int x,int y){
    int key=xy(x,y);
    if(found(memo,key)) return mv+memo[key];
    if(bd[x][y]) return -1;
    bd[x][y]=true;
    int a=num(orig[y][x]);
    int rmax=mv+1;
    if(x>=a && orig[y][x-a]!='H') {
      int r=sub(mv+1,x-a,y); if(r==-1) return -1;
      rmax=max(rmax,r);
    }
    if(x+a<w && orig[y][x+a]!='H') {
      int r=sub(mv+1,x+a,y); if(r==-1) return -1;
      rmax=max(rmax,r);
    }
    if(y>=a && orig[y-a][x]!='H') {
      int r=sub(mv+1,x,y-a); if(r==-1) return -1;
      rmax=max(rmax,r);
    }
    if(y+a<h && orig[y+a][x]!='H') {
      int r=sub(mv+1,x,y+a); if(r==-1) return -1;
      rmax=max(rmax,r);
    }
    bd[x][y]=false;
    memo[key]=rmax-mv;
    return rmax;
  }
 public:
  int maxJumps(vector<string> board) {
    orig=board;
    h=sz(board); w=sz(board[0]); // 1-50,1-50,[1-9H]
    mset(bd,0);
    return sub(0,0,0);
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
 "9HHHH11"};
	  vector <string> board(board_, board_+sizeof(board_)/sizeof(*board_)); 
	int RetVal = 2; 
	return verify_case(RetVal, JumpingBoard().maxJumps(board)); }
int Test_(Case_<6>) { // 8
	timer_clear();
	string board_[] = {"4HHH12H12H12H12H12H12H12H12H12H12H12H12H12H12H12H1", "HH21H21H21H21H21H21H21H21H21H21H21H21H21H21H21HHH4", "HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH", "H51HHH12H12H12H12H12H12H12H12H12H12H12H12H12H12H1H", "HHHHH1H21H21H21H21H21H21H21H21H21H21H21H21H21HHH4H", "HHH1H2HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH3HH", "HHH3HH2H12H12H12H12H12H12H12H12H12H12H12H12H12H1HH", "12HH4H21H21H21H21H21H21H21H21H21H21H21H21H21H2HHHH", "HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH1HHHH5HH", "H12H12H12H12H12H12H12H12H12H12H12H12H12H12H12H12H1", "HH21H21H21H21H21H21H21H21H21H21H21H21H21H21H21HHH4", "HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH", "6H1HHH12H12H12H12H12H12H12H12H12H12H12H12H12H12H1H", "1H2HH1H21H21H21H21H21H21H21H21H21H21H21H21H21HHH4H", "HHH1H2HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH3HH", "HHH3HH2H12H12H12H12H12H12H12H12H12H12H12H12H12H1HH", "12HH4H21H21H21H21H21H21H21H21H21H21H21H21H21H2HHHH", "HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH1HHHH5HH", "H12H12H12H12H12H12H12H12H12H12H12H12H12H12H12H12H1", "HH21H21H21H21H21H21H21H21H21H21H21H21H21H21H21HHH4", "HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH", "6H1HHH12H12H12H12H12H12H12H12H12H12H12H12H12H12H1H", "1H2HH1H21H21H21H21H21H21H21H21H21H21H21H21H21HHH4H", "HHH1H2HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH3HH", "HHH3HH2H12H12H12H12H12H12H12H12H12H12H12H12H12H1HH", "12HH4H21H21H21H21H21H21H21H21H21H21H21H21H21H2HHHH", "HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH1HHHH5HH", "H12H12H12H12H12H12H12H12H12H12H12H12H12H12H12H12H1", "HH21H21H21H21H21H21H21H21H21H21H21H21H21H21H21HHH4", "HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH", "6H1HHH12H12H12H12H12H12H12H12H12H12H12H12H12H12H1H", "1H2HH1H21H21H21H21H21H21H21H21H21H21H21H21H21HHH4H", "HHH1H2HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH3HH", "HHH3HH2H12H12H12H12H12H12H12H12H12H12H12H12H12H1HH", "12HH4H21H21H21H21H21H21H21H21H21H21H21H21H21H2HHHH", "HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH1HHHH5HH", "H12H12H12H12H12H12H12H12H12H12H12H12H12H12H12H12H1", "HH21H21H21H21H21H21H21H21H21H21H21H21H21H21H21HHH4", "HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH", "6H1HHH12H12H12H12H12H12H12H12H12H12H12H12H12H12H1H", "1H2HH1H21H21H21H21H21H21H21H21H21H21H21H21H21HHH4H", "HHH1H2HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH3HH", "HHH3HH2H12H12H12H12H12H12H12H12H12H12H12H12H12H1HH", "12HH4H21H21H21H21H21H21H21H21H21H21H21H21H21H2HHHH", "HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH1HHHH5HH", "H12H12H12H12H12H12H12H12H12H12H12H12H12H12H12H12H1", "HH21H21H21H21H21H21H21H21H21H21H21H21H21H21H21HHH4", "HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH", "6H1HHH12H12H12H12H12H12H12H12H12H12H12H12H12H12H1H", "1H2HH1H21H21H21H21H21H21H21H21H21H21H21H21H21HHH4H"};
    vector <string> board(board_, board_+sizeof(board_)/sizeof(*board_)); 
	int RetVal = 1057;
	return verify_case(RetVal, JumpingBoard().maxJumps(board)); }
int Test_(Case_<7>) {
	timer_clear();
	string board_[] = {"1HHHHH2HHHH512HHHHHHHHHHHHH6HH9HH1H8HH31HHHHHHHHHH", "6HHHHH5H5HHHHHHHH3HH56137H24H71HH44HHHHHHHHHHHHHHH", "HHH4HH81HH7H9HHH7HHH8H63HHHHHHHHHHHHHHHHHHHHHHHH6H", "HHHHHHH4HH4HH55HHH76HHHHH8HHHHHHH1HHHHHHH16HHHHHHH", "HHHHHHHHHH1HHH4H2HHHHHH7HHHHHHHHH7HHHHHHHHHH5H8H9H", "HHHHHHHHHHHHHHHHHHH214HHH3HHHHHHHH9H22H938HH19H617", "7HHHHH6H6HHHHHHHHHHH3HHHHHHHHHHHHHH4HHH91H2HHHHH4H", "HHHH21H16HHH7H9HHHHHHHHHHHHHHHHHHH6HHHHH2H3H3HHH4H", "HHHHHHHH95HHHH7HH3H77H59H22HHHHH2HHHHHHHH5HHHHHH1H", "HHHH8HHHHHHH9HHHHHHH5HHHHHH7H6HHHH5H3HHHH9473H5HHH", "HHHH9H2HHHHHH6HHHHH2HHHHHH9HHHHH8HHHHHHH421HHHHHHH", "HHHHHHHHHH9H4HHHHH4HHHHHHH8HHHHHH3HH5HHH6HH3HHHHHH", "HHHHHHHH9HHH3H8HH1HH6HHHHHHHHHHH9HH31HHHHHHHHH5H81", "6HHHHHHHHHHHHHHHH8HH8H2HHHH4HHHHHHHHH2H4HH53HHHH7H", "HHHHHHHH6HHH2H7H88HH3HHHHH31HHHH5HH8HHHH9H8H9HHHH7", "HHHHHHHHH6HH7H1HHH9H9H5HHHHHH7HH1HHHHHH7HHHHHHHHHH", "HHHHHHHHH8HHHHHHHHHHHHHH7H8HHHH5HH9H6HHHHH35H7HHHH", "HHHHHHHHHHHHHHHHHHHHHHHH1HHHHHHHHHH1HHHHH4H8HH3HHH", "HHHHHHHH2H7HHHHHHH6H7HHH7H419HHHHHH8HHHHH1H9HHHHHH", "3HHHHHH4HHH3HHHHH8HHHHHHH9HHHHHHHHHHHHHHHHHHHHHHHH", "HHHHHHH1H4HHHHHHHHHH8H2H1HHHHHHHHHH6HHHHHHHHHHHHHH", "7HHHHHH2H4HHHHHH717HHHHH62HHHHH31281HH7H451HHH6HHH", "1HHHHHHHHH642HH9H4HHHHHH2H8H3HHHHHHHHHHHHH9H8HHHHH", "HHHHHHH9HHHH2H7H645H5H4H5833H9H4HHHHH2H7HHHHH8HHHH", "HHHHHHHHHHHHHHHHHHHH3HH273HH6HHHH72H3HHH3HH12HHHHH", "HHHHHHHHH5HHHHHHHHHHHH9H5H7H6HHH9HHH87HH85HHHHHHHH", "HHHHHHHHHHH8HHHHH9H9HHHHHH6HHHH3HHHHHH5H9HHHHHHHHH", "HH6HHHHH9H3918HHHHH5213HHH6H5HHHHHHHHHHH1HHH4HHHHH", "3HH5HHHHHH82HHHHHHH8H5HH963HHHHHH6HHHHHHHHHHHHHHHH", "6H2H3219H18HH4HHHHHHHHHHHH9HHHHHHHHHHHH8HHHHHHHHHH", "HHHHHHHHHHHHH6HHHHHHHHH3H3HH5HHHH1HHHH61HH182HHHHH", "HHHHHHH66HHH8H2HHHHHHHHHH6HHH4H9H589HHHHHHHHHHHHHH", "HHHH2HHH1HHHHHH72H92H86HH254H2HHHH9H3169HH8HHHHHH9", "HHH4HHH2HH6H67HHHHH95H34HHH6HHHHH85H5H54HH8HH3HHHH", "HHHH3396HHHH618HHHHH2H1HHH5HHHHH69HH6HHHHH2HHHHHH2", "HH9HHHH46HHH4HHHHHH2HHHHH22H3HHH3HHH48HHHHHH8HHHHH", "HHHHHHHHHH4H67H4H61H8742HH39HHHHH796HHHHHHH81HHHHH", "HHHHH967HHHH27HHHHH4HHHHH18HHHHHHHH62HH3HHH9HHHHHH", "9H73H28H4HH851HHHHHH4HHHHH8HHHHH18794H3HHHH62HHHH4", "HHHHHHHHHHHHHH6HHH4H8HHHHHHHHHHHHH5HHH6HHHHHHHHHHH", "HH693HHHHH7HHHHHHHH45HH9H73H49H6HHHH85HHHHH3H7HHHH", "HHHHHHHH3HHHH1HHHHHHHH9H2HHHH2HH39HHH5HHHHHHH8HHH4", "HHH2H831HHHH8975H9HHHHHHHH2HHHHHHHH586HHHHH2HH9HHH", "HH8H154HHHHHHHH7HHH3824HHH8H39HH9HHHH6HHHHHHHHHHHH", "6H43HHH15H5HH3HHHHHHH69HHHH36H7HHH8HH15HHHHHHHHHHH", "HH4HHHH4HHH7HHHHHH6HHHHHH71HHHHHHHHHHHHHHHHHHHHHHH", "HH8H619HHHH2H8H64HHH52HHHHHHHHHHHHHHHHHHHHH2H6HHHH", "HHH8HHH19HH4HHH3HH1H7HHHH9HHH2H14H5HH91HHHH16H5HHH", "HHHHHHHHHHHHHHH5HH66HH5H93HH6HHHHHHHHHHHHHHHHHHHHH", "6H22749HH966H6H734H1HHH6HHHHHHHHH3H82266HHH29HHHHH"};
	  vector <string> board(board_, board_+sizeof(board_)/sizeof(*board_)); 
	int RetVal = 592;
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
