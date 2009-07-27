#line 2 "Cafeteria.cpp"
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
#define rep(var,n)  for(int var=0;var<(n);var++)

class Cafeteria {
  string twelve(int min){
    int h=min/60, m=min%60;
    if (h>12) h-=12;
    char buf[6];
    sprintf(buf,"%02d:%02d",h,m);
    return buf;
  }
 public:
  string latestTime(vector <int> offset, vector <int> walkingTime, vector <int> drivingTime) {
	int n=sz(offset);
    int lim=60*14+30;
    int latest=0;
    rep(i,n){
      int o=offset[i],// 0-9
          wt=walkingTime[i],//1-30
          dt=drivingTime[i];//1-300
      int lastdep=lim-dt, lastdepo=lastdep%10, lastdep0 = lastdep-lastdepo;
      int busdep= (o<=lastdepo)? (lastdep0+o) : (lastdep0-10+o);
      int dep=busdep-wt;
// BEGIN CUT HERE
      //printf("%d,%d,%d // o:%d wt:%d dt:%d // busdep:%d,dep:%d\n", lastdep,lastdepo,lastdep0, o,wt,dt, busdep,dep);
// END CUT HERE
      latest >?= dep;
    }
    return twelve(latest);
  }
};

// BEGIN CUT HERE
#include <time.h>
clock_t start_time;
void timer_clear() { start_time = clock(); }
string timer() { clock_t end_time = clock(); double interval = (double)(end_time - start_time)/CLOCKS_PER_SEC; ostringstream os; os << " (" << interval*1000 << " msec)"; return os.str(); }

template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
int verify_case(const string &Expected, const string &Received) { if (Expected == Received) cerr << "PASSED" << timer() << endl; else { cerr << "FAILED" << timer() << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } return 0;}

template<int N> struct Case_ {};
char Test_(...);
int Test_(Case_<0>) {
	timer_clear();
	int offset_[] = {9};
	  vector <int> offset(offset_, offset_+sizeof(offset_)/sizeof(*offset_)); 
	int walkingTime_[] = {1};
	  vector <int> walkingTime(walkingTime_, walkingTime_+sizeof(walkingTime_)/sizeof(*walkingTime_)); 
	int drivingTime_[] = {1};
	  vector <int> drivingTime(drivingTime_, drivingTime_+sizeof(drivingTime_)/sizeof(*drivingTime_)); 
	string RetVal = "02:28"; 
	return verify_case(RetVal, Cafeteria().latestTime(offset, walkingTime, drivingTime)); }
int Test_(Case_<1>) {
	timer_clear();
	int offset_[] = {6};
	  vector <int> offset(offset_, offset_+sizeof(offset_)/sizeof(*offset_)); 
	int walkingTime_[] = {9};
	  vector <int> walkingTime(walkingTime_, walkingTime_+sizeof(walkingTime_)/sizeof(*walkingTime_)); 
	int drivingTime_[] = {120};
	  vector <int> drivingTime(drivingTime_, drivingTime_+sizeof(drivingTime_)/sizeof(*drivingTime_)); 
	string RetVal = "12:17"; 
	return verify_case(RetVal, Cafeteria().latestTime(offset, walkingTime, drivingTime)); }
int Test_(Case_<2>) {
	timer_clear();
	int offset_[] = {6,9};
	  vector <int> offset(offset_, offset_+sizeof(offset_)/sizeof(*offset_)); 
	int walkingTime_[] = {9,10};
	  vector <int> walkingTime(walkingTime_, walkingTime_+sizeof(walkingTime_)/sizeof(*walkingTime_)); 
	int drivingTime_[] = {120,121};
	  vector <int> drivingTime(drivingTime_, drivingTime_+sizeof(drivingTime_)/sizeof(*drivingTime_)); 
	string RetVal = "12:19"; 
	return verify_case(RetVal, Cafeteria().latestTime(offset, walkingTime, drivingTime)); }
int Test_(Case_<3>) {
	timer_clear();
	int offset_[] = {0,1,2,3,4,5,6,7,8,9};
	  vector <int> offset(offset_, offset_+sizeof(offset_)/sizeof(*offset_)); 
	int walkingTime_[] = {11,11,11,11,11,11,11,11,11,11};
	  vector <int> walkingTime(walkingTime_, walkingTime_+sizeof(walkingTime_)/sizeof(*walkingTime_)); 
	int drivingTime_[] = {190,190,190,190,190,190,190,190,190,190};
	  vector <int> drivingTime(drivingTime_, drivingTime_+sizeof(drivingTime_)/sizeof(*drivingTime_)); 
	string RetVal = "11:09"; 
	return verify_case(RetVal, Cafeteria().latestTime(offset, walkingTime, drivingTime)); }
