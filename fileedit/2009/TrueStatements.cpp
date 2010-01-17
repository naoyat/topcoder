// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// Professor Smith teaches a logic class. One day, he writes some statements on the blackboard:
Exactly a of these statements are true.
Exactly b of these statements are true.
Exactly c of these statements are true.
.
.
.
Each of a, b, c and so on is a number. He then asks the class how many of the statements are true.
You will be given a vector <int> statements, containing the numbers written in Professor Smith's statements. Return the number of the statements that are true. If there is more than one possible answer, return the largest one. If there are no possible answers, return -1.

DEFINITION
Class:TrueStatements
Method:numberTrue
Parameters:vector <int>
Returns:int
Method signature:int numberTrue(vector <int> statements)


CONSTRAINTS
-statements will contain between 1 and 50 elements, inclusive.
-Each element of statements will be between 0 and 50, inclusive.


EXAMPLES

0)
{0, 1, 2, 3}

Returns: 1

The 2nd statement is true (there is one true statement) and the others are false.

1)
{0}

Returns: -1

This is the Epimedes paradox: if the statement is true then it claims to be false, but if it is false then it must be true.

2)
{0, 3, 1, 3, 2, 3}

Returns: 3

One solution is that the 3rd statement is the only true statement. However, it is also possible that the 2nd, 4th and 6th statements are true (all of which say that 3 statements are true), and the largest solution must be returned.

3)
{1, 1}

Returns: 0



*/
// END CUT HERE

#line 61 "TrueStatements.cpp"
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
// END CUT HERE
#include <sstream>
#include <cmath>
using namespace std;

#define sz(a)  int((a).size())
#define pb  push_back
#define all(c)  (c).begin(),(c).end()
#define tr(c,i)  for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); i++)
#define rep(var,n)  for(int var=0;var<(n);var++)
#define found(s,e)  ((s).find(e)!=(s).end())
#define remove_(c,val) (c).erase(remove((c).begin(),(c).end(),(val)),(c).end())

class TrueStatements {
 public:
  int numberTrue(vector<int> stmts) {
	vector<int> cnt(51,0);
    tr(stmts,it) cnt[*it]++;
    priority_queue<int> pq;
    rep(i,51){
      if(cnt[i]==i) pq.push(i);
    }
    return pq.empty()? -1: pq.top();
  }
};

// BEGIN CUT HERE
#include <time.h>
clock_t start_time;
void timer_clear() { start_time = clock(); }
string timer() { clock_t end_time = clock(); double interval = (double)(end_time - start_time)/CLOCKS_PER_SEC; ostringstream os; os << " (" << interval*1000 << " msec)"; return os.str(); }

template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
int verify_case(const int &Expected, const int &Received) { if (Expected == Received) cerr << "PASSED" << timer() << endl; else { cerr << "FAILED" << timer() << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } return 0;}

template<int N> struct Case_ {};
char Test_(...);
int Test_(Case_<0>) {
	timer_clear();
	int statements_[] = {0, 1, 2, 3};
	  vector <int> statements(statements_, statements_+sizeof(statements_)/sizeof(*statements_)); 
	int RetVal = 1; 
	return verify_case(RetVal, TrueStatements().numberTrue(statements)); }
int Test_(Case_<1>) {
	timer_clear();
	int statements_[] = {0};
	  vector <int> statements(statements_, statements_+sizeof(statements_)/sizeof(*statements_)); 
	int RetVal = -1; 
	return verify_case(RetVal, TrueStatements().numberTrue(statements)); }
int Test_(Case_<2>) {
	timer_clear();
	int statements_[] = {0, 3, 1, 3, 2, 3};
	  vector <int> statements(statements_, statements_+sizeof(statements_)/sizeof(*statements_)); 
	int RetVal = 3; 
	return verify_case(RetVal, TrueStatements().numberTrue(statements)); }
int Test_(Case_<3>) {
	timer_clear();
	int statements_[] = {1, 1};
	  vector <int> statements(statements_, statements_+sizeof(statements_)/sizeof(*statements_)); 
	int RetVal = 0; 
	return verify_case(RetVal, TrueStatements().numberTrue(statements)); }

template<int N> void Run_() { cerr << "Test Case #" << N << "..." << flush; Test_(Case_<N>()); Run_<sizeof(Test_(Case_<N+1>()))==1 ? -1 : N+1>(); }
template<>      void Run_<-1>() {}
int main() { Run_<0>(); }
// END CUT HERE

