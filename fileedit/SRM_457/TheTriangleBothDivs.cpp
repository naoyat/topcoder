#line 2 "TheTriangleBothDivs.cpp"
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
#define rep(var,n)  for(int var=0;var<(n);var++)
//215.87
class TheTriangleBothDivs {
  string disp;
  
 public:
  string tostr(int m){
    char buf[6];
    sprintf(buf, "%02d:%02d", m/60, m%60);
    return buf;
  }
  bool possible(string s){
    rep(i,11){
      if(disp[i]=='?') continue;
      if(disp[i]!=s[i]) return false;
    }
    return true;
  }
  
  string fix(string time) {
    disp = time;

    char buf[12];
    priority_queue<int> pq;
    for(int z=-9;z<=9;z++){
      for(int h=0;h<24;h++){
        for(int m=0;m<60;m++){
          sprintf(buf,"%02d:%02d GMT%c%d",h,m, z>=0?'+':'-', abs(z));
          if (possible(buf)) {
            int t=((h-z)*60 + m + 1440)%1440;
            pq.push(-t);
          }
        }
      }
    }

    return tostr(-pq.top());
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
	string time = "17:45 GMT-4"; 
	string RetVal = "21:45"; 
	return verify_case(RetVal, TheTriangleBothDivs().fix(time)); }
int Test_(Case_<1>) {
	timer_clear();
	string time = "16:?? GMT??"; 
	string RetVal = "00:00"; 
	return verify_case(RetVal, TheTriangleBothDivs().fix(time)); }
int Test_(Case_<2>) {
	timer_clear();
	string time = "?1:34 GMT-9"; 
	string RetVal = "06:34"; 
	return verify_case(RetVal, TheTriangleBothDivs().fix(time)); }
int Test_(Case_<3>) {
	timer_clear();
	string time = "??:?? GMT??"; 
	string RetVal = "00:00"; 
	return verify_case(RetVal, TheTriangleBothDivs().fix(time)); }

template<int N> void Run_() { cerr << "Test Case #" << N << "..." << flush; Test_(Case_<N>()); Run_<sizeof(Test_(Case_<N+1>()))==1 ? -1 : N+1>(); }
template<>      void Run_<-1>() {}
int main() { Run_<0>(); }
// END CUT HERE


// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// John and Brus have always been confused by time zones.  Their recent promotions to Concorde pilot and copilot do not help.  Having to constantly fly through the Bermuda Triangle does not help either.  They have therefore purchased a special digital clock that displays the current time in one of 19 time zones, from GMT-9 to GMT+9.  The clock displays time in the format "HH:mm GMTof" (quotes for clarity), where HH is the hour of the day (between 00 and 23, inclusive), mm is the number of minutes since the start of the hour (between 00 and 59, inclusive), and of is the offset from "Greenwich Mean Time" (time zone GMT+0) to the current time zone.  If the offset is +4, for example, it means the displayed time is 4 hours ahead of the time in GMT+0, and if the offset is -4, it means the time is 4 hours behind the time in GMT+0.  GMT+0 will always be displayed with an offset of +0, so the clock will never display it as GMT-0.

In the middle of a flight, John wanted to know what time it was, so he asked Brus to check the clock.  To Brus' surprise, the Bermuda Triangle had caused the clock to malfunction, and some of the characters on the display were unrecognizable.  You are given the clock's display as a string time, where '?' characters represent the unrecognizable characters.  Assuming that all the recognizable characters are accurate, determine what time it is in time zone GMT+0.  Return this time formatted as "HH:mm" (quotes for clarity).  If there are multiple possible answers, return the one that comes earliest lexicographically.  The constraints ensure that at least one result is always possible.

DEFINITION
Class:TheTriangleBothDivs
Method:fix
Parameters:string
Returns:string
Method signature:string fix(string time)


NOTES
-string s1 comes before string s2 lexicographically if s1 has a lexicographically smaller character at the first index where they differ.


CONSTRAINTS
-time will contain exactly 11 characters.
-time will be formatted "xx:xx GMTsx" (quotes for clarity).
-Each x in time will be a digit ('0'-'9') or '?'.
-The s in time will be '-','+' or '?'.
-time will represent a valid clock display (as described in the statement) where zero or more of the digits or the '-' or '+' sign have been replaced by '?' characters.


EXAMPLES

0)
"17:45 GMT-4"

Returns: "21:45"



1)
"16:?? GMT??"

Returns: "00:00"

There are many possible times the clock could be displaying, for example: "16:00 GMT+8", "16:35 GMT-9", etc.
It is possible to choose "00" minutes and the GMT-8 time zone to yield time "00:00" which is the lexicographically first result.

2)
"?1:34 GMT-9"

Returns: "06:34"



3)
"??:?? GMT??"

Returns: "00:00"



*/
// END CUT HERE
