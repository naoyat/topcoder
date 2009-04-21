// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
John and Brus are studying string theory at the university.  Their task is to create a list of all the palindromes that contain between 1 and n lowercase letters ('a'-'z'), inclusive.  A palindrome is a string that reads the same forward and backward.  Additionally, each palindrome in their list must contain no more than k distinct letters.  Return the number of palindromes in the list modulo 1234567891.


DEFINITION
Class:TheLongPalindrome
Method:count
Parameters:int, int
Returns:int
Method signature:int count(int n, int k)


CONSTRAINTS
-n will be between 1 and 1,000,000,000, inclusive.
-k will be between 1 and 26, inclusive.


EXAMPLES

0)
1
1

Returns: 26

All palindromes in the list are single character strings.

1)
2
10

Returns: 52

Now we have single and double character palindromes.

2)
3
2

Returns: 728

A slightly longer list.

3)
44
7

Returns: 240249781

*/
// END CUT HERE

#line 57 "TheLongPalindrome.cpp"
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

#define sz(a)  int((a).size())
#define pb  push_back
#define all(c)  (c).begin(),(c).end()
#define tr(c,i)  for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); i++)

const long long H = 1234567891LL;

inline long long sub_(long long a, long long b) { return (a + H - (b % H)) % H; }
inline long long add_(long long a, long long b) { return (a + b) % H; }
inline long long mul_(long long a, long long b) { return ((a % H) * (b % H)) % H; }

long long fast_expt(long long r, long long n) { // r^n % H
  //printf("fast_expt(%lld ^ %lld mod %lld)...\n", r,n,m);
  if (n == 1) return r;
  if (n % 2 == 0)
	return fast_expt(mul_(r,r), n/2);
  else
	return mul_(fast_expt(r,n-1), r);
}

inline long long div_(long long a, long long b) { return mul_(a, fast_expt(b,H-2)); }

long long geo(int r, int n) {
  // 1,r,r^2,...,r^n
  if (r == 1) return n % H;

  return div_(fast_expt(r,n+1)-1, r-1);
}

// BEGIN CUT HERE
/*
long long geo(int r, int n) {
  // 1,r,r^2,...,r^n
  if (r == 1) return n % H;

  long long denom = r - 1;
  long long m = H * denom;
  long long numer = (fast_expt(r,n+1,m) + m - 1) % m;
  return (numer / denom) % H;//(1-r^n)/1-r = r^n-1/r-1
}
*/
// END CUT HERE

long long C(int n, int r)
{
  if (n == 0 || r == 0 || r == n) return 1;
  if (r > n-r) r = n-r;
  return C(n-1,r-1) * n / r;
}

long long fac_(int n) { // n ! - not used here
  long long p = 1LL;
  for (int k=n; k>1; k--) p = mul_(p, k);
  return p;
}

vector<long long> coeffs_(int k) {
  vector<long long> cs(k+1, 1LL); cs[0] = 0;
  
  for (int j=1; j<=k; j++) {
	long long t = 0;
	for (int i=0,pm=1; i<=k-j; i++,pm=-pm) {
	  t += C(26-j, i) * pm;
	}
	cs[j] = C(26, j) * t;
  }
  return cs;
}

class TheLongPalindrome {
  long long f_(int k, int len) {
	if (k == 1) return 1;
	if (k == len) return fac_(k);
	
	long long t = 0;
	for (int j=k,pm=1; j>=1; j--,pm=-pm) {
	  if (pm >= 0)
		t = add_(t, fast_expt(j,len) * C(k,j));
	  else
		t = sub_(t, fast_expt(j,len) * C(k,j));
	}
	return t;
  }

public:
  int count(int n, int k) {
	int h = (n + 1) / 2, m = n % 2;
	if (k > h) k = h;

	vector<long long> expts(k+1, 1LL); expts[0] = 0;
	vector<long long> coeffs = coeffs_(k);

	long long c = 0LL;
	for (int len=1; len<=k; len++) {
	  int k_ = len;
	  long long o = 0LL;
	  for (int j=1; j<=k_; j++)
		o = add_(o, mul_(C(26,j), f_(j,len))); // o += 26Cj x f(j,len)
	  c = (len == h && m == 1)? add_(c,o) : add_(c,o*2);
	}

	if (h > k) {
	  long long o = 0LL;
	  for (int r=1; r<=k; r++) {
		long long co = coeffs[r];

		if (co >= 0)
		  o = add_(o, mul_(co, sub_(geo(r,h-1), geo(r,k))));
		else
		  o = sub_(o, mul_(-co, sub_(geo(r,h-1), geo(r,k))));
	  }
	  c = add_(c, o*2);

	  o = 0LL;
	  for (int r=1; r<=k; r++) {
		long long co = coeffs[r];
		if (co >= 0)
		  o = add_(o, mul_(co, fast_expt(r,h)));
		else
		  o = sub_(o, mul_(-co, fast_expt(r,h)));
	  }
	  c = (m == 1) ? add_(c, o) : add_(c, o*2);
	}

	return (int)c;
  }
};

// BEGIN CUT HERE
#include <time.h>
clock_t start_time;
void timer_clear() { start_time = clock(); }
string timer() { clock_t end_time = clock(); double interval = (double)(end_time - start_time)/CLOCKS_PER_SEC; ostringstream os; os << " (" << interval*1000 << " msec)"; return os.str(); }

template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
int verify_case(const int &Expected, const int &Received) { if (Expected == Received) cerr << "PASSED" << timer() << endl; else { cerr << "FAILED" << timer() << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } return 0;}

template<int N> struct Case_ {};
char Test_(...);
int Test_(Case_<0>) {
	timer_clear();
	int n = 1; 
	int k = 1; 
	int RetVal = 26; 
	return verify_case(RetVal, TheLongPalindrome().count(n, k)); }
int Test_(Case_<1>) {
	timer_clear();
	int n = 2; 
	int k = 10; 
	int RetVal = 52; 
	return verify_case(RetVal, TheLongPalindrome().count(n, k)); }
int Test_(Case_<2>) {
	timer_clear();
	int n = 3; 
	int k = 2; 
	int RetVal = 728; 
	return verify_case(RetVal, TheLongPalindrome().count(n, k)); }
int Test_(Case_<3>) {
	timer_clear();
	int n = 44; 
	int k = 7; 
	int RetVal = 240249781; 
	return verify_case(RetVal, TheLongPalindrome().count(n, k)); }

template<int N> void Run_() { cerr << "Test Case #" << N << "..." << flush; Test_(Case_<N>()); Run_<sizeof(Test_(Case_<N+1>()))==1 ? -1 : N+1>(); }
template<>      void Run_<-1>() {}
int main() { Run_<0>(); }
// END CUT HERE

