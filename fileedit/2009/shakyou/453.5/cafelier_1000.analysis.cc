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
//typedef long long LL;
typedef complex<double> CMP;

#include "cout.h"
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

template <typename T> void sort_(vector<T> v)
{
  sort(v.begin(), v.end());
}
template <typename T> void uniq_(vector<T> v)
{
  v.erase( unique(v.begin(), v.end()), v.end() );
}

// 最大公約数（swap使ってるー！）
template <typename T> T gcd(T x, T y)
{
  while (x) swap(x, y%=x);
  return y;
}
// 最小公倍数（普通ですね。順番に気をつけるところも）
template <typename T> T lcm(T x, T y)
{
  return x / gcd(x,y)*y;
}

class TheAlmostLuckyNumbers {
 public:
  void genLuck(vector<ll>& v)
  {
    // lucky numbers
    vector<ll> u;
    FOR(d,1,10) genLuck(d, u);

    // filtering
    rep(i,sz(u)) {
      rep(j,i) if( u[i] % u[j] == 0 ) goto next;
      v.pb( u[i] );
    next:;
    }
    sort_(v);
    // sort(v.begin(), v.end());
    // 1199 lucky numbers are left...
  }

  void genLuck(int d, vector<ll>& v)
  {
    // d-digit lucky numbers
    rep(b,1<<d) {
      ll n = 0;
      rep(i,d) n = n*10 + (b&(1<<i) ? 4 : 7);
      v.pb(n);
    }
  }
  // ここまでは一緒

  ll count(ll a, ll b)
  {
    vector<ll> v;
    genLuck(v); // 1199 items in it

    static const int M = 16;

    // inclusion-exclusion
    ll cnt = 0;
    {
      FOR(m,1,(1<<M)-1) { // 1..65535
        int pm = -1;
        ll n = 1;
        rep(i,M) // i as mask, 0..15, 1..32768
            if( m & (1<<i) ) pm*=-1, n=lcm(n, v[i]);
        cnt += pm*(b/n - (a-1)/n);
      }
    }

    // sieve
    vector<ll> aml;
    FOR(i,M,(sz(v) && v[i]<=b)-1) {
      ll u = v[i];
      for (ll s=a%u?(a/u+1)*u:a; s<=b; s+=u) {
        rep(k,M) if( s%v[k]==0 ) goto next;
        aml.pb(s);
      next:;
      }
      if( sz(aml) > 10000000 ) {
        //sort(all(aml));
        sort_(aml);
        uniq_(aml);
        //aml.erase(unique(all(aml)), aml.end());
      }
    }

    sort_(aml); uniq_(aml);
    // sort(all(aml));
    // aml.erase(unique(all(aml)), aml.end());

    ll result = cnt + sz(aml);
    printf("returns cnt:%lld + aml.size():%lld = %lld;\n", cnt,  (ll)sz(aml),  result);
    return result;
  }
};


/////////////////////
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

