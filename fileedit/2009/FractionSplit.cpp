#line 2 "FractionSplit.cpp"
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
typedef vector<string> vs;
#define sz(a)  int((a).size())
#define pb  push_back
#define all(c)  (c).begin(),(c).end()
#define tr(c,i)  for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); i++)
#define rep(var,n)  for(int var=0;var<(n);var++)

int gcd(int m, int n)
{
  if (m == 0 || n == 0) return 0;
  if (m == 1 || n == 1) return 1;
  if (m == n) return m;
  while (1) {
        if (m == 0) return n;
        if (n == 0) return m;
        if (m > n) m %= n; else n %= m;
  }
}

class FractionSplit {
 public:
  vector<string> getSum(int n, int d) {
    vs ans;
    for(int x=2;n>0;x++){
      //printf("n/d=%d/%d, 1/x=1/%d\n", n,d,x);
      // n/d >= 1/x : nx >= d
      int nr = n*x - d;
      if (nr >= 0){
        // n/d - 1/x = (nx-d)/xd
        char buf[128];
        sprintf(buf,"1/%d",x);
        ans.pb(buf);
        if(nr==0) break;
        int dr = x*d;
        int g = gcd(nr,dr);
        n = nr / g; d = dr / g;
      }
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
int verify_case(const vector <string> &Expected, const vector <string> &Received) { if (Expected == Received) cerr << "PASSED" << timer() << endl; else { cerr << "FAILED" << timer() << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } return 0;}

template<int N> struct Case_ {};
char Test_(...);
int Test_(Case_<0>) {
	timer_clear();
	int n = 4; 
	int d = 5; 
	string RetVal_[] = {"1/2", "1/4", "1/20" };
	  vector <string> RetVal(RetVal_, RetVal_+sizeof(RetVal_)/sizeof(*RetVal_)); 
	return verify_case(RetVal, FractionSplit().getSum(n, d)); }
int Test_(Case_<1>) {
	timer_clear();
	int n = 2; 
	int d = 3; 
	string RetVal_[] = {"1/2", "1/6" };
	  vector <string> RetVal(RetVal_, RetVal_+sizeof(RetVal_)/sizeof(*RetVal_)); 
	return verify_case(RetVal, FractionSplit().getSum(n, d)); }
int Test_(Case_<2>) {
	timer_clear();
	int n = 1; 
	int d = 2; 
	string RetVal_[] = {"1/2" };
	  vector <string> RetVal(RetVal_, RetVal_+sizeof(RetVal_)/sizeof(*RetVal_)); 
	return verify_case(RetVal, FractionSplit().getSum(n, d)); }
int Test_(Case_<3>) {
	timer_clear();
	int n = 15; 
	int d = 16; 
	string RetVal_[] = {"1/2", "1/3", "1/10", "1/240" };
	  vector <string> RetVal(RetVal_, RetVal_+sizeof(RetVal_)/sizeof(*RetVal_)); 
	return verify_case(RetVal, FractionSplit().getSum(n, d)); }
int Test_(Case_<4>) {
	timer_clear();
	int n = 14; 
	int d = 15; 
	string RetVal_[] = {"1/2", "1/3", "1/10" };
	  vector <string> RetVal(RetVal_, RetVal_+sizeof(RetVal_)/sizeof(*RetVal_)); 
	return verify_case(RetVal, FractionSplit().getSum(n, d)); }

template<int N> void Run_() { cerr << "Test Case #" << N << "..." << flush; Test_(Case_<N>()); Run_<sizeof(Test_(Case_<N+1>()))==1 ? -1 : N+1>(); }
template<>      void Run_<-1>() {}
int main() { Run_<0>(); }
// END CUT HERE


// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// Unit fractions are defined by having 1 in the numerator position.  Any positive fraction of the form n/d can be rewritten as a finite sum of distinct unit fractions.  When n<d, such a sum can be found by repeatedly subtracting the largest possible unit fraction until you reach 0.  

For example, if you begin with 4/5 then the largest unit fraction you can subtract is 1/2.  You are then left with 3/10.  The largest unit fraction you can subtract from 3/10 is 1/4.  You are then left with 1/20.  The largest unit fraction you can subtract is 1/20 leaving you with 0.  You should return a vector <string> giving the sequence of fractions you subtract, in the order you subtract them.  Each should be given in the form "1/q" where q is a positive integer with no leading zeros.  In the example just given, you would return  {"1/2","1/4","1/20"} 

DEFINITION
Class:FractionSplit
Method:getSum
Parameters:int, int
Returns:vector <string>
Method signature:vector <string> getSum(int n, int d)


CONSTRAINTS
-d will be between 2 and 16 inclusive.
-n will be between 1 and d-1 inclusive.


EXAMPLES

0)
4
5

Returns: {"1/2", "1/4", "1/20" }

The example above.

1)
2
3

Returns: {"1/2", "1/6" }

1/2 is the largest unit fraction that can be subtracted from 2/3.  The unit fraction 1/6 remains after the subtraction.

2)
1
2

Returns: {"1/2" }

1/2 is the largest unit fraction you can subtract.

3)
15
16

Returns: {"1/2", "1/3", "1/10", "1/240" }

4)
14
15

Returns: {"1/2", "1/3", "1/10" }

*/
// END CUT HERE
