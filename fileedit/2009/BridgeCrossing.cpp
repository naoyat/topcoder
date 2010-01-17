#line 2 "BridgeCrossing.cpp"
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
#define all(c)  (c).begin(),(c).end()
#define tr(c,i)  for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); i++)
#define rep(var,n)  for(int var=0;var<(n);var++)
#define found(s,e)  ((s).find(e)!=(s).end())
typedef pair<int,int> ii;

class BridgeCrossing {
 public:
  int minTime(vector <int> times) {
	int m=sz(times);
    if (m==1) return times[0];
    
    sort(all(times));
    int fl=(1<<(m+1))-1;
    int lt=1<<m;
    vector<int> tm(lt);
    rep(i,lt){
      int t=0;
      for(int j=0,k=1;j<m;j++,k<<=1){
        if(i & k) t >?= times[j];
      }
      tm[i] = t;
    }
    //cout <<"tm:"<< tm << endl;
    
    priority_queue<ii> pq;
    pq.push(make_pair(0,0));
    vector<int> d(fl+1,INT_MAX); d[0]=0;
    while(!pq.empty()){
      ii t=pq.top(); pq.pop();
      int sc=-t.first, z=t.second;
      if(z==fl) return sc;
      if(z & lt){
        // あっちから
        for(int i=1;i<lt;i++){
          if((i&z) < i) continue;
          int popc=__builtin_popcount(i);
          if(popc==1){
            int newz=z-lt-i;
            int newsc=sc+tm[i];
            if(d[newz]>newsc){ d[newz]=newsc; pq.push(make_pair(-newsc,newz)); }
            break;
          }
        }
        // 実際には、いちばん速いやつを１人戻せばよい
      } else {
        // こっちから
        for(int i=1;i<lt;i++){
          if((i&z) > 0) continue;
          int popc=__builtin_popcount(i);
          if(popc==2){
            int newz=z+lt+i;
            int newsc=sc+tm[i];
            if(d[newz]>newsc){ d[newz]=newsc; pq.push(make_pair(-newsc,newz)); }
          }
        }
        // こちらからは２人行ったほうがよい。というか１人で行く理由はない
      }
    }
    return -1;
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
	int times_[] = { 1, 2, 5, 10 };
	  vector <int> times(times_, times_+sizeof(times_)/sizeof(*times_)); 
	int RetVal = 17; 
	return verify_case(RetVal, BridgeCrossing().minTime(times)); }
int Test_(Case_<1>) {
	timer_clear();
	int times_[] = { 1, 2, 3, 4, 5 };
	  vector <int> times(times_, times_+sizeof(times_)/sizeof(*times_)); 
	int RetVal = 16; 
	return verify_case(RetVal, BridgeCrossing().minTime(times)); }
int Test_(Case_<2>) {
	timer_clear();
	int times_[] = { 100 };
	  vector <int> times(times_, times_+sizeof(times_)/sizeof(*times_)); 
	int RetVal = 100; 
	return verify_case(RetVal, BridgeCrossing().minTime(times)); }
int Test_(Case_<3>) {
	timer_clear();
	int times_[] = { 1, 2, 3, 50, 99, 100 };
	  vector <int> times(times_, times_+sizeof(times_)/sizeof(*times_)); 
	int RetVal = 162; 
	return verify_case(RetVal, BridgeCrossing().minTime(times)); }

template<int N> void Run_() { cerr << "Test Case #" << N << "..." << flush; Test_(Case_<N>()); Run_<sizeof(Test_(Case_<N+1>()))==1 ? -1 : N+1>(); }
template<>      void Run_<-1>() {}
int main() { Run_<0>(); }
// END CUT HERE


// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// A well-known riddle goes like this: Four people are crossing an old bridge. The bridge cannot hold more than two people at once. It is dark, so they can't walk without a flashlight, and they only have one flashlight! Furthermore, the time needed to cross the bridge varies among the people in the group. For instance, let's say that the people take 1, 2, 5 and 10 minutes to cross the bridge. When people walk together, they always walk at the speed of the slowest person. It is impossible to toss the flashlight across the bridge, so one person always has to go back with the flashlight to the others. What is the minimum amount of time needed to get all the people across the bridge?

In this instance, the answer is 17. Person number 1 and 2 cross the bridge together, spending 2 minutes. Then person 1 goes back with the flashlight, spending an additional one minute. Then person 3 and 4 cross the bridge together, spending 10 minutes. Person 2 goes back with the flashlight (2 min), and person 1 and 2 cross the bridge together (2 min). This yields a total of 2+1+10+2+2 = 17 minutes spent.

You want to create a computer program to help you solve new instances of this problem. Given an vector <int> times, where the elements represent the time each person spends on a crossing, your program should return the minimum possible amount of time spent crossing the bridge.

DEFINITION
Class:BridgeCrossing
Method:minTime
Parameters:vector <int>
Returns:int
Method signature:int minTime(vector <int> times)


NOTES
-In an optimal solution, exactly two people will be sent across the bridge with the flashlight each time (if possible), and exactly one person will be sent back with the flashlight each time.  In other words, in an optimal solution, you will never send more than one person back from the far side at a time, and you will never send less than two people across to the far side each time (when possible).


CONSTRAINTS
-times will have between 1 and 6 elements, inclusive.
-Each element of times will be between 1 and 100, inclusive.


EXAMPLES

0)
{ 1, 2, 5, 10 }

Returns: 17

The example from the text.

1)
{ 1, 2, 3, 4, 5 }

Returns: 16

One solution is: 1 and 2 cross together (2min), 1 goes back (1min), 4 and 5 cross together (5min), 2 goes back (2min), 1 and 3 cross together (3min), 1 goes back (1min), 1 and 2 cross together (2min). This yields a total of 2 + 1 + 5 + 2 + 3 + 1 + 2 = 16 minutes spent.

2)
{ 100 }

Returns: 100

Only one person crosses the bridge once.

3)
{ 1, 2, 3, 50, 99, 100 }

Returns: 162

*/
// END CUT HERE
