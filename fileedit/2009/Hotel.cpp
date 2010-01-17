#line 2 "Hotel.cpp"
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
typedef vector<int> vi;
#define sz(a)  int((a).size())
#define all(c)  (c).begin(),(c).end()
#define tr(c,i)  for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); i++)
#define rep(var,n)  for(int var=0;var<(n);var++)

class Hotel {
 public:
  int marketCost(int minCustomers, vector<int> customers, vector<int> cost) {
    int n=sz(customers);
    int maxc = minCustomers + *max_element(all(customers));
    vector<int> v(maxc+1, INT_MAX); v[0] = 0;
    rep(mc,minCustomers) {
      if (v[mc] == INT_MAX) continue;
// BEGIN CUT HERE
      //      printf("stage: mc=%d\n", mc);
// END CUT HERE
      rep(i,n){
        int c=customers[i], ct=cost[i];
// BEGIN CUT HERE
        /*
        printf(" + %d customer at price %d... min(%d,%d+%d)\n", c, ct,
               v[mc+c], v[mc],ct);
        */
// END CUT HERE
        v[mc+c] = min(v[mc+c],v[mc]+ct);
      }
    }
    int ct = INT_MAX;
    for(int mc=minCustomers; mc<=maxc; mc++) ct = min(ct,v[mc]);
    return ct;
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
	int minCustomers = 10; 
	int customers_[] = {1,2,3};
	  vector <int> customers(customers_, customers_+sizeof(customers_)/sizeof(*customers_)); 
	int cost_[] = {3,2,1};
	  vector <int> cost(cost_, cost_+sizeof(cost_)/sizeof(*cost_)); 
	int RetVal = 4; 
	return verify_case(RetVal, Hotel().marketCost(minCustomers, customers, cost)); }
int Test_(Case_<1>) {
	timer_clear();
	int minCustomers = 10; 
	int customers_[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	  vector <int> customers(customers_, customers_+sizeof(customers_)/sizeof(*customers_)); 
	int cost_[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	  vector <int> cost(cost_, cost_+sizeof(cost_)/sizeof(*cost_)); 
	int RetVal = 10; 
	return verify_case(RetVal, Hotel().marketCost(minCustomers, customers, cost)); }
int Test_(Case_<2>) {
	timer_clear();
	int minCustomers = 12; 
	int customers_[] = {5, 1};
	  vector <int> customers(customers_, customers_+sizeof(customers_)/sizeof(*customers_)); 
	int cost_[] = {3, 1};
	  vector <int> cost(cost_, cost_+sizeof(cost_)/sizeof(*cost_)); 
	int RetVal = 8; 
	return verify_case(RetVal, Hotel().marketCost(minCustomers, customers, cost)); }
int Test_(Case_<3>) {
	timer_clear();
	int minCustomers = 100; 
	int customers_[] = {9, 11, 4, 7, 2, 8};
	  vector <int> customers(customers_, customers_+sizeof(customers_)/sizeof(*customers_)); 
	int cost_[] = {4, 9, 3, 8, 1, 9};
	  vector <int> cost(cost_, cost_+sizeof(cost_)/sizeof(*cost_)); 
	int RetVal = 45; 
	return verify_case(RetVal, Hotel().marketCost(minCustomers, customers, cost)); }

template<int N> void Run_() { cerr << "Test Case #" << N << "..." << flush; Test_(Case_<N>()); Run_<sizeof(Test_(Case_<N+1>()))==1 ? -1 : N+1>(); }
template<>      void Run_<-1>() {}
int main() { Run_<0>(); }
// END CUT HERE


// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// The hotel industry  is difficult to thrive in, especially when competing at a resort city like Las Vegas.  
Marketing is essential and often gets a large part of total revenues.  You have a list of cities you can market at, 
and a good estimate of how many customers you will get for a certain amount of money spent at each city.  


You are given int[]s customers and cost.  cost[i] is the amount of money required to get customers[i] customers from the i-th city.  You are only allowed to spend integer multiples of the cost for any city. For example, if it costs 9 to get 3 customers from a certain city, you can spend 9 to get 3 customer, 18 to get 6 customers, 27 to get 9 customers, but not 3 to get 1 customer, or 12 to get 4 customers.  Each city has an unlimited number of potential customers.  Return the minimum amount of money required to get at least minCustomers customers.

DEFINITION
Class:Hotel
Method:marketCost
Parameters:int, vector <int>, vector <int>
Returns:int
Method signature:int marketCost(int minCustomers, vector <int> customers, vector <int> cost)


CONSTRAINTS
-minCustomers will be between 1 and 1000, inclusive.
-customers will contain between 1 and 20 elements, inclusive.
-cost will have the same number of elements as customers.
-Each element of cost and customers will be between 1 and 100, inclusive.


EXAMPLES

0)
10
{1,2,3}
{3,2,1}

Returns: 4

Just get 12 customers from the third city.

1)
10
{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}
{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}

Returns: 10

It does not matter from which city you get your customers.

2)
12
{5, 1}
{3, 1}

Returns: 8

Get 10 customers from the first city, and 2 from the second city.

3)
100
{9, 11, 4, 7, 2, 8}
{4, 9, 3, 8, 1, 9}

Returns: 45



*/
// END CUT HERE
