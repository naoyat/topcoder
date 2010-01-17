#line 2 "SortingWithPermutation.cpp"
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
#define sz(a)  int((a).size())
#define pb  push_back
#define all(c)  (c).begin(),(c).end()
#define tr(c,i)  for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); i++)
#define rep(var,n)  for(int var=0;var<(n);var++)

class SortingWithPermutation {
 public:
  vector<int> getPermutation(vector<int> a) {
    int n=sz(a);
    int M=1000;
    vector<vector<int> > s(M+1),t(M+1);
    rep(i,M+1) s[i].resize(0);
    rep(i,n) s[ a[i] ].pb(i);
    rep(i,M+1) sort(all(s[i]));
	vector<int> b(all(a));
    sort(all(b));
    rep(i,n) t[ b[i] ].pb(i);
    rep(i,M+1){ sort(all(t[i])); reverse(all(t[i])); }
    vector<int> ans(n);
    rep(i,n){
      ans[i] = t[ a[i] ].back();
      t[ a[i] ].pop_back();
    }
    return ans;
  }
};

// BEGIN CUT HERE
#include <time.h>
clock_t start_time;
void timer_clear() { start_time = clock(); }
string timer() { clock_t end_time = clock(); double interval = (double)(end_time - start_time)/CLOCKS_PER_SEC; ostringstream os; os << " (" << interval*1000 << " msec)"; return os.str(); }

template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
int verify_case(const vector <int> &Expected, const vector <int> &Received) { if (Expected == Received) cerr << "PASSED" << timer() << endl; else { cerr << "FAILED" << timer() << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } return 0;}

template<int N> struct Case_ {};
char Test_(...);
int Test_(Case_<0>) {
	timer_clear();
	int a_[] = {2, 3, 1};
	  vector <int> a(a_, a_+sizeof(a_)/sizeof(*a_)); 
	int RetVal_[] = {1, 2, 0 };
	  vector <int> RetVal(RetVal_, RetVal_+sizeof(RetVal_)/sizeof(*RetVal_)); 
	return verify_case(RetVal, SortingWithPermutation().getPermutation(a)); }
int Test_(Case_<1>) {
	timer_clear();
	int a_[] = {2, 1, 3, 1};
	  vector <int> a(a_, a_+sizeof(a_)/sizeof(*a_)); 
	int RetVal_[] = {2, 0, 3, 1 };
	  vector <int> RetVal(RetVal_, RetVal_+sizeof(RetVal_)/sizeof(*RetVal_)); 
	return verify_case(RetVal, SortingWithPermutation().getPermutation(a)); }
int Test_(Case_<2>) {
	timer_clear();
	int a_[] = {4, 1, 6, 1, 3, 6, 1, 4};
	  vector <int> a(a_, a_+sizeof(a_)/sizeof(*a_)); 
	int RetVal_[] = {4, 0, 6, 1, 3, 7, 2, 5 };
	  vector <int> RetVal(RetVal_, RetVal_+sizeof(RetVal_)/sizeof(*RetVal_)); 
	return verify_case(RetVal, SortingWithPermutation().getPermutation(a)); }
int Test_(Case_<3>) {
	timer_clear();
	int a_[] = {1};
	  vector <int> a(a_, a_+sizeof(a_)/sizeof(*a_)); 
    int RetVal_[] = {0};
	  vector <int> RetVal(RetVal_, RetVal_+sizeof(RetVal_)/sizeof(*RetVal_)); 
	return verify_case(RetVal, SortingWithPermutation().getPermutation(a)); }
int Test_(Case_<4>) {
	timer_clear();
	int a_[] = {1000};
	  vector <int> a(a_, a_+sizeof(a_)/sizeof(*a_)); 
    int RetVal_[] = {0};
	  vector <int> RetVal(RetVal_, RetVal_+sizeof(RetVal_)/sizeof(*RetVal_)); 
	return verify_case(RetVal, SortingWithPermutation().getPermutation(a)); }
int Test_(Case_<5>) {
	timer_clear();
	int a_[] = {1,1,1,1,1,1,1,1,1,1,
                1,1,1,1,1,1,1,1,1,1,
                1,1,1,1,1,1,1,1,1,1,
                1,1,1,1,1,1,1,1,1,1,
                1,1,1,1,1,1,1,1,1,1};
	  vector <int> a(a_, a_+sizeof(a_)/sizeof(*a_)); 
      int RetVal_[] = {0,1,2,3,4,5,6,7,8,9,
                       10,11,12,13,14,15,16,17,18,19,
                       0,0,0,0,0,0,0,0,0,0,
                       0,0,0,0,0,0,0,0,0,0,
                       0,0,0,0,0,0,0,0,0,0 };
	  vector <int> RetVal(RetVal_, RetVal_+sizeof(RetVal_)/sizeof(*RetVal_)); 
	return verify_case(RetVal, SortingWithPermutation().getPermutation(a)); }

template<int N> void Run_() { cerr << "Test Case #" << N << "..." << flush; Test_(Case_<N>()); Run_<sizeof(Test_(Case_<N+1>()))==1 ? -1 : N+1>(); }
template<>      void Run_<-1>() {}
int main() { Run_<0>(); }
// END CUT HERE


// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// A permutation p[0], p[1], ..., p[n-1] is a sequence containing each number from 0 to n-1 exactly once. The result of applying permutation p to an array a of length n is an array b of length n, where b[p[i]] = a[i] (0-based indices).

Given an array a, find a permutation which has the effect of sorting the elements of a in non-descending order, i.e., an order where each element is greater than or equal to the previous one. If there are several suitable permutations return the lexicographically smallest one.

The permutation p[0], p[1], ..., p[n-1] is considered lexicographically smaller than the permutation q[0], q[1], ..., q[n-1] if there is an index i such that p[i] < q[i] and the equation p[j] = q[j] holds for all j < i.

DEFINITION
Class:SortingWithPermutation
Method:getPermutation
Parameters:vector <int>
Returns:vector <int>
Method signature:vector <int> getPermutation(vector <int> a)


CONSTRAINTS
-a will contain between 1 and 50 elements, inclusive.
-Each element of a will be between 1 and 1000, inclusive.


EXAMPLES

0)
{2, 3, 1}

Returns: {1, 2, 0 }

The element that is originally at position 0 goes to position 1.  The elements originally at positions 1 and 2 go to positions 2 and 0, respectively.

1)
{2, 1, 3, 1}

Returns: {2, 0, 3, 1 }

There are two suitable permutations - {2, 0, 3, 1} and {2, 1, 3, 0}. The first one is lexicographically smaller.

2)
{4, 1, 6, 1, 3, 6, 1, 4}

Returns: {4, 0, 6, 1, 3, 7, 2, 5 }



*/
// END CUT HERE
