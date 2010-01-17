#line 2 "ObtainingDigitK.cpp"
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
class ObtainingDigitK {
  vector<int> ds;
  int l,k_;
  
  bool inc(){
    for(int i=l;i>=0;i--){
      if(ds[i]==9){
        ds[i]=0;
        if(k_==0) return true;
      }else{
        ds[i]++;
        return (ds[i]==k_);
      }
    }
    return false;
  }
 public:
  int minNumberToAdd(string originalNumber, int k) {
	l=originalNumber.length(); k_=k;
    ds.resize(l+1);
    ds[0]=0;
    rep(i,l) {
      ds[i+1]=originalNumber[i]-'0';
      if(ds[i+1]==k) return 0;
    }
    for(int i=1;i<=10;i++){
      //cout << "ds: " << ds << endl;
      if(inc()) return i;
    }
    return 222;
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
	string originalNumber = "153"; 
	int k = 7; 
	int RetVal = 4; 
	return verify_case(RetVal, ObtainingDigitK().minNumberToAdd(originalNumber, k)); }
int Test_(Case_<1>) {
	timer_clear();
	string originalNumber = "158"; 
	int k = 7; 
	int RetVal = 9; 
	return verify_case(RetVal, ObtainingDigitK().minNumberToAdd(originalNumber, k)); }
int Test_(Case_<2>) {
	timer_clear();
	string originalNumber = "7853192"; 
	int k = 2; 
	int RetVal = 0; 
	return verify_case(RetVal, ObtainingDigitK().minNumberToAdd(originalNumber, k)); }
int Test_(Case_<3>) {
	timer_clear();
	string originalNumber = "99999999999999999999999999999999999999999999999"; 
	int k = 0; 
	int RetVal = 1; 
	return verify_case(RetVal, ObtainingDigitK().minNumberToAdd(originalNumber, k)); }

template<int N> void Run_() { cerr << "Test Case #" << N << "..." << flush; Test_(Case_<N>()); Run_<sizeof(Test_(Case_<N+1>()))==1 ? -1 : N+1>(); }
template<>      void Run_<-1>() {}
int main() { Run_<0>(); }
// END CUT HERE


// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
Return the smallest non-negative integer that can be added to originalNumber such that the resulting integer contains at least one digit k. All numbers should have no extra leading zeroes.



DEFINITION
Class:ObtainingDigitK
Method:minNumberToAdd
Parameters:string, int
Returns:int
Method signature:int minNumberToAdd(string originalNumber, int k)


CONSTRAINTS
-originalNumber will contain between 1 and 50 characters, inclusive.
-originalNumber will contain only digits ('0'-'9').
-originalNumber will represent a non-negative integer with no extra leading zeroes.
-k will be between 0 and 9, inclusive.


EXAMPLES

0)
"153"
7

Returns: 4

153 + 4 = 157

1)
"158"
7

Returns: 9

158 + 9 = 167

2)
"7853192"
2

Returns: 0

Digit '2' is already present in the number.

3)
"99999999999999999999999999999999999999999999999"
0

Returns: 1

Add 1 to get a lot of zeroes.

*/
// END CUT HERE
