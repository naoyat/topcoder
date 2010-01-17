#line 2 "Inventory.cpp"
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
#define tr(c,i)  for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); i++)

typedef long long T;

T gcd(T m, T n)
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

class Fraction {
  T numer, denom;

public:
  Fraction(){ init(0,1); }
  Fraction(T n, T d=1){ init(n,d); }
  Fraction(const Fraction& other){ init(other); }

  Fraction& init(T n, T d); // impl.below
  Fraction& init(const Fraction& other); // impl.below

  double value() {
    if (numer == 0) return 0;
    if (denom == 1) return (double)numer;
    return (double)numer / denom;
  }

  Fraction& operator+=(const Fraction& other); // impl.below
  Fraction& operator/=(T n){ return init(numer, denom*n); }
};

/// implementation
Fraction&
Fraction::init(T n, T d)
{
  if (d < 0) n=-n, d=-d;
  if (n==0) {
    numer = 0, denom = 1;
  } else {
    T g = gcd(n,d);
    numer = n / g, denom = d / g;
  }
  return *this;
}

Fraction&
Fraction::init(const Fraction& other){
  numer = other.numer, denom = other.denom;
  return *this;
}

Fraction&
Fraction::operator+=(const Fraction& other)
{
  T g = gcd(denom, other.denom), l=denom/g*other.denom;// l=denomm*other.denom/gcd
  T n = numer*(other.denom/g) + other.numer*(denom/g);
  return init(n,l);
}

//
class Inventory {
 public:
  int monthlyOrder(vector <int> sales, vector <int> daysAvailable) {
    int n=sz(sales), d=0;
    Fraction sum;
    rep(i,n) {
      //if (sales[i]==0 || daysAvailable[i]==0) continue;
      if (daysAvailable[i]==0) continue;

      Fraction expected(sales[i]*30, daysAvailable[i]);
      sum += expected;
      d++;
    }
    sum /= d;
    return (int)ceil( sum.value() );
  }
};//154.61

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
	int sales_[] = {5};
	  vector <int> sales(sales_, sales_+sizeof(sales_)/sizeof(*sales_)); 
	int daysAvailable_[] = {15};
	  vector <int> daysAvailable(daysAvailable_, daysAvailable_+sizeof(daysAvailable_)/sizeof(*daysAvailable_)); 
	int RetVal = 10; 
	return verify_case(RetVal, Inventory().monthlyOrder(sales, daysAvailable)); }
int Test_(Case_<1>) {
	timer_clear();
	int sales_[] = {75,120,0,93};
	  vector <int> sales(sales_, sales_+sizeof(sales_)/sizeof(*sales_)); 
	int daysAvailable_[] = {24,30,0,30};
	  vector <int> daysAvailable(daysAvailable_, daysAvailable_+sizeof(daysAvailable_)/sizeof(*daysAvailable_)); 
	int RetVal = 103; 
	return verify_case(RetVal, Inventory().monthlyOrder(sales, daysAvailable)); }
int Test_(Case_<2>) {
	timer_clear();
	int sales_[] = {8773};
	  vector <int> sales(sales_, sales_+sizeof(sales_)/sizeof(*sales_)); 
	int daysAvailable_[] = {16};
	  vector <int> daysAvailable(daysAvailable_, daysAvailable_+sizeof(daysAvailable_)/sizeof(*daysAvailable_)); 
	int RetVal = 16450; 
	return verify_case(RetVal, Inventory().monthlyOrder(sales, daysAvailable)); }
int Test_(Case_<3>) {
	timer_clear();
	int sales_[] = {1115,7264,3206,6868,7301}
;
	  vector <int> sales(sales_, sales_+sizeof(sales_)/sizeof(*sales_)); 
	int daysAvailable_[] = {1,3,9,4,18};
	  vector <int> daysAvailable(daysAvailable_, daysAvailable_+sizeof(daysAvailable_)/sizeof(*daysAvailable_)); 
	int RetVal = 36091; 
	return verify_case(RetVal, Inventory().monthlyOrder(sales, daysAvailable)); }

