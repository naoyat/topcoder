#line 2 "NumbersAndMatches.cpp"
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
class NumbersAndMatches {
  vector<int> d;
  map<int,ll> mm;
  int kt;
  vector<vector<i_i> > tm;
  inline int set3(int i,int h,int r){
    return (i<<16) | ((h+128)<<8) | r;
  }
  i_i mv(int x, int y){
    // __builtin_popcount(ma[i] ^ ma[j])
    int w = x & y, c_w = __builtin_popcount(w);
    int x_ = x - w, c_x_ = __builtin_popcount(x_);
    int y_ = y - w, c_y_ = __builtin_popcount(y_);
    int in_mov = min(c_x_, c_y_);
    int out_mov = (c_y_ - in_mov) - (c_x_ - in_mov);
    return cons(out_mov, abs(out_mov)+in_mov);
  }
  
  ll sub(int ix,int ha,int rk){
    ll sum=0LL; int cap, ky;
    if (ix==kt) {
      sum = (rk >= 0 && ha == 0)? 1 : 0;
      goto out;
    }
    if (rk<0) goto out;
    if (abs(ha)>rk) goto out;
    ky=set3(ix,ha,rk);
    //    printf("%d,%d,%d = %d\n", ix,ha,rk, ky);
    if (found(mm,ky)) return mm[ky];
    cap = d[ix];
    rep(j,10){
      i_i p = tm[cap][j];
      if (rk < p.second) continue;
      ll sb = sub(ix+1, ha-p.first, rk-p.second);
          /*
      printf("  sum += <%d->%d:(%d,%d)>sub(%d,%d->%d,%d->%d):%lld\n",
             cap,j,p.first,p.second,
             ix+1,
             ha, ha-p.first,
             rk, rk-p.second,
             sb);
          */
      sum += sb;
    }
 out:
    mm[ky]=sum;
    char buf[kt+1-ix]; for(int i=ix;i<kt;i++) buf[i-ix]='0'+d[i]; buf[kt-ix]=0;
    printf("sub(%d=\"%s\",%d,%d) => %lld\n", ix,buf, ha,rk, sum);
    return sum;
  }
 public:
  long long differentNumbers(long long N, int K) {
    d.clear(); mm.clear();
    
    for(ll x=N; x>0LL; x/=10LL){
      int r = (int)(x % 10LL);
      d.pb(r);
    }
    reverse(all(d));
    kt=sz(d);
    cout << N << " " << d << " " << kt << endl;

    int nm[10] = { 6,3,5,5,4,5,6,3,7,6 };
    int ma[10] = { 0x77, //{ 1,1,1,0,1,1,1 },// 111 0111
                   0x13, //{ 0,0,1,0,0,1,1 },// 001 0011
                   0x5d, //{ 1,0,1,1,1,0,1 },// 101 1101
                   0x5b, //{ 1,0,1,1,0,1,1 },// 101 1011
                   0x3a, //{ 0,1,1,1,0,1,0 },// 011 1010
                   0x6b, //{ 1,1,0,1,0,1,1 },// 110 1011
                   0x6f, //{ 1,1,0,1,1,1,1 },// 110 1111
                   0x72, //{ 1,1,1,0,0,1,0 },// 111 0010
                   0x7f, //{ 1,1,1,1,1,1,1 },// 111 1111
                   0x7b //{ 1,1,1,1,0,1,1 } // 111 1011
    };
    tm.resize(10);
    rep(i,10) {
      tm[i].resize(10);;
      rep(j,10) {
        tm[i][j] = mv(ma[i],ma[j]);
        //make_pair( __builtin_popcount(ma[j]) - __builtin_popcount(ma[i]), // i->j
            //                      mv(ma[i],ma[j]) );
      }
    }

    set<ll> nums;
    set<pair<ll,pair<int,int> > > visited;
    queue<pair<ll,pair<int,int> > > q;
    q.push(cons(N,cons(0,0)));
    ll cnt=0;
    while(!q.empty()){
      pair<ll,pair<int,int> > p = q.front(); q.pop();
      if(found(visited,p)) continue;
      visited.insert(p);
      if(found(nums,p.first)) continue;
      if (p.second.first == 0) {
        printf("%lld: %d,%d\n", p.first, p.second.first, p.second.second);
        nums.insert(p.first);
      }
      cnt++;
      for(ll a=p.first,m=1;a>=m;m*=10){
        int di=(int)((a/m)%10LL);
        ll a_ = a - m*di;
        rep(i,10){if (di==i)continue;
          i_i u = tm[di][i];
          ll a_i = a_ + m*i;
          int ca=cadr(p)+car(u);
          int cd=cddr(p)+cdr(u);
          printf(" %d) %lld -> %lld (%d,%d)+(%d,%d)\n", i,a,a_i,
                 cadr(p),cddr(p), car(u),cdr(u));
          if(cd>K)continue;
          if(abs(ca)>(K-cd))continue;
          q.push(cons(a_i,cons(ca,cd)));
        }
      }
    }
    cout << sz(nums) << " " << cnt << endl;
    return cnt;
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
	long long N = 10LL; 
	int K = 1; 
	long long RetVal = 4LL; 
	return verify_case(RetVal, NumbersAndMatches().differentNumbers(N, K)); }
int Test_(Case_<1>) {
	timer_clear();
	long long N = 23LL; 
	int K = 1; 
	long long RetVal = 4LL; 
	return verify_case(RetVal, NumbersAndMatches().differentNumbers(N, K)); }
int Test_(Case_<2>) {
	timer_clear();
	long long N = 66LL; 
	int K = 2; 
	long long RetVal = 15LL; 
	return verify_case(RetVal, NumbersAndMatches().differentNumbers(N, K)); }
int Test_(Case_<3>) {
	timer_clear();
	long long N = 888888888LL; 
	int K = 100; 
	long long RetVal = 1LL; 
	return verify_case(RetVal, NumbersAndMatches().differentNumbers(N, K)); }
int Test_(Case_<4>) {
	timer_clear();
	long long N = 444444444444444444LL; 
	int K = 2; 
	long long RetVal = 1LL; 
	return verify_case(RetVal, NumbersAndMatches().differentNumbers(N, K)); }

template<int N> void Run_() { cerr << "Test Case #" << N << "..." << flush; Test_(Case_<N>()); Run_<sizeof(Test_(Case_<N+1>()))==1 ? -1 : N+1>(); }
template<>      void Run_<-1>() {}
int main() { Run_<0>(); }
// END CUT HERE


// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// You have a piece of paper with exactly D positions laid out in a horizontal row.  Each position looks like the following:


