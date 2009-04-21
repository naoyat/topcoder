// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
Two players play a simple game on a n x n board.  The first player has a single white checker which is initially located at (rowWhite, colWhite).  The second player has a single black checker which is initially located at (rowBlack, colBlack).  All coordinates are 1-based.  The two players alternate turns, and the first player moves first.



When it is the first player's turn, he chooses one of four directions (up, down, left or right) and moves his checker one cell in the chosen direction.  When it is the second player's turn, he also chooses one of those four directions and moves his checker one or two cells in the chosen direction.  A player wins the game when his move puts his checker in the cell occupied by his opponent's checker.



Both players use an optimal game strategy.  If the player can win, he will follow the strategy that minimizes the number of moves in the game.  If the player cannot win, he will follow the strategy that maximizes the number of moves in the game.



If the first player will win, return "WHITE x", and if the second player will win, return "BLACK x", where x is the number of moves in the game (all quotes for clarity).



DEFINITION
Class:TheEasyChase
Method:winner
Parameters:int, int, int, int, int
Returns:string
Method signature:string winner(int n, int rowWhite, int colWhite, int rowBlack, int colBlack)


CONSTRAINTS
-n will be between 2 and 20, inclusive.
-rowWhite will be between 1 and n, inclusive.
-colWhite will be between 1 and n, inclusive.
-rowBlack will be between 1 and n, inclusive.
-colBlack will be between 1 and n, inclusive.
-(rowWhite, colWhite) and (rowBlack, colBlack) will represent different cells.


EXAMPLES

0)
2
1
1
2
2

Returns: "BLACK 2"

There are two possible moves for the first player. But he will lose the game anyway.

1)
2
2
2
1
2

Returns: "WHITE 1"

Just one move in this game.

2)
3
1
1
3
3

Returns: "BLACK 6"

*/
// END CUT HERE

#line 75 "TheEasyChase.cpp"
#include <string>
#include <vector>
#include <queue>
// BEGIN CUT HERE
#include <iostream>
#include "cout.h"
// END CUT HERE
#include <sstream>
using namespace std;

#define WHITE 0
#define BLACK 1

