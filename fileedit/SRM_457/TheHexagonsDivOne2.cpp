#line 2 "TheHexagonsDivOne.cpp"
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <cctype>
#include <algorithm>
#include <string>
#include <vector>
#include <deque>
#include <stack>
#include <queue>
#include <list>
#include <map>
#include <set>
// BEGIN CUT HERE
#include "cout.h"
// END CUT HERE
using namespace std;
typedef long long ll;
#define sz(a)  int((a).size())
#define pb  push_back
#define FOR(var,from,to) for(int var=(from);var<=(to);var++)
#define rep(var,n)  for(int var=0;var<(n);var++)
#define all(c)  (c).begin(),(c).end()

class TheHexagonsDivOne {
 public:
  long long count(int n) {
// BEGIN CUT HERE
    //    printf("count(%d)..\n", n);
// END CUT HERE
    ll N=n;
// BEGIN CUT HERE
	// 7枠あるのです.
// END CUT HERE
    if (n*2 < 7) return 0LL;
// BEGIN CUT HERE
    // 1 .. 2n(wn); n=150で300
// END CUT HERE
    ll cnt=0LL;

// BEGIN CUT HERE
    // 0組 z+ 123456
// END CUT HERE
    if (n>=7) { // z, a,b,c,d,e,f
      ll p = N * (N-1) * (N-2) * (N-3) * (N-4) * (N-5) * (N-6);
      ll mag = 2*2*2*2*2*2*2; // z,a,b,c,d,e,f
      cnt += p*mag/6;
    }

// BEGIN CUT HERE
    // 1組 z+ 1.1..., 1..1..
// END CUT HERE
    if (n>=6) { // z, 1, a,b,c,d
      ll p = N * (N-1) * (N-2) * (N-3) * (N-4) * (N-5);
      ll mag = 2*2*2*2*2; // z,a,b,c,d
      ll pat = 2*6 + 2*3;
      cnt += p*mag*pat/6; // 1
    }

// BEGIN CUT HERE
    // 2組 z+ 1212..
    //        121.2.  // 121..2
    //        12.21. 1.12.2 (=21.12.)
    //         [13][24] [31][42]
    //        12.12. // 12.1.2(=212.1.=121.2.)
    //         1[24] 3[42]
    //        //1.212.(=121.2.) //1.21.2(=21.21.)
// END CUT HERE
    if (n>=5) { // z, 1,2, a,b
      ll p = N * (N-1) * (N-2) * (N-3) * (N-4);
      ll mag = 2*2*2;
      ll pat = 2*2*6 + 2*2*6 + 2*6 + 2*6;
      cnt += p*mag*pat/6; // 1,2
    }

// BEGIN CUT HERE
    // 3組 z + 121323, 131232, 123132 (132123), 123123, 132132, x
// END CUT HERE
    if (n>=4) { // z, 1,2,3
      ll p = N * (N-1) * (N-2) * (N-3);
      ll mag = 2;
      ll pat = 2*2*2 + 2*2*2 + 2*2*2 + 2*2*2;
      cnt += p*mag*pat/6;
    }

    return cnt;
  }
}; // 181.86 = 74'56''

// BEGIN CUT HERE
#include <time.h>
clock_t start_time;
void timer_clear() { start_time = clock(); }
string timer() { clock_t end_time = clock(); double interval = (double)(end_time - start_time)/CLOCKS_PER_SEC; ostringstream os; os << " (" << interval*1000 << " msec)"; return os.str(); }

template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
int verify_case(const long long &Expected, const long long &Received) { if (Expected == Received) cerr << "PASSED" << timer() << endl; else { cerr << "FAILED" << timer() << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } return 0;}

template<int N> struct Case_ {};
char Test_(...);
int Test_(Case_<0>) {
	timer_clear();
	int n = 3; 
	long long RetVal = 0LL; 
	return verify_case(RetVal, TheHexagonsDivOne().count(n)); }
int Test_(Case_<1>) {
	timer_clear();
	int n = 4; 
	long long RetVal = 256LL; 
	return verify_case(RetVal, TheHexagonsDivOne().count(n)); }
int Test_(Case_<2>) {
	timer_clear();
	int n = 8; 
	long long RetVal = 3458560LL; 
	return verify_case(RetVal, TheHexagonsDivOne().count(n)); }
int Test_(Case_<3>) {
	timer_clear();
	int n = 20; 
	long long RetVal = 11193888000LL; 
	return verify_case(RetVal, TheHexagonsDivOne().count(n)); }

template<int N> void Run_() { cerr << "Test Case #" << N << "..." << flush; Test_(Case_<N>()); Run_<sizeof(Test_(Case_<N+1>()))==1 ? -1 : N+1>(); }
template<>      void Run_<-1>() {}
int main() { Run_<0>(); }
// END CUT HERE


// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// John and Brus are interested in a new game called "Hexagon Flower".  The rules are simple.  You are given a flower formed by seven hexagons arranged as follows:



The objective of the game is to place a number in each hexagon of the flower such that all of the following conditions are satisfied:

Each number is an integer between 1 and n*2, inclusive.
Each number is distinct.
For every pair of adjacent hexagons, if the numbers placed in them are a and b, then a%n != b%n.

Given n, return the total number of distinct solutions.  Two solutions are considered the same if you can rotate one to form the other.

For example, if n = 4 then:



The top three placements are not valid.  The other three placements are valid, but the first two among them are considered equal since one can be rotated to become the other.

DEFINITION
Class:TheHexagonsDivOne
Method:count
Parameters:int
Returns:long long
Method signature:long long count(int n)


CONSTRAINTS
-n will be between 1 and 150, inclusive.


EXAMPLES

0)
3

Returns: 0

There are not enough numbers to fill the flower with.

1)
4

Returns: 256



2)
8

Returns: 3458560



3)
20

Returns: 11193888000



*/
// END CUT HERE
