// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// You are given a 5x5 board containing at most 5 pieces.  Your task is to move the pieces so that the cells occupied by them form a connected component.  A connected component is a set of cells where each pair of cells is connected by at least one path.  Consecutive cells in a path must all be adjacent.  Two cells are called adjacent if they share a common edge.
You are given a String[] board, where the j-th character of the i-th element is '*' if cell (i, j) is occupied by a piece and '.' otherwise.  Return the minimum number of moves required to achieve your goal.  Each move consists of moving one piece to an adjacent empty cell.

DEFINITION
Class:PiecesMover
Method:getMinimumMoves
Parameters:vector <string>
Returns:int
Method signature:int getMinimumMoves(vector <string> board)


CONSTRAINTS
-board will contain exactly 5 elements.
-Each element of board will contain exactly 5 characters.
-Each character in board will be either '.' or '*'.
-board will contain between 1 and 5 '*' characters, inclusive.


EXAMPLES

0)
{".....",
 "..**.",
 ".....",
 "...*.",
 "....."}


Returns: 1


 + + + + +
          
 + + O O +
          
 + + + O +
       |  
 + + + . +
          
 + + + + +

1)
{".....",
 ".....",
 ".**..",
 ".*...",
 "**..."}


Returns: 0

The cells occupied by pieces have already formed a connected component.

2)
{"*...*",
 ".....",
 ".....",
 ".....",
 "*...*"}


Returns: 12


 . + +-+-.
 |   |    
 + + + + +
 |   |    
 +-O O O-+
         |
 + O + + +
   |     |
 .-+ + + .

*/
// END CUT HERE

#line 82 "PiecesMover.cpp"
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
#include <time.h>
// END CUT HERE
#include <sstream>
#include <cmath>
using namespace std;

#define sz(a)  int((a).size())
#define pb  push_back
#define all(c)  (c).begin(),(c).end()
#define tr(c,i)  for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); i++)

class PiecesMover {
	public:
	int getMinimumMoves(vector <string> board) {
		
	}
// BEGIN CUT HERE
  clock_t start;
  void timer_clear()
  {
	start = clock();
  }
  char *timer()
  {
	clock_t end = clock();
	double interval = (double)(end - start)/CLOCKS_PER_SEC;
	
	char *ret = NULL;
	asprintf(&ret, " (%g msec)", interval*1000);
	return ret;
  }
// END CUT HERE
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {".....",
 "..**.",
 ".....",
 "...*.",
 "....."}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(0, Arg1, getMinimumMoves(Arg0)); }
	void test_case_1() { string Arr0[] = {".....",
 ".....",
 ".**..",
 ".*...",
 "**..."}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(1, Arg1, getMinimumMoves(Arg0)); }
	void test_case_2() { string Arr0[] = {"*...*",
 ".....",
 ".....",
 ".....",
 "*...*"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 12; verify_case(2, Arg1, getMinimumMoves(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main(int argc, char *argv[]) {
	PiecesMover ___test;
	___test.run_test( argc>=2 ? atoi(argv[1]):-1 );
}
// END CUT HERE
