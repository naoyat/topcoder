// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// A Ferrers diagram of the partition of positive number n = a1 + a2 + ... + ak, for a list a1, a2, ..., ak of k positive integers with a1 ≥ a2 ≥ ... ≥ ak is an arrangement of n boxes in k rows, such that the boxes are left-justified, the first row is of length a1, the second row is of length a2, and so on, with the kth row of length ak. Let's call a FIELD diagram of order fieldOrder a Ferrers diagram with a1 ≤ fieldOrder, a2 ≤ fieldOrder - 1, ..., ak ≤ fieldOrder - k + 1, so a FIELD diagram can have a number of rows which is less than or equal to fieldOrder. Your method will be given fieldOrder, it should return the total number of FIELD diagrams of order fieldOrder. 

DEFINITION
Class:FIELDDiagrams
Method:countDiagrams
Parameters:int
Returns:long long
Method signature:long long countDiagrams(int fieldOrder)


CONSTRAINTS
-fieldOrder will be between 1 and 30, inclusive


EXAMPLES

0)
2

Returns: 4

There are four possible FIELD diagrams for fieldOrder equal to 2, corresponding to partitions: (1), (2), (1, 1), (2,1). They are shown in the picture below. There white stands for unused space in a row and red for boxes, corresponding to FIELD diagrams. 



1)
3

Returns: 13

2)
5

Returns: 131

*/
// END CUT HERE

#line 43 "FIELDDiagrams.cpp"
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

class FIELDDiagrams {
public:
  int fo;
  vector<long long> memo;

  long long sub(int last,int fieldOrder){
	int ceil = min(last,fieldOrder);
	if (ceil == 0) { return 1;}

	int key=(ceil<<5)|fieldOrder;
	if (memo[key]>=0) return memo[key];
	long long count=1LL;
	for(int ai=ceil;ai>0;ai--){
	  count += sub(ai,fieldOrder-1);
	}
	return memo[key] = count;
  }
  
  long long countDiagrams(int fieldOrder) {
	fo = fieldOrder;
	memo.resize(1024); fill(all(memo),-1);

	long long count = 0LL;
	for (int a1=fieldOrder;a1>0;a1--) {
	  count += sub(a1, fieldOrder-1);
	}
	return count;
  }
};

// BEGIN CUT HERE
#include <time.h>
clock_t start_time;
void timer_clear() { start_time = clock(); }
string timer() { clock_t end_time = clock(); double interval = (double)(end_time - start_time)/CLOCKS_PER_SEC; ostringstream os; os << " (" << interval*1000 << " msec)"; return os.str(); }

template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
int verify_case(const long long &Expected, const long long &Received) { if (Expected == Received) cerr << "PASSED" << timer() << endl; else { cerr << "FAILED" << timer() << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } return 0;}

template<int N> struct Case_ {};
char Test_(...);
int Test_(Case_<0>) {
	timer_clear();
	int fieldOrder = 2; 
	long long RetVal = 4LL; 
	return verify_case(RetVal, FIELDDiagrams().countDiagrams(fieldOrder)); }
int Test_(Case_<1>) {
	timer_clear();
	int fieldOrder = 3; 
	long long RetVal = 13LL; 
	return verify_case(RetVal, FIELDDiagrams().countDiagrams(fieldOrder)); }
int Test_(Case_<2>) {
	timer_clear();
	int fieldOrder = 5; 
	long long RetVal = 131LL; 
	return verify_case(RetVal, FIELDDiagrams().countDiagrams(fieldOrder)); }

template<int N> void Run_() { cerr << "Test Case #" << N << "..." << flush; Test_(Case_<N>()); Run_<sizeof(Test_(Case_<N+1>()))==1 ? -1 : N+1>(); }
template<>      void Run_<-1>() {}
int main() { Run_<0>(); }
// END CUT HERE

