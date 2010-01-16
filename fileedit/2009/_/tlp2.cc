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
inline long long mul_(long long a, long long b) {
  long long ab = (a % H) * (b % H);
  return ab % H;
}
inline long long mulm_(long long a, long long b, long long m=H) {
  a %= m;
  long long bh = b >> 16, bl = b & 0x0000ffffLL;
  return ((((a * bh) % m) << 16) + a * bl) % m;
}

long long fast_expt(long long r, long long n, long long m=H) { // r^n % m
  //printf("fast_expt(%lld ^ %lld mod %lld)...\n", r,n,m);
  if (n == 1) return r;
  // r = 65536a | b とすると、r^2 = r(65536a + b) = 65536ar + rb
  // r^2 % m = (65536ar % m) + rb % m = (ar % m) * 65536 + rb
  if (n % 2 == 0)
	return fast_expt(mulm_(r,r,m), n/2, m);
  else
	return mulm_(fast_expt(r,n-1,m), r, m);
}

inline long long div_(long long a, long long b) { // a/b
  return mul_(a, fast_expt(b,H-2));
}

long long geo(int r, int n) {
  // 1,r,r^2,...,r^n
  if (r == 1) return n % H;

  return div_(fast_expt(r,n+1)-1, r-1);
  /*
  long long denom = r - 1;
  long long m = H * denom;
  long long numer = (fast_expt(r,n+1,m) + m - 1) % m;
  return (numer / denom) % H;//(1-r^n)/1-r = r^n-1/r-1
  */
}

/*
//const long long H = LONG_LONG_MAX;
inline long long sub_(int a, int b) { return (long long)a - b; }
inline long long add_(int a, int b) { return (long long)a + b; }
inline long long mul_(int a, int b) { return (long long)a * b; }
*/

class TheLongPalindrome {
  long long C(int n, int r)
  {
	if (n == 0 || r == 0 || r == n) return 1;
	if (r > n-r) r = n-r;
	return C(n-1,r-1) * n / r;
  }

  long long c_(int n, int r) // not used here
  {
	if (n == 0 || r == 0 || r == n) return 1;
	if (r > n-r) r = n-r;
	return (c_(n-1,r-1) * n / r) % H;
  }
  /**
  long long expt_(int n, int k) { // n ^ k
	long long p = 1LL;
	for (int i=0; i<k; i++) p = mul_(p, n);
	//printf("# %d ^ %d = %lld\n", n, k, p);
	return p;
  }
  **/

  long long fac_(int n) { // n ! - not used here
	long long p = 1LL;
	for (int k=n; k>1; k--) p = mul_(p, k);
	//printf("# %d ! = %lld\n", n, p);
	return p;
  }

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

