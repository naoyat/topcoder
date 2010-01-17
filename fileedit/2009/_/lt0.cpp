// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// First of all we define a function dig for all nonnegative integers:

dig(x) := x                          if 0 <= x <= 9
dig(x) := dig(sum of digits of x)    if x >= 10

For example: dig(49) = dig(13) = dig(4) = 4.


Your crew of treasure hunters have recently found a very old map with instructions on how to find the treasure of an old civilization.  There is a variable named Gold number, and it is initially assigned a value of 1.  You are currently standing at position (0, 0), facing north.

Repeat the following instructions K times:
1. Take dig(Gold number) steps forward, and then turn 90 degrees right.
2. Multiply Gold number by multi.

Each step forward moves you one unit in your current direction.  Moving north changes your location by (0, 1), south changes your location by (0, -1), west changes your location by (-1, 0) and east changes your location by (1, 0). After you perform all the instructions, you can start digging.  Return the coordinates (X, Y) of your final location as a string in the form "X Y" (quotes for clarity), where X and Y contain no extra leading zeroes.


DEFINITION
Class:LocateTreasure
Method:location
Parameters:int, int
Returns:string
Method signature:string location(int K, int multi)


CONSTRAINTS
-K will be between 1 and 10^9, inclusive.
-multi will be between 1 and 1000, inclusive.


EXAMPLES

0)
5
2

Returns: "-6 4"

You will go 1 step north, 2 steps east, 4 steps south, 8 steps west and 7 steps north.

1)
99
1

Returns: "1 0"

You will do exactly 1 step in every iteration.

2)
6
9

Returns: "9 1"



*/
// END CUT HERE

#line 64 "LocateTreasure.cpp"
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

class LocateTreasure {
  int dig(int x) {
	if (x == 0) return 0;
	int m = x % 9;
	return (m == 0) ? 9 : m;
  }
public:
  string location(int K, int multi) {
// BEGIN CUT HERE
	// K: 1-10^9
	// multi:1-1000
	/*
 1 2 3 4 5 6 7 8 9
 1 4 9 7 7 9 4 1 9
 1 8 9 1 8 9 1 8 9
 1 7 9 4 4 9 7 1 9
	*/
// END CUT HERE
	int t[13][10];
	for (int i=1; i<=9; i++) t[0][i] = 1;
	for (int j=1; j<=12; j++) {
	  for (int i=1; i<=9; i++) {
		t[j][i] = dig(t[j-1][i] * i);
	  }
	}

	int Kq = K / 12, Kr = K % 12;
	int m_ = dig(multi);
// BEGIN CUT HERE
	/*	
	long long b = 1 + (Kq - 1)*g;
	long long x = b * (m_ - dig(m_*m_*m_));
	long long y = b * (1 - dig(m_*m_));
	*/
// END CUT HERE
	long long x = Kq * (t[1][m_] + t[5][m_] + t[9][m_])
	  - Kq * (t[3][m_] + t[7][m_] + t[11][m_]);
	long long y = (1 + t[4][m_] + t[8][m_]) + (Kq-1)*(t[12][m_] + t[4][m_] + t[8][m_])
	  - Kq * (t[2][m_] + t[6][m_] + t[10][m_]);

	map<pair<int,int>,pair<int,int> > turns;
	turns[make_pair(0,1)] = make_pair(1,0);
	turns[make_pair(1,0)] = make_pair(0,-1);
	turns[make_pair(0,-1)] = make_pair(-1,0);
	turns[make_pair(-1,0)] = make_pair(0,1);
	pair<int,int> dir = make_pair(0,1);
	int g = t[12][m_];
	for (int i=0; i<Kr; i++) {
	  int d = dig(g);
// BEGIN CUT HERE
	  /*
	  printf("K=%d (4*%d+%d), i=%d, x+=%d*%d=%d, y+=%d*%d=%d\n",
			 K, Kq, Kr, i,
			 dir.first, d, dir.first * d,
			 dir.second, d, dir.second * d
			 );
	  */
// END CUT HERE
	  x += dir.first * d; y += dir.second * d;
	  g *= m_; dir = turns[dir];
	}
	ostringstream os;
	os << x << " " << y;
	return os.str();
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
  void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1();
	if ((Case == -1) || (Case == 2)) test_case_2();
	if ((Case == -1) || (Case == 7)) test_case_7();
	if ((Case == -1) || (Case == 8)) test_case_8();
	if ((Case == -1) || (Case == 9)) test_case_9();

	if ((Case == -1) || (Case == 10)) test_case_10();
	if ((Case == -1) || (Case == 102)) test_case_102();
	if ((Case == -1) || (Case == 104)) test_case_104();
  }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 5; int Arg1 = 2; string Arg2 = "-6 4"; verify_case(0, Arg2, location(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 99; int Arg1 = 1; string Arg2 = "1 0"; verify_case(1, Arg2, location(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 6; int Arg1 = 9; string Arg2 = "9 1"; verify_case(2, Arg2, location(Arg0, Arg1)); }

	void test_case_7() { int Arg0 = 5; int Arg1 = 1000; string Arg2 = "0 1"; verify_case(7, Arg2, location(Arg0, Arg1)); }
	void test_case_8() { int Arg0 = 1000000000; int Arg1 = 1; string Arg2 = "0 0"; verify_case(8, Arg2, location(Arg0, Arg1)); }
	void test_case_9() { int Arg0 = 1000000000; int Arg1 = 1000; string Arg2 = "0 0"; verify_case(9, Arg2, location(Arg0, Arg1)); }

	void test_case_10() { int Arg0 = 1; int Arg1 = 1; string Arg2 = "0 1"; verify_case(10, Arg2, location(Arg0, Arg1)); }

  void test_case_102() { int Arg0 = 5226; int Arg1 = 4; string Arg2 = "10 -2"; verify_case(102, Arg2, location(Arg0, Arg1)); }
  void test_case_104() { int Arg0 = 1000000000; int Arg1 = 2; string Arg2 = "-6 -3"; verify_case(104, Arg2, location(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main(int argc, char *argv[]) {
	LocateTreasure ___test;
	___test.run_test( argc>=2 ? atoi(argv[1]):-1 );
}
// END CUT HERE
