#line 2 "TallPeople.cpp"
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
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<string> vs;
typedef vector<long long> vll;
#define sz(a)  int((a).size())
#define pb  push_back
#define all(c)  (c).begin(),(c).end()
#define tr(c,i)  for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); i++)
#define rep(var,n)  for(int var=0;var<(n);var++)

vector<string> split(string str, int delim=' ')
{
  vector<string> result;

  const char *s = str.c_str();
  if (delim == ' ') {
    for (const char *p=s; *p; p++) {
      if (*p == delim)
        s++;
      else
        break;
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

class TallPeople {
 public:
  vector<int> getPeople(vector<string> people) {
    int rows=sz(people),cols=0;
    vector<vector<int> > nums(rows);
    rep(row,rows){
      nums[row] = map_atoi(split(people[row]));
      cols=sz(nums[row]);
      //      cout << nums << endl;
    }
    int ts=0;
    rep(r,rows){
      vector<int> row(all(nums[r]));
      sort(all(row));
      int s=row[0]; if(s>ts) ts=s;
    }
    int st=INT_MAX;
    rep(c,cols){
      vector<int> col(rows);
      rep(r,rows) col[r]=nums[r][c];
      sort(all(col));
      int t=col[rows-1]; if(t<st) st=t;
    }
    vector<int> ret(2);
    ret[0]=ts, ret[1]=st;
    //cout << ret << endl;
    return ret;
  }
};

// BEGIN CUT HERE
#include <time.h>
clock_t start_time;
void timer_clear() { start_time = clock(); }
string timer() { clock_t end_time = clock(); double interval = (double)(end_time - start_time)/CLOCKS_PER_SEC; ostringstream os; os << " (" << interval*1000 << " msec)"; return os.str(); }

template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
int verify_case(const vector <int> &Expected, const vector <int> &Received) { if (Expected == Received) cerr << "PASSED" << timer() << endl; else { cerr << "FAILED" << timer() << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } return 0;}

template<int N> struct Case_ {};
char Test_(...);
int Test_(Case_<0>) {
	timer_clear();
	string people_[] = {"9 2 3",
 "4 8 7"};
	  vector <string> people(people_, people_+sizeof(people_)/sizeof(*people_)); 
	int RetVal_[] = { 4,  7 };
	  vector <int> RetVal(RetVal_, RetVal_+sizeof(RetVal_)/sizeof(*RetVal_)); 
	return verify_case(RetVal, TallPeople().getPeople(people)); }
int Test_(Case_<1>) {
	timer_clear();
	string people_[] = {"1 2",
 "4 5",
 "3 6"};
	  vector <string> people(people_, people_+sizeof(people_)/sizeof(*people_)); 
	int RetVal_[] = { 4,  4 };
	  vector <int> RetVal(RetVal_, RetVal_+sizeof(RetVal_)/sizeof(*RetVal_)); 
	return verify_case(RetVal, TallPeople().getPeople(people)); }
int Test_(Case_<2>) {
	timer_clear();
	string people_[] = {"1 1",
 "1 1"};
	  vector <string> people(people_, people_+sizeof(people_)/sizeof(*people_)); 
	int RetVal_[] = { 1,  1 };
	  vector <int> RetVal(RetVal_, RetVal_+sizeof(RetVal_)/sizeof(*RetVal_)); 
	return verify_case(RetVal, TallPeople().getPeople(people)); }

template<int N> void Run_() { cerr << "Test Case #" << N << "..." << flush; Test_(Case_<N>()); Run_<sizeof(Test_(Case_<N+1>()))==1 ? -1 : N+1>(); }
template<>      void Run_<-1>() {}
int main() { Run_<0>(); }
// END CUT HERE


// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// A group of people stand before you arranged in rows and columns.  Looking from above, they form an R by C rectangle of people.  You will be given a vector <string> people containing the height of each person.  Elements of people correspond to rows in the rectangle.  Each element contains a space-delimited list of integers representing the heights of the people in that row.  Your job is to return 2 specific heights in a vector <int>.  The first is computed by finding the shortest person in each row, and then finding the tallest person among them (the "tallest-of-the-shortest").  The second is computed by finding the tallest person in each column, and then finding the shortest person among them (the "shortest-of-the-tallest").

DEFINITION
Class:TallPeople
Method:getPeople
Parameters:vector <string>
Returns:vector <int>
Method signature:vector <int> getPeople(vector <string> people)


CONSTRAINTS
-people will contain between 2 and 50 elements inclusive.
-Each element of people will contain between 3 and 50 characters inclusive.
-Each element of people will be a single space-delimited list of positive integers such that: 1) Each positive integer is between 1 and 1000 inclusive with no extra leading zeros.2) Each element contains the same number of integers.3) Each element contains at least 2 positive integers.4) Each element does not contain leading or trailing whitespace.


EXAMPLES

0)
{"9 2 3",
 "4 8 7"}

Returns: { 4,  7 }

The heights 2 and 4 are the shortest from the rows, so 4 is the taller of the two.  The heights 9, 8, and 7 are the tallest from the columns, so 7 is the shortest of the 3.

1)
{"1 2",
 "4 5",
 "3 6"}

Returns: { 4,  4 }

2)
{"1 1",
 "1 1"}

Returns: { 1,  1 }

*/
// END CUT HERE
