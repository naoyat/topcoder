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
#include <time.h>
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
	int M=1<<26;
	vector<vector<int> > t(n);
	for (int i=0;i<n;i++) {
	  t[i].resize(27 * (M+1));
	  tr(t[i],it) *it = 0;
	}
	for (int st=0;st<n;st++) {
	  
	}
	
  }
// BEGIN CUT HERE
  clock_t start;
  void timer_clear()
  {
	start = clock();
  }
  char *timer()
  {
	clock_t end = clock();
	double interval = (double)(end - start)/CLOCKS_PER_SEC;
	
	char *ret = NULL;
	asprintf(&ret, " (%g msec)", interval*1000);
	return ret;
  }
// END CUT HERE
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 1; int Arg2 = 26; verify_case(0, Arg2, count(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 10; int Arg2 = 52; verify_case(1, Arg2, count(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 3; int Arg1 = 2; int Arg2 = 728; verify_case(2, Arg2, count(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 44; int Arg1 = 7; int Arg2 = 240249781; verify_case(3, Arg2, count(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main(int argc, char *argv[]) {
	TheLongPalindrome ___test;
	___test.run_test( argc>=2 ? atoi(argv[1]):-1 );
}
// END CUT HERE
