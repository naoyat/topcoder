#line 2 "TheSoccerDivOne.cpp"
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

class TheSoccerDivOne {
	public:
	int find(vector <int> points) {
		
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
	int points_[] = {5, 17};
	  vector <int> points(points_, points_+sizeof(points_)/sizeof(*points_)); 
	int RetVal = 1; 
	return verify_case(RetVal, TheSoccerDivOne().find(points)); }
int Test_(Case_<1>) {
	timer_clear();
	int points_[] = {5, 18, 21, 19};
	  vector <int> points(points_, points_+sizeof(points_)/sizeof(*points_)); 
	int RetVal = 4; 
	return verify_case(RetVal, TheSoccerDivOne().find(points)); }
int Test_(Case_<2>) {
	timer_clear();
	int points_[] = {4, 1, 5};
	  vector <int> points(points_, points_+sizeof(points_)/sizeof(*points_)); 
	int RetVal = 1; 
	return verify_case(RetVal, TheSoccerDivOne().find(points)); }
int Test_(Case_<3>) {
	timer_clear();
	int points_[] = {4, 16, 4, 16, 16};
	  vector <int> points(points_, points_+sizeof(points_)/sizeof(*points_)); 
	int RetVal = 2; 
	return verify_case(RetVal, TheSoccerDivOne().find(points)); }

template<int N> void Run_() { cerr << "Test Case #" << N << "..." << flush; Test_(Case_<N>()); Run_<sizeof(Test_(Case_<N+1>()))==1 ? -1 : N+1>(); }
template<>      void Run_<-1>() {}
int main() { Run_<0>(); }
// END CUT HERE


// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
John and Brus have an interest in team sports tournaments.
They are investigating a soccer tournament that is currently in progress.
Soccer is a team sport played between two teams of eleven players using a spherical ball.
It is the most popular football variant worldwide, and is widely considered to be the most popular sport in the world.



In this tournament, each game results in either a victory for one team or a draw.
If a team wins a game, it gains three points and its opponent gains no points.
In case of a draw, each team gains one point.
The score of a team is the sum of all the points it has gained from all its games.
Each pair of teams can play against each other any number of times.



You are given a vector <int> points representing the current standings in the tournament.
The i-th element of points is the score of the i-th team.
You can assume that the points represent a valid state, i.e., intermediate standings that can be achieved in a tournament according to the rules described above.



Each team will play exactly four more games in the tournament, but it is not known what the matchups will be.
This means that every distribution of the remaining games is potentially possible.
In particular, the same pair of teams might play more than one game against each other.
After the tournament is over, the teams will be ranked by score.
1st place will go to the team with the highest score, 2nd place will go to the team with the second highest score, and so on.
If two teams have the same score, the team with the lower number will place higher.
For example, if team 0 and team 3 each have the highest score of 100 points, then team 0 will place 1st and team 3 will place 2nd.



John's favorite team is team 0, and he wants it to place as high as possible.
Assuming that the remaining games can be scheduled arbitrarily and can end with any possible outcome, return the highest possible place for team 0 at the end of the tournament.



DEFINITION
Class:TheSoccerDivOne
Method:find
Parameters:vector <int>
Returns:int
Method signature:int find(vector <int> points)


CONSTRAINTS
-points will contain between 2 and 50 elements, inclusive.
-Each element of points will be between 0 and 1,000,000, inclusive.
-points will represent a valid state.


EXAMPLES

0)
{5, 17}

Returns: 1

If team 0 wins all its remaining games, it will end up with a score of 17.
Team 1 will also have 17 points, but according to the tie breaker rules, team 0 will get first place.

1)
{5, 18, 21, 19}

Returns: 4

John's favorite team has too few points here to rise above last place.


2)
{4, 1, 5}

Returns: 1

It will be easy for John's favorite team to get to the top of the standings after the remaining games.

3)
{4, 16, 4, 16, 16}

Returns: 2

*/
// END CUT HERE
