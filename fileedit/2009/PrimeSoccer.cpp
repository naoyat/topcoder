// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// You are watching a soccer match, and you wonder what the probability is that at least one of the two teams will score a prime number of goals.  The game lasts 90 minutes, and to simplify the analysis, we will split the match into five-minute intervals.  The first interval is the first five minutes, the second interval is the next five minutes, and so on.  During each interval, there is a skillOfTeamA percent probability that team A will score a goal, and a skillOfTeamB percent probability that teamB will score a goal.  Assume that each team will score at most one goal within each interval.  Return the probability that at least one team will have a prime number as its final score.

DEFINITION
Class:PrimeSoccer
Method:getProbability
Parameters:int, int
Returns:double
Method signature:double getProbability(int skillOfTeamA, int skillOfTeamB)


NOTES
-The returned value must be accurate to within a relative or absolute value of 1E-9.
-A prime number is a number that has exactly two divisors, 1 and itself. Note that 0 and 1 are not prime.


CONSTRAINTS
-skillOfTeamA will be between 0 and 100, inclusive.
-skillOfTeamB will be between 0 and 100, inclusive.


EXAMPLES

0)
50
50

Returns: 0.5265618908306351



1)
100
100

Returns: 0.0

Both teams will score a goal in each interval, so the final result will be 18 to 18.

2)
12
89

Returns: 0.6772047168840167



*/
// END CUT HERE

#line 54 "PrimeSoccer.cpp"
#include <string>
#include <vector>
// BEGIN CUT HERE
#include <iostream>
#include "cout.h"
// END CUT HERE
#include <sstream>
using namespace std;

class PrimeSoccer {
  int c(int n, int r)
  {
	if (n == 0 || r == 0) return 1;
	return n * c(n-1,r-1) / r;
  }

  double ntimes(double rate, int times)
  {
	double r = 1.0 * c(18,min(times,18-times));
	for (int i=0; i<times; i++) r *= rate;
	for (int i=times; i<18; i++) r *= (1.0 - rate);
// BEGIN CUT HERE
	//	printf("ntimes(%g, %d) = %g\n", rate, times, r);
// END CUT HERE
	return r;
  }

  double primetimes(double rate)
  {
	return ntimes(rate,2) + ntimes(rate,3) + ntimes(rate,5) + ntimes(rate,7) +
	  ntimes(rate,11) + ntimes(rate,13) + ntimes(rate,17);
	  
  }
	public:
	double getProbability(int skillOfTeamA, int skillOfTeamB) {
	  double pa = 0.01 * skillOfTeamA;
	  double pb = 0.01 * skillOfTeamB;
	  double ra = primetimes(pa);
	  double rb = primetimes(pb);
// BEGIN CUT HERE
	  cout << "a:" << ra << endl;
	  cout << "b:" << rb << endl;
// END CUT HERE
	  return ra + rb - ra*rb;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1();
	  if ((Case == -1) || (Case == 2)) test_case_2();
	  if ((Case == -1) || (Case == 3)) test_case_3();
	  if ((Case == -1) || (Case == 4)) test_case_4();
	}
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 50; int Arg1 = 50; double Arg2 = 0.5265618908306351; verify_case(0, Arg2, getProbability(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 100; int Arg1 = 100; double Arg2 = 0.0; verify_case(1, Arg2, getProbability(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 12; int Arg1 = 89; double Arg2 = 0.6772047168840167; verify_case(2, Arg2, getProbability(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 0; int Arg1 = 0; double Arg2 = 0.0; verify_case(3, Arg2, getProbability(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 0; int Arg1 = 100; double Arg2 = 0.0; verify_case(4, Arg2, getProbability(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	PrimeSoccer ___test;
	___test.run_test(-1);
}
// END CUT HERE
