// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// There is a laser cannon at coordinates (0, 0) on the cartesian plane.
 There are also several targets on the plane.
 Each target is a vertical line segment, and the endpoints of the i-th target are at coordinates (x[i], y1[i]) and (x[i], y2[i]).
 A random angle between -Pi/2 and Pi/2, inclusive, is chosen, and a single shot is fired.
 The angle -Pi/2 is straight down vertically, 0 is straight to the right horizontally, and Pi/2 is straight up vertically. A shot is a straight ray of infinite length starting from the point (0, 0). A shot hits a target if there is a common point between them. Return the expected number of targets that will be hit by the single shot. Hitting a target doesn't change the direction of the laser shot.

DEFINITION
Class:LaserShooting
Method:numberOfHits
Parameters:vector <int>, vector <int>, vector <int>
Returns:double
Method signature:double numberOfHits(vector <int> x, vector <int> y1, vector <int> y2)


NOTES
-A return value with either an absolute or relative error of less than 1.0e-9 is considered correct.


CONSTRAINTS
-x will contain between 1 and 50 elements, inclusive.
-All elements of x will be distinct.
-x, y1 and y2 will contain the same number of elements.
-Each element of x will be between 1 and 1,000, inclusive.
-Each element of y1 and y2 will be between -1,000 and 1,000, inclusive.
-All targets will have positive lengths.


EXAMPLES

0)
{1}
{-1}
{1}

Returns: 0.5

The only one target will be hit with probability 1/2.

1)
{1,2}
{-1,-2}
{1,2}

Returns: 1.0

Both targets will be hit with probability 1/2.

2)
{3,4,7,1}
{1,2,3,4}
{4,3,2,1}

Returns: 0.4623163952488826



3)
{134,298,151,942}
{-753,-76,19,568}
{440,689,-39,672}

Returns: 1.444210260641501



*/
// END CUT HERE

#line 69 "LaserShooting.cpp"
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

class LaserShooting {
public:
  double numberOfHits(vector <int> x, vector <int> y1, vector <int> y2) {
	int n=x.size();
	double rate=0;
	for(int i=0;i<n;i++){
	  double r1=atan2((double)y1[i],(double)x[i]),
		r2=atan2((double)y2[i],(double)x[i]);
	  if (r1>r2) { double tmp=r1;r1=r2;r2=tmp;}
	  rate += (r2-r1)/3.141592653589793238462643383279;
	}
	return rate;
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
	int x_[] = {1};
	  vector <int> x(x_, x_+sizeof(x_)/sizeof(*x_)); 
	int y1_[] = {-1};
	  vector <int> y1(y1_, y1_+sizeof(y1_)/sizeof(*y1_)); 
	int y2_[] = {1};
	  vector <int> y2(y2_, y2_+sizeof(y2_)/sizeof(*y2_)); 
	double RetVal = 0.5; 
	return verify_case(RetVal, LaserShooting().numberOfHits(x, y1, y2)); }
int Test_(Case_<1>) {
	timer_clear();
	int x_[] = {1,2};
	  vector <int> x(x_, x_+sizeof(x_)/sizeof(*x_)); 
	int y1_[] = {-1,-2};
	  vector <int> y1(y1_, y1_+sizeof(y1_)/sizeof(*y1_)); 
	int y2_[] = {1,2};
	  vector <int> y2(y2_, y2_+sizeof(y2_)/sizeof(*y2_)); 
	double RetVal = 1.0; 
	return verify_case(RetVal, LaserShooting().numberOfHits(x, y1, y2)); }
int Test_(Case_<2>) {
	timer_clear();
	int x_[] = {3,4,7,1};
	  vector <int> x(x_, x_+sizeof(x_)/sizeof(*x_)); 
	int y1_[] = {1,2,3,4};
	  vector <int> y1(y1_, y1_+sizeof(y1_)/sizeof(*y1_)); 
	int y2_[] = {4,3,2,1};
	  vector <int> y2(y2_, y2_+sizeof(y2_)/sizeof(*y2_)); 
	double RetVal = 0.4623163952488826; 
	return verify_case(RetVal, LaserShooting().numberOfHits(x, y1, y2)); }
int Test_(Case_<3>) {
	timer_clear();
	int x_[] = {134,298,151,942};
	  vector <int> x(x_, x_+sizeof(x_)/sizeof(*x_)); 
	int y1_[] = {-753,-76,19,568};
	  vector <int> y1(y1_, y1_+sizeof(y1_)/sizeof(*y1_)); 
	int y2_[] = {440,689,-39,672};
	  vector <int> y2(y2_, y2_+sizeof(y2_)/sizeof(*y2_)); 
	double RetVal = 1.444210260641501; 
	return verify_case(RetVal, LaserShooting().numberOfHits(x, y1, y2)); }

template<int N> void Run_() { cerr << "Test Case #" << N << "..." << flush; Test_(Case_<N>()); Run_<sizeof(Test_(Case_<N+1>()))==1 ? -1 : N+1>(); }
template<>      void Run_<-1>() {}
int main() { Run_<0>(); }
// END CUT HERE

