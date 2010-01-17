#line 2 "TheNewHouseDivOne.cpp"
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

class TheNewHouseDivOne {
 public:
  inline double md(double x1,double y1,double x2,double y2) {
    return abs(x1-x2)+abs(y1-y2);
  }
    
  double distance(vector <int> x, vector <int> y, int k) {
	int n=sz(x);
    double minx = *min_element(all(x)), maxx = *max_element(all(x));
    double miny = *min_element(all(y)), maxy = *max_element(all(y));
    double mdk=100000;
    for (double a=minx;a<=maxx;a+=0.5) {
      for (double b=miny;b<=maxy;b+=0.5) {
        priority_queue<double> pq;
        rep(i,n) {
          double d=md(a,b,1.0*x[i],1.0*y[i]);
          pq.push(-d);
        }
        rep(i,k-1) pq.pop();
        double dk=-pq.top();
        if(dk<mdk) mdk=dk;
      }
    }
    return mdk;
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
	int x_[] = {-1, -1, 1, 1};
	  vector <int> x(x_, x_+sizeof(x_)/sizeof(*x_)); 
	int y_[] = {-1, 1, -1, 1};
	  vector <int> y(y_, y_+sizeof(y_)/sizeof(*y_)); 
	int k = 3; 
	double RetVal = 2.0; 
	return verify_case(RetVal, TheNewHouseDivOne().distance(x, y, k)); }
int Test_(Case_<1>) {
	timer_clear();
	int x_[] = {-1, -1, 1, 1};
	  vector <int> x(x_, x_+sizeof(x_)/sizeof(*x_)); 
	int y_[] = {-1, 1, -1, 1};
	  vector <int> y(y_, y_+sizeof(y_)/sizeof(*y_)); 
	int k = 2; 
	double RetVal = 1.0; 
	return verify_case(RetVal, TheNewHouseDivOne().distance(x, y, k)); }
int Test_(Case_<2>) {
	timer_clear();
	int x_[] = {4, 4, 4, 4, 4, 3, 3, 5, 5};
	  vector <int> x(x_, x_+sizeof(x_)/sizeof(*x_)); 
	int y_[] = {7, 7, 7, 4, 4, 5, 6, 5, 6};
	  vector <int> y(y_, y_+sizeof(y_)/sizeof(*y_)); 
	int k = 9; 
	double RetVal = 1.5; 
	return verify_case(RetVal, TheNewHouseDivOne().distance(x, y, k)); }
int Test_(Case_<3>) {
	timer_clear();
	int x_[] = {30, -15, 24, -23, 43, -8, -6, -47, 23, -11, 43, 6, -18, 44, -46, 16, 32, 31, 13, 9, 22, 25, 4, -44, 38, -41, -20, 41, -35, 7, 25, 39, -36, -20, -5, -38, -15, -22, 0};
	  vector <int> x(x_, x_+sizeof(x_)/sizeof(*x_)); 
	int y_[] = {-45, -7, -33, 31, -8, -33, -20, -14, -50, -48, -31, 35, -24, -31, -11, 41, -41, -11, 46, -1, -5, 5, -39, -26, -40, -9, 16, 38, -30, 34, 46, -17, -27, 33, -38, 28, 46, -16, -46};
	  vector <int> y(y_, y_+sizeof(y_)/sizeof(*y_)); 
	int k = 13; 
	double RetVal = 32.0; 
	return verify_case(RetVal, TheNewHouseDivOne().distance(x, y, k)); }

template<int N> void Run_() { cerr << "Test Case #" << N << "..." << flush; Test_(Case_<N>()); Run_<sizeof(Test_(Case_<N+1>()))==1 ? -1 : N+1>(); }
template<>      void Run_<-1>() {}
int main() { Run_<0>(); }
// END CUT HERE


// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
John is obsessed with security.
He has several old houses and he wants to build one new.
John is very afraid of thieves, so he will choose the location of the new house using the following method.
From each of his old houses, he will measure the Manhattan distance to the new house.
He will then take the k-th (1 based) shortest distance.
The location that minimizes this distance will be the location of his new house.



You are given the locations of his old houses in vector <int>s x and y.
The i-th old house is located at (x[i], y[i]).
Return the smallest possible k-th distance.



DEFINITION
Class:TheNewHouseDivOne
Method:distance
Parameters:vector <int>, vector <int>, int
Returns:double
Method signature:double distance(vector <int> x, vector <int> y, int k)


NOTES
-The returned value must be accurate to within a relative or absolute value of 1E-9.
-The Manhattan distance between two points (x1, y1) and (x2, y2) is |x1 - x2| + |y1 - y2|.
-Several houses can be located at the same point.


CONSTRAINTS
-x will contain between 1 and 50 elements, inclusive.
-x and y will contain the same number of elements.
-Each element of x will be between -50 and 50, inclusive.
-Each element of y will be between -50 and 50, inclusive.
-k will be between 1 and the number of elements in x, inclusive.


EXAMPLES

0)
{-1, -1, 1, 1}
{-1, 1, -1, 1}
3

Returns: 2.0

One of the optimal ways is to build a new house at (0, 0).

1)
{-1, -1, 1, 1}
{-1, 1, -1, 1}
2

Returns: 1.0

And here we have four possible locations for the new house - (-1, 0), (1, 0), (0, -1) and (0, 1).

2)
{4, 4, 4, 4, 4, 3, 3, 5, 5}
{7, 7, 7, 4, 4, 5, 6, 5, 6}
9

Returns: 1.5

Some houses are located at the same point.

3)
{30, -15, 24, -23, 43, -8, -6, -47, 23, -11, 43, 6, -18, 44, -46, 16, 32, 31, 13, 9, 22, 25, 4, -44, 38, -41, -20, 41, -35, 7, 25, 39, -36, -20, -5, -38, -15, -22, 0}
{-45, -7, -33, 31, -8, -33, -20, -14, -50, -48, -31, 35, -24, -31, -11, 41, -41, -11, 46, -1, -5, 5, -39, -26, -40, -9, 16, 38, -30, 34, 46, -17, -27, 33, -38, 28, 46, -16, -46}
13

Returns: 32.0

*/
// END CUT HERE
