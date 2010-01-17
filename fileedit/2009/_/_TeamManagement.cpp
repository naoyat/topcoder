// BEGIN CUT HERE
/* SRM421 DIV1 1000pts
// PROBLEM STATEMENT
// You are the manager of a newly formed football club and want to buy some players for your club. You identified that there are N potentially interesting players on the market and numbered them 0 to N-1. You don't have enough money to buy all these players, so you want to buy only K of them.
It appears however that buying players is not always easy. Some of the players are loyal to your club. To buy such a player you can just pay money for him. Other players are not loyal, and you can buy such a player A only if you have previously bought some player B, who is a friend of player A.
You are given a string loyalty, where the i-th character is 'Y' if the i-th player is loyal to your club, and is 'N' otherwise. You are also given a vector <string> friends, which describes which pairs of players are friends of each other. Each element has the format "A B", where A and B are the numbers of two players who are the friends of each other.
Friendship is symmetrical (if A is a friend of B, then B is a friend of A) and not necessarily transitive (if A is a friend of B and B is a friend of C, then C is not necessarily a friend of A). It is known that friends contains exactly N-1 elements and that for any two players A and B there exists a chain of players with numbers I0=A, I1, ..., Ik-1, Ik=B (k >= 1), where every two players consecutive in the chain are friends of each other (we'll call this property a connectedness of friendship relation). It is guaranteed that each player has at most 3 friends and that at least one player is loyal to your club.
A subset of K players is called possible if you can buy all players from this subset and only these players, in some order. You decided to choose some possible subset and to buy all players from it. If there are many such subsets, you choose one at random (all subsets have the same probability of being chosen).
You are now interested in the probability of buying each of the players. Return a vector <double> containing N elements, where the i-th element is the probability of buying the i-th player.

DEFINITION
Class:TeamManagement
Method:getDistribution
Parameters:int, int, vector <string>, string
Returns:vector <double>
Method signature:vector <double> getDistribution(int N, int K, vector <string> friends, string loyalty)


NOTES
-Each element of your return value must have an absolute or relative error less than 1e-9.


CONSTRAINTS
-N will be between 1 and 50, inclusive.
-K will be between 1 and N, inclusive.
-loyalty will contain exactly N characters.
-Each character of loyalty will be 'Y' or 'N'.
-At least one character of loyalty will be 'Y'.
-friends will contain exactly N-1 elements.
-Each element of friends will be formatted "A B" (quotes for clarity), where A and B are distinct integers between 0 and N-1, inclusive, with no extra leading zeros.
-The friendship relation will be connected (see the statement for precise definition).
-Each player will have at most 3 friends.


EXAMPLES

0)
5
3
{"0 1", "1 2", "2 3", "3 4"}
"NNYNN"

Returns: {0.33333333333333337, 0.6666666666666667, 1.0, 0.6666666666666667, 0.33333333333333337 }

There are three possible subsets: {0, 1, 2}, {1, 2, 3} and {2, 3, 4}.

1)
4
3
{"2 0", "2 1", "2 3"}
"NNYN"

Returns: {0.6666666666666667, 0.6666666666666667, 1.0, 0.6666666666666667 }

All subsets that include player 2 are possible.

2)
6
4
{"4 3", "3 1", "3 0", "0 2", "0 5"}
"NNNNYY"

Returns: {0.8571428571428572, 0.4285714285714286, 0.4285714285714286, 0.8571428571428572, 0.7142857142857143, 0.7142857142857143 }

The following 7 subsets are possible in this case: {1, 3, 4, 5}, {0, 3, 4, 5}, {0, 2, 4, 5}, {0, 2, 3, 5}, {0, 2, 3, 4}, {0, 1, 3, 5}, {0, 1, 3, 4}.

3)
6
1
{"3 0", "0 2", "0 4", "4 1", "2 5"}
"YYYNNN"

Returns: {0.33333333333333337, 0.33333333333333337, 0.33333333333333337, 0.0, 0.0, 0.0 }

When you wish to buy only one player, it must be a loyal player.

4)
7
7
{"3 1", "1 5", "5 4", "4 0", "4 6", "5 2"}
"NNNNNNY"

Returns: {1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0 }

Here you wish to buy all available players.

*/
// END CUT HERE

#line 91 "TeamManagement.cpp"
#include <string>
#include <vector>
// BEGIN CUT HERE
#include <iostream>
// END CUT HERE
#include <sstream>
using namespace std;

class TeamManagement {
	public:
	vector <double> getDistribution(int N, int K, vector <string> friends, string loyalty) {
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <double> &Expected, const vector <double> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arg0 = 5; int Arg1 = 3; string Arr2[] = {"0 1", "1 2", "2 3", "3 4"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "NNYNN"; double Arr4[] = {0.33333333333333337, 0.6666666666666667, 1.0, 0.6666666666666667, 0.33333333333333337 }; vector <double> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(0, Arg4, getDistribution(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 4; int Arg1 = 3; string Arr2[] = {"2 0", "2 1", "2 3"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "NNYN"; double Arr4[] = {0.6666666666666667, 0.6666666666666667, 1.0, 0.6666666666666667 }; vector <double> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(1, Arg4, getDistribution(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 6; int Arg1 = 4; string Arr2[] = {"4 3", "3 1", "3 0", "0 2", "0 5"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "NNNNYY"; double Arr4[] = {0.8571428571428572, 0.4285714285714286, 0.4285714285714286, 0.8571428571428572, 0.7142857142857143, 0.7142857142857143 }; vector <double> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(2, Arg4, getDistribution(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 6; int Arg1 = 1; string Arr2[] = {"3 0", "0 2", "0 4", "4 1", "2 5"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "YYYNNN"; double Arr4[] = {0.33333333333333337, 0.33333333333333337, 0.33333333333333337, 0.0, 0.0, 0.0 }; vector <double> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(3, Arg4, getDistribution(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arg0 = 7; int Arg1 = 7; string Arr2[] = {"3 1", "1 5", "5 4", "4 0", "4 6", "5 2"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "NNNNNNY"; double Arr4[] = {1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0 }; vector <double> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(4, Arg4, getDistribution(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	TeamManagement ___test;
	___test.run_test(-1);
}
// END CUT HERE
