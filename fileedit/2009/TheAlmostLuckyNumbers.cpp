#line 2 "TheAlmostLuckyNumbers.cpp"
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
#define tr(c,i)  for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); i++)
#define rep(var,n)  for(int var=0;var<(n);var++)
#define FOR(var,from,to) for(int var=(from);var<=(to);var++)
#define RFOR(var,from,to) for(int var=(to);var>=(from);var--)
#define found(s,e)  ((s).find(e)!=(s).end())
#define mset(arr,val)  memset(arr,val,sizeof(arr))
#define remove_(c,val) (c).erase(remove((c).begin(),(c).end(),(val)),(c).end())
#define lastc(str) (*((str).end()-1))

typedef pair<int,int> i_i;
typedef pair<ll,ll> ll_ll;
typedef pair<double,double> d_d;
typedef pair<int,pair<int,int> > i_ii;
#define cons(x,y) make_pair((x),(y))
#define car(x) ((x).first)
#define cdr(x) ((x).second)
#define cadr(x) (x).second.first
#define cddr(x) (x).second.second

ll gcd(ll m, ll n)
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
ll lcm(ll m, ll n)
{
  return m / gcd(m,n) * n;
}

class TheAlmostLuckyNumbers {
  vector<ll> lns; int lnsn;
  
  int keta(ll x){
    if(x<10) return 1;
    return 1+keta(x/10);
  }
  ll rp(int k,int mask){
    ll r=0, b=1LL;
    for(int i=0,m=1;i<k;i++,m<<=1){
      r += b * ((mask&m)? 7 : 4);
      b *= 10LL;
    }
    return r;
  }
  ll sub(ll x){
    if(x==0) return 0;

    int k=keta(x);

    ll cx=0;
    rep(i,lnsn){
      cx += x / lns[i];
    }
    printf("sub(%lld:%d) <= %lld\n", x,k, cx);

    return cx;
  }
 public:
  long long count(long long a, long long b) {
    lns.clear();
    for(int k=1;k<=10;k++){
      for(int m=0;m<1<<k;m++){
        ll r = rp(k,m); if (r>b) break;
        int skip=0;
        rep(i,sz(lns)) if (r%lns[i]==0) skip=1;
        if(!skip) lns.pb(r);
      }
    }
    lnsn = sz(lns);
    cout << lnsn << " " << lns << endl;
    ll x=1LL; int f=lnsn;
    rep(i,lnsn){
      x *= lns[i]; if(x>b){ f=i; break; }
    }
    // 5 out of 1199: 1199C5 = 20478021302739 ... orz
    printf("s1.size = %d\n", lnsn);
    
    set<ll> s2, s3;
    int c2=0, c3=0;
    FOR(i,0,lnsn-2){
      FOR(j,i+1,lnsn-1){
        ll ij = lcm(lns[i],lns[j]);
        if (ij<=b) {
          //if (found(s2,ij)) printf("DUP: %lld (LCM %lld %lld)\n", ij, lns[i],lns[j]);
          // s2.insert(ij);
          c2++;
          if (j<lnsn-1)
            FOR(k,j+1,lnsn-1) {
              ll ijk = lcm(ij,lns[k]);
              if (ijk<=b) {
                // s3.insert(ijk);
                c3++;
              } else break;
            }
        } else break;
      }
    }
    printf("s2.size = %d, k = %d\n", sz(s2), c2);
    printf("s2.size = %d, k = %d\n", sz(s3), c3);

    printf("count(a:%lld, b:%lld)...f=%d\n",a,b, f);
	return sub(b) - sub(a-1);
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
	long long RetVal = 1178LL; 
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
// END CUT HERE
