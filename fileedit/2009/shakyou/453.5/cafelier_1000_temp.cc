#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>
#include <iterator>
#include <functional>
#include <complex>
#include <queue>
#include <stack>
#include <cmath>
#include <cassert>
#include <cstring>
using namespace std;
typedef long long LL;
typedef complex<double> CMP;

LL gcd(LL a, LL b)
{
  while(a)
    swap(a, b%=a);
  return b;
}

LL lcm(LL a, LL b)
{
  return a/gcd(a,b)*b;
}

class TheAlmostLuckyNumbers { public:
  void genLuck(vector<LL>& v)
  {
    // lucky numbers
    vector<LL> u;
    for(int d=1; d<=10; ++d)
      genLuck(d, u);

    // filtering
    for(int i=0; i<u.size(); ++i)
    {
      for(int j=0; j<i; ++j)
        if( u[i] % u[j] == 0 )
          goto next;
      v.push_back( u[i] );
    next:;
    }
    sort(v.begin(), v.end());
    // 1199 lucky numbers are left...
  }

  void genLuck(int d, vector<LL>& v)
  {
    // d-digit lucky numbers
    for(int b=0; b<(1<<d); ++b)
    {
      LL n = 0;
      for(int i=0; i<d; ++i)
        n = n*10 + (b&(1<<i) ? 4 : 7);
      v.push_back(n);
    }
  }

  long long count(long long a, long long b) 
  {
    vector<LL> v;
    genLuck(v);

    static const int M = 16;

    // inclusion-exclusion
    LL cnt = 0;
    {
      for(int m=1; m<(1<<M); ++m)
      {
        int bc = 0;
        LL n = 1;
        for(int i=0; i<M; ++i)
          if( m & (1<<i) )
            ++bc, n=lcm(n, v[i]);
        cnt += (bc&1) ? (b/n-(a-1)/n) : -(b/n-(a-1)/n);
      }
    }

    // sieve
    vector<LL> aml;
    for(int i=M; i<v.size() && v[i]<=b; ++i)
    {
      LL u = v[i];
      for(LL s=a%u?(a/u+1)*u:a; s<=b; s+=u)
      {
        for(int k=0; k<M; ++k)
          if( s%v[k]==0 )
            goto next;
        aml.push_back(s);
      next:;
      }
      if( aml.size() > 10000000 ) {
        sort(aml.begin(), aml.end());
        aml.erase(unique(aml.begin(), aml.end()), aml.end());
      }
    }

        sort(aml.begin(), aml.end());
        aml.erase(unique(aml.begin(), aml.end()), aml.end());
    return cnt + aml.size();
  }
};



// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003] : <cafelier&naoya_t>-custom
// Powered by CodeProcessor
#include "cout.h"
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
	long long a = 1LL; 
	long long b = 10LL; 
	long long RetVal = 3LL; 
	return verify_case(RetVal, TheAlmostLuckyNumbers().count(a, b)); }
int Test_(Case_<1>) {
	timer_clear();
	long long a = 14LL; 
	long long b = 14LL; 
	long long RetVal = 1LL; 
	return verify_case(RetVal, TheAlmostLuckyNumbers().count(a, b)); }
int Test_(Case_<2>) {
	timer_clear();
	long long a = 1LL; 
	long long b = 100LL; 
	long long RetVal = 39LL; 
	return verify_case(RetVal, TheAlmostLuckyNumbers().count(a, b)); }
int Test_(Case_<3>) {
	timer_clear();
	long long a = 1234LL; 
	long long b = 4321LL; 
	long long RetVal = 1178LL; 
	return verify_case(RetVal, TheAlmostLuckyNumbers().count(a, b)); }
int Test_(Case_<4>) {
	timer_clear();
	long long a =  9999999999LL;
	long long b = 10000000000LL;
	long long RetVal = 1LL; 
	return verify_case(RetVal, TheAlmostLuckyNumbers().count(a, b)); }

template<int N> void Run_() { cerr << "Test Case #" << N << "..." << flush; Test_(Case_<N>()); Run_<sizeof(Test_(Case_<N+1>()))==1 ? -1 : N+1>(); }
template<>      void Run_<-1>() {}
int main() { Run_<0>(); }
// END CUT HERE


// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// A lucky number is a number whose decimal representation contains only the digits 4 and 7.  An almost lucky number is a number that is divisible by a lucky number.  For example, 14, 36 and 747 are almost lucky, but 2 and 17 are not. Note that a number can be both lucky and almost lucky at the same time (for example, 747).

You are given long longs a and b.  Return the number of almost lucky numbers between a and b, inclusive.

DEFINITION
Class:TheAlmostLuckyNumbers
Method:count
Parameters:long long, long long
Returns:long long
Method signature:long long count(long long a, long long b)


CONSTRAINTS
-a will be between 1 and 10,000,000,000, inclusive.
-b will be between a and 10,000,000,000, inclusive.


EXAMPLES

0)
1
10

Returns: 3

There are three almost lucky numbers less than or equal to ten - 4, 7 and 8.

1)
14
14

Returns: 1

14 is an almost lucky number.

2)
1
100

Returns: 39

3)
1234
4321

Returns: 1178

*/
