// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
You are walking home from school through the city.  The city is infinite in size, with vertical streets located at every integer X value and horizontal streets located at every Y value.  You are currently located at (0,0) and are trying to get to your home, located at (X, Y).  You have two methods of travel available to you:  you can walk along the street to proceed to a horizontally or vertically adjacent intersection (which takes walkTime seconds), or you can sneak across the block diagonally to the opposite corner (taking sneakTime seconds).  You can walk or sneak in any of the eight directions shown in the image (see example 2).





Return the least amount of time that it will take you to return home.  See the examples for clarification.


DEFINITION
Class:StreetWalking
Method:minTime
Parameters:int, int, int, int
Returns:long long
Method signature:long long minTime(int X, int Y, int walkTime, int sneakTime)


CONSTRAINTS
-X will be between 0 and 1,000,000,000, inclusive.
-Y will be between 0 and 1,000,000,000, inclusive.
-walkTime will be between 1 and 10000, inclusive.
-sneakTime will be between 1 and 10000, inclusive.


EXAMPLES

0)
4
2
3
10

Returns: 18

The fastest way to your home is to not sneak at all.

1)
4
2
3
5

Returns: 16

In this case, it is faster to sneak across twice, following the path (0,0)->(1,0)->(2,1)->(3,1)->(4,2).  This takes 10 seconds for the sneaking, and 6 seconds for the walking.

2)
2
0
12
10

Returns: 20

One possible path is (0,0)->(1,1)->(2,0).

3)
25
18
7
11

Returns: 247



4)
24
16
12
10

Returns: 240



5)
10000000
50000000
800
901

Returns: 41010000000



6)
135
122
43
29

Returns: 3929



*/
// END CUT HERE

#line 105 "StreetWalking.cpp"
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

class StreetWalking {
public:
  long long minTime(int X, int Y, int walkTime, int sneakTime) {
	if(X>Y)swap(X,Y);
// BEGIN CUT HERE
	//printf("%d,%d, %d,%d, min(%d*%d, %d*%d+%d,%d)\n",X,Y,walkTime,sneakTime,
	//X+Y, walkTime, X,sneakTime, Y-X,walkTime);
// END CUT HERE
	long long a=Y-X, b=X, h=a/2, m=a%2;
	long long t = min(b*2*walkTime, b*sneakTime) 
	  + min(a*walkTime, h*2*sneakTime+m*walkTime);
	return t;
  }
};

// BEGIN CUT HERE
#include <time.h>
clock_t start_time;
void timer_clear() { start_time = clock(); }
string timer() { clock_t end_time = clock(); double interval = (double)(end_time - start_time)/CLOCKS_PER_SEC; ostringstream os; os << " (" << interval*1000 << " msec)"; return os.str(); }

template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
int verify_case(const long long &Expected, const long long &Received) { if (Expected == Received) cerr << "PASSED" << timer() << endl; else { cerr << "FAILED" << timer() << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } return 0;}

template<int N> struct Case_ {};
char Test_(...);
int Test_(Case_<0>) {
	timer_clear();
	int X = 4; 
	int Y = 2; 
	int walkTime = 3; 
	int sneakTime = 10; 
	long long RetVal = 18LL; 
	return verify_case(RetVal, StreetWalking().minTime(X, Y, walkTime, sneakTime)); }
int Test_(Case_<1>) {
	timer_clear();
	int X = 4; 
	int Y = 2; 
	int walkTime = 3; 
	int sneakTime = 5; 
	long long RetVal = 16LL; 
	return verify_case(RetVal, StreetWalking().minTime(X, Y, walkTime, sneakTime)); }
int Test_(Case_<2>) {
	timer_clear();
	int X = 2; 
	int Y = 0; 
	int walkTime = 12; 
	int sneakTime = 10; 
	long long RetVal = 20LL; 
	return verify_case(RetVal, StreetWalking().minTime(X, Y, walkTime, sneakTime)); }
int Test_(Case_<3>) {
	timer_clear();
	int X = 25; 
	int Y = 18; 
	int walkTime = 7; 
	int sneakTime = 11; 
	long long RetVal = 247LL; 
	return verify_case(RetVal, StreetWalking().minTime(X, Y, walkTime, sneakTime)); }
int Test_(Case_<4>) {
	timer_clear();
	int X = 24; 
	int Y = 16; 
	int walkTime = 12; 
	int sneakTime = 10; 
	long long RetVal = 240LL; 
	return verify_case(RetVal, StreetWalking().minTime(X, Y, walkTime, sneakTime)); }
int Test_(Case_<5>) {
	timer_clear();
	int X = 10000000; 
	int Y = 50000000; 
	int walkTime = 800; 
	int sneakTime = 901; 
	long long RetVal = 41010000000LL; 
	return verify_case(RetVal, StreetWalking().minTime(X, Y, walkTime, sneakTime)); }
int Test_(Case_<6>) {
	timer_clear();
	int X = 135; 
	int Y = 122; 
	int walkTime = 43; 
	int sneakTime = 29; 
	long long RetVal = 3929LL; 
	return verify_case(RetVal, StreetWalking().minTime(X, Y, walkTime, sneakTime)); }

template<int N> void Run_() { cerr << "Test Case #" << N << "..." << flush; Test_(Case_<N>()); Run_<sizeof(Test_(Case_<N+1>()))==1 ? -1 : N+1>(); }
template<>      void Run_<-1>() {}
int main() { Run_<0>(); }
// END CUT HERE

