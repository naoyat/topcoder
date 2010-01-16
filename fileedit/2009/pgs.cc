#line 2 "PlanarGraphShop.cpp"
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

typedef pair<int,int> i_i;
typedef pair<ll,ll> ll_ll;
typedef pair<double,double> d_d;
typedef pair<int,pair<int,int> > i_ii;

class PlanarGraphShop {
  vector<int> xs; int xsn;
  //map<int,int> m0;
  vector<int> m,m0;
  
  int cost(int v, int e){
    return v*v*v + e*e;
  }
  int sub(int n){
    if(m[n]<INT_MAX) return m[n];
    priority_queue<int> pq;
    tr(m0,it){
      int x=*it; if(x>n) continue; if(x==n)return 1;
      pq.push(-(1+m[n-x]));
    }
    return -pq.top();
  }
 public:
  int bestCount(int N) {
    double r = pow((double)N, 1.0/3);
    //    int rc = (int)floor(r + .00001);
    int rc = (int)r;

    set<int> cs;
    FOR(n,1,rc){
      FOR(e,0,max(0,n*2-3)){
        int c=cost(n,e);
        if(c>N) continue;
        if(c==N) return 1;
        cs.insert(c);
      }
    }
    xs.assign(all(cs)); xsn=sz(xs);
    m0.clear();
    m.resize(N+1); FOR(i,0,N) m[i]=INT_MAX;
    tr(xs,it) { m0.pb(*it); m[*it]=1; }

    FOR(i,1,N){
      if (m[i] < INT_MAX) continue;
      m[i] = sub(i);
    }
    return m[N];
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
	int N = 36; 
	int RetVal = 1; 
	return verify_case(RetVal, PlanarGraphShop().bestCount(N)); }
int Test_(Case_<1>) {
	timer_clear();
	int N = 7; 
	int RetVal = 7; 
	return verify_case(RetVal, PlanarGraphShop().bestCount(N)); }
int Test_(Case_<5>) {
	timer_clear();
	int N = 8; 
	int RetVal = 1; 
	return verify_case(RetVal, PlanarGraphShop().bestCount(N)); }
int Test_(Case_<2>) {
	timer_clear();
	int N = 72; 
	int RetVal = 2; 
	return verify_case(RetVal, PlanarGraphShop().bestCount(N)); }
int Test_(Case_<3>) {
	timer_clear();
	int N = 46; 
	int RetVal = 3; 
	return verify_case(RetVal, PlanarGraphShop().bestCount(N)); }
/*
int Test_(Case_<4>) {
	timer_clear();
	int N = 50000; 
	int RetVal = 2; 
	return verify_case(RetVal, PlanarGraphShop().bestCount(N)); }
*/
int Test_(Case_<4>) {
	timer_clear();
	int N = 1; 
	int RetVal = 1; 
	return verify_case(RetVal, PlanarGraphShop().bestCount(N)); }
template<int N> void Run_() { cerr << "Test Case #" << N << "..." << flush; Test_(Case_<N>()); Run_<sizeof(Test_(Case_<N+1>()))==1 ? -1 : N+1>(); }
template<>      void Run_<-1>() {}
int main() { Run_<0>(); }
// END CUT HERE


// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
In the Kocurkovo village there is a shop that sells simple planar graphs. (See Notes for a definition.)


The cost of any graph with X vertices and Y edges is (X^3 + Y^2) gold coins.


Monika has N gold coins, and she wants to spend all of them on simple planar graphs.


Write a method that gets the value N and computes the minimum number of simple planar graphs Monika has to buy in order to spend exactly N gold coins.
She is allowed to buy multiple graphs of the same type.


DEFINITION
Class:PlanarGraphShop
Method:bestCount
Parameters:int
Returns:int
Method signature:int bestCount(int N)


NOTES
-A simple graph is an ordered pair (V,E) where V is a finite non-empty set of objects called vertices, and E is a finite set of edges. Each edge is a two-element subset of V.  (You can find drawings of several graphs in Example #3.)
-Note that a simple graph does not contain any loops (edges that connect a vertex to itself) and any duplicate edges. In other words, each edge connects two different vertices, and each pair of vertices is connected by at most one edge.
-A graph is called planar if it has a drawing in the plane such that no two edges intersect.
-Note that a simple planar graph does not have to be connected.


CONSTRAINTS
-N will be between 1 and 50,000, inclusive.


EXAMPLES

0)
36

Returns: 1

For 36 gold coins she can buy a triangle: a simple planar graph with 3 vertices and 3 edges.

1)
7

Returns: 7

The only simple planar graph that costs 7 gold coins or less is the graph that consists of a single vertex (and no edges). This graph costs 1^3 + 0^2 = 1, so Monika has to buy 7 of them.

2)
72

Returns: 2

She can buy 2 triangles for 36 gold coins each. No simple planar graph costs exactly 72 gold coins, hence the optimal answer in this case is 2.

3)
46

Returns: 3

All the graphs Monika can afford are shown in the following picture:



One optimal solution is to buy graphs worth 1 + 9 + 36 gold coins.

*/
// END CUT HERE
