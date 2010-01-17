#line 2 "LeaguePicks.cpp"
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

class LeaguePicks {
	public:
	vector <int> returnPicks(int position, int friends, int picks) {
		
	}
};

// BEGIN CUT HERE
#include <time.h>
clock_t start_time;
void timer_clear() { start_time = clock(); }
string timer() { clock_t end_time = clock(); double interval = (double)(end_time - start_time)/CLOCKS_PER_SEC; ostringstream os; os << " (" << interval*1000 << " msec)"; return os.str(); }

template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
int verify_case(const vector <int> &Expected, const vector <int> &Received) { if (Expected == Received) cerr << "PASSED" << timer() << endl; else { cerr << "FAILED" << timer() << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } return 0;}

template<int N> struct Case_ {};
char Test_(...);
int Test_(Case_<0>) {
	timer_clear();
	int position = 3; 
	int friends = 6; 
	int picks = 15; 
	int RetVal_[] = { 3,  10,  15 };
	  vector <int> RetVal(RetVal_, RetVal_+sizeof(RetVal_)/sizeof(*RetVal_)); 
	return verify_case(RetVal, LeaguePicks().returnPicks(position, friends, picks)); }
int Test_(Case_<1>) {
	timer_clear();
	int position = 1; 
	int friends = 1; 
	int picks = 10; 
	int RetVal_[] = { 1,  2,  3,  4,  5,  6,  7,  8,  9,  10 };
	  vector <int> RetVal(RetVal_, RetVal_+sizeof(RetVal_)/sizeof(*RetVal_)); 
	return verify_case(RetVal, LeaguePicks().returnPicks(position, friends, picks)); }
int Test_(Case_<2>) {
	timer_clear();
	int position = 1; 
	int friends = 2; 
	int picks = 39; 
	int RetVal_[] = { 1,  4,  5,  8,  9,  12,  13,  16,  17,  20,  21,  24,  25,  28,  29,  32,  33,  36,  37 };
	  vector <int> RetVal(RetVal_, RetVal_+sizeof(RetVal_)/sizeof(*RetVal_)); 
	return verify_case(RetVal, LeaguePicks().returnPicks(position, friends, picks)); }
int Test_(Case_<3>) {
	timer_clear();
	int position = 5; 
	int friends = 11; 
	int picks = 100; 
	int RetVal_[] = { 5,  18,  27,  40,  49,  62,  71,  84,  93 };
	  vector <int> RetVal(RetVal_, RetVal_+sizeof(RetVal_)/sizeof(*RetVal_)); 
	return verify_case(RetVal, LeaguePicks().returnPicks(position, friends, picks)); }

template<int N> void Run_() { cerr << "Test Case #" << N << "..." << flush; Test_(Case_<N>()); Run_<sizeof(Test_(Case_<N+1>()))==1 ? -1 : N+1>(); }
template<>      void Run_<-1>() {}
int main() { Run_<0>(); }
// END CUT HERE


// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
//  You and your friends are setting up a fantasy TopCoder league, where you choose coders to be on your team and score points in the league when any one of your coders wins their room or successfully challenges somebody, etc. To be fair, a system has been developed to choose the order in which picks are distributed. It works like this: first, lots are drawn to choose your position in the league. Then the player with the first position gets first pick, the second player gets second pick, all the way until the last player picks. Then the order reverses: the last player chooses again, then the next to last player, and so on, until you reach the first player again. Then the cycle repeats: the first position chooses again, then the second, and so on.
 For example: say you were in the third position on a 6 player league. You would get the 3rd pick, then you'd wait until the 10th pick (the order would be 1,2,you,4,5,6,6,5,4,you), and then the 15th pick, and so on until there were no more coders to choose. If there were 20 total picks, then you would get pick numbers 3,10,15.
Not wanting to miss your chance at a pick, your goal is to write a program that tells you what pick numbers you have in the order that you have them. You will receive three ints indicating your position in the league(1 being the first position), the number of friends that are in the league with you, and the number of picks that are being divvied up among the league. You will return an vector <int> that indicates the picks that you receive in ascending order.

DEFINITION
Class:LeaguePicks
Method:returnPicks
Parameters:int, int, int
Returns:vector <int>
Method signature:vector <int> returnPicks(int position, int friends, int picks)


NOTES
-Note that your position in the league and the pick numbers start at 1 and not 0. This should be clear from the examples.


CONSTRAINTS
-position will be between 1 and friends inclusive.
-friends will be between 1 and 40 inclusive.
-picks will be between 1 and 40 * friends inclusive.


EXAMPLES

0)
3
6
15

Returns: { 3,  10,  15 }

Example from above.

1)
1
1
10

Returns: { 1,  2,  3,  4,  5,  6,  7,  8,  9,  10 }

You're the only player, so you get all the picks.

2)
1
2
39

Returns: { 1,  4,  5,  8,  9,  12,  13,  16,  17,  20,  21,  24,  25,  28,  29,  32,  33,  36,  37 }

You'll get the 1st and 4th picks in every set of 4.

3)
5
11
100

Returns: { 5,  18,  27,  40,  49,  62,  71,  84,  93 }

You'll get the 5th and (2*11-5+1) or 18th picks out of every 2*11 picks.

*/
// END CUT HERE
