#line 2 "TheCardLineDivOne.cpp"
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

class TheCardLineDivOne {
	public:
	int count(vector <string> cards) {
		
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
	string cards_[] = {"KH", "QD", "KC"};
	  vector <string> cards(cards_, cards_+sizeof(cards_)/sizeof(*cards_)); 
	int RetVal = 2; 
	return verify_case(RetVal, TheCardLineDivOne().count(cards)); }
int Test_(Case_<1>) {
	timer_clear();
	string cards_[] = {"JS", "JC", "JD", "JH"};
	  vector <string> cards(cards_, cards_+sizeof(cards_)/sizeof(*cards_)); 
	int RetVal = 24; 
	return verify_case(RetVal, TheCardLineDivOne().count(cards)); }
int Test_(Case_<2>) {
	timer_clear();
	string cards_[] = {"2S", "3C", "4C", "5S", "6C", "7S", "8S", "9H"};
	  vector <string> cards(cards_, cards_+sizeof(cards_)/sizeof(*cards_)); 
	int RetVal = 0; 
	return verify_case(RetVal, TheCardLineDivOne().count(cards)); }
int Test_(Case_<3>) {
	timer_clear();
	string cards_[] = {"KD", "KC", "AD", "7C", "AH", "9C", "4H", "4S", "AS"};
	  vector <string> cards(cards_, cards_+sizeof(cards_)/sizeof(*cards_)); 
	int RetVal = 2416; 
	return verify_case(RetVal, TheCardLineDivOne().count(cards)); }
int Test_(Case_<4>) {
	timer_clear();
	string cards_[] = {"5S", "AS", "9S", "4D", "3H", "2S", "2D", "3D", "2H", "7C", "JD", "9C", "5D", "TS", "8S", "6C", "KD", "2C", "TC", "3S"};
	  vector <string> cards(cards_, cards_+sizeof(cards_)/sizeof(*cards_)); 
	int RetVal = 1176318675; 
	return verify_case(RetVal, TheCardLineDivOne().count(cards)); }

template<int N> void Run_() { cerr << "Test Case #" << N << "..." << flush; Test_(Case_<N>()); Run_<sizeof(Test_(Case_<N+1>()))==1 ? -1 : N+1>(); }
template<>      void Run_<-1>() {}
int main() { Run_<0>(); }
// END CUT HERE


// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
John and Brus are training for a card game tournament.
During his off-time, Brus likes to occupy himself with the following game.
The game is played with a subset of a standard deck of 52 distinct cards.
Each card can be represented by a two-character string, where the first character is the rank ('2'-'9', 'T', 'J', 'Q', 'K', or 'A') and the second character is the suit ('S' for Spades, 'C' for Clubs, 'D' for Diamonds or 'H' for Hearts).
All Spades and Clubs are black, and all Diamonds and Hearts are red.
For example, the Jack of Spades is black and is represented as "JS", and the Nine of Hearts is red and is represented as "9H".



You are given a vector <string> cards containing the subset of the deck that Brus is playing with.
Each element of cards represents a single card.
He wants to place all of these cards in a line such that every pair of neighboring cards has the same rank or the same color (or both).
Return the number of different ways he can do this modulo 1234567891.



DEFINITION
Class:TheCardLineDivOne
Method:count
Parameters:vector <string>
Returns:int
Method signature:int count(vector <string> cards)


CONSTRAINTS
-cards will contain between 1 and 50 elements, inclusive.
-Each element of cards will contain exactly two characters, where the first character is '2'-'9', 'T', 'J', 'Q', 'K' or 'A', and the second character is 'S', 'C', 'D' or 'H'.
-All elements of cards will be distinct.


EXAMPLES

0)
{"KH", "QD", "KC"}

Returns: 2

There are two possible placements - KC-KH-QD and QD-KH-KC.

1)
{"JS", "JC", "JD", "JH"}

Returns: 24

All 24 permutations are valid.

2)
{"2S", "3C", "4C", "5S", "6C", "7S", "8S", "9H"}

Returns: 0

There is nothing we can do with the Nine of Hearts.

3)
{"KD", "KC", "AD", "7C", "AH", "9C", "4H", "4S", "AS"}

Returns: 2416



4)
{"5S", "AS", "9S", "4D", "3H", "2S", "2D", "3D", "2H", "7C", "JD", "9C", "5D", "TS", "8S", "6C", "KD", "2C", "TC", "3S"}

Returns: 1176318675

*/
// END CUT HERE
