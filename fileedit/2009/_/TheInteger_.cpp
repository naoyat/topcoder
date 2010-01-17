#line 2 "TheInteger.cpp"
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

long long minnum[11] = { 0,
                         0LL, 10LL, 102LL, 1023LL, 10234LL, 102345LL, 1023456LL, 10234567LL, 102345678LL, 1023456789LL };
long long minnum1[11] = { 0,
                         10LL, 100LL, 1002LL, 10023LL, 100234LL, 1002345LL, 10023456LL, 100234567LL, 1002345678LL, 10023456789LL };
long long maxnum[11] = { 0,
                         9LL, 98LL, 987LL, 9876LL, 98765LL, 987654LL, 9876543LL, 98765432LL, 987654321LL, 9876543210LL };

int revds[10] = { 9,8,7,6,5,4,3,2,1,0 };

class TheInteger {
  vi num2vec(ll n){
    vi v;
    int d=0;
    ll x=n;
    while(x){d++; v.pb(x%10LL); x/=10LL;}
    reverse(all(v));
    return v;
  }
  ll vec2num(vi v){
    ll x=0LL;
    tr(v,it){x*=10LL; x+=(ll)(*it);}
    return x;
  }
  ll maxwith(int kt,int k){
    vi v(kt,9);
    rep(i,k-1) v[kt-1-i]=(10-k)+i;
    cout << "maxwith " << v<<endl;
    ll n= vec2num(v);
    if (n<0 && kt==19) return LONG_LONG_MAX;
    return n;
  }
  ll minwith(int kt,int k){
    if (kt<k) return minnum[k];
    vi v(kt,0); v[0]=1;
    rep(i,k-2) v[kt-1-i]=(k-1)-i;
    cout << "minwith " << v<<endl;
    return vec2num(v);
  }
 public:
  long long find(long long n, int k) {
    vi nv = num2vec(n); int kt=sz(nv);
    cout << "n  : " << n << endl;
    //    cout << "max: " << maxwith(kt,k) << endl;
    //    cout << "min: " << minwith(kt,k) << endl;
    if(n < minnum[k]) return minnum[k];
    if (n>maxwith(kt,k)) return minwith(kt+1,k);
        //    if(kt == k && n > maxnum[k]) return minnum1[k];
// BEGIN CUT HERE
    //    cout << "n:"<<n << "=>" <<nv <<endl;
// END CUT HERE
    vi cn(10,0); tr(nv,it) cn[*it]=1;
    int tot=0; rep(i,10) tot+=cn[i];
// BEGIN CUT HERE
    //    cout << "cn:" << cn<< ", "<<tot<<endl;
// END CUT HERE
    printf("keta=%d, k=%d, used=%d; cn:",kt, k,tot); cout << cn << endl;
    if(k==tot) return n;
    if(k<tot){ //塗れ
      if(k==1) {
        int nvk=kt; ll iii=1;rep(i,nvk)iii*=10LL; iii=(iii-1)/9;
        for(int d=nv[0];d<=9;d++) if (iii*d >= n) return iii*d;
      }else{ //k色だけ使っていい;
        int a=nv[0];
        printf("USE LESS: K#0 = %d or %d\n",a,a+1);
        for(int i=1;i<kt;i++){
          
        }
            
      }
    }else{ //k>tot もっと使え
      printf("USE MORE: K#0 = %d or %d\n", nv[0], nv[0]+1);
    }

    return n;//-k;
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
	long long n = 47LL; 
	int k = 1; 
	long long RetVal = 55LL; 
	return verify_case(RetVal, TheInteger().find(n, k)); }
int Test_(Case_<1>) {
	timer_clear();
	long long n = 7LL; 
	int k = 3; 
	long long RetVal = 102LL; 
	return verify_case(RetVal, TheInteger().find(n, k)); }
int Test_(Case_<2>) {
	timer_clear();
	long long n = 69LL; 
	int k = 2; 
	long long RetVal = 69LL; 
	return verify_case(RetVal, TheInteger().find(n, k)); }
int Test_(Case_<3>) {
	timer_clear();
	long long n = 12364LL; 
	int k = 3; 
	long long RetVal = 12411LL; 
	return verify_case(RetVal, TheInteger().find(n, k)); }

int Test_(Case_<4>) {
	timer_clear();
	long long n = 33LL; 
	int k = 2; 
	long long RetVal = 34LL; 
	return verify_case(RetVal, TheInteger().find(n, k)); }
int Test_(Case_<5>) {
	timer_clear();
	long long n = 1000000000000000000LL;
	int k = 10; 
	long long RetVal = 1000000000023456789LL;
	return verify_case(RetVal, TheInteger().find(n, k)); }
int Test_(Case_<6>) {
	timer_clear();
	long long n = 1LL; 
	int k = 1; 
	long long RetVal = 1LL;
	return verify_case(RetVal, TheInteger().find(n, k)); }
int Test_(Case_<7>) {
	timer_clear();
	long long n = 99LL; 
	int k = 2; 
	long long RetVal = 100LL;
	return verify_case(RetVal, TheInteger().find(n, k)); }
int Test_(Case_<8>) {
	timer_clear();
	long long n = 309LL; 
	int k = 2; 
	long long RetVal = 311LL;
	return verify_case(RetVal, TheInteger().find(n, k)); }
int Test_(Case_<9>) {
	timer_clear();
	long long n = 19999LL; 
	int k = 5; 
	long long RetVal = 20134LL;
	return verify_case(RetVal, TheInteger().find(n, k)); }

template<int N> void Run_() { cerr << "Test Case #" << N << "..." << flush; Test_(Case_<N>()); Run_<sizeof(Test_(Case_<N+1>()))==1 ? -1 : N+1>(); }
template<>      void Run_<-1>() {}
int main() { Run_<0>(); }
// END CUT HERE


// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
There is nothing more beautiful than just an integer number.



You are given an integer n.  Return the smallest integer greater than or equal to n that contains exactly k distinct digits in decimal notation.



DEFINITION
Class:TheInteger
Method:find
Parameters:long long, int
Returns:long long
Method signature:long long find(long long n, int k)


CONSTRAINTS
-n will be between 1 and 10^18, inclusive.
-k will be between 1 and 10, inclusive.


EXAMPLES

0)
47
1

Returns: 55

Here, k is 1, so we're looking for a number whose digits are all equal.  The smallest such number that is greater than or equal to 47 is 55.

1)
7
3

Returns: 102

We need three distinct digits here.

2)
69
2

Returns: 69

69 already consists of two different digits.

3)
12364
3

Returns: 12411

*/
// END CUT HERE
