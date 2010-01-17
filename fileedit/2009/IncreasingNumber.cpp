#line 2 "IncreasingNumber.cpp"
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

class IncreasingNumber {
	public:
	int countNumbers(long long digits, int divisor) {
		
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
	long long digits = 2LL; 
	int divisor = 12; 
	int RetVal = 4; 
	return verify_case(RetVal, IncreasingNumber().countNumbers(digits, divisor)); }
int Test_(Case_<1>) {
	timer_clear();
	long long digits = 3LL; 
	int divisor = 111; 
	int RetVal = 9; 
	return verify_case(RetVal, IncreasingNumber().countNumbers(digits, divisor)); }
int Test_(Case_<2>) {
	timer_clear();
	long long digits = 452LL; 
	int divisor = 10; 
	int RetVal = 0; 
	return verify_case(RetVal, IncreasingNumber().countNumbers(digits, divisor)); }
int Test_(Case_<3>) {
	timer_clear();
	long long digits = 6LL; 
	int divisor = 58; 
	int RetVal = 38; 
	return verify_case(RetVal, IncreasingNumber().countNumbers(digits, divisor)); }

template<int N> void Run_() { cerr << "Test Case #" << N << "..." << flush; Test_(Case_<N>()); Run_<sizeof(Test_(Case_<N+1>()))==1 ? -1 : N+1>(); }
template<>      void Run_<-1>() {}
int main() { Run_<0>(); }
// END CUT HERE


// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// A positive integer is called Increasing Number if its digits are in non-descending order from left to right in decimal notation. For example, 1234, 111, 58 and 8899 are Increasing Numbers, while 314, 7654 and 2009 are not.


You are given a long long digits and an int divisor. Calculate the number of Increasing Numbers that satisfy both of the following conditions and return this number modulo 1,000,000,007.

The number contains exactly digits digits in the decimal notation with no leading zeroes.
The number is divisible by divisor.


DEFINITION
Class:IncreasingNumber
Method:countNumbers
Parameters:long long, int
Returns:int
Method signature:int countNumbers(long long digits, int divisor)


CONSTRAINTS
-digits will be between 1 and 1,000,000,000,000,000,000 (10^18), inclusive.
-divisor will be between 1 and 500, inclusive.


EXAMPLES

0)
2
12

Returns: 4

12, 24, 36, and 48 satisfy the conditions.

1)
3
111

Returns: 9

All 3-digits numbers divisible by 111 are Increasing Numbers.

2)
452
10

Returns: 0

There is no Increasing Number divisible by 10.

3)
6
58

Returns: 38



*/
// END CUT HERE
