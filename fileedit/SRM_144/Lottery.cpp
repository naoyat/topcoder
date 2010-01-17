#line 2 "Lottery.cpp"
//SRM 144 DIV1  - 550pt 345.29
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
#define FOR(var,from,to) for(int var=(from);var<=(to);var++)
#define RFOR(var,from,to) for(int var=(to);var>=(from);var--)
#define found(s,e)  ((s).find(e)!=(s).end())
#define mset(arr,val)  memset(arr,val,sizeof(arr))
#define remove_(c,val) (c).erase(remove((c).begin(),(c).end(),(val)),(c).end())
#define lastc(str) (*((str).end()-1))

typedef pair<int,int> i_i;
typedef pair<ll,ll> ll_ll;
typedef pair<double,double> d_d;
typedef pair<int,pair<int,int> > i_ii;
#define cons(x,y) make_pair((x),(y))
#define car(x) ((x).first)
#define cdr(x) ((x).second)
#define cadr(x) (x).second.first
#define cddr(x) (x).second.second

vector<string> split(string str, string delim)
{
  vector<string> result;

  if (str.length() == 0) return result;

  if (delim.length() == 0) {
    int len = str.length();
    result.resize(len);
    for (int i=0; i<len; i++) result[i] = str.substr(i,1);
    return result;
  }

  int since = 0, at;
  while ((at = str.find(delim, since)) != string::npos) {
    result.push_back(str.substr(since, at-since));
    since = at + delim.length();
  }
  result.push_back(str.substr(since));

  return result;
}
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

bool atob(string s){ return s[0]=='T'; }

ll pow(int x,int y){ // x^y
  ll ans=1LL; rep(i,y) ans *= (ll)x; return ans;
}
ll fac(int x,int y){ // x!/(x-y)!
  ll ans=1LL; rep(i,y) ans *= (ll)(x--); return ans;
}
class Lottery {
  map<i_i,ll> m1, m2;
  ll sub_sorted_unique(int choices,int blanks){ // 1 2 3 ...
    if (blanks==0) return 1;
    i_i key=cons(choices,blanks);
    if(found(m1,key)) return m1[key];
    ll sum=0LL;
    rep(i,choices){
      sum += sub_sorted_unique(choices-i-1,blanks-1);
    }
    m1[key]=sum;
    return sum;
  }
  ll sub_sorted(int choices,int blanks){ // 1 1 2 ...
    if (blanks==0) return 1;
    i_i key=cons(choices,blanks);
    if(found(m2,key)) return m2[key];
    ll sum=0LL;
    rep(i,choices){
      sum += sub_sorted(choices-i,blanks-1);
    }
    m2[key]=sum;
    return sum;
  }
  ll num(string name, int choices, int blanks, bool sorted, bool unique) {
    // number of valid lottery tickets for that game...
    // choices: 10-100 ... [1..choices]
    // blanks: 1-8
    ll cnt = 0LL;

    if (sorted) {
      if (unique) {
        // 1 2 3 4 5
        cnt = sub_sorted_unique(choices,blanks);
      } else {
        // 1 1 2 3 3
        cnt = sub_sorted(choices,blanks);
      }
    } else {
      if (unique) {
        // 3 2 1 5 4
        cnt = fac(choices,blanks);
      } else {
        // 3 3 1 2 1
        cnt = pow(choices,blanks); // 1e2 ^ 8 = 1e16
      }
    }
   
    printf("name:%s choices:%d blanks:%d sorted:%s unique:%s => %lld\n",
           name.c_str(), choices, blanks, sorted?"YES":"NO", unique?"YES":"NO",
           cnt);
    return cnt;
  }
 public:
  vector <string> sortByOdds(vector<string> rules) {
    m1.clear(); m2.clear();
    
    vector<pair<ll,string> > res;
    tr(rules,st){
      vs a1 = split(*st,": ");
      string name = a1[0];
      vs a2 = split(a1[1],' ');
      int choices = atoi(a2[0].c_str()), blanks = atoi(a2[1].c_str());
      bool sorted = atob(a2[2]), unique = atob(a2[3]);

      res.pb(cons(num(name,choices,blanks,sorted,unique),name));
    }
    sort(all(res));// reverse(all(res));
    vs ans;
    tr(res,it) ans.pb(it->second);
    return ans;
  }
};

// BEGIN CUT HERE
#include <time.h>
clock_t start_time;
void timer_clear() { start_time = clock(); }
string timer() { clock_t end_time = clock(); double interval = (double)(end_time - start_time)/CLOCKS_PER_SEC; ostringstream os; os << " (" << interval*1000 << " msec)"; return os.str(); }

template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
int verify_case(const vector <string> &Expected, const vector <string> &Received) { if (Expected == Received) cerr << "PASSED" << timer() << endl; else { cerr << "FAILED" << timer() << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } return 0;}

template<int N> struct Case_ {};
char Test_(...);
int Test_(Case_<0>) {
	timer_clear();
	string rules_[] = {"PICK ANY TWO: 10 2 F F"
,"PICK TWO IN ORDER: 10 2 T F"
,"PICK TWO DIFFERENT: 10 2 F T"
,"PICK TWO LIMITED: 10 2 T T"};
	  vector <string> rules(rules_, rules_+sizeof(rules_)/sizeof(*rules_)); 
	string RetVal_[] = { "PICK TWO LIMITED",  "PICK TWO IN ORDER",  "PICK TWO DIFFERENT",  "PICK ANY TWO" };
	  vector <string> RetVal(RetVal_, RetVal_+sizeof(RetVal_)/sizeof(*RetVal_)); 
	return verify_case(RetVal, Lottery().sortByOdds(rules)); }
