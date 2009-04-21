#line 2 "BestView.cpp"
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

class BestView {
 public:
  int numberOfBuildings(vector<int> heights) {
	int n=sz(heights);
    if(n==1) return 0; if(n==2) return 1;
    double fmin=-1e100;
    int nmmax=2;
    rep(i,n){
      int h=heights[i]; //i,h
      double lastmax = fmin;
      int nm=0;
      for(int j=i-1; j>=0; j--){
        int jh=heights[j];
        double an = (double)(jh-h) / (i-j);
        if (an > lastmax) {nm++; lastmax = an;}
      }
      lastmax = fmin;
      for(int j=i+1; j<n; j++){
        int jh=heights[j];
        double an = (double)(jh-h) / (j-i);
        if (an > lastmax) {nm++; lastmax = an;}
      }
      if (nm>nmmax) nmmax=nm;
    }
    return nmmax;
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
	int heights_[] = {10};
	  vector <int> heights(heights_, heights_+sizeof(heights_)/sizeof(*heights_)); 
	int RetVal = 0; 
	return verify_case(RetVal, BestView().numberOfBuildings(heights)); }
int Test_(Case_<1>) {
	timer_clear();
	int heights_[] = {5,5,5,5};
	  vector <int> heights(heights_, heights_+sizeof(heights_)/sizeof(*heights_)); 
	int RetVal = 2; 
	return verify_case(RetVal, BestView().numberOfBuildings(heights)); }
int Test_(Case_<2>) {
	timer_clear();
	int heights_[] = {1,2,7,3,2};
	  vector <int> heights(heights_, heights_+sizeof(heights_)/sizeof(*heights_)); 
	int RetVal = 4; 
	return verify_case(RetVal, BestView().numberOfBuildings(heights)); }
int Test_(Case_<3>) {
	timer_clear();
	int heights_[] = {1,5,3,2,6,3,2,6,4,2,5,7,3,1,5};
	  vector <int> heights(heights_, heights_+sizeof(heights_)/sizeof(*heights_)); 
	int RetVal = 7; 
	return verify_case(RetVal, BestView().numberOfBuildings(heights)); }
int Test_(Case_<4>) {
	timer_clear();
	int heights_[] = {1000000000,999999999,999999998,999999997,999999996,1,2,3,4,5};
	  vector <int> heights(heights_, heights_+sizeof(heights_)/sizeof(*heights_)); 
	int RetVal = 6; 
	return verify_case(RetVal, BestView().numberOfBuildings(heights)); }
int Test_(Case_<5>) {
	timer_clear();
	int heights_[] = {244645169,956664793,752259473,577152868,605440232,569378507,111664772,653430457,454612157,397154317};
	  vector <int> heights(heights_, heights_+sizeof(heights_)/sizeof(*heights_)); 
	int RetVal = 7; 
	return verify_case(RetVal, BestView().numberOfBuildings(heights)); }

template<int N> void Run_() { cerr << "Test Case #" << N << "..." << flush; Test_(Case_<N>()); Run_<sizeof(Test_(Case_<N+1>()))==1 ? -1 : N+1>(); }
template<>      void Run_<-1>() {}
int main() { Run_<0>(); }
// END CUT HERE


// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// There are several skyscrapers arranged in a row.  You're interested in finding the one from which the maximal number of other skyscrapers can be seen.  The i-th skyscraper can be represented as a line segment on a plane with endpoints (i, 0) and (i, heights[i]).  A skyscraper can be seen from the roof of another skyscraper if a line segment connecting their roofs does not intersect with or touch any other skyscraper.  Return the maximal number of other skyscrapers that can be seen from the roof of some skyscraper.

DEFINITION
Class:BestView
Method:numberOfBuildings
Parameters:vector <int>
Returns:int
Method signature:int numberOfBuildings(vector <int> heights)


CONSTRAINTS
-heights will contain between 1 and 50 elements, inclusive. 
-Each element of heights will be between 1 and 1,000,000,000, inclusive.


EXAMPLES

0)
{10}

Returns: 0

There's only a single skyscraper, so you can see no other skyscrapers from its roof.


1)
{5,5,5,5}

Returns: 2

From each skyscraper, you can only see its adjacent neighbors.

2)
{1,2,7,3,2}

Returns: 4

You can see all the other skyscrapers from the central one.

3)
{1,5,3,2,6,3,2,6,4,2,5,7,3,1,5}

Returns: 7

You can see seven skyscrapers from the skyscraper with height 7:


4)
{1000000000,999999999,999999998,999999997,999999996,1,2,3,4,5}

Returns: 6

You can see 6 skyscrapers from the skyscraper with height 999999996 - the nearest one to the left and all 5 skyscrapers to the right.

5)
{244645169,956664793,752259473,577152868,605440232,569378507,111664772,653430457,454612157,397154317}

Returns: 7



*/
// END CUT HERE
