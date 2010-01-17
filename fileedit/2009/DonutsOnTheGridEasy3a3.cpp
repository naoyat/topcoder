#line 2 "DonutsOnTheGridEasy.cpp"
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
#define FOR(var,from,to) for(int var=(from);var<=(to);var++)
#define RFOR(var,from,to) for(int var=(to);var>=(from);var--)
#define found(s,e)  ((s).find(e)!=(s).end())
#define mset(arr,val)  memset(arr,val,sizeof(arr))

char z[50][50][51][51], mp[50][50][51][51];

class DonutsOnTheGridEasy {
  vector<string> gr;
  int R,C;
  
  int isZeroShape(int r,int c,int h,int w){
    if (h<3 || w<3) return 0;
    if (z[r][c][h][w]>=0) return z[r][c][h][w];

    int re=1;
    
    rep(j,h) { int y=r+j;
      if (gr[y][c]=='.') {re=0; goto end;}
      if (gr[y][c+(w-1)]=='.') {re=0; goto end;}
    }
    rep(i,w) { int x=c+i;
      if (gr[r][x]=='.') {re=0; goto end;}
      if (gr[r+(h-1)][x]=='.') {re=0; goto end;}
    }
 end:
    return z[r][c][h][w] = re;
  }

  void pp(vector<vector<int> > g){
    rep(r,sz(g)){
      rep(c,sz(g[0])){
        if (g[r][c]>=0) {
          printf(" %2d", g[r][c]);
        } else {
          printf(" --");
        }
      }
      printf("\n");
    }
  }
  
