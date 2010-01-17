// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// A string of letters A, B, C is forbidden if there are three consecutive letters from which one is A, one is B, and one is C. For example, BAACAACCBAAA is forbidden, while AABBCCAABB is not.

Your task is to calculate how many such strings of length n are not forbidden.


DEFINITION
Class:ForbiddenStrings
Method:countNotForbidden
Parameters:int
Returns:long long
Method signature:long long countNotForbidden(int n)


CONSTRAINTS
-n will be between 1 and 30, inclusive.


EXAMPLES

0)
2

Returns: 9

All 9 strings of length 2 are not forbidden.


1)
3

Returns: 21

There are 27 strings of length 3. Of these, 6 contain one occurrence of each letter. Those 6 strings are forbidden, so you should return 21.


2)
4

Returns: 51



*/
// END CUT HERE

#line 50 "ForbiddenStrings.cpp"
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

long long pow(int x, int n)
{
  long long val = 1;
  for (int i=0;i<n;i++) val *= (long long)x;
  return val;
}

class ForbiddenStrings {
public:
  long long countNotForbidden(int n) {
	if (n < 3) return pow(3,n);

	vector<vector<long long> > cnt(n);
	tr(cnt,it) {
	  (*it).resize(27);
	  tr(*it,jt) *jt = 0LL;
	}
	rep(i,3) rep(j,3) rep(k,3) {
	  cnt[2][i*9 + j*3 + k] = 1;
	}

	for(int s=3;s<n;s++) {
	  vector<long long> tmp(9,0LL);
	  rep(i,27) {
		switch(i) {
		case 5: case 7: case 11: case 15: case 19: case 21: break;
		default:
		  tmp[i%9] += cnt[s-1][i]; break;
		}
	  }
	  rep(j,9) {
		long long c = tmp[j];
		rep(k,3) {
		  int i=j*3+k;
		  switch(i) {
		  case 5: case 7: case 11: case 15: case 19: case 21: break;
		  default:
			cnt[s][i] = c; break;
		  }
		}
	  }
	}

	long long sum = 0;
	rep(i,27) {
	  switch (i){
		// 012 021 102 120 201 210
	  case 5: case 7: case 11: case 15: case 19: case 21: break;
	  default:
		/*
		printf("%d %d %d) %lld\n",
			   (i/27), (i/9)%3, i%3,
			   cnt[n-1][i]);
		*/
		sum += cnt[n-1][i]; break;
	  }
	}
	return sum;
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
	int n = 2; 
	long long RetVal = 9LL; 
	return verify_case(RetVal, ForbiddenStrings().countNotForbidden(n)); }
int Test_(Case_<1>) {
	timer_clear();
	int n = 3; 
	long long RetVal = 21LL; 
	return verify_case(RetVal, ForbiddenStrings().countNotForbidden(n)); }
int Test_(Case_<2>) {
	timer_clear();
	int n = 4; 
	long long RetVal = 51LL; 
	return verify_case(RetVal, ForbiddenStrings().countNotForbidden(n)); }

template<int N> void Run_() { cerr << "Test Case #" << N << "..." << flush; Test_(Case_<N>()); Run_<sizeof(Test_(Case_<N+1>()))==1 ? -1 : N+1>(); }
template<>      void Run_<-1>() {}
int main() { Run_<0>(); }
// END CUT HERE