int Test_(Case_<1>) {
	timer_clear();
	string rules_[] = {"INDIGO: 93 8 T F",
 "ORANGE: 29 8 F T",
 "VIOLET: 76 6 F F",
 "BLUE: 100 8 T T",
 "RED: 99 8 T T",
 "GREEN: 78 6 F T",
 "YELLOW: 75 6 F F"}
;
	  vector <string> rules(rules_, rules_+sizeof(rules_)/sizeof(*rules_)); 
	string RetVal_[] = { "RED",  "ORANGE",  "YELLOW",  "GREEN",  "BLUE",  "INDIGO",  "VIOLET" };
	  vector <string> RetVal(RetVal_, RetVal_+sizeof(RetVal_)/sizeof(*RetVal_)); 
	return verify_case(RetVal, Lottery().sortByOdds(rules)); }
int Test_(Case_<2>) {
	timer_clear();
	vector <string> rules; 
	vector <string> RetVal; 
	return verify_case(RetVal, Lottery().sortByOdds(rules)); }

template<int N> void Run_() { cerr << "Test Case #" << N << "..." << flush; Test_(Case_<N>()); Run_<sizeof(Test_(Case_<N+1>()))==1 ? -1 : N+1>(); }
template<>      void Run_<-1>() {}
int main() { Run_<0>(); }
// END CUT HERE


// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// In most states, gamblers can choose from a wide variety of different lottery games.  The rules of a lottery are defined by two integers (choices and blanks) and two boolean variables (sorted and unique).  choices represents the highest valid number that you may use on your lottery ticket.  (All integers between 1 and choices, inclusive, are valid and can appear on your ticket.)  blanks represents the number of spots on your ticket where numbers can be written.

The sorted and unique variables indicate restrictions on the tickets you can create.  If sorted is set to true, then the numbers on your ticket must be written in non-descending order.  If sorted is set to false, then the numbers may be written in any order.  Likewise, if unique is set to true, then each number you write on your ticket must be distinct.  If unique is set to false, then repeats are allowed.

Here are some example lottery tickets, where choices = 15 and blanks = 4:
{3, 7, 12, 14} -- this ticket is unconditionally valid.
{13, 4, 1, 9} -- because the numbers are not in nondescending order, this ticket is valid only if sorted = false.
{8, 8, 8, 15} -- because there are repeated numbers, this ticket is valid only if unique = false.
{11, 6, 2, 6} -- this ticket is valid only if sorted = false and unique = false.

Given a list of lotteries and their corresponding rules, return a list of lottery names sorted by how easy they are to win.  The probability that you will win a lottery is equal to (1 / (number of valid lottery tickets for that game)).  The easiest lottery to win should appear at the front of the list.  Ties should be broken alphabetically (see example 1).

DEFINITION
Class:Lottery
Method:sortByOdds
Parameters:vector <string>
Returns:vector <string>
Method signature:vector <string> sortByOdds(vector <string> rules)


CONSTRAINTS
-rules will contain between 0 and 50 elements, inclusive.
-Each element of rules will contain between 11 and 50 characters, inclusive.
-Each element of rules will be in the format "<NAME>:_<CHOICES>_<BLANKS>_<SORTED>_<UNIQUE>" (quotes for clarity). The underscore character represents exactly one space. The string will have no leading or trailing spaces.
-<NAME> will contain between 1 and 40 characters, inclusive, and will consist of only uppercase letters ('A'-'Z') and spaces (' '), with no leading or trailing spaces.
-<CHOICES> will be an integer between 10 and 100, inclusive, with no leading zeroes.
-<BLANKS> will be an integer between 1 and 8, inclusive, with no leading zeroes.
-<SORTED> will be either 'T' (true) or 'F' (false).
-<UNIQUE> will be either 'T' (true) or 'F' (false).
-No two elements in rules will have the same name.


EXAMPLES

0)
{"PICK ANY TWO: 10 2 F F"
,"PICK TWO IN ORDER: 10 2 T F"
,"PICK TWO DIFFERENT: 10 2 F T"
,"PICK TWO LIMITED: 10 2 T T"}

Returns: { "PICK TWO LIMITED",  "PICK TWO IN ORDER",  "PICK TWO DIFFERENT",  "PICK ANY TWO" }

The "PICK ANY TWO" game lets either blank be a number from 1 to 10.  Therefore, there are 10 * 10 = 100 possible tickets, and your odds of winning are 1/100.

The "PICK TWO IN ORDER" game means that the first number cannot be greater than the second number.  This eliminates 45 possible tickets, leaving us with 55 valid ones.  The odds of winning are 1/55.

The "PICK TWO DIFFERENT" game only disallows tickets where the first and second numbers are the same.  There are 10 such tickets, leaving the odds of winning at 1/90.

Finally, the "PICK TWO LIMITED" game disallows an additional 10 tickets from the 45 disallowed in "PICK TWO IN ORDER".  The odds of winning this game are 1/45.

1)
{"INDIGO: 93 8 T F",
 "ORANGE: 29 8 F T",
 "VIOLET: 76 6 F F",
 "BLUE: 100 8 T T",
 "RED: 99 8 T T",
 "GREEN: 78 6 F T",
 "YELLOW: 75 6 F F"}


Returns: { "RED",  "ORANGE",  "YELLOW",  "GREEN",  "BLUE",  "INDIGO",  "VIOLET" }

Note that INDIGO and BLUE both have the exact same odds (1/186087894300).  BLUE is listed first because it comes before INDIGO alphabetically.

2)
{}

Returns: { }

Empty case

*/
// END CUT HERE
