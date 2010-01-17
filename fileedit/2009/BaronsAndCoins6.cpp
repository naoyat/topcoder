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
#define FOR(var,from,to) for(int var=(from);var<=(to);var++)
#define RFOR(var,from,to) for(int var=(to);var>=(from);var--)
#define found(s,e)  ((s).find(e)!=(s).end())

typedef pair<int,int> i_i;
typedef pair<int,pair<int,int> > i_ii;
#define cons(x,y) make_pair((x),(y))
#define car(x) ((x).first)
#define cdr(x) ((x).second)
#define psub(p,q) make_pair(car(p)-car(q),cdr(p)-cdr(q))
#define cadr(x) (x).second.first
#define cddr(x) (x).second.second

class BaronsAndCoins {
  vector<i_i> p;
  vector<vector<i_i> > tt, sx;

 public:
  int getMaximum(vector <int> x, vector <int> y) {
	int N=sz(x);

    p.resize(N);
    rep(i,N) p[i]=cons(x[i],y[i]);
    p.pb(cons(0,0)); N++;
    sort(all(p));
// BEGIN CUT HERE
    cout << p << endl;
// END CUT HERE
    
    tt.resize(N);
    sx.resize(N);
    rep(i,N) {
      tt[i].resize(N);
      sx[i].resize(N);
    }
        
    FOR(i,0,N-2){
      FOR(j,i+1,N-1){
        int dx = car(p[j]) - car(p[i]);
        int dy = cdr(p[j]) - cdr(p[i]);
        if (dy==0) continue;
        
        int sx0max = (dx - (dy*(dy-1)/2))/dy;
        if (sx0max <= 0) continue;
        int sx1min = sx0max + (dy-1) + ((dx - (dy*(dy-1)/2) - sx0max*dy)?1:0);

        tt[i][j] = cons(dx,dy);
        sx[i][j] = cons(sx0max,sx1min);
      }
    }

    vector<map<int,int> > sc(N,map<int,int>());
    sc[0][0] = 0; // dmin, cnt

    int cntmax = 0;
    FOR(i,0,N-2) {
// BEGIN CUT HERE
      printf("i=%d; sc[%d]=", i,i);
      cout << sc[i] << endl;
// END CUT HERE
      tr(sc[i],it) {
        int dmin = car(*it), cnt = cdr(*it);
// BEGIN CUT HERE
        printf("  dmin,cnt = %d,%d\n", dmin,cnt);
// END CUT HERE
        FOR(j,i+1,N-1) {
// BEGIN CUT HERE
          printf("    j=%d; tt=(%d,%d), sx=[%d..%d]\n",
                 j,
                 car(tt[i][j]),cdr(tt[i][j]),
                 car(sx[i][j]),cdr(sx[i][j])
                 );
// END CUT HERE
          if (car(tt[i][j]) <= 0) continue;

          i_i s = sx[i][j];
          int smin=car(s), smax=cdr(s);
          if (dmin < smin) {
            int cnt_next = cnt + 1;
            if (found(sc[j],smax)) {
// BEGIN CUT HERE
              printf("      adopt sc[j=%d][%d] <- max(%d,%d)\n", j,smax, cnt_next, sc[j][smax]);
// END CUT HERE
              sc[j][smax] = max(cnt_next,sc[j][smax]);
            } else {
// BEGIN CUT HERE
              printf("      adopt sc[j=%d][%d] := %d\n", j,smax, cnt_next);
// END CUT HERE
              sc[j][smax] = cnt_next;
            }
            if (cnt_next > cntmax) cntmax = cnt_next;
          }
        }
      }
    }
// BEGIN CUT HERE
    cout << sc << endl;
// END CUT HERE
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

int test_(int case_id) {
  timer_clear();
  switch (case_id) {
    case 0: {
      int x_[] = {15, 5, 30};
      int y_[] = {4, 5, 6};
      int RetVal = 2;
      vector <int> x(x_, x_+sizeof(x_)/sizeof(*x_));
      vector <int> y(y_, y_+sizeof(y_)/sizeof(*y_));
      return verify_case(RetVal, BaronsAndCoins().getMaximum(x, y)); }
    case 1: {
      int x_[] = {10};
      int y_[] = {10};
      int RetVal = 0; 
      vector <int> x(x_, x_+sizeof(x_)/sizeof(*x_));
      vector <int> y(y_, y_+sizeof(y_)/sizeof(*y_));
      return verify_case(RetVal, BaronsAndCoins().getMaximum(x, y)); }
    case 2: {
      int x_[] = {1, 3, 6, 10, 15, 21};
      int y_[] = {1, 2, 3, 4, 5, 6};
      int RetVal = 6; 
      vector <int> x(x_, x_+sizeof(x_)/sizeof(*x_)); 
      vector <int> y(y_, y_+sizeof(y_)/sizeof(*y_));
      return verify_case(RetVal, BaronsAndCoins().getMaximum(x, y)); }
    case 3: {
      int x_[] = {5, 10, 15, 20, 25, 30, 35, 40, 45};
      int y_[] = {1, 1, 1, 2, 2, 2, 3, 3, 3};
      int RetVal = 3; 
      vector <int> x(x_, x_+sizeof(x_)/sizeof(*x_));
      vector <int> y(y_, y_+sizeof(y_)/sizeof(*y_));
      return verify_case(RetVal, BaronsAndCoins().getMaximum(x, y)); }
    case 4: {
      int x_[] = {1, 3, 6, 10, 22, 35, 50, 66};
      int y_[] = {1, 2, 3, 1, 2, 3, 4, 5};
      int RetVal = 5; 
      vector <int> x(x_, x_+sizeof(x_)/sizeof(*x_));
      vector <int> y(y_, y_+sizeof(y_)/sizeof(*y_));
      return verify_case(RetVal, BaronsAndCoins().getMaximum(x, y)); }
    case 5: {
      int x_[] = {1,3,6,10,15,21,28,36,45,55,66,78,91,105,120,136,153,171,190,210,231,253,276,300,325,351,378,406,435,465,496,528,561,595,630,666,703,741,780,820,861,903,946,990,1035,1081,1128,1176,1225,1275};
      int y_[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50};
      int RetVal = 50; 
      vector <int> x(x_, x_+sizeof(x_)/sizeof(*x_));
      vector <int> y(y_, y_+sizeof(y_)/sizeof(*y_));
      return verify_case(RetVal, BaronsAndCoins().getMaximum(x, y)); }
    case 6: {
      int x_[] = {1};
      int y_[] = {1};
      int RetVal = 1; 
      vector <int> x(x_, x_+sizeof(x_)/sizeof(*x_));
      vector <int> y(y_, y_+sizeof(y_)/sizeof(*y_));
      return verify_case(RetVal, BaronsAndCoins().getMaximum(x, y)); }
    case 7: {
      int x_[] = {1459, 162, 1167, 26, 1872, 1512, 675, 538, 1598, 723, 133};
      int y_[] = {28, 9, 25, 3, 32, 29, 19, 17, 30, 20, 8};
      int RetVal = 8;
      vector <int> x(x_, x_+sizeof(x_)/sizeof(*x_));
      vector <int> y(y_, y_+sizeof(y_)/sizeof(*y_));
      return verify_case(RetVal, BaronsAndCoins().getMaximum(x, y)); }
    case 8: {
      int x_[] = {1394, 815, 2435, 668, 428, 424, 28, 669, 535, 1343, 4024, 1798, 367, 521, 468, 2003, 535, 2484, 1251, 2047, 690, 481, 1100};
      int y_[] = {32, 24, 42, 22, 19, 18, 5, 22, 21, 30, 53, 37, 17, 20, 20, 37, 20, 42, 29, 39, 24, 19, 28};
      int RetVal = 9;
      vector <int> x(x_, x_+sizeof(x_)/sizeof(*x_));
      vector <int> y(y_, y_+sizeof(y_)/sizeof(*y_));
      return verify_case(RetVal, BaronsAndCoins().getMaximum(x, y)); }
    case 9: {
      int x_[] = {2127, 3954, 130, 3051, 2649, 34, 1143, 1327, 361, 2343, 1337, 594, 248, 94, 303, 2909, 415, 3199, 663, 1057, 1749, 1053, 888, 974, 4290};
      int y_[] = {34, 47, 8, 41, 38, 4, 25, 27, 14, 36, 27, 18, 11, 7, 12, 40, 15, 42, 19, 24, 31, 24, 22, 23, 49};
      int RetVal = 17;
      vector <int> x(x_, x_+sizeof(x_)/sizeof(*x_));
      vector <int> y(y_, y_+sizeof(y_)/sizeof(*y_));
      return verify_case(RetVal, BaronsAndCoins().getMaximum(x, y)); }

  }
}

#define CASE_ID_MAX 9
int main(int argc, char **argv) {
  if (argc == 1) {
    FOR(case_id,0,CASE_ID_MAX) test_(case_id);
  } else {
    int case_id = atoi(argv[1]);
    if (0 <= case_id && case_id <= CASE_ID_MAX) test_(case_id);
  }
}
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
