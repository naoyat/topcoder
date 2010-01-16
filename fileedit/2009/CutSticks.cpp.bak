#line 2 "CutSticks.cpp"
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
#define cons(x,y) make_pair((x),(y))
#define car(x) ((x).first)
#define cdr(x) ((x).second)
#define cadr(x) (x).second.first
#define cddr(x) (x).second.second

class CutSticks {
  int N, mq, C, K;
  vector<double> s;
  int MAX;
  
 public:
  int f(double x){
    //vector<int> ct(N,0);
    int cutcnt=0,sum=0;
    rep(j,N){
      double sx = s[j]/x;
      int cut;
      if (sx >= (double)MAX) cut = MAX;
      else cut=(int)sx;
      if (cut==0) continue;
      if(cut>=2) cutcnt+=(cut-1);
      if(cut>=1) sum+=cut;
      //      printf("f(%g) #%d: %g / %g = %g, cut=%d\n", x,j, s[j],x,sx,cut);
    }
    //    printf("f(%g): cutcnt=%d,sum=%d - %d\n", x,cutcnt,sum, cutcnt-C);
    if (cutcnt > C) sum -= (cutcnt - C);
    if (sum>=K) return 1;
    return 0;
  }
  double md(double l, double h) {
    if (!f(l)) return -1;
    if (f(h)) return -1;
    double m=(l+h)/2;
    if (abs(h-l) < 1e-12) return m;
    //    printf("md(%g,%g) ;; %d %d\n", l,h, f(l),f(h));
    if (f(m)) return md(m,h);
    else return md(l,m);
  }
  double maxKth(vector <int> sticks, int c, int k) {
    N=sz(sticks); C=c; K=k;
    MAX = INT_MAX/N;
    sort(all(sticks)); reverse(all(sticks));
    s.resize(N); rep(i,N) s[i]=(double)sticks[i];
    
    if(K<N) return s[K-1];
    mq=K-N;
    double r= md(1e-12,s[0]);
    //cout << " => " << r << endl;
    return r;
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
	int sticks_[] = {5, 8};
	  vector <int> sticks(sticks_, sticks_+sizeof(sticks_)/sizeof(*sticks_)); 
	int C = 1; 
	int K = 1; 
	double RetVal = 8.0; 
	return verify_case(RetVal, CutSticks().maxKth(sticks, C, K)); }
int Test_(Case_<1>) {
	timer_clear();
	int sticks_[] = {5, 8};
	  vector <int> sticks(sticks_, sticks_+sizeof(sticks_)/sizeof(*sticks_)); 
	int C = 1; 
	int K = 2; 
	double RetVal = 5.0; 
	return verify_case(RetVal, CutSticks().maxKth(sticks, C, K)); }
int Test_(Case_<2>) {
	timer_clear();
	int sticks_[] = {5, 8};
	  vector <int> sticks(sticks_, sticks_+sizeof(sticks_)/sizeof(*sticks_)); 
	int C = 1; 
	int K = 3; 
	double RetVal = 4.0; 
	return verify_case(RetVal, CutSticks().maxKth(sticks, C, K)); }
int Test_(Case_<3>) {
	timer_clear();
	int sticks_[] = {1000000000, 1000000000, 1};
	  vector <int> sticks(sticks_, sticks_+sizeof(sticks_)/sizeof(*sticks_)); 
	int C = 2; 
	int K = 5; 
	double RetVal = 1.0; 
	return verify_case(RetVal, CutSticks().maxKth(sticks, C, K)); }
int Test_(Case_<5>) {
	timer_clear();
	int sticks_[] = {1000000000,1000000000,1000000000,1000000000,1000000000,
                     1000000000,1000000000,1000000000,1000000000,1000000000,
                     1000000000,1000000000,1000000000,1000000000,1000000000,
                     1000000000,1000000000,1000000000,1000000000,1000000000,
                     1000000000,1000000000,1000000000,1000000000,1000000000,
                     1000000000,1000000000,1000000000,1000000000,1000000000,
                     1000000000,1000000000,1000000000,1000000000,1000000000,
                     1000000000,1000000000,1000000000,1000000000,1000000000,
                     1000000000,1000000000,1000000000,1000000000,1000000000,
                     1000000000,1000000000,1000000000,1000000000,1 };
	  vector <int> sticks(sticks_, sticks_+sizeof(sticks_)/sizeof(*sticks_)); 
	int C = 1; 
	int K = 51; 
	double RetVal = 1.0; 
	return verify_case(RetVal, CutSticks().maxKth(sticks, C, K)); }

int Test_(Case_<4>) {
	timer_clear();
	int sticks_[] = {76, 594, 17, 6984, 26, 57, 9, 876, 5816, 73, 969, 527, 49};
	  vector <int> sticks(sticks_, sticks_+sizeof(sticks_)/sizeof(*sticks_)); 
	int C = 789; 
	int K = 456; 
	double RetVal = 34.92; 
	return verify_case(RetVal, CutSticks().maxKth(sticks, C, K)); }

template<int N> void Run_() { cerr << "Test Case #" << N << "..." << flush; Test_(Case_<N>()); Run_<sizeof(Test_(Case_<N+1>()))==1 ? -1 : N+1>(); }
template<>      void Run_<-1>() {}
int main() { Run_<0>(); }
// END CUT HERE


// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// John has some sticks of various lengths. You are given a vector <int> sticks, where each element is the length of a single stick.


He is allowed to perform at most C cuts. With each cut, he chooses one of his sticks and divides it into exactly two sticks of arbitrary positive lengths (the sum of their lengths must equal the length of the original stick). Each of these sticks can then be chosen again when making subsequent cuts.


After he performs all his cuts, he sorts the sticks in non-increasing order by length and chooses the K-th (1-based) stick. Return the maximal possible length of the stick he chooses. Note that he must perform at least as many cuts as are required to end up with K or more sticks.

DEFINITION
Class:CutSticks
Method:maxKth
Parameters:vector <int>, int, int
Returns:double
Method signature:double maxKth(vector <int> sticks, int C, int K)


NOTES
-Your return value must have an absolute or relative error less than 1e-9.


CONSTRAINTS
-sticks will contain between 1 and 50 elements, inclusive.
-Each element of sticks will be between 1 and 1,000,000,000, inclusive.
-C will be between 1 and 1,000,000,000, inclusive.
-K will be between 1 and n + C, inclusive, where n is the number of elements in sticks.


EXAMPLES

0)
{5, 8}
1
1

Returns: 8.0

John can make at most one cut.  He should either cut the stick of length 5 (it doesn't matter where) or not make any cuts at all.  If he makes no cuts, then after he sorts the sticks, they will be in the following order: {8, 5}.  He chooses the 1st stick, which has length 8.

1)
{5, 8}
1
2

Returns: 5.0

Again, the easiest thing to do here is not make any cuts.

2)
{5, 8}
1
3

Returns: 4.0

John has 2 sticks and he can make at most one cut.  In this case, since K is 3, he is required to make a cut so he can end up with 3 sticks.  He should cut the longest stick into two equal sticks of length 4.  After he sorts the sticks, they will be in the following order: {5, 4, 4}.  He will choose the 3rd stick, which has length 4.

3)
{1000000000, 1000000000, 1}
2
5

Returns: 1.0



4)
{76, 594, 17, 6984, 26, 57, 9, 876, 5816, 73, 969, 527, 49}
789
456

Returns: 34.92



*/
// END CUT HERE
