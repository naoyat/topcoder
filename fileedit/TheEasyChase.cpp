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
// BEGIN CUT HERE
#include <iostream>
#include "cout.h"
// END CUT HERE
#include <sstream>
using namespace std;

#define ix(wx,wy,bx,by) (n*(n*(n*(wx)+(wy))+(bx))+(by))
n*(w)+(b))
#define p(x,y) (n*((x)-1)+((y)-1))

class TheEasyChase {
public:
  string winner(int n, int rw, int cw, int rb, int cb) {
// BEGIN CUT HERE
	// n: [2..20]
	// (rw,cw),(rb,cb): [1..n]
/*
	printf("[n=%d] (%d - %d)x(%d - %d) = %d patterns\n",
		   n,
		   0, p(n,n),
		   0, p(n,n),
		   (p(n,n)+1) * (p(n,n)+1) );
*/
// END CUT HERE
	vector<int> wt(n*n*n*n,0);
	for (int wx=0;wx<n;wx++) {
	  for (int wy=0;wy<n;wy++) {
		for (int bx=0;bx<n;bx++) {
		  for (int by=0;by<n;by++) {
			wt[ix(wx,wy,bx,by)] = -1;
			if (wx >= 1) wt[ix(wx-1,wy,bx,by)] = 1;
			if (wx < n-1) wt[ix(wx+1,wy,bx,by)] = 1;
			if (wy >= 1) wt[ix(wx,wy-1,bx,by)] = 1;
			if (wy < n-1) wt[ix(wx,wy+1,bx,by)] = 1;
		  }
		}
	  }
	}

	(for a
	for (int w=0;w<p(n,n);w++) {
	  for (int b=0;b<p(n,n);b++) {
		wt[t(w,b)] = -1;
		wt[t(w,b)] = -1;
		
	  }
	}

	for (int i=0;i<p(n,n);i++) {
	  wt[t(i,i)] = bt[t(i,i)] = -1;
	  wt[t(i-1,i)
	}

	
	return "OO";
  }
	
// BEGIN CUT HERE
public:
  void run_test(int Case) {
	if ((Case == -1) || (Case == 0)) test_case_0();
	if ((Case == -1) || (Case == 1)) test_case_1();
	if ((Case == -1) || (Case == 2)) test_case_2();
	if ((Case == -1) || (Case == 998)) test_case_998();
	if ((Case == -1) || (Case == 999)) test_case_999();
  }
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 1; int Arg2 = 1; int Arg3 = 2; int Arg4 = 2; string Arg5 = "BLACK 2"; verify_case(0, Arg5, winner(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 2; int Arg2 = 2; int Arg3 = 1; int Arg4 = 2; string Arg5 = "WHITE 1"; verify_case(1, Arg5, winner(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_2() { int Arg0 = 3; int Arg1 = 1; int Arg2 = 1; int Arg3 = 3; int Arg4 = 3; string Arg5 = "BLACK 6"; verify_case(2, Arg5, winner(Arg0, Arg1, Arg2, Arg3, Arg4)); }

  void test_case_998() {
	int Arg0 = 20; int Arg1 = 1; int Arg2 = 1; int Arg3 = 19; int Arg4 = 20;
	string Arg5 = "BLACK 6";
	verify_case(998, Arg5, winner(Arg0, Arg1, Arg2, Arg3, Arg4)); }
  void test_case_999() {
	int Arg0 = 20; int Arg1 = 1; int Arg2 = 1; int Arg3 = 20; int Arg4 = 20;
	string Arg5 = "BLACK 6";
	verify_case(999, Arg5, winner(Arg0, Arg1, Arg2, Arg3, Arg4)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	TheEasyChase ___test;
	___test.run_test(-1);
}
// END CUT HERE
