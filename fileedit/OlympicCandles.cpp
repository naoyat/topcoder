// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// To celebrate the upcoming Thought Challenge Olympics, you are going to follow tradition and light candles. On the first night of the event, you will light one candle. At the end of the night, you will extinguish the candle. On each subsequent night, you will light one more candle than you did on the previous night, so that on the n-th night (indexed from 1) you will light n candles (and extinguish them all in the morning).  Each night that you light a candle, its height will decrease by 1 inch; once its height reaches 0 inches, you cannot use it anymore.

You are given a vector <int> candles, the i-th element of which is the height of the i-th candle that you own. Return the maximum number of nights you can celebrate the event without going to the store to get more candles. For example, if you have three candles of height 2, you can light one the first night, the other two on the second night, and then all three candles on the third night.


DEFINITION
Class:OlympicCandles
Method:numberOfNights
Parameters:vector <int>
Returns:int
Method signature:int numberOfNights(vector <int> candles)


CONSTRAINTS
-candles will contain between 1 and 50 elements, inclusive.
-Each element of candles will be between 1 and 100, inclusive.


EXAMPLES

0)
{2, 2, 2}

Returns: 3

The example from the statement.

1)
{2, 2, 2, 4}

Returns: 4

With an extra candle we are able to use the candles for four nights.

2)
{5, 2, 2, 1}

Returns: 3



3)
{1, 2, 3, 4, 5, 6}

Returns: 6



4)
{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}

Returns: 4

*/
// END CUT HERE

#line 64 "OlympicCandles.cpp"
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

#define remove_(c,val) (c).erase(remove((c).begin(),(c).end(),(val)),(c).end())

class OlympicCandles {
public:
  int numberOfNights(vector<int> candles) {
    for(int nights=1;;nights++){
      sort(all(candles),greater<int>());
      if(candles.size() < nights) return nights-1;

      for(int i=0;i<nights;i++) candles[i]--;
	  remove_(candles,0);
      //cout << candles ;
	  //      candles.erase(remove(all(candles),0),candles.end());
      //cout << " => " << candles << endl;
    }
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
	int candles_[] = {2, 2, 2};
	  vector <int> candles(candles_, candles_+sizeof(candles_)/sizeof(*candles_)); 
	int RetVal = 3; 
	return verify_case(RetVal, OlympicCandles().numberOfNights(candles)); }
int Test_(Case_<1>) {
	timer_clear();
	int candles_[] = {2, 2, 2, 4};
	  vector <int> candles(candles_, candles_+sizeof(candles_)/sizeof(*candles_)); 
	int RetVal = 4; 
	return verify_case(RetVal, OlympicCandles().numberOfNights(candles)); }
int Test_(Case_<2>) {
	timer_clear();
	int candles_[] = {5, 2, 2, 1};
	  vector <int> candles(candles_, candles_+sizeof(candles_)/sizeof(*candles_)); 
	int RetVal = 3; 
	return verify_case(RetVal, OlympicCandles().numberOfNights(candles)); }
int Test_(Case_<3>) {
	timer_clear();
	int candles_[] = {1, 2, 3, 4, 5, 6};
	  vector <int> candles(candles_, candles_+sizeof(candles_)/sizeof(*candles_)); 
	int RetVal = 6; 
	return verify_case(RetVal, OlympicCandles().numberOfNights(candles)); }
int Test_(Case_<4>) {
	timer_clear();
	int candles_[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
	  vector <int> candles(candles_, candles_+sizeof(candles_)/sizeof(*candles_)); 
	int RetVal = 4; 
	return verify_case(RetVal, OlympicCandles().numberOfNights(candles)); }

template<int N> void Run_() { cerr << "Test Case #" << N << "..." << flush; Test_(Case_<N>()); Run_<sizeof(Test_(Case_<N+1>()))==1 ? -1 : N+1>(); }
template<>      void Run_<-1>() {}
int main() { Run_<0>(); }
// END CUT HERE

