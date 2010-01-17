// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// A positive integer is said to be k-smooth if its largest prime factor is no greater than k. Compute how many positive integers less than or equal to N are k-smooth.

DEFINITION
Class:SmoothNumbers
Method:countSmoothNumbers
Parameters:int, int
Returns:int
Method signature:int countSmoothNumbers(int N, int k)


CONSTRAINTS
-N will be between 1 and 100,000, inclusive.
-k will be between 1 and 100, inclusive.


EXAMPLES

0)
10
3

Returns: 7

Of the first ten integers, only 5, 7 and 10 have prime factors greater than 3.

1)
10
4

Returns: 7

4 is not prime, so 4-smooth numbers are the same as 3-smooth numbers.

2)
15
3

Returns: 8



3)
5
20

Returns: 5



4)
100000
100

Returns: 17442



*/
// END CUT HERE

#line 65 "SmoothNumbers.cpp"
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
#define found(s,e)  ((s).find(e)!=(s).end())
#define remove_(c,val) (c).erase(remove((c).begin(),(c).end(),(val)),(c).end())

class SmoothNumbers {
  int N_;
  vector<int> primes;
  vector<bool> memo;

  void sub(int n){
	//printf("  sub(%d)\n",n);
	tr(primes,it){
	  int np = *it * n;
	  if (np>N_) continue;
	  if (!memo[np]) { sub(np); memo[np]=true; }
	}
  }
public:
  int countSmoothNumbers(int N, int k) {
	N_=N;
	int primes_[25] = { 2, 3, 5, 7, 11,  13, 17, 19, 23, 29,
					   31, 37, 41, 43, 47,  53, 59, 61, 67, 71,
					   73, 79, 83, 89, 97 };
	memo.resize(N+1); fill(all(memo),false);
	memo[1]=true;
	rep(i,25) {
	  int p=primes_[i]; 
	  if(p<=k) primes.pb(p);
	  else break;
	}
	sub(1);
	int cnt=0; for(int i=1;i<=N;i++) if(memo[i]) cnt++;
	return cnt;
// BEGIN CUT HERE
	cout << k << " | " << primes << endl;
//	cout << N <<"," <<k <<","<< primes <<endl;
	/*
	int cnt=0;
	tr(primes,it) {
	  int p=*it;
	  if(p>N) break;
	  //if (N%p==0)
	  cnt += sub(N/p);
	}
	return cnt;
	*/
// END CUT HERE
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
	int N = 10; 
	int k = 3; 
	int RetVal = 7; 
	return verify_case(RetVal, SmoothNumbers().countSmoothNumbers(N, k)); }
int Test_(Case_<1>) {
	timer_clear();
	int N = 10; 
	int k = 4; 
	int RetVal = 7; 
	return verify_case(RetVal, SmoothNumbers().countSmoothNumbers(N, k)); }
int Test_(Case_<2>) {
	timer_clear();
	int N = 15; 
	int k = 3; 
	int RetVal = 8; 
	return verify_case(RetVal, SmoothNumbers().countSmoothNumbers(N, k)); }
int Test_(Case_<3>) {
	timer_clear();
	int N = 5; 
	int k = 20; 
	int RetVal = 5; 
	return verify_case(RetVal, SmoothNumbers().countSmoothNumbers(N, k)); }
int Test_(Case_<4>) {
	timer_clear();
	int N = 100000; 
	int k = 100; 
	int RetVal = 17442; 
	return verify_case(RetVal, SmoothNumbers().countSmoothNumbers(N, k)); }
int Test_(Case_<5>) {
	timer_clear();
	int N = 100000; 
	int k = 1; 
	int RetVal = 1; 
	return verify_case(RetVal, SmoothNumbers().countSmoothNumbers(N, k)); }

template<int N> void Run_() { cerr << "Test Case #" << N << "..." << flush; Test_(Case_<N>()); Run_<sizeof(Test_(Case_<N+1>()))==1 ? -1 : N+1>(); }
template<>      void Run_<-1>() {}
int main() { Run_<0>(); }
// END CUT HERE

