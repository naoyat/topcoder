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

ll NN,Ans,KK;
int NUM[10],xx;
int DFS(int Digit,ll Now,int Length){
  if(Length<20){
    Now =Now*10+Digit;
    if(NUM[Digit]==0) xx++;
    NUM[Digit]++;
    ll temp=Now;
    while(temp<NN) temp=temp*10+9;
    if (Now<Ans &&temp<Ans &&xx<=KK){
      if (Now>=NN)
        if (Now<Ans &&xx==KK) Ans=Now;
      rep(i,9) DFS(i,Now,Length+1);
    }
    NUM[Digit]--;
    if(NUM[Digit]==0)xx--;
  }
  return 0;
}

class TheInteger {
 public:
  long long find(long long n, int k) {
    NN=n;KK=k;
    Ans=1E19;
    for(int i=1;i<=9;++i){
      memset(NUM,0,sizeof(NUM));
      xx=0;
      DFS(i,0,1);
    }
    return Ans;
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
