#line 2 "SilverDistance.cpp"
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
#define tr(c,i)  for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); i++)
#define rep(var,n)  for(int var=0;var<(n);var++)
#define FOR(var,from,to) for(int var=(from);var<=(to);var++)
#define RFOR(var,from,to) for(int var=(to);var>=(from);var--)
#define found(s,e)  ((s).find(e)!=(s).end())
#define mset(arr,val)  memset(arr,val,sizeof(arr))
#define remove_(c,val) (c).erase(remove((c).begin(),(c).end(),(val)),(c).end())
#define lastc(str) (*((str).end()-1))

typedef pair<int,int> i_i;
typedef pair<ll,ll> ll_ll;
typedef pair<double,double> d_d;
typedef pair<int,pair<int,int> > i_ii;
typedef pair<int,pair<int,pair<int,int> > > i_i_ii;
#define cons(x,y) make_pair((x),(y))
#define car(x) ((x).first)
#define cdr(x) ((x).second)
#define cadr(x) (x).second.first
#define cddr(x) (x).second.second

class SilverDistance {
  inline int ad(int dx,int dy) { return abs(dx)+abs(dy); }
  inline ll ab(int dx,int dy) { return (((ll)(dx+2000000))<<32)|(ll)(dy+2000000); }
  
  map<i_i,int> vim;
  
 public:
  int minSteps(int sx, int sy, int gx, int gy) {
	int dx = gx-sx, dy = gy-sy, a = ad(dx,dy);
    if(dx==0&&dy==0) return 0;

    priority_queue<i_i_ii> pq;
    priority_queue<int> g;
    vim.clear();// vim[cons(dx,dy)] = 0;

    int mina = INT_MAX;
    pq.push(cons(-a,cons(0,cons(dx,dy))));
    while(!pq.empty()){
      i_i_ii t = pq.top(); pq.pop();
      int ta=-car(t);
      if (ta > mina) continue;
      mina = min(mina,ta);
      if (ta==0) { g.push(-cadr(t)); continue; }

      i_i d = cddr(t);
      int st=cadr(t), dx=car(d),dy=cdr(d), a;
      //      ll d_ =ab(dx,dy);
      printf("%d, %d, (%d,%d), %d\n", ta,st,dx,dy, sz(vim));
      if (found(vim,d)) continue;
      //      if(vis.find(d_)!=vis.end()) continue;
      //      printf("-\n");
      vim[d]=ta;
      
      a=ad(dx+1,dy-1);
      //      printf(" ( %d, %d )\n", a, ta);
      if(a<=ta) pq.push(cons(-a,cons(st+1,cons(dx+1,dy-1))));
      a=ad(dx,dy-1);
      if(a<=ta) pq.push(cons(-a,cons(st+1,cons(dx,dy-1))));
      a=ad(dx-1,dy-1);
      if(a<=ta) pq.push(cons(-a,cons(st+1,cons(dx-1,dy-1))));
      a=ad(dx+1,dy-1);
      if(a<=ta) pq.push(cons(-a,cons(st+1,cons(dx+1,dy+1))));
      a=ad(dx-1,dy-1);
      if(a<=ta) pq.push(cons(-a,cons(st+1,cons(dx-1,dy+1))));
    }
    
    return -g.top();
    //    return -1;
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
	int sx = 1; 
	int sy = 0; 
	int gx = 1; 
	int gy = 9; 
	int RetVal = 9; 
	return verify_case(RetVal, SilverDistance().minSteps(sx, sy, gx, gy)); }
int Test_(Case_<1>) {
	timer_clear();
	int sx = 0; 
	int sy = 0; 
	int gx = -4; 
	int gy = 3; 
	int RetVal = 5; 
	return verify_case(RetVal, SilverDistance().minSteps(sx, sy, gx, gy)); }
int Test_(Case_<2>) {
	timer_clear();
	int sx = 0; 
	int sy = 0; 
	int gx = 5; 
	int gy = 8; 
	int RetVal = 8; 
	return verify_case(RetVal, SilverDistance().minSteps(sx, sy, gx, gy)); }
int Test_(Case_<3>) {
	timer_clear();
	int sx = -487617; 
	int sy = 826524; 
	int gx = 892309; 
	int gy = -918045; 
	int RetVal = 1744571; 
	return verify_case(RetVal, SilverDistance().minSteps(sx, sy, gx, gy)); }
int Test_(Case_<4>) {
	timer_clear();
	int sx = -27857; 
	int sy = 31475; 
	int gx = -27857; 
	int gy = 31475; 
	int RetVal = 0; 
	return verify_case(RetVal, SilverDistance().minSteps(sx, sy, gx, gy)); }

template<int N> void Run_() { cerr << "Test Case #" << N << "..." << flush; Test_(Case_<N>()); Run_<sizeof(Test_(Case_<N+1>()))==1 ? -1 : N+1>(); }
template<>      void Run_<-1>() {}
int main() { Run_<0>(); }
// END CUT HERE


// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// In Japanese Chess, there is a piece called Silver. A Silver piece located in cell (x,y) can move to any of the following cells in one step: (x-1,y+1), (x,y+1), (x+1,y+1), (x-1,y-1), (x+1,y-1). In other words, it can move one cell in any of the four diagonal directions, or it can move one cell vertically in the positive y direction.





Initially, there's a Silver piece in cell (sx,sy) of an infinitely large board. Return the minimal number of steps required to move to cell (gx,gy).

DEFINITION
Class:SilverDistance
Method:minSteps
Parameters:int, int, int, int
Returns:int
Method signature:int minSteps(int sx, int sy, int gx, int gy)


CONSTRAINTS
-sx, sy, gx and gy will each be between -1,000,000 and 1,000,000 inclusive.


EXAMPLES

0)
1
0
1
9

Returns: 9

Move up vertically in the positive y direction 9 times.

1)
0
0
-4
3

Returns: 5

Follow the path : (0,0) -> (-1,1) -> (-1,2) -> (-2,3) -> (-3,2) -> (-4,3)

2)
0
0
5
8

Returns: 8

Move up vertically in the postive y direction 3 times, then move diagonally up and to the right 5 times.

3)
-487617
826524
892309
-918045

Returns: 1744571



4)
-27857
31475
-27857
31475

Returns: 0

The Silver is already in the goal.

*/
// END CUT HERE
