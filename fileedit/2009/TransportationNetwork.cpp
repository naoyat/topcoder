#line 2 "TransportationNetwork.cpp"
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

class TransportationNetwork {
  vector<int> cx, cy;
  double dist(int i,int j){
    return hypot(cx[j]-cx[i],cy[j]-cy[i]);
  }
 public:
  double minCost(vector<int> cityX, vector <int> cityY, double rC, double apC) {
	int n=sz(cityX);
    cx.resize(n); cy.resize(n); rep(i,n) { cx[i]=cityX[i]; cy[i]=cityY[i]; }

    double cost=apC*n;
    vector<bool> ap(n,true);

    priority_queue<pair<double,pair<int,int> > > pq;
    for(int i=0;i<n-1;i++){
      for(int j=i+1;j<n;j++){
        double d=dist(i,j), roadcost=rC*d;
        /*
        printf("city %d (%d,%d)-- city %d (%d,%d): distance = %g, road cost = %g, air cost = %g\n",
               i,cx[i],cy[i],
               j,cx[j],cy[j],
               d,
               roadcost, apC);
        */
        if (roadcost < apC) {
          pq.push(make_pair(-roadcost,make_pair(i,j)));
        }
      }
    }
    while(!pq.empty()){
      double roadcost = -pq.top().first;
      int c1 = pq.top().second.first, c2 = pq.top().second.second;
      pq.pop();
      if (ap[c1]) {
        ap[c1]=false;
        cost = cost - apC + roadcost;
        printf("(cut c1) city %d - %d : cost %g < %g\n", c1, c2, roadcost, apC);
      } else if (ap[c2]) {
        ap[c2]=false;
        cost = cost - apC + roadcost;
        printf("(cut c2) city %d - %d : cost %g < %g\n", c1,c2, roadcost, apC);
      } else {
      }
    }
    
    return cost;
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
	int cityX_[] = {0, 0, 400, 400};
	  vector <int> cityX(cityX_, cityX_+sizeof(cityX_)/sizeof(*cityX_)); 
	int cityY_[] = {0, 100, 0, 100};
	  vector <int> cityY(cityY_, cityY_+sizeof(cityY_)/sizeof(*cityY_)); 
	double roadCost = 1.0; 
	double airportCost = 150.0; 
	double RetVal = 500.0; 
	return verify_case(RetVal, TransportationNetwork().minCost(cityX, cityY, roadCost, airportCost)); }
int Test_(Case_<1>) {
	timer_clear();
	int cityX_[] = {0, 0, 400, 400, 2000};
	  vector <int> cityX(cityX_, cityX_+sizeof(cityX_)/sizeof(*cityX_)); 
	int cityY_[] = {0, 100, 0, 100, 2000};
	  vector <int> cityY(cityY_, cityY_+sizeof(cityY_)/sizeof(*cityY_)); 
	double roadCost = 1.0; 
	double airportCost = 500; 
	double RetVal = 1600.0; 
	return verify_case(RetVal, TransportationNetwork().minCost(cityX, cityY, roadCost, airportCost)); }
int Test_(Case_<2>) {
	timer_clear();
	int cityX_[] = {0, 100, 200, 300, 400,2000,2100,2200};
	  vector <int> cityX(cityX_, cityX_+sizeof(cityX_)/sizeof(*cityX_)); 
	int cityY_[] = {0, 100, 200, 300, 400,2000,2100,2200};
	  vector <int> cityY(cityY_, cityY_+sizeof(cityY_)/sizeof(*cityY_)); 
	double roadCost = 0.5; 
	double airportCost = 200; 
	double RetVal = 824.2640687119285; 
	return verify_case(RetVal, TransportationNetwork().minCost(cityX, cityY, roadCost, airportCost)); }
int Test_(Case_<3>) {
	timer_clear();
	int cityX_[] = {798, 915, 797, 463, 895, 523, 959, 702, 235, 523};
	  vector <int> cityX(cityX_, cityX_+sizeof(cityX_)/sizeof(*cityX_)); 
	int cityY_[] = {126, 25, 402, 45, 841, 762, 982, 605, 616, 78};
	  vector <int> cityY(cityY_, cityY_+sizeof(cityY_)/sizeof(*cityY_)); 
	double roadCost = 1.66; 
	double airportCost = 300; 
	double RetVal = 2727.2895312339606; 
	return verify_case(RetVal, TransportationNetwork().minCost(cityX, cityY, roadCost, airportCost)); }

template<int N> void Run_() { cerr << "Test Case #" << N << "..." << flush; Test_(Case_<N>()); Run_<sizeof(Test_(Case_<N+1>()))==1 ? -1 : N+1>(); }
template<>      void Run_<-1>() {}
int main() { Run_<0>(); }
// END CUT HERE


// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// Little Johnny has just been named minister of transportation for the republic of Feudalia. Feudalia currently lacks any means of transportation between its cities,  which has prompted Little Johnny to begin the planning process for a new transportation network for the twentieth century. To do so, Feudalia may build roads to connect pairs of cities and may also build airports within cities. Each airport costs airportCost to build. The construction of a road of length L will cost roadCost x L. A road must be a straight line between two cities. Although roads may cross, road travel between two cities must be done in a straight line. Air travel is possible between two cities if and only if both cities have an airport. Little Johnny requires every city in Feudalia to be reachable from all the other cities. Formally, a city B is reachable from a city A if any of the following conditions is true:

There is a straight line road between A and B.
Both A and B contain airports.
There exists some city C, such that B is reachable from C and C is reachable A.


You are given the coordinates of the cities as two vector <int> cityX and cityY such the i-th city will have cartesian coordinates (cityX[i], cityY[i]). You are also given roadCost and airportCost. Return the minimum cost the ministry of transportation will have to incur.

DEFINITION
Class:TransportationNetwork
Method:minCost
Parameters:vector <int>, vector <int>, double, double
Returns:double
Method signature:double minCost(vector <int> cityX, vector <int> cityY, double roadCost, double airportCost)


CONSTRAINTS
-cityX will have between 1 and 150 elements, inclusive.
-cityY will have the same number of elements as cityX.
-Each element of cityX and cityY will be between 0 and 1000000, inclusive.
-roadCost will be between 0 and 3.0, inclusive.
-airportCost will be between 0 and 10000000, inclusive.
-The locations of the cites will be distinct.


EXAMPLES

0)
{0, 0, 400, 400}
{0, 100, 0, 100}
1.0
150.0

Returns: 500.0

An optimal transportation network would be:
- Build roads connecting city 0 with city 1 and city 2 with city 3.
- Build airports at cities 0 and 2.

1)
{0, 0, 400, 400, 2000}
{0, 100, 0, 100, 2000}
1.0
500

Returns: 1600.0



2)
{0, 100, 200, 300, 400,2000,2100,2200}
{0, 100, 200, 300, 400,2000,2100,2200}
0.5
200

Returns: 824.2640687119285



3)
{798, 915, 797, 463, 895, 523, 959, 702, 235, 523}
{126, 25, 402, 45, 841, 762, 982, 605, 616, 78}
1.66
300

Returns: 2727.2895312339606



*/
// END CUT HERE