int Test_(Case_<4>) {
	timer_clear();
	int sales_[] = {4010, 6439, 282, 9089, 95, 3176, 8042, 4084, 6350, 2239, 7659, 8792, 41};
    vector <int> sales(sales_, sales_+sizeof(sales_)/sizeof(*sales_)); 
	int daysAvailable_[] = {17, 27, 16, 25, 19, 8, 30, 9, 3, 26, 27, 15, 10};

    vector <int> daysAvailable(daysAvailable_, daysAvailable_+sizeof(daysAvailable_)/sizeof(*daysAvailable_)); 
    int RetVal = 11668; 
	return verify_case(RetVal, Inventory().monthlyOrder(sales, daysAvailable)); }


template<int N> void Run_() { cerr << "Test Case #" << N << "..." << flush; Test_(Case_<N>()); Run_<sizeof(Test_(Case_<N+1>()))==1 ? -1 : N+1>(); }
template<>      void Run_<-1>() {}
int main() { Run_<0>(); }
// END CUT HERE


// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// Inventory control is an important part of any business that maintains an inventory.  On the one hand, businesses want to have enough of a product in stock that they can ship orders immediately.  However, they do not want to have so much of a product in stock that all of their capital is tied up in that product.  To deal with this, businesses often maintain a small stock, and replenish that stock as it is sold on a monthly basis.  In other words, every month the business orders or produces more of a product so that it has some of the product in stock for the next month.
In this problem, a business wants to place a standing monthly order so that a certain number of items are delivered to it each month.  Your task is to help the business determine how large a standing order to place.  You will be given a vector <int>, sales, representing the number of items that the business sold for each of a number of months, and are to determine how many they can expect to sell in an average month.  Unfortunately, the business may have run out of items some months, so this is not as simple as just taking the average of the number of items sold each month.  You will be given a vector <int>, daysAvailable, whose elements represent the number of days that the item was available in each of the months (elements of daysAvailable correspond to elements of sales with the same index).  You should assume that, if the item was not available for a whole month, the business would have continued to sell the item at the same rate during the days of the month that it was not available as it did during the days the item was available, had sufficient stock been present.  So, for example, if the business sold 5 items in the first half of a month, and then ran out, you can assume that they would have sold 10 items that month, if they had been available.  On months when the item was available for zero days, you can tell nothing about the number of items that might have sold, so you should not include these months in your calculation.  Also, for simplicity, you may assume that all months have 30 days.  Thus, if the item were in stock for exactly half of the month this would be represented by a 15 in daysAvailable.  Furthermore, if the expected number of sales per month is not a whole number, you should round up since it is probably better to have one too many items than it is to have one too few.

DEFINITION
Class:Inventory
Method:monthlyOrder
Parameters:vector <int>, vector <int>
Returns:int
Method signature:int monthlyOrder(vector <int> sales, vector <int> daysAvailable)


NOTES
-While it is possible to solve this problem without using any double arithmetic, the last constraint ensures that the simpler solution using doubles will work if an epsilon is used properly (pay special attention to the last example).  In other words, once you have computed the expected number of sales, you should subtract a small number (like 1e-9) from this number before rounding up.


CONSTRAINTS
-daysAvailable and sales will have the same number of elements.
-daysAvailable and sales will both have between 1 and 50 elements, inclusive.
-Each element of daysAvailable will be between 0 and 30, inclusive.
-Each element of sales will be between 0 and 10,000, inclusive.
-If an element of daysAvailable is 0, the corresponding element of sales will also be 0.
-At least one element of daysAvailable will be greater than 0.
-The expected number of sales, prior to rounding, will not be within 1e-9 of an integer, unless the expected number is exactly an integer.


EXAMPLES

0)
{5}
{15}

Returns: 10

If 5 items are sold in 15 days (half a month), then 10 items could have been sold in a full month.

1)
{75,120,0,93}
{24,30,0,30}

Returns: 103

The expected number of sales per month is 102.25.  Rounding up, we get 103.

2)
{8773}
{16}

Returns: 16450

3)
{1115,7264,3206,6868,7301}

{1,3,9,4,18}

Returns: 36091

Watch out for double imprecision.  The expected number of sales per month, without rounding, is exactly 36091.

*/
// END CUT HERE
