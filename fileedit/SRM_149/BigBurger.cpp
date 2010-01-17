#line 2 "BigBurger.cpp"
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
#define rep(var,n)  for(int var=0;var<(n);var++)
// 241.56 5'20''
class BigBurger {
 public:
  int maxWait(vector <int> arrival, vector <int> service) {
    int n=sz(arrival), t=0, waitmax=0;
    rep(i,n){
      if(t<arrival[i]) t=arrival[i];
      int wait=t-arrival[i]; waitmax=max(waitmax,wait);
      t+=service[i];
    }
    return waitmax;
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
	int arrival_[] = {3,3,9};
	  vector <int> arrival(arrival_, arrival_+sizeof(arrival_)/sizeof(*arrival_)); 
	int service_[] = {2,15,14};
	  vector <int> service(service_, service_+sizeof(service_)/sizeof(*service_)); 
	int RetVal = 11; 
	return verify_case(RetVal, BigBurger().maxWait(arrival, service)); }
int Test_(Case_<1>) {
	timer_clear();
	int arrival_[] = {182};
	  vector <int> arrival(arrival_, arrival_+sizeof(arrival_)/sizeof(*arrival_)); 
	int service_[] = {11};
	  vector <int> service(service_, service_+sizeof(service_)/sizeof(*service_)); 
	int RetVal = 0; 
	return verify_case(RetVal, BigBurger().maxWait(arrival, service)); }
int Test_(Case_<2>) {
	timer_clear();
	int arrival_[] = {2,10,11};
	  vector <int> arrival(arrival_, arrival_+sizeof(arrival_)/sizeof(*arrival_)); 
	int service_[] = {3,4,3};
	  vector <int> service(service_, service_+sizeof(service_)/sizeof(*service_)); 
	int RetVal = 3; 
	return verify_case(RetVal, BigBurger().maxWait(arrival, service)); }
int Test_(Case_<3>) {
	timer_clear();
	int arrival_[] = {2,10,12};
	  vector <int> arrival(arrival_, arrival_+sizeof(arrival_)/sizeof(*arrival_)); 
	int service_[] = {15,1,15};
	  vector <int> service(service_, service_+sizeof(service_)/sizeof(*service_)); 
	int RetVal = 7; 
	return verify_case(RetVal, BigBurger().maxWait(arrival, service)); }

template<int N> void Run_() { cerr << "Test Case #" << N << "..." << flush; Test_(Case_<N>()); Run_<sizeof(Test_(Case_<N+1>()))==1 ? -1 : N+1>(); }
template<>      void Run_<-1>() {}
int main() { Run_<0>(); }
// END CUT HERE


// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// BigBurger Inc. wants to see if having a single person at the counter both to
take orders and to serve them is feasible.  At each BigBurger, customers will 
arrive and get in line. When they get to the head of the line they will place
their order, which will be assembled and served to them.  Then they will leave
the BigBurger and the next person in line will be able to order.

We need to know how long a customer may be forced to wait before he or she can
place an order.  Given a script that lists each customer for a typical day,
we want to calculate the maximum customer waiting time.  Each customer in the
script is characterized by an arrival time (measured in minutes after the store
opened) and a service duration (the number of minutes between ordering and
getting the food). 

Create a class BigBurger that contains method maxWait that is given a vector <int>
arrival and a vector <int> service describing all the customers and returns the
maximum time spent by a customer between arriving and placing the order. Corresponding
elements of arrival and service refer to the same customer, and they are
given in the order in which they arrive at the store (arrival is in non-descending
order).

If multiple customers arrive at the same time they will all join the line at the
same time, with the ones listed earlier ahead of ones appearing later in the list.



DEFINITION
Class:BigBurger
Method:maxWait
Parameters:vector <int>, vector <int>
Returns:int
Method signature:int maxWait(vector <int> arrival, vector <int> service)


CONSTRAINTS
-arrival will contain between 1 and 50 elements inclusive
-service will contain the same number of elements as arrival
-the elements of arrival will be in non-decreasing order
-each element of arrival will be between 1 and 720 inclusive
-each element of service will be between 1 and 15 inclusive


EXAMPLES

0)
{3,3,9}
{2,15,14}

Returns: 11


   Two customers arrive at time 3. The first one waits 0 time, orders, 
and is  served after 2 minutes, leaving at time 5. The second one then
orders and is served at time 20.  Meanwhile a customer arrives at
time 9 and waits until the second customer leaves.  This last customer 
then orders at time 20, and is served and leaves at time 20+14 = 34.  
The first customer waited 0 minutes, the second waited 2 minutes (from 
time 3 to time 5), and the last customer waited 11 minutes (from 
time 9 to time 20).

1)
{182}
{11}

Returns: 0

The first customer never needs to wait.

2)
{2,10,11}
{3,4,3}

Returns: 3

The third customer needs to wait from time 11 to time 14. Neither of the other customers needs to wait at all.

3)
{2,10,12}
{15,1,15}

Returns: 7

The second customer waits the longest.

*/
// END CUT HERE
