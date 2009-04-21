#line 2 "PointsOnCircle.cpp"
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

vector<long long> divisors(long long n, long long lim)
{
  if (n == 1) {
        vector<long long> ds(1);
        ds[0] = 1;
        return ds;
  }

  vector<long long> ds(1), ds_(1);
  ds[0] = 1; ds_[0] = n;

  long long dmax = sqrt(n);
  for (long long d=2; d<=dmax; d++) {
        if (n % d == 0) {
          ds.push_back(d);
          ds_.push_back(n / d);
        }
  }
  if (ds_.back() == dmax) ds_.pop_back();

  for (int i=ds_.size()-1; i>=0; i--) {
        long long ds_i = ds_[i];
        if (ds_i > lim) break;
        ds.push_back(ds_i);
  }
  return ds;
}

class PointsOnCircle {
 public:
  long long count(int r) {
    ll n=(ll)r*r;
    vector<ll> ds = divisors(n,n);
    ll c=0;
    tr(ds,it){
      int rm=(*it)%4;
      if(rm==1) c++;
      else if(rm==3) c--;
    }
    return c<<2;
  }
};

// BEGIN CUT HERE
#include <time.h>
clock_t start_time;
void timer_clear() { start_time = clock(); }
string timer() { clock_t end_time = clock(); double interval = (double)(end_time - start_time)/CLOCKS_PER_SEC; ostringstream os; os << " (" << interval*1000 << " msec)"; return os.str(); }

template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
int verify_case(const long long &Expected, const long long &Received) { if (Expected == Received) cerr << "PASSED" << timer() << endl; else { cerr << "FAILED" << timer() << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } return 0;}

template<int N> struct Case_ {};
char Test_(...);
int Test_(Case_<0>) {
	timer_clear();
	int r = 1; 
	long long RetVal = 4LL; 
	return verify_case(RetVal, PointsOnCircle().count(r)); }
int Test_(Case_<1>) {
	timer_clear();
	int r = 2000000000; 
	long long RetVal = 76LL; 
	return verify_case(RetVal, PointsOnCircle().count(r)); }
int Test_(Case_<2>) {
	timer_clear();
	int r = 3; 
	long long RetVal = 4LL; 
	return verify_case(RetVal, PointsOnCircle().count(r)); }
int Test_(Case_<3>) {
	timer_clear();
	int r = 1053; 
	long long RetVal = 12LL; 
	return verify_case(RetVal, PointsOnCircle().count(r)); }

template<int N> void Run_() { cerr << "Test Case #" << N << "..." << flush; Test_(Case_<N>()); Run_<sizeof(Test_(Case_<N+1>()))==1 ? -1 : N+1>(); }
template<>      void Run_<-1>() {}
int main() { Run_<0>(); }
// END CUT HERE


// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// You are given the radius r of a circle centered at the origin.  Your task is to return the number of lattice points (points whose coordinates are both integers) on the circle.  The number of pairs of integers (x, y) that satisfy x^2 + y^2 = n is given by the formula 4*(d1(n) - d3(n)), where di(n) denotes the number of divisors of n that leave a remainder of i when divided by 4.

DEFINITION
Class:PointsOnCircle
Method:count
Parameters:int
Returns:long long
Method signature:long long count(int r)


CONSTRAINTS
-r will be between 1 and 2*10^9, inclusive.


EXAMPLES

0)
1

Returns: 4

The only lattice points on the circle are (0, 1), (1, 0), (-1, 0), (0, -1).

1)
2000000000

Returns: 76



2)
3

Returns: 4

The number of lattice points on the circle of radius 3 is the same as the number of integer solutions of the equation x^2 + y^2 = 9. Using the formula from the problem statement we can calculate this number as 4*(d1(9) - d3(9)). It is easy to see that d1(9) = 2 (divisors 1 and 9) and d3(9) = 3 (divisor 3). So the answer is 4*(2 - 1) = 4.

3)
1053

Returns: 12



*/
// END CUT HERE
