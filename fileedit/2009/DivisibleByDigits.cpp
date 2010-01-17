// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// Given an integer n, find the smallest integer that starts with n and is divisible by every non-zero digit of n (all in decimal notation).

DEFINITION
Class:DivisibleByDigits
Method:getContinuation
Parameters:int
Returns:long long
Method signature:long long getContinuation(int n)


NOTES
-An integer A starts with an integer B if the string representation of B is a prefix of the string representation of A (both in decimal notation with no leading zeroes).


CONSTRAINTS
-n will be between 1 and 1000000000, inclusive.


EXAMPLES

0)
13

Returns: 132

We need a number that starts with 13 and is divisible by 1 (always true) and by 3. The smallest one is 132.


1)
648

Returns: 648

If n is divisible by all its non-zero digits, the answer to the problem is n itself.

2)
566

Returns: 56610

The resulting number must be divisible by 5, so it should end either with 0 or with 5. But a number ending with 5 is odd and can't be divisible by 6. So the last digit of the answer must be 0. In order to make the number divisible by 6, we need to put something before this 0, and the smallest appropriate digit is 1.

3)
1000000000

Returns: 1000000000



4)
987654321

Returns: 987654321360



5)
83

Returns: 8304



*/
// END CUT HERE

#line 71 "DivisibleByDigits.cpp"
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
// END CUT HERE
#include <sstream>
#include <cmath>
using namespace std;

// BEGIN CUT HERE
#define sz(a)  int((a).size())
#define pb  push_back
#define all(c)  (c).begin(),(c).end()
#define tr(c,i)  for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); i++)
#define rep(var,n)  for(int var=0;var<(n);var++)
#define found(s,e)  ((s).find(e)!=(s).end())
#define remove_(c,val) (c).erase(remove((c).begin(),(c).end(),(val)),(c).end())
// END CUT HERE

int gcd(int m, int n)
{
  if (m == 0 || n == 0) return 0;
  if (m == 1 || n == 1) return 1;
  if (m == n) return m;
  while (1) {
        if (m == 0) return n;
        if (n == 0) return m;
        if (m > n) m %= n; else n %= m;
  }
}
int lcm(int m, int n)
{
  return m / gcd(m,n) * n;
}

class DivisibleByDigits {
 public:
  long long getContinuation(int n) {
	long long de=1LL;
    for(int _=n;_>0;_/=10){
      int r=_%10;
      if(r) de=lcm(de,r);
    }
    for(long long b=n,m=1;b<=LONG_LONG_MAX;b*=10,m*=10){
      long long r=b%de;
      if(r==0)return b;
      long long s=de-r;
      if(s<=m-1)return b+s;
    }
    return 0;
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
	int n = 13; 
	long long RetVal = 132LL; 
	return verify_case(RetVal, DivisibleByDigits().getContinuation(n)); }
int Test_(Case_<1>) {
	timer_clear();
	int n = 648; 
	long long RetVal = 648LL; 
	return verify_case(RetVal, DivisibleByDigits().getContinuation(n)); }
int Test_(Case_<2>) {
	timer_clear();
	int n = 566; 
	long long RetVal = 56610LL; 
	return verify_case(RetVal, DivisibleByDigits().getContinuation(n)); }
int Test_(Case_<3>) {
	timer_clear();
	int n = 1000000000; 
	long long RetVal = 1000000000LL; 
	return verify_case(RetVal, DivisibleByDigits().getContinuation(n)); }
int Test_(Case_<4>) {
	timer_clear();
	int n = 987654321; 
	long long RetVal = 987654321360LL; 
	return verify_case(RetVal, DivisibleByDigits().getContinuation(n)); }
int Test_(Case_<5>) {
	timer_clear();
	int n = 83; 
	long long RetVal = 8304LL; 
	return verify_case(RetVal, DivisibleByDigits().getContinuation(n)); }

template<int N> void Run_() { cerr << "Test Case #" << N << "..." << flush; Test_(Case_<N>()); Run_<sizeof(Test_(Case_<N+1>()))==1 ? -1 : N+1>(); }
template<>      void Run_<-1>() {}
int main() { Run_<0>(); }
// END CUT HERE

