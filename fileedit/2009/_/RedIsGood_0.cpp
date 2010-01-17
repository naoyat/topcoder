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
// BEGIN CUT HERE
#include <iostream>
inline void indent(int level) { for (int i=0; i<level; i++) putchar(' '); }

// END CUT HERE
#include <sstream>
using namespace std;

class RedIsGood {
private:
  double expected(int curr, int R, int B) {
	if (R + B == 0) {
	  //	  cout << "fin." << curr << endl;
	  return curr;
	}
	int level = 23 - R - B;

	double eR = -1.0, eB = -1.0, rR = 0.0, rB = 0.0, eTotal = 0.0;

	if (R > 0) {
	  eR = expected(curr+1, R-1, B);
	  if (level < 3) {
		indent( level * 2 );
		printf(" - expected(%d, %d, %d) = %g (%g)\n", curr+1, R-1, B, eR, 1.0 * R / (R + B));
	  }
	  // if (eR < 0) return -1;
	  //	  if (eR > 0) {
	  rR = 1.0 * R / (R + B);
	  eTotal += eR * rR;
	  if (eR < 0) printf("[level=%d,curr=%d] eR = %g\n", level,curr, eR);
		//	  }
	}
	if (B > 0) {
	  eB = expected(curr-1, R, B-1);
	  if (level < 3) {
		indent( level * 2 );
		printf(" - expected(%d, %d, %d) = %g (%g)\n", curr-1, R, B-1, eB, 1.0 * B / (R + B));
	  }
	  //	  if (eB > 0) {
		rB = 1.0 * B / (R + B);
		eTotal += eB * rB;
		if (eB < 0) printf("[level=%d,curr=%d] eB = %g\n", level,curr, eB);
		//	  }
	}
	// if (eR < 0.0 && eB < 0.0) return -1.0;

	if (level < 3) {
	  indent( level * 2 );
	  printf(" => expected(%d, %d, %d) = %g %s\n", curr, R, B, eTotal, (eTotal > curr)?"":"x");
	}
	return (eTotal > curr) ? eTotal : static_cast<double>( curr );
  }
public:
  double getProfit(int R, int B) {
    double e = expected(0, R, B);
	// printf("e = %2.20f\n", e);
	return (e >= 0.0)? e : 0;
  }
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) {
	  /*
	  if ((Case == -1) || (Case == 0)) test_case_0();
	  if ((Case == -1) || (Case == 1)) test_case_1();
	  if ((Case == -1) || (Case == 2)) test_case_2();
	  if ((Case == -1) || (Case == 3)) test_case_3();
	  if ((Case == -1) || (Case == 4)) test_case_4();
	  */
	  if ((Case == -1) || (Case == 5)) test_case_5();
	  //if ((Case == -1) || (Case == 6)) test_case_6();
	}
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) {
 cerr << "Test Case #" << Case << "...";
 double diff = Expected - Received; if (diff < 0.0) diff = -diff;
 if (diff < 1.0e-9) cerr << "PASSED" << endl;
 else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 0; int Arg1 = 7; double Arg2 = 0.0; verify_case(0, Arg2, getProfit(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 4; int Arg1 = 0; double Arg2 = 4.0; verify_case(1, Arg2, getProfit(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 5; int Arg1 = 1; double Arg2 = 4.166666666666667; verify_case(2, Arg2, getProfit(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 2; int Arg1 = 2; double Arg2 = 0.6666666666666666; verify_case(3, Arg2, getProfit(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 12; int Arg1 = 4; double Arg2 = 8.324175824175823; verify_case(4, Arg2, getProfit(Arg0, Arg1)); }
	void test_case_5() { int Arg0 = 11; int Arg1 = 12; double Arg2 = 1.075642825339958; verify_case(5, Arg2, getProfit(Arg0, Arg1)); }
  //	void test_case_6() { int Arg0 = 10; int Arg1 = 12; double Arg2 = 1.075642825339958; verify_case(6, Arg2, getProfit(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	RedIsGood ___test;
	___test.run_test(-1);
}
// END CUT HERE
