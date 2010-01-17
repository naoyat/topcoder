// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// You are given an int N.  Find the smallest positive integer X such that the product of its digits (in decimal notation) is equal to N.  Return the number of digits in X, or return -1 if such a number does not exist.

DEFINITION
Class:ProductOfDigits
Method:smallestNumber
Parameters:int
Returns:int
Method signature:int smallestNumber(int N)


CONSTRAINTS
-N will be between 1 and 1,000,000,000, inclusive.


EXAMPLES

0)
1

Returns: 1

Just take X = 1. It contains 1 digit.

1)
10

Returns: 2

Here the smallest possible X is 25.

2)
26

Returns: -1



3)
100

Returns: 3

The number 455 has 3 digits and the product of its digits is 4 * 5 * 5 = 100.

4)
2520

Returns: 4



5)
864

Returns: 4



*/
// END CUT HERE

#line 66 "ProductOfDigits.cpp"
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

class ProductOfDigits {
public:
  int smallestNumber(int N) {
// BEGIN CUT HERE
	//2357
	//  N:1-1 000 000 000
// END CUT HERE
	int fs[8] = { 0,0,0,0,0,0,0,0 };
	int n = N;
	while (1) if (n % 2 == 0) { n /= 2; fs[2]++; } else break;
	while (1) if (n % 3 == 0) { n /= 3; fs[3]++; } else break;
	while (1) if (n % 5 == 0) { n /= 5; fs[5]++; } else break;
	while (1) if (n % 7 == 0) { n /= 7; fs[7]++; } else break;
// BEGIN CUT HERE
	printf("%d => 2.%d 3.%d 5.%d 7.%d => %d\n", N, fs[2],fs[3],fs[5],fs[7], n);
// END CUT HERE
	if (N == n) return N == 1 ? 1 : -1; // 1のみ
	if (n != 1) return -1;
	// 2, 3, 22, 5, 23, 7, 222, 33
	int k = fs[7] + fs[5];
	if (fs[2] >= 3) { 
	  k += fs[2] / 3;
	  fs[2] %= 3; // 0,1,2
	}
	if (fs[3] >= 2) { 
	  k += fs[3] / 2;
	  fs[3] %= 2; // 0,1
	}
	if (fs[3] == 1) {
	  switch(fs[2]) {
	  case 0: k++; fs[3]--; break;
	  case 1: k++; fs[3]--; fs[2]--; break;
	  case 2: k += 2; fs[3]--; fs[2]-=2; break; // 12
	  }
	}
	if (fs[2] > 0) { k++; fs[2] = 0; }
// BEGIN CUT HERE
	printf("  now %d, => 2.%d 3.%d  %d\n", k, fs[2],fs[3]);
// END CUT HERE
	return k;
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
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4();
	  if ((Case == -1) || (Case == 5)) test_case_5();
	  if ((Case == -1) || (Case == 6)) test_case_6();
	  if ((Case == -1) || (Case == 13)) test_case_13();
	  if ((Case == -1) || (Case == 20)) test_case_20();
	  if ((Case == -1) || (Case == 21)) test_case_21();
	  if ((Case == -1) || (Case == 22)) test_case_22();
	  if ((Case == -1) || (Case == 23)) test_case_23();
	  if ((Case == -1) || (Case == 24)) test_case_24();
	  if ((Case == -1) || (Case == 25)) test_case_25();
	  if ((Case == -1) || (Case == 26)) test_case_26();
	  if ((Case == -1) || (Case == 27)) test_case_27();
	  if ((Case == -1) || (Case == 28)) test_case_28();
	  if ((Case == -1) || (Case == 29)) test_case_29();
	}
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 1; verify_case(0, Arg1, smallestNumber(Arg0)); }
	void test_case_1() { int Arg0 = 10; int Arg1 = 2; verify_case(1, Arg1, smallestNumber(Arg0)); }
	void test_case_2() { int Arg0 = 26; int Arg1 = -1; verify_case(2, Arg1, smallestNumber(Arg0)); }
	void test_case_3() { int Arg0 = 100; int Arg1 = 3; verify_case(3, Arg1, smallestNumber(Arg0)); }
	void test_case_4() { int Arg0 = 2520; int Arg1 = 4; verify_case(4, Arg1, smallestNumber(Arg0)); }
	void test_case_5() { int Arg0 = 864; int Arg1 = 4; verify_case(5, Arg1, smallestNumber(Arg0)); }
  void test_case_6() { int Arg0 = 1000000000; int Arg1 = 12; verify_case(6, Arg1, smallestNumber(Arg0)); }
  void test_case_13() { int Arg0 = 2*3*5*7*11*13; int Arg1 = -1; verify_case(13, Arg1, smallestNumber(Arg0)); }

  void test_case_20() { int Arg0 = 2*2*2*2*3*3*3; int Arg1 = 3; verify_case(20, Arg1, smallestNumber(Arg0)); }
  void test_case_21() { int Arg0 = 2*2*2*3*3*3; int Arg1 = 3; verify_case(21, Arg1, smallestNumber(Arg0)); }
  void test_case_22() { int Arg0 = 2*2*3*3*3; int Arg1 = 3; verify_case(22, Arg1, smallestNumber(Arg0)); }
  void test_case_23() { int Arg0 = 2*3*3*3; int Arg1 = 2; verify_case(23, Arg1, smallestNumber(Arg0)); }
  void test_case_24() { int Arg0 = 2*2*2*3*3; int Arg1 = 2; verify_case(24, Arg1, smallestNumber(Arg0)); }
  void test_case_25() { int Arg0 = 2*2*3*3; int Arg1 = 2; verify_case(25, Arg1, smallestNumber(Arg0)); }
  void test_case_26() { int Arg0 = 2*3*3; int Arg1 = 2; verify_case(26, Arg1, smallestNumber(Arg0)); }
  void test_case_27() { int Arg0 = 2*2*2*3; int Arg1 = 2; verify_case(27, Arg1, smallestNumber(Arg0)); }
  void test_case_28() { int Arg0 = 2*2*3; int Arg1 = 2; verify_case(28, Arg1, smallestNumber(Arg0)); }
  void test_case_29() { int Arg0 = 2*3; int Arg1 = 1; verify_case(29, Arg1, smallestNumber(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main(int argc, char *argv[]) {
	ProductOfDigits ___test;
	___test.run_test( argc>=2 ? atoi(argv[1]):-1 );
}
// END CUT HERE
