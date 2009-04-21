// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
John thinks 4 and 7 are lucky digits, and all other digits are not lucky.  A lucky number is a number that contains only lucky digits in decimal notation.



You are given ints a and b.  Return the number of lucky numbers between a and b, inclusive.



DEFINITION
Class:TheLuckyNumbers
Method:count
Parameters:int, int
Returns:int
Method signature:int count(int a, int b)


CONSTRAINTS
-a will be between 1 and 1,000,000,000, inclusive.
-b will be between a and 1,000,000,000, inclusive.


EXAMPLES

0)
1
10

Returns: 2

There are only two lucky numbers among the first ten positive integers.

1)
11
20

Returns: 0

But there are none among the next ten.

2)
74
77

Returns: 2

These two numbers are lucky. There are no additional lucky numbers between them.


3)
1000000
5000000

Returns: 64



*/
// END CUT HERE

#line 65 "TheLuckyNumbers.cpp"
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
#define rep(var,n)  for(int var=0;var<(n);var++)

int c(int n, int r)
{
  if (n == 0 || r == 0 || r == n) return 1;
  if (r > n-r) r = n-r;
  return n * c(n-1,r-1) / r;
}
int expt(int x,int n){
  int v=1; rep(i,n) v*=x; return v;
}

class TheLuckyNumbers {
public:
  int s_(int k,int n){
// BEGIN CUT HERE
	//printf("s_(%d,%d)...\n",k,n);
// END CUT HERE
	int cnt=0;
	rep(i,1<<k){
	  int u=0,m=1<<(k-1);
	  rep(j,k){u*=10; u+=(i&m)?7:4; m>>=1;}
	  //printf("u=%d\n", u);
	  if (n>=u) cnt++; else break;
	}
// BEGIN CUT HERE
	//printf("=>%d\n", cnt);
// END CUT HERE
	return cnt;
  }
  int s(int k){
	return expt(2,k);
// BEGIN CUT HERE
	/*
	if(k==0) return 0;
	if(k==1) return 2;
	if(k==1) return 2;
	int cnt=0;
	rep(i,k+1) cnt+=c(k,i);
	printf("s(%d)=%d\n", k,cnt);
	return cnt;
	*/
// END CUT HERE
  }
  int lns(int n){
	if (n<4) return 0;
	if (n<7) return 1;
	if (n<44) return 2;
	if (n>777777777) n=777777777;

	int k=0,t=0,o=1;
	int n_=n;
	while(n_>0){ t=n_; n_/=10; o*=10; k++; }
	o = (o-1)/9;
	int o4=o*4, o7=o*7;
	int kt=k;
	int cnt=0;
	if (n<o7) {
	  kt--;
	  if (n>=o4) {
		cnt += s_(k,n);
	  }
	}
// BEGIN CUT HERE
	//printf("n=%d, k:%d t:%d o:%d[%d %d] kt:%d\n", n, k,t,o,o4,o7,kt);
// END CUT HERE
	rep(i,kt) cnt+=s(i+1);
	return cnt;
  }
  int count(int a, int b) {
// BEGIN CUT HERE
	//a<=b
	/*
	  printf("lns(%d)=%d, lns(%d-1)=%d\n",
		   b, lns(b),
		   a, lns(a-1));
	*/
// END CUT HERE
	return lns(b)-lns(a-1);
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
	int a = 1; 
	int b = 10; 
	int RetVal = 2; 
	return verify_case(RetVal, TheLuckyNumbers().count(a, b)); }
int Test_(Case_<1>) {
	timer_clear();
	int a = 11; 
	int b = 20; 
	int RetVal = 0; 
	return verify_case(RetVal, TheLuckyNumbers().count(a, b)); }
int Test_(Case_<2>) {
	timer_clear();
	int a = 74; 
	int b = 77; 
	int RetVal = 2; 
	return verify_case(RetVal, TheLuckyNumbers().count(a, b)); }
int Test_(Case_<3>) {
	timer_clear();
	int a = 1000000; 
	int b = 5000000; 
	int RetVal = 64; 
	return verify_case(RetVal, TheLuckyNumbers().count(a, b)); }

template<int N> void Run_() { cerr << "Test Case #" << N << "..." << flush; Test_(Case_<N>()); Run_<sizeof(Test_(Case_<N+1>()))==1 ? -1 : N+1>(); }
template<>      void Run_<-1>() {}
int main() { Run_<0>(); }
// END CUT HERE

