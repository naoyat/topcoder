// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// As a serious strategy-games player, you decided to solve one of the most common problems - attacking your
opponent's building (barracks), which constantly produces new soldiers.

Before the attack, you've got myUnits soldiers. In a single round, each soldier can either kill one of your opponent's soldiers or inflict 1 hit point of damage to the barracks.

Your opponent doesn't have any soldiers initially.  However, his barracks has barHp hit points and produces unitsPerRound soldiers per round.

The course of one round:
1. Each solider from your army either kills one of your opponent's soldiers or inflicts 1 hit point of damage to the barracks.  Each soldier can choose to do something different.  When the barracks loses all of its hit points, it is destroyed. 
2. Your opponent attacks. He will kill k of your soldiers, where k is the number of remaining soldiers he has.
3. If the barracks are not yet destroyed, your opponent will produce unitsPerRound new soldiers.

Your task is to destroy the barracks and kill all your opponent's soldiers. If it is possible, return the minimum number of rounds you need to do this.
Otherwise return -1.



DEFINITION
Class:BarracksEasy
Method:attack
Parameters:int, int, int
Returns:int
Method signature:int attack(int myUnits, int barHp, int unitsPerRound)


CONSTRAINTS
-myUnits, barHp, unitsPerRound will each be between 1 and 50, inclusive.


EXAMPLES

0)
10
11
15

Returns: 4

Round 1:
- All your soldiers attack the barracks, leaving it with 1 hit point.
- Your opponent has no soldiers, so he cannot kill any of your soldiers.
- Your opponent's army increases from 0 soldiers to 15 soldiers.

Round 2:
- One of your soldiers destroys the barracks. The other nine kill 9 of your opponent's soldiers.
- Your opponent has 6 soldiers, so he kills 6 of your soldiers.
- The barracks have been destroyed, so no new soldiers are produced.

Round 3:
- You have got 4 soldiers, so you decrease your opponent's army to 2 soldiers.
- Your opponent kills 2 of your soldiers.
- The barracks have been destroyed, so no new soldiers are produced.

Round 4:
- You kill 2 remaining soldiers. 

1)
3
10
4

Returns: -1



2)
2
10
1

Returns: 9



3)
11
12
9

Returns: 2



*/
// END CUT HERE

#line 91 "BarracksEasy.cpp"
#include <string>
#include <vector>
// BEGIN CUT HERE
#include <iostream>
// END CUT HERE
#include <sstream>
#include <queue>
#include <set>
using namespace std;

class Stat {
public:
  int myUnits;
  int barHp;
  int hisUnits;
public:
  Stat(int m,int b,int h) {
	// cout << "  new Stat(myUnits=" << m << ", barHp=" << b << ", hisUnits=" << h << ")\n";
	myUnits = m; barHp = b; hisUnits = h;
  }
  //  int score() { return myUnits - (barHp + hisUnits); }
  bool impossible() { return (barHp > 0 && hisUnits >= (myUnits << 1)) ? true : false; }
};

typedef struct cmp{
  bool operator () ( Stat* left, Stat* right) {
	if (left->myUnits == right->myUnits) {
	  return (left->barHp + left->hisUnits) > (right->barHp + right->hisUnits);
	} else {
	  return left->myUnits > right->myUnits;
	}
  }
} cmp;

typedef priority_queue<Stat*,vector<Stat*>,cmp> pqueue;

class BarracksEasy {
private:
  int sub(int round, int myUnits, int barHp, int hisUnits, int unitsPerRound) {

	// cout << "round " << round << ": myUnits=" << myUnits << ", barHp=" << barHp << ", hisUnits=" << hisUnits << endl;

	if (myUnits >= barHp + hisUnits) return round;
	if (round > 50) return -1;
	//	cout << "round " << round << endl;

	pqueue pq;
	
	// myUnits を barKiller と unitsKillerに分ける。
	for (int barKiller=0; barKiller<=myUnits; barKiller++) {
	  int myUnits_ = myUnits, barHp_ = barHp, hisUnits_ = hisUnits;
	  
	  if (barKiller > barHp_) continue;

	  int unitsKiller = myUnits_ - barKiller;
	  if (unitsKiller > hisUnits_) continue;
	  
	  barHp_ -= barKiller; // >=0
	  hisUnits_ -= unitsKiller;
	  if (hisUnits_ < 0) hisUnits_ = 0;
	  
	  myUnits_ -= hisUnits_;
	  if (barHp_) hisUnits_ += unitsPerRound;
	  
	  pq.push(new Stat(myUnits_, barHp_, hisUnits_));
	}

	set<Stat*> s;

	int restUnits = 0;
	// int maxScore = -1;
	//	cout << "round " << round << ":" << endl;
	while (!pq.empty()) {
	  Stat* stat = pq.top();
	  if (stat->barHp == 0 && stat->hisUnits == 0) return round;
	  // cout << "- " << stat->myUnits << " " << stat->barHp << " " << stat->hisUnits << " //" << stat->score() << endl;
	  // if (stat->score() > maxScore) maxScore = stat->score();
	  if (! stat->impossible()) {
		//  if (stat->myUnits > 0) {
		restUnits++;
		s.insert(stat);
	  }
	  pq.pop();
	}
	if (restUnits == 0) return -1;
	//	if (maxScore <= lastMaxScore) return -1;
	// cout << "  maxScore = " << maxScore << "/" << lastMaxScore << endl;

	round++;
	for (set<Stat*>::iterator it=s.begin(); it!=s.end(); it++) {
	  Stat *stat = *it;
	  int r = sub(round, stat->myUnits, stat->barHp, stat->hisUnits, unitsPerRound);
	  if (r >= round) return r;
	}
	return -1;
  }
public:
  int attack(int myUnits, int barHp, int unitsPerRound) {
	// cout << "====" << endl;
	// cout << "attack(" << myUnits << ", " << barHp << ", " << unitsPerRound << ")\n";
	int r = sub(1, myUnits, barHp, 0, unitsPerRound);
	// cout << " => " << r << endl;
	return r;
  }
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 10; int Arg1 = 11; int Arg2 = 15; int Arg3 = 4; verify_case(0, Arg3, attack(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 10; int Arg2 = 4; int Arg3 = -1; verify_case(1, Arg3, attack(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 2; int Arg1 = 10; int Arg2 = 1; int Arg3 = 9; verify_case(2, Arg3, attack(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 11; int Arg1 = 12; int Arg2 = 9; int Arg3 = 2; verify_case(3, Arg3, attack(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	BarracksEasy ___test;
	___test.run_test(-1);
}
// END CUT HERE
