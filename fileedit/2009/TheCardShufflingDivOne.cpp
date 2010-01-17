#line 2 "TheCardShufflingDivOne.cpp"
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

class TheCardShufflingDivOne {
  vector<int> d_main,d_left,d_right,d_result;
 public:
  int shuffle(int n, int left, int right) {
	d_main.resize(n);
    rep(i,n) d_main[i]=1+i;

    rep(i,n) {
      
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
	int n = 3; 
	int left = 0; 
	int right = 0; 
	int RetVal = 1; 
	return verify_case(RetVal, TheCardShufflingDivOne().shuffle(n, left, right)); }
int Test_(Case_<1>) {
	timer_clear();
	int n = 3; 
	int left = 1; 
	int right = 1; 
	int RetVal = 3; 
	return verify_case(RetVal, TheCardShufflingDivOne().shuffle(n, left, right)); }
int Test_(Case_<2>) {
	timer_clear();
	int n = 5; 
	int left = 0; 
	int right = 0; 
	int RetVal = 2; 
	return verify_case(RetVal, TheCardShufflingDivOne().shuffle(n, left, right)); }
int Test_(Case_<3>) {
	timer_clear();
	int n = 17; 
	int left = 12; 
	int right = 21; 
	int RetVal = 17; 
	return verify_case(RetVal, TheCardShufflingDivOne().shuffle(n, left, right)); }

template<int N> void Run_() { cerr << "Test Case #" << N << "..." << flush; Test_(Case_<N>()); Run_<sizeof(Test_(Case_<N+1>()))==1 ? -1 : N+1>(); }
template<>      void Run_<-1>() {}
int main() { Run_<0>(); }
// END CUT HERE


// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
John and Brus are training for a card game tournament.
John is practicing his shuffling technique.
John is using a deck of n cards, numbered 1 to n from top to bottom.
This initial deck is called the main deck.
There are three additional decks on the table, called the left, right and resulting decks.
These three decks are initially empty.
To shuffle the deck, John will repeat the following sequence of actions until the main deck contains less than two cards:

Move one card from the top of the main deck to the top of the left deck, then one card from the top of the main deck to the top of the right deck, then one card from top of the main deck to the top of the left deck, and so on, until the main deck is empty.
Repeat the following left times: Move one card from the top of the left deck to the bottom of the left deck.
Repeat the following right times: Move one card from the top of the right deck to the bottom of the right deck.
Move one card from the top of the left deck to the top of the resulting deck.
Move one card from the top of the right deck to the top of the resulting deck.
While the left deck is not empty, move one card from the top of the left deck to the top of the main deck.
While the right deck is not empty, move one card from the top of the right deck to the top of the main deck.

If there is one card left in the main deck, John will move it to the top of the resulting deck.
Return the number of the card at the top of the resulting deck after the shuffling is complete.



DEFINITION
Class:TheCardShufflingDivOne
Method:shuffle
Parameters:int, int, int
Returns:int
Method signature:int shuffle(int n, int left, int right)


CONSTRAINTS
-n will be between 1 and 1,000,000, inclusive.
-left and right will each be between 0 and 1,000,000, inclusive.


EXAMPLES

0)
3
0
0

Returns: 1

The resulting deck will contain cards in the same order as the main deck at the beginning.

1)
3
1
1

Returns: 3

Here the order of cards in the resulting deck (from top to bottom) will be 3, 2, 1.

2)
5
0
0

Returns: 2

3)
17
12
21

Returns: 17

*/
// END CUT HERE
