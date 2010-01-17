#line 2 "DriveFailures.cpp"
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
#define sz(a)  int((a).size())
#define pb  push_back
#define tr(c,i)  for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); i++)
#define rep(var,n)  for(int var=0;var<(n);var++)

class DriveFailures {
 public:
  vector<double> failureChances(vector <double> failureProb) {
	int n=sz(failureProb);//1-15
    vector<double> ans(n+1,0.0);
    ans[0]=1.0;
    rep(i,n){
      vector<double> w(n+1,0.0);
      double r=failureProb[i];
      rep(j,n){
        w[j] +=ans[j]*(1.0-r);
        w[j+1] +=ans[j]*r;
      }
      rep(j,n+1) ans[j]=w[j];
    }
    return ans;
  }
};

// BEGIN CUT HERE
#include <time.h>
clock_t start_time;
void timer_clear() { start_time = clock(); }
string timer() { clock_t end_time = clock(); double interval = (double)(end_time - start_time)/CLOCKS_PER_SEC; ostringstream os; os << " (" << interval*1000 << " msec)"; return os.str(); }

template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
int verify_case(const vector <double> &Expected, const vector <double> &Received) { if (Expected == Received) cerr << "PASSED" << timer() << endl; else { cerr << "FAILED" << timer() << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } return 0;}

template<int N> struct Case_ {};
char Test_(...);
int Test_(Case_<0>) {
	timer_clear();
	double failureProb_[] = {1.0, 0.25, 0.0};
	  vector <double> failureProb(failureProb_, failureProb_+sizeof(failureProb_)/sizeof(*failureProb_)); 
	double RetVal_[] = {0.0, 0.75, 0.25, 0.0 };
	  vector <double> RetVal(RetVal_, RetVal_+sizeof(RetVal_)/sizeof(*RetVal_)); 
	return verify_case(RetVal, DriveFailures().failureChances(failureProb)); }
int Test_(Case_<1>) {
	timer_clear();
	double failureProb_[] = {0.4, 0.7};
	  vector <double> failureProb(failureProb_, failureProb_+sizeof(failureProb_)/sizeof(*failureProb_)); 
	double RetVal_[] = {0.18000000000000002, 0.54, 0.27999999999999997 };
	  vector <double> RetVal(RetVal_, RetVal_+sizeof(RetVal_)/sizeof(*RetVal_)); 
	return verify_case(RetVal, DriveFailures().failureChances(failureProb)); }
int Test_(Case_<2>) {
	timer_clear();
	double failureProb_[] = {0.2, 0.3, 0.0, 1.0, 0.8, 0.9};
	  vector <double> failureProb(failureProb_, failureProb_+sizeof(failureProb_)/sizeof(*failureProb_)); 
	double RetVal_[] = {0.0, 0.011199999999999993, 0.15319999999999995, 0.5031999999999999, 0.2892, 0.0432, 0.0 };
	  vector <double> RetVal(RetVal_, RetVal_+sizeof(RetVal_)/sizeof(*RetVal_)); 
	return verify_case(RetVal, DriveFailures().failureChances(failureProb)); }

template<int N> void Run_() { cerr << "Test Case #" << N << "..." << flush; Test_(Case_<N>()); Run_<sizeof(Test_(Case_<N+1>()))==1 ? -1 : N+1>(); }
template<>      void Run_<-1>() {}
int main() { Run_<0>(); }
// END CUT HERE


// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// A redundant storage system can survive a certain number of hard drive failures without losing any data. You are doing some analysis to determine the risk of various numbers of drives failing during one week. Your task is complicated by the fact that the drives in this system have different failure rates. You will be given a vector <double> containing n elements that describe the probability of each drive failing during a week. Return a vector <double> containing n + 1 elements, where element i is the probability that exactly i drives will fail during a week. Assume that drive failures are independent events.

DEFINITION
Class:DriveFailures
Method:failureChances
Parameters:vector <double>
Returns:vector <double>
Method signature:vector <double> failureChances(vector <double> failureProb)


NOTES
-The returned value must be accurate to within a relative or absolute value of 1E-9.
-If events with probabilities p1 and p2 are independent, then the probability of both occurring is p1p2.


CONSTRAINTS
-failureProb will contain between 1 and 15 elements, inclusive.
-Each element of failureProb will be between 0.0 and 1.0, inclusive.


EXAMPLES

0)
{1.0, 0.25, 0.0}

Returns: {0.0, 0.75, 0.25, 0.0 }

The first drive is guaranteed to fail, the second has a 25% chance of failing, and the third is guaranteed not to fail. So there is a 25% of two failures and a 75% chance of only one failure.


1)
{0.4, 0.7}

Returns: {0.18000000000000002, 0.54, 0.27999999999999997 }

There is a probability of 0.4 x 0.7 = 0.28 that both drives will fail. The chance that only the first will fail is 0.12 and that only the second will fail is 0.42, for a total probability of 0.54 that exactly one drive will fail. This leaves a probability of 0.18 that no drives will fail.

2)
{0.2, 0.3, 0.0, 1.0, 0.8, 0.9}

Returns: {0.0, 0.011199999999999993, 0.15319999999999995, 0.5031999999999999, 0.2892, 0.0432, 0.0 }



*/
// END CUT HERE
