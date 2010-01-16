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
/*
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
*/
typedef long long ll;

bool c[1000005];
bool u[...1000005]; // u[i] = U[(mn+)i]

class SquareFreeNumbers {
 public:
  int getCount(long long mn, long long mx) {
    memset(c,0,sizeof(c));
    memset(u,0,sizeof(u));
    
    for (int j=2; j<1000005; j++)
      if (!c[j]) {
        for (int k=j; k<1000005; k+=j) c[k] = true;
        ll jl = j; jl *= jl;
        ll st = mn / jl * jl; if (st < mn) st += jl;
        for (ll i = st; i <= mx; i+=jl)
          u[i-mn] = true;
      }

    int cnt = 0;
    for (ll i=mn; i<=mx; i++) if (!u[i-mn]) cnt++;
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
	int RetVal = 607940; 
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
