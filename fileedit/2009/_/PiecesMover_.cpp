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
  int d(pair<int,int> x,pair<int,int> y) {
	int dx = abs(x.first - y.first);
	int dy = abs(x.second - y.second);
	return dx + dy;
  }
public:
  int getMinimumMoves(vector<string> board) {
	int cn = 0;

	vector<pair<int,int> > p;
	cout << "board: " << board << endl;
	int id = 0;
	for (int r=0; r<5; r++)
	  for (int c=0; c<5; c++)
		if (board[r][c] == '*') {
		  p.push_back( make_pair(r,c) );
		}
	cout << "p: " << p << endl;
	int n = p.size();

  loop:
	//	vector<bool> vd(n,false);vd[0] = true;
	vector<vector<int> > ds(5);
	vector<vector<bool> > bs(5);
	for (int i=0;i<n;i++) { ds[i].resize(5); bs[i].resize(5); }
	for (int i=0;i<n;i++) {
	  ds[i][i] = 0; bs[i][i] = false;
	  for (int j=i+1;j<n;j++) {
		int d_ = d(p[i],p[j]);
		ds[j][i] = ds[i][j] = d_;
		bs[j][i] = bs[i][j] = (d_ == 1);
	  }
	}

	vector<bool> vd(n,false); vd[0] = true;
	int vds = 1;
	for (int c=1;c<n;c++) {
	  bool ok = false;
	  for (int j=0;j<n;j++) {
		if (!vd[j]) continue;
		for (int i=1;i<n;i++) {
		  if (vd[i]||i==j) continue;
		  if (bs[j][i]) { vd[i] = true; ok = true; vds++; }
		}
	  }
	  if (!ok) break;
	}
	if (vds == n) return cn;
	cout << "vd: " << vd << endl;

	int x=-1;
	for (int c=0;c<n;c++)
	  if (!vd[n]) {x=c; break;}
	int nr=9,nra=-1;
	for (int j=0;j<n;j++) {
	  if (j==x) continue;
	  int d_ = d(p[j],p[x]);
	  if (d_ < nr) { nra =j; nr = d_; }
	}
	printf("x=%d, nr=%d (%d)\n",x,nra,nr);
	cn += nr - 1;
	if (p[x].first < p[nra].first)
	  p[x].first = p[nra].first-1;
	else if (p[x].first > p[nra].first)
	  p[x].first = p[nra].first+1;
	if (p[x].second < p[nra].second)
	  p[x].second = p[nra].second-1;
	else if (p[x].second > p[nra].second)
	  p[x].second = p[nra].second+1;
	goto loop;
	
	return cn;
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
