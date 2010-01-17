#line 2 "FourBlocks.cpp"
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
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
#define sz(a)  int((a).size())
#define pb  push_back
#define all(c)  (c).begin(),(c).end()
#define tr(c,i)  for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); i++)
#define rep(var,n)  for(int var=0;var<(n);var++)
#define found(s,e)  ((s).find(e)!=(s).end())

typedef pair<int,int> ii;

class FourBlocks {
  bool hits(ii p1, ii p2){
    if (p1.first>p2.first) return hits(p2,p1);
    // p1 <= p2
    if (p1.first+2 <= p2.first) return false;
    if (p2.second <= p1.second-2 || p1.second+2 <= p2.second) return false;
    return true;
  }

  vector<ii> fs;
  vector<bool> mask;
  int n;
  int best;
  set<vector<bool> >v;
  
  void sub(){
    vi sc(n,0); int sct=0;
    int mn=0; rep(i,n) if(mask[i])mn++;
    if (mn==0) return;
    
    rep(i,n) {
      if (!mask[i]) continue;
      for(int j=i+1;j<n;j++){
        if (!mask[j]) continue;
        if (hits(fs[i],fs[j])) { sc[i]++; sc[j]++; sct++; }
      }
    }
    if (sct==0) {
      if (best<mn) best=mn;
      return;
    }
    // else
    int wo=0;
    rep(i,n) if (sc[i]>wo) wo=sc[i];
    rep(i,n) if (sc[i]==wo) {
      if(mask[i]) {
        mask[i]=false;
        //if(!found(v,mask)) {
        // v.insert(mask);
        sub();
        //}
        //mask[i]=true;
      }
    }
  }

 public:
  int maxScore(vector<string> grid) {
    int h=sz(grid),w=sz(grid[0]);
// BEGIN CUT HERE
    printf("maxScore(%dx%d)...\n",w,h);
// END CUT HERE
    rep(y,h)rep(x,w){
      if(x==w-1||y==h-1) continue;
      if(grid[y][x]=='1'||grid[y+1][x]=='1'||grid[y][x+1]=='1'||grid[y+1][x+1]=='1') continue;
      fs.pb(make_pair(x,y));
    }
    n=sz(fs);
// BEGIN CUT HERE
    cout << fs << endl;
// END CUT HERE
    mask.resize(n);
    rep(i,n) mask[i]=true;

    best=0;
    sub();
    int rest = h*w - best*4;
    return best*16 + rest;
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
	string grid_[] = {".....1..1..",
 "..1.....1.."};
	  vector <string> grid(grid_, grid_+sizeof(grid_)/sizeof(*grid_)); 
	int RetVal = 70; 
	return verify_case(RetVal, FourBlocks().maxScore(grid)); }
int Test_(Case_<1>) {
	timer_clear();
	string grid_[] = {"...1.",
 ".....",
 ".1..1",
 ".....",
 "1...."};
	  vector <string> grid(grid_, grid_+sizeof(grid_)/sizeof(*grid_)); 
	int RetVal = 73; 
	return verify_case(RetVal, FourBlocks().maxScore(grid)); }
int Test_(Case_<2>) {
	timer_clear();
	string grid_[] = {"...1.",
 ".1...",
 "..1.1",
 "1...."};
	  vector <string> grid(grid_, grid_+sizeof(grid_)/sizeof(*grid_)); 
	int RetVal = 20; 
	return verify_case(RetVal, FourBlocks().maxScore(grid)); }
int Test_(Case_<3>) {
	timer_clear();
	string grid_[] = {".....1...",
 ".....1...",
 "111111111",
 ".....1...",
 ".....1..."};
	  vector <string> grid(grid_, grid_+sizeof(grid_)/sizeof(*grid_)); 
	int RetVal = 117; 
	return verify_case(RetVal, FourBlocks().maxScore(grid)); }
int Test_(Case_<4>) {
	timer_clear();
	string grid_[] = {
 ".........................",
 ".........................",
 ".........................",
 ".........................",
 ".........................",
 ".........................",
 ".........................",
 ".........................",
 ".........................",
 "........................."};
	  vector <string> grid(grid_, grid_+sizeof(grid_)/sizeof(*grid_)); 
      int RetVal = 10+60*16;
	return verify_case(RetVal, FourBlocks().maxScore(grid)); }
/***
Problem: 500
Test Case: 6
Succeeded: No
Execution Time: 28 ms
Args:
{{"............1............", ".........................", "............1............", ".........................", ".........................", "............1............", ".........................", ".........................", ".........................", "............1............"}}

Expected:
970

Received:
958
--
Problem: 500
Test Case: 7
Succeeded: No
Execution Time: 8 ms
Args:
{{"......................", "......................", "......................", "....11111111111111....", ".........11111111111..", ".................1111.", "......................", "......................", "............1.........", ".............1........"}}

Expected:
700

Received:
688

 **/

template<int N> void Run_() { cerr << "Test Case #" << N << "..." << flush; Test_(Case_<N>()); Run_<sizeof(Test_(Case_<N+1>()))==1 ? -1 : N+1>(); }
template<>      void Run_<-1>() {}
int main() { Run_<0>(); }
// END CUT HERE


// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// NOTE: This problem statement contains images that may not display properly if viewed outside of the applet.

"4Blocks" is a two player cooperative game played on a special board.  The board is a grid composed of 1x1 square cells. There are two different kinds of blocks: '1' blocks and '4' blocks.  '1' blocks are 1x1, and '4' blocks are 2x2:





You must place blocks on the board so that their sides are aligned to the grid lines and no two blocks overlap.  The final score is the sum of the values in each cell.  '1' blocks are worth 1 point, and '4' blocks are worth 16 points because they cover 4 cells and each cell is worth 4 points.

Your friend has taken his turn and placed a number of '1' blocks on the board.  The current configuration is given in the vector <string> grid.  The j-th character of the i-th element of grid is '.' if the cell at row i, column j is empty, and '1' if your friend placed a '1' block in that cell.  It is now your turn, and you can place any number of '1' or '4' blocks on the board, but you cannot remove any of the blocks that have already been placed.  Return the maximum score that can be achieved.  For example, the following images show one possible starting state, and the optimal placement of blocks from that state:




The final score would be 4*16 + 6*1 = 70.

DEFINITION
Class:FourBlocks
Method:maxScore
Parameters:vector <string>
Returns:int
Method signature:int maxScore(vector <string> grid)


CONSTRAINTS
-grid will contain between 1 and 10 elements, inclusive.
-Each element of grid will contain between 1 and 25 characters, inclusive.
-All elements of grid will contain the same number of characters.
-Each element of grid will contain only '.' or '1' (one).


EXAMPLES

0)
{".....1..1..",
 "..1.....1.."}

Returns: 70

This is the example from the statement.

1)
{"...1.",
 ".....",
 ".1..1",
 ".....",
 "1...."}

Returns: 73



2)
{"...1.",
 ".1...",
 "..1.1",
 "1...."}

Returns: 20

It is not possible to place any '4' bricks in this setup.

3)
{".....1...",
 ".....1...",
 "111111111",
 ".....1...",
 ".....1..."}

Returns: 117



*/
// END CUT HERE
