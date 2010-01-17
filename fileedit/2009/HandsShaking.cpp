#line 2 "HandsShaking.cpp"
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
#define pb  push_back
#define all(c)  (c).begin(),(c).end()
#define tr(c,i)  for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); i++)
#define rep(var,n)  for(int var=0;var<(n);var++)
#define found(s,e)  ((s).find(e)!=(s).end())

class HandsShaking {
  map<int,ll> memo;
 public:
  long long countPerfect(int n) {
    if(n==0) return 0LL;
    if(n==2) return 1LL;
    if(found(memo,n)) return memo[n];
    ll sum=0;
    for(int i=1;i<n;i+=2){
      int a=i-1, b=n-i-1;
      if(a==0) sum+=countPerfect(b);
      else if(b==0) sum+=countPerfect(a);
      else sum+=countPerfect(a)*countPerfect(b);
    }
    return memo[n]=sum;
  }
};

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
	int n = 2; 
	long long RetVal = 1LL; 
	return verify_case(RetVal, HandsShaking().countPerfect(n)); }
int Test_(Case_<1>) {
	timer_clear();
	int n = 4; 
	long long RetVal = 2LL; 
	return verify_case(RetVal, HandsShaking().countPerfect(n)); }
int Test_(Case_<2>) {
	timer_clear();
	int n = 8; 
	long long RetVal = 14LL; 
	return verify_case(RetVal, HandsShaking().countPerfect(n)); }

template<int N> void Run_() { cerr << "Test Case #" << N << "..." << flush; Test_(Case_<N>()); Run_<sizeof(Test_(Case_<N+1>()))==1 ? -1 : N+1>(); }
template<>      void Run_<-1>() {}
int main() { Run_<0>(); }
// END CUT HERE


// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// Consider a meeting of n businessmen sitting around a circular table. To start the meeting, they must shake hands. Each businessman shakes the hand of exactly one other businessman. All handshakes happen simultaneously. We say that the shake is perfect if no arms cross each other. Given an int n, return the number of perfect shakes that exist for n businessmen. See examples for further clarification.

DEFINITION
Class:HandsShaking
Method:countPerfect
Parameters:int
Returns:long long
Method signature:long long countPerfect(int n)


NOTES
-Businessmen are distinguishable. Rotating a perfect shake can yield a different perfect shake (see example 1).


CONSTRAINTS
-n will be between 2 and 50, inclusive.
-n will be even.


EXAMPLES

0)
2

Returns: 1

Two businessmen have only one possibility - just to shake each other's hand.

1)
4

Returns: 2

Two out of three possible shakes are perfect.
    

2)
8

Returns: 14



*/
// END CUT HERE
