// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// Given a positive integer number, concatenate one or more copies of number to create an integer that is divisible by k.  Do not add any leading zeroes.  Return the least number of copies needed, or -1 if it is impossible.

DEFINITION
Class:ConcatenateNumber
Method:getSmallest
Parameters:int, int
Returns:int
Method signature:int getSmallest(int number, int k)


CONSTRAINTS
-number will be between 1 and 1,000,000,000, inclusive.
-k will be between 1 and 100,000, inclusive.


EXAMPLES

0)
2
9

Returns: 9

At least 9 copies are needed, since 222222222 is divisible by 9.

1)
121
11

Returns: 1

121 is divisible by 11.

2)
1
2

Returns: -1

You can never get an even number by concatenating only 1's.

3)
35
98765

Returns: 9876

The resulting integer could be really big.

4)
1000000000
3

Returns: 3



*/
// END CUT HERE

#line 65 "ConcatenateNumber.cpp"
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

class ConcatenateNumber {
public:
  int getSmallest(int number, int k) {
    int keta=0;
    long long f=1, k_=k;
    for(int n=number;n>0;n/=10) {keta++; f*=10;}
    f%=k;
    long long n_=number%k, rem=n_;
    if(rem==0) return 1;
    set<int> rep; rep.insert(rem);
// BEGIN CUT HERE
    //printf("number=%d, k=%d, keta=%d, f=%lld, amari=%d\n", number,k,keta,f,amari);
// END CUT HERE
    int cnt=1;
    while(1){
      cnt++;
      long long new_rem = ((rem*f) + n_)%k_;
      if(found(rep,new_rem)) return -1;
      //if(new_rem==rem) return -1;
      if(new_rem==0) return cnt;
      rep.insert(new_rem);
      rem=new_rem;
    }
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
	int number = 2; 
	int k = 9; 
	int RetVal = 9; 
	return verify_case(RetVal, ConcatenateNumber().getSmallest(number, k)); }
int Test_(Case_<1>) {
	timer_clear();
	int number = 121; 
	int k = 11; 
	int RetVal = 1; 
	return verify_case(RetVal, ConcatenateNumber().getSmallest(number, k)); }
int Test_(Case_<2>) {
	timer_clear();
	int number = 1; 
	int k = 2; 
	int RetVal = -1; 
	return verify_case(RetVal, ConcatenateNumber().getSmallest(number, k)); }
int Test_(Case_<3>) {
	timer_clear();
	int number = 35; 
	int k = 98765; 
	int RetVal = 9876; 
	return verify_case(RetVal, ConcatenateNumber().getSmallest(number, k)); }
int Test_(Case_<4>) {
	timer_clear();
	int number = 1000000000; 
	int k = 3; 
	int RetVal = 3; 
	return verify_case(RetVal, ConcatenateNumber().getSmallest(number, k)); }
int Test_(Case_<5>) {
	timer_clear();
	int number = 4368969;
	int k = 158; 
	int RetVal = -1; 
	return verify_case(RetVal, ConcatenateNumber().getSmallest(number, k)); }

template<int N> void Run_() { cerr << "Test Case #" << N << "..." << flush; Test_(Case_<N>()); Run_<sizeof(Test_(Case_<N+1>()))==1 ? -1 : N+1>(); }
template<>      void Run_<-1>() {}
int main() { Run_<0>(); }
// END CUT HERE

