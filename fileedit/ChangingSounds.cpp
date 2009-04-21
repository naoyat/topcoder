#line 2 "ChangingSounds.cpp"
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
#define sz(a)  int((a).size())
#define rep(var,n)  for(int var=0;var<(n);var++)
// BEGIN CUT HERE
/*
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<string> vs;
typedef vector<long long> vll;
#define pb  push_back
#define all(c)  (c).begin(),(c).end()
#define mset(arr,val)  memset(arr,val,sizeof(arr))
#define tr(c,i)  for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); i++)
#define forr(var,from,to) for(int var=(from);var<=(to);var++) 
#define found(s,e)  ((s).find(e)!=(s).end())
#define remove_(c,val) (c).erase(remove((c).begin(),(c).end(),(val)),(c).end())
#define lastc(str) (*((str).end()-1))
*/
// END CUT HERE
class ChangingSounds {
 public:
  int maxFinal(vector<int> changeIntervals, int beginLevel, int maxLevel) {
	int n=sz(changeIntervals);
    bool lev[2][maxLevel+1];
    rep(i,maxLevel+1) lev[0][i]=lev[1][i]=false;
    lev[0][beginLevel]=true;
    rep(s,n){
      int ci=changeIntervals[s];
      rep(i,maxLevel+1) lev[(s+1)%2][i]=false;
      rep(i,maxLevel+1) {
        if(lev[s%2][i]){
          if(i+ci<=maxLevel) lev[(s+1)%2][i+ci]=true;
          if(i-ci>=0) lev[(s+1)%2][i-ci]=true;
        }
      }
    }
    for(int i=maxLevel;i>=0;i--){
      if(lev[n%2][i]) return i;
    }
    return -1;
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
	int changeIntervals_[] = {5, 3, 7};
	  vector <int> changeIntervals(changeIntervals_, changeIntervals_+sizeof(changeIntervals_)/sizeof(*changeIntervals_)); 
	int beginLevel = 5; 
	int maxLevel = 10; 
	int RetVal = 10; 
	return verify_case(RetVal, ChangingSounds().maxFinal(changeIntervals, beginLevel, maxLevel)); }
int Test_(Case_<1>) {
	timer_clear();
	int changeIntervals_[] = {15, 2, 9, 10};
	  vector <int> changeIntervals(changeIntervals_, changeIntervals_+sizeof(changeIntervals_)/sizeof(*changeIntervals_)); 
	int beginLevel = 8; 
	int maxLevel = 20; 
	int RetVal = -1; 
	return verify_case(RetVal, ChangingSounds().maxFinal(changeIntervals, beginLevel, maxLevel)); }
int Test_(Case_<2>) {
	timer_clear();
	int changeIntervals_[] = {74,39,127,95,63,140,99,96,154,18,137,162,14,88};
	  vector <int> changeIntervals(changeIntervals_, changeIntervals_+sizeof(changeIntervals_)/sizeof(*changeIntervals_)); 
	int beginLevel = 40; 
	int maxLevel = 243; 
	int RetVal = 238; 
	return verify_case(RetVal, ChangingSounds().maxFinal(changeIntervals, beginLevel, maxLevel)); }

template<int N> void Run_() { cerr << "Test Case #" << N << "..." << flush; Test_(Case_<N>()); Run_<sizeof(Test_(Case_<N+1>()))==1 ? -1 : N+1>(); }
template<>      void Run_<-1>() {}
int main() { Run_<0>(); }
// END CUT HERE


// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// You are a guitar player and you are going to play a concert.  You don't like to play all the songs at the same volume, so you decide to change the volume level of your guitar before each new song.  Before the concert begins, you make a list of the number of intervals you will be changing your volume level by before each song.  For each volume change, you will decide whether to add that number of intervals to the volume, or substract it.

You are given a vector <int> changeIntervals, the i-th element of which is the number of intervals you will change your volume by before the i-th song. You are also given an int beginLevel, the initial volume of your guitar, and an int maxLevel, the highest volume setting of your guitar. You cannot change the volume of your guitar to a level above maxLevel or below 0 (but exactly 0 is no problem). Return the maximum volume you can use to play the last song. If there is no way to go through the list without exceeding maxLevel or going below 0, return -1.


DEFINITION
Class:ChangingSounds
Method:maxFinal
Parameters:vector <int>, int, int
Returns:int
Method signature:int maxFinal(vector <int> changeIntervals, int beginLevel, int maxLevel)


CONSTRAINTS
-changeIntervals will contain between 1 and 50 elements, inclusive.
-Each element of changeIntervals will be between 1 and maxLevel, inclusive.
-maxLevel will be between 1 and 1000, inclusive.
-beginLevel will be between 0 and maxLevel, inclusive.


EXAMPLES

0)
{5, 3, 7}
5
10

Returns: 10

First we turn the volume down to 0 (-5), then we turn it up to 3 (+3), and then up to 10 (+7) for the last song.

1)
{15, 2, 9, 10}
8
20

Returns: -1

Adding 15 to 8 or substracting 15 from 8 both give an invalid sound level.

2)
{74,39,127,95,63,140,99,96,154,18,137,162,14,88}
40
243

Returns: 238



*/
// END CUT HERE
