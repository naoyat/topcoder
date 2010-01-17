// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// As a serious strategy-games player, you decided to solve one of the most common problems - attacking your
opponent's guard towers. 

Before the attack, you've got myUnits soldiers. Each soldier in a single round inflicts 1 hit point of damage to one of the towers.

Your opponent doesn't have any soldiers. However, he's got numT towers with hpT hit points each. Each tower kills attackT of your soldiers per round.

The course of one round:
1. Each soldier in your army attacks a tower of your choice for 1 hit point of damage.  When a tower loses all its hit points, it is destroyed. You can pick the tower independently for each soldier. 
2. Your opponent attacks. He will kill k*attackT of your soliders, where k is the number of remaining towers. 

Your task is to destroy all the towers. If it is possible, return the minimum number of rounds you need to do this.
Otherwise return -1.


DEFINITION
Class:Towers
Method:attack
Parameters:int, int, int, int
Returns:int
Method signature:int attack(int myUnits, int hpT, int attackT, int numT)


NOTES
-More than one soldier can attack the same tower in the same round.


CONSTRAINTS
-myUnits will be between 1 and 1000000, inclusive.
-hpT, attackT, numT will each be between 1 and 10000, inclusive.


EXAMPLES

0)
13
2
3
8

Returns: 2

Round 1:
- Your soldiers destroy 6 towers leaving one tower with 1 hit point and one tower with 2 hit points.
- Your opponent attacks and kills 2*3=6 of your soldiers.

Round 2:
- You have 7 soldiers remaining, which is more than enough to take out the 3 hit points of the remaining towers.


1)
10
6
8
2

Returns: 2



2)
10
6
9
2

Returns: -1



3)
1
1
1
1

Returns: 1



4)
10000
10
2
2789

Returns: 10



5)
2
1
1
3

Returns: 2



*/
// END CUT HERE

#line 108 "Towers.cpp"
#include <string>
#include <vector>
// BEGIN CUT HERE
#include <iostream>
// END CUT HERE
#include <sstream>
using namespace std;

class Towers {
	public:
	int attack(int myUnits, int hpT, int attackT, int numT) {
	  int totalHP = numT * hpT;
	  int times = 0;
	  while(1) {
		times++;
		totalHP -= myUnits;
		if (totalHP <= 0) return times;
		numT = (totalHP + hpT - 1) / hpT;
		myUnits -= numT * attackT;
		if (myUnits <= 0) return -1;
	  }
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 13; int Arg1 = 2; int Arg2 = 3; int Arg3 = 8; int Arg4 = 2; verify_case(0, Arg4, attack(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 10; int Arg1 = 6; int Arg2 = 8; int Arg3 = 2; int Arg4 = 2; verify_case(1, Arg4, attack(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 10; int Arg1 = 6; int Arg2 = 9; int Arg3 = 2; int Arg4 = -1; verify_case(2, Arg4, attack(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 1; int Arg1 = 1; int Arg2 = 1; int Arg3 = 1; int Arg4 = 1; verify_case(3, Arg4, attack(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arg0 = 10000; int Arg1 = 10; int Arg2 = 2; int Arg3 = 2789; int Arg4 = 10; verify_case(4, Arg4, attack(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_5() { int Arg0 = 2; int Arg1 = 1; int Arg2 = 1; int Arg3 = 3; int Arg4 = 2; verify_case(5, Arg4, attack(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	Towers ___test;
	___test.run_test(-1);
}
// END CUT HERE
