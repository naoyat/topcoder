#line 2 "TheTournamentDivOne.cpp"
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
#define lastc(str) (*((str).end()-1))


class TheTournamentDivOne {
  int N, W, D;
  
  vector<double> pat(int sum)
  {
    set<double> s;
    for(int i=0;i<=sum;i+=D){
      int rest=sum-i; if (rest%W) continue;
      s.insert(1.0*rest/W + 0.5*i/D);
    }
    return vector<double>(all(s));
  }
 public:
  bool intp(double x){ return (floor(x)==x)? true:false; }

  int find(vector<int> points, int w, int d) {
    N=sz(points); W=w; D=d;

    map<int,int> mp;
    rep(i,N) {
      int p=points[i];
      if (found(mp,p)) mp[p]++; else mp[p]=1;
    }

    vector<vector<double> > v;
    tr(mp,it){
      int sum=it->first, c=it->second;
      vector<double> ps = pat(sum);
      rep(i,sz(ps)) ps[i] *= c;
      v.pb(ps);
    }
    int vn = sz(v);
    
    double sm=0; rep(i,vn) sm+=v[i][0];
    if (intp(sm)) return (int)sm;

    vector<double> vv;
    tr(v,it){
      int n=sz(*it); if (n==1) continue;
      for(int j=1;j<n;j++){
        double df = (*it)[j] - (*it)[0];
        if (intp(df)) continue;
        vv.pb(df); break;
      }
    }
    if (sz(vv) == 0) return -1;

    sort(all(vv)); return (int)(sm + vv[0]);
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
	int points_[] = {10, 1, 1};
	  vector <int> points(points_, points_+sizeof(points_)/sizeof(*points_)); 
	int w = 2; 
	int d = 1; 
	int RetVal = 6; 
	return verify_case(RetVal, TheTournamentDivOne().find(points, w, d)); }
int Test_(Case_<1>) {
	timer_clear();
	int points_[] = {1, 1, 1};
	  vector <int> points(points_, points_+sizeof(points_)/sizeof(*points_)); 
	int w = 2; 
	int d = 1; 
	int RetVal = -1; 
	return verify_case(RetVal, TheTournamentDivOne().find(points, w, d)); }
int Test_(Case_<2>) {
	timer_clear();
	int points_[] = {1, 4, 0, 2};
	  vector <int> points(points_, points_+sizeof(points_)/sizeof(*points_)); 
	int w = 3; 
	int d = 1; 
	int RetVal = 3; 
	return verify_case(RetVal, TheTournamentDivOne().find(points, w, d)); }
int Test_(Case_<3>) {
	timer_clear();
	int points_[] = {8, 3, 8, 5, 9, 2, 7, 11};
	  vector <int> points(points_, points_+sizeof(points_)/sizeof(*points_)); 
	int w = 3; 
	int d = 2; 
	int RetVal = 15; 
	return verify_case(RetVal, TheTournamentDivOne().find(points, w, d)); }

template<int N> void Run_() { cerr << "Test Case #" << N << "..." << flush; Test_(Case_<N>()); Run_<sizeof(Test_(Case_<N+1>()))==1 ? -1 : N+1>(); }
template<>      void Run_<-1>() {}
int main() { Run_<0>(); }
// END CUT HERE


// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
John and Brus have an interest in team sports tournaments.
They are currently investigating the intermediate standings of a tournament.
They don't know which games have been played so far.
They only know that the tournament is played using the following rules:



Each game is played between two teams and results in either a victory for one team or a draw.
If a team wins a game, it gains w points and its opponent gains no points.
In case of a draw, each team gains d points.
The score of a team is the sum of all the points it has gained from all its games.
There are no restrictions on which teams can play against each other, and each pair of teams can play against each other any number of times (possibly zero).



You are given a vector <int> points representing the intermediate standings of the tournament.
The i-th element of points is the score of the i-th team.
Return the minimum number of games that could have been played to achieve those standings.
If points doesn't represent a valid state, return -1 instead.



DEFINITION
Class:TheTournamentDivOne
Method:find
Parameters:vector <int>, int, int
Returns:int
Method signature:int find(vector <int> points, int w, int d)


CONSTRAINTS
-points will contain between 2 and 50 elements, inclusive.
-Each element of points will be between 0 and 10,000, inclusive.
-w will be between 1 and 10,000, inclusive.
-d will be between 1 and w, inclusive.


EXAMPLES

0)
{10, 1, 1}
2
1

Returns: 6

The first team has five wins or four wins and two draws.
The second and the third teams each has one draw.


1)
{1, 1, 1}
2
1

Returns: -1

These standings are impossible.
For each of the three teams to have one point, each one must have played in a game that resulted in a draw.
There is no way for three teams to have each played in exactly one game.


2)
{1, 4, 0, 2}
3
1

Returns: 3

The only win goes to the second team.

3)
{8, 3, 8, 5, 9, 2, 7, 11}
3
2

Returns: 15

*/
// END CUT HERE
