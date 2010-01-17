#line 2 "FunctionalEquation.cpp"
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

class FunctionalEquation {
 public:
  long long minAbsSum(int C, int N,
                      int xzero, int xprod, int xadd, int xmod,
                      int yzero, int yprod, int yadd, int ymod) {
    ll xz = xzero, xp = xprod, xa = xadd, xm = xmod;
    ll yz = yzero, yp = yprod, ya = yadd, ym = ymod;
	vector<ll> x(N), y(N);
    x[0] = xz, y[0] = yz;

    FOR(i,1,N-1) {
      x[i] = (x[i-1] * xp + xa) % xm;
      y[i] = (y[i-1] * yp + ya) % ym;
    }
      /*
      printf("f(2f(%lld) - %lld) = f(%lld) + %d\n", x[i], x[i]-1, x[i], C);
      printf("g(g(x:%lld) - %lld) = (g(x:%lld) - %lld) + (x:%lld + %d)\n",
             x[i], x[i]-1,
             x[i], x[i]-1,
             x[i], C*2-1);
      //      printf("u(x)=2f(x)-x-1; f(u(x))=f(x)+C;...\n");
      // f(x) = (u(x)+x+1)/2
      //printf("|f(%lld) - %lld| = |u(%lld)+%lld|/2\n", x[i] + y[i], x[i], x[i]+1-y[i]*2);
      */
    double sum = 0, k = 0.5*(C - 1);
    rep(i,N) sum += fabs(k + x[i] - y[i]);

    /*
    cout << "x[] : " << x << endl;
    cout << "y[] : " << y << endl;
    */
    printf("sum = %g\n", sum);
    return (long long)ceil(sum);
    // min of sigma |f(x[]) - y[]|
    // f(2f(x) - x + 1) = f(x) + C
    // f(2f(x) - x + 1) - f(x) = C
    /*
    g = f(x), f(2g - x + 1) - g = C
f(x)=0  f(-x+1)=C
f(x)=k, f(2k-x+1)=k+C

2f(2f(x) - x + 1) = 2f(x) + 2C
g(x)=2f(x)
g(g(x)-(x-1)) = g(x)+2C
    */
    //    return 0LL;
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
	int C = 3; 
	int N = 10; 
	int xzero = 0; 
	int xprod = 1; 
	int xadd = 1; 
	int xmod = 456; 
	int yzero = 1; 
	int yprod = 1; 
	int yadd = 1; 
	int ymod = 456; 
	long long RetVal = 0LL; 
	return verify_case(RetVal, FunctionalEquation().minAbsSum(C, N, xzero, xprod, xadd, xmod, yzero, yprod, yadd, ymod)); }
int Test_(Case_<1>) {
	timer_clear();
	int C = 4; 
	int N = 10; 
	int xzero = 0; 
	int xprod = 1; 
	int xadd = 1; 
	int xmod = 456; 
	int yzero = 1; 
	int yprod = 1; 
	int yadd = 1; 
	int ymod = 456; 
	long long RetVal = 5LL; 
	return verify_case(RetVal, FunctionalEquation().minAbsSum(C, N, xzero, xprod, xadd, xmod, yzero, yprod, yadd, ymod)); }
int Test_(Case_<2>) {
	timer_clear();
	int C = 16; 
	int N = 10000; 
	int xzero = 654816386; 
	int xprod = 163457813; 
	int xadd = 165911619; 
	int xmod = 987654321; 
	int yzero = 817645381; 
	int yprod = 871564816; 
	int yadd = 614735118; 
	int ymod = 876543210; 
	long long RetVal = 3150803357206LL; 
	return verify_case(RetVal, FunctionalEquation().minAbsSum(C, N, xzero, xprod, xadd, xmod, yzero, yprod, yadd, ymod)); }

template<int N> void Run_() { cerr << "Test Case #" << N << "..." << flush; Test_(Case_<N>()); Run_<sizeof(Test_(Case_<N+1>()))==1 ? -1 : N+1>(); }
template<>      void Run_<-1>() {}
int main() { Run_<0>(); }
// END CUT HERE


// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// f is a function from integers to integers. In other words, f is defined over integers, and f(x) is an integer for all integers x. You are given an integer C. f is called C-beautiful if the following equality is satisfied for all integers x:





Return the minimal possible value of the following formula when f is C-beautiful:





Use the following recursive definitions to generate the sequences x and y:

x[0] = xzero
For all integer i between 1 and N-1, inclusive, x[i] = (x[i-1] * xprod + xadd) % xmod
y[0] = yzero
For all integer i between 1 and N-1, inclusive, y[i] = (y[i-1] * yprod + yadd) % ymod


DEFINITION
Class:FunctionalEquation
Method:minAbsSum
Parameters:int, int, int, int, int, int, int, int, int, int
Returns:long long
Method signature:long long minAbsSum(int C, int N, int xzero, int xprod, int xadd, int xmod, int yzero, int yprod, int yadd, int ymod)


NOTES
-64-bit integers should be used to generate the sequences x and y to avoid overflow.


CONSTRAINTS
-C will be between 1 and 16, inclusive.
-N will be between 1 and 10,000, inclusive.
-xmod and ymod will each be between 1 and 1,000,000,000, inclusive.
-xzero, xprod and xadd will each be between 0 and xmod - 1, inclusive.
-yzero, yprod and yadd will each be between 0 and ymod - 1, inclusive.


EXAMPLES

0)
3
10
0
1
1
456
1
1
1
456

Returns: 0

f(x) = x + 1 is a 3-beautiful function.

Since x = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9} and y = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10},
the sum of |f(x[i]) - y[i]| is 0.

1)
4
10
0
1
1
456
1
1
1
456

Returns: 5

x and y are the same as in example 0, but f(x) = x + 1 is not a 4-beautiful function.

2)
16
10000
654816386
163457813
165911619
987654321
817645381
871564816
614735118
876543210

Returns: 3150803357206



*/
// END CUT HERE
