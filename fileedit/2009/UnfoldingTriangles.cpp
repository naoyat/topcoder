#line 2 "UnfoldingTriangles.cpp"
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
#define all(c)  (c).begin(),(c).end()
#define rep(var,n)  for(int var=0;var<(n);var++)

class UnfoldingTriangles {
 public:
  int solve(vector<string> grid, int unfoldLimit) {
    int h=sz(grid),w=sz(grid[0]);
    int best=-1,s=0;
// BEGIN CUT HERE
    printf("Go [%dx%d, %d]\n", w,h, unfoldLimit);
// END CUT HERE
    for(int y=1;y<=h;y++) {
      for(int x=1;x<=w;x++) {
        int maxl=min(x,y);
        for(int l=1;l<=maxl;l++) {
          int unfold=0;
// BEGIN CUT HERE
          printf("trying (%d,%d),L=%d/%d...\n", x,y,l,maxl);
// END CUT HERE
          // ob
          rep(i,l){
            int x_=x-1-i, y_=y-l+i;
// BEGIN CUT HERE
            printf("  - ob %d,%d = %c\n", x_,y_,grid[y_][x_]);
// END CUT HERE
            if(grid[y_][x_]!='/') goto fail;
          }
          // in
          rep(i,l-1){
            rep(j,l-i-1){
              int x_=x-1-i, y_=y-1-j;
// BEGIN CUT HERE
              printf("  - in %d,%d = %c\n", x_,y_,grid[y_][x_]);
// END CUT HERE
              switch(grid[y_][x_]){
                case '.': goto fail;
                case '/': unfold++; break;
                case '#': break;
              }
              if (unfold>unfoldLimit) goto fail;
            }
          }
          // R
          if(x<w)
            rep(i,l){
              int x_=x,y_=y-1-i;
// BEGIN CUT HERE
              printf("  - R %d,%d = %c\n", x_,y_,grid[y_][x_]);
// END CUT HERE
              if(grid[y_][x_]=='#') goto fail;
            }
          // B
          if (y<h)
            rep(i,l){
              int x_=x-1-i,y_=y;
// BEGIN CUT HERE
              printf("  - B %d,%d = %c\n", x_,y_,grid[y_][x_]);
// END CUT HERE
              if(grid[y_][x_]=='#') goto fail;
            }
          s=l*(l+1)/2;
// BEGIN CUT HERE
          printf("(%d,%d),L=%d: unfold=%d/%d, s=%d\n", x,y,l, unfold,unfoldLimit, s);
// END CUT HERE
          if (s>best) best=s;
       fail:;
        }
      }
    }
    return best;
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
	string grid_[] = {".../",
 "../#",
 "./#/",
 "/#//"};
	  vector <string> grid(grid_, grid_+sizeof(grid_)/sizeof(*grid_)); 
	int unfoldLimit = 4; 
	int RetVal = 10; 
	return verify_case(RetVal, UnfoldingTriangles().solve(grid, unfoldLimit)); }
int Test_(Case_<1>) {
	timer_clear();
	string grid_[] = {".../",
 "../#",
 "./#/",
 "/#//"};
	  vector <string> grid(grid_, grid_+sizeof(grid_)/sizeof(*grid_)); 
	int unfoldLimit = 2; 
	int RetVal = 3; 
	return verify_case(RetVal, UnfoldingTriangles().solve(grid, unfoldLimit)); }
int Test_(Case_<2>) {
	timer_clear();
	string grid_[] = {"////",
 "////",
 "////",
 "////"};
	  vector <string> grid(grid_, grid_+sizeof(grid_)/sizeof(*grid_)); 
	int unfoldLimit = 5; 
	int RetVal = 6; 
	return verify_case(RetVal, UnfoldingTriangles().solve(grid, unfoldLimit)); }
int Test_(Case_<3>) {
	timer_clear();
	string grid_[] = {".....#...",
 "....###.."};
	  vector <string> grid(grid_, grid_+sizeof(grid_)/sizeof(*grid_)); 
	int unfoldLimit = 10; 
	int RetVal = -1; 
	return verify_case(RetVal, UnfoldingTriangles().solve(grid, unfoldLimit)); }
int Test_(Case_<4>) {
	timer_clear();
	string grid_[] = {"#//#",
 "#//#",
 "####",
 "///#"};
	  vector <string> grid(grid_, grid_+sizeof(grid_)/sizeof(*grid_)); 
	int unfoldLimit = 4; 
	int RetVal = 1; 
	return verify_case(RetVal, UnfoldingTriangles().solve(grid, unfoldLimit)); }
int Test_(Case_<5>) {
	timer_clear();
	string grid_[] = {".../.../",
 "../#..//",
 "./.#.///",
 "/###...."};
	  vector <string> grid(grid_, grid_+sizeof(grid_)/sizeof(*grid_)); 
	int unfoldLimit = 3; 
	int RetVal = 6; 
	return verify_case(RetVal, UnfoldingTriangles().solve(grid, unfoldLimit)); }

template<int N> void Run_() { cerr << "Test Case #" << N << "..." << flush; Test_(Case_<N>()); Run_<sizeof(Test_(Case_<N+1>()))==1 ? -1 : N+1>(); }
template<>      void Run_<-1>() {}
int main() { Run_<0>(); }
// END CUT HERE


// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// NOTE: This problem statement contains images that may not display properly if viewed outside of the applet.


You are given a white rectangular grid made up of square cells.  Some cells contain black squares, and some contain black squares that have been folded in half to form right triangles, such that one of their sides matches the grid line to the right of the cell and another side of the triangle matches the grid line to the bottom of the cell.  At most unfoldLimit of these triangles can be unfolded to become black squares. However, black squares cannot be folded to become triangles.

We are interested in forming the largest possible proper black triangle in the grid using the aforementioned operations.  A black triangle is considered proper within a grid configuration if no other black shape shares a line segment with it.  However, black shapes may still share one or more points with the triangle. The size of a triangle is defined as the number of grid cells that are currently occupied by the triangle.

The grid will be given as a vector <string>, where the j-th character of the i-th element represents the cell at row i, column j.  '.' represents an empty cell, '#' represents a cell containing a black square, and '/' represents a cell containing a black triangle.  Return the largest possible size for a proper triangle that can be formed in the given grid by unfolding at most unfoldLimit triangles. In case it is not possible to form a proper black triangle in the grid, return -1.

For example, consider the following input grid:





If unfoldLimit is greater than or equal to 3, the largest possible proper triangle size is 10:
   



If unfoldLimit is 2, the largest possible proper triangle size is 3:
   
Larger black triangles are possible, but they would not be proper triangles.

DEFINITION
Class:UnfoldingTriangles
Method:solve
Parameters:vector <string>, int
Returns:int
Method signature:int solve(vector <string> grid, int unfoldLimit)


CONSTRAINTS
-grid will contain between 1 and 50 elements, inclusive.
-Each element of grid will contain between 1 and 50 characters, inclusive.
-Each element of grid will contain the same number of characters.
-Each character in grid will be '.', '#' or '/'.
-unfoldLimit will be between 1 and 2500, inclusive.


EXAMPLES

0)
{".../",
 "../#",
 "./#/",
 "/#//"}
4

Returns: 10



1)
{".../",
 "../#",
 "./#/",
 "/#//"}
2

Returns: 3

Examples 1 and 0 were explained in the problem statement.

2)
{"////",
 "////",
 "////",
 "////"}
5

Returns: 6



3)
{".....#...",
 "....###.."}
10

Returns: -1



4)
{"#//#",
 "#//#",
 "####",
 "///#"}
4

Returns: 1



5)
{".../.../",
 "../#..//",
 "./.#.///",
 "/###...."}
3

Returns: 6



*/
// END CUT HERE
