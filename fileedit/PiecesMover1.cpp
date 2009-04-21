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
#include "lib.h"
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
// BEGIN CUT HERE
  void plot(int x) {
	for (int i=0,m=1<<24; i<25; i++,m>>=1) {
	  putchar((x & m) ? 'o' : '.');
	  if (i % 5 == 4) putchar('\n');
	}
	putchar('\n');
  }
// END CUT HERE

  vector<pair<int,int> > pattern(int x)
  {
	vector<pair<int,int> > ms(__builtin_popcount(x));
	int msi = 0;
	for (int i=0,m=1<<24; i<25; i++,m>>=1)
	  if (x & m) ms[msi++] = make_pair(i/5,i%5);
	return ms;
  }
	//vector<int> oks; int okc = 0;
  bool is_possible_pattern(const vector<pair<int,int> > &ms)
  {
	int n = ms.size();
	vector<bool> ok(n,false),ck(n,false);
	ok[0] = true;
	int okc = 1;

	bool om[7][7]; for (int i=1;i<=5;i++) for (int j=1;j<=5;j++) om[i][j] = 0;

	while (1) {
	  int cx = -1;
	  for (int i=0;i<n;i++) if (ok[i] && !ck[i]) { cx=i; break; }
	  if (cx == -1) break;//return false;

	  ck[cx] = true;
	  
	  int x = 1+ms[cx].first, y = 1+ms[cx].second;
	  om[x-1][y] = om[x+1][y] = om[x][y-1] = om[x][y+1] = true;

	  for (int i=/* 0 */1;i<n;i++) {
		if (!ok[i]) {
		  int x = 1+ms[i].first, y = 1+ms[i].second;
		  if (om[x][y]) { ok[i]=true; okc++; }
		}
	  }
	}
	return (okc == n);
  }

  int distance(pair<int,int> p1, pair<int,int> p2)
  {
	return abs(p1.first - p2.first) + abs(p1.second - p2.second);
  }
public:
  int getMinimumMoves(vector<string> board) {
	vector<pair<int,int> > pieces;
	for(int r=0;r<5;r++)
	  for (int c=0;c<5;c++)
		if (board[r][c]=='*') {
		  pieces.pb(make_pair(r,c));
		}
	if (is_possible_pattern(pieces)) return 0;
	// cout << pieces << endl;
	int N = pieces.size(), Nx = 1;
	for(int i=2;i<=N;i++) Nx*=i;

	// vector<vector<pair<int,int> > > ppat;
	int minimum_distance = INT_MAX;
	for (int i=(1<<25)-1; i>=0; i--) {
	  if (__builtin_popcount(i) != N) continue;
	  vector<pair<int,int> > pat = pattern(i);
	  if (!is_possible_pattern(pat)) continue;
	  //}
	// printf("%d / %d\n", (int)ppat.size(), c(25,N));
	  //tr(ppat,p) {
	  vector<int> v(N); for(int i=0;i<N;i++) v[i]=i;
	  for (int i=0; i<Nx; i++) {
		int total_distance = 0;
		for (int j=0;j<N;j++) total_distance += distance(pieces[j], pat[v[j]]);
		if (total_distance < minimum_distance) minimum_distance = total_distance;
		next_permutation(all(v));
	  }
	}
	return minimum_distance;
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
	void run_test(int Case) {
	  if ((Case == -1) || (Case == 0)) test_case_0();
	  if ((Case == -1) || (Case == 1)) test_case_1();
	  if ((Case == -1) || (Case == 2)) test_case_2();

	  if ((Case == -1) || (Case == 100)) test_case_100();
	  if ((Case == -1) || (Case == 101)) test_case_101();
	  if ((Case == -1) || (Case == 102)) test_case_102();
	  if ((Case == -1) || (Case == 103)) test_case_103();
	}
	private:
	template <typename T> string print_array(const vector<T> &V) {
	  ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str();
	}
	void verify_case(int Case, const int &Expected, const int &Received) {
	  cerr << "Test Case #" << Case << "...";
	  if (Expected == Received) cerr << "PASSED" << timer() << endl;
	  else { cerr << "FAILED" << timer() << endl;
		cerr << "\tExpected: \"" << Expected << '\"' << endl;
		cerr << "\tReceived: \"" << Received << '\"' << endl;
	  }
	}
	void test_case_0() {
	  timer_clear();
	  string Arr0[] = {".....",
					   "..**.",
					   ".....",
					   "...*.",
					   "....."};
	  vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
	  int Arg1 = 1;
	  verify_case(0, Arg1, getMinimumMoves(Arg0));
	}
	void test_case_1() {
	  timer_clear();
	  string Arr0[] = {".....",
					   ".....",
					   ".**..",
					   ".*...",
					   "**..."};
	  vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
	  int Arg1 = 0;
	  verify_case(1, Arg1, getMinimumMoves(Arg0));
	}
	void test_case_2() {
	  timer_clear();
	  string Arr0[] = {"*...*",
					   ".....",
					   ".....",
					   ".....",
					   "*...*"};
	  vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
	  int Arg1 = 12;
	  verify_case(2, Arg1, getMinimumMoves(Arg0));
	}

	void test_case_100() {
	  timer_clear();
	  string Arr0[] = {"..*..",
					   ".....",
					   "*.*.*",
					   ".....",
					   "..*.."};
	  vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
	  int Arg1 = 4;
	  verify_case(100, Arg1, getMinimumMoves(Arg0));
	}
	void test_case_101() {
	  timer_clear();
	  string Arr0[] = {"*....",
					   ".....",
					   ".....",
					   ".....",
					   "....."};
	  vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
	  int Arg1 = 0;
	  verify_case(101, Arg1, getMinimumMoves(Arg0));
	}
	void test_case_102() {
	  timer_clear();
	  string Arr0[] = {"*....",
					   ".....",
					   ".....",
					   ".....",
					   "....*"};
	  vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
	  int Arg1 = 7;
	  verify_case(102, Arg1, getMinimumMoves(Arg0));
	}
	void test_case_103() {
	  timer_clear();
	  string Arr0[] = {"**...",
					   ".....",
					   ".....",
					   ".....",
					   "....."};
	  vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
	  int Arg1 = 0;
	  verify_case(103, Arg1, getMinimumMoves(Arg0));
	}
// END CUT HERE

};

// BEGIN CUT HERE
int main(int argc, char *argv[]) {
	PiecesMover ___test;
	___test.run_test( argc>=2 ? atoi(argv[1]):-1 );
}
// END CUT HERE
