// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// An out-of-control robot is placed on a plane, and it takes n random steps.  At each step, the robot chooses one of four directions randomly and moves one unit in that direction. The probabilities of the robot choosing north, south, east or west are north, south, east and west percent, respectively.

The robot's path is considered simple if it never visits the same point more than once.  (The robot's starting point is always the first visited point.)  Return a double containing the probability that the robot's path is simple.  For example, "EENE" and "ENW" are simple, but "ENWS" and "WWWWSNE" are not ('E', 'W', 'N' and 'S' represent east, west, north and south, respectively).

DEFINITION
Class:CrazyBot
Method:getProbability
Parameters:int, int, int, int, int
Returns:double
Method signature:double getProbability(int n, int east, int west, int south, int north)


NOTES
-Your return must have relative or absolute error less than 1E-9.


CONSTRAINTS
-n will be between 1 and 14, inclusive.
-east will be between 0 and 100, inclusive.
-west will be between 0 and 100, inclusive.
-south will be between 0 and 100, inclusive.
-north will be between 0 and 100, inclusive.
-The sum of east, west, south and north will be 100.


EXAMPLES

0)
1
25
25
25
25

Returns: 1.0

The robot only takes one step, so it never visits a point more than once.

1)
2
25
25
25
25

Returns: 0.75

The robot will visit its starting point twice only if the two moves are in opposite directions.

2)
7
50
0
0
50

Returns: 1.0

Here, the only possible directions are north and east, so the robot will never visit the same point twice.

3)
14
50
50
0
0

Returns: 1.220703125E-4

Here, the only possible directions are east and west. The only two available paths are "EEEEEEEEEEEEEE" and "WWWWWWWWWWWWWW". The probability is equal to 2 / (2^14).

4)
14
25
25
25
25

Returns: 0.008845493197441101

The probability is quite small for n=14.

*/
// END CUT HERE

#line 90 "CrazyBot.cpp"
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

class CrazyBot {
  int t_;
  double e_,w_,s_,n_;
public:
  //  double turn(int n,double r,int x,int y,set<pair<int,int> > h) {
  double turn(int n,double r,int x,int y,vector<int> h) {

	for (int i=n;i<=t_;i++) if (h[i] == 29*y+x) return 0.0;
	if (n == 0) return r;

	h[n] = 29*y+x;
	double total = 0.0;
	if (e_ > 0) total += turn(n-1,r*e_,x+1,y,h);
	if (w_ > 0) total += turn(n-1,r*w_,x-1,y,h);
	if (n_ > 0) total += turn(n-1,r*n_,x,y-1,h);
	if (s_ > 0) total += turn(n-1,r*s_,x,y+1,h);
	return total;
  }
  double getProbability(int n, int east, int west, int south, int north) {
	t_=n;
	e_=0.01*east; w_=0.01*west; s_=0.01*south; n_=0.01*north;

 	vector<int> h(15,0);
	return turn(n,1.0,14,14,h);
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
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) {
	  ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
  void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << timer() << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 25; int Arg2 = 25; int Arg3 = 25; int Arg4 = 25; double Arg5 = 1.0; verify_case(0, Arg5, getProbability(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 25; int Arg2 = 25; int Arg3 = 25; int Arg4 = 25; double Arg5 = 0.75; verify_case(1, Arg5, getProbability(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_2() { int Arg0 = 7; int Arg1 = 50; int Arg2 = 0; int Arg3 = 0; int Arg4 = 50; double Arg5 = 1.0; verify_case(2, Arg5, getProbability(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_3() { int Arg0 = 14; int Arg1 = 50; int Arg2 = 50; int Arg3 = 0; int Arg4 = 0; double Arg5 = 1.220703125E-4; verify_case(3, Arg5, getProbability(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_4() { 
	  timer_clear();
	  int Arg0 = 14; int Arg1 = 25; int Arg2 = 25; int Arg3 = 25; int Arg4 = 25; double Arg5 = 0.008845493197441101; verify_case(4, Arg5, getProbability(Arg0, Arg1, Arg2, Arg3, Arg4)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main(int argc, char *argv[]) {
	CrazyBot ___test;
	___test.run_test( argc>=2 ? atoi(argv[1]):-1 );
}
// END CUT HERE
