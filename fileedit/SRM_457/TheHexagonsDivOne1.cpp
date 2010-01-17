#line 2 "TheHexagonsDivOne.cpp"
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
#define FOR(var,from,to) for(int var=(from);var<=(to);var++)
#define rep(var,n)  for(int var=0;var<(n);var++)
#define all(c)  (c).begin(),(c).end()
#define tr(c,i)  for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); i++)
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

class TheHexagonsDivOne {
  int wn,z;
 public:
  long long count(int n) {
    wn=n*2;
	// 7枠あるのです.
    if (wn < 7) return 0LL;
    // 1 .. 2n(wn); n=150で300

    ll cnt=0LL;
    int a,b,c,d,e,f;
    // center(z)選ぶ
    vector<bool> fl(wn+1,false);
    for(z=1;z<=wn;z++){
      // minimumどれ
      fl[z]=true;
      for(a=1;a<=wn-5;a++){
        if (a%n==z%n)continue;
        fl[a]=true;
        for(b=a+1;b<=wn;b++){
          if (fl[b])continue;
          if (b%n==z%n)continue;
          if (b%n==a%n)continue;
          fl[b]=true;
          for(c=a+1;c<=wn;c++){
            if (fl[c])continue;
            if (c%n==z%n)continue;
            if (c%n==b%n)continue;
            fl[c]=true;
            for(d=a+1;d<=wn;d++){
              if (fl[d])continue;
              if (d%n==z%n)continue;
              if (d%n==c%n)continue;
              fl[d]=true;
              for(e=a+1;e<=wn;e++){
                if (fl[e])continue;
                if (e%n==z%n)continue;
                if (e%n==d%n)continue;
                fl[e]=true;
                for(f=a+1;f<=wn;f++){
                  if (fl[f])continue;
                  if (f%n==z%n)continue;
                  if (f%n==e%n)continue;
                  if (f%n==a%n)continue;
                  //fl[f]=true;
                  cnt++;
                  //fl[f]=false;
                }
                fl[e]=false;
              }
              fl[d]=false;
            }
            fl[c]=false;
          }
          fl[b]=false;
        }
        fl[a]=false;
      }
      fl[z]=false;
    }
    return cnt;
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
	int n = 3; 
	long long RetVal = 0LL; 
	return verify_case(RetVal, TheHexagonsDivOne().count(n)); }
int Test_(Case_<1>) {
	timer_clear();
	int n = 4; 
	long long RetVal = 256LL; 
	return verify_case(RetVal, TheHexagonsDivOne().count(n)); }
int Test_(Case_<2>) {
	timer_clear();
	int n = 8; 
	long long RetVal = 3458560LL; 
	return verify_case(RetVal, TheHexagonsDivOne().count(n)); }
int Test_(Case_<3>) {
	timer_clear();
	int n = 20; 
	long long RetVal = 11193888000LL; 
	return verify_case(RetVal, TheHexagonsDivOne().count(n)); }

template<int N> void Run_() { cerr << "Test Case #" << N << "..." << flush; Test_(Case_<N>()); Run_<sizeof(Test_(Case_<N+1>()))==1 ? -1 : N+1>(); }
template<>      void Run_<-1>() {}
int main() { Run_<0>(); }
// END CUT HERE


// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// John and Brus are interested in a new game called "Hexagon Flower".  The rules are simple.  You are given a flower formed by seven hexagons arranged as follows:



The objective of the game is to place a number in each hexagon of the flower such that all of the following conditions are satisfied:

Each number is an integer between 1 and n*2, inclusive.
Each number is distinct.
For every pair of adjacent hexagons, if the numbers placed in them are a and b, then a%n != b%n.

Given n, return the total number of distinct solutions.  Two solutions are considered the same if you can rotate one to form the other.

For example, if n = 4 then:



The top three placements are not valid.  The other three placements are valid, but the first two among them are considered equal since one can be rotated to become the other.

DEFINITION
Class:TheHexagonsDivOne
Method:count
Parameters:int
Returns:long long
Method signature:long long count(int n)


CONSTRAINTS
-n will be between 1 and 150, inclusive.


EXAMPLES

0)
3

Returns: 0

There are not enough numbers to fill the flower with.

1)
4

Returns: 256



2)
8

Returns: 3458560



3)
20

Returns: 11193888000



*/
// END CUT HERE
