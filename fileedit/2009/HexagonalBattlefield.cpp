#line 2 "HexagonalBattlefield.cpp"
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

class HexagonalBattlefield {
  int pn, vn, w;
  set<pair<int,int> > petr;
  
 public:
  bool inside(int x, int y){
    if (x < -vn || vn < x) return false;
    if (y < -vn || vn < y) return false;
    if (y-x < -vn || vn < y-x) return false;
    if (found(petr,make_pair(x,y))) return false;
    return true;
  }

  map<pair<int,int>,int> mem;

  vector<vector<int> > ne, vid;
    

  int sub(int sx, int sy){
    if (sy>vn) return 1;
    if (sx>vn) return sub(-vn,sy+1);

    pair<int,int> k = make_pair(sx,sy);
    if (found(mem,k)) return mem[k];

    if (vid[vn+sx][vn+sy] || !inside(sx,sy)) return sub(sx+1,sy);

    int ne_ = ne[vn+sx][vn+sy];
    if (inside(sx,sy+1)) vid[vn+sx][vn+sy+1]=1;
    if (inside(sx+1,sy+1)) vid[vn+sx+1][vn+sy+1]=1;
    if (inside(sx+1,sy)) vid[vn+sx+1][vn+sy]=1;
    int sum = sub(sx+1,sy);
    
    if (inside(sx,sy+1)) vid[vn+sx][vn+sy+1]=0;
    if (inside(sx+1,sy+1)) vid[vn+sx+1][vn+sy+1]=0;
    if (inside(sx+1,sy)) vid[vn+sx+1][vn+sy]=0;
    sum += sub(sx+1,sy);

    mem[k] = sum;
    return sum;
  }
  