  vector<long long> coeffs_(int k) {
	vector<long long> cs(k+1, 1LL); cs[0] = 0;

	for (int j=1; j<=k; j++) {
	  // cout << "coeff #" << j << ": ";
	  //int w = 26 - j;
	  long long t = 0;
	  for (int i=0,pm=1; i<=k-j; i++,pm=-pm) {
		t += C(26-j, i) * pm;
	  }
	  cs[j] = C(26, j) * t;
	}
	//cout << "coeffs[k=" << k << "] = " << cs << endl;
	return cs;
  }

public:
  int count(int n, int k) {
// BEGIN CUT HERE
	// 字数: 1..n <= 1e9
	// 字種: 1..k <= 26
	  /*
	{
	  for (int i=1; i<=100; i++) {
		int e1 = expt_(26,i);
		int e2 = fast_expt(26,i,H);
		printf("<fast_expt> 26^%d mod H = { %d, %d } %s\n", i, e1, e2, (e1==e2)? "ok" : "NG");
	  }

	  long long e1 = 1;
	  for (int i=1; i<=100; i++) {
		e1 = (e1 * 26) % (H * 25);
		//int e1 = expt_(26,i);
		long long e2 = fast_expt(26,i,H*25);
		printf("<fast_expt'> 26^%d mod 25H = { %lld, %lld } %s\n", i, e1, e2, (e1==e2)? "ok" : "NG");
	  }

	  long long p = 1;
	  int s1 = 1;
	  for (int i=1; i<=10000; i++) {
		p = mul_(p, 26); s1 = add_(p, s1);
		int s2 = geo(26,i);
		printf("1 + 26 + ... + 26^%d = { %d, %d } %s ; p=%lld\n", i, s1, s2, (s1==s2)? "ok" : "NG", p);
	  }
	}
	*/
// END CUT HERE

	int h = (n + 1) / 2, m = n % 2;
	if (k > h) k = h;

	vector<long long> expts(k+1, 1LL); expts[0] = 0;
	vector<long long> coeffs = coeffs_(k);
	cout << "coeffs: " << coeffs << endl;

	long long c = 0LL;
	for (int len=1; len<=k; len++) {
	  int k_ = len;
	  long long o = 0LL;
	  for (int j=1; j<=k_; j++)
		o = add_(o, mulm_(C(26,j), f_(j,len))); // o += 26Cj x f(j,len)
	  c = (len == h && m == 1)? add_(c,o) : add_(c,o*2);
	}

	if (h > k) {
	  long long o = 0LL;
	  for (int r=1; r<=k; r++) {
		long long co = coeffs[r];
		printf("(h:%d > k:%d) r:%d, o += %lld x (%lld - %lld)\n",
			   h,k,r,
			   co, geo(r,h-1), geo(r,k)
			   );
		if (co >= 0)
		  o = add_(o, mulm_(co, sub_(geo(r,h-1), geo(r,k))));
		else
		  o = sub_(o, mulm_(-co, sub_(geo(r,h-1), geo(r,k))));
	  }
	  c = add_(c, o*2);
	  //printf("c += 2o <%lld> = %lld\n", o*2, c);
	  /* printf("geo(r,h-1) = %lld, fast_expt(r,h) = %lld, geo(r,h) = %lld\n",
		 geo(26,h-1), fast_expt(26,h), geo(26,h) ); */

	  if (m == 1) {
		long long o = 0LL;
		for (int r=1; r<=k; r++) {
		  long long co = coeffs[r];
		  if (co >= 0)
			o = add_(o, mulm_(co, fast_expt(r,h)));
		  else
			o = sub_(o, mulm_(-co, fast_expt(r,h)));
		}
		c = add_(c, o);
	  }
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
int Test_(Case_<4>) {
	timer_clear();
	int n = 1000000000;
	int k = 1;
	int RetVal = 0;
	return verify_case(RetVal, TheLongPalindrome().count(n, k)); }
int Test_(Case_<5>) {
	timer_clear();
	int n = 1000000000;
	int k = 10;
	int RetVal = 0;
	return verify_case(RetVal, TheLongPalindrome().count(n, k)); }
int Test_(Case_<6>) {
	timer_clear();
	int n = 1000000000;
	int k = 26;
	int RetVal = 0;
	return verify_case(RetVal, TheLongPalindrome().count(n, k)); }

template<int N> void Run_() { cerr << "Test Case #" << N << "..." << flush; Test_(Case_<N>()); Run_<sizeof(Test_(Case_<N+1>()))==1 ? -1 : N+1>(); }
template<>      void Run_<-1>() {}

int main(int argc, char *argv[])
{
  int n = (argc == 2)? atoi(argv[1]) : -1;
  if (n >= 0) {
	cerr << "Test Case #" << n << "..." << flush;
	switch (n) {
	case 0:	Test_(Case_<0>()); break;
	case 1:	Test_(Case_<1>()); break;
	case 2:	Test_(Case_<2>()); break;
	case 3:	Test_(Case_<3>()); break;
	case 4:	Test_(Case_<4>()); break;
	case 5:	Test_(Case_<5>()); break;
	case 6:	Test_(Case_<6>()); break;
	default: Run_<0>(); break;
	}
  } else {
	Run_<0>();
  }
}
// END CUT HERE

