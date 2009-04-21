// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// You've been given the blueprint for a trainyard which was laid out on a grid.  Some grid cells have East-West track segments (marked with '-'), some have North-South track segments (marked with '|'), and others are intersections (marked with '+').  Cells with no track are marked with a '.' character. A train may enter an intersection square from any direction and may leave in any direction.  Trains may enter a North-South track segment from either the North or South, and must exit the square moving in the same direction.  Thus if a train enters a North-South segment from the South, it must leave to the North.  East-West tracks work the same way, except with directions East and West.  Squares without track may not be entered, and the train may not leave the area covered by the grid.  The train always occupies a single grid location, and each square moved requires one unit of fuel.
 
The train's starting location is marked on the map with an 'S' character.  Trains may exit this location going any direction.  Given the trainyard map in layout and the fuel available in fuel, you want to determine how many grid squares may be reached.  You do not need to construct one route that reaches all these squares; rather, you are determining which squares could be reached using any legal route beginning at the 'S' location.  A legal route may use some, all, or none of the fuel.  Return the number of distinct grid squares that can be reached, including the initial 'S' location.


DEFINITION
Class:Trainyard
Method:reachableSquares
Parameters:vector <string>, int
Returns:int
Method signature:int reachableSquares(vector <string> layout, int fuel)


CONSTRAINTS
-layout will contain between 1 and 10 elements, inclusive.
-Each element of layout will contain between 1 and 10 characters, inclusive.
-Each element of layout will contain the same number of characters.
-Each element of layout will contain only the characters '-','|','+','.', and 'S'.
-layout will contain exactly one 'S' character.
-fuel will be between 1 and 10, inclusive.


EXAMPLES

0)
{
".-....",
"-S---.",
"......"}
2

Returns: 4

The train can reach the initial 'S', as well as one square to the West.  It could also reach two squares to the East (but not the third, as there's only 2 units of fuel). It can't move North to start, as it can't enter an East-West segment from the South.

1)
{
"..+-+.",
"..|.|.",
"S-+-+."}
10

Returns: 10

All 9 of the track segments are reachable, plus 1 for the 'S' square.  Be sure not to count squares twice!

2)
{
"-....-",
"|....+",
"+-S++|",
"|.|..|",
"..+-++"}
8

Returns: 15

All of the track segments are reachable except for the two at the North end that seem to be oriented the wrong way.

3)
{
".|...",
"-+S+|",
".|..."}
5

Returns: 6

The track segment on the far East side is not reachable - as you can't enter a North-South segment from the West.

*/
// END CUT HERE

#line 78 "Trainyard.cpp"
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
#define rep(var,n)  for(int var=0;var<(n);var++)
#define found(s,e)  ((s).find(e)!=(s).end())
#define remove_(c,val) (c).erase(remove((c).begin(),(c).end(),(val)),(c).end())

class Trainyard {
  bool ns(int c){return (c=='+'||c=='|')?true:false;}
  bool ew(int c){return (c=='+'||c=='-')?true:false;}
public:
 int reachableSquares(vector<string> lo, int fuel) {
  int w=sz(lo[0]), h=sz(lo);
  int sx,sy;
  vector<vector<bool> > r(h),v(h);
  rep(i,h){r[i].resize(w); v[i].resize(w);}
  rep(y,h)rep(x,w){ r[y][x]=v[y][x]=false; if(lo[y][x]=='S') {sy=y;sx=x;r[y][x]=v[y][x]=true;}}
  queue<pair<int,int> > q;
  if(sy>0){
    v[sy-1][sx]=true;
    if(ns(lo[sy-1][sx])) q.push(make_pair(sy-1,sx));
  }
  if(sx>0){
    v[sy][sx-1]=true;
    if(ew(lo[sy][sx-1])) q.push(make_pair(sy,sx-1));
  }
  if(sx<w-1){
    v[sy][sx+1]=true;
    if(ew(lo[sy][sx+1])) q.push(make_pair(sy,sx+1));
  }
  if(sy<h-1){
    v[sy+1][sx]=true;
    if(ns(lo[sy+1][sx])) q.push(make_pair(sy+1,sx));
  }
  while(!q.empty()){
    int sy=q.front().first, sx=q.front().second;
    v[sy][sx]=r[sy][sx]=true;
    q.pop();
    if(sy>0){
      if(ns(lo[sy-1][sx])&&!v[sy-1][sx]) q.push(make_pair(sy-1,sx));
      v[sy-1][sx]=true;
    }
    if(sx>0){
      if(ew(lo[sy][sx-1])&&!v[sy][sx-1]) q.push(make_pair(sy,sx-1));
      v[sy][sx-1]=true;
    }
    if(sx<w-1){
      if(ew(lo[sy][sx+1])&&!v[sy][sx+1]) q.push(make_pair(sy,sx+1));
      v[sy][sx+1]=true;
    }
    if(sy<h-1){
      if(ns(lo[sy+1][sx])&&!v[sy+1][sx]) q.push(make_pair(sy+1,sx));
      v[sy+1][sx]=true;
    }
  }
  int cnt=0;
  rep(y,h)rep(x,w) if(r[y][x])cnt++;
  return cnt;
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
	string layout_[] = {
".-....",
"-S---.",
"......"};
	  vector <string> layout(layout_, layout_+sizeof(layout_)/sizeof(*layout_)); 
	int fuel = 2; 
	int RetVal = 4; 
	return verify_case(RetVal, Trainyard().reachableSquares(layout, fuel)); }
int Test_(Case_<1>) {
	timer_clear();
	string layout_[] = {
"..+-+.",
"..|.|.",
"S-+-+."};
	  vector <string> layout(layout_, layout_+sizeof(layout_)/sizeof(*layout_)); 
	int fuel = 10; 
	int RetVal = 10; 
	return verify_case(RetVal, Trainyard().reachableSquares(layout, fuel)); }
int Test_(Case_<2>) {
	timer_clear();
	string layout_[] = {
"-....-",
"|....+",
"+-S++|",
"|.|..|",
"..+-++"};
	  vector <string> layout(layout_, layout_+sizeof(layout_)/sizeof(*layout_)); 
	int fuel = 8; 
	int RetVal = 15; 
	return verify_case(RetVal, Trainyard().reachableSquares(layout, fuel)); }
int Test_(Case_<3>) {
	timer_clear();
	string layout_[] = {
".|...",
"-+S+|",
".|..."};
	  vector <string> layout(layout_, layout_+sizeof(layout_)/sizeof(*layout_)); 
	int fuel = 5; 
	int RetVal = 6; 
	return verify_case(RetVal, Trainyard().reachableSquares(layout, fuel)); }

template<int N> void Run_() { cerr << "Test Case #" << N << "..." << flush; Test_(Case_<N>()); Run_<sizeof(Test_(Case_<N+1>()))==1 ? -1 : N+1>(); }
template<>      void Run_<-1>() {}
int main() { Run_<0>(); }
// END CUT HERE

