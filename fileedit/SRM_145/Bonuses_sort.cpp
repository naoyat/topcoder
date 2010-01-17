#line 2 "Bonuses.cpp"
// 250 211.75 (12'32'')
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
#define sz(a)  int((a).size())
#define pb  push_back
#define rep(var,n)  for(int var=0;var<(n);var++)
#define all(c)  (c).begin(),(c).end()

typedef pair<int,int> i_i;
#define cons(x,y) make_pair((x),(y))
#define car(x) ((x).first)
#define cdr(x) ((x).second)

class Bonuses {
 public:
  vector<int> getDivision(vector <int> points) {
    int n=sz(points);
    int sum=0;rep(i,n)sum+=points[i];

    vector<int> pd(n);
    int left=100;
    rep(i,n){pd[i]=100*points[i]/sum;left-=pd[i];}

    vector<i_i> pp(n);
    rep(i,n)pp[i]=cons(-points[i],i);
    sort(all(pp));//reverse(all(pp));
    rep(i,left) pd[cdr(pp[i])]++;
    return pd;
  }
};

// BEGIN CUT HERE
#include <time.h>
clock_t start_time;
void timer_clear() { start_time = clock(); }
string timer() { clock_t end_time = clock(); double interval = (double)(end_time - start_time)/CLOCKS_PER_SEC; ostringstream os; os << " (" << interval*1000 << " msec)"; return os.str(); }

template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
int verify_case(const vector <int> &Expected, const vector <int> &Received) { if (Expected == Received) cerr << "PASSED" << timer() << endl; else { cerr << "FAILED" << timer() << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } return 0;}

template<int N> struct Case_ {};
char Test_(...);
int Test_(Case_<0>) {
	timer_clear();
	int points_[] = {1,2,3,4,5};
	  vector <int> points(points_, points_+sizeof(points_)/sizeof(*points_)); 
	int RetVal_[] = { 6,  13,  20,  27,  34 };
	  vector <int> RetVal(RetVal_, RetVal_+sizeof(RetVal_)/sizeof(*RetVal_)); 
	return verify_case(RetVal, Bonuses().getDivision(points)); }
int Test_(Case_<1>) {
	timer_clear();
	int points_[] = {5,5,5,5,5,5};
	  vector <int> points(points_, points_+sizeof(points_)/sizeof(*points_)); 
	int RetVal_[] = { 17,  17,  17,  17,  16,  16 };
	  vector <int> RetVal(RetVal_, RetVal_+sizeof(RetVal_)/sizeof(*RetVal_)); 
	return verify_case(RetVal, Bonuses().getDivision(points)); }
int Test_(Case_<2>) {
	timer_clear();
	int points_[] = {485, 324, 263, 143, 470, 292, 304, 188, 100, 254, 296,
 255, 360, 231, 311, 275,  93, 463, 115, 366, 197, 470};
	  vector <int> points(points_, points_+sizeof(points_)/sizeof(*points_)); 
	int RetVal_[] = { 8,  6,  4,  2,  8,  5,  5,  3,  1,  4,  5,  4,  6,  3,  5,  4,  1,  8,  1,  6,  3,  8 };
	  vector <int> RetVal(RetVal_, RetVal_+sizeof(RetVal_)/sizeof(*RetVal_)); 
	return verify_case(RetVal, Bonuses().getDivision(points)); }
int Test_(Case_<3>) {
	timer_clear();
	int points_[] = { 3 };
    vector <int> points(points_, points_+sizeof(points_)/sizeof(*points_)); 
    int RetVal_[] = { 100 };
    vector <int> RetVal(RetVal_, RetVal_+sizeof(RetVal_)/sizeof(*RetVal_)); 
	return verify_case(RetVal, Bonuses().getDivision(points)); }

template<int N> void Run_() { cerr << "Test Case #" << N << "..." << flush; Test_(Case_<N>()); Run_<sizeof(Test_(Case_<N+1>()))==1 ? -1 : N+1>(); }
template<>      void Run_<-1>() {}
int main() { Run_<0>(); }
// END CUT HERE


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
