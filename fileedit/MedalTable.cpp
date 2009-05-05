#line 2 "MedalTable.cpp"
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
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<string> vs;
#define sz(a)  int((a).size())
#define pb  push_back
#define all(c)  (c).begin(),(c).end()
#define tr(c,i)  for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); i++)
#define rep(var,n)  for(int var=0;var<(n);var++)
#define found(s,e)  ((s).find(e)!=(s).end())

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

class MedalTable {
 public:
  vector<string> generate(vector<string> results) {
    int rn=sz(results);
    map<string,int> m;
    rep(i,rn){
      vector<string> cs=split(results[i]);
      for(int j=0,mk=4096;j<3;j++,mk>>=6){
        string cnt=cs[j];
        if(found(m,cnt)){
          m[cnt]+=mk;
        }else{
          m[cnt]=mk;
        }
      }
    }
    vector<pair<int,string> > sc;
    tr(m,it){
      sc.pb(make_pair(-it->second,it->first));
      //cout << it->first << ": " << it->second << endl;
    }
    sort(all(sc));
    vector<string> ret;
    tr(sc,it){
      stringstream ss;
      ss << it->second << " ";
      int score=-it->first;
      ss << (score >> 12) << " " << ((score >> 6) & 63) << " " << (score & 63);
      ret.pb(ss.str());
    }
    return ret;
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
	string results_[] = {"ITA JPN AUS", "KOR TPE UKR", "KOR KOR GBR", "KOR CHN TPE"};
	  vector <string> results(results_, results_+sizeof(results_)/sizeof(*results_)); 
	string RetVal_[] = { "KOR 3 1 0",  "ITA 1 0 0",  "TPE 0 1 1",  "CHN 0 1 0",  "JPN 0 1 0",  "AUS 0 0 1",  "GBR 0 0 1",  "UKR 0 0 1" };
	  vector <string> RetVal(RetVal_, RetVal_+sizeof(RetVal_)/sizeof(*RetVal_)); 
	return verify_case(RetVal, MedalTable().generate(results)); }
int Test_(Case_<1>) {
	timer_clear();
	string results_[] = {"USA AUT ROM"};
	  vector <string> results(results_, results_+sizeof(results_)/sizeof(*results_)); 
	string RetVal_[] = { "USA 1 0 0",  "AUT 0 1 0",  "ROM 0 0 1" };
	  vector <string> RetVal(RetVal_, RetVal_+sizeof(RetVal_)/sizeof(*RetVal_)); 
	return verify_case(RetVal, MedalTable().generate(results)); }
int Test_(Case_<2>) {
	timer_clear();
	string results_[] = {"GER AUT SUI", "AUT SUI GER", "SUI GER AUT"};
	  vector <string> results(results_, results_+sizeof(results_)/sizeof(*results_)); 
	string RetVal_[] = { "AUT 1 1 1",  "GER 1 1 1",  "SUI 1 1 1" };
	  vector <string> RetVal(RetVal_, RetVal_+sizeof(RetVal_)/sizeof(*RetVal_)); 
	return verify_case(RetVal, MedalTable().generate(results)); }

template<int N> void Run_() { cerr << "Test Case #" << N << "..." << flush; Test_(Case_<N>()); Run_<sizeof(Test_(Case_<N+1>()))==1 ? -1 : N+1>(); }
template<>      void Run_<-1>() {}
int main() { Run_<0>(); }
// END CUT HERE


// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// The Olympic Games in Athens end tomorrow.
Given the results of the olympic disciplines, generate and return the medal table.

The results of the disciplines are given as a vector <string> results,
where each element is in the format "GGG SSS BBB". GGG, SSS and
BBB are the 3-letter country codes (three capital letters from 'A' to 'Z') of the countries winning
the gold, silver and bronze medal, respectively.

The medal table is a vector <string> with an element for each country appearing in results.
Each element has to be in the format "CCO G S B" (quotes for clarity), where
G, S and B are the number of gold, silver and bronze medals won
by country CCO, e.g. "AUT 1 4 1". The numbers should not have any extra leading zeros.

Sort the elements by the number of gold medals won in decreasing order.
If several countries are tied, sort the tied countries by the number of silver medals won in decreasing order.
If some countries are still tied, sort the tied countries by the number of bronze medals won in decreasing order.
If a tie still remains, sort the tied countries by their 3-letter code in ascending alphabetical order.


DEFINITION
Class:MedalTable
Method:generate
Parameters:vector <string>
Returns:vector <string>
Method signature:vector <string> generate(vector <string> results)


CONSTRAINTS
-results contains between 1 and 50 elements, inclusive.
-Each element of results is formatted as described in the problem statement.
-No more than 50 different countries appear in results.


EXAMPLES

0)
{"ITA JPN AUS", "KOR TPE UKR", "KOR KOR GBR", "KOR CHN TPE"}

Returns: { "KOR 3 1 0",  "ITA 1 0 0",  "TPE 0 1 1",  "CHN 0 1 0",  "JPN 0 1 0",  "AUS 0 0 1",  "GBR 0 0 1",  "UKR 0 0 1" }

These are the results of the archery competitions.

1)
{"USA AUT ROM"}

Returns: { "USA 1 0 0",  "AUT 0 1 0",  "ROM 0 0 1" }

2)
{"GER AUT SUI", "AUT SUI GER", "SUI GER AUT"}

Returns: { "AUT 1 1 1",  "GER 1 1 1",  "SUI 1 1 1" }

*/
// END CUT HERE
