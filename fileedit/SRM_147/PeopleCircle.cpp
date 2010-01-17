// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
There are numMales males and numFemales females arranged in a circle. Starting from a given point, you count clockwise and remove the K'th person from the circle (where K=1 is the person at the current point, K=2 is the next person in the clockwise direction, etc...).  After removing that person, the next person in the clockwise direction becomes the 
new starting point.  After repeating this procedure numFemales times, 
there are no females left in the circle.		

Given numMales, numFemales and K, your task is to return what the initial arrangement of people in the circle must have been, starting from the starting point and in clockwise order.

For example, if there are 5 males and 3 females and you remove every second person, your return String will be "MFMFMFMM".


DEFINITION
Class:PeopleCircle
Method:order
Parameters:int, int, int
Returns:string
Method signature:string order(int numMales, int numFemales, int K)


CONSTRAINTS
-numMales is between 0 and 25 inclusive
-numFemales is between 0 and 25 inclusive
-K is between 1 and 1000 inclusive


EXAMPLES

0)
5
3
2

Returns: "MFMFMFMM"

Return "MFMFMFMM". On the first round you remove the second person - "M_MFMFMM". Your new circle looks like "MFMFMMM" from your new starting point. Then you remove the second person again etc.

1)
7
3
1

Returns: "FFFMMMMMMM"

Starting from the starting point you remove the first person, then you continue and remove the next first person etc. Clearly, all the females are located at the beginning. Hence return "FFFMMMMMMM"

2)
25
25
1000

Returns: "MMMMMFFFFFFMFMFMMMFFMFFFFFFFFFMMMMMMMFFMFMMMFMFMMF"

3)
5
5
3

Returns: "MFFMMFFMFM"

Here we mark the removed people with '_', and the starting position with lower-case:

Number of      | People Remaining
Rounds         | (in initial order)
---------------+-----------------
 0             | mFFMMFFMFM
 1             | MF_mMFFMFM
 2             | MF_MM_fMFM
 3             | MF_MM_FM_m
 4             | M__mM_FM_M
 5             | M__MM__m_M



4)
1
0
245

Returns: "M"

*/
// END CUT HERE

#line 87 "PeopleCircle.cpp"
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
#define rep(var,n)  for(int var=0;var<(n);var++)
#define all(c)  (c).begin(),(c).end()

class PeopleCircle {
 public:
  string order(int numMales, int numFemales, int K) {
    int n=numMales+numFemales, rest=n;
    vector<char> ring(n,'M');
    K--;
    int here=0;
    //printf(":: %d+%d, K=1+%d\n", numMales,numFemales,K);
    //cout << 0 << " " << string(all(ring)) << endl;
    rep(i,numFemales){
      // skip K persons
      int skipped=0;
      while(skipped<K){
        if(ring[(here++)%n]=='M') skipped++;
      }
      // skip Fs
      while (1){
        if(ring[(here)%n]=='F') here++; else break;
      }
      ring[here%n] = 'F';
      //cout << (1+i) << " " << string(all(ring)) << endl;
      rest--;
    }
    return string(all(ring));
  }
};//227.88 + 5min 17'9''-5

// BEGIN CUT HERE
#include <time.h>
clock_t start_time;
void timer_clear() { start_time = clock(); }
string timer() { clock_t end_time = clock(); double interval = (double)(end_time - start_time)/CLOCKS_PER_SEC; ostringstream os; os << " (" << interval*1000 << " msec)"; return os.str(); }

template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
int verify_case(const string &Expected, const string &Received) { if (Expected == Received) cerr << "PASSED" << timer() << endl; else { cerr << "FAILED" << timer() << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } return 0;}

template<int N> struct Case_ {};
char Test_(...);
int Test_(Case_<0>) {
	timer_clear();
	int numMales = 5; 
	int numFemales = 3; 
	int K = 2; 
	string RetVal = "MFMFMFMM"; 
	return verify_case(RetVal, PeopleCircle().order(numMales, numFemales, K)); }
int Test_(Case_<1>) {
	timer_clear();
	int numMales = 7; 
	int numFemales = 3; 
	int K = 1; 
	string RetVal = "FFFMMMMMMM"; 
	return verify_case(RetVal, PeopleCircle().order(numMales, numFemales, K)); }
int Test_(Case_<2>) {
	timer_clear();
	int numMales = 25; 
	int numFemales = 25; 
	int K = 1000; 
	string RetVal = "MMMMMFFFFFFMFMFMMMFFMFFFFFFFFFMMMMMMMFFMFMMMFMFMMF"; 
	return verify_case(RetVal, PeopleCircle().order(numMales, numFemales, K)); }
int Test_(Case_<3>) {
	timer_clear();
	int numMales = 5; 
	int numFemales = 5; 
	int K = 3; 
	string RetVal = "MFFMMFFMFM"; 
	return verify_case(RetVal, PeopleCircle().order(numMales, numFemales, K)); }
int Test_(Case_<4>) {
	timer_clear();
	int numMales = 1; 
	int numFemales = 0; 
	int K = 245; 
	string RetVal = "M"; 
	return verify_case(RetVal, PeopleCircle().order(numMales, numFemales, K)); }

template<int N> void Run_() { cerr << "Test Case #" << N << "..." << flush; Test_(Case_<N>()); Run_<sizeof(Test_(Case_<N+1>()))==1 ? -1 : N+1>(); }
template<>      void Run_<-1>() {}
int main() { Run_<0>(); }
// END CUT HERE

