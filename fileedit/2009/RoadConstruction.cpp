// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
During today's meeting of the Council of Rainban, your advisors warned you about the growing traffic problems in your fair country.  It seems that the Daring Ostrich Society has shut down the Rainban Access Motorway due to the annual migration of ostriches across the highway.  This is rather unfortunate, as many cars are now trapped on the highway.  Construction crews have begun to build an emergency exit so that the trapped cars can exit, but there will be chaos without rules on when cars can exit.  To promote friendly driving, you decide to enforce the following rules:

A car may not exit if there is a car in front of it in its lane.
A car may not exit if a car in a lower numbered lane is about to exit.
Once a car has reached the front of its lane, it must (if possible) yield exactly once to a car from a higher numbered lane.  This means that the car will allow a car from a higher numbered lane to exit (if one exists).
If a car has fulfilled all of the above requirements, it may exit the highway.  The next car in that lane (if there is one) then moves to the front of the lane.

As an example, suppose that there are five cars in the highway, as pictured below (with the front of the lane located on the left):


0 A B
1 C D
2 E


Car A has not yet yielded, so it must yield.  The same happens for car C.  Car E cannot yield (as there are no cars in higher lanes), and so it exits.  Now car A fulfills the exiting rules (having yielded to car E), and it can exit.  Car B moves up to the front, but has not yet yielded, and thus must yield to car C.  Car B then can exit, followed by car D.

You will be given currentLanes.  The i-th element of currentLanes corresponds to the cars currently located in lane i.  The 0-th character in each element corresponds to the car at the front of the lane.  No car in currentLanes has yielded yet.  The car represented by the character 'D' is a diplomat from a far-off country.  You want to know how many cars exit in front of this diplomat (so that you know whether you have time to take a bath before his arrival), and return this number.


DEFINITION
Class:RoadConstruction
Method:getExitTime
Parameters:vector <string>
Returns:int
Method signature:int getExitTime(vector <string> currentLanes)


CONSTRAINTS
-currentLanes will contain between 1 and 50 elements, inclusive.
-Each element of currentLanes will contain between 1 and 50 characters, inclusive.
-Each character of currentLanes will be an uppercase letter ('A'-'Z').
-There will be exactly one 'D' in currentLanes.


EXAMPLES

0)
{"AB",
 "CD",
 "E"}

Returns: 4

The example from the problem statement.

1)
{"AH",
 "D",
 "BCG",
 "E",
 "F"}

Returns: 2

Car F goes first.  Having yielded right of way, car A moves next, followed by car D (which already yielded to car F).

2)
{"AAA",
 "A",
 "AAA",
 "A",
 "AAD",
 "A",
 "AAB"}

Returns: 13

Multiple cars can be represented by the same letter, but there will be exactly one diplomat.

3)
{"DEFGHIJK"}

Returns: 0



4)
{"I",
 "WANT",
 "TO",
 "DRINK",
 "SOME",
 "COFFEE"}

Returns: 5



*/
// END CUT HERE

#line 98 "RoadConstruction.cpp"
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
#define found(s,e)  ((s).find(e)!=(s).end())
#define remove_(c,val) (c).erase(remove((c).begin(),(c).end(),(val)),(c).end())
#define lastc(str) (*((str).end()-1))

typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<long long> vll;

class RoadConstruction {
 public:
  int getExitTime(vector<string> currentLanes) {
    int n=sz(currentLanes);
    vector<vector<pair<bool,char> > > lanes(n);
    int cars=0;
    rep(i,n){
      int l=sz(currentLanes[i]);
      rep(j,l){
        char c = currentLanes[i][j];
        lanes[i].push_back(make_pair(false,c));
        cars++;
      }
    }
    rep(t,cars){
      bool exitable=true;
      //cout << "t=" << t << ", lanes=" << lanes << endl;
      tr(lanes,it){
        //cout << "  *it =" << *it << endl;
        if(it==(lanes.end()-1)){
          if(it->front().second=='D') return t;
          it->erase(it->begin());
          if(sz(*it)==0) lanes.erase(it);
          goto next;
        }else if(exitable){
          if(it->front().first){
            if(it->front().second=='D') return t;
            it->erase(it->begin());
            if(sz(*it)==0) lanes.erase(it);
            goto next;
          } else {
            it->front().first=true;
          }
        }
      }
   next:;
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
	string currentLanes_[] = {"AB",
 "CD",
 "E"};
	  vector <string> currentLanes(currentLanes_, currentLanes_+sizeof(currentLanes_)/sizeof(*currentLanes_)); 
	int RetVal = 4; 
	return verify_case(RetVal, RoadConstruction().getExitTime(currentLanes)); }
int Test_(Case_<1>) {
	timer_clear();
	string currentLanes_[] = {"AH",
 "D",
 "BCG",
 "E",
 "F"};
	  vector <string> currentLanes(currentLanes_, currentLanes_+sizeof(currentLanes_)/sizeof(*currentLanes_)); 
	int RetVal = 2; 
	return verify_case(RetVal, RoadConstruction().getExitTime(currentLanes)); }
int Test_(Case_<2>) {
	timer_clear();
	string currentLanes_[] = {"AAA",
 "A",
 "AAA",
 "A",
 "AAD",
 "A",
 "AAB"};
	  vector <string> currentLanes(currentLanes_, currentLanes_+sizeof(currentLanes_)/sizeof(*currentLanes_)); 
	int RetVal = 13; 
	return verify_case(RetVal, RoadConstruction().getExitTime(currentLanes)); }
int Test_(Case_<3>) {
	timer_clear();
	string currentLanes_[] = {"DEFGHIJK"};
	  vector <string> currentLanes(currentLanes_, currentLanes_+sizeof(currentLanes_)/sizeof(*currentLanes_)); 
	int RetVal = 0; 
	return verify_case(RetVal, RoadConstruction().getExitTime(currentLanes)); }
int Test_(Case_<4>) {
	timer_clear();
	string currentLanes_[] = {"I",
 "WANT",
 "TO",
 "DRINK",
 "SOME",
 "COFFEE"};
	  vector <string> currentLanes(currentLanes_, currentLanes_+sizeof(currentLanes_)/sizeof(*currentLanes_)); 
	int RetVal = 5; 
	return verify_case(RetVal, RoadConstruction().getExitTime(currentLanes)); }

template<int N> void Run_() { cerr << "Test Case #" << N << "..." << flush; Test_(Case_<N>()); Run_<sizeof(Test_(Case_<N+1>()))==1 ? -1 : N+1>(); }
template<>      void Run_<-1>() {}
int main() { Run_<0>(); }
// END CUT HERE

