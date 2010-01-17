// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// Long long ago, there was a kingdom named Kingdom C.  There were n cities in Kingdom C, and every pair of cities was connected by a two-way road.  Unfortunately, some of those roads may have been destroyed in a heavy rain.
You are given a vector <string> roads.  The probability that the road connecting city i and city j is still available after the heavy rain is d/8, where d is the j-th digit of the i-th element of roads.
The king of Kingdom C is very sad, and he wants to know the probability of the following scenario: Every city is reachable from the capital (city 0), but if you were to destroy any one of the remaining roads, there would be at least one city that is not reachable from the capital.  Return the probability of this scenario as a double.

DEFINITION
Class:RoadsOfKingdom
Method:getProbability
Parameters:vector <string>
Returns:double
Method signature:double getProbability(vector <string> roads)


NOTES
-Your return must have relative or absolute error less than 1E-9.


CONSTRAINTS
-roads will contain exactly n elements, where n is between 2 and 16, inclusive.
-Each element of roads will contain exactly n characters.
-All characters in roads will be between '0' and '8', inclusive.
-Character i in element i of roads will be '0'.
-Character i in element j of roads will be the same as character j in element i of roads.


EXAMPLES

0)
{"04",
 "40"}

Returns: 0.5

There is exactly one road connecting the capital and city 1. The answer is equal to the probability that the road is available after the rain.

1)
{"08",
 "80"}

Returns: 1.0

The same example as above, but this time the road is always available.

2)
{"00",
 "00"}

Returns: 0.0

In this case, all roads have been destroyed.

3)
{"088",
 "808",
 "880"}

Returns: 0.0

Here all three roads 0-1, 0-2 and 1-2 are definitely not destroyed. These roads form a cycle, so you can always remove a road in such way that all cities are reachable from the capital.

4)
{"044",
 "404",
 "440"}

Returns: 0.375

Exactly two of three roads should be available, so the probability is C(3,2) * 0.5^3 = 0.375.

5)
{"0701",
 "7071",
 "0708",
 "1180"}

Returns: 0.622314453125



*/
// END CUT HERE

#line 86 "RoadsOfKingdom.cpp"
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
#define rep(n,i) for(int i=0;i<n;i++)

class RoadsOfKingdom {
public:
  double getProbability(vector<string> roads) {
	int N=sz(roads);
	vector<vector<double> > rs(N);
	rep(N,i) {
	  rs[i].resize(N);
	  rep(N,j) {
		rs[j][i] = rs[i][j] = 0.125 * (roads[i][j] - '0');
	  }
	}
	cout << "rs: " << rs << endl;

	
	return 0.0;
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
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"04",
 "40"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 0.5; verify_case(0, Arg1, getProbability(Arg0)); }
	void test_case_1() { string Arr0[] = {"08",
 "80"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 1.0; verify_case(1, Arg1, getProbability(Arg0)); }
	void test_case_2() { string Arr0[] = {"00",
 "00"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 0.0; verify_case(2, Arg1, getProbability(Arg0)); }
	void test_case_3() { string Arr0[] = {"088",
 "808",
 "880"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 0.0; verify_case(3, Arg1, getProbability(Arg0)); }
	void test_case_4() { string Arr0[] = {"044",
 "404",
 "440"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 0.375; verify_case(4, Arg1, getProbability(Arg0)); }
	void test_case_5() { string Arr0[] = {"0701",
 "7071",
 "0708",
 "1180"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 0.622314453125; verify_case(5, Arg1, getProbability(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main(int argc, char *argv[]) {
	RoadsOfKingdom ___test;
	___test.run_test( argc>=2 ? atoi(argv[1]):-1 );
}
// END CUT HERE
