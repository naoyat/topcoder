// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// Instant run-off voting is a system for selecting the most preferred candidate in an election.  At the beginning of the process, each voter ranks the candidates from most preferred to least preferred.  A series of automated voting rounds are then held to determine the overall winner.

In each round, each voter casts a single vote for his most preferred remaining candidate.  If a candidate receives strictly more than 50% of the votes cast in that round, that candidate is declared the winner of the election.  Otherwise, the candidate with the fewest votes in that round is eliminated, and another round is held.  If multiple candidates are tied for the least number of votes, they are all eliminated.  If all the candidates are eliminated, the election ends without a winner.

You are given the preferences of the voters in an election, and you must determine the outcome.  There are N candidates numbered 0 to N-1, inclusive.  The preferences are given in a vector <string> voters, where each element describes the preferences of a single voter.  This is a permutation of the digits 0 to N-1 in decreasing order of preference.  In other words, the first digit is the voter's most preferred candidate, the second digit is his second most preferred candidate, and so on.  Return the number of the candidate who wins the election, or -1 if the election ends without a winner.

DEFINITION
Class:InstantRunoffVoting
Method:winner
Parameters:vector <string>
Returns:int
Method signature:int winner(vector <string> voters)


CONSTRAINTS
-voters will contain between 1 and 50 elements, inclusive.
-Each element of voters will contain between 1 and 10 characters, inclusive.
-Each element of voters will contain the same number of characters.
-Each element of voters will be a permutation of the digits between 0 and N-1, where N is the number of characters in each element of voters.


EXAMPLES

0)
{"01","10","01","01","10"}

Returns: 0

In the first round, candidate 0 gets 3 votes and candidate 1 gets 2 votes, so candidate 0 wins.

1)
{"120","102","210","021","012"}

Returns: 1

Nobody gets an absolute majority in the first round and candidate 2 is eliminated. Candidate 1 then receives 3 votes in the next round, giving an absolute majority.

2)
{"10","01"}

Returns: -1

Each candidate gets 1 vote, so nobody can be declared winner.

3)
{"3120","3012","1032"
,"3120","2031","2103"
,"1230","1230"}

Returns: -1

Candidate 0 is eliminated in the first round of voting.  Candidate 2 is eliminated in the second round.   In the third round, candidates 1 and 3 get 4 votes each.  Neither candidate receives an absolute majority, and they are both eliminated for having the least number of votes, so the election ends without a winner.

4)
{"24103","30412","32014","21043","30412"
,"32401","14203","04123","30241","02413"
,"13042","01432","01342","32401","24301"
,"12430","41023","02413","42310","12043"}

Returns: 1



5)
{"0649853172","2146875039","2671548309"
,"5897216403","4719823056","7945213860"
,"9021538647","9286145307","9176403528"
,"3709486152"}

Returns: 9



*/
// END CUT HERE

#line 81 "InstantRunoffVoting.cpp"
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

class InstantRunoffVoting {
public:
  int winner(vector<string> voters) {
	int population=sz(voters), // 1-50
	  N=voters[0].length(); //1-10
	set<int> s; rep(i,N) s.insert(i);
	while(sz(s)>0){
// BEGIN CUT HERE
	  cout << "s:" << s <<endl;
// END CUT HERE
	  vector<int> votes(N,0);
	  rep(p,population){
		rep(i,N) {
		  int c=voters[p][i]-'0';
		  if(found(s,c)) { votes[c]++; break; }
		}
	  }
	  vector<int> vo(all(votes));
	  rep(i,N){
		if(votes[i]==0) s.erase(i); //oops
	  }
	  remove_(vo,0);
	  sort(all(vo));
// BEGIN CUT HERE
	  cout << votes << " => " << vo << endl;
// END CUT HERE
	  if(sz(vo)==0) return -1;
	  if(sz(vo)==1) {
		rep(i,N) if(votes[i]==vo[0]) return i;
	  }
	  int minvote=vo[0];
	  rep(i,N){
		if(votes[i]==minvote) s.erase(i);
	  }
	  remove_(vo,minvote);
	  if(sz(vo)==0) return -1;
// BEGIN CUT HERE
	  cout << "   => " << vo << endl;
// END CUT HERE
	  if(sz(vo)==1) {
		rep(i,N) if(votes[i]==vo[0]) return i;
	  }
	}
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
	string voters_[] = {"01","10","01","01","10"};
	  vector <string> voters(voters_, voters_+sizeof(voters_)/sizeof(*voters_)); 
	int RetVal = 0; 
	return verify_case(RetVal, InstantRunoffVoting().winner(voters)); }
int Test_(Case_<1>) {
	timer_clear();
	string voters_[] = {"120","102","210","021","012"};
	  vector <string> voters(voters_, voters_+sizeof(voters_)/sizeof(*voters_)); 
	int RetVal = 1; 
	return verify_case(RetVal, InstantRunoffVoting().winner(voters)); }
int Test_(Case_<2>) {
	timer_clear();
	string voters_[] = {"10","01"};
	  vector <string> voters(voters_, voters_+sizeof(voters_)/sizeof(*voters_)); 
	int RetVal = -1; 
	return verify_case(RetVal, InstantRunoffVoting().winner(voters)); }
int Test_(Case_<3>) {
	timer_clear();
	string voters_[] = {"3120","3012","1032"
,"3120","2031","2103"
,"1230","1230"};
	  vector <string> voters(voters_, voters_+sizeof(voters_)/sizeof(*voters_)); 
	int RetVal = -1; 
	return verify_case(RetVal, InstantRunoffVoting().winner(voters)); }
int Test_(Case_<4>) {
	timer_clear();
	string voters_[] = {"24103","30412","32014","21043","30412"
,"32401","14203","04123","30241","02413"
,"13042","01432","01342","32401","24301"
,"12430","41023","02413","42310","12043"};
	  vector <string> voters(voters_, voters_+sizeof(voters_)/sizeof(*voters_)); 
	int RetVal = 1; 
	return verify_case(RetVal, InstantRunoffVoting().winner(voters)); }
int Test_(Case_<5>) {
	timer_clear();
	string voters_[] = {"0649853172","2146875039","2671548309"
,"5897216403","4719823056","7945213860"
,"9021538647","9286145307","9176403528"
,"3709486152"};
	  vector <string> voters(voters_, voters_+sizeof(voters_)/sizeof(*voters_)); 
	int RetVal = 9; 
	return verify_case(RetVal, InstantRunoffVoting().winner(voters)); }
int Test_(Case_<6>) {
	timer_clear();
	string voters_[] = {"1308752964", "7196243085", "4305187926", "2365479018", "7962534108", "6841250739", "0196342758", "6185093724", "5130927648", "9506824731"};
	vector <string> voters(voters_, voters_+sizeof(voters_)/sizeof(*voters_)); 
	int RetVal = -1; 
	return verify_case(RetVal, InstantRunoffVoting().winner(voters)); }

template<int N> void Run_() { cerr << "Test Case #" << N << "..." << flush; Test_(Case_<N>()); Run_<sizeof(Test_(Case_<N+1>()))==1 ? -1 : N+1>(); }
template<>      void Run_<-1>() {}
int main() { Run_<0>(); }
// END CUT HERE

