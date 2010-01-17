// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// You are given a vector <int> permutation containing a permutation of the first n positive integers (1 through n), and you want to sort them in ascending order.  To do this, you will perform a series of swaps.  For each swap, you consider all pairs (i, j) such that i < j and permutation[i] > permutation[j].  Among all those pairs, you choose one randomly and swap permutation[i] and permutation[j].  Each pair has the same probability of being chosen.  Return the expected number of swaps needed to sort permutation in ascending order.

DEFINITION
Class:RandomSort
Method:getExpected
Parameters:vector <int>
Returns:double
Method signature:double getExpected(vector <int> permutation)

NOTES
-The returned value must be accurate to within a relative or absolute value of 1E-9.


CONSTRAINTS
-permutation will contain between 1 and 8 elements, inclusive.
-permutation will contain each integer between 1 and n, inclusive, exactly once, where n is the number of elements in permutation.


EXAMPLES

0)
{1,3,2}

Returns: 1.0

Exactly one swap is needed.

1)
{4,3,2,1}

Returns: 4.066666666666666

In the first step, any two elements can be swapped.

2)
{1}

Returns: 0.0

This permutation is already sorted, so there\'s no need to perform any swaps.

3)
{2,5,1,6,3,4}

Returns: 5.666666666666666

*/
// END CUT HERE

#line 57 "RandomSort.cpp"
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

template <typename T> T expt(T x, int n) // x^n
{
  T y=1; for(int i=0;i<n;i++) y*=x; return y;
}

class RandomSort {
  int n;
  vector<int> perm;
  //vector<double> memo;
  map<int,double> memo;

  int sig() {
	int s=0;
	tr(perm,it) s=s*n+(*it-1);
	return s;
  }
  double sw(){
	int key=sig();
	//cout << "perm:" << perm << " => " << key << endl;
	if(memo.find(key)!=memo.end()) return memo[key];
	//if(memo[key]>=0) return memo[key];

	set<pair<int,int> > s;
    rep(i,n){
	  int p = perm[i];
	  for(int j=i+1;j<n;j++){
		int q = perm[j];
		if (p>q) s.insert(make_pair(i,j));
	  }
	}
	if (s.size() == 0) {
	  return memo[key] = 0;
	}
	
	double cnt=0;
	tr(s,it){
	  int i=it->first, j=it->second;
	  int p=perm[i], q=perm[j];
	  perm[i]=q; perm[j]=p;
	  cnt += 1 + sw();
	  perm[i]=p; perm[j]=q;
	}

	cnt /= s.size();
	return memo[key] = cnt;
  }
public:
  double getExpected(vector<int> permutation) {
	n=sz(permutation);
	perm = permutation;

	//memo.resize(expt(n,n));
	//fill(all(memo),-1.0);
	return sw();
  }
};

// BEGIN CUT HERE
#include <time.h>
clock_t start_time;
void timer_clear() { start_time = clock(); }
string timer() { clock_t end_time = clock(); double interval = (double)(end_time - start_time)/CLOCKS_PER_SEC; ostringstream os; os << " (" << interval*1000 << " msec)"; return os.str(); }

template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
int verify_case(const double &Expected, const double &Received) { double diff = Expected - Received; if (diff < 0) diff = -diff; if (diff < 1e-9) cerr << "PASSED" << timer() << endl; else { cerr << "FAILED" << timer() << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } return 0;}

template<int N> struct Case_ {};
char Test_(...);
int Test_(Case_<0>) {
	timer_clear();
	int permutation_[] = {1,3,2};
	  vector <int> permutation(permutation_, permutation_+sizeof(permutation_)/sizeof(*permutation_)); 
	double RetVal = 1.0; 
	return verify_case(RetVal, RandomSort().getExpected(permutation)); }
int Test_(Case_<1>) {
	timer_clear();
	int permutation_[] = {4,3,2,1};
	  vector <int> permutation(permutation_, permutation_+sizeof(permutation_)/sizeof(*permutation_)); 
	double RetVal = 4.066666666666666; 
	return verify_case(RetVal, RandomSort().getExpected(permutation)); }
int Test_(Case_<2>) {
	timer_clear();
	int permutation_[] = {1};
	  vector <int> permutation(permutation_, permutation_+sizeof(permutation_)/sizeof(*permutation_)); 
	double RetVal = 0.0; 
	return verify_case(RetVal, RandomSort().getExpected(permutation)); }
int Test_(Case_<3>) {
	timer_clear();
	int permutation_[] = {2,5,1,6,3,4};
	  vector <int> permutation(permutation_, permutation_+sizeof(permutation_)/sizeof(*permutation_)); 
	double RetVal = 5.666666666666666; 
	return verify_case(RetVal, RandomSort().getExpected(permutation)); }
int Test_(Case_<4>) {
	timer_clear();
	int permutation_[] = {1, 5, 3, 7, 8, 6, 2, 4};
	vector <int> permutation(permutation_, permutation_+sizeof(permutation_)/sizeof(*permutation_)); 
	double RetVal = 8.685714285714287;
	return verify_case(RetVal, RandomSort().getExpected(permutation)); }

template<int N> void Run_() { cerr << "Test Case #" << N << "..." << flush; Test_(Case_<N>()); Run_<sizeof(Test_(Case_<N+1>()))==1 ? -1 : N+1>(); }
template<>      void Run_<-1>() {}
int main() { Run_<0>(); }
// END CUT HERE

