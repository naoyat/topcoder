#line 2 "SquareFreeNumbers.cpp"
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
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<string> vs;
typedef vector<long long> vll;
#define sz(a)  int((a).size())
#define pb  push_back
#define all(c)  (c).begin(),(c).end()
#define mset(arr,val)  memset(arr,val,sizeof(arr))
#define tr(c,i)  for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); i++)
#define rep(var,n)  for(int var=0;var<(n);var++)
#define forr(var,from,to) for(int var=(from);var<=(to);var++) 
#define found(s,e)  ((s).find(e)!=(s).end())
#define remove_(c,val) (c).erase(remove((c).begin(),(c).end(),(val)),(c).end())
#define lastc(str) (*((str).end()-1))

#define M 78498
ll px[M];
int d[M],px_c;

////
long long random(long long n)
{
  return (long long)rand() % n;
}
long long check_nontrivial_sqrt_1(long long m, long long a)
{
  long long r = (a * a) % m;
  return (1LL < a && a < m-1 && r == 1)? 0LL : r;
}
long long expmod(long long base, long long exp, long long m)
{
  if (exp == 0)
        return 1LL;
  else if (!(exp & 1))
        return check_nontrivial_sqrt_1(m,expmod(base,exp/2,m));
  else
        return (base*expmod(base,exp-1,m)) % m;
}
bool miller_rabin_test(long long n)
{
  return expmod((1LL+random(n-1)),n-1,n) == 1LL;
}
bool fast_prime(long long n, int times)
{
  if (n == 1) return false;
  if (n == 2) return true;
  else if (!(n & 1)) return false;

  for (int i=times; i>0; i--)
        if (!miller_rabin_test(n)) return false;
  return true;
}
////
int e_sieve(int till)
{
  vector<bool> sieve(till+1,true);
  px_c = 0;

  // +2
  sieve[2] = true;
  px[px_c++] = 2;

  for (int prime=3;;) {
    px[px_c++] = prime;
    for (int i=prime*3;i<=till;i+=(prime*2)) sieve[i] = false;

    int next_prime = -1;
    for (int j=prime+2; j<=till; j+=2) {
      if (sieve[j]) { next_prime = j; break; }
    }

    if (next_prime == -1) break;
    prime = next_prime;
  }

  return px_c;
}
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

ll bt(ll n) {
  ll c=1;
  ll x=n*rand(),y=x;
  x = (x*x + c)% n;
  ll ub=2+sqrt(n);
  ll nx=2;
  ll i=1;
  while (++i <= ub){
    ll g=gcd(y-x,n); if(g<0) g=-g;
    if(g==n) break;
    else if(g!=1){
      while(n%g == 0) n/=g;
      ub = 2+sqrt(n);
    }
    if(i==nx){
      y=x;
      nx*=2;
    }
    i++;
    x = (x*x + c)%n;
  }
  return n;
}

class SquareFreeNumbers {
  bool pf(ll x){
    //memset(d,0,sizeof(d));
    ll xs=sqrt(x);
    rep(i,px_c){
      d[i]=-2;
      ll p=px[i];
      //if(p>x) break;
      if(p>xs) break;
      while(x%p==0) { if(!++d[i]) return false; x/=p; }
      if(x==1) break;
    }
    return true;
  }
 public:
  int getCount(long long min, long long max) {
    e_sieve(1000001);
    int cnt=0;
    for(ll n=min; n<=max; n++){
      if((n&3)==0) continue;
      /*
      if(n%9==0) continue;
      if(fast_prime(n,2) || pf(n)) cnt++;
      */
      //printf("%lld, bt=%lld\n", n, bt(n));
      if(pf(n)) cnt++;
    }
    return cnt;
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
	long long min = 1LL; 
	long long max = 10LL; 
	int RetVal = 7; 
	return verify_case(RetVal, SquareFreeNumbers().getCount(min, max)); }
int Test_(Case_<1>) {
	timer_clear();
	long long min = 15LL; 
	long long max = 15LL; 
	int RetVal = 1; 
	return verify_case(RetVal, SquareFreeNumbers().getCount(min, max)); }
int Test_(Case_<2>) {
	timer_clear();
	long long min = 1LL; 
	long long max = 1000LL; 
	int RetVal = 608; 
	return verify_case(RetVal, SquareFreeNumbers().getCount(min, max)); }

int Test_(Case_<5>) {
	timer_clear();
	long long min = 1000000000000LL;
	long long max = min + 1000000LL;
	int RetVal = 0; 
	return verify_case(RetVal, SquareFreeNumbers().getCount(min, max)); }
int Test_(Case_<4>) {
	timer_clear();
	long long min = 1LL;
	long long max = 1LL;
	int RetVal = 1; 
	return verify_case(RetVal, SquareFreeNumbers().getCount(min, max)); }
int Test_(Case_<3>) {
	timer_clear();
	long long min = 4LL;
	long long max = 4LL;
	int RetVal = 0; 
	return verify_case(RetVal, SquareFreeNumbers().getCount(min, max)); }

template<int N> void Run_() { cerr << "Test Case #" << N << "..." << flush; Test_(Case_<N>()); Run_<sizeof(Test_(Case_<N+1>()))==1 ? -1 : N+1>(); }
template<>      void Run_<-1>() {}
int main() { Run_<0>(); }
// END CUT HERE


// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// A number is called square-free if it is not divisible by a perfect square which is greater than one.  A perfect square is the square of an integer.  Return the number of square-free numbers between min and max, inclusive.

DEFINITION
Class:SquareFreeNumbers
Method:getCount
Parameters:long long, long long
Returns:int
Method signature:int getCount(long long min, long long max)


CONSTRAINTS
-min will be between 1 and 1,000,000,000,000, inclusive.
-max will be between min and (min + 1,000,000), inclusive.


EXAMPLES

0)
1
10

Returns: 7

Numbers 4, 8 and 9 are not square-free.

1)
15
15

Returns: 1

min and max can be equal.

2)
1
1000

Returns: 608



*/
// END CUT HERE
