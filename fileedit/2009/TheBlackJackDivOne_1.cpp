#line 2 "TheBlackJackDivOne.cpp"
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
#define mset(arr,val)  memset(arr,val,sizeof(arr))
#define tr(c,i)  for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); i++)
#define rep(var,n)  for(int var=0;var<(n);var++)
#define found(s,e)  ((s).find(e)!=(s).end())

class TheBlackJackDivOne {
  vector<int> rest;
  
  int cval(int c){
    if ('0'<=c &&c<='9')return c-'0';
    switch(c){
      case 'T':case'J':case'Q':case 'K': return 10;
      case 'A': return 11;
    }
  }
    
 public:
  double sb(double r,int re,int to,int ma){
    double d=0;
    //cout << r ;
    //printf(" sb(re=%d,to=%d,ma=%d) ", re,to,ma); cout << rest << endl;
    for(int i=1;i<=11;i++){
      if(rest[i]==0) continue;

      double m_ = 1.0*rest[i]/re;
      int to_ = to - i;

      if(to_<=0) { d += r*ma*m_; continue; }

      rest[i]--;
      d += sb(r*m_,re-1,to_,ma+1);
      rest[i]++;
    }
    return d;
  }
  
  double expected(vector<string> cards) {
    int i;
    rest.resize(12); rep(i,12) rest[i]=0;
    for(i=2;i<=9;i++) rest[i]+=4;
    rest[10]+=16; rest[11]+=4;
    
    int n=sz(cards);
    //cout << rest << endl;
    vector<int> v(n);
    int sc=0;
    rep(i,n){
      int c = cval(cards[i][0]);
      v[i] = c;
      rest[c]--;
      sc+=c;
      if(sc>21) return 0.0;
    }

    return sb(1.0, 52-n,21-sc,1);
  }
};

// BEGIN CUT HERE
#include <time.h>
clock_t start_time;
void timer_clear() { start_time = clock(); }
string timer() { clock_t end_time = clock(); double interval = (double)(end_time - start_time)/CLOCKS_PER_SEC; ostringstream os; os << " (" << interval*1000 << " msec)"; return os.str(); }

template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
int verify_case(const double &Expected, const double &Received) { double diff = Expected - Received; if (diff < 0) diff = -diff; if (diff < 1e-9) cerr << "PASSED" << timer() << endl; else { cerr << "FAILED" << timer() << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } return 0;}

template<int N> struct Case_ {};
char Test_(...);
int Test_(Case_<0>) {
	timer_clear();
	string cards_[] = {"JS"};
	  vector <string> cards(cards_, cards_+sizeof(cards_)/sizeof(*cards_)); 
	double RetVal = 2.105854341736695; 
	return verify_case(RetVal, TheBlackJackDivOne().expected(cards)); }
int Test_(Case_<1>) {
	timer_clear();
	string cards_[] = {"KD", "8S"};
	  vector <string> cards(cards_, cards_+sizeof(cards_)/sizeof(*cards_)); 
	double RetVal = 1.08; 
	return verify_case(RetVal, TheBlackJackDivOne().expected(cards)); }
int Test_(Case_<2>) {
	timer_clear();
	string cards_[] = {"KD", "2S", "2C", "2D", "2H"};
	  vector <string> cards(cards_, cards_+sizeof(cards_)/sizeof(*cards_)); 
	double RetVal = 1.0; 
	return verify_case(RetVal, TheBlackJackDivOne().expected(cards)); }
int Test_(Case_<3>) {
	timer_clear();
	string cards_[] = {"AS", "KS", "9S", "JC", "2D"};
	  vector <string> cards(cards_, cards_+sizeof(cards_)/sizeof(*cards_)); 
	double RetVal = 0.0; 
	return verify_case(RetVal, TheBlackJackDivOne().expected(cards)); }

template<int N> void Run_() { cerr << "Test Case #" << N << "..." << flush; Test_(Case_<N>()); Run_<sizeof(Test_(Case_<N+1>()))==1 ? -1 : N+1>(); }
template<>      void Run_<-1>() {}
int main() { Run_<0>(); }
// END CUT HERE


// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
John and Brus are training for a card game tournament.
There they will be playing Black Jack.
Black Jack is played using a standard deck containing 52 distinct cards.
Each card can be represented as a two-character string where the first character is the rank ('2' - '9' for ranks Two through Nine, 'T' for Ten, 'J' for Jack, 'Q' for Queen, 'K' for King and 'A' for Ace) and the second character is the suit ('S' for Spades, 'C' for Clubs, 'D' for Diamonds and 'H' for Hearts).
For example, the Jack of Spades can be represented as "JS" and the Nine of Hearts as "9H".



Each time a player receives a card from the deck, his score increases by the card's value.
Ranks Two through Ten have values of 2 - 10, respectively.
Jacks, Queens and Kings each have a value of 10, and Aces have a value of 11.



Brus randomly shuffles the full card deck and gives John one or more cards from the top of the deck.
You are given a vector <string> cards, where each element represents a single card given to John in this initial step.
John will then take extra cards from the top of the deck, one by one, until his score is greater than or equal to 21.
Return the expected number of extra cards that John will take.



DEFINITION
Class:TheBlackJackDivOne
Method:expected
Parameters:vector <string>
Returns:double
Method signature:double expected(vector <string> cards)


NOTES
-The returned value must be accurate to within a relative or absolute value of 1E-9.


CONSTRAINTS
-cards will contain between 1 and 50 elements, inclusive.
-Each element of cards will contain exactly two characters, where the first character is '2'-'9', 'T', 'J', 'Q', 'K' or 'A', and the second character is 'S', 'C', 'D' or 'H'.
-All elements of cards will be distinct.


EXAMPLES

0)
{"JS"}

Returns: 2.105854341736695



1)
{"KD", "8S"}

Returns: 1.08

John will take the second extra card only if the first one is Two.

2)
{"KD", "2S", "2C", "2D", "2H"}

Returns: 1.0

The same situation, but here there are no Twos left in the deck.

3)
{"AS", "KS", "9S", "JC", "2D"}

Returns: 0.0

Here John's score is already more than 21.

*/
// END CUT HERE
