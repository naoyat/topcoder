#line 2 "HexatridecimalSum.cpp"
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
#define mset(arr,val)  memset(arr,val,sizeof(arr))
#define tr(c,i)  for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); i++)
#define rep(var,n)  for(int var=0;var<(n);var++)
#define forr(var,from,to) for(int var=(from);var<=(to);var++) 
#define found(s,e)  ((s).find(e)!=(s).end())
#define remove_(c,val) (c).erase(remove((c).begin(),(c).end(),(val)),(c).end())
#define lastc(str) (*((str).end()-1))

class HexatridecimalSum {
  int de(int c){
    if('0'<=c && c<='9') return c-'0';
    else return 10+(c-'A');
  }
  int en(int c){
    if (c<10) return '0'+c;
    else return 'A'+(c-10);
  }
 public:
  string maximizeSum(vector<string> numbers, int k) {
    vvi m(52);
    rep(i,52) m[i].resize(0);

    tr(numbers,it){
      string ns=*it;
      int l=sz(ns);
      rep(i,l) m[i].pb(de(ns[l-i-1]));
    }
    int maxk = 0;
    rep(i,52){
      if(sz(m[i])>0) maxk=i;
      sort(all(m[i]));
    }

    vvi di(36),id(36);
    rep(i,36) {
      di[i].resize(maxk+3);
      id[i].resize(maxk+3);
      rep(j,maxk+3) di[i][j] = id[i][j] = 0;
    }

    vi sum(maxk+3,0);
    for(int i=maxk;i>=0;i--){
      tr(m[i],it) {
        int c = *it;
        di[c][i] += (35-c);
        sum[maxk+2-i] += c;
      }
    }
    rep(c,36) {
      rep(i,maxk+2){
        if(di[c][i] >= 36) {
          di[c][i+1] += di[c][i]/36;
          di[c][i] %= 36;
        }
      }
    }
    rep(c,36){
      rep(i,maxk+3){
        id[c][maxk+2-i] = di[c][i];
      }
    }
    sort(all(id)); reverse(all(id));
    rep(i,k){
      rep(j,maxk+3){
        sum[j] += id[i][j];
      }
    }
    for(int i=maxk+2;i>0;i--){
      if(sum[i] >= 36) {
        sum[i-1] += sum[i]/36;
        sum[i] %= 36;
      }
    }
    bool left=true;
    stringstream ss;
    rep(i,maxk+3){
      if (left && sum[i]==0) continue;
      left=false;
      ss << (char)en(sum[i]);
    }
    return ss.str();
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
	string numbers_[] = {"HELLO"};
	  vector <string> numbers(numbers_, numbers_+sizeof(numbers_)/sizeof(*numbers_)); 
	int k = 2; 
	string RetVal = "ZZLLO"; 
	return verify_case(RetVal, HexatridecimalSum().maximizeSum(numbers, k)); }
int Test_(Case_<1>) {
	timer_clear();
	string numbers_[] = {"500", "POINTS", "FOR", "THIS", "PROBLEM"};
	  vector <string> numbers(numbers_, numbers_+sizeof(numbers_)/sizeof(*numbers_)); 
	int k = 5; 
	string RetVal = "1100TC85"; 
	return verify_case(RetVal, HexatridecimalSum().maximizeSum(numbers, k)); }
int Test_(Case_<2>) {
	timer_clear();
	string numbers_[] = {"TO", "BE", "OR", "NOT", "TO", "BE"};
	  vector <string> numbers(numbers_, numbers_+sizeof(numbers_)/sizeof(*numbers_)); 
	int k = 0; 
	string RetVal = "QNO"; 
	return verify_case(RetVal, HexatridecimalSum().maximizeSum(numbers, k)); }
int Test_(Case_<3>) {
	timer_clear();
	string numbers_[] = {"KEQUALS36"};
	  vector <string> numbers(numbers_, numbers_+sizeof(numbers_)/sizeof(*numbers_)); 
	int k = 36; 
	string RetVal = "ZZZZZZZZZ"; 
	return verify_case(RetVal, HexatridecimalSum().maximizeSum(numbers, k)); }
int Test_(Case_<4>) {
	timer_clear();
	string numbers_[] = {"GOOD", "LUCK", "AND", "HAVE", "FUN"};
	  vector <string> numbers(numbers_, numbers_+sizeof(numbers_)/sizeof(*numbers_)); 
	int k = 7; 
	string RetVal = "31YUB"; 
	return verify_case(RetVal, HexatridecimalSum().maximizeSum(numbers, k)); }

template<int N> void Run_() { cerr << "Test Case #" << N << "..." << flush; Test_(Case_<N>()); Run_<sizeof(Test_(Case_<N+1>()))==1 ? -1 : N+1>(); }
template<>      void Run_<-1>() {}
int main() { Run_<0>(); }
// END CUT HERE


// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// Hexatridecimal notation is base 36 notation.  The digits are '0' to '9' (with values 0 to 9) and 'A' to 'Z' (with values 10 to 35).

You are given a vector <string> numbers, where each element represents a positive integer in hexatridecimal notation.  You must select exactly k digits (from the set of all digits - '0' to '9' and 'A' to 'Z') and replace all of their occurrences in all of the numbers with 'Z'.  Then, calculate the sum of all the numbers.

Return the maximal possible sum you can get.  The return value must be in hexatridecimal format with no leading zeroes.

DEFINITION
Class:HexatridecimalSum
Method:maximizeSum
Parameters:vector <string>, int
Returns:string
Method signature:string maximizeSum(vector <string> numbers, int k)


CONSTRAINTS
-numbers will contain between 1 and 50 elements, inclusive.
-Each element of numbers will contain between 1 and 50 characters, inclusive.
-Each element of numbers will contain only characters '0' to '9' and 'A' to 'Z'.
-Each element of numbers will not start with '0'.
-k will be between 0 and 36, inclusive.


EXAMPLES

0)
{"HELLO"}
2

Returns: "ZZLLO"

It is optimal to change the two most significant digits in the given number.

1)
{"500", "POINTS", "FOR", "THIS", "PROBLEM"}
5

Returns: "1100TC85"



2)
{"TO", "BE", "OR", "NOT", "TO", "BE"}
0

Returns: "QNO"

k = 0 means that you're not allowed to change any digits, so the answer is the sum of the given numbers.

3)
{"KEQUALS36"}
36

Returns: "ZZZZZZZZZ"

k = 36 means that you have to replace all the letters with 'Z'.

4)
{"GOOD", "LUCK", "AND", "HAVE", "FUN"}
7

Returns: "31YUB"



*/
// END CUT HERE
