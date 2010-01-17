// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
N checkers are placed on an infinitely large board.  The i-th checker is in the cell at row x[i], column y[i].  There can be more than one checker in the same cell.  A move consists of taking one checker and moving it one cell up, down, left or right.



Return a vector <int> containing exactly N elements, where the i-th element (0-based) is the minimum number of moves necessary to end up with at least i+1 checkers in the same cell.



DEFINITION
Class:TheTower
Method:count
Parameters:vector <int>, vector <int>
Returns:vector <int>
Method signature:vector <int> count(vector <int> x, vector <int> y)


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
#include <queue>
// BEGIN CUT HERE
#include <iostream>
#include "cout.h"
// END CUT HERE
#include <sstream>
using namespace std;

class TheTower {
	public:
	vector<int> count(vector<int> x, vector<int> y) {
	  int n = x.size();

	  priority_queue<pair<int,pair<int,int> > > pq;
	  for (int i=0;i<n;i++) {
		int dsum = 0, dmin = INT_MAX;
		for (int j=0;j<n;j++) {
		  if (j != i) {
			int d = abs(x[i] - x[j]) + abs(y[i] - y[j]);
			if (d < dmin) dmin = d;
			dsum += d*d;
		  }
		}
		pq.push(make_pair(-dmin,make_pair(-dsum,i)));
	  }
	  vector<int> ds(n);
	  int ix =0;
	  while(!pq.empty()) {
		ds[ix++] = pq.top().second.second;
		pq.pop();
	  }
// BEGIN CUT HERE
	  cout << "ds:" << ds << endl;
// END CUT HERE

	  vector<int> retv(n,0);
	  for (int j=2;j<=n;j++) {
		int xsum = 0, ysum = 0;
		for (int i=0;i<j;i++) { xsum += x[i]; ysum += y[i]; }
		int xavg = (xsum + j/2) / j, yavg = (ysum + j/2) / j;
		int dsum = 0;
		for (int i=0;i<j;i++) {
		  int distance = abs(x[i] - xavg) + abs(y[i] - yavg);
		  dsum += distance;
		}
		retv[j-1] = dsum;
	  }
// BEGIN CUT HERE
	  cout << retv << endl;
// END CUT HERE
	  return retv;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1();
	  if ((Case == -1) || (Case == 2)) test_case_2();
	  if ((Case == -1) || (Case == 40)) test_case_40();
	  if ((Case == -1) || (Case == 50)) test_case_50();
	}
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }

	void test_case_0() { int Arr0[] = {1, 2, 4, 9}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 1, 1, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0, 1, 3, 10 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, count(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {15, 15, 14, 16}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {14, 16, 15, 15}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0, 2, 3, 4 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, count(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {4, 4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {7, 7}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0, 0 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, count(Arg0, Arg1)); }

  void test_case_40() {
	int Arr0[] = {1,10,100,1000,10000,100000,1000000};
	vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
	int Arr1[] = {1,10,100,1000,10000,100000,1000000};
	vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
	int Arr2[] = { 0, 1,2,3,4,5,6};
	vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
	verify_case(40, Arg2, count(Arg0, Arg1));
  }
  void test_case_50() {
	int Arr0[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,
				  21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,
				  41,42,43,44,45,46,47,48,49,50};
	vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
	int Arr1[] = {1,1,1,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,1,1,1,
				  1,1,1,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,1,1,1 };
	vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
	int Arr2[] = { 0, 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,
				  21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,
				   41,42,43,44,45,46,47,48,49 };
	vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
	verify_case(50, Arg2, count(Arg0, Arg1));
  }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	TheTower ___test;
	___test.run_test(-1);
}
// END CUT HERE
