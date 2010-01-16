#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
 
using namespace std;
 
class TheAlmostLuckyNumbers {
public:
  long long count(long long, long long);
};
 
long long a[10000], da[10000], b[10000], c[10000];
int last[10000], ls[10000];
 
long long TheAlmostLuckyNumbers::count(long long left, long long right) {
  int n = 0, d, t, i, j;
  long long x;
  for (d=1;d<=10;d++) {
    for (t=0;t<(1<<d);t++) {
      x = 0;
      for (i=d-1;i>=0;i--) {
        x = x*10+4;
        if (t & (1 << i)) x += 3;
      }
      for (i=0;i<n;i++)
        if (x % a[i] == 0) x = 0;
      if (x) a[n++] = x;
    }
  }
  long long ans = 0, aa, bb;
  for (i=0;i<n;i++) {
    if (a[i] > right) {
      n = i;
      break;
    }
    da[i] = right/a[i];
    ans += right/a[i]-(left-1)/a[i];
    last[i] = i;
  }
  int m, q, p;
  m = n;
  for (i=0;i<m;i++) b[i] = a[i];
  q = 1;
  while (m) {
    q = -q; p = 0;
    for (i=0;i<m;i++)
      for (j=last[i]+1;j<n;j++) {
        aa = b[i]; bb = a[j];
        while (aa && bb)
          if (aa > bb) aa %= bb;
          else bb %= aa;
        x = b[i]/(aa+bb);
        if (x > da[j]*10000000) break;
        if (x > da[j]) continue;
        x *= a[j];
        if (x <= right) {
          c[p] = x;
          ls[p++] = j;
        }
      }
    m = p;
    for (i=0;i<m;i++) {
      b[i] = c[i];
      last[i] = ls[i];
    }
    for (i=0;i<m;i++) ans += q*(right/b[i]-(left-1)/b[i]);
  }
  return ans;
}
 
 
//Powered by [KawigiEdit] 2.0!
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
