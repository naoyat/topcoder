#line 2 "WhiteHats.cpp"
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
using namespace std;
// BEGIN CUT HERE
#include "cout.h"
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<string> vs;
typedef vector<long long> vll;
#define pb  push_back
#define all(c)  (c).begin(),(c).end()
#define mset(arr,val)  memset(arr,val,sizeof(arr))
#define rep(var,n)  for(int var=0;var<(n);var++)
#define forr(var,from,to) for(int var=(from);var<=(to);var++) 
#define found(s,e)  ((s).find(e)!=(s).end())
#define remove_(c,val) (c).erase(remove((c).begin(),(c).end(),(val)),(c).end())
#define lastc(str) (*((str).end()-1))
// END CUT HERE
#define sz(a)  int((a).size())
#define tr(c,i)  for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); i++)

class WhiteHats {
 public:
  int whiteNumber(vector <int> count) {
    int n=sz(count);
    int w=0;
	tr(count,it){
      w+=*it;
    }
    if(w%(n-1)>0) return -1;
    int c=w/(n-1);
    if(c>n) return -1;
    tr(count,it){
      if(*it<c-1 || c<*it) return -1;
    }
    return c;
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
	int count_[] = {2,1,1};
	  vector <int> count(count_, count_+sizeof(count_)/sizeof(*count_)); 
	int RetVal = 2; 
	return verify_case(RetVal, WhiteHats().whiteNumber(count)); }
int Test_(Case_<1>) {
	timer_clear();
	int count_[] = {2,2,2};
	  vector <int> count(count_, count_+sizeof(count_)/sizeof(*count_)); 
	int RetVal = 3; 
	return verify_case(RetVal, WhiteHats().whiteNumber(count)); }
int Test_(Case_<2>) {
	timer_clear();
	int count_[] = {0,0};
	  vector <int> count(count_, count_+sizeof(count_)/sizeof(*count_)); 
	int RetVal = 0; 
	return verify_case(RetVal, WhiteHats().whiteNumber(count)); }
int Test_(Case_<3>) {
	timer_clear();
	int count_[] = {1,1,1,2};
	  vector <int> count(count_, count_+sizeof(count_)/sizeof(*count_)); 
	int RetVal = -1; 
	return verify_case(RetVal, WhiteHats().whiteNumber(count)); }
int Test_(Case_<4>) {
	timer_clear();
	int count_[] = {10,10};
	  vector <int> count(count_, count_+sizeof(count_)/sizeof(*count_)); 
	int RetVal = -1; 
	return verify_case(RetVal, WhiteHats().whiteNumber(count)); }
int Test_(Case_<5>) {
	timer_clear();
	int count_[] = {7, 8, 7, 8, 8, 7, 8, 7, 8, 7, 8, 7, 7, 8, 7, 8};
	  vector <int> count(count_, count_+sizeof(count_)/sizeof(*count_)); 
	int RetVal = 8; 
	return verify_case(RetVal, WhiteHats().whiteNumber(count)); }
int Test_(Case_<6>) {
	timer_clear();
	int count_[] = {1, 1, 1, 1, 1, 1, 1, 1, 8};
	  vector <int> count(count_, count_+sizeof(count_)/sizeof(*count_)); 
	int RetVal = -1;
	return verify_case(RetVal, WhiteHats().whiteNumber(count)); }

template<int N> void Run_() { cerr << "Test Case #" << N << "..." << flush; Test_(Case_<N>()); Run_<sizeof(Test_(Case_<N+1>()))==1 ? -1 : N+1>(); }
template<>      void Run_<-1>() {}
int main() { Run_<0>(); }
// END CUT HERE


// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// There is a number of people in a room, and each of them wears a hat which is either black or white.
Every person counts the number of other people wearing white hats. You are given a vector <int> count, the i-th element of which is the number counted by the i-th person. Return the total number of people wearing white hats, or -1 if count doesn't correspond to a valid situation.


DEFINITION
Class:WhiteHats
Method:whiteNumber
Parameters:vector <int>
Returns:int
Method signature:int whiteNumber(vector <int> count)


CONSTRAINTS
-count will contain between 2 and 50 elements, inclusive.
-Each element of count will be between 0 and 50, inclusive.


EXAMPLES

0)
{2,1,1}

Returns: 2

The first person wears a black hat and sees two people wearing white hats.  Each person wearing a white hat sees only one other white hat in the room.

1)
{2,2,2}

Returns: 3

Everyone wears a white hat here.

2)
{0,0}

Returns: 0

Black hats only.

3)
{1,1,1,2}

Returns: -1



4)
{10,10}

Returns: -1

Now that's interesting.  There are only two people in the room, yet each of them counted 10 others.

*/
// END CUT HERE
