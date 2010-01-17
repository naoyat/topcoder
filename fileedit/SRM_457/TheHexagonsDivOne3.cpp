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

long long c(int n, int r)
{
  if (n == 0 || r == 0 || r == n) return 1LL;
  if (r > n-r) r = n-r;
  return c(n-1,r-1) * n / r;
}

class TheHexagonsDivOne {
  bool meq(int a,int b,int mod){ return (a%mod == b%mod); }

  vector<int> shift(vector<int> vec){
    vector<int> res(sz(vec));
    int at = min_element(all(vec)) - vec.begin();
    rep(i,6) res[i] = vec[(at+i)%6];
    return res;
  }

 public:
  long long count(int n) {
    if (n<4) return 0LL;
    ll N=(ll)n;

    ll cnt=0LL;

    // 3 pairs
    if (N >= 4) {
      vector<int> iota(6); iota[0]=-3, iota[1]=-2, iota[2]=-1, iota[3]=1, iota[4]=2, iota[5]=3;
      sort(all(iota));
      set<vector<int> > pats;
      do {
        rep(i,6) if (abs(iota[i%6])==abs(iota[(i+1)%6])) goto next3;
        pats.insert( shift(iota) );
     next3:;
      } while (next_permutation(all(iota)));
      cnt += c(N,4) * c(4,1)*2 * sz(pats);  // last 2 for z
    }

    // 2 pairs (z, 1,1,2,2,a,b)
    if (N >= 5) {
      vector<int> iota(6); iota[0]=-2, iota[1]=-1, iota[2]=1, iota[3]=2, iota[4]=0, iota[5]=0;
      sort(all(iota));
      set<vector<int> > pats;
      do {
        //        rep(i,6) if (iota[i] && abs(iota[i%6])==abs(iota[(i+1)%6])) goto next2;
        rep(i,6) { if (!iota[i]) continue; if (abs(iota[i%6])==abs(iota[(i+1)%6])) goto next2; }
        pats.insert( shift(iota) );
     next2:;
      } while (next_permutation(all(iota)));
      cnt += c(N,5) * c(5,1)*2 * c(4,1)*2 * c(3,1)*2 * sz(pats);
    }

    // 1 pair (z, 1,1,a,b,c,d)
    if (N >= 6) {
      vector<int> iota(6); iota[0]=-1, iota[1]=1, iota[2]=0, iota[3]=0, iota[4]=0, iota[5]=0;
      sort(all(iota));
      set<vector<int> > pats;
      do {
        rep(i,6) { if (!iota[i]) continue; if (abs(iota[i%6])==abs(iota[(i+1)%6])) goto next1; }
        pats.insert( shift(iota) );
     next1:;
      } while (next_permutation(all(iota)));
      cnt += c(N,6) * c(6,1)*2 * c(5,1)*2 * c(4,1)*2 * c(3,1)*2 * c(2,1)*2 * sz(pats);
    }

    // no pairs
    if (N >= 7) {
      cnt += c(N,7) * c(7,1)*2 * c(6,1)*2 * c(5,1)*2 * c(4,1)*2 * c(3,1)*2 * c(2,1)*2 * c(1,1)*2 / 6;
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
