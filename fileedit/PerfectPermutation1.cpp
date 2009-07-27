#line 2 "PerfectPermutation.cpp"
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
typedef vector<long long> vll;
#define sz(a)  int((a).size())
#define pb  push_back
#define all(c)  (c).begin(),(c).end()
#define tr(c,i)  for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); i++)
#define rep(var,n)  for(int var=0;var<(n);var++)
#define found(s,e)  ((s).find(e)!=(s).end())

class PerfectPermutation {
  /*
  int dif(const vi&a, const vi&b){
    int n=sz(a),c=0;
    rep(i,n) if(a[i]!=b[i])c++;
    return c;
  }
  */
  vi p_,q; int N, difm;
  map<ll,int> mp;
 public:
  void sub(ll rest,int cur,int diff){
    //ll key=rest | (((ll)cur)<<50);
    ll key=rest;
    if(found(mp,key)){ if(mp[key]<diff) return; }
    mp[key]=diff;
    if (diff>=difm)return;
    //if (__builtin_popcountll(rest)+diff>=difm) return;
    if (rest==0){
      //cout << "Q=" << q << ", " << diff << "|" << difm << endl;
      if(diff<difm)difm=diff;
      return;
    }
    ll m=1LL;
    rep(i,N){
      if(i==cur)goto skip;
      if(!(m&rest))goto skip;
      if(q[cur]>=0)goto skip;
      q[cur]=i;
      sub(rest-m,i,(q[cur]==p_[cur])?diff:(diff+1));
      q[cur]=-1;
   skip:
      m<<=1;
    }
  }
  int reorder(vector <int> P) {
    //cout << "P:" << P << endl;
	N=sz(P); p_.resize(N); rep(i,N) p_[i]=P[i];
    difm=INT_MAX;

    ll rest=(1LL<<N)-1;
    q.resize(N); rep(i,N)q[i]=-1;
    sub(rest,0,0);
    // cout << N << ", " << difm << endl;
    return difm;
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
	int P_[] = {2, 0, 1};
	  vector <int> P(P_, P_+sizeof(P_)/sizeof(*P_)); 
	int RetVal = 0; 
	return verify_case(RetVal, PerfectPermutation().reorder(P)); }
int Test_(Case_<1>) {
	timer_clear();
	int P_[] = {2, 0, 1, 4, 3};
	  vector <int> P(P_, P_+sizeof(P_)/sizeof(*P_)); 
	int RetVal = 2; 
	return verify_case(RetVal, PerfectPermutation().reorder(P)); }
int Test_(Case_<2>) {
	timer_clear();
	int P_[] = {2, 3, 0, 1};
	  vector <int> P(P_, P_+sizeof(P_)/sizeof(*P_)); 
	int RetVal = 2; 
	return verify_case(RetVal, PerfectPermutation().reorder(P)); }
int Test_(Case_<3>) {
	timer_clear();
	int P_[] = {0, 5, 3, 2, 1, 4};
	  vector <int> P(P_, P_+sizeof(P_)/sizeof(*P_)); 
	int RetVal = 3; 
	return verify_case(RetVal, PerfectPermutation().reorder(P)); }
int Test_(Case_<4>) {
	timer_clear();
	int P_[] = {4, 2, 6, 0, 3, 5, 9, 7, 8, 1};
	  vector <int> P(P_, P_+sizeof(P_)/sizeof(*P_)); 
	int RetVal = 5; 
	return verify_case(RetVal, PerfectPermutation().reorder(P)); }
int Test_(Case_<5>) {
	timer_clear();
	int P_[] = {0,1,2,3,4,5,6,7,8,9};
	  vector <int> P(P_, P_+sizeof(P_)/sizeof(*P_)); 
	int RetVal = 0; 
	return verify_case(RetVal, PerfectPermutation().reorder(P)); }
int Test_(Case_<6>) {
	timer_clear();
	int P_[] = {0,1,2,3,4,5,6,7,8,9,
                10,11,12,13,14,15,16,17,18,19,
                20,21,22,23,24,25,26,27,28,29,
                30,31,32,33,34,35,36,37,38,39,
                40,41,42,43,44,45,46,47,48,49};
	  vector <int> P(P_, P_+sizeof(P_)/sizeof(*P_)); 
	int RetVal = 0; 
	return verify_case(RetVal, PerfectPermutation().reorder(P)); }

template<int N> void Run_() { cerr << "Test Case #" << N << "..." << flush; Test_(Case_<N>()); Run_<sizeof(Test_(Case_<N+1>()))==1 ? -1 : N+1>(); }
template<>      void Run_<-1>() {}
int main() { Run_<0>(); }
// END CUT HERE


// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// A permutation A[0], A[1], ..., A[N-1] is a sequence containing each integer between 0 and N-1, inclusive, exactly once.  Each permutation A of length N has a corresponding child array B of the same length, where B is defined as follows:


B[0] = 0
B[i] = A[B[i-1]], for every i between 1 and N-1, inclusive.


A permutation is considered perfect if its child array is also a permutation.

Below are given all permutations for N=3 with their child arrays. Note that for two of these permutations ({1, 2, 0} and {2, 0, 1}) the child array is also a permutation, so these two permutations are perfect.


Permutation		Child array
{0, 1, 2}		{0, 0, 0}
{0, 2, 1}		{0, 0, 0}
{1, 0, 2}		{0, 1, 0}
{1, 2, 0}		{0, 1, 2}
{2, 0, 1}		{0, 2, 1}
{2, 1, 0}		{0, 2, 0}


You are given a vector <int> P containing a permutation of length N.  Find a perfect permutation Q of the same length such that the difference between P and Q is as small as possible, and return this difference.  The difference between P and Q is the number of indices i for which P[i] and Q[i] are different.

DEFINITION
Class:PerfectPermutation
Method:reorder
Parameters:vector <int>
Returns:int
Method signature:int reorder(vector <int> P)


CONSTRAINTS
-P will contain between 1 and 50 elements, inclusive.
-P will contain each integer between 0 and N-1, inclusive, exactly once, where N is the number of elements in P.


EXAMPLES

0)
{2, 0, 1}

Returns: 0

P is a perfect permutation, so we can use the same permutation for Q.  The difference is then 0 because P and Q are the same.

1)
{2, 0, 1, 4, 3}

Returns: 2

Q might be {2, 0, 3, 4, 1}.

2)
{2, 3, 0, 1}

Returns: 2

Q might be {1, 3, 0, 2}.

3)
{0, 5, 3, 2, 1, 4}

Returns: 3



4)
{4, 2, 6, 0, 3, 5, 9, 7, 8, 1}

Returns: 5



*/
// END CUT HERE
