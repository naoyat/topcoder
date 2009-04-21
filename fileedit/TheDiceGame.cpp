// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
Little John has one standard die with numbers one to six on its sides.  Each time he throws the die, he gets as many candies from his mom as the number on the top of the die. John’s goal is to collect at least candies candies. Then he will eat them all and became a little fat boy.


Return the expected number of throws needed for John to achieve his goal.



DEFINITION
Class:TheDiceGame
Method:expectedThrows
Parameters:int
Returns:double
Method signature:double expectedThrows(int candies)


NOTES
-The returned value must be accurate to within a relative or absolute value of 1E-9.


CONSTRAINTS
-candies will be between 1 and 1000000, inclusive.


EXAMPLES

0)
1

Returns: 1.0

John needs only one throw to get at least one candy.

1)
2

Returns: 1.1666666666666667

After the first throw, there is a probability of 1/6 that John will need an additional throw.

2)
7

Returns: 2.5216263717421126



3)
47

Returns: 13.90476189046144



*/
// END CUT HERE

#line 62 "TheDiceGame.cpp"
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

class TheDiceGame {
 public:
  double expectedThrows(int candies) {
// BEGIN CUT HERE
	// 1-1000000
// END CUT HERE
    int n=candies+6;
    vector<double> t(n,0.0),r(n,0.0);
    t[1]=t[2]=t[3]=t[4]=t[5]=t[6]=1.0;
    r[1]=r[2]=r[3]=r[4]=r[5]=r[6]=1.0/6;
    for(int i=1;i<candies;i++){
      double t_=t[i]+1, r_=r[i]/6;
      for(int j=1;j<=6;j++){
        double tj=t[i+j], rj=r[i+j];
        r[i+j]=r_+rj;
        t[i+j]=(t_*r_ + tj*rj)/r[i+j];
      }
    }
    double t_=0, r_=0;
    rep(i,6){
      int c=candies+i;
      t_ += t[c]*r[c]; r_ += r[c];
// BEGIN CUT HERE
      //printf("%d+%d: %g, %g\n", candies,i, t[c],r[c]);
// END CUT HERE
    }
    return t_/r_;
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
	int candies = 1; 
	double RetVal = 1.0; 
	return verify_case(RetVal, TheDiceGame().expectedThrows(candies)); }
int Test_(Case_<1>) {
	timer_clear();
	int candies = 2; 
	double RetVal = 1.1666666666666667; 
	return verify_case(RetVal, TheDiceGame().expectedThrows(candies)); }
int Test_(Case_<2>) {
	timer_clear();
	int candies = 7; 
	double RetVal = 2.5216263717421126; 
	return verify_case(RetVal, TheDiceGame().expectedThrows(candies)); }
int Test_(Case_<3>) {
	timer_clear();
	int candies = 47; 
	double RetVal = 13.90476189046144; 
	return verify_case(RetVal, TheDiceGame().expectedThrows(candies)); }

template<int N> void Run_() { cerr << "Test Case #" << N << "..." << flush; Test_(Case_<N>()); Run_<sizeof(Test_(Case_<N+1>()))==1 ? -1 : N+1>(); }
template<>      void Run_<-1>() {}
int main() { Run_<0>(); }
// END CUT HERE

