// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// Jack has bought a rectangular table containing a grid of lamps.  Each lamp is initially either "on" or "off".  There is a switch underneath each column, and when the switch is flipped, all the lamps in that column reverse their states ("on" lamps become "off" and vice versa).



A row in the grid is considered lit if all the lamps in that row are "on".  Jack must make exactly K flips.  The K flips do not necessarily have to be performed on K distinct switches.  His goal is to have as many lit rows as possible after making those flips.


You are given a vector <string> initial, where the j-th character of the i-th element is '1' (one) if the lamp in row i, column j is initially "on", and '0' (zero) otherwise.  Return the maximal number of rows that can be lit after performing exactly K flips.


DEFINITION
Class:LampsGrid
Method:mostLit
Parameters:vector <string>, int
Returns:int
Method signature:int mostLit(vector <string> initial, int K)


CONSTRAINTS
-initial will contain between 1 and 50 elements, inclusive.
-Each element of initial will contain between 1 and 50 characters, inclusive.
-Each element of initial will contain the same number of characters.
-Each element of initial will contain only the digits '0' and '1'.
-K will be between 0 and 1000, inclusive.


EXAMPLES

0)
{"01",
 "10",
 "10"}
1

Returns: 2

Here, Jack must flip exactly one switch.  If he flips the switch for the second column, the bottom two rows become lit.

1)
{"101010"}
2

Returns: 0



2)
{"00", "11"}
999

Returns: 0

No row can be lit after exactly 999 flips.


3)
{"0", "1", "0", "1", "0"}

1000

Returns: 2



4)
{"001", "101", "001", "000", "111", "001", "101", "111", "110", "000", "111", "010", "110", "001"}
6

Returns: 4



5)
{"01", "10", "01", "01", "10"}
1

Returns: 3



*/
// END CUT HERE

#line 88 "LampsGrid.cpp"
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

