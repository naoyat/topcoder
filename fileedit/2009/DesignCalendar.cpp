// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// An alien civilization has advanced to the point where it needs to start keeping track of time. Its leaders have therefore decided to design a calendar. Like many Earthly calendars, this calendar is going to be based on the motion of celestial bodies: in particular the calendar must include period of rotation of their planet (a day) and the period of orbit of the planet around the sun (a real year). Unfortunately, just as is the case on Earth, a real year is not necessarily a convenient integer number of days. Their solution to this problem is to define a calendar year, which is an integer number of days long, and periodically insert an extra day into some calendar years (leap years) in order to correct the discrepancy and resychronize the start of the calendar year with the start of the real year. 
The formal requirements for the calendar are as follows:

A normal calendar year is a length of time that is some integer number N days long.
A leap calendar year is exactly one day longer than a normal calendar year (N+1 days long).
Each calendar year is either a normal year or a leap year.
The calendar must have some positive integer period P, such that every P whole consecutive calendar years sum to exactly the same length of time as P real years.

The leaders wish to design the calendar to make the period P as short as possible. A day is dayLength time units long and a real year is yearLength time units long. Return the smallest achievable positive integer value of P.

DEFINITION
Class:DesignCalendar
Method:shortestPeriod
Parameters:int, int
Returns:int
Method signature:int shortestPeriod(int dayLength, int yearLength)


CONSTRAINTS
-yearLength will be between 1 and 1000000000 (10^9), inclusive.
-dayLength will be between 1 and yearLength, inclusive.


EXAMPLES

0)
4
1461

Returns: 4

These are the values for the Earth to the nearest quarter day. A days here is 4 quarter days long and a year is 365 * 4 + 1 = 1461 quarter days long. A single leap year every 4 years keeps the calendar synchronized.

1)
86400
31558150

Returns: 1728

These are the values for the Earth to the nearest second. A calendar with a period of 1728 years would be aligned to the start of the solar year to within a 
second after the first period.

2)
98
100

Returns: 49

3)
1000 
50000100

Returns: 10

4)
5673
28565335

Returns: 5673

5)
5555
846555

Returns: 1111

*/
// END CUT HERE

#line 74 "DesignCalendar.cpp"
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

class DesignCalendar {
public:
  int shortestPeriod(int dayLength, int yearLength) {
	int m = yearLength % dayLength;
	if (m == 0) return 1;

	int g = gcd(m,dayLength);
	return dayLength / g;
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
	  if ((Case == -1) || (Case == 7)) test_case_7();
	  if ((Case == -1) || (Case == 8)) test_case_8();
	  if ((Case == -1) || (Case == 9)) test_case_9();
	  if ((Case == -1) || (Case == 10)) test_case_10();
	  if ((Case == -1) || (Case == 11)) test_case_11();
	  if ((Case == -1) || (Case == 12)) test_case_12();
	}
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 4; int Arg1 = 1461; int Arg2 = 4; verify_case(0, Arg2, shortestPeriod(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 86400; int Arg1 = 31558150; int Arg2 = 1728; verify_case(1, Arg2, shortestPeriod(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 98; int Arg1 = 100; int Arg2 = 49; verify_case(2, Arg2, shortestPeriod(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 1000 ; int Arg1 = 50000100; int Arg2 = 10; verify_case(3, Arg2, shortestPeriod(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 5673; int Arg1 = 28565335; int Arg2 = 5673; verify_case(4, Arg2, shortestPeriod(Arg0, Arg1)); }
	void test_case_5() { int Arg0 = 5555; int Arg1 = 846555; int Arg2 = 1111; verify_case(5, Arg2, shortestPeriod(Arg0, Arg1)); }

  void test_case_6() { int Arg0 = 1; int Arg1 = 1; int Arg2 = 1; verify_case(6, Arg2, shortestPeriod(Arg0, Arg1)); }
  void test_case_7() { int Arg0 = 1; int Arg1 = 1000000000; int Arg2 = 1; verify_case(7, Arg2, shortestPeriod(Arg0, Arg1)); }
  void test_case_8() { int Arg0 = 1000000000; int Arg1 = 1000000000; int Arg2 = 1; verify_case(8, Arg2, shortestPeriod(Arg0, Arg1)); }
  void test_case_9() { int Arg0 = 1000000000; int Arg1 = 999999999; int Arg2 = 1000000000; verify_case(9, Arg2, shortestPeriod(Arg0, Arg1)); }
  void test_case_10() { int Arg0 = 4; int Arg1 = 1462; int Arg2 = 2; verify_case(10, Arg2, shortestPeriod(Arg0, Arg1)); }
  void test_case_11() { int Arg0 = 4; int Arg1 = 1463; int Arg2 = 4; verify_case(11, Arg2, shortestPeriod(Arg0, Arg1)); }
  void test_case_12() { int Arg0 = 5; int Arg1 = 12; int Arg2 = 5; verify_case(11, Arg2, shortestPeriod(Arg0, Arg1)); }


// END CUT HERE

};

// BEGIN CUT HERE
int main(int argc, char *argv[]) {
	DesignCalendar ___test;
	___test.run_test( argc>=2 ? atoi(argv[1]):-1 );
}
// END CUT HERE
