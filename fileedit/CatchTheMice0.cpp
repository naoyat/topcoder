// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// A fairground operator has designed a new game, called "Catch the Mice". This consists of a set of electronic "mice" that move around on a large board. The contestant controls a square cage, which is initially suspended above the board. The contestant can position the cage anywhere above the board and then drop it, the aim being to enclose some of the mice in the cage. The contestant wins a prize accoring to how many mice he managed to capture. If the contestant captures all of the mice, then he wins the grand prize, which is a sports car. However the fairground operator is not entirely honest, and wants your help to rig the game so that it is impossible to win the grand prize. He wants to make the cage sufficiently small that at no point in time are the mice close enough for it to capture them all.
Consider the mice as a set of points moving in an infinite 2D cartesian plane. Each mouse starts at a known position at time t = 0, then moves with constant velocity in time t ≥ 0. Consider the cage as a perfect square of side length L, that can be positioned anywhere in the plane with its sides parallel to the axes (i.e., the contestant can move, but cannot rotate the cage). The cage can be dropped at any time t ≥ 0 and it will capture a mouse if at that point in time the mouse's position is strictly contained within its boundary (mice exactly on the boundary are not considered to be captured). You should calculate the maximum value of L that doesn't allow all the mice to be captured.
You will be given 4 vector <int>s xp, yp, xv and yv. The position of the mouse with index i is given by (xp[i], yp[i]) and its velocity by (xv[i], yv[i]). The position of the mouse at time t will therefore be (xp[i] + xv[i]*t, yp[i] + yv[i]*t). Return a double giving the length of the side of the largest cage that cannot capture all the mice at any time t ≥ 0.

DEFINITION
Class:CatchTheMice
Method:largestCage
Parameters:vector <int>, vector <int>, vector <int>, vector <int>
Returns:double
Method signature:double largestCage(vector <int> xp, vector <int> yp, vector <int> xv, vector <int> yv)


NOTES
-Your return value must be accurate to an absolute or relative tolerance of 1e-9.


CONSTRAINTS
-xp, yp, xv and yv will contain between 2 and 50 elements, inclusive.
-xp, yp, xv and yv will contain the same number of elements.
-Each element of xp, yp, xv and yv will be between -1000 and 1000, inclusive.
-At no point in time t ≥ 0 will any two mice occupy the same point in space.


EXAMPLES

0)
{0,10}
{0,10}
{10,-10}
{0,0}

Returns: 10.0

A cage with side length greater than 10 would be able to catch both the mice at any time before t = 1.

1)
{0,10,0}
{0,0,10}
{1,-6,4}
{4,5,-4}

Returns: 3.0

At time t = 1, the mice are at positions (1, 4), (4, 5) and (4, 6). At this point in time any cage with an edge length larger than 3 would be able to catch them. This is the point in time when the mice are closest together.

2)
{50,10,30,15}
{-10,30,20,40}
{-5,-10,-15,-5}
{40,-10,-1,-50}

Returns: 40.526315789473685



3)
{0,10,10,0}
{0,0,10,10}
{1,0,-1,0}
{0,1,0,-1}

Returns: 10.0



4)
{13,50,100,40,-100}
{20,20,-150,-40,63}
{4,50,41,-41,-79}
{1,1,1,3,-1}

Returns: 212.78688524590163



5)
{0,10}
{0,0}
{5,5}
{3,3}

Returns: 10.0



6)
{-49,-463,-212,-204,-557,-67,-374,-335,-590,-4}
{352,491,280,355,129,78,404,597,553,445}
{-82,57,-23,-32,89,-72,27,17,100,-94}
{-9,-58,9,-14,56,75,-32,-98,-81,-43}

Returns: 25.467532467532468

*/
// END CUT HERE

#line 101 "CatchTheMice.cpp"
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

