// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
N checkers are placed on an infinitely large board.  The i-th checker is in the cell at row x[i], column y[i].  There can be more than one checker in the same cell.  A move consists of taking one checker and moving it one cell up, down, left or right.



Return a vector<int> containing exactly N elements, where the i-th element (0-based) is the minimum number of moves necessary to end up with at least i+1 checkers in the same cell.



DEFINITION
Class:TheTower
Method:count
Parameters:vector<int>, vector<int>
Returns:vector<int>
Method signature:vector<int> count(vector<int> x, vector<int> y)


CONSTRAINTS
-x will contain between 1 and 50 elements, inclusive.
-y will contain the same number of elements as x.
-Each element of x will be between 1 and 1,000,000, inclusive.
-Each element of y will be between 1 and 1,000,000, inclusive.


EXAMPLES

0)
{1, 2, 4, 9}
{1, 1, 1, 1}

Returns: {0, 1, 3, 10 }

Here is one possible way to get the minimal number of moves:

for 1 checker: do nothing
for 2 checkers: put the first two checkers at cell (1, 1)
for 3 checkers: put the first three checkers at cell (2, 1)
for 4 checkers: put all the checkers at cell (3, 1)



1)
{15, 15, 14, 16}
{14, 16, 15, 15}

Returns: {0, 2, 3, 4 }

Whenever we need to have more than one checker in a single cell, we can put them in cell (15, 15).

2)
{4, 4}
{7, 7}

Returns: {0, 0 }

They are already at the same cell.

*/
// END CUT HERE

#line 65 "TheTower.cpp"
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
// BEGIN CUT HERE
#include <iostream>
#include "cout.h"
// END CUT HERE
#include <sstream>
using namespace std;

#define tr(c,i)  for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); i++)
#define found(s,e)  ((s).find(e)!=(s).end())
#define all(x)  (x).begin(),(x).end()

class TheTower {
	public:
	vector<int> count(vector<int> x, vector<int> y) {
	  int n = x.size();
	  vector<int> xs(all(x)); sort(all(xs));
	  vector<int> ys(all(y)); sort(all(ys));
// BEGIN CUT HERE
	  cout << "x: " << xs << endl;
	  cout << "y: " << ys << endl;
// END CUT HERE
	  vector<int> m(n,INT_MAX); m[0] = 0;
	  tr(xs,x_) {
		tr(ys,y_) {
		  vector<int> d(n);
		  for (int i=0; i<n; i++) d[i] = abs(*x_ - x[i]) + abs(*y_ - y[i]);
		  sort(all(d));
		  int a = d[0];
		  for (int i=1;i<n;i++) {
			a += d[i];
			if (a < m[i]) m[i] = a;
		  }
		}
	  }
	  return m;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) {
	  if ((Case == -1) || (Case == 0)) test_case_0();
	  if ((Case == -1) || (Case == 1)) test_case_1();
	  if ((Case == -1) || (Case == 2)) test_case_2();
	  if ((Case == -1) || (Case == 3)) test_case_3();
	  if ((Case == -1) || (Case == 4)) test_case_4();
	  if ((Case == -1) || (Case == 5)) test_case_5();
	  if ((Case == -1) || (Case == 13)) test_case_13();
	}
	private:
	template <typename T> string print_array(const vector<T> &V) {
	  ostringstream os;
	  os << "{ ";
	  tr(V,iter) os << *iter << ", ";
	  os << "}";
	  return os.str();
	}
	void verify_case(int Case, const vector<int> &Expected, const vector<int> &Received) {
	  cerr << "Test Case #" << Case << "...";
	  if (Expected == Received)
		cerr << "PASSED" << endl;
	  else {
		cerr << "FAILED" << endl;
		cerr << "\tExpected: " << print_array(Expected) << endl;
		cerr << "\tReceived: " << print_array(Received) << endl;
	  }
	}

  void test_case_0() {
	int Arr0[] = {1, 2, 4, 9}; vector<int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
	int Arr1[] = {1, 1, 1, 1}; vector<int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
	int Arr2[] = {0, 1, 3, 10 }; vector<int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
	verify_case(0, Arg2, count(Arg0, Arg1));
  }
  void test_case_1() {
	int Arr0[] = {15, 15, 14, 16}; vector<int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
	int Arr1[] = {14, 16, 15, 15}; vector<int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
	int Arr2[] = {0, 2, 3, 4 }; vector<int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
	verify_case(1, Arg2, count(Arg0, Arg1));
  }
  void test_case_2() {
	int Arr0[] = {4, 4}; vector<int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
	int Arr1[] = {7, 7}; vector<int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
	int Arr2[] = {0, 0 }; vector<int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
	verify_case(2, Arg2, count(Arg0, Arg1));
  }
  void test_case_3() {
	int Arr0[] = {8, 1, 9, 9, 7}; vector<int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
	int Arr1[] = {7, 7, 7, 7, 10}; vector<int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
	int Arr2[] = {0, 0,1,6,13 }; vector<int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
	verify_case(3, Arg2, count(Arg0, Arg1));
  }
  void test_case_4() {
	  int Arr0[] = {3, 3, 6, 1, 5, 7}; vector<int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
	  int Arr1[] = {1, 9, 9, 2, 1, 6}; vector<int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
	  int Arr2[] = {0, 2,5,13,21,31}; vector<int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
	  verify_case(4, Arg2, count(Arg0, Arg1));
  }
  void test_case_5() {
	int Arr0[] = {3}; vector<int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
	int Arr1[] = {1}; vector<int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
	int Arr2[] = {0}; vector<int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
	verify_case(5, Arg2, count(Arg0, Arg1));
  }
  void test_case_13() {
	int Arr0[] = {8716, 5960, 8716, 5622, 5622, 7368, 9170, 4069, 9269, 9875, 4700, 8716, 7635, 7635, 8716, 7635, 9264, 4750, 10188, 4505};
	int Arr1[] = {8068, 10888, 8068, 7679, 7679, 6389, 5870, 5424, 4104, 7266, 10654, 8068, 10552, 10552, 8068, 10552, 10512, 5618, 7072, 6218};
	int Arr2[] = {0, 0, 0, 0, 1961, 4429, 7081, 10073, 13100, 16296, 19677, 23631, 27196, 30761, 35278, 40854, 46915, 53254, 58852, 65062};
	vector<int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
	vector<int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
	vector<int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
	verify_case(13, Arg2, count(Arg0, Arg1));
  }



// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	TheTower ___test;
	___test.run_test(-1);
}
// END CUT HERE
