#line 2 "PipeCuts.cpp"
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
#define all(c)  (c).begin(),(c).end()
#define tr(c,i)  for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); i++)
#define rep(var,n)  for(int var=0;var<(n);var++)
#define forr(var,from,to) for(int var=(from);var<=(to);var++) 

class PipeCuts {
 public:
  double probability(vector <int> weldLocations, int L) {
    int n=sz(weldLocations);
    sort(all(weldLocations));
    int nC2=n*(n-1)/2,cnt=0;
    rep(i,n-1){
      int a=weldLocations[i];
      forr(j,i+1,n-1){
        int b=weldLocations[j]-a, c=100-weldLocations[j];
        //printf("[%d,%d/%d] %d %d %d\n", i,j,n, a,b,c);
        if(a>L || b>L || c>L) cnt++;
      }
    }
    return (double)cnt/nC2;
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
	int weldLocations_[] = {25, 50, 75};
	  vector <int> weldLocations(weldLocations_, weldLocations_+sizeof(weldLocations_)/sizeof(*weldLocations_)); 
	int L = 25; 
	double RetVal = 1.0; 
	return verify_case(RetVal, PipeCuts().probability(weldLocations, L)); }
int Test_(Case_<1>) {
	timer_clear();
	int weldLocations_[] = {25, 50, 75};
	  vector <int> weldLocations(weldLocations_, weldLocations_+sizeof(weldLocations_)/sizeof(*weldLocations_)); 
	int L = 50; 
	double RetVal = 0.0; 
	return verify_case(RetVal, PipeCuts().probability(weldLocations, L)); }
int Test_(Case_<2>) {
	timer_clear();
	int weldLocations_[] = {25, 50, 75};
	  vector <int> weldLocations(weldLocations_, weldLocations_+sizeof(weldLocations_)/sizeof(*weldLocations_)); 
	int L = 24; 
	double RetVal = 1.0; 
	return verify_case(RetVal, PipeCuts().probability(weldLocations, L)); }
int Test_(Case_<3>) {
	timer_clear();
	int weldLocations_[] = {99, 88, 77, 66, 55, 44, 33, 22, 11};
	  vector <int> weldLocations(weldLocations_, weldLocations_+sizeof(weldLocations_)/sizeof(*weldLocations_)); 
	int L = 50; 
	double RetVal = 0.7222222222222222; 
	return verify_case(RetVal, PipeCuts().probability(weldLocations, L)); }

template<int N> void Run_() { cerr << "Test Case #" << N << "..." << flush; Test_(Case_<N>()); Run_<sizeof(Test_(Case_<N+1>()))==1 ? -1 : N+1>(); }
template<>      void Run_<-1>() {}
int main() { Run_<0>(); }
// END CUT HERE


// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// A 100 meter long pipe must be cut in two places.  It can only be cut at certain places, where it was originally welded from smaller pipes.  If the two cut locations are chosen at random (each potential location has equal probability of being chosen), find the probability of a resulting pipe being longer than L meters.


Create a method named probability that accepts a int[] weldLocations and int L as parameters.  It should calculate the probability of one or more resulting pipes being strictly longer than L if the two cut locations are chosen at random from weldLocations.  Each element in weldLocations represents the number of meters from the left end of the pipe.

DEFINITION
Class:PipeCuts
Method:probability
Parameters:vector <int>, int
Returns:double
Method signature:double probability(vector <int> weldLocations, int L)


NOTES
-Your return value must have a relative or absolute error less than 1e-9.


CONSTRAINTS
-weldLocations will have between 2 and 50 elements, inclusive.
-Each element in weldLocations will be between 1 and 99, inclusive.
-weldLocations will not contain duplicate elements.
-L will be between 1 and 100, inclusive.


EXAMPLES

0)
{25, 50, 75}
25

Returns: 1.0

Any random set of cuts results in a pipe being longer than 25 meters.

1)
{25, 50, 75}
50

Returns: 0.0

This time, it is impossible to cut the pipe such that some resulting pipe is longer than 50 meters.

2)
{25, 50, 75}
24

Returns: 1.0

3)
{99, 88, 77, 66, 55, 44, 33, 22, 11}
50

Returns: 0.7222222222222222

*/
// END CUT HERE
