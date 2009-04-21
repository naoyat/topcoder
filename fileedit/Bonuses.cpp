// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
You have a certain amount of money to give out as a bonus to employees.  The trouble is, who do you pick to receive what bonus?  You decide to assign a number of points to each employee, which corresponds to how much they helped the company in the last year.  You are given an vector <int> points, where each element contains the points earned by the corresponding employee (i.e. points[0] is the number of points awarded to employee 0).  Using this, you are to calculate the bonuses as follows:



- First, add up all the points, this is the pool of total points awarded.
- Each employee gets a percentage of the bonus money, equal to the percentage of the point pool that the employee got.
- Employees can only receive whole percentage amounts, so if an employee's cut of the bonus has a fractional percentage, truncate it.
- There may be some percentage of bonus left over (because of the fractional truncation).  If n% of the bonus is left over, give the top n employees 1% of the bonus.  There will be no more bonus left after this.  If two or more employees with the same number of points qualify for this "extra" bonus, but not enough bonus is left to give them all an extra 1%, give it to the employees that come first in points.



The return value should be a vector <int>, one element per employee in the order they were passed in.  Each element should be the percent of the bonus that the employee gets.


DEFINITION
Class:Bonuses
Method:getDivision
Parameters:vector <int>
Returns:vector <int>
Method signature:vector <int> getDivision(vector <int> points)


CONSTRAINTS
-points will have between 1 and 50 elements, inclusive.
-Each element of points will be between 1 and 500, inclusive.


EXAMPLES

0)
{1,2,3,4,5}

Returns: { 6,  13,  20,  27,  34 }

The total points in the point pool is 1+2+3+4+5 = 15.
Employee 1 gets 1/15 of the total pool, or 6.66667%, Employee 2 gets 13.33333%, Employee 3 gets 20% (exactly), Employee 4 gets 26.66667%, and Employee 5 gets 33.33333%.  After truncating, the percentages look like:
{6,13,20,26,33}
Adding up all the fractional percentages, we see there is 2% in extra bonuses, which go to the top two scorers.  These are the employees who received 4 and 5 points.

1)
{5,5,5,5,5,5}

Returns: { 17,  17,  17,  17,  16,  16 }

The pool of points is 30.  Each employee got 1/6 of the total pool, which translates to 16.66667%.  Truncating for all employees, we are left with 4% in extra bonuses.  Because everyone got the same number of points, the extra 1% bonuses are assigned to the four that come first in the array.

2)
{485, 324, 263, 143, 470, 292, 304, 188, 100, 254, 296,
 255, 360, 231, 311, 275,  93, 463, 115, 366, 197, 470}

Returns: { 8,  6,  4,  2,  8,  5,  5,  3,  1,  4,  5,  4,  6,  3,  5,  4,  1,  8,  1,  6,  3,  8 }

*/
// END CUT HERE

#line 61 "Bonuses.cpp"
#include <string>
#include <vector>
#include <map>
// BEGIN CUT HERE
#include <iostream>
#include "cout.h"
// END CUT HERE
#include <sstream>
using namespace std;

class Bonuses {
	public:
	vector<int> getDivision(vector<int> points) {
	  int persons = points.size();
	  vector<float> percentages(persons);
	  vector<int> bonuses(persons);
	  vector< pair<float,int> > pairs(persons);

	  int sum_of_points = 0;
	  for (int i=0; i<persons; i++) sum_of_points += points[i];

	  int bonus_rest = 100;
	  for (int i=0; i<persons; i++) {
		percentages[i] = 100.0 * points[i] / sum_of_points;
		int bonus = static_cast<int>( percentages[i] );
		bonuses[i] = bonus;
		bonus_rest -= bonus;
		pairs[i] = make_pair(-percentages[i], i);
	  }
	  sort( pairs.begin(), pairs.end() );

	  while (bonus_rest > 0) {
		int rep = min(bonus_rest,persons);
		for (int i=0; i<rep; i++) {
		  bonuses[ pairs[i].second ]++;
		  bonus_rest--;
		}
	  }
	  // cout << bonuses << endl;
	  return bonuses;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arr0[] = {1,2,3,4,5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 6,  13,  20,  27,  34 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, getDivision(Arg0)); }
	void test_case_1() { int Arr0[] = {5,5,5,5,5,5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 17,  17,  17,  17,  16,  16 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, getDivision(Arg0)); }
	void test_case_2() { int Arr0[] = {485, 324, 263, 143, 470, 292, 304, 188, 100, 254, 296,
 255, 360, 231, 311, 275,  93, 463, 115, 366, 197, 470}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 8,  6,  4,  2,  8,  5,  5,  3,  1,  4,  5,  4,  6,  3,  5,  4,  1,  8,  1,  6,  3,  8 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, getDivision(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	Bonuses ___test;
	___test.run_test(-1);
}
// END CUT HERE
