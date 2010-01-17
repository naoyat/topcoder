#line 2 "BaronsAndCoins.cpp"
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
#define forrr(var,from,to) for(int var=(to);var>=(from);var--)
#define found(s,e)  ((s).find(e)!=(s).end())

typedef pair<int,int> i_i;
typedef pair<int,pair<int,int> > i_ii;
#define cons(x,y) make_pair((x),(y))
#define car(x) ((x).first)
#define cdr(x) ((x).second)
#define sub(p,q) make_pair(car(p)-car(q),cdr(p)-cdr(q))
#define cadr(x) (x).second.first
#define cddr(x) (x).second.second

class BaronsAndCoins {
 public:
  int getMaximum(vector <int> x, vector <int> y) {
	int N=sz(x);

    vector<i_i> p(N);
    rep(i,N) p[i]=cons(y[i],x[i]); p.pb(cons(0,0)); N++;
    
    vector<vector<i_i> > tt(N,vector<i_i>(N));
    sort(all(p)); // reverse(all(p));
    
    forr(i,0,N-2){
      forr(j,i+1,N-1){
        tt[i][j] = sub(p[j],p[i]);
      }
    }

    priority_queue<pair<int,pair<int,int> > > pq;  // j,cnt,ymax
    forr(j,1,N-1) pq.push(cons(j,cons(1,10001)));
    map<int,int> score;

    int cntmax=0;
    while(!pq.empty()){
      i_ii x = pq.top(); pq.pop();
      int j=car(x),cnt=cadr(x),last_dxmax = cddr(x);
      if (found(score,j) && score[j]>cnt) continue;
      /*
      if (found(score,j)){
        if (score[j].second>=last_dxmax) continue;
      }
      score[j] = cons(cnt,last_dxmax);
      */
      forrr(i,0,j-1){
        i_i dif = tt[i][j];
        int dy=car(dif),dx=cdr(dif); if (dy==0) continue;
        int dxmax = (dx - (dy*(dy-1)/2))/dy;
        if (dxmax <= 0) continue;
        int dxmax_ = dxmax + (dy-1) + ((dx - (dy*(dy-1)/2) - dxmax*dy)?1:0);
        printf("testing %d-%d (cnt=%d), diff=(%d,%d), dxmax=%d..%d{%d-(%d+%d)=%d}|%d,..\n",
               i,j,cnt, dx,dy,
               dxmax, dxmax_,
               dx, dy*(dy-1)/2, dxmax*dy, ((dx - (dy*(dy-1)/2) - dxmax*dy)?1:0),
               last_dxmax);
        if (dxmax_ >= last_dxmax) continue;
        if (i==0) {
          if (cnt>cntmax) cntmax = cnt;
        } else {
          pq.push(cons(i,cons(cnt+1,dxmax)));
        }
      }
    }
    return cntmax;
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
	int x_[] = {15, 5, 30};
	  vector <int> x(x_, x_+sizeof(x_)/sizeof(*x_)); 
	int y_[] = {4, 5, 6};
	  vector <int> y(y_, y_+sizeof(y_)/sizeof(*y_)); 
	int RetVal = 2; 
	return verify_case(RetVal, BaronsAndCoins().getMaximum(x, y)); }
int Test_(Case_<1>) {
	timer_clear();
	int x_[] = {10};
	  vector <int> x(x_, x_+sizeof(x_)/sizeof(*x_)); 
	int y_[] = {10};
	  vector <int> y(y_, y_+sizeof(y_)/sizeof(*y_)); 
	int RetVal = 0; 
	return verify_case(RetVal, BaronsAndCoins().getMaximum(x, y)); }
int Test_(Case_<2>) {
	timer_clear();
	int x_[] = {1, 3, 6, 10, 15, 21};
	  vector <int> x(x_, x_+sizeof(x_)/sizeof(*x_)); 
	int y_[] = {1, 2, 3, 4, 5, 6};
	  vector <int> y(y_, y_+sizeof(y_)/sizeof(*y_)); 
	int RetVal = 6; 
	return verify_case(RetVal, BaronsAndCoins().getMaximum(x, y)); }
int Test_(Case_<3>) {
	timer_clear();
	int x_[] = {5, 10, 15, 20, 25, 30, 35, 40, 45};
	  vector <int> x(x_, x_+sizeof(x_)/sizeof(*x_)); 
	int y_[] = {1, 1, 1, 2, 2, 2, 3, 3, 3};
	  vector <int> y(y_, y_+sizeof(y_)/sizeof(*y_)); 
	int RetVal = 3; 
	return verify_case(RetVal, BaronsAndCoins().getMaximum(x, y)); }
int Test_(Case_<4>) {
	timer_clear();
	int x_[] = {1, 3, 6, 10, 22, 35, 50, 66};
	  vector <int> x(x_, x_+sizeof(x_)/sizeof(*x_)); 
	int y_[] = {1, 2, 3, 1, 2, 3, 4, 5};
	  vector <int> y(y_, y_+sizeof(y_)/sizeof(*y_)); 
	int RetVal = 5; 
	return verify_case(RetVal, BaronsAndCoins().getMaximum(x, y)); }

int Test_(Case_<5>) {
	timer_clear();
	int x_[] = {1,3,6,10,15,21,28,36,45,55,66,78,91,105,120,136,153,171,190,210,231,253,276,300,325,351,378,406,435,465,496,528,561,595,630,666,703,741,780,820,861,903,946,990,1035,1081,1128,1176,1225,1275};
    vector <int> x(x_, x_+sizeof(x_)/sizeof(*x_)); 
    int y_[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50};
    vector <int> y(y_, y_+sizeof(y_)/sizeof(*y_)); 
	int RetVal = 50; 
	return verify_case(RetVal, BaronsAndCoins().getMaximum(x, y)); }
int Test_(Case_<6>) {
	timer_clear();
	int x_[] = {1};
    vector <int> x(x_, x_+sizeof(x_)/sizeof(*x_)); 
	int y_[] = {1};
    vector <int> y(y_, y_+sizeof(y_)/sizeof(*y_)); 
	int RetVal = 1;
	return verify_case(RetVal, BaronsAndCoins().getMaximum(x, y)); }

int Test_(Case_<7>) {
	timer_clear();
	int x_[] = {1459, 162, 1167, 26, 1872, 1512, 675, 538, 1598, 723, 133};
    vector <int> x(x_, x_+sizeof(x_)/sizeof(*x_)); 
	int y_[] = {28, 9, 25, 3, 32, 29, 19, 17, 30, 20, 8};
    vector <int> y(y_, y_+sizeof(y_)/sizeof(*y_)); 
	int RetVal = 8;
	return verify_case(RetVal, BaronsAndCoins().getMaximum(x, y)); }
  

template<int N> void Run_() { cerr << "Test Case #" << N << "..." << flush; Test_(Case_<N>()); Run_<sizeof(Test_(Case_<N+1>()))==1 ? -1 : N+1>(); }
template<>      void Run_<-1>() {}
int main() { Run_<0>(); }
// END CUT HERE


// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// The game "Barons and Coins" utilizes a customized chess board that can be much larger than the usual 8x8. The game involves the use of a special chess piece, the baron. Initially, a baron is placed on the top-left cell of the board (specified as  x=0, y=0) and coins are placed by the other players on specific cells of the board. The objective of the game is to use the baron to capture as many coins as possible. A coin is considered captured when the player moves the baron to the cell where the coin has been placed.

A baron's movement is as follows: In the first turn, the baron moves from its cell (x,y) to cell (x + K1, y + 1) such that K1 is positive.  After the first turn, the i-th move is specified as moving from current cell (x,y) to a new cell (x+Ki , y+1) such that Ki is strictly greater than Ki-1 . 

The coordinates of every coin are given in the vector <int> x and the vector <int> y, where the i-th coin is located on cell (x[i], y[i]). Return the maximum number of coins a player can capture.

DEFINITION
Class:BaronsAndCoins
Method:getMaximum
Parameters:vector <int>, vector <int>
Returns:int
Method signature:int getMaximum(vector <int> x, vector <int> y)


CONSTRAINTS
-x will contain between 1 and 50 elements, inclusive.
-y will contain the same number of elements as x.
-Each element of x will be between 1 and 10000, inclusive.
-Each element of y will be between 1 and 10000, inclusive.
-Each pair x[i], y[i] will be distinct.


EXAMPLES

0)
{15, 5, 30}
{4, 5, 6}

Returns: 2

The baron can move in this order to obtain the coins at (15,4) and (30,6):
(0,0) -> (2,1) -> (5,2) -> (9,3) -> (15,4) -> (22,5) -> (30,6)

1)
{10}
{10}

Returns: 0

No valid sequence of baron movements can take the baron from (0,0) to (10,10).

2)
{1, 3, 6, 10, 15, 21}
{1, 2, 3, 4, 5, 6}

Returns: 6



3)
{5, 10, 15, 20, 25, 30, 35, 40, 45}
{1, 1, 1, 2, 2, 2, 3, 3, 3}

Returns: 3



4)
{1, 3, 6, 10, 22, 35, 50, 66}
{1, 2, 3, 1, 2, 3, 4, 5}

Returns: 5



*/
// END CUT HERE
