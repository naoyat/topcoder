// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
You have a deck that contains R red and B black cards.



You are playing the following game: You shuffle the deck, and then begin dealing the cards one by one.
For each red card you flip you get a dollar, and for each black card you flip you have to pay a dollar.
At any moment (including the beginning of the game) you are allowed to stop and keep the money you have.



Write a method that will take the ints R and B, and return the expected amount you will 
gain if you play this game optimally.


DEFINITION
Class:RedIsGood
Method:getProfit
Parameters:int, int
Returns:double
Method signature:double getProfit(int R, int B)


NOTES
-During the game, your balance may be negative.
-We assume that each permutation of the cards in the deck is equally likely.
-Your return value must have a relative or absolute error less than 1e-9.


CONSTRAINTS
-R will be between 0 and 5,000, inclusive.
-B will be between 0 and 5,000, inclusive.


EXAMPLES

0)
0
7

Returns: 0.0

If all cards are black, the best strategy is not to play at all.

1)
4
0

Returns: 4.0

If all cards are red, the best strategy is to flip them all.

2)
5
1

Returns: 4.166666666666667

The strategy "flip all cards" is guaranteed to earn $4. However, we can do better. If we flipped 5 cards and all of them are red, it makes no sense to flip the final, black card. Therefore if we play optimally the expected gain is more than $4.

3)
2
2

Returns: 0.6666666666666666

An optimal strategy for this case: Flip the first card. If it is red, stop. If it is black, flip the second and the third card. If both are red, stop, otherwise flip the fourth card.

4)
12
4

Returns: 8.324175824175823

This is a game I would surely like to play often.

5)
11
12

Returns: 1.075642825339958

Surprisingly, sometimes there is a good strategy even if the number of red cards is smaller than the number of black cards.

*/
// END CUT HERE

#line 92 "RedIsGood.cpp"
#include <string>
#include <vector>
#include <map>
// BEGIN CUT HERE
#include <iostream>
#include "cout.h"
// END CUT HERE
#include <sstream>
using namespace std;

class RedIsGood {
public:
  double getProfit(int R, int B) {
    if (B == 0) return static_cast<double>(R);
    if (R == 0) return 0.0;

    double *last_line = new double[B+1];
    double *curr_line = new double[B+1];
    double expected = 0.0;

    for (int b=0; b<=B; b++) last_line[b] = 0;

    for (int r=1; r<=R; r++) {
      curr_line[0] = static_cast<double>(r);

      for (int b=1; b<=B; b++) {
        double eR = last_line[b] + 1;
        double eB = curr_line[b-1] - 1;
        curr_line[b] = max((eR*r + eB*b)/(r + b), 0.0);
      }
      if (r == R) { expected = curr_line[B]; break; }

      swap( last_line, curr_line );
    }

    delete[] last_line;
    delete[] curr_line;
    return expected;
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) {
	  if ((Case == -1) || (Case == 0)) test_case_0(); // 0 7
	  if ((Case == -1) || (Case == 1)) test_case_1(); // 4 0
	  if ((Case == -1) || (Case == 2)) test_case_2(); // 5 1
	  if ((Case == -1) || (Case == 3)) test_case_3(); // 2 2
	  if ((Case == -1) || (Case == 4)) test_case_4(); // 12 4
	  if ((Case == -1) || (Case == 5)) test_case_5(); // 11 12
	  if ((Case == -1) || (Case == 6)) test_case_6(); // 5000 5000
	  if ((Case == -1) || (Case == 7)) test_case_7(); // 4950 4772
	  if ((Case == -1) || (Case == 9)) test_case_9(); // 4446 4526
	}
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) {
	  cerr << "Test Case #" << Case << "...";
	  double diff = Expected - Received; if (diff < 0.0) diff = -diff;
	  if (diff < 1.0e-9) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 0; int Arg1 = 7; double Arg2 = 0.0; verify_case(0, Arg2, getProfit(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 4; int Arg1 = 0; double Arg2 = 4.0; verify_case(1, Arg2, getProfit(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 5; int Arg1 = 1; double Arg2 = 4.166666666666667; verify_case(2, Arg2, getProfit(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 2; int Arg1 = 2; double Arg2 = 0.6666666666666666; verify_case(3, Arg2, getProfit(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 12; int Arg1 = 4; double Arg2 = 8.324175824175823; verify_case(4, Arg2, getProfit(Arg0, Arg1)); }
	void test_case_5() { int Arg0 = 11; int Arg1 = 12; double Arg2 = 1.075642825339958; verify_case(5, Arg2, getProfit(Arg0, Arg1)); }
	void test_case_6() { int Arg0 = 5000; int Arg1 = 5000; double Arg2 = 36.90021846438633; verify_case(6, Arg2, getProfit(Arg0, Arg1)); }
	void test_case_7() { int Arg0 = 4950; int Arg1 = 4772; double Arg2 = 191.15589434419024; verify_case(7, Arg2, getProfit(Arg0, Arg1)); }
	void test_case_9() { int Arg0 = 4446; int Arg1 = 4526; double Arg2 = 0.0; verify_case(9, Arg2, getProfit(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	RedIsGood ___test;
	___test.run_test(-1);
}
// END CUT HERE
