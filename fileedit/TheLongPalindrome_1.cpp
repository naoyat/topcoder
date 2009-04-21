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
  long long ab = (long long)(a % H) * (b % H);
  return ab % H;
}
/*
//const long long H = LONG_LONG_MAX;
inline long long sub_(int a, int b) { return (long long)a - b; }
inline long long add_(int a, int b) { return (long long)a + b; }
inline long long mul_(int a, int b) { return (long long)a * b; }
*/

class TheLongPalindrome {
  long long c_(int n, int r)
  {
	if (n == 0 || r == 0 || r == n) return 1;
	if (r > n-r) r = n-r;
	return (c_(n-1,r-1) * n / r) % H;
  }
  long long expt_(int n, int k) { // n ^ k
	long long p = 1LL;
	for (int i=0; i<k; i++) p = mul_(p, n);
	//printf("# %d ^ %d = %lld\n", n, k, p);
	return p;
  }
  long long fac_(int n) { // n !
	long long p = 1LL;
	for (int k=n; k>1; k--) p = mul_(p, k);
	//printf("# %d ! = %lld\n", n, p);
	return p;
  }

  long long f_(int k, int len) {
	if (k == 1) return 1;
	if (k == len) return fac_(k);
	/*
	for (int i=k-1; i>=1; i--) {
	  t = add_(t, mul_(c_(k,i), f_(i,len)));
	}
	return sub_(expt_(k,len), t); // k^len - Σ[i:1..k-1] kCi x f(i,len)
	*/
	long long t = 0;
	for (int j=k,pm=1; j>=1; j--,pm=-pm) {
	  t = (t + pm * expt_(j,len) * c_(k,j)) % H;
	}
	return t;
  }
public:
  int count(int n, int k) {
// BEGIN CUT HERE
	// 字数: 1..n <= 1e9
	// 字種: 1..k <= 26
// END CUT HERE
	vector<int> expts(27,1);

	int h = (n + 1) / 2, m = n % 2;
	if (k > h) k = h;

	long long c = 0LL;
	for (int len=1; len<=h; len++) {
	  // i:何文字長？
	  int k_ = min(len,k); // 字種数
	  long long o = 0LL;
	  for (int j=1; j<=k_; j++)
		o = add_(o, mul_(c_(26,j), f_(j,len))); // o += 26Cj x f(j,len)
	  c = (len == h && m == 1)? add_(c,o) : add_(c,o*2);
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

