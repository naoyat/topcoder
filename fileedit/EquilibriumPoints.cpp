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
#include <cmath>
using namespace std;

class EquilibriumPoints {
public:
  vector<double> getPoints(vector<int> x, vector<int> m) {
// BEGIN CUT HERE
	// x,m each has 2-50 elements
	// x:[1-1000] ordered, m:[1-1000]
	//	cout << "x: " << x << endl;
	//	cout << "m: " << m << endl;
// END CUT HERE
	int nn = x.size();
	vector<double> points(nn - 1);

	for (int i=0; i<nn-1; i++) {
	  double lower = (double)x[i], upper = (double)x[i+1], mid = (lower + upper)/2;
	  //printf("i=%d/%d\n", i+1,nn-1);
	  double last_g = 0.0;
	  while (1) {
		double g = 0.0;
		for (int j=i+1; j<nn; j++) {
		  double r = mid - x[j];
		  g += (double)m[j] / r / r;
		}
		for (int j=0; j<=i; j++) {
		  double r = mid - x[j];
		  g -= (double)m[j] / r / r;
		}
		//printf("  lower=%g, mid=%g, upper=%g, g = %g\n", lower,mid,upper, g);
		if (upper - lower < 10e-10) {
		  // printf(" solved... mid=%2.10f, g = %g\n", mid, g);
		  points[i] = mid;
		  break;
		}

		if (g > 0.0) {
		  upper = mid;
		  mid = (lower + mid)/2;
		} else {
		  lower = mid;
		  mid = (mid + upper)/2;
		}
		last_g = g;
	  }
	}
	return points;
  }
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) {
	  if ((Case == -1) || (Case == 0)) test_case_0();
	  if ((Case == -1) || (Case == 1)) test_case_1();
	  if ((Case == -1) || (Case == 2)) test_case_2();
	  if ((Case == -1) || (Case == 3)) test_case_3();

	  if ((Case == -1) || (Case == 100)) test_case_100();
	}
	private:

	template <typename T> string print_array(const vector<T> &V) {
	  ostringstream os;
	  os << "{ ";
	  for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) {
		char buf[16];
		sprintf(buf, "%2.10f", *iter);
		os << buf << ", ";
	  }
	  //		os << '\"' << *iter << "\",";
	  //		os << '\"' << *iter << "\",";
	  os << " }";
	  return os.str();
	}

  clock_t start;
  void timer_clear()
  {
	start = clock();
  }
  char *timer()
  {
	clock_t end = clock();
	double interval = (double)(end - start)/CLOCKS_PER_SEC;
	
	char *ret = NULL;
	asprintf(&ret, " (%g msec)", interval*1000);
	return ret;
  }

  void verify_case(int Case, const vector<double> &Expected, const vector<double> &Received) {
	cerr << "Test Case #" << Case << "..."; 
	for (int i=Expected.size()-1; i>=0; i--) {
	  if (abs(Expected[i] - Received[i]) >= 10e-9) {
		cerr << "FAILED" << timer() << endl;
		cerr << "\tExpected: " << print_array(Expected) << endl;
		cerr << "\tReceived: " << print_array(Received) << endl;
		return;
	  }
	}
	cerr << "PASSED" << timer() << endl;
  }
  
  void test_case_0() { 
	timer_clear();
	int Arr0[] = {1, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arr2[] = {1.5 }; vector <double> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, getPoints(Arg0, Arg1)); }
  void test_case_1() {
	timer_clear();
	int Arr0[] = {1, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 1000}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arr2[] = {1.0306534300317156 }; vector <double> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, getPoints(Arg0, Arg1)); }
  void test_case_2() {
	timer_clear();
	int Arr0[] = {1, 2, 3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 2, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arr2[] = {1.4060952084922507, 2.5939047915077493 }; vector <double> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, getPoints(Arg0, Arg1)); }
  void test_case_3() {
	timer_clear();
	int Arr0[] = {2, 3, 5, 7}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {3, 2, 7, 5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arr2[] = {2.532859446114924, 3.7271944335152813, 6.099953640852538 }; vector <double> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(3, Arg2, getPoints(Arg0, Arg1)); }

  void test_case_100() {
	timer_clear();
	int Arr0[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,
				  26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50};
	vector<int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
	int Arr1[] = {1,1,1,1,1, 1,1,1,1,1, 1,1,1,1,1, 1,1,1,1,1, 1,1,1,1,1,
				  1,1,1,1,1, 1,1,1,1,1, 1,1,1,1,1, 1,1,1,1,1, 1,1,1,1,1 };
	vector<int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
	double Arr2[] = { 1.4722966738, 2.4859717749, 3.4907930307, 4.4932458885, 5.4947323911, 6.4957317747, 7.4964518063, 8.4969970770, 9.4974259250, 10.4977734871, 11.4980621748, 12.4983069934, 13.4985183515, 14.4987037294, 15.4988686629, 16.4990173243, 17.4991529547, 18.4992781244, 19.4993948974, 20.4995049797, 21.4996098317, 22.4997106977, 23.4998086877, 24.4999048002, 25.5000000037, 26.5000951998, 27.5001913123, 28.5002893023, 29.5003901683, 30.5004950203, 31.5006051026, 32.5007218756, 33.5008470453, 34.5009826757, 35.5011313371, 36.5012962706, 37.5014816485, 38.5016930066, 39.5019378252, 40.5022265129, 41.5025740750, 42.5030029230, 43.5035481937, 44.5042682253, 45.5052676089, 46.5067541115, 47.5092069693, 48.5140282251, 49.5277033262 };
	vector<double> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
	verify_case(100, Arg2, getPoints(Arg0, Arg1));
  }
	// x,m each has 2-50 elements
	// x:[1-1000] ordered, m:[1-1000]

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	EquilibriumPoints ___test;
	___test.run_test(-1);
}
// END CUT HERE
