#line 2 "MaximizeSquares.cpp"
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
using namespace std;
// BEGIN CUT HERE
#include "cout.h"
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
// END CUT HERE

class MaximizeSquares {
 public:
  int squareCount(int N) {
    if(N<4) return 0;
    int wmin=(int)sqrt(N),wmax=N/2;
    int cmax=wmax-1;
    for(int w=wmin;w<=wmax;w++){
      int c=0;
      int h0=N/w;
      int w0=N-w*h0;
      if(w0==1) w0=0;
      int h=h0+((w0==0)?0:1);
      int rmax=min(w,h);
      //printf("w,h=%d,%d  w0,h0=%d,%d  rmax=%d\n", w,h, w0,h0, rmax);
      for(int r=1;r<=rmax;r++){
        if(w-1>=r && h0-1>=r) c += (w-r)*(h0-r);
        if(w0-1>=r && h-1>=r) c += (w0-r);
      }
      //printf(" => c=%d\n", c);
      cmax = max(cmax,c);
    }
    return cmax;
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
	int N = 4; 
	int RetVal = 1; 
	return verify_case(RetVal, MaximizeSquares().squareCount(N)); }
int Test_(Case_<1>) {
	timer_clear();
	int N = 5; 
	int RetVal = 1; 
	return verify_case(RetVal, MaximizeSquares().squareCount(N)); }
int Test_(Case_<2>) {
	timer_clear();
	int N = 6; 
	int RetVal = 2; 
	return verify_case(RetVal, MaximizeSquares().squareCount(N)); }
int Test_(Case_<3>) {
	timer_clear();
	int N = 16; 
	int RetVal = 14; 
	return verify_case(RetVal, MaximizeSquares().squareCount(N)); }
int Test_(Case_<4>) {
	timer_clear();
	int N = 115; 
	int RetVal = 340; 
	return verify_case(RetVal, MaximizeSquares().squareCount(N)); }
int Test_(Case_<5>) {
	timer_clear();
	int N = 34; 
	int RetVal = 46;
	return verify_case(RetVal, MaximizeSquares().squareCount(N)); }

template<int N> void Run_() { cerr << "Test Case #" << N << "..." << flush; Test_(Case_<N>()); Run_<sizeof(Test_(Case_<N+1>()))==1 ? -1 : N+1>(); }
template<>      void Run_<-1>() {}
int main() { Run_<0>(); }
// END CUT HERE


// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// Consider an arrangement of N points on the cartesian plane. The "square count" of the points is the total number of distinct squares with sides parallel to the coordinate axes which can be built using 4 different points as vertices.  Your task is to return the maximum square count, considering all possible arrangements of N points on the plane.

DEFINITION
Class:MaximizeSquares
Method:squareCount
Parameters:int
Returns:int
Method signature:int squareCount(int N)


NOTES
-Two squares are distinct if at least one of their corners is in a different location.


CONSTRAINTS
-N will be between 0 and 1000000, inclusive.


EXAMPLES

0)
4

Returns: 1

Clearly, we can only make one square out of 4 points.

1)
5

Returns: 1

No matter where we place a fifth point, we can't get any extra squares.

2)
6

Returns: 2

We can get 2 squares by placing the points in the shape of a rectangle.

3)
16

Returns: 14



4)
115

Returns: 340



*/
// END CUT HERE
