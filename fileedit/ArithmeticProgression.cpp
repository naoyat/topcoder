// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// NOTE: This problem statement contains subscripts that may not display properly if viewed outside of the applet.

In mathematics, an arithmetic progression or arithmetic sequence is a sequence of numbers such that the difference of any two successive members of the sequence is a constant. For instance, the sequence 3, 5, 7, 9, 11, 13... is an arithmetic progression with common difference 2. An arithmetic sequence can always be represented as an=a0+n*d.


You will be given a sequence seq, where seqi = [ai+1] for some nondecreasing arithmetic sequence a (both indices are 0-based). [x] denotes the floor function (see Notes). The sequence a is defined as a0+i*d. Return the minimal possible value for d. If no possible value exists for d, return -1 instead.


DEFINITION
Class:ArithmeticProgression
Method:minCommonDifference
Parameters:int, vector <int>
Returns:double
Method signature:double minCommonDifference(int a0, vector <int> seq)


NOTES
-[x] denotes the floor function of x which returns the highest integer less than or equal to x. For example, [3.4] = 3, [0.6] = 0, [-1.2] = -2 and [-0.6] = -1.
-Your return value must be accurate to within an absolute or relative tolerance of 1E-9.


CONSTRAINTS
-seq will contain between 0 and 50 elements, inclusive.
-Each element of seq will be between -10^6 and 10^6, inclusive.
-a0 will be between -10^6 and 10^6, inclusive.


EXAMPLES

0)
0
{6, 13, 20, 27}

Returns: 6.75



1)
1
{2, 3, 4, 5, 6}

Returns: 1.0



2)
3
{}

Returns: 0.0

Since the sequence a is nondecreasing, d must be at least 0.

3)
3
{3, 3, 3, 3, 4}

Returns: 0.2



4)
1
{-3}

Returns: -1.0



5)
0
{6, 14}

Returns: -1.0



*/
// END CUT HERE

#line 85 "ArithmeticProgression.cpp"
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

class ArithmeticProgression {
public:
  double minCommonDifference(int a0, vector<int> seq) {
	int n=seq.size();
	if (n == 0) return 0;
	
	double dmin=0, dmax=INT_MAX;
	for (int i=1;i<=n;i++) {
	  double ai=seq[i-1]-a0, ai_ = ai+1;
	  double dlower=ai/i, dupper=ai_/i;
// BEGIN CUT HERE
	  //printf("i=%d, a[i]=%g.. {%g - %g}\n", i,ai, dlower,dupper);
// END CUT HERE
	  if (dmin < dlower) dmin = dlower;
	  if (dmax > dupper) dmax = dupper;
// BEGIN CUT HERE
	  //printf("  now %g - %g\n", dmin, dmax);
// END CUT HERE
	}

	if (dmin >= dmax) return -1.0;
	return dmin;
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
	int a0 = 0; 
	int seq_[] = {6, 13, 20, 27};
	  vector <int> seq(seq_, seq_+sizeof(seq_)/sizeof(*seq_)); 
	double RetVal = 6.75; 
	return verify_case(RetVal, ArithmeticProgression().minCommonDifference(a0, seq)); }
int Test_(Case_<1>) {
	timer_clear();
	int a0 = 1; 
	int seq_[] = {2, 3, 4, 5, 6};
	  vector <int> seq(seq_, seq_+sizeof(seq_)/sizeof(*seq_)); 
	double RetVal = 1.0; 
	return verify_case(RetVal, ArithmeticProgression().minCommonDifference(a0, seq)); }
int Test_(Case_<2>) {
	timer_clear();
	int a0 = 3; 
	vector <int> seq; 
	double RetVal = 0.0; 
	return verify_case(RetVal, ArithmeticProgression().minCommonDifference(a0, seq)); }
int Test_(Case_<3>) {
	timer_clear();
	int a0 = 3; 
	int seq_[] = {3, 3, 3, 3, 4};
	  vector <int> seq(seq_, seq_+sizeof(seq_)/sizeof(*seq_)); 
	double RetVal = 0.2; 
	return verify_case(RetVal, ArithmeticProgression().minCommonDifference(a0, seq)); }
int Test_(Case_<4>) {
	timer_clear();
	int a0 = 1; 
	int seq_[] = {-3};
	  vector <int> seq(seq_, seq_+sizeof(seq_)/sizeof(*seq_)); 
	double RetVal = -1.0; 
	return verify_case(RetVal, ArithmeticProgression().minCommonDifference(a0, seq)); }
int Test_(Case_<5>) {
	timer_clear();
	int a0 = 0; 
	int seq_[] = {6, 14};
	  vector <int> seq(seq_, seq_+sizeof(seq_)/sizeof(*seq_)); 
	double RetVal = -1.0; 
	return verify_case(RetVal, ArithmeticProgression().minCommonDifference(a0, seq)); }

template<int N> void Run_() { cerr << "Test Case #" << N << "..." << flush; Test_(Case_<N>()); Run_<sizeof(Test_(Case_<N+1>()))==1 ? -1 : N+1>(); }
template<>      void Run_<-1>() {}
int main() { Run_<0>(); }
// END CUT HERE

