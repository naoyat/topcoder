// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// A string composed of the letters 'A' and 'B' is called beautiful if it satisfies all of the following criteria:

it contains no more than countA occurences of 'A';
it contains no more than countB occurences of 'B';
each substring that contains only 'A's consists of no more than maxA characters;
each substring that contains only 'B's consists of no more than maxB characters.

Given countA, countB, maxA and maxB, return the maximum possible length of a beautiful string.

DEFINITION
Class:BeautifulString
Method:maximumLength
Parameters:int, int, int, int
Returns:int
Method signature:int maximumLength(int countA, int countB, int maxA, int maxB)


CONSTRAINTS
-countA will be between 0 and 1000000, inclusive.
-countB will be between 0 and 1000000, inclusive.
-maxA will be between 0 and 1000000, inclusive.
-maxB will be between 0 and 1000000, inclusive.


EXAMPLES

0)
0
0
10
10

Returns: 0

We don't have any available letters as countA=0 and countB=0, so the only beautiful string is the empty one.

1)
10
10
0
0

Returns: 0

Now we have available letters, but can't include them into the beautiful string as maxA=0 and maxB=0.

2)
3
5
1
1

Returns: 7

In this case we can't have two consecutive 'A's or 'B's, so letters in the beautiful string should alternate. If we start the string from 'A', the longest one we'll be able to get is "ABABAB". But if we start the string from 'B', we'll be able to get the longer one - "BABABAB".

3)
677578
502524
989951
504698

Returns: 1180102

Here maxA >= countA and maxB >= countB, so we can easily construct a beautiful string using all available countA+countB letters.

*/
// END CUT HERE

#line 74 "BeautifulString.cpp"
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

class BeautifulString {
 public:
  int maximumLength(int countA, int countB, int maxA, int maxB) {
	maxA = min(maxA,countA); maxB = min(maxB,countB);
    if(maxA==0) return maxB;
    if(maxB==0) return maxA;
    int rA=countA/maxA,rB=countB/maxB;
    if(rA<rB){
      swap(countA,countB); swap(maxA,maxB); swap(rA,rB);
    }
    int ma=maxA,mb=0,ml=ma;
    while(ma<=countA && mb<=countB) {
      int b=min(maxB,countB-mb);
      if(b==0) return ml;
      mb+=b; ml+=b;
      int a=min(maxA,countA-ma);
      ma+=a; ml+=a;
      if(a==0) return ml;
    }
    return ml;
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
	int countA = 0; 
	int countB = 0; 
	int maxA = 10; 
	int maxB = 10; 
	int RetVal = 0; 
	return verify_case(RetVal, BeautifulString().maximumLength(countA, countB, maxA, maxB)); }
int Test_(Case_<1>) {
	timer_clear();
	int countA = 10; 
	int countB = 10; 
	int maxA = 0; 
	int maxB = 0; 
	int RetVal = 0; 
	return verify_case(RetVal, BeautifulString().maximumLength(countA, countB, maxA, maxB)); }
int Test_(Case_<2>) {
	timer_clear();
	int countA = 3; 
	int countB = 5; 
	int maxA = 1; 
	int maxB = 1; 
	int RetVal = 7; 
	return verify_case(RetVal, BeautifulString().maximumLength(countA, countB, maxA, maxB)); }
int Test_(Case_<3>) {
	timer_clear();
	int countA = 677578; 
	int countB = 502524; 
	int maxA = 989951; 
	int maxB = 504698; 
	int RetVal = 1180102; 
	return verify_case(RetVal, BeautifulString().maximumLength(countA, countB, maxA, maxB)); }
int Test_(Case_<4>) { // #36
	timer_clear();
	int countA = 387085;
	int countB = 185394;
	int maxA = 4184;
	int maxB = 336687;
	int RetVal = 572479;
	return verify_case(RetVal, BeautifulString().maximumLength(countA, countB, maxA, maxB)); }
int Test_(Case_<5>) { // #40
    timer_clear(); //
	int countA = 4855;
	int countB = 2677;
	int maxA = 4855;
	int maxB = 1150;
	int RetVal = 7532;
	return verify_case(RetVal, BeautifulString().maximumLength(countA, countB, maxA, maxB)); }

template<int N> void Run_() { cerr << "Test Case #" << N << "..." << flush; Test_(Case_<N>()); Run_<sizeof(Test_(Case_<N+1>()))==1 ? -1 : N+1>(); }
template<>      void Run_<-1>() {}
int main() { Run_<0>(); }
// END CUT HERE