class LampsGrid {
 public:
  int mostLit(vector<string> il, int K) {
    map<string,int> ss;
    tr(il,it){
      if(found(ss,*it)) ss[*it]++;
      else ss[*it]=1;
    }
    int l=il[0].length();
    int maxc=0;
    tr(ss,it){
      string st=it->first;
      int cnt=it->second;
      int c=K; rep(i,l) if(st[i]=='0') c--;
      if(c>=0 && c%2==0) maxc=max(maxc,cnt);
    }
    return maxc;
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
	string initial_[] = {"01",
 "10",
 "10"};
	  vector <string> initial(initial_, initial_+sizeof(initial_)/sizeof(*initial_)); 
	int K = 1; 
	int RetVal = 2; 
	return verify_case(RetVal, LampsGrid().mostLit(initial, K)); }
int Test_(Case_<1>) {
	timer_clear();
	string initial_[] = {"101010"};
	  vector <string> initial(initial_, initial_+sizeof(initial_)/sizeof(*initial_)); 
	int K = 2; 
	int RetVal = 0; 
	return verify_case(RetVal, LampsGrid().mostLit(initial, K)); }
int Test_(Case_<2>) {
	timer_clear();
	string initial_[] = {"00", "11"};
	  vector <string> initial(initial_, initial_+sizeof(initial_)/sizeof(*initial_)); 
	int K = 999; 
	int RetVal = 0; 
	return verify_case(RetVal, LampsGrid().mostLit(initial, K)); }
int Test_(Case_<3>) {
	timer_clear();
	string initial_[] = {"0", "1", "0", "1", "0"};
	  vector <string> initial(initial_, initial_+sizeof(initial_)/sizeof(*initial_)); 
	int K = 1000; 
	int RetVal = 2; 
	return verify_case(RetVal, LampsGrid().mostLit(initial, K)); }
int Test_(Case_<4>) {
	timer_clear();
	string initial_[] = {"001", "101", "001", "000", "111", "001", "101", "111", "110", "000", "111", "010", "110", "001"};
	  vector <string> initial(initial_, initial_+sizeof(initial_)/sizeof(*initial_)); 
	int K = 6; 
	int RetVal = 4; 
	return verify_case(RetVal, LampsGrid().mostLit(initial, K)); }
int Test_(Case_<5>) {
	timer_clear();
	string initial_[] = {"01", "10", "01", "01", "10"};
	  vector <string> initial(initial_, initial_+sizeof(initial_)/sizeof(*initial_)); 
	int K = 1; 
	int RetVal = 3; 
	return verify_case(RetVal, LampsGrid().mostLit(initial, K)); }
int Test_(Case_<7>) {
	timer_clear();
	string initial_[] = {"01", "10", "01", "01", "10"};
	  vector <string> initial(initial_, initial_+sizeof(initial_)/sizeof(*initial_)); 
	int K = 0; 
	int RetVal = 0;
	return verify_case(RetVal, LampsGrid().mostLit(initial, K)); }
int Test_(Case_<8>) {
	timer_clear();
	string initial_[] = {"01", "11", "01", "01", "10"};
	  vector <string> initial(initial_, initial_+sizeof(initial_)/sizeof(*initial_)); 
	int K = 0; 
	int RetVal = 1;
	return verify_case(RetVal, LampsGrid().mostLit(initial, K)); }
int Test_(Case_<6>) {
	timer_clear();
	string initial_[] = {
      "01010101010101010101010101010101010101010101010101",
      "01010101010101010101010101010101010101010101010101",
      "01010101010101010101010101010101010101010101010101",
      "01010101010101010101010101010101010101010101010101",
      "01010101010101010101010101010101010101010101010101",
      "01010101010101010101010101010101010101010101010101",
      "01010101010101010101010101010101010101010101010101",
      "01010101010101010101010101010101010101010101010101",
      "01010101010101010101010101010101010101010101010101",
      "01010101010101010101010101010101010101010101010101",
      "01010101010101010101010101010101010101010101010101",
      "01010101010101010101010101010101010101010101010101",
      "01010101010101010101010101010101010101010101010101",
      "01010101010101010101010101010101010101010101010101",
      "01010101010101010101010101010101010101010101010101",
      "01010101010101010101010101010101010101010101010101",
      "01010101010101010101010101010101010101010101010101",
      "01010101010101010101010101010101010101010101010101",
      "01010101010101010101010101010101010101010101010101",
      "01010101010101010101010101010101010101010101010101",
      "01010101010101010101010101010101010101010101010101",
      "01010101010101010101010101010101010101010101010101",
      "01010101010101010101010101010101010101010101010101",
      "01010101010101010101010101010101010101010101010101",
      "01010101010101010101010101010101010101010101010101",
      "01010101010101010101010101010101010101010101010101",
      "01010101010101010101010101010101010101010101010101",
      "01010101010101010101010101010101010101010101010101",
      "01010101010101010101010101010101010101010101010101",
      "01010101010101010101010101010101010101010101010101",
      "01010101010101010101010101010101010101010101010101",
      "01010101010101010101010101010101010101010101010101",
      "01010101010101010101010101010101010101010101010101",
      "01010101010101010101010101010101010101010101010101",
      "01010101010101010101010101010101010101010101010101",
      "01010101010101010101010101010101010101010101010101",
      "01010101010101010101010101010101010101010101010101",
      "01010101010101010101010101010101010101010101010101",
      "01010101010101010101010101010101010101010101010101",
      "01010101010101010101010101010101010101010101010101",
      "01010101010101010101010101010101010101010101010101",
      "01010101010101010101010101010101010101010101010101",
      "01010101010101010101010101010101010101010101010101",
      "01010101010101010101010101010101010101010101010101",
      "01010101010101010101010101010101010101010101010101",
      "01010101010101010101010101010101010101010101010101",
      "01010101010101010101010101010101010101010101010101",
      "01010101010101010101010101010101010101010101010101",
      "01010101010101010101010101010101010101010101010101",
      "01010101010101010101010101010101010101010101010101"};
	  vector <string> initial(initial_, initial_+sizeof(initial_)/sizeof(*initial_)); 
	int K = 49; 
	int RetVal = 50;
	return verify_case(RetVal, LampsGrid().mostLit(initial, K)); }

template<int N> void Run_() { cerr << "Test Case #" << N << "..." << flush; Test_(Case_<N>()); Run_<sizeof(Test_(Case_<N+1>()))==1 ? -1 : N+1>(); }
template<>      void Run_<-1>() {}
int main() { Run_<0>(); }
// END CUT HERE

