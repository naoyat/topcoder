// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// Your character in a game has two properties: strength and intellect.  Initially, both are equal to 1.  There are several missions in the game, and to complete mission i, you must have strength of at least strength[i] or intellect of at least intellect[i].  After you complete mission i, you receive points[i] points that can be added to your properties.  You can distribute these points however you want between the two properties.  Each mission can be completed only once, and missions can be completed in any order.  Return the maximum number of missions you can complete.

DEFINITION
Class:StrengthOrIntellect
Method:numberOfMissions
Parameters:vector <int>, vector <int>, vector <int>
Returns:int
Method signature:int numberOfMissions(vector <int> strength, vector <int> intellect, vector <int> points)


CONSTRAINTS
-strength will contain between 1 and 50 elements, inclusive.
-strength, intellect and points will contain the same number of elements.
-Each element of strength, intellect and points will be between 1 and 1000, inclusive.


EXAMPLES

0)
{1, 2}
{1, 2}
{1, 2}

Returns: 2

Complete mission 0. After adding 1 point to either inlellect or strength you will be able to complete mission 1.

1)
{3}
{2}
{1}

Returns: 0

Only one mission and you can't complete it.

2)
{1, 3, 1, 10, 3}
{1, 1, 3, 20, 3}
{2, 1, 1, 5, 1}

Returns: 4



3)
{1, 2, 100, 5, 100, 10, 100, 17, 100}
{1, 100, 3, 100, 7, 100, 13, 100, 21}
{1, 2, 3, 4, 5, 6, 7, 8, 1}

Returns: 9



4)
{1, 10, 1, 2, 16, 12, 13, 19, 12, 8}
{1, 5, 1, 8, 3, 5, 3, 16, 19, 20}
{1, 1, 1, 2, 1, 1, 2, 3, 5, 1}

Returns: 7



*/
// END CUT HERE

#line 71 "StrengthOrIntellect.cpp"
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