  int countArrangements(vector<int> X, vector<int> Y, int N) {
	pn=sz(X), vn=N-1, w=vn*2+1;

    petr.clear();
    mem.clear();
    printf("N = %d\n", N);
    rep(i,pn) {
      petr.insert(make_pair(X[i],Y[i]));
      printf("  petr[%d] = (%d, %d)\n", i, X[i],Y[i]);
    }
    
    ne.resize(w); vid.resize(w);
    rep(i,w) {
      ne[i].resize(w);
      vid[i].resize(w);
      rep(j,w) ne[i][j] = vid[i][j] = 0;
    }
    
    for(int x=-vn; x<=vn; x++){
      for (int y=-vn; y<=vn; y++) {
        if (!inside(x,y)) continue;
        //        printf("(%d,%d)\n", x,y);

        int x2,y2;
        x2 = x; y2 = y+1;
        if (inside(x2,y2)) {
          //printf("(%d,%d) - (%d,%d)\n", x,y, x2,y2);
          ne[vn+x][vn+y] |= 1;
        }
        x2 = x+1; y2 = y+1;
        if (inside(x2,y2)) {
          //printf("(%d,%d) - (%d,%d)\n", x,y, x2,y2);
          ne[vn+x][vn+y] |= 2;
        }
        x2 = x+1; y2 = y;
        if (inside(x2,y2)) {
          //printf("(%d,%d) - (%d,%d)\n", x,y, x2,y2);
          ne[vn+x][vn+y] |= 4;
        }
      }
    }
    
    for(int y=vn; y>=-vn; y--){
      for(int x=-vn; x<=vn; x++){
        if (found(petr,make_pair(x,y))) putchar('X');
        else if (inside(x,y)) putchar('o');
        else putchar('.');
      }
      printf("\n");
    }

    
    return sub(-vn,-vn);
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
	int X_[] = {-2,0,1,1,0};
	  vector <int> X(X_, X_+sizeof(X_)/sizeof(*X_)); 
	int Y_[] = {-2,0,1,0,2};
	  vector <int> Y(Y_, Y_+sizeof(Y_)/sizeof(*Y_)); 
	int N = 3; 
	int RetVal = 10; 
	return verify_case(RetVal, HexagonalBattlefield().countArrangements(X, Y, N)); }
int Test_(Case_<1>) {
	timer_clear();
	int X_[] = {0};
	  vector <int> X(X_, X_+sizeof(X_)/sizeof(*X_)); 
	int Y_[] = {0};
	  vector <int> Y(Y_, Y_+sizeof(Y_)/sizeof(*Y_)); 
	int N = 2; 
	int RetVal = 2; 
	return verify_case(RetVal, HexagonalBattlefield().countArrangements(X, Y, N)); }
int Test_(Case_<2>) {
	timer_clear();
	int X_[] = {0};
	  vector <int> X(X_, X_+sizeof(X_)/sizeof(*X_)); 
	int Y_[] = {0};
	  vector <int> Y(Y_, Y_+sizeof(Y_)/sizeof(*Y_)); 
	int N = 3; 
	int RetVal = 104; 
	return verify_case(RetVal, HexagonalBattlefield().countArrangements(X, Y, N)); }
int Test_(Case_<3>) {
	timer_clear();
	int X_[] = {-1,0,0,1,2};
	  vector <int> X(X_, X_+sizeof(X_)/sizeof(*X_)); 
	int Y_[] = {0,0,1,0,0};
	  vector <int> Y(Y_, Y_+sizeof(Y_)/sizeof(*Y_)); 
	int N = 3; 
	int RetVal = 6; 
	return verify_case(RetVal, HexagonalBattlefield().countArrangements(X, Y, N)); }
int Test_(Case_<4>) {
	timer_clear();
	int X_[] = {0,1,0,0,1,-1,-1};
	  vector <int> X(X_, X_+sizeof(X_)/sizeof(*X_)); 
	int Y_[] = {0,0,-1,1,1,0,-1};
	  vector <int> Y(Y_, Y_+sizeof(Y_)/sizeof(*Y_)); 
	int N = 2; 
	int RetVal = 1; 
	return verify_case(RetVal, HexagonalBattlefield().countArrangements(X, Y, N)); }

template<int N> void Run_() { cerr << "Test Case #" << N << "..." << flush; Test_(Case_<N>()); Run_<sizeof(Test_(Case_<N+1>()))==1 ? -1 : N+1>(); }
template<>      void Run_<-1>() {}
int main() { Run_<0>(); }
// END CUT HERE


// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// You may have heard of the game "Heroes of Might and Magic".  Recently, battles in this game have been broadcast online, and the weekly battles between Petr and Vasyl have been very popular.  Petr usually wins these battles, so Vasyl has decided to develop a new strategy.

The battlefield in this game consists of equal hexagonal cells arranged in the form of a larger hexagon.  The number of cells on each side of the battlefield represents the size of the field.  The coordinate system is shown in the following figure, which depicts a battlefield of size 3:



This week, Petr and Vasyl are playing on a battlefield of size N.  Some of the cells are already occupied by Petr's heroes.  The locations of these cells are given in the vector <int>s X and Y, where (X[i], Y[i]) is the location of Petr's i-th hero.  To defeat Petr, Vasyl must occupy every single free cell with his own heroes.  Unfortunately, Vasyl only has equestrian heroes, each of which occupy exactly two adjacent cells.  No two heroes can occupy a single cell.  One possible correct arrangement is shown in the following figure:



Vasyl wants to simulate a battle with every possible arrangement of his heroes so that he can determine the optimal one.  Calculate the number of different possible arrangements he will consider.  The answer might be very large, so return the number modulo 2000000011.

DEFINITION
Class:HexagonalBattlefield
Method:countArrangements
Parameters:vector <int>, vector <int>, int
Returns:int
Method signature:int countArrangements(vector <int> X, vector <int> Y, int N)


CONSTRAINTS
-N will be between 1 and 8, inclusive.
-X will contain between 1 and 50 elements, inclusive.
-X and Y will each contain the same number of elements.
-All points (X[i], Y[i]) will lie inside the battlefield of size N.
-All points (X[i], Y[i]) will be distinct.


EXAMPLES

0)
{-2,0,1,1,0}
{-2,0,1,0,2}
3

Returns: 10

This is the battlefield shown in the figure above.

1)
{0}
{0}
2

Returns: 2

2)
{0}
{0}
3

Returns: 104

3)
{-1,0,0,1,2}
{0,0,1,0,0}
3

Returns: 6

4)
{0,1,0,0,1,-1,-1}
{0,0,-1,1,1,0,-1}
2

Returns: 1

Here the entire battlefield is occupied by Petr's heroes. Therefore there exists only one possible arrangement.

*/
// END CUT HERE