class TheEasyChase {
  bool w_reach(int r,int c, int xr,int xc) {
	return ((r == xr && abs(xc - c) == 1) || (c == xc && abs(xr - r) == 1)) ? true: false;
  }
  bool b_reach(int r,int c, int xr,int xc) {
	return ((r == xr && (abs(xc - c) == 1 || abs(xc - c) == 2))
			|| (c == xc && (abs(xr - r) == 1 || abs(xr - r) == 2)) )? true: false;
  }
public:
  string winner(int n, int rw, int cw, int rb, int cb) {
	int winner = WHITE, winturn = 0;
// BEGIN CUT HERE
/*
	  vector<vector<int> > board(n);
	  	  for (int i=0;i<n;i++) board[i].resize(n,0);
		  	  board[rowWhite] = 0;
*/
// END CUT HERE
	priority_queue<pair<int,vector<int> > > pq;
	int l[4] = {rw,cw,rb,cb};
	vector<int> lv(l,l+4);
	pq.push(make_pair(0,lv));
	while (1) {
	  int t = -pq.top().first + 1;
	  int turn = 1-(t % 2);
	  vector<int> v = pq.top().second;

// BEGIN CUT HERE
	  cout << pq.top() << endl;
// END CUT HERE
	  pq.pop();
	  if (turn == WHITE) {
		if (w_reach(v[0],v[1],v[2],v[3])) { winner = WHITE; winturn = t; break; }
		
		vector<int> u(4,0);
		int z = 0;
		if (v[0] > 0) {
		  copy(v.begin(),v.end(), u.begin());
		  u[0] = v[0] - 1;
		  if (!b_reach(v[2],v[3],v[0],v[1])) { z++; pq.push(make_pair(-t,u)); }
		}
		if (v[0] < n-1) {
		  copy(v.begin(),v.end(), u.begin());
		  u[0] = v[0] + 1;
		  if (!b_reach(v[2],v[3],v[0],v[1])) { z++; pq.push(make_pair(-t,u)); }
		}
		if (v[1] > 0) {
		  copy(v.begin(),v.end(), u.begin());
		  u[1] = v[1] - 1;
		  if (!b_reach(v[2],v[3],v[0],v[1])) { z++; pq.push(make_pair(-t,u)); }
		}
		if (v[1] < n-1) {
		  copy(v.begin(),v.end(), u.begin());
		  u[1] = v[1] + 1;
		  if (!b_reach(v[2],v[3],v[0],v[1])) { z++; pq.push(make_pair(-t,u)); }
		}
		if (z == 0) { winner = BLACK; winturn = t+1; break; }
	  } else {
		if (b_reach(v[2],v[3],v[0],v[1])) { winner = BLACK; winturn = t; break; }

		int z = 0;
		vector<int> u(4,0);
		if (v[2] >= 1) {
		  copy(v.begin(),v.end(), u.begin());
		  u[2] = v[2] - 1;
		  if (!w_reach(v[0],v[1],v[2],v[3])) {z++; pq.push(make_pair(-t,u)); }
		}
		if (v[2] >= 2) {
		  copy(v.begin(),v.end(), u.begin());
		  u[2] = v[2] - 2;
		  if (!w_reach(v[0],v[1],v[2],v[3])) {z++;  pq.push(make_pair(-t,u)); }
		}
		if (v[2] <= n-2) {
		  copy(v.begin(),v.end(), u.begin());
		  u[2] = v[2] + 1;
		  if (!w_reach(v[0],v[1],v[2],v[3])) {z++;  pq.push(make_pair(-t,u)); }
		}
		if (v[2] <= n-3) {
		  copy(v.begin(),v.end(), u.begin());
		  u[2] = v[2] + 2;
		  if (!w_reach(v[0],v[1],v[2],v[3])) {z++;  pq.push(make_pair(-t,u)); }
		}
		if (v[3] >= 1) {
		  copy(v.begin(),v.end(), u.begin());
		  u[3] = v[3] - 1;
		  if (!w_reach(v[0],v[1],v[2],v[3])) {z++;  pq.push(make_pair(-t,u)); }
		}
		if (v[3] >= 2) {
		  copy(v.begin(),v.end(), u.begin());
		  u[3] = v[3] - 2;
		  if (!w_reach(v[0],v[1],v[2],v[3])) {z++;  pq.push(make_pair(-t,u)); }
		}
		if (v[3] <= n-2) {
		  copy(v.begin(),v.end(), u.begin());
		  u[3] = v[3] + 1;
		  if (!w_reach(v[0],v[1],v[2],v[3])) {z++;  pq.push(make_pair(-t,u)); }
		}
		if (v[3] <= n-3) {
		  copy(v.begin(),v.end(), u.begin());
		  u[3] = v[3] + 2;
		  if (!w_reach(v[0],v[1],v[2],v[3])) {z++;  pq.push(make_pair(-t,u)); }
		}
		if (z == 0) { winner = WHITE; winturn = t+1; break; }
		
	  }

	  
	  
	}


	  char buf[80];
	  sprintf(buf,"%s %d",(winner == BLACK)?"BLACK":"WHITE", winturn);
	  string s = buf;
	  return s;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 1; int Arg2 = 1; int Arg3 = 2; int Arg4 = 2; string Arg5 = "BLACK 2"; verify_case(0, Arg5, winner(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 2; int Arg2 = 2; int Arg3 = 1; int Arg4 = 2; string Arg5 = "WHITE 1"; verify_case(1, Arg5, winner(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_2() { int Arg0 = 3; int Arg1 = 1; int Arg2 = 1; int Arg3 = 3; int Arg4 = 3; string Arg5 = "BLACK 6"; verify_case(2, Arg5, winner(Arg0, Arg1, Arg2, Arg3, Arg4)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	TheEasyChase ___test;
	___test.run_test(-1);
}
// END CUT HERE
