#line 2 "MixingLiquids.cpp"
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <cctype>
#include <algorithm>
#include <string>
#include <vector>
#include <deque>
#include <stack>
#include <queue>
#include <list>
#include <map>
#include <set>
// BEGIN CUT HERE
#include "cout.h"
// END CUT HERE
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<string> vs;
typedef vector<long long> vll;
#define sz(a)  int((a).size())
#define pb  push_back
#define all(c)  (c).begin(),(c).end()
#define mset(arr,val)  memset(arr,val,sizeof(arr))
#define tr(c,i)  for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); i++)
#define rep(var,n)  for(int var=0;var<(n);var++)
#define forr(var,from,to) for(int var=(from);var<=(to);var++) 
#define found(s,e)  ((s).find(e)!=(s).end())
#define remove_(c,val) (c).erase(remove((c).begin(),(c).end(),(val)),(c).end())
#define lastc(str) (*((str).end()-1))

class MixingLiquids {
	public:
	double howMuch(vector <int> percent, vector <int> amount, int need) {
		
	}
};

// BEGIN CUT HERE
#include <time.h>
clock_t start_time;
void timer_clear() { start_time = clock(); }
string timer() { clock_t end_time = clock(); double interval = (double)(end_time - start_time)/CLOCKS_PER_SEC; ostringstream os; os << " (" << interval*1000 << " msec)"; return os.str(); }

template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
int verify_case(const double &Expected, const double &Received) { double diff = Expected - Received; if (diff < 0) diff = -diff; if (diff < 1e-9) cerr << "PASSED" << timer() << endl; else { cerr << "FAILED" << timer() << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } return 0;}

template<int N> struct Case_ {};
char Test_(...);
int Test_(Case_<0>) {
	timer_clear();
	int percent_[] = {0, 100};
	  vector <int> percent(percent_, percent_+sizeof(percent_)/sizeof(*percent_)); 
	int amount_[] = {20, 30};
	  vector <int> amount(amount_, amount_+sizeof(amount_)/sizeof(*amount_)); 
	int need = 50; 
	double RetVal = 40.0; 
	return verify_case(RetVal, MixingLiquids().howMuch(percent, amount, need)); }
int Test_(Case_<1>) {
	timer_clear();
	int percent_[] = {0, 100};
	  vector <int> percent(percent_, percent_+sizeof(percent_)/sizeof(*percent_)); 
	int amount_[] = {20, 30};
	  vector <int> amount(amount_, amount_+sizeof(amount_)/sizeof(*amount_)); 
	int need = 60; 
	double RetVal = 50.0; 
	return verify_case(RetVal, MixingLiquids().howMuch(percent, amount, need)); }
int Test_(Case_<2>) {
	timer_clear();
	int percent_[] = {90, 70, 80};
	  vector <int> percent(percent_, percent_+sizeof(percent_)/sizeof(*percent_)); 
	int amount_[] = {10, 10, 10};
	  vector <int> amount(amount_, amount_+sizeof(amount_)/sizeof(*amount_)); 
	int need = 50; 
	double RetVal = 0.0; 
	return verify_case(RetVal, MixingLiquids().howMuch(percent, amount, need)); }
int Test_(Case_<3>) {
	timer_clear();
	int percent_[] = {30, 80, 60};
	  vector <int> percent(percent_, percent_+sizeof(percent_)/sizeof(*percent_)); 
	int amount_[] = {40, 10, 15};
	  vector <int> amount(amount_, amount_+sizeof(amount_)/sizeof(*amount_)); 
	int need = 57; 
	double RetVal = 35.18518518518519; 
	return verify_case(RetVal, MixingLiquids().howMuch(percent, amount, need)); }
int Test_(Case_<4>) {
	timer_clear();
	int percent_[] = {50,50,50};
	  vector <int> percent(percent_, percent_+sizeof(percent_)/sizeof(*percent_)); 
	int amount_[] = {395,971,964};
	  vector <int> amount(amount_, amount_+sizeof(amount_)/sizeof(*amount_)); 
	int need = 50; 
	double RetVal = 2330.0; 
	return verify_case(RetVal, MixingLiquids().howMuch(percent, amount, need)); }

template<int N> void Run_() { cerr << "Test Case #" << N << "..." << flush; Test_(Case_<N>()); Run_<sizeof(Test_(Case_<N+1>()))==1 ? -1 : N+1>(); }
template<>      void Run_<-1>() {}
int main() { Run_<0>(); }
// END CUT HERE


// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// In Chemistry, there's a different meaning to the word 'solution' than in programming. When we mix x liters of some substance with (100-x) liters of water, we get 100 liters of x-% solution of that substance.
You are given several bottles containing solutions of the same substance. The i-th bottle contains amount[i] liters of percent[i]-% solution. Return the maximal number of liters of need-% solution we can get by pouring together some of these bottles (possibly partially, see example 0).

DEFINITION
Class:MixingLiquids
Method:howMuch
Parameters:vector <int>, vector <int>, int
Returns:double
Method signature:double howMuch(vector <int> percent, vector <int> amount, int need)


NOTES
-The returned value must have an absolute or relative error less than 1e-9.


CONSTRAINTS
-percent will contain between 1 and 50 elements, inclusive.
-Each element of percent will be between 0 and 100, inclusive.
-amount will contain the same number of elements as percent.
-Each element of amount will be between 1 and 1000, inclusive.
-need will be between 0 and 100, inclusive.


EXAMPLES

0)
{0, 100}
{20, 30}
50

Returns: 40.0

We have 20 liters of water and 30 liters of pure substance. We need a 50% solution, so we combine all the water with 20 liters of substance.

1)
{0, 100}
{20, 30}
60

Returns: 50.0

We can use everything we have.

2)
{90, 70, 80}
{10, 10, 10}
50

Returns: 0.0

All our bottles contain too much substance.

3)
{30, 80, 60}
{40, 10, 15}
57

Returns: 35.18518518518519



4)
{50,50,50}
{395,971,964}
50

Returns: 2330.0

*/
// END CUT HERE