  int sub(int r,int c,int h,int w){
    if (h<3 || w<3) return 0;
    if (mp[r][c][h][w]>=0) return mp[r][c][h][w];

    int ct=0; if (isZeroShape(r,c,h,w)) ct=1+sub(r+1,c+1,h-2,w-2);
    FOR(hj,1,h-1) ct = max(ct, max(sub(r,c,hj,w),sub(r+hj,c,h-hj,w)));
    FOR(wj,1,w-1) ct = max(ct, max(sub(r,c,h,wj),sub(r,c+wj,h,w-wj)));

    mp[r][c][h][w] = ct;
    return ct;
  }
 public:
  int calc(vector<string> grid) {
    R=sz(grid), C=sz(grid[0]);
    gr = grid; //cout << gr << endl;

    //    printf("|| 0,0,%d,%d\n", R,C);
    //    rep(r,50)rep(c,50)rep(w,51)rep(h,51) z[r][c][h][w] = mp[r][c][h][w] = -1;
    memset(z,255,sizeof(z));
    memset(mp,255,sizeof(mp));

    return sub(0,0,R,C);
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
	string grid_[] = {"0000000"
                      ,"0.....0"
                      ,"0.00000"
                      ,"0.0..00"
                      ,"0.00000"
                      ,"0.....0"
                      ,"0000000"};
    vector <string> grid(grid_, grid_+sizeof(grid_)/sizeof(*grid_)); 
	int RetVal = 2; 
	return verify_case(RetVal, DonutsOnTheGridEasy().calc(grid)); }
int Test_(Case_<1>) {
	timer_clear();
	string grid_[] = {"000"
                      ,"0.0"
                      ,"000"};
	  vector <string> grid(grid_, grid_+sizeof(grid_)/sizeof(*grid_)); 
	int RetVal = 1; 
	return verify_case(RetVal, DonutsOnTheGridEasy().calc(grid)); }
int Test_(Case_<2>) {
	timer_clear();
	string grid_[] = {"..."
                      ,"..."
                      ,"..."};
	  vector <string> grid(grid_, grid_+sizeof(grid_)/sizeof(*grid_)); 
	int RetVal = 0; 
	return verify_case(RetVal, DonutsOnTheGridEasy().calc(grid)); }
int Test_(Case_<3>) {
	timer_clear();
	string grid_[] = {"00.000"
,"00.000"
,"0.00.0"
,"000.00"};
	  vector <string> grid(grid_, grid_+sizeof(grid_)/sizeof(*grid_)); 
	int RetVal = 0; 
	return verify_case(RetVal, DonutsOnTheGridEasy().calc(grid)); }
int Test_(Case_<4>) {
	timer_clear();
	string grid_[] = {"0000000....",
                      "0000000....",
                      "0000000.000",
                      "0000000.0.0",
                      "0000000.000",
                      "0000000....",
                      "0000000...."};
	  vector <string> grid(grid_, grid_+sizeof(grid_)/sizeof(*grid_)); 
	int RetVal = 3; 
	return verify_case(RetVal, DonutsOnTheGridEasy().calc(grid)); }
/*
int Test_(Case_<5>) {
	timer_clear();
	string grid_[] = {
      "00000000000000000000000000000000000000000000000000",
      "00000000000000000000000000000000000000000000000000",
      "00000000000000000000000000000000000000000000000000",
      "00000000000000000000000000000000000000000000000000",
      "00000000000000000000000000000000000000000000000000",
      "00000000000000000000000000000000000000000000000000",
      "00000000000000000000000000000000000000000000000000",
      "00000000000000000000000000000000000000000000000000",
      "00000000000000000000000000000000000000000000000000",
      "00000000000000000000000000000000000000000000000000",
      "00000000000000000000000000000000000000000000000000",
      "00000000000000000000000000000000000000000000000000",
      "00000000000000000000000000000000000000000000000000",
      "00000000000000000000000000000000000000000000000000",
      "00000000000000000000000000000000000000000000000000",
      "00000000000000000000000000000000000000000000000000",
      "00000000000000000000000000000000000000000000000000",
      "00000000000000000000000000000000000000000000000000",
      "00000000000000000000000000000000000000000000000000",
      "00000000000000000000000000000000000000000000000000",
      "00000000000000000000000000000000000000000000000000",
      "00000000000000000000000000000000000000000000000000",
      "00000000000000000000000000000000000000000000000000",
      "00000000000000000000000000000000000000000000000000",
      "00000000000000000000000000000000000000000000000000",
      "00000000000000000000000000000000000000000000000000",
      "00000000000000000000000000000000000000000000000000",
      "00000000000000000000000000000000000000000000000000",
      "00000000000000000000000000000000000000000000000000",
      "00000000000000000000000000000000000000000000000000",
      "00000000000000000000000000000000000000000000000000",
      "00000000000000000000000000000000000000000000000000",
      "00000000000000000000000000000000000000000000000000",
      "00000000000000000000000000000000000000000000000000",
      "00000000000000000000000000000000000000000000000000",
      "00000000000000000000000000000000000000000000000000",
      "00000000000000000000000000000000000000000000000000",
      "00000000000000000000000000000000000000000000000000",
      "00000000000000000000000000000000000000000000000000",
      "00000000000000000000000000000000000000000000000000",
      "00000000000000000000000000000000000000000000000000",
      "00000000000000000000000000000000000000000000000000",
      "00000000000000000000000000000000000000000000000000",
      "00000000000000000000000000000000000000000000000000",
      "00000000000000000000000000000000000000000000000000",
      "00000000000000000000000000000000000000000000000000",
      "00000000000000000000000000000000000000000000000000",
      "00000000000000000000000000000000000000000000000000",
      "00000000000000000000000000000000000000000000000000",
      "00000000000000000000000000000000000000000000000000"};
	  vector <string> grid(grid_, grid_+sizeof(grid_)/sizeof(*grid_)); 
	int RetVal = 3; 
	return verify_case(RetVal, DonutsOnTheGridEasy().calc(grid)); }
*/
template<int N> void Run_() { cerr << "Test Case #" << N << "..." << flush; Test_(Case_<N>()); Run_<sizeof(Test_(Case_<N+1>()))==1 ? -1 : N+1>(); }
template<>      void Run_<-1>() {}
int main() { Run_<0>(); }
// END CUT HERE


// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// Petya likes donuts. He tries to find them everywhere. For example if he is given a grid where each cell contains a '0' (zero) or '.' he will construct donuts from the cells.
To make the donuts:

Petya first selects a rectangle of cells of width, w, and height, h, where both are at least 3.
Then he removes a rectangular hole of width w-2 and height h-2 centered in the larger rectangle.
For the remaining cells (a closed rectangular ring) to be a valid donut, all of the cells must contain '0' (because donuts are shaped like zeros). Cells in the hole can contain anything since they are not part of the donut.

An example of large donut containing a smaller donut.

..........
.00000000.
.0......0.
.0.0000.0.
.0.0..0.0.
.0.0..0.0.
.0.0000.0.
.0......0.
.00000000.
..........

Donuts may contain other donuts and donuts may touch, but the cells of one donut may not overlap the cells of another. Petra is most interested in donuts that contain other donuts. He first places one valid donut on the grid (if possible). He then places a valid donut in the hole of the first donut (if possible). He continues to place a donut into the hole of the most recently placed donut until this is no longer possible.

Your task is to find the maximum number of donuts that Petya can place on the grid as described such that each donut (except for the first) is contained within the previous donut. You are given grid, a String[], containing only '0' and '.' characters. The j-th character of the i-th element is the value at cell (i, j).


DEFINITION
Class:DonutsOnTheGridEasy
Method:calc
Parameters:vector <string>
Returns:int
Method signature:int calc(vector <string> grid)


CONSTRAINTS
-grid will have between 1 and 50 elements, inclusive.
-Each element of grid will have between 1 and 50 characters, inclusive.
-All elements of grid will have the same length.
-Each character of grid will be either '0' (zero) or '.'.


EXAMPLES

0)
{"0000000"
,"0.....0"
,"0.00000"
,"0.0..00"
,"0.00000"
,"0.....0"
,"0000000"}

Returns: 2



1)
{"000"
,"0.0"
,"000"}

Returns: 1



2)
{"..."
,"..."
,"..."}

Returns: 0



3)
{"00.000"
,"00.000"
,"0.00.0"
,"000.00"}

Returns: 0



4)
{"0000000....",
 "0000000....",
 "0000000.000",
 "0000000.0.0",
 "0000000.000",
 "0000000....",
 "0000000...."}

Returns: 3



*/
// END CUT HERE
