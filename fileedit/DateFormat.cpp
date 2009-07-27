#line 2 "DateFormat.cpp"
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
/*
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<string> vs;
typedef vector<long long> vll;
#define pb  push_back
#define all(c)  (c).begin(),(c).end()
#define mset(arr,val)  memset(arr,val,sizeof(arr))
#define forr(var,from,to) for(int var=(from);var<=(to);var++) 
#define found(s,e)  ((s).find(e)!=(s).end())
#define remove_(c,val) (c).erase(remove((c).begin(),(c).end(),(val)),(c).end())
#define lastc(str) (*((str).end()-1))
*/
typedef vector<int> vi;
typedef vector<string> vs;
#define pb  push_back
#define tr(c,i)  for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); i++)
#define sz(a)  int((a).size())
#define rep(var,n)  for(int var=0;var<(n);var++)
#define all(c)  (c).begin(),(c).end()

vector<string> split(string str, int delim=' ')
{
  vector<string> result;

  const char *s = str.c_str();
  if (delim == ' ') {
    for (const char *p=s; *p; p++) {
      if (*p == delim) s++;
      else break;
    }
    if (!*s) return result;

    for (const char *p=s; *p; p++) {
      if (*p == delim) {
        if (s < p) {
          string a(s,p-s);
          result.push_back(a);
        }
        s = p + 1;
      }
    }
    if (*s) result.push_back(s);
  } else {
    for (const char *p=s; *p; p++) {
      if (*p == delim) {
        string a(s,p-s);
        result.push_back(a);
        s = p + 1;
        if (*s == '\0') result.push_back("");
      }
    }
    if (*s) result.push_back(s);
  }

  return result;
}

vector<int> map_atoi(vector<string> nums)
{
  vector<int> vals(nums.size());
  for (int i=nums.size()-1; i>=0; i--) vals[i] = atoi(nums[i].c_str());
  return vals;
}

string join(vector<string> strs, const string &delim="")
{
  int n=strs.size(); if (n==0) return "";
  stringstream ss;
  ss << strs[0];
  for(int i=1;i<n;i++) { ss << delim << strs[i]; }
  return ss.str();
}


