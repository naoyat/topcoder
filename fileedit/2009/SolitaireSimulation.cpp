// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
Consider the following solitaire game:
We have a deck of identical cards. Initially, these cards are split into several heaps, with heaps[i] cards on the i-th heap.
Each step of the game looks as follows: Pick one card from each of the heaps and make a new heap out of these cards.
 


When describing a position in the game, only the heap sizes matter, their order does not.
Clearly, sooner or later a position will repeat and the game will become periodic from that point on.



Write a method that takes a vector <int> heaps and returns the length of the shortest period of the game.

In other words, find the smallest number of steps S such that for some X the positions after X and X+S steps are equal.


DEFINITION
Class:SolitaireSimulation
Method:periodLength
Parameters:vector <int>
Returns:int
Method signature:int periodLength(vector <int> heaps)


NOTES
-After some finite number of moves the game must always become periodic.


CONSTRAINTS
-heaps will contain between 1 and 50 elements, inclusive.
-Each element in heaps will be between 1 and 50, inclusive.
-The sum of all elements in heaps will be between 1 and 50, inclusive.


EXAMPLES

0)
{3,1,3}

Returns: 4


In the first step of this game we take one card from each of the heaps, leaving two heaps with two cards each. Then we form a new heap consisting of the three cards we took. Thus the new heap sizes are 2, 2, and 3.


In the next step, the sizes of these heaps decrease to 1, 1, 2, and a new heap of size 3 appears.


After the third step the heap sizes will be 1, 2, and 4.


After the fourth step the heap sizes will be 1, 3, and 3. This is exactly the starting position.


1)
{1,4}

Returns: 3

In this case, the positions after the next few steps will look as follows:

2,3
1,2,2
1,1,3
2,3
1,2,2
...

The shortest period has length 3. Note that the starting position 1,4 is never repeated again.

2)
{1}

Returns: 1

After each step we have the same heap with one card.

3)
{4,3,2,1}

Returns: 1



4)
{3,3,3,3}

Returns: 5



*/
// END CUT HERE

#line 100 "SolitaireSimulation.cpp"
#include <string>
#include <vector>
// BEGIN CUT HERE
#include <iostream>
#include "cout.h"
// END CUT HERE
#include <sstream>
using namespace std;

class SolitaireSimulation {
	public:
	int periodLength(vector<int> heaps) {
	  int curr_heap_size = heaps.size();
	  sort(heaps.begin(), heaps.end());

	  vector<int> buf(heaps.begin(), heaps.end());
	  // for (int i=0; i<curr_heap_size; i++) buf[i] = heaps[i];

	  vector< pair<int,vector<int> > > history;
	  history.push_back( make_pair( curr_heap_size, heaps ) );

	  while (1) {
		buf.push_back( curr_heap_size );
		for (int i=0; i<curr_heap_size; i++) buf[i]--;
		sort(buf.begin(), buf.end());

		while (buf.size() > 0) {
		  if (buf[0] > 0) break;
		  buf.erase(buf.begin(),buf.begin()+1);
		}
		curr_heap_size = buf.size();
		
		int current_step = history.size();
		for (int i=current_step-1; i>=0; i--) {
		  pair<int, vector<int> > h = history[i];
		  if (h.first != curr_heap_size) continue;
		  bool matched = true;
		  for (int j=0; j<curr_heap_size; j++) {
			if (h.second[j] != buf[j]) matched = false;
		  }
		  if (matched == true) return current_step - i;
		}
		history.push_back( make_pair( curr_heap_size, buf ) );
	  }
	  return -1;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) {
	  if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3();
	  if ((Case == -1) || (Case == 4)) test_case_4();
	  if ((Case == -1) || (Case == 5)) test_case_5();
	  if ((Case == -1) || (Case == 6)) test_case_6();
	}
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {3,1,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(0, Arg1, periodLength(Arg0)); }
	void test_case_1() { int Arr0[] = {1,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(1, Arg1, periodLength(Arg0)); }
	void test_case_2() { int Arr0[] = {1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(2, Arg1, periodLength(Arg0)); }
	void test_case_3() { int Arr0[] = {4,3,2,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(3, Arg1, periodLength(Arg0)); }
	void test_case_4() { int Arr0[] = {3,3,3,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; verify_case(4, Arg1, periodLength(Arg0)); }
  void test_case_5() { int Arr0[] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; verify_case(5, Arg1, periodLength(Arg0)); }
  void test_case_6() { int Arr0[] = {50}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; verify_case(6, Arg1, periodLength(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	SolitaireSimulation ___test;
	___test.run_test(-1);
}
// END CUT HERE