class CatchTheMice {
	public:
	double largestCage(vector <int> xp, vector <int> yp, vector <int> xv, vector <int> yv) {
		
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
	int xp_[] = {0,10};
	  vector <int> xp(xp_, xp_+sizeof(xp_)/sizeof(*xp_)); 
	int yp_[] = {0,10};
	  vector <int> yp(yp_, yp_+sizeof(yp_)/sizeof(*yp_)); 
	int xv_[] = {10,-10};
	  vector <int> xv(xv_, xv_+sizeof(xv_)/sizeof(*xv_)); 
	int yv_[] = {0,0};
	  vector <int> yv(yv_, yv_+sizeof(yv_)/sizeof(*yv_)); 
	double RetVal = 10.0; 
	return verify_case(RetVal, CatchTheMice().largestCage(xp, yp, xv, yv)); }
int Test_(Case_<1>) {
	timer_clear();
	int xp_[] = {0,10,0};
	  vector <int> xp(xp_, xp_+sizeof(xp_)/sizeof(*xp_)); 
	int yp_[] = {0,0,10};
	  vector <int> yp(yp_, yp_+sizeof(yp_)/sizeof(*yp_)); 
	int xv_[] = {1,-6,4};
	  vector <int> xv(xv_, xv_+sizeof(xv_)/sizeof(*xv_)); 
	int yv_[] = {4,5,-4};
	  vector <int> yv(yv_, yv_+sizeof(yv_)/sizeof(*yv_)); 
	double RetVal = 3.0; 
	return verify_case(RetVal, CatchTheMice().largestCage(xp, yp, xv, yv)); }
int Test_(Case_<2>) {
	timer_clear();
	int xp_[] = {50,10,30,15};
	  vector <int> xp(xp_, xp_+sizeof(xp_)/sizeof(*xp_)); 
	int yp_[] = {-10,30,20,40};
	  vector <int> yp(yp_, yp_+sizeof(yp_)/sizeof(*yp_)); 
	int xv_[] = {-5,-10,-15,-5};
	  vector <int> xv(xv_, xv_+sizeof(xv_)/sizeof(*xv_)); 
	int yv_[] = {40,-10,-1,-50};
	  vector <int> yv(yv_, yv_+sizeof(yv_)/sizeof(*yv_)); 
	double RetVal = 40.526315789473685; 
	return verify_case(RetVal, CatchTheMice().largestCage(xp, yp, xv, yv)); }
int Test_(Case_<3>) {
	timer_clear();
	int xp_[] = {0,10,10,0};
	  vector <int> xp(xp_, xp_+sizeof(xp_)/sizeof(*xp_)); 
	int yp_[] = {0,0,10,10};
	  vector <int> yp(yp_, yp_+sizeof(yp_)/sizeof(*yp_)); 
	int xv_[] = {1,0,-1,0};
	  vector <int> xv(xv_, xv_+sizeof(xv_)/sizeof(*xv_)); 
	int yv_[] = {0,1,0,-1};
	  vector <int> yv(yv_, yv_+sizeof(yv_)/sizeof(*yv_)); 
	double RetVal = 10.0; 
	return verify_case(RetVal, CatchTheMice().largestCage(xp, yp, xv, yv)); }
int Test_(Case_<4>) {
	timer_clear();
	int xp_[] = {13,50,100,40,-100};
	  vector <int> xp(xp_, xp_+sizeof(xp_)/sizeof(*xp_)); 
	int yp_[] = {20,20,-150,-40,63};
	  vector <int> yp(yp_, yp_+sizeof(yp_)/sizeof(*yp_)); 
	int xv_[] = {4,50,41,-41,-79};
	  vector <int> xv(xv_, xv_+sizeof(xv_)/sizeof(*xv_)); 
	int yv_[] = {1,1,1,3,-1};
	  vector <int> yv(yv_, yv_+sizeof(yv_)/sizeof(*yv_)); 
	double RetVal = 212.78688524590163; 
	return verify_case(RetVal, CatchTheMice().largestCage(xp, yp, xv, yv)); }
int Test_(Case_<5>) {
	timer_clear();
	int xp_[] = {0,10};
	  vector <int> xp(xp_, xp_+sizeof(xp_)/sizeof(*xp_)); 
	int yp_[] = {0,0};
	  vector <int> yp(yp_, yp_+sizeof(yp_)/sizeof(*yp_)); 
	int xv_[] = {5,5};
	  vector <int> xv(xv_, xv_+sizeof(xv_)/sizeof(*xv_)); 
	int yv_[] = {3,3};
	  vector <int> yv(yv_, yv_+sizeof(yv_)/sizeof(*yv_)); 
	double RetVal = 10.0; 
	return verify_case(RetVal, CatchTheMice().largestCage(xp, yp, xv, yv)); }
int Test_(Case_<6>) {
	timer_clear();
	int xp_[] = {-49,-463,-212,-204,-557,-67,-374,-335,-590,-4};
	  vector <int> xp(xp_, xp_+sizeof(xp_)/sizeof(*xp_)); 
	int yp_[] = {352,491,280,355,129,78,404,597,553,445};
	  vector <int> yp(yp_, yp_+sizeof(yp_)/sizeof(*yp_)); 
	int xv_[] = {-82,57,-23,-32,89,-72,27,17,100,-94};
	  vector <int> xv(xv_, xv_+sizeof(xv_)/sizeof(*xv_)); 
	int yv_[] = {-9,-58,9,-14,56,75,-32,-98,-81,-43};
	  vector <int> yv(yv_, yv_+sizeof(yv_)/sizeof(*yv_)); 
	double RetVal = 25.467532467532468; 
	return verify_case(RetVal, CatchTheMice().largestCage(xp, yp, xv, yv)); }

template<int N> void Run_() { cerr << "Test Case #" << N << "..." << flush; Test_(Case_<N>()); Run_<sizeof(Test_(Case_<N+1>()))==1 ? -1 : N+1>(); }
template<>      void Run_<-1>() {}
int main() { Run_<0>(); }
// END CUT HERE

