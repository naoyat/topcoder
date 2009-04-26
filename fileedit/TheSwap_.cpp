#line 2 "TheSwap.cpp"
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
#define sz(a)  int((a).size())
#define pb  push_back
#define all(c)  (c).begin(),(c).end()
#define tr(c,i)  for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); i++)
#define rep(var,n)  for(int var=0;var<(n);var++)

class TheSwap {
 public:
  int findMax(int n, int k) {
// BEGIN CUT HERE
	// n:1-1000000
    // k:1-10
// END CUT HERE
    if (n<10) return -1;
    if (n<100 && n%10==0) return -1;

    vector<int> v;
    int d=0,x=n;
    while(x){d++; v.pb(x%10); x/=10;}
    reverse(all(v));
    vector<int> s(all(v));
    sort(all(s)); reverse(all(s));
// BEGIN CUT HERE
    //    cout << n << ","<< d << ",v:"<<v << endl;
    //    cout << n << ","<< d << ",s:"<<s << endl;
// END CUT HERE
    rep(b,d){
      int mn=v[b],mnat=b;
      for(int i=b+1;i<d;i++) if(v[i]>=mn) {mn=v[i];mnat=i;}
      if(mnat==b) continue;
      int tm=v[b];v[b]=v[mnat];v[mnat]=tm;k--;
      if (k==0) break;
    }
    if (k>0){
      int tm=v[d-1];v[d-1]=v[d-2];v[d-2]=tm; k--;
    }
// BEGIN CUT HERE
    //    cout << "k:"<< k << ",v:"<<v << endl;
// END CUT HERE
    x=0;
    rep(i,d){x*=10; x+=v[i];}
    return x;
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
	int n = 16375; 
	int k = 1; 
	int RetVal = 76315; 
	return verify_case(RetVal, TheSwap().findMax(n, k)); }
int Test_(Case_<1>) {
	timer_clear();
	int n = 432; 
	int k = 1; 
	int RetVal = 423; 
	return verify_case(RetVal, TheSwap().findMax(n, k)); }
int Test_(Case_<2>) {
	timer_clear();
	int n = 90; 
	int k = 4; 
	int RetVal = -1; 
	return verify_case(RetVal, TheSwap().findMax(n, k)); }
int Test_(Case_<3>) {
	timer_clear();
	int n = 5; 
	int k = 2; 
	int RetVal = -1; 
	return verify_case(RetVal, TheSwap().findMax(n, k)); }
int Test_(Case_<4>) {
	timer_clear();
	int n = 436659; 
	int k = 2; 
	int RetVal = 966354; 
	return verify_case(RetVal, TheSwap().findMax(n, k)); }
int Test_(Case_<5>) {
	timer_clear();
	int n = 1000000;
	int k = 1;
	int RetVal = 1000000;
	return verify_case(RetVal, TheSwap().findMax(n, k)); }
int Test_(Case_<6>) {
	timer_clear();
	int n = 1000000;
	int k = 10;
	int RetVal = 1000000;
	return verify_case(RetVal, TheSwap().findMax(n, k)); }
int Test_(Case_<7>) {
	timer_clear();
	int n = 1;
	int k = 1;
	int RetVal = -1;
	return verify_case(RetVal, TheSwap().findMax(n, k)); }
int Test_(Case_<8>) {
	timer_clear();
	int n = 1;
	int k = 10;
	int RetVal = -1;
	return verify_case(RetVal, TheSwap().findMax(n, k)); }

template<int N> void Run_() { cerr << "Test Case #" << N << "..." << flush; Test_(Case_<N>()); Run_<sizeof(Test_(Case_<N+1>()))==1 ? -1 : N+1>(); }
template<>      void Run_<-1>() {}
int main() { Run_<0>(); }
// END CUT HERE


// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
There is nothing more beautiful than just an integer number.



You are given an integer n.  Write down n in decimal notation with no leading zeroes, and let M be the number of written digits.  Perform the following operation exactly k times:

Choose two different 1-based positions, i and j, such that 1 &lt= i &lt j &lt= M. Swap the digits at positions i and j.  This swap must not cause the resulting number to have a leading zero, i.e., if the digit at position j is zero, then i must be strictly greater than 1.




Return the maximal possible number you can get at the end of this procedure.  If it's not possible to perform k operations, return -1 instead.



DEFINITION
Class:TheSwap
Method:findMax
Parameters:int, int
Returns:int
Method signature:int findMax(int n, int k)


CONSTRAINTS
-n will be between 1 and 1,000,000, inclusive.
-k will be between 1 and 10, inclusive.


EXAMPLES

0)
16375
1

Returns: 76315

The optimal way is to swap 1 and 7.

1)
432
1

Returns: 423

In this case the result is less than the given number.

2)
90
4

Returns: -1

We can't make even a single operation because it would cause the resulting number to have a leading zero.

3)
5
2

Returns: -1

Here we can't choose two different positions for an operation.

4)
436659
2

Returns: 966354



*/
// END CUT HERE