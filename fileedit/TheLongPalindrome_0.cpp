// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
John and Brus are studying string theory at the university.  Their task is to create a list of all the palindromes that contain between 1 and n lowercase letters ('a'-'z'), inclusive.  A palindrome is a string that reads the same forward and backward.  Additionally, each palindrome in their list must contain no more than k distinct letters.  Return the number of palindromes in the list modulo 1234567891.


DEFINITION
Class:TheLongPalindrome
Method:count
Parameters:int, int
Returns:int
Method signature:int count(int n, int k)


CONSTRAINTS
-n will be between 1 and 1,000,000,000, inclusive.
-k will be between 1 and 26, inclusive.


EXAMPLES

0)
1
1

Returns: 26

All palindromes in the list are single character strings.

1)
2
10

Returns: 52

Now we have single and double character palindromes.

2)
3
2

Returns: 728

A slightly longer list.

3)
44
7

Returns: 240249781

*/
// END CUT HERE

#line 57 "TheLongPalindrome.cpp"
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

class TheLongPalindrome {
	public:
	int count(int n, int k) {
		
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
	int n = 1; 
	int k = 1; 
	int RetVal = 26; 
	return verify_case(RetVal, TheLongPalindrome().count(n, k)); }
int Test_(Case_<1>) {
	timer_clear();
	int n = 2; 
	int k = 10; 
	int RetVal = 52; 
	return verify_case(RetVal, TheLongPalindrome().count(n, k)); }
int Test_(Case_<2>) {
	timer_clear();
	int n = 3; 
	int k = 2; 
	int RetVal = 728; 
	return verify_case(RetVal, TheLongPalindrome().count(n, k)); }
int Test_(Case_<3>) {
	timer_clear();
	int n = 44; 
	int k = 7; 
	int RetVal = 240249781; 
	return verify_case(RetVal, TheLongPalindrome().count(n, k)); }

template<int N> void Run_() { cerr << "Test Case #" << N << "..." << flush; Test_(Case_<N>()); Run_<sizeof(Test_(Case_<N+1>()))==1 ? -1 : N+1>(); }
template<>      void Run_<-1>() {}
int main() { Run_<0>(); }
// END CUT HERE

