#line 2 "IncredibleMachine.cpp"
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

class IncredibleMachine {
 public:
  double gravitationalAcceleration(vector <int> x, vector <int> y, int T) {
    int N=sz(x)-1;
	vector<double> dx(N),dy(N),a(N),s(N),l(N),v(N+1),dt(N);
    v[0]=0.0;
    double t=0;
    //geo
    rep(i,N) {
      dx[i] = (double)x[i+1]-x[i];
      dy[i] = -(double)(y[i+1]-y[i]);
      //l[i] = (dx[i]*dx[i] + dy[i]*dy[i]); l[i] *= l[i];
      a[i]=atan2(dy[i],dx[i]);
      s[i]=sin(a[i]);

      v[i+1]=sqrt(v[i]*v[i] + (y[i]-y[i+1])*2); // *√g
      dt[i] = (v[i+1]-v[i])/s[i]; // /g
      t += dt[i];
    }
    // t/T=√g
    return (t/T)*(t/T);
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
	int x_[] = {0,6};
	  vector <int> x(x_, x_+sizeof(x_)/sizeof(*x_)); 
	int y_[] = {100,22};
	  vector <int> y(y_, y_+sizeof(y_)/sizeof(*y_)); 
	int T = 4; 
	double RetVal = 9.807692307692307; 
	return verify_case(RetVal, IncredibleMachine().gravitationalAcceleration(x, y, T)); }
int Test_(Case_<1>) {
	timer_clear();
	int x_[] = {0,26,100};
	  vector <int> x(x_, x_+sizeof(x_)/sizeof(*x_)); 
	int y_[] = {50,26,24};
	  vector <int> y(y_, y_+sizeof(y_)/sizeof(*y_)); 
	int T = 4; 
	double RetVal = 26.743031720603582; 
	return verify_case(RetVal, IncredibleMachine().gravitationalAcceleration(x, y, T)); }
int Test_(Case_<2>) {
	timer_clear();
	int x_[] = {0,7,8};
	  vector <int> x(x_, x_+sizeof(x_)/sizeof(*x_)); 
	int y_[] = {10,6,0};
	  vector <int> y(y_, y_+sizeof(y_)/sizeof(*y_)); 
	int T = 7; 
	double RetVal = 1.1076837407708007; 
	return verify_case(RetVal, IncredibleMachine().gravitationalAcceleration(x, y, T)); }

template<int N> void Run_() { cerr << "Test Case #" << N << "..." << flush; Test_(Case_<N>()); Run_<sizeof(Test_(Case_<N+1>()))==1 ? -1 : N+1>(); }
template<>      void Run_<-1>() {}
int main() { Run_<0>(); }
// END CUT HERE


// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// You may remember an old computer game called "The Incredible Machine".  It was a game where you could simulate simple processes like balls falling, lasers shooting, or cats pursuing mice.  Moreover, you were able to perform these observations with different values for gravitational acceleration.

We are observing a system with some unknown acceleration of gravity.  There is a slope which has the form of a polyline with N vertices.  Each vertex of the polyline is positioned lower and to the right of the previous one.  At time 0, a ball is placed at the first vertex.  The ball is small enough to be considered a single point.  Assume that there's no friction between the slope and the ball, the ball is absolutely nonelastic, and the direction of its velocity changes instantly at the polyline's vertices.  Under these conditions, the ball will follow the polyline without ever losing contact with it.  The ball reaches the final vertex at time T.

You are given vector <int>s x and y, where (x[i], y[i]) are the coordinates of the i-th vertex.  Return the gravitational acceleration in this system.  A body rolling down an inclined plane of angle alpha (measured between the plane and horizontal direction) under gravitational acceleration g has a constant acceleration of a = g * sin(alpha). The distance d travelled by an object during time t moving with initial velocity v0 and with constant acceleration a is equal to d = v0 * t + 0.5 * a * t^2. The velocity v1 of the object after time t has passed is equal to v1 = v0 + a * t.

DEFINITION
Class:IncredibleMachine
Method:gravitationalAcceleration
Parameters:vector <int>, vector <int>, int
Returns:double
Method signature:double gravitationalAcceleration(vector <int> x, vector <int> y, int T)


CONSTRAINTS
-x will contain between 2 and 50 elements, inclusive.
-Elements of x will be strictly ascending.
-Elements of x will be between 0 and 100, inclusive.
-x and y will contain the same number of elements.
-Elements of y will be strictly descending.
-Elements of y will be between 0 and 100, inclusive.
-T will be between 1 and 100, inclusive.


EXAMPLES

0)
{0,6}
{100,22}
4

Returns: 9.807692307692307

That's an acceleration of gravity that might be somewhere on Earth's surface.


1)
{0,26,100}
{50,26,24}
4

Returns: 26.743031720603582

And this is likely on Jupiter.


2)
{0,7,8}
{10,6,0}
7

Returns: 1.1076837407708007

Note that in spite of the angle at vertex (7,6), the body won't fly off the slope and will follow the segment (7,6)-(8,0).



*/
// END CUT HERE
