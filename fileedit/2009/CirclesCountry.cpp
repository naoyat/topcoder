#line 2 "CirclesCountry.cpp"
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
typedef vector<string> vs;
typedef vector<long long> vll;
#define sz(a)  int((a).size())
#define pb  push_back
#define all(c)  (c).begin(),(c).end()
#define mset(arr,val)  memset(arr,val,sizeof(arr))
#define tr(c,i)  for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); i++)
#define rep(var,n)  for(int var=0;var<(n);var++)
#define forr(var,from,to) for(int var=(from);var<=(to);var++) 
#define found(s,e)  ((s).find(e)!=(s).end())
#define remove_(c,val) (c).erase(remove((c).begin(),(c).end(),(val)),(c).end())
#define lastc(str) (*((str).end()-1))

class CirclesCountry {
	public:
	int leastBorders(vector <int> X, vector <int> Y, vector <int> R, int x1, int y1, int x2, int y2) {
		
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
	int X_[] = {0};
	  vector <int> X(X_, X_+sizeof(X_)/sizeof(*X_)); 
	int Y_[] = {0};
	  vector <int> Y(Y_, Y_+sizeof(Y_)/sizeof(*Y_)); 
	int R_[] = {2};
	  vector <int> R(R_, R_+sizeof(R_)/sizeof(*R_)); 
	int x1 = -5; 
	int y1 = 1; 
	int x2 = 5; 
	int y2 = 1; 
	int RetVal = 0; 
	return verify_case(RetVal, CirclesCountry().leastBorders(X, Y, R, x1, y1, x2, y2)); }
int Test_(Case_<1>) {
	timer_clear();
	int X_[] = {0,-6,6};
	  vector <int> X(X_, X_+sizeof(X_)/sizeof(*X_)); 
	int Y_[] = {0,1,2};
	  vector <int> Y(Y_, Y_+sizeof(Y_)/sizeof(*Y_)); 
	int R_[] = {2,2,2};
	  vector <int> R(R_, R_+sizeof(R_)/sizeof(*R_)); 
	int x1 = -5; 
	int y1 = 1; 
	int x2 = 5; 
	int y2 = 1; 
	int RetVal = 2; 
	return verify_case(RetVal, CirclesCountry().leastBorders(X, Y, R, x1, y1, x2, y2)); }
int Test_(Case_<2>) {
	timer_clear();
	int X_[] = {1,-3,2,5,-4,12,12};
	  vector <int> X(X_, X_+sizeof(X_)/sizeof(*X_)); 
	int Y_[] = {1,-1,2,5,5,1,1};
	  vector <int> Y(Y_, Y_+sizeof(Y_)/sizeof(*Y_)); 
	int R_[] = {8,1,2,1,1,1,2};
	  vector <int> R(R_, R_+sizeof(R_)/sizeof(*R_)); 
	int x1 = -5; 
	int y1 = 1; 
	int x2 = 12; 
	int y2 = 1; 
	int RetVal = 3; 
	return verify_case(RetVal, CirclesCountry().leastBorders(X, Y, R, x1, y1, x2, y2)); }
int Test_(Case_<3>) {
	timer_clear();
	int X_[] = {-3,2,2,0,-4,12,12,12};
	  vector <int> X(X_, X_+sizeof(X_)/sizeof(*X_)); 
	int Y_[] = {-1,2,3,1,5,1,1,1};
	  vector <int> Y(Y_, Y_+sizeof(Y_)/sizeof(*Y_)); 
	int R_[] = {1,3,1,7,1,1,2,3};
	  vector <int> R(R_, R_+sizeof(R_)/sizeof(*R_)); 
	int x1 = 2; 
	int y1 = 3; 
	int x2 = 13; 
	int y2 = 2; 
	int RetVal = 5; 
	return verify_case(RetVal, CirclesCountry().leastBorders(X, Y, R, x1, y1, x2, y2)); }
int Test_(Case_<4>) {
	timer_clear();
	int X_[] = {-107,-38,140,148,-198,172,-179,148,176,153,-56,-187};
	  vector <int> X(X_, X_+sizeof(X_)/sizeof(*X_)); 
	int Y_[] = {175,-115,23,-2,-49,-151,-52,42,0,68,109,-174};
	  vector <int> Y(Y_, Y_+sizeof(Y_)/sizeof(*Y_)); 
	int R_[] = {135,42,70,39,89,39,43,150,10,120,16,8};
	  vector <int> R(R_, R_+sizeof(R_)/sizeof(*R_)); 
	int x1 = 102; 
	int y1 = 16; 
	int x2 = 19; 
	int y2 = -108; 
	int RetVal = 3; 
	return verify_case(RetVal, CirclesCountry().leastBorders(X, Y, R, x1, y1, x2, y2)); }

template<int N> void Run_() { cerr << "Test Case #" << N << "..." << flush; Test_(Case_<N>()); Run_<sizeof(Test_(Case_<N+1>()))==1 ? -1 : N+1>(); }
template<>      void Run_<-1>() {}
int main() { Run_<0>(); }
// END CUT HERE


// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// Circles Country is a country that contains several circular-shaped districts.  Some districts may be situated inside other districts, but their borders do not intersect or touch.  Qatam is a resident of Circles Country.  When he travels between two locations, he always tries to cross the fewest number of district borders as possible because crossing borders is usually a laborious task.

Imagine Circles Country as an infinite plane.  You are given vector <int>s X, Y and R, where (X[i], Y[i]) are the coordinates of the i-th district's center and R[i] is its radius.  Qatam is currently at point (x1,y1) and he needs to get to point (x2,y2).  Neither of these points lies on a district border.  Return the minimal number of district borders he must cross to get to his destination.


DEFINITION
Class:CirclesCountry
Method:leastBorders
Parameters:vector <int>, vector <int>, vector <int>, int, int, int, int
Returns:int
Method signature:int leastBorders(vector <int> X, vector <int> Y, vector <int> R, int x1, int y1, int x2, int y2)


CONSTRAINTS
-X will contain between 1 and 50 elements, inclusive.
-X, Y and R will each contain the same number of elements.
-Each element of X and Y will be between -1000 and 1000, inclusive.
-Each element of R will be between 1 and 1000, inclusive.
-x1, y1, x2 and y2 will be between -1000 and 1000, inclusive.
-No two circumferences will have common points.
-The points (x1,y1) and (x2,y2) will not lie on any of the circumferences.


EXAMPLES

0)
{0}
{0}
{2}
-5
1
5
1

Returns: 0



1)
{0,-6,6}
{0,1,2}
{2,2,2}
-5
1
5
1

Returns: 2



2)
{1,-3,2,5,-4,12,12}
{1,-1,2,5,5,1,1}
{8,1,2,1,1,1,2}
-5
1
12
1

Returns: 3



3)
{-3,2,2,0,-4,12,12,12}
{-1,2,3,1,5,1,1,1}
{1,3,1,7,1,1,2,3}
2
3
13
2

Returns: 5



4)
{-107,-38,140,148,-198,172,-179,148,176,153,-56,-187}
{175,-115,23,-2,-49,-151,-52,42,0,68,109,-174}
{135,42,70,39,89,39,43,150,10,120,16,8}
102
16
19
-108

Returns: 3

*/
// END CUT HERE
