// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// You are given a vector <int> S containing a set of distinct integers.  A sequence is called a p-sequence of S if it satisfies both of the following conditions:

1. It contains each element of S exactly once.
2. For each pair of consecutive sequence elements s1 and s2,  (s1 - s2) is not divisible by p.

Return the number of p-sequences of S, modulo 1234567891.

DEFINITION
Class:PSequence
Method:count
Parameters:vector <int>, int
Returns:int
Method signature:int count(vector <int> S, int p)


CONSTRAINTS
-S will contain between 1 and 30 elements, inclusive.
-All elements of S will be distinct.
-Each element of S will be between -1,000,000 and 1,000,000, inclusive.
-p will be between 1 and 1,000, inclusive.


EXAMPLES

0)
{-1,0,1,2,3}
10

Returns: 120

All permutations of numbers are valid, so we have 5! = 120 sequences.

1)
{6,2}
4

Returns: 0

Both numbers have the same remainder modulo 4 and so we cannot create a valid 4-sequence from them.

2)
{1,2,3,4}
3

Returns: 12



3)
{4,6,8,-3,7}
2

Returns: 12



*/
// END CUT HERE

#line 64 "PSequence.cpp"
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

class PSequence {
public:
  int count(vector<int> S, int p) {
	int n = S.size(); // 30
	vector<vector<bool> > ds(n); for (int i=0;i<n;i++) ds[i].resize(n);
	for (int i=0;i<n;i++) {
	  for (int j=i+1;j<n;j++) {
		ds[j][i] = ds[i][j] = (abs(S[i] - S[j]) % p) == 0 ? false : true;
	  }
	}
	cout << ds << endl;

	// 

	//next_permutation(all(S));
	return 0;
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
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {-1,0,1,2,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; int Arg2 = 120; verify_case(0, Arg2, count(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {6,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; int Arg2 = 0; verify_case(1, Arg2, count(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {1,2,3,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 12; verify_case(2, Arg2, count(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {4,6,8,-3,7}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 12; verify_case(3, Arg2, count(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main(int argc, char *argv[]) {
	PSequence ___test;
	___test.run_test( argc>=2 ? atoi(argv[1]):-1 );
}
// END CUT HERE
