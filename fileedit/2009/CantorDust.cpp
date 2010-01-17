#line 2 "CantorDust.cpp"
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

template <typename T> T expt(T x, int n) // x^n
{
  T y=1; for(int i=0;i<n;i++) y*=x; return y;
}

class CantorDust {
  int w,h;
  vector<ll> p;
  ll bin(string pat){
    ll b=0;
    for(ll i=0,m=1LL;i<w;i++,m<<=1){
      if(pat[w-i-1]=='X') b|=m;
    }
    return b;
  }
  int on1(int time){
    int hh=expt(3,time), ww=hh;
    vector<ll> pp(hh,0LL);
    pp[0]=pp[2]=5; // 1
    if(time>=2){
      pp[0]*=65; pp[2]*=65;
      pp[6]=pp[0]; pp[8]=pp[2];
    }
    if(time==3){
      ll mg=(1LL<<18)+1;
      pp[0]*=mg; pp[2]*=mg; pp[6]*=mg; pp[8]*=mg;
      pp[18]=pp[0]; pp[20]=pp[2]; pp[24]=pp[6]; pp[26]=pp[8];
    }
// BEGIN CUT HERE
    cout << "pp:" << pp << endl;
    cout << "p:" << p << endl;
// END CUT HERE
    if(ww<w || hh<h) return 0;
    int cnt=0;
    rep(sj,hh-h+1){
      rep(si,ww-w+1){
        int cj=0;
        rep(j,h){
          ll mk = ((1LL << w)-1) << si;
          if ((pp[sj+j] & mk) == p[j] << si) cj++;
        }
        if (cj==h) cnt++;
      }
    }
    return cnt;
  }
  int on2(int time){
    return 0;
  }
 public:
  int occurrencesNumber(vector<string> pattern, int time) {
    h=sz(pattern); w=sz(pattern[0]);
    p.resize(h);
    rep(i,h){
      p[i]=bin(pattern[i]);
    }
	if (time<=3){
      return on1(time);
    }else{
      return on2(time);
    }
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
	string pattern_[] = {".X",".."};
	  vector <string> pattern(pattern_, pattern_+sizeof(pattern_)/sizeof(*pattern_)); 
	int time = 1; 
	int RetVal = 1; 
	return verify_case(RetVal, CantorDust().occurrencesNumber(pattern, time)); }
int Test_(Case_<1>) {
	timer_clear();
	string pattern_[] = {".."};
	  vector <string> pattern(pattern_, pattern_+sizeof(pattern_)/sizeof(*pattern_)); 
	int time = 1; 
	int RetVal = 2; 
	return verify_case(RetVal, CantorDust().occurrencesNumber(pattern, time)); }
int Test_(Case_<2>) {
	timer_clear();
	string pattern_[] = {"."};
	  vector <string> pattern(pattern_, pattern_+sizeof(pattern_)/sizeof(*pattern_)); 
	int time = 2; 
	int RetVal = 65; 
	return verify_case(RetVal, CantorDust().occurrencesNumber(pattern, time)); }
int Test_(Case_<3>) {
	timer_clear();
	string pattern_[] = {"X...X"};
	  vector <string> pattern(pattern_, pattern_+sizeof(pattern_)/sizeof(*pattern_)); 
	int time = 2; 
	int RetVal = 4; 
	return verify_case(RetVal, CantorDust().occurrencesNumber(pattern, time)); }
int Test_(Case_<4>) {
	timer_clear();
	string pattern_[] = {"X"};
	  vector <string> pattern(pattern_, pattern_+sizeof(pattern_)/sizeof(*pattern_)); 
	int time = 9; 
	int RetVal = 262144; 
	return verify_case(RetVal, CantorDust().occurrencesNumber(pattern, time)); }

template<int N> void Run_() { cerr << "Test Case #" << N << "..." << flush; Test_(Case_<N>()); Run_<sizeof(Test_(Case_<N+1>()))==1 ? -1 : N+1>(); }
template<>      void Run_<-1>() {}
int main() { Run_<0>(); }
// END CUT HERE


// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// Cantor dust is a 2-dimensional fractal constructed in the following way. Initially the fractal is a black square. At each iteration, each square of the fractal is divided into a 3x3 subgrid of equal subsquares.
Any black subsquares which belong to the middle row or to the middle column of a subgrid (or to both of them) are painted white.

You are given a vector <string> pattern which represents a rectangular pattern of black and white squares (represented by 'X' and '.' characters, respectively). Return the number of occurrences of this pattern in Cantor dust at iteration time. Overlapping occurrences are allowed.

DEFINITION
Class:CantorDust
Method:occurrencesNumber
Parameters:vector <string>, int
Returns:int
Method signature:int occurrencesNumber(vector <string> pattern, int time)


CONSTRAINTS
-time will be between 1 and 9, inclusive.
-pattern will contain between 1 and min(50, 3time) elements, inclusive.
-Each element of pattern will contain between 1 and min(50, 3time) characters, inclusive.
-All elements of pattern will contain the same number of characters.
-Each character in each element of pattern will be '.' or 'X'.


EXAMPLES

0)
{".X",".."}
1

Returns: 1

1)
{".."}
1

Returns: 2

2)
{"."}
2

Returns: 65

3)
{"X...X"}
2

Returns: 4

4)
{"X"}
9

Returns: 262144



*/
// END CUT HERE
