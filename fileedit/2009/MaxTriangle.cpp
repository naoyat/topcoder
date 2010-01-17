#line 2 "MaxTriangle.cpp"
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
#define sz(a)  int((a).size())
#define pb  push_back
#define all(c)  (c).begin(),(c).end()
#define tr(c,i)  for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); i++)
#define rep(var,n)  for(int var=0;var<(n);var++)
#define found(s,e)  ((s).find(e)!=(s).end())

class MaxTriangle {
  double s(int v1x, int v1y, int v2x, int v2y) {
    // v1: A, v2: B
    return 0.5 * abs(v1x * v2y - v1y * v2x);
  }
 public:
  double calculateArea(int A, int B) {
    int i;
	map<int,int> sq;
    sq.clear();
    for(i=0;i<=44721;i++) { sq[i*i]=i; }

    set<pair<int,int> > ai, bi;
    ai.clear(); bi.clear();
    
    for(i=0;i<=A;i++) {
      int i2=i*i; if (i2 > A) break;
      int j2=A-i2; if (!found(sq,j2)) continue;
      int j=sq[j2]; //if (j<i) break;
      ai.insert(make_pair(i,j));
    }
    if (sz(ai)==0) return -1;
    for(i=0;i<=B;i++) {
      int i2=i*i; if (i2 > B) break;
      int j2=B-i2; if (!found(sq,j2)) continue;
      int j=sq[j2]; //if (j<i) break;
      bi.insert(make_pair(i,j));
    }
    if (sz(bi)==0) return -1;

    double smax=0, s_;
    tr(ai,at){
      int ax=at->first, ay=at->second;
      tr(bi,bt){
        int bx=bt->first, by=bt->second;
        for(int a0=-1;a0<=1;a0+=2)
          for(int a1=-1;a1<=1;a1+=2)
            for(int b0=-1;b0<=1;b0+=2)
              for(int b1=-1;b1<=1;b1+=2) {
                s_ = s(a0*ax,a1*ay,b0*bx,b1*by);
                if (s_ > smax) smax = s_;
              }
      }
    }
    
    return smax;
  }
};

// BEGIN CUT HERE
#include <time.h>
clock_t start_time;
void timer_clear() { start_time = clock(); }
string timer() { clock_t end_time = clock(); double interval = (double)(end_time - start_time)/CLOCKS_PER_SEC; ostringstream os; os << " (" << interval*1000 << " msec)"; return os.str(); }

template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
int verify_case(const double &Expected, const double &Received) { double diff = Expected - Received; if (diff < 0) diff = -diff; if (diff < 1e-9) cerr << "PASSED" << timer() << endl; else { cerr << "FAILED" << timer() << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } return 0;}

template<int N> struct Case_ {};
char Test_(...);
int Test_(Case_<0>) {
	timer_clear();
	int A = 1; 
	int B = 1; 
	double RetVal = 0.5; 
	return verify_case(RetVal, MaxTriangle().calculateArea(A, B)); }
int Test_(Case_<1>) {
	timer_clear();
	int A = 3; 
	int B = 7; 
	double RetVal = -1.0; 
	return verify_case(RetVal, MaxTriangle().calculateArea(A, B)); }
int Test_(Case_<2>) {
	timer_clear();
	int A = 41; 
	int B = 85; 
	double RetVal = 29.5; 
	return verify_case(RetVal, MaxTriangle().calculateArea(A, B)); }
int Test_(Case_<3>) {
	timer_clear();
	int A = 2000000000; 
	int B = 2000000000; 
	double RetVal = 29.5; 
	return verify_case(RetVal, MaxTriangle().calculateArea(A, B)); }


template<int N> void Run_() { cerr << "Test Case #" << N << "..." << flush; Test_(Case_<N>()); Run_<sizeof(Test_(Case_<N+1>()))==1 ? -1 : N+1>(); }
template<>      void Run_<-1>() {}
int main() { Run_<0>(); }
// END CUT HERE


// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// A triangle with positive area has been positioned on the plane in such a way that all of its vertices are located at integer coordinates. The lengths of two sides of this triangle are equal to sqrt(A) and sqrt(B), where sqrt(X) denotes the square root of X. Return the maximum area this triangle can have. If there is no such triangle, return -1 instead.

DEFINITION
Class:MaxTriangle
Method:calculateArea
Parameters:int, int
Returns:double
Method signature:double calculateArea(int A, int B)


NOTES
-The returned value must be accurate to within a relative or absolute value of 1E-9.


CONSTRAINTS
-A and B will each be between 1 and 2000000000, inclusive.


EXAMPLES

0)
1
1

Returns: 0.5

1)
3
7

Returns: -1.0

2)
41
85

Returns: 29.5

One possible triangle has vertices at (-1, 1), (6, -5) and (10, 0).

*/
// END CUT HERE
