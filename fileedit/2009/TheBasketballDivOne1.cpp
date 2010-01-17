#line 2 "TheBasketballDivOne.cpp"
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
#define pb  push_back
#define all(c)  (c).begin(),(c).end()
#define tr(c,i)  for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); i++)
#define rep(var,n)  for(int var=0;var<(n);var++)

class TheBasketballDivOne {
 public:
  int find(int n, int m) {
	int matches=n*(n-1); // [2-5][1-4] = [2-20]
    if (m > 2*(n-1)) return 0;

    int h = matches/2;
    int mx = (1 << h)-1, ma = (1 << matches)-1;
    int xx = (1 << h)|1;

    vector<vector<int> > ms(n,vector<int>(2));
    ms[0][0] = 0x04b & mx, ms[0][1] = 0x000 & mx; // 4+0
    ms[1][0] = 0x094 & mx, ms[1][1] = 0x001 & mx; // 3+1
    if (n>=3) {
      ms[2][0] = 0x120 & mx, ms[2][1] = 0x006 & mx; // 2+2
      if (n>=4) {
        ms[3][0] = 0x200 & mx, ms[3][1] = 0x038 & mx; // 1+3
        if (n>=5) {
          ms[4][0] = 0x000 & mx, ms[4][1] = 0x3c0 & mx; // 0+4
        }
      }
    }

    rep(i,n) rep(j,2) ms[i][j] *= xx;
    
    //cout << matches << " " << mx << " " << ma << endl;
    //cout << ms << endl;
    vector<int> win(n,0);
    set<vector<int> > s;
    for (int i=0;i<=ma;i++) {
      rep(j,n){
        win[j] = __builtin_popcount(i & ms[j][0])
            + __builtin_popcount((~i) & ms[j][1]);
      }
      sort(all(win));
      s.insert(win);
    }
    int cnt=0;
    tr(s,it){
      if ((*it)[n-1] == m) {
        //cout << " - " << *it << endl;
        cnt++;
      }
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
int verify_case(const int &Expected, const int &Received) { if (Expected == Received) cerr << "PASSED" << timer() << endl; else { cerr << "FAILED" << timer() << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } return 0;}

template<int N> struct Case_ {};
char Test_(...);
int Test_(Case_<0>) {
	timer_clear();
	int n = 2; 
	int m = 1; 
	int RetVal = 1; 
	return verify_case(RetVal, TheBasketballDivOne().find(n, m)); }
int Test_(Case_<1>) {
	timer_clear();
	int n = 3; 
	int m = 1; 
	int RetVal = 0; 
	return verify_case(RetVal, TheBasketballDivOne().find(n, m)); }
int Test_(Case_<2>) {
	timer_clear();
	int n = 3; 
	int m = 3; 
	int RetVal = 2; 
	return verify_case(RetVal, TheBasketballDivOne().find(n, m)); }
int Test_(Case_<3>) {
	timer_clear();
	int n = 4; 
	int m = 6; 
	int RetVal = 5; 
	return verify_case(RetVal, TheBasketballDivOne().find(n, m)); }
int Test_(Case_<4>) {
	timer_clear();
	int n = 5; 
	int m = 9; 
	int RetVal = 0;
	return verify_case(RetVal, TheBasketballDivOne().find(n, m)); }
int Test_(Case_<5>) {
	timer_clear();
	int n = 5; 
	int m = 8; 
	int RetVal = 16;  // ??
	return verify_case(RetVal, TheBasketballDivOne().find(n, m)); }
int Test_(Case_<6>) {
	timer_clear();
	int n = 5; 
	int m = 4; 
	int RetVal = 1;
	return verify_case(RetVal, TheBasketballDivOne().find(n, m)); }

template<int N> void Run_() { cerr << "Test Case #" << N << "..." << flush; Test_(Case_<N>()); Run_<sizeof(Test_(Case_<N+1>()))==1 ? -1 : N+1>(); }
template<>      void Run_<-1>() {}
int main() { Run_<0>(); }
// END CUT HERE


// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
John and Brus have an interest in team sports tournaments.
They are currently investigating a basketball tournament.
Basketball is a team sport in which two teams of five players try to score points against one another by placing a ball through a ten foot high hoop.
Basketball is one of the most popular and widely viewed sports in the world.



There are n teams in the tournament. Each pair of teams plays exactly two games against each other. Each game results in one team winning.  There are no draws.
After the tournament is over, the team with the highest total number of wins takes 1st place, the team with the second highest number of wins takes 2nd place, and so on.



A sequence of integers W1, W2, ..., Wn is called a W-sequence if there exists a tournament where the team that took i-th place has exactly Wi total wins (for all i between 1 and n, inclusive).
Given ints n and m, return the number of W-sequences consisting of n integers where W1 = m.


DEFINITION
Class:TheBasketballDivOne
Method:find
Parameters:int, int
Returns:int
Method signature:int find(int n, int m)


CONSTRAINTS
-n will be between 2 and 5, inclusive.
-m will be between 1 and 9, inclusive.


EXAMPLES

0)
2
1

Returns: 1

The only possible W-sequence is (1, 1).

1)
3
1

Returns: 0

There is no valid outcome where the winning team has just one win.

2)
3
3

Returns: 2

The two possible sequences are (3, 2, 1) and (3, 3, 0).

3)
4
6

Returns: 5



*/
// END CUT HERE
