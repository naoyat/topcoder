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
#define sz(a)  int((a).size())
#define pb  push_back
#define all(c)  (c).begin(),(c).end()
#define tr(c,i)  for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); i++)
#define rep(var,n)  for(int var=0;var<(n);var++)
#define found(s,e)  ((s).find(e)!=(s).end())

class CutSticks {
  ll N, mq, C, K;
  vector<double> s;
  //  ll MAX;
  
 public:
  int f(double x){
    //vector<int> ct(N,0);
    ll cutcnt=0,sum=0;
    rep(j,N){
      double sx = s[j]/x;
      ll cut;
      if (sx >= (double)INT_MAX) cut = INT_MAX;
      else cut=(ll)sx;
      if (cut==0) continue;
      if(cut>=2) cutcnt+=(cut-1);
      if(cut>=1) sum+=cut;
// BEGIN CUT HERE
      //      printf("f(%g) #%d: %g / %g = %g, cut=%d\n", x,j, s[j],x,sx,cut);
// END CUT HERE
     
    }
// BEGIN CUT HERE
    printf("f(%g): cutcnt=%lld (C=%lld), sum=%lld - %lld\n", x, cutcnt,C, sum, cutcnt-C);
// END CUT HERE
    if (cutcnt >= C) sum -= cutcnt-C;
    if (sum>=K) return 1;
    return 0;
  }
  
  double md(double l, double h) {
    if (!f(l)) return -1;
    if (f(h)) return h; //-2;
    double m=(l+h)/2;
    if ((h-l)/h < 1e-12) return m; ////
// BEGIN CUT HERE
    printf("md(%g,%g) ;; %d %d\n", l,h, f(l),f(h));
// END CUT HERE
    if (f(m)) return md(m,h);
    else return md(l,m);
  }
  double maxKth(vector<int> sticks, int c, int k) {
    N=sz(sticks); C=c; K=k;
    //    MAX = INT_MAX/N;
    sort(all(sticks)); reverse(all(sticks));
    s.resize(N); rep(i,N) s[i]=(double)sticks[i];
    
    // if(K<N) return s[K-1];// oops
    mq=K-N;
    double r= md(1e-12,s[0]);
// BEGIN CUT HERE
    cout << " => " << r << endl;
// END CUT HERE
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
int Test_(Case_<4>) {
	timer_clear();
	int sticks_[] = {76, 594, 17, 6984, 26, 57, 9, 876, 5816, 73, 969, 527, 49};
	  vector <int> sticks(sticks_, sticks_+sizeof(sticks_)/sizeof(*sticks_)); 
	int C = 789; 
	int K = 456; 
	double RetVal = 34.92; 
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

int Test_(Case_<6>) { // X
	timer_clear();
	int sticks_[] = {528, 530, 545, 525, 594, 568, 545, 528, 676, 787, 522, 544, 526, 525, 758, 4978, 534};
	  vector <int> sticks(sticks_, sticks_+sizeof(sticks_)/sizeof(*sticks_)); 
	int C = 1; 
	int K = 5;
	double RetVal = 676.0; // 594.0
	return verify_case(RetVal, CutSticks().maxKth(sticks, C, K)); }
int Test_(Case_<7>) { // X
	timer_clear();
	int sticks_[] = {549, 552, 553, 549, 551, 1327, 552, 560, 601, 576};
	  vector <int> sticks(sticks_, sticks_+sizeof(sticks_)/sizeof(*sticks_));
      int C = 26; 
	int K = 8; 
	double RetVal = 552.0; // 551.0
	return verify_case(RetVal, CutSticks().maxKth(sticks, C, K)); }
int Test_(Case_<8>) { // Y
	timer_clear();
	int sticks_[] = {8994339, 94, 411794, 47413068, 5, 38200158, 95417945, 8762, 2541955, 805, 6987, 322317, 406893, 733317, 1000000000, 1603, 5318372, 6248, 845652, 477, 681378882, 7, 910072, 1603660, 2984, 72283, 72390328, 70322789, 698996, 1000000000, 47975, 1000000000, 1056275, 99, 1000000000, 77251880, 61560504, 7, 1, 1000000000, 260675708, 559, 4155052, 240269, 3, 80098653, 32567};
	  vector <int> sticks(sticks_, sticks_+sizeof(sticks_)/sizeof(*sticks_));
      int C = 1000000000;
      int K = 1000000047;
	double RetVal = 1.0; // 551.0
	return verify_case(RetVal, CutSticks().maxKth(sticks, C, K)); }

int Test_(Case_<9>) { // Z
	timer_clear();
	int sticks_[] = {224385202, 511022696, 431407797, 368632924, 247730664, 77878030, 489898168, 391534997, 16439846, 11277806, 105940208, 307595079, 125080253, 118724975, 357135829, 239001063, 468077778, 265157776, 405092247, 439414733, 62503135, 187628895, 241733739, 358747064, 390426745, 136422084, 58533058, 317848537, 383813706, 409538624, 520123468, 300777949, 147686512, 490937549, 61492248, 119728503, 78317250, 268947293, 117384410, 420876827};
	  vector <int> sticks(sticks_, sticks_+sizeof(sticks_)/sizeof(*sticks_));
      int C = 61574;
      int K = 49;
      double RetVal = 1.537975395E8;
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
