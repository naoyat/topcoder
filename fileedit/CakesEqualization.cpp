// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// You are organizing a party and have bought several pieces of cake for it. The weights of these pieces are given in the vector <int> weights, where each element corresponds to the weight of a single piece.

After looking at the pieces more carefully, you became worried that they have different weights and decided to make these differences smaller. In order to do this, you can make at most maxCuts cuts. With each cut you can choose one of the pieces you currently have and divide it into two distinct pieces. Note that each of these two pieces can be chosen again when making subsequent cuts.

Your goal is to produce cuts in such way that the difference between the maximal and the minimal pieces' weights becomes as small as possible. Find the best way of making cuts and return the optimal difference.

DEFINITION
Class:CakesEqualization
Method:fairDivision
Parameters:vector <int>, int
Returns:double
Method signature:double fairDivision(vector <int> weights, int maxCuts)


NOTES
-Your return value must have an absolute or relative error less than 1e-9.


CONSTRAINTS
-weights will contain between 1 and 50 elements, inclusive.
-Each element of weights will be between 1 and 1,000,000,000, inclusive.
-maxCuts will be between 1 and 100,000, inclusive.


EXAMPLES

0)
{1, 3}
2

Returns: 0.0

First, choose the piece with weight 3 and cut it into pieces with weights 1 and 2. Then, choose the piece with weight 2 and cut it into two pieces with weight 1. Now all pieces have the same weight, so the answer is 0.

1)
{1, 1, 1, 1, 1}
4

Returns: 0.0

Even though you are allowed to make 4 cuts, there is no sense in making any of them.

2)
{1, 3}
1

Returns: 0.5

The same case as in example 0, but now you are allowed to make only one cut. The best thing to do is to cut the piece with weight 3 into two pieces with weights 1.5.

3)
{7, 11, 13}
10

Returns: 0.3999999999999999



4)
{13, 69, 41, 37, 80}
27

Returns: 1.4666666666666668



*/
// END CUT HERE

#line 74 "CakesEqualization.cpp"
#include <string>
#include <vector>
// BEGIN CUT HERE
#include <iostream>
#include "cout.h"
// END CUT HERE
#include <sstream>
using namespace std;

class CakesEqualization {
private:
  double fabs(double x) { return (x < 0) ? -x : x; }
  double difference(vector<int> weights, vector<int> cuts, int *max_at)
  {
	double rmax = 0.0, rmin = 1000000001.0;
	int rmax_at = -1;
	int wsize = weights.size();
	for (int i=0; i<wsize; i++) {
	  double r = 1.0 * weights[i] / cuts[i];
	  if (rmax < r) { rmax = r; rmax_at = i; }
	  if (r < rmin) rmin = r;
	}
	double dif = rmax - rmin;
	if (fabs(dif) < 1.0e-9) { *max_at = -1; return 0.0; }
	else { *max_at = rmax_at; return dif; }
  }

public:
	double fairDivision(vector<int> weights, int maxCuts) {
// BEGIN CUT HERE
	  // weight[i]: wsize=1-50 x 1-1000000000
	  // maxCuts: 1-100000
// END CUT HERE
	  int wsize = weights.size();
	  vector<int> cuts(wsize,1);
	  double dmin = 1000000000;

	  int max_at = -1, cutcount = 0;
	  while (1) {
		max_at = -1;
		double d = difference(weights, cuts, &max_at);
		if (d < dmin) dmin = d;
		if (cutcount == maxCuts || max_at < 0) return dmin;
		cuts[max_at]++; cutcount++;
	  }
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3();
	  if ((Case == -1) || (Case == 4)) test_case_4();
	  if ((Case == -1) || (Case == 5)) test_case_5();
	  if ((Case == -1) || (Case == 6)) test_case_6();
	  if ((Case == -1) || (Case == 10)) test_case_10();
	  if ((Case == -1) || (Case == 40)) test_case_40();
	  if ((Case == -1) || (Case == 41)) test_case_41();
	}
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "...";
	  if (fabs(Expected - Received) < 1.0e-9) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() {
	  int Arr0[] = {1, 3};
	  vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
	  int Arg1 = 2;
	  double Arg2 = 0.0;
	  verify_case(0, Arg2, fairDivision(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {1, 1, 1, 1, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; double Arg2 = 0.0; verify_case(1, Arg2, fairDivision(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {1, 3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; double Arg2 = 0.5; verify_case(2, Arg2, fairDivision(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {7, 11, 13}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; double Arg2 = 0.3999999999999999; verify_case(3, Arg2, fairDivision(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {13, 69, 41, 37, 80}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 27; double Arg2 = 1.4666666666666668; verify_case(4, Arg2, fairDivision(Arg0, Arg1)); }

  void test_case_5() {
	int Arr0[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50};
	vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
	int Arg1 = 100000;
	double Arg2 = 0.0; verify_case(5, Arg2, fairDivision(Arg0, Arg1)); }
  void test_case_6() {
	int Arr0[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50};
	vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
	int Arg1 = 50;
	double Arg2 = 16.0; verify_case(6, Arg2, fairDivision(Arg0, Arg1)); }
  void test_case_10() {
	int Arr0[] = {1};
	vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
	int Arg1 = 1;
	double Arg2 = 0.0; verify_case(10, Arg2, fairDivision(Arg0, Arg1)); }
  void test_case_40() {
	int Arr0[] = {1000000000, 690000000, 410000000, 370000000, 1};
	vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
	int Arg1 = 1;
	double Arg2 = 690000000; verify_case(40, Arg2, fairDivision(Arg0, Arg1)); }
  void test_case_41() {
	int Arr0[] = {1000000000, 690000000, 410000000, 370000000, 1};
	vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
	int Arg1 = 100000;
	double Arg2 = 10000; verify_case(41, Arg2, fairDivision(Arg0, Arg1)); }
  
// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	CakesEqualization ___test;
	___test.run_test(-1);
}
// END CUT HERE
