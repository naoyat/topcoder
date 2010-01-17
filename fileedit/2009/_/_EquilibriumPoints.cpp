// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// There are N points situated on a straight line. The i-th point is located at coordinate x[i] and has a mass of m[i]. The locatıon of each point is strongly fixed and cannot be changed by any forces. Coordinates of all points are distinct.
When another point P is added on the line and its position is not fixed, the point falls under the impact of gravitational forces from each of the given N points.  Points located to the left of P force it to the left, and points located to the right of P force it to the right.  When two points are located a distance of d apart and have masses m1 and m2, the value of gravitational force between them is F = G * m1 * m2 / d^2, where G is some positive constant.
Point P is said to be an equilibrium point if the vector sum of gravitational forces from all points on P equals zero.  In other words, the sum of the values of gravitational forces between P and all the points located to the left of P must be the same as the sum of the values of gravitational forces between P and all the points located to the right of P.
It is known that there always exist exactly N-1 equilibrium points. Return a vector <double> containing their coordinates sorted in ascending order.

DEFINITION
Class:EquilibriumPoints
Method:getPoints
Parameters:vector <int>, vector <int>
Returns:vector <double>
Method signature:vector <double> getPoints(vector <int> x, vector <int> m)


NOTES
-Each element of your return value must have an absolute or relative error less than 1e-9.
-You don't need to know the mass of point P and the value of constant G to solve the problem.


CONSTRAINTS
-x will contain between 2 and 50 elements, inclusive.
-m will contain the same number of elements as x.
-Each element of x will be between 1 and 1000, inclusive.
-Each element of m will be between 1 and 1000, inclusive.
-x will be sorted in strictly ascending order.


EXAMPLES

0)
{1, 2}
{1, 1}

Returns: {1.5 }

When two points have the same mass, the equilibrium point is located exactly halfway between them.

1)
{1, 2}
{1, 1000}

Returns: {1.0306534300317156 }

When two points have distinct masses, the equlibrium point is located closer to the point with lesser mass.

2)
{1, 2, 3}
{1, 2, 1}

Returns: {1.4060952084922507, 2.5939047915077493 }

There are two equilibrium points located symmetrically with respect to the middle point of the input points.

3)
{2, 3, 5, 7}
{3, 2, 7, 5}

Returns: {2.532859446114924, 3.7271944335152813, 6.099953640852538 }



*/
// END CUT HERE

#line 68 "EquilibriumPoints.cpp"
#include <string>
#include <vector>
// BEGIN CUT HERE
#include <iostream>
#include "cout.h"
// END CUT HERE
#include <sstream>
using namespace std;

class EquilibriumPoints {
private:
  double fabs(double x) { return (x < 0.0) ? -x : x; }

  double equ(vector<int> x, vector<int> m, int n)
  {
	double g = 0.0;
	double x0 = 0.5 * (x[n] + x[n+1]);
	double o = x[n+1] - x[n];

	while (1) {
	  for (int i=0; i<=n; i++) {
		double d = x0 - x[i];
		g -= 1.0 * m[i] / (d * d);
	  }
	  for (int i=n+1,c=x.size(); i<c; i++) {
		double d = x0 - x[i];
		g += 1.0 * m[i] / (d * d);
	  }
	  cout << g << endl;
	  if (fabs(g) < 0.0001) break;
	  x0 += g / o;
	}
	return x0;
  }
public:
  vector<double> getPoints(vector<int> x, vector<int> m) {
// BEGIN CUT HERE
	  // x: 2-50
	  // m: xと同数
	  // x[i]: 1-1000
	  // m[i]: 1-1000
// END CUT HERE
	  int xn = x.size();
	  vector<double> xs(xn - 1);
	  for (int i=0; i<xn-1; i++) xs[i] = equ(x,m,i);
	  return xs;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <double> &Expected, const vector <double> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arr0[] = {1, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arr2[] = {1.5 }; vector <double> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, getPoints(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {1, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 1000}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arr2[] = {1.0306534300317156 }; vector <double> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, getPoints(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {1, 2, 3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 2, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arr2[] = {1.4060952084922507, 2.5939047915077493 }; vector <double> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, getPoints(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {2, 3, 5, 7}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {3, 2, 7, 5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arr2[] = {2.532859446114924, 3.7271944335152813, 6.099953640852538 }; vector <double> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(3, Arg2, getPoints(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	EquilibriumPoints ___test;
	___test.run_test(-1);
}
// END CUT HERE
