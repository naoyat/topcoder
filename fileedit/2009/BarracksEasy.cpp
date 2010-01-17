#line 91 "BarracksEasy.cpp"
#include <string>
#include <vector>
#include <iostream>
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
	myUnits = m; barHp = b; hisUnits = h;
  }
  bool impossible() { return (barHp > 0 && hisUnits >= (myUnits << 1)) ? true : false; }
};

typedef struct StatCmp {
  bool operator () ( Stat* left, Stat* right) {
	if (left->myUnits == right->myUnits) {
	  return (left->barHp + left->hisUnits) > (right->barHp + right->hisUnits);
	} else {
	  return left->myUnits > right->myUnits;
	}
  }
} StatCmp;

typedef priority_queue<Stat*,vector<Stat*>,StatCmp> pqueue;

class BarracksEasy {
private:
  int sub(int round, int myUnits, int barHp, int hisUnits, int unitsPerRound) {
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
	while (!pq.empty()) {
	  Stat* stat = pq.top();
	  if (stat->barHp == 0 && stat->hisUnits == 0) return round;
	  if (! stat->impossible()) {
		restUnits++;
		s.insert(stat);
	  }
	  pq.pop();
	}
	if (restUnits == 0) return -1;

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
	return sub(1, myUnits, barHp, 0, unitsPerRound);
  }
	

};



// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
