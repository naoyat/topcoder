#line 2 "FeudaliasWar.cpp"
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

class FeudaliasWar {
	public:
	double getMinimumTime(vector <int> baseX, vector <int> baseY, vector <int> siloX, vector <int> siloY, int takeOffTime, int rechargeTime, int missileSpeed) {
		
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
	int baseX_[] = {0,0,50};
	  vector <int> baseX(baseX_, baseX_+sizeof(baseX_)/sizeof(*baseX_)); 
	int baseY_[] = {0,50,0};
	  vector <int> baseY(baseY_, baseY_+sizeof(baseY_)/sizeof(*baseY_)); 
	int siloX_[] = {50,0,1000};
	  vector <int> siloX(siloX_, siloX_+sizeof(siloX_)/sizeof(*siloX_)); 
	int siloY_[] = {50,1000,0};
	  vector <int> siloY(siloY_, siloY_+sizeof(siloY_)/sizeof(*siloY_)); 
	int takeOffTime = 30; 
	int rechargeTime = 20; 
	int missileSpeed = 1; 
	double RetVal = 91.5; 
	return verify_case(RetVal, FeudaliasWar().getMinimumTime(baseX, baseY, siloX, siloY, takeOffTime, rechargeTime, missileSpeed)); }
int Test_(Case_<1>) {
	timer_clear();
	int baseX_[] = {0,0,50};
	  vector <int> baseX(baseX_, baseX_+sizeof(baseX_)/sizeof(*baseX_)); 
	int baseY_[] = {0,50,0};
	  vector <int> baseY(baseY_, baseY_+sizeof(baseY_)/sizeof(*baseY_)); 
	int siloX_[] = {50,0,1000};
	  vector <int> siloX(siloX_, siloX_+sizeof(siloX_)/sizeof(*siloX_)); 
	int siloY_[] = {50,1000,0};
	  vector <int> siloY(siloY_, siloY_+sizeof(siloY_)/sizeof(*siloY_)); 
	int takeOffTime = 30; 
	int rechargeTime = 900; 
	int missileSpeed = 1; 
	double RetVal = 950.5; 
	return verify_case(RetVal, FeudaliasWar().getMinimumTime(baseX, baseY, siloX, siloY, takeOffTime, rechargeTime, missileSpeed)); }
int Test_(Case_<2>) {
	timer_clear();
	int baseX_[] = {0,2000,4000,6000,8000};
	  vector <int> baseX(baseX_, baseX_+sizeof(baseX_)/sizeof(*baseX_)); 
	int baseY_[] = {0,2000,4000,6000,8000};
	  vector <int> baseY(baseY_, baseY_+sizeof(baseY_)/sizeof(*baseY_)); 
	int siloX_[] = {0,2000,4000,6000};
	  vector <int> siloX(siloX_, siloX_+sizeof(siloX_)/sizeof(*siloX_)); 
	int siloY_[] = {2000,4000,6000,8000};
	  vector <int> siloY(siloY_, siloY_+sizeof(siloY_)/sizeof(*siloY_)); 
	int takeOffTime = 60; 
	int rechargeTime = 1000; 
	int missileSpeed = 50; 
	double RetVal = 1042.0; 
	return verify_case(RetVal, FeudaliasWar().getMinimumTime(baseX, baseY, siloX, siloY, takeOffTime, rechargeTime, missileSpeed)); }
int Test_(Case_<3>) {
	timer_clear();
	int baseX_[] = {1100,1200,1300,1400,1500,1600,1700,1800,1900};
	  vector <int> baseX(baseX_, baseX_+sizeof(baseX_)/sizeof(*baseX_)); 
	int baseY_[] = {2100,2300,2500,2700,2900,2700,2500,2300,2100};
	  vector <int> baseY(baseY_, baseY_+sizeof(baseY_)/sizeof(*baseY_)); 
	int siloX_[] = {1400,1400,1500,1600,1600};
	  vector <int> siloX(siloX_, siloX_+sizeof(siloX_)/sizeof(*siloX_)); 
	int siloY_[] = {3100,3300,3200,3100,3300};
	  vector <int> siloY(siloY_, siloY_+sizeof(siloY_)/sizeof(*siloY_)); 
	int takeOffTime = 20; 
	int rechargeTime = 300; 
	int missileSpeed = 100; 
	double RetVal = 306.7494291969649; 
	return verify_case(RetVal, FeudaliasWar().getMinimumTime(baseX, baseY, siloX, siloY, takeOffTime, rechargeTime, missileSpeed)); }

template<int N> void Run_() { cerr << "Test Case #" << N << "..." << flush; Test_(Case_<N>()); Run_<sizeof(Test_(Case_<N+1>()))==1 ? -1 : N+1>(); }
template<>      void Run_<-1>() {}
int main() { Run_<0>(); }
// END CUT HERE


// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// Feudalia's military is preparing a preemptive strike against Banania's military installations.  Feudalia has a number of missile silos.  Each silo has an unlimited number of missiles at its disposal, but can only fire a single missile at a time.  When a missile is fired, it requires takeOffTime seconds before it can take off from its silo.  Once it takes off, it requires distance/missileSpeed minutes to reach its target, where distance is the Euclidean distance between the silo and the target.  When the missile reaches its target, the target is instantly destroyed.  After a missile takes off, its silo requires rechargeTime minutes of preparation before it can launch another missile.

The general has ordered you to destroy all of Banania's military bases in as little time as possible.  You are given vector <int>s siloX, siloY, baseX and baseY which determine the locations of the missile silos and bases.  Feudalia's i-th missile silo is located at (siloX[i], siloY[i]) and Banania's j-th base is located at (baseX[j], baseY[j]).  Return the minimum time in minutes required to destroy all enemy bases.

DEFINITION
Class:FeudaliasWar
Method:getMinimumTime
Parameters:vector <int>, vector <int>, vector <int>, vector <int>, int, int, int
Returns:double
Method signature:double getMinimumTime(vector <int> baseX, vector <int> baseY, vector <int> siloX, vector <int> siloY, int takeOffTime, int rechargeTime, int missileSpeed)


NOTES
-The returned value must be accurate to within a relative or absolute value of 1E-9.


CONSTRAINTS
-takeOffTime will be between 1 and 60, inclusive.
-rechargeTime will be between 5 and 1000, inclusive.
-missileSpeed will be between 1 and 2000, inclusive.
-baseX will contain between 1 and 50 elements, inclusive.
-baseY will contain the same number of elements as baseX.
-siloX will contain between 1 and 50 elements, inclusive.
-siloY will contain the same number of elements as siloX.
-Each element of baseX, baseY, siloX and siloY will be between 0 and 1000000, inclusive.
-The locations for each base and silo will be distinct.


EXAMPLES

0)
{0,0,50}
{0,50,0}
{50,0,1000}
{50,1000,0}
30
20
1