 _
|_|
|_|



There are 7 line segments in each position, and each line segment can hold exactly one match.  Matches cannot be placed anywhere except on the line segments.

You are given an integer N containing exactly D digits (with no leading zeroes).  Spell out the number using matches on the paper.  Each digit must occupy a single position.  The following diagram shows how each digit should be formed:


      _	               _        _                 _       _        _        _        _
 0 - | |  1 -  |  2 -  _|  3 -  _|  4 - |_|  5 - |_  6 - |_   7 -   |  8 - |_|  9 - |_|
     |_|      _|      |_        _|        |       _|     |_|        |      |_|       _|



After you lay out the initial arrangement, you are allowed to move up to K matches.  You cannot discard matches or add new matches.  After you make all your moves, the final arrangement must be valid (as described above) and the integer formed by the arrangement must contain the same number of digits as the original integer.  Leading zeroes are allowed.  Return the number of distinct integers that can be formed in this manner.  Note that the original integer counts toward the total because it always obtainable by making 0 moves.

DEFINITION
Class:NumbersAndMatches
Method:differentNumbers
Parameters:long long, int
Returns:long long
Method signature:long long differentNumbers(long long N, int K)


CONSTRAINTS
-N will be between 1 and 10^18 - 1, inclusive. 
-K will be between 1 and 126, inclusive.


EXAMPLES

0)
10
1

Returns: 4

Here you can compose numbers 10, 19, 16 and 70:

      _                     _
  |  | |     ----->     |  | |
 _|  |_|               _|  |_|
      _                     _
  |  | |     ----->     |  |_|
 _|  |_|               _|   _|
      _                     _
  |  | |     ----->     |  |_ 
 _|  |_|               _|  |_|
      _                _    _
  |  | |     ----->     |  | |
 _|  |_|                |  |_|


1)
23
1

Returns: 4

This time it's possible to compose 22, 23, 32 and 33.

2)
66
2

Returns: 15

Here you can move up to 2 matches, so quite a lot of numbers can be composed. Note that you are allowed to move a match from one digit to another one, so, for example, it's possible to compose 38. However, you can't discard a match or add a new match, so, for example, you can't compose 55 or 88.

3)
888888888
100

Returns: 1

You are allowed to move a lot of matches, but still it's only possible to compose 888888888.

4)
444444444444444444
2

Returns: 1

Given that at most 2 matches can be moved, only the initial number can be composed.

*/
// END CUT HERE
