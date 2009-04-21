#line 2 "BarbarianInvasion.cpp"
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

class BarbarianInvasion {
 public:
  int minimalDetachment(vector<string> cMap, vector<int> dSize) {
    int h=sz(cMap),w=sz(cMap[0]); // 3-50
	int x,y;
    rep(i,h) rep(j,w) if(cMap[i][j]=='*') {x=j;y=i;break;}
    cout << cMap << endl;
    cout << dSize << endl;
    cout << x << "," << y << endl;
    return 0;
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
	string countryMap_[] = {"ABA",
 "A*A",
 "AAA"};
	  vector <string> countryMap(countryMap_, countryMap_+sizeof(countryMap_)/sizeof(*countryMap_)); 
	int detachmentSize_[] = {1,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
	  vector <int> detachmentSize(detachmentSize_, detachmentSize_+sizeof(detachmentSize_)/sizeof(*detachmentSize_)); 
	int RetVal = 5; 
	return verify_case(RetVal, BarbarianInvasion().minimalDetachment(countryMap, detachmentSize)); }
int Test_(Case_<1>) {
	timer_clear();
	string countryMap_[] = {"CCCC",
 "-BAC",
 "-*AC",
 "--AC"};
	  vector <string> countryMap(countryMap_, countryMap_+sizeof(countryMap_)/sizeof(*countryMap_)); 
	int detachmentSize_[] = {5,20,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
	  vector <int> detachmentSize(detachmentSize_, detachmentSize_+sizeof(detachmentSize_)/sizeof(*detachmentSize_)); 
	int RetVal = 25; 
	return verify_case(RetVal, BarbarianInvasion().minimalDetachment(countryMap, detachmentSize)); }
int Test_(Case_<2>) {
	timer_clear();
	string countryMap_[] = {"A----A",
 "-AAAA-",
 "-AA*A-",
 "-AAAA-",
 "A----A"};
	  vector <string> countryMap(countryMap_, countryMap_+sizeof(countryMap_)/sizeof(*countryMap_)); 
	int detachmentSize_[] = {9,8,2,5,3,2,1,2,6,10,4,6,7,1,7,8,8,8,2,9,7,6,5,1,5,10};
	  vector <int> detachmentSize(detachmentSize_, detachmentSize_+sizeof(detachmentSize_)/sizeof(*detachmentSize_)); 
	int RetVal = 0; 
	return verify_case(RetVal, BarbarianInvasion().minimalDetachment(countryMap, detachmentSize)); }
int Test_(Case_<3>) {
	timer_clear();
	string countryMap_[] = {"-A-----",
 "-BCCC*-",
 "-A-----"};
	  vector <string> countryMap(countryMap_, countryMap_+sizeof(countryMap_)/sizeof(*countryMap_)); 
	int detachmentSize_[] = {1,5,10,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
	  vector <int> detachmentSize(detachmentSize_, detachmentSize_+sizeof(detachmentSize_)/sizeof(*detachmentSize_)); 
	int RetVal = 5; 
	return verify_case(RetVal, BarbarianInvasion().minimalDetachment(countryMap, detachmentSize)); }
int Test_(Case_<4>) {
	timer_clear();
	string countryMap_[] = {"WANNABRUTEFORCEMEHUH",
 "ASUDQWNHIOCASFIUQISA",
 "UWQD-ASFFC-AJSQOOWE-",
 "-----*Y--AVSSFIUQISA",
 "UWQD-ASFFC-AJSQOOWE-",
 "JUFDIFD-CHBVISBOOWE-",
 "WANNABRUTEFORCEMEHUH"};
	  vector <string> countryMap(countryMap_, countryMap_+sizeof(countryMap_)/sizeof(*countryMap_)); 
	int detachmentSize_[] = {87,78,20,43,30,12,9,18,57,93,32,60,64,9,69,74,74,78,12,81,63,57,48,8,44,95};
	  vector <int> detachmentSize(detachmentSize_, detachmentSize_+sizeof(detachmentSize_)/sizeof(*detachmentSize_)); 
	int RetVal = 218; 
	return verify_case(RetVal, BarbarianInvasion().minimalDetachment(countryMap, detachmentSize)); }

template<int N> void Run_() { cerr << "Test Case #" << N << "..." << flush; Test_(Case_<N>()); Run_<sizeof(Test_(Case_<N+1>()))==1 ? -1 : N+1>(); }
template<>      void Run_<-1>() {}
int main() { Run_<0>(); }
// END CUT HERE


// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// A kingdom is being threatened by a barbarian invasion from all sides.  It was decided that the aggressors must not reach the capital.  You are given a vector <string> countryMap containing a map of the kingdom.  The kingdom is represented as a rectangular grid of equal squares.  The j-th character of the i-th element of countryMap corresponds to the square at row i, column j.  The capital square is marked with a '*', impassable squares are marked with '-', and all other squares are marked with uppercase letters representing different types of open terrain.

You must deploy detachments to open squares in such a way that the capital square is unreachable from the border.  In other words, to ensure that no aggressors can reach the capital, each path from the border to the capital must be blocked by an impassable square or a detachment.  The enemy can only move directly north, east, south and west between open squares that share common sides.  Therefore, only consider paths where each pair of consecutive squares has a common side.

Each type of terrain requires a detachment of a certain size.  You are given a vector <int> detachmentSize, where element 0 is the size of a detachment required for each square of terrain type 'A', element 1 is the required size for terrain type 'B', and so on.  Each detachment contains a commander, and qualified commanders are hard to come by.  Therefore, your primary goal is to minimize the total number of detachments required.  If there are multiple ways to defend the capital using the minimum possible number of detachments, choose the one among them that minimizes the total size of all the detachments.  Return the total size of all the detachments.


DEFINITION
Class:BarbarianInvasion
Method:minimalDetachment
Parameters:vector <string>, vector <int>
Returns:int
Method signature:int minimalDetachment(vector <string> countryMap, vector <int> detachmentSize)


CONSTRAINTS
-countryMap will contain between 3 and 50 elements, inclusive.
-Each element of countryMap will contain between 3 and 50 elements, inclusive.
-Elements of countryMap will be of the same length.
-Each element of countryMap will contain only uppercase letters, minus signs and asterisks ('A'-'Z','-','*').
-countryMap will contain exactly one character '*'.
-The '*' character will not be in the first or last row or column of countryMap.
-detachmentSize will contain exactly 26 elements.
-Each element of detachmentSize will be between 1 and 1000000, inclusive.


EXAMPLES

0)
{"ABA",
 "A*A",
 "AAA"}
{1,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}

Returns: 5

We have no other way than blocking the squares adjacent to the capital, so the minimal total size of the detachments is 5.

1)
{"CCCC",
 "-BAC",
 "-*AC",
 "--AC"}
{5,20,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}

Returns: 25

Having enough commanders, it could be possible to block the way with 7 detachments standing on the border with the total size of 7. But our primary goal is to minimize the number of detachments, so we have to block 'B' and 'A' squares adjacent to the capital.

2)
{"A----A",
 "-AAAA-",
 "-AA*A-",
 "-AAAA-",
 "A----A"}
{9,8,2,5,3,2,1,2,6,10,4,6,7,1,7,8,8,8,2,9,7,6,5,1,5,10}

Returns: 0

There is already no way to reach the capital from the border.

3)
{"-A-----",
 "-BCCC*-",
 "-A-----"}
{1,5,10,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}

Returns: 5

Blocking 'B' is the optimal decision.

4)
{"WANNABRUTEFORCEMEHUH",
 "ASUDQWNHIOCASFIUQISA",
 "UWQD-ASFFC-AJSQOOWE-",
 "-----*Y--AVSSFIUQISA",
 "UWQD-ASFFC-AJSQOOWE-",
 "JUFDIFD-CHBVISBOOWE-",
 "WANNABRUTEFORCEMEHUH"}
{87,78,20,43,30,12,9,18,57,93,32,60,64,9,69,74,74,78,12,81,63,57,48,8,44,95}

Returns: 218



*/
// END CUT HERE
