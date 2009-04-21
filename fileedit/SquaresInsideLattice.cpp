// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// We define a rectangular lattice as the set of all points with integer coordinates (x,y) such that 0 <= x <= width and 0 <= y <= height.  A square is inside this lattice if and only if all its vertices belong to the lattice.  Two squares are different if there exists at least one point which is a vertex of the first square but not a vertex of the second square.  The edges of a square are not required to be parallel to the axes.

Return the number of different squares inside the lattice.

DEFINITION
Class:SquaresInsideLattice
Method:howMany
Parameters:int, int
Returns:long long
Method signature:long long howMany(int width, int height)


CONSTRAINTS
-width and height will each be between 1 and 10^5, inclusive.


EXAMPLES

0)
1
1

Returns: 1

There is only one square.

1)
2
3

Returns: 10

There are 6 squares with area 1, 2 squares with area 4, and 2 squares with area 2 (their sides are not parallel to the axes).

2)
3
3

Returns: 20

3)
27
19

Returns: 23940

*/
// END CUT HERE

#line 54 "SquaresInsideLattice.cpp"
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
// BEGIN CUT HERE
#define sz(a)  int((a).size())
#define pb  push_back
#define all(c)  (c).begin(),(c).end()
#define tr(c,i)  for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); i++)
#define rep(var,n)  for(int var=0;var<(n);var++)
#define found(s,e)  ((s).find(e)!=(s).end())
#define remove_(c,val) (c).erase(remove((c).begin(),(c).end(),(val)),(c).end())
// END CUT HERE

class SquaresInsideLattice {
 public:
  long long howMany(int width, int height) {
	int w=min(width,height);
    long long sigma=0;
    for(int i=1;i<=w;i++){
      sigma += (1LL+width-i)*(1LL+height-i)*i;
    }
    return sigma;
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
	int width = 1; 
	int height = 1; 
	long long RetVal = 1LL; 
	return verify_case(RetVal, SquaresInsideLattice().howMany(width, height)); }
int Test_(Case_<1>) {
	timer_clear();
	int width = 2; 
	int height = 3; 
	long long RetVal = 10LL; 
	return verify_case(RetVal, SquaresInsideLattice().howMany(width, height)); }
int Test_(Case_<2>) {
	timer_clear();
	int width = 3; 
	int height = 3; 
	long long RetVal = 20LL; 
	return verify_case(RetVal, SquaresInsideLattice().howMany(width, height)); }
int Test_(Case_<3>) {
	timer_clear();
	int width = 27; 
	int height = 19; 
	long long RetVal = 23940LL; 
	return verify_case(RetVal, SquaresInsideLattice().howMany(width, height)); }

template<int N> void Run_() { cerr << "Test Case #" << N << "..." << flush; Test_(Case_<N>()); Run_<sizeof(Test_(Case_<N+1>()))==1 ? -1 : N+1>(); }
template<>      void Run_<-1>() {}
int main() { Run_<0>(); }
// END CUT HERE