Returns: 91.5

An optimal strategy would be:
00:00 : The silo at (50,50) launches an attack against the base at (0,0).
00:30 : The first missile finishes taking off.
20:30 : The silo at (50,50) launches its second missile, this time against the base at (0,50).
21:00 : The second missile finishes taking off.
41:30 : The silo at (50,50) launches its third missile, this time against the base at (50,0).
71:00 : The second missile hits the base at (0,50) (The distance was 50).
71:12.6 (Approx.) : The first missile hits the base at (0,0) (The distance was 70.710678119).
91:30 : The third missile hits the remaining base.

1)
{0,0,50}
{0,50,0}
{50,0,1000}
{50,1000,0}
30
900
1

Returns: 950.5

Since it now takes 15 hours to prepare a new missile, using the same silo against the three enemy bases is no longer the optimal strategy. Instead, each of the silos at (0,1000) and (1000,0) should target the closest base while the silo at (50,50) targets the base at (0,0).

2)
{0,2000,4000,6000,8000}
{0,2000,4000,6000,8000}
{0,2000,4000,6000}
{2000,4000,6000,8000}
60
1000
50

Returns: 1042.0



3)
{1100,1200,1300,1400,1500,1600,1700,1800,1900}
{2100,2300,2500,2700,2900,2700,2500,2300,2100}
{1400,1400,1500,1600,1600}
{3100,3300,3200,3100,3300}
20
300
100

Returns: 306.7494291969649



*/
// END CUT HERE
