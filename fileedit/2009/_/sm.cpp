// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// A card shuffling machine is a device designed to randomize the order of a deck of cards. A particularly poor (but unfortunately relatively common) design of machine works as follows: an integer N is selected uniformly at random between 1 and maxShuffles, inclusive, and a series of N exactly similar deterministic shuffles are performed. A deterministic shuffle is a fixed permutation of the cards. The randomness of the resulting ordering is clearly therefore only dependent on the number of shuffles chosen. After the deck has been shuffled N times, the cards are distributed to the players.
A particularly dishonest player has decided that he wishes to cheat. He has identified K cards in the deck that he wants to receive when the cards are distributed. He has managed to figure out both the fixed shuffle that the machine uses and also the maximum number of shuffles chosen. The fixed shuffle is given in a vector <int> shuffle, in which element i gives the position after the shuffle of the card that was initially in position i (both 0-based). The positions in the deck of the cards the player will receive after they have been shuffled are given in cardsReceived (0-based). Before the cards are shuffled, the player can order them in any way he wishes. Determine the initial ordering that will maximize the expected number of the K desired cards that he will receive and return this expected number.

DEFINITION
Class:ShufflingMachine
Method:stackDeck
Parameters:vector <int>, int, vector <int>, int
Returns:double
Method signature:double stackDeck(vector <int> shuffle, int maxShuffles, vector <int> cardsReceived, int K)


NOTES
-Your return value must be accurate to an absolute or relative tolerance of 1e-9.


CONSTRAINTS
-shuffle will contain between 1 and 50 elements, inclusive.
-shuffle will be a permutation of the numbers between 0 and M-1, inclusive, where M is the number of elements in shuffle.
-maxShuffles will be between 1 and 100, inclusive.
-cardsReceived will contain between 1 and M elements, inclusive.
-Each element of cardsReceived will be between 0 and M-1.
-The elements of cardsReceived will be distinct.
-K will be between 1 and M, inclusive.


EXAMPLES

0)
{1,0}
3
{0}
1

Returns: 0.6666666666666666

This deck contains only 2 cards and they swap positions after each shuffle. The cheating player receives first card in the deck after the shuffling is completed and he wants to receive 1 of the cards in the deck. If the deck is shuffled 1 or 3 times, he will receive the card that was initially in position 1. If the deck is shuffled 2 times, he will receive the card in position 0. It is therefore optimal to put the card that he wants in position 1 and he will receive it 2 times out of 3.

1)
{1,2,0}
5
{0}
2

Returns: 0.8

If he puts the cards he wants in positions 1 and 2, he will receive one of them 4 times out of 5.

2)
{1,2,0,4,3}
7
{0,3}
2

Returns: 1.0

If he puts the cards in positions 3 and 4, he will receive exactly one of them, regardless of how many shuffles are chosen.

3)
{0,4,3,5,2,6,1}
19
{1,3,5}
2

Returns: 1.0526315789473684



4)
{3,4,7,2,8,5,6,1,0,9}
47
{6,3,5,2,8,7,4}
8

Returns: 6.297872340425532

*/
// END CUT HERE

#line 83 "ShufflingMachine.cpp"
#include <string>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <algorithm>
// BEGIN CUT HERE
#include <iostream>
#include "cout.h"
#include <time.h>
// END CUT HERE
#include <sstream>
#include <cmath>
using namespace std;

#define sz(a)  int((a).size())
#define pb  push_back
#define all(c)  (c).begin(),(c).end()
#define tr(c,i)  for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); i++)

class ShufflingMachine {
public:
  double stackDeck(vector<int> shuffle, int maxShuffles, vector<int> cardsReceived, int K) {
	int M = shuffle.size();
// BEGIN CUT HERE
	cout << shuffle << endl;
	cout << maxShuffles << endl;
	cout << "cR:" << cardsReceived << endl;
	cout << "K:"  << K << endl;
	// shuffle{1-50 elem} : 0..M-1 のpermutation
	// maxShuffles : [1..100]
	// cardsReceived{1-M elem}: [0..M-1] x []
	// K: [1..M]
// END CUT HERE
	vector<vector<int> > sx(M);
	vector<int> cards(M); for(int i=0;i<M;i++) cards[i] = i;
	tr(sx,it) { it->resize(M); tr(*it,jt) *jt = 0; }
	for (int i=0; i<maxShuffles; i++) {
	  vector<int> last_cards(all(cards));
	  for (int j=0;j<M;j++) {
		int loc = shuffle[j];
		int c = cards[loc] = last_cards[j];
		sx[loc][c]++;
	  }
	}
	
	tr(cardsReceived,c) {
	  printf("loc#%d: %d/%d\n", *c, sx[*c][K], maxShuffles);
	}
	/*
	for (int i=0;i<M;i++) {
	  printf("loc#%d: %d/%d\n", i, sx[i][K], maxShuffles);
	}
	  */
	return 0.0;
  }

// BEGIN CUT HERE
  clock_t start;
  void timer_clear()
  {
	start = clock();
  }
  char *timer()
  {
	clock_t end = clock();
	double interval = (double)(end - start)/CLOCKS_PER_SEC;
	
	char *ret = NULL;
	asprintf(&ret, " (%g msec)", interval*1000);
	return ret;
  }
// END CUT HERE
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arr2[] = {0}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 1; double Arg4 = 0.6666666666666666; verify_case(0, Arg4, stackDeck(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arr0[] = {1,2,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; int Arr2[] = {0}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2; double Arg4 = 0.8; verify_case(1, Arg4, stackDeck(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arr0[] = {1,2,0,4,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 7; int Arr2[] = {0,3}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2; double Arg4 = 1.0; verify_case(2, Arg4, stackDeck(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arr0[] = {0,4,3,5,2,6,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 19; int Arr2[] = {1,3,5}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2; double Arg4 = 1.0526315789473684; verify_case(3, Arg4, stackDeck(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arr0[] = {3,4,7,2,8,5,6,1,0,9}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 47; int Arr2[] = {6,3,5,2,8,7,4}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 8; double Arg4 = 6.297872340425532; verify_case(4, Arg4, stackDeck(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main(int argc, char *argv[]) {
	ShufflingMachine ___test;
	___test.run_test( argc>=2 ? atoi(argv[1]):-1 );
}
// END CUT HERE
