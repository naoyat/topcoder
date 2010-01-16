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

//#define sz(a)  int((a).size())
#define pb  push_back
#define all(c)  (c).begin(),(c).end()
#define tr(c,i)  for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); i++)
#define rep(var,n)  for(int var=0;var<(n);var++)
#define found(s,e)  ((s).find(e)!=(s).end())
#define remove_(c,val) (c).erase(remove((c).begin(),(c).end(),(val)),(c).end())
/*
#define LET(x,a) __typeof(a) x(a)
#define FOR(i,a,b) for(LET(i,a);i!=(b);++i)
//#define FOR(j,a,b) for(int j=a;j<b;++j)
#define REP(i,n) FOR(i,0,n);
#define bset(i,j) (((i)>>(j))&1)
#define sz size()
*/
#define REPS(i,x) for(int i=0;i<(int)((x).size());++i)

template<class T> inline T checkmax(T &a,T b){if(b>a)a=b;return a;}

class LampsGrid {
 public:
  int mostLit(vector<string> initial, int K) {
    int res=0;
    REPS(i,initial){
      int c=0,cc=0;
      REPS(j,initial) if(initial[j]==initial[i])c++;

      REPS(k,initial[i]) if(initial[i][k]=='0')cc++;
      if(cc==K||(K>=cc & K%2==cc%2)) checkmax(res,c);
    }
    
    return res;
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
	string initial_[] = {"01", "10", "10"};
    vector<string> initial(initial_, initial_+sizeof(initial_)/sizeof(*initial_)); 
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