class StrengthOrIntellect {
public:
  int numberOfMissions(vector<int> st, vector<int> il, vector<int> pt) {
	int n = st.size();
	int start = -1, start_pt = -1;
	for (int i=0;i<n;i++) {
	  if (st[i] == 1 && il[i] == 1 && pt[i] > start_pt) {
		start = i; start_pt = pt[i];
	  }
	}
	if (start == -1) return 0;
// BEGIN CUT HERE
//	cout << "st: " << st << endl;
//	cout << "il: " << il << endl;
//	cout << "pt: " << pt << endl;
// strength, il;  : 1-50 elems
// st[], il[] pt[] 1-1000
// END CUT HERE
/*
//	vector<vector<pair<int,int> > > m(n);
	for (int i=0;i<n;i++) {
	  //	  m[i].resize(n);
	  int si = st[i], ii = il[i];
	  for (int j=0;j<n;j++) {
		if (j==i) continue;
		int sj = st[j], ij = il[j];
		//		m[i][j] = make_pair( max(0,sj-si), max(0,ij-ii) );
		//		m[j][i] = make_pair( max(0,si-sj), max(0,ii-ij) );
	  }
	}
*/
	priority_queue<pair<vector<int>,set<int> > > pq;
	// depth, last, sj, si, のこり
	vector<int> s0(5);
	s0[0] = -1; s0[1] = start;
	s0[2] = s0[3] = 1; s0[4] = pt[start];
	set<int> h0; h0.insert(start);
	pq.push(make_pair(s0,h0));

	int depth_max = 1;
	while (!pq.empty()) {
	  cout << pq.size() << endl;
	  vector<int> n0 = pq.top().first;
	  set<int> h = pq.top().second;
	  int i = n0[1];
	  pq.pop();

// BEGIN CUT HERE
	  //	  cout << "n0 = " << n0 << endl;
	  //	  cout << "depth = " << -n0[0] << endl;
	  //	  cout << "h " << h.size() << " = " << h << endl;
// END CUT HERE

	  for (int j=0; j<n; j++) {
		if (j==i) continue;
		if (h.find(j) != h.end()) continue;

		int m2 = max(0, st[j] - n0[2]);
		int m3 = max(0, il[j] - n0[3]);

		if (m2 <= n0[4]) {
		  vector<int> n1(5);
		  n1[0] = n0[0] - 1; 
		  if (-n1[0] > depth_max) depth_max = -n1[0];
		  if (depth_max == n) return n;
		  set<int> h1(h);
		  h1.insert(j);
		  n1[1] = j;
		  n1[2] = n0[2] + m2;
		  n1[3] = n0[3];
		  n1[4] = n0[4] - m2 + pt[j];
		  pq.push(make_pair(n1,h1));
		}
		if (m3 <= n0[4] && m2 != 0) {
		  vector<int> n1(5);
		  n1[0] = n0[0] - 1; 
		  if (-n1[0] > depth_max) depth_max = -n1[0];
		  if (depth_max == n) return n;
		  set<int> h1(h);
		  h1.insert(j);
		  n1[1] = j;
		  n1[2] = n0[2];
		  n1[3] = n0[3] + m3;
		  n1[4] = n0[4] - m3 + pt[j];
		  pq.push(make_pair(n1,h1));
		}
	  }
	}
	return depth_max;
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
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2();
	  if ((Case == -1) || (Case == 3)) test_case_3();
	  if ((Case == -1) || (Case == 4)) test_case_4();
	  if ((Case == -1) || (Case == 999)) test_case_999();
	}
private:
  template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
  void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
  void test_case_0() { int Arr0[] = {1, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1, 2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2; verify_case(0, Arg3, numberOfMissions(Arg0, Arg1, Arg2)); }
  void test_case_1() { int Arr0[] = {3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 0; verify_case(1, Arg3, numberOfMissions(Arg0, Arg1, Arg2)); }
  void test_case_2() { int Arr0[] = {1, 3, 1, 10, 3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 1, 3, 20, 3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2, 1, 1, 5, 1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 4; verify_case(2, Arg3, numberOfMissions(Arg0, Arg1, Arg2)); }
  void test_case_3() { int Arr0[] = {1, 2, 100, 5, 100, 10, 100, 17, 100}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 100, 3, 100, 7, 100, 13, 100, 21}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1, 2, 3, 4, 5, 6, 7, 8, 1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 9; verify_case(3, Arg3, numberOfMissions(Arg0, Arg1, Arg2)); }
  void test_case_4() { int Arr0[] = {1, 10, 1, 2, 16, 12, 13, 19, 12, 8}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 5, 1, 8, 3, 5, 3, 16, 19, 20}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1, 1, 1, 2, 1, 1, 2, 3, 5, 1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 7; verify_case(4, Arg3, numberOfMissions(Arg0, Arg1, Arg2)); }
  void test_case_999() {
	int Arr0[] = {1,21,41,61,81,101,121,141,161,181,201,221,241,261,281,301,321,341,361,381,401,421,441,461,481,501,521,541,561,581,601,621,641,661,681,701,721,741,761,781,801,821,841,861,881,901,921,941,961,981};
	vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
	int Arr1[] = {1,979,959,939,919,899,879,859,839,819,799,779,759,739,719,699,679,659,639,619,599,579,559,539,519,499,479,459,439,419,399,379,359,339,319,299,279,259,239,219,199,179,159,139,119,99,79,59,39,19};
	vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
	int Arr2[] = {1000,994,988,983,978,972,967,962,957,952,946,941,936,931,926,921,916,910,905,900,895,890,885,880,875,870,864,859,854,849,844,839,834,829,824,819,814,808,803,798,793,788,783,778,773,768,763,758,753,748};
	vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
	int Arg3 = 7; verify_case(999, Arg3, numberOfMissions(Arg0, Arg1, Arg2));
  }

// END CUT HERE

};

// BEGIN CUT HERE
int main(int argc, char *argv[]) {
	StrengthOrIntellect ___test;
	___test.run_test( argc>=2 ? atoi(argv[1]):-1 );
}
// END CUT HERE