class DateFormat {
 public:
  string fromEuropeanToUs(vector <string> dateList) {
	vs dates = split(join(dateList)); int n=sz(dates);
    //    cout << dates << endl;
    vs mins(n), maxs(n);
    vi ds; int lastd=0;
    rep(i,n){
      vi ns=map_atoi(split(dates[i],'/'));
      if(ns[0]<ns[1]){ // xX
        if (ns[1]<=12) { // mD, dM
          int d1=ns[0]*100 + ns[1], d2=ns[1]*100+ns[0];
          if(lastd < d1) { ds.pb(d1); lastd = d1; }
          else if(lastd < d2) { ds.pb(d2); lastd = d2; }
          else return "";
        } else { // mD
          int d=ns[0]*100 + ns[1];
          if(lastd<d) { ds.pb(d); lastd = d; }
          else return "";
        }
      }else if(ns[0]==ns[1]) { // md, <=12
        int d=ns[0]*101;
        if(lastd<d) { ds.pb(d); lastd = d; }
        else return "";
      }else{ //Xx
        if (ns[0]<=12) { // Md, Dm
          int d1=ns[1]*100 + ns[0], d2=ns[0]*100+ns[1];
          if(lastd < d1) { ds.pb(d1); lastd = d1; }
          else if(lastd < d2) { ds.pb(d2); lastd = d2; }
          else return "";
        } else { // Dm
          int d=ns[1]*100 + ns[0];
          if(lastd<d) { ds.pb(d); lastd = d; }
          else return "";
        }
      }
    }
    //cout << ds << endl;
    vs anss;
    rep(i,n){
      char buf[6]; sprintf(buf,"%02d/%02d",ds[i]/100,ds[i]%100);
      anss.pb(buf);
    }
    return join(anss," ");
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
	string dateList_[] = {"16/01"};
	  vector <string> dateList(dateList_, dateList_+sizeof(dateList_)/sizeof(*dateList_)); 
	string RetVal = "01/16"; 
	return verify_case(RetVal, DateFormat().fromEuropeanToUs(dateList)); }
int Test_(Case_<1>) {
	timer_clear();
	string dateList_[] = {"02/01 08/02 08/02 21/09 06/11"};
	  vector <string> dateList(dateList_, dateList_+sizeof(dateList_)/sizeof(*dateList_)); 
	string RetVal = "01/02 02/08 08/02 09/21 11/06"; 
	return verify_case(RetVal, DateFormat().fromEuropeanToUs(dateList)); }
int Test_(Case_<2>) {
	timer_clear();
	string dateList_[] = {"08/02 08/02 03/04"};
	  vector <string> dateList(dateList_, dateList_+sizeof(dateList_)/sizeof(*dateList_)); 
	string RetVal = ""; 
	return verify_case(RetVal, DateFormat().fromEuropeanToUs(dateList)); }
int Test_(Case_<3>) {
	timer_clear();
	string dateList_[] = {"2", "9/02", " 08/", "03 01/08"};
	  vector <string> dateList(dateList_, dateList_+sizeof(dateList_)/sizeof(*dateList_)); 
	string RetVal = "02/29 03/08 08/01"; 
	return verify_case(RetVal, DateFormat().fromEuropeanToUs(dateList)); }
int Test_(Case_<4>) {
	timer_clear();
	string dateList_[] = {"17/01 05/05 03/07 07/24 23/09 09/30 01/11 11/11"};
	  vector <string> dateList(dateList_, dateList_+sizeof(dateList_)/sizeof(*dateList_)); 
	string RetVal = "01/17 05/05 07/03 07/24 09/23 09/30 11/01 11/11"; 
	return verify_case(RetVal, DateFormat().fromEuropeanToUs(dateList)); }

template<int N> void Run_() { cerr << "Test Case #" << N << "..." << flush; Test_(Case_<N>()); Run_<sizeof(Test_(Case_<N+1>()))==1 ? -1 : N+1>(); }
template<>      void Run_<-1>() {}
int main() { Run_<0>(); }
// END CUT HERE


// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
In the US, dates are usually written starting with the month, but in Europe, they are usually written starting with the day. So, January 16 will be written as "01/16" in the US and as "16/01" in Europe.

You have a list of dates for the next year and it is known that the given dates are listed in strictly increasing order. Unfortunately, the list was populated by different people and it can contain dates in both formats. You want to convert all dates into the US format.

You will be given a string dateList. First, you should concatenate all elements of dateList and consider it as one string. The conjoint dateList will contain a space-separated list of the dates. Each date will be in the form "XX/XX" (quotes for clarity), where each X is a digit. 
Convert the dates (without changing the order of the list) so that each date is in the US format and the list is in strictly increasing order.
Note that in the original list, the format in which certain dates were written might be ambiguous.  You may interpret those dates as being in either format as long as the final list is in strictly increasing order. Return the result as a single string in the same format as the original.  If there are several solutions possible return one that comes first lexicographically. If it is impossible to obtain a strictly increasing list of dates, return an empty string.



DEFINITION
Class:DateFormat
Method:fromEuropeanToUs
Parameters:vector <string>
Returns:string
Method signature:string fromEuropeanToUs(vector <string> dateList)


NOTES
-Next year is 2008, a leap year. So, February 29 is a valid date. 


CONSTRAINTS
-dateList will contain between 1 and 50 elements, inclusive.
-Each element of dateList will contain between 1 and 50 characters, inclusive.
-The conjoint dateList will contain a single space separated list of dates without leading or trailing spaces. 
-Each date in dateList will be in the form "XX/XX" (quotes for clarity), where each X is a digit.
-Each date in dateList will represent a valid date in either US format or European format. 


EXAMPLES

0)
{"16/01"}

Returns: "01/16"

The example from the problem statement.

1)
{"02/01 08/02 08/02 21/09 06/11"}

Returns: "01/02 02/08 08/02 09/21 11/06"

The first date is either January 2 or February 1.
The second date is either February 8 or August 2.
The third date is either February 8 or August 2.
The fourth date is definitely September 21.
The fifth date is either June 11 or November 06.
There are two ways to interpret these dates in strictly increasing order: "01/02 02/08 08/02 09/21 11/06" and "02/01 02/08 08/02 09/21 11/06". The first variant comes earlier lexicographically.
 

2)
{"08/02 08/02 03/04"}

Returns: ""

3)
{"2", "9/02", " 08/", "03 01/08"}

Returns: "02/29 03/08 08/01"

4)
{"17/01 05/05 03/07 07/24 23/09 09/30 01/11 11/11"}

Returns: "01/17 05/05 07/03 07/24 09/23 09/30 11/01 11/11"

*/
// END CUT HERE