int Test_(Case_<4>) {
	timer_clear();
	int offset_[] = {7,4,0,0,2,1,6,7,7,0,8,6,0,5,0,6,7,9,0,2,4,8,4,7,
9,2,4,4,3,1,4,5,8,8,2,5,7,8,7,5,6,8,8,0,1,3,5,0,8};
	  vector <int> offset(offset_, offset_+sizeof(offset_)/sizeof(*offset_)); 
	int walkingTime_[] = {26,14,1,4,16,28,16,6,4,5,21,18,5,2,21,21,28,22,5,22,26,16,14,
19,19,19,4,12,24,4,30,16,28,20,25,2,30,18,4,6,9,22,8,3,7,29,8,30,6};
	  vector <int> walkingTime(walkingTime_, walkingTime_+sizeof(walkingTime_)/sizeof(*walkingTime_)); 
	int drivingTime_[] = {151,264,280,89,63,57,15,120,28,296,76,269,90,106,31,222,
291,52,102,73,140,248,44,187,76,49,296,106,54,119,54,283,263,
285,275,127,108,82,84,241,169,203,244,256,109,288,9,262,103};
	  vector <int> drivingTime(drivingTime_, drivingTime_+sizeof(drivingTime_)/sizeof(*drivingTime_)); 
	string RetVal = "02:07"; 
	return verify_case(RetVal, Cafeteria().latestTime(offset, walkingTime, drivingTime)); }

template<int N> void Run_() { cerr << "Test Case #" << N << "..." << flush; Test_(Case_<N>()); Run_<sizeof(Test_(Case_<N+1>()))==1 ? -1 : N+1>(); }
template<>      void Run_<-1>() {}
int main() { Run_<0>(); }
// END CUT HERE


// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// During the week, the cafeteria of my university is open until 2:30 PM. Normally, I will be at the university before this time anyway. Since I am a lazy person, I don't want to cook for myself and prefer eating in the cafeteria. But sometimes I don't have any classes in the morning, so I have to make sure to get to the university before the cafeteria closes.
There are several bus stops within walking distance of my home and each one has a bus connection to the university. For each bus stop, there will be a bus driving to the university every ten minutes, so I just need to remember the number of minutes after a full hour when the first bus departs from each stop, how long it takes to get to the bus stop and how long the bus needs to drive to the university.
Given a vector <int> offset (the number of minutes after a full hour when the first bus departs),
vector <int> walkingTime (the number of minutes I need to walk to a bus stop)
and a vector <int> drivingTime (the number of minutes the bus needs to drive to the university) you should write a method that returns the latest time when I have to leave my house in order to be at the university at 2:30 PM or before. The ith element of offset, walkingTime and drivingTime refers to the ith bus stop.
The format of the returned time should be HH:MM (HH the hour, MM the minute). The 12 hour time format is used (see examples).

DEFINITION
Class:Cafeteria
Method:latestTime
Parameters:vector <int>, vector <int>, vector <int>
Returns:string
Method signature:string latestTime(vector <int> offset, vector <int> walkingTime, vector <int> drivingTime)


NOTES
-Times between noon and 1 PM should be written as 12:MM (where MM is the number of minutes after noon).


CONSTRAINTS
-offset, walkingTime and drivingTime contain the same number of elements.
-offset, walkingTime and drivingTime contain between 1 and 50 elements, inclusive.
-Each element of offset is between 0 and 9, inclusive.
-Each element of walkingTime is between 1 and 30, inclusive.
-Each element of drivingTime is between 1 and 300, inclusive.


EXAMPLES

0)
{9}
{1}
{1}

Returns: "02:28"

There is only one bus stop. One bus departs at 2:29 and arrives at 2:30. Since the time to walk to the bus stop is 1 minute, the return value is 02:28.

1)
{6}
{9}
{120}

Returns: "12:17"

Leaving the house at 12:17 lets me catch the bus at 12:26 which arrives at 2:26 at the university. Note that the bus departing at 12:36 would arrive too late.

2)
{6,9}
{9,10}
{120,121}

Returns: "12:19"

Although the bus needs one minute more from the 2nd bus stop, and the walking time is also one minute longer, it is still better to leave the house at 12:19 and catch the bus at the 2nd bus stop at 12:29.

3)
{0,1,2,3,4,5,6,7,8,9}
{11,11,11,11,11,11,11,11,11,11}
{190,190,190,190,190,190,190,190,190,190}

Returns: "11:09"

This simulates a bus departing every minute.

4)
{7,4,0,0,2,1,6,7,7,0,8,6,0,5,0,6,7,9,0,2,4,8,4,7,
9,2,4,4,3,1,4,5,8,8,2,5,7,8,7,5,6,8,8,0,1,3,5,0,8}
{26,14,1,4,16,28,16,6,4,5,21,18,5,2,21,21,28,22,5,22,26,16,14,
19,19,19,4,12,24,4,30,16,28,20,25,2,30,18,4,6,9,22,8,3,7,29,8,30,6}
{151,264,280,89,63,57,15,120,28,296,76,269,90,106,31,222,
291,52,102,73,140,248,44,187,76,49,296,106,54,119,54,283,263,
285,275,127,108,82,84,241,169,203,244,256,109,288,9,262,103}

Returns: "02:07"

*/
// END CUT HERE
