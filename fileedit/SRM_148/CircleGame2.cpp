#line 2 "CircleGame.cpp"
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
#include "cout.h" // 227.91
// END CUT HERE
using namespace std;
#define sz(a)  int((a).size())
#define pb  push_back
#define FOR(var,from,to) for(int var=(from);var<=(to);var++)
#define rep(var,n)  for(int var=0;var<(n);var++)
#define all(c)  (c).begin(),(c).end()
#define tr(c,i)  for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); i++)
#define remove_(c,val) (c).erase(remove((c).begin(),(c).end(),(val)),(c).end())

class CircleGame {
 public:
  int cardsLeft(string deck) {
    int tonum[128];
    rep(i,10) tonum['0'+i]=i;
    tonum['A']=1, tonum['T']=10, tonum['J']=11, tonum['Q']=12, tonum['K']=13;
	vector<int> dc;
    tr(deck,s){
      if(*s=='K') continue;
      dc.pb(tonum[*s]);
    }
    //cout << deck << " " << dc << endl;
    int del,left;
    do{
      del=0;
      left=sz(dc);
      //cout << dc << " => ";
      rep(i,left){
        if(dc[i]+dc[(i+1)%left]==13) {
          dc[i]=dc[(i+1)%left]=-1;
          del++;
        }
      }
      //rep(i,del)
      remove_(dc,-1);
      //cout << dc << endl;
      left=sz(dc);
    } while(del>0);
    return left;
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
	string deck = "KKKKKKKKKK"; 
	int RetVal = 0; 
	return verify_case(RetVal, CircleGame().cardsLeft(deck)); }
int Test_(Case_<1>) {
	timer_clear();
	string deck = "KKKKKAQT23"; 
	int RetVal = 1; 
	return verify_case(RetVal, CircleGame().cardsLeft(deck)); }
int Test_(Case_<2>) {
	timer_clear();
	string deck = "KKKKATQ23J"; 
	int RetVal = 6; 
	return verify_case(RetVal, CircleGame().cardsLeft(deck)); }
int Test_(Case_<3>) {
	timer_clear();
	string deck = "AT68482AK6875QJ5K9573Q"; 
	int RetVal = 4; 
	return verify_case(RetVal, CircleGame().cardsLeft(deck)); }
int Test_(Case_<4>) {
	timer_clear();
	string deck = "AQK262362TKKAQ6262437892KTTJA332"; 
	int RetVal = 24; 
	return verify_case(RetVal, CircleGame().cardsLeft(deck)); }

template<int N> void Run_() { cerr << "Test Case #" << N << "..." << flush; Test_(Case_<N>()); Run_<sizeof(Test_(Case_<N+1>()))==1 ? -1 : N+1>(); }
template<>      void Run_<-1>() {}
int main() { Run_<0>(); }
// END CUT HERE


// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// Tommy is learning a simple card game called Circle.  To play the game, the single player shuffles a deck of cards.  He or she then flips through the deck, removing all instances of the 'K' card, and all consecutive pairs of cards that add up to 13.  The deck does wrap around, so that if the last card remaining in the deck and the first card remaining in the deck add up to 13, they are both removed.  The player keeps cycling through the deck until no more cards can be removed.
Create a class CircleGame containing the method cardsLeft that takes a string deck representing a not-necessarily complete nor correct deck of cards.  Each character of deck represents the value of a card without the suit.  The values shown on the card represent the following numerical values:

'A' - 1
'2' - 2
'3' - 3
'4' - 4
'5' - 5
'6' - 6
'7' - 7
'8' - 8
'9' - 9
'T' - 10
'J' - 11
'Q' - 12
'K' - 13

Given deck, return the number of cards remaining after the game has been played to its fullest such that no more cards can be removed.

DEFINITION
Class:CircleGame
Method:cardsLeft
Parameters:string
Returns:int
Method signature:int cardsLeft(string deck)


NOTES
-There are no guarantees made about the contents of the deck.  For example, there can be more than four of a given value of card.
-Note that if a particular card can make a sum of 13 with the card before or after it, it does not matter which is chosen.  For example, 38582, whether you use the first 8 or the second 8, will still become 382 after the two cards (5 and 8) are removed.


CONSTRAINTS
-deck will have between 10 and 50 characters, inclusive.
-each character of deck will be a character from the set {'2'-'9','A','T','J','Q','K'}.


EXAMPLES

0)
"KKKKKKKKKK"

Returns: 0

All K cards are always removed from the deck.

1)
"KKKKKAQT23"

Returns: 1

The K cards are removed, leaving AQT23.  AQ are then removed because they add up to 13, leaving T23.  Since the deck wraps around and T and 3 add up to 13, they are also removed, just leaving the 2.


2)
"KKKKATQ23J"

Returns: 6

Only the K cards can be removed.

3)
"AT68482AK6875QJ5K9573Q"

Returns: 4

The remaining deck is 6875.

4)
"AQK262362TKKAQ6262437892KTTJA332"

Returns: 24

*/
// END CUT HERE
