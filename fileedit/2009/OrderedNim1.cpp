#line 2 "OrderedNim.cpp"
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
#define rep(var,n)  for(int var=0;var<(n);var++)

class OrderedNim {
 public:
  string winner(vector<int> layout) {
    int n=sz(layout);//1-50
    rep(i,n) if(layout[i]>=2) layout[i]=2;
    bool r=true;
    if (n==1) goto alice;
    for(int i=n-2;i>=0;i--){
      if(layout[i]==1) r=not r;
    }
    if (r==false && layout[0]>1) r=true;
    if (r) goto alice; else goto bob;
    
 alice:
    return "Alice";
 bob:
    return "Bob";
  }
};

// BEGIN CUT HERE
#include <time.h>
clock_t start_time;
void timer_clear() { start_time = clock(); }
string timer() { clock_t end_time = clock(); double interval = (double)(end_time - start_time)/CLOCKS_PER_SEC; ostringstream os; os << " (" << interval*1000 << " msec)"; return os.str(); }

template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
int verify_case(const string &Expected, const string &Received) { if (Expected == Received) cerr << "PASSED" << timer() << endl; else { cerr << "FAILED" << timer() << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } return 0;}

template<int N> struct Case_ {};
char Test_(...);
int Test_(Case_<0>) {
	timer_clear();
	int layout_[] = {5};
	  vector <int> layout(layout_, layout_+sizeof(layout_)/sizeof(*layout_)); 
	string RetVal = "Alice"; 
	return verify_case(RetVal, OrderedNim().winner(layout)); }
int Test_(Case_<1>) {
	timer_clear();
	int layout_[] = {1,2};
	  vector <int> layout(layout_, layout_+sizeof(layout_)/sizeof(*layout_)); 
	string RetVal = "Bob"; 
	return verify_case(RetVal, OrderedNim().winner(layout)); }
int Test_(Case_<2>) {
	timer_clear();
	int layout_[] = {2,1};
	  vector <int> layout(layout_, layout_+sizeof(layout_)/sizeof(*layout_)); 
	string RetVal = "Alice"; 
	return verify_case(RetVal, OrderedNim().winner(layout)); }
int Test_(Case_<3>) {
	timer_clear();
	int layout_[] = {10,9,8,7,6,5,4,3,2,1};
	  vector <int> layout(layout_, layout_+sizeof(layout_)/sizeof(*layout_)); 
	string RetVal = "Alice"; 
	return verify_case(RetVal, OrderedNim().winner(layout)); }
int Test_(Case_<4>) {
	timer_clear();
	int layout_[] = {1,1,1,1};
	  vector <int> layout(layout_, layout_+sizeof(layout_)/sizeof(*layout_)); 
	string RetVal = "Bob"; 
	return verify_case(RetVal, OrderedNim().winner(layout)); }
int Test_(Case_<5>) {
	timer_clear();
	int layout_[] = {1};
    vector <int> layout(layout_, layout_+sizeof(layout_)/sizeof(*layout_)); 
	string RetVal = "Alice"; 
	return verify_case(RetVal, OrderedNim().winner(layout)); }
int Test_(Case_<6>) {
	timer_clear();
	int layout_[] = {1,1};
    vector <int> layout(layout_, layout_+sizeof(layout_)/sizeof(*layout_)); 
	string RetVal = "Bob"; 
	return verify_case(RetVal, OrderedNim().winner(layout)); }
int Test_(Case_<7>) {
	timer_clear();
	int layout_[] = {1,1,1};
    vector <int> layout(layout_, layout_+sizeof(layout_)/sizeof(*layout_)); 
	string RetVal = "Alice"; 
	return verify_case(RetVal, OrderedNim().winner(layout)); }
int Test_(Case_<8>) {
	timer_clear();
	int layout_[] = {2,1,1};
    vector <int> layout(layout_, layout_+sizeof(layout_)/sizeof(*layout_)); 
	string RetVal = "Alice"; 
	return verify_case(RetVal, OrderedNim().winner(layout)); }
int Test_(Case_<9>) {
	timer_clear();
	int layout_[] = {2,1,1,1};
    vector <int> layout(layout_, layout_+sizeof(layout_)/sizeof(*layout_)); 
	string RetVal = "Alice"; 
	return verify_case(RetVal, OrderedNim().winner(layout)); }
int Test_(Case_<10>) {
	timer_clear();
	int layout_[] = {2,9,8,7,6,5,4,3,2,1};
	  vector <int> layout(layout_, layout_+sizeof(layout_)/sizeof(*layout_)); 
	string RetVal = "Alice"; 
	return verify_case(RetVal, OrderedNim().winner(layout)); }
int Test_(Case_<11>) {
	timer_clear();
	int layout_[] = {1,9,8,7,6,5,4,3,2,1};
	  vector <int> layout(layout_, layout_+sizeof(layout_)/sizeof(*layout_)); 
	string RetVal = "Bob"; 
	return verify_case(RetVal, OrderedNim().winner(layout)); }

template<int N> void Run_() { cerr << "Test Case #" << N << "..." << flush; Test_(Case_<N>()); Run_<sizeof(Test_(Case_<N+1>()))==1 ? -1 : N+1>(); }
template<>      void Run_<-1>() {}
int main() { Run_<0>(); }
// END CUT HERE


// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// Nim is a game in which two players take turns removing stones from heaps.  On each turn, a player must choose a single heap and remove one or more stones from that heap.  The player who takes the last stone wins.

Alice and Bob are bored with playing Nim over and over again, so they've decided to create a new variation called Ordered Nim.  Ordered Nim differs from regular Nim in the following way.  The heaps are numbered 0 through n-1 (where n is the number of heaps), and a player can only remove stones from a heap if all the lower-numbered heaps are empty.

You are given a vector <int> layout, where the i-th element (0-indexed) is the number of stones in heap i at the beginning of the game.  Alice will take the first turn.  Determine who will win the game, assuming both players play optimally.  Return "Alice" if Alice will win, or "Bob" if Bob will win (all quotes for clarity).

DEFINITION
Class:OrderedNim
Method:winner
Parameters:vector <int>
Returns:string
Method signature:string winner(vector <int> layout)


CONSTRAINTS
-layout will contain between 1 and 50 elements, inclusive.
-Each element of layout will be between 1 and 1000000000, inclusive.


EXAMPLES

0)
{5}

Returns: "Alice"

Alice takes all 5 stones and wins.

1)
{1,2}

Returns: "Bob"

According to the rules of the game, Alice is not allowed to take stones from heap 1 because heap 0 is not empty.  Her only option is to take the one stone from heap 0.  Heap 0 will then be empty, so Bob can take both stones from heap 1 to win the game.

2)
{2,1}

Returns: "Alice"



3)
{10,9,8,7,6,5,4,3,2,1}

Returns: "Alice"



4)
{1,1,1,1}

Returns: "Bob"

*/
// END CUT HERE
