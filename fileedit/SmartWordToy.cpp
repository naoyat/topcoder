#line 2 "SmartWordToy.cpp"
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

class SmartWordToy {
  inline int state(int ch0,int ch1,int ch2,int ch3){
    return ((ch0-'a') << 15) | ((ch1-'a') << 10) | ((ch2-'a') << 5) | (ch3-'a');
  }
  inline int state_ch(int state,int pos){
    return (state >> (15 - 5*pos)) & 0x1f; // 0-25
  }
  int str2state(const string str){
    return state(str[0],str[1],str[2],str[3]);
  }
  string state2str(int state){
    stringstream ss;
    rep(i,4) ss << 'a'+state_ch(state,0);
    return ss.str();
  }
  int incr(int state, int pos){
    int ofs=15-5*pos;
    int ch=state_ch(state,pos);
    state &= ~(0x1f << ofs);
    int newstate=state|(((ch+1)%26)<<ofs);
    return newstate;
  }
  int decr(int state, int pos){
    int ofs=15-5*pos;
    int ch=state_ch(state,pos);
    state &= ~(0x1f << ofs);
    int newstate=state|(((ch+25)%26)<<ofs);
    return newstate;
  }
     
 public:
  int minPresses(string start, string finish, vector <string> forbid) {
    int s_state=str2state(start), f_state=str2state(finish);

    vector<int> passed(1048576,INT_MAX);
// BEGIN CUT HERE
    //vector<int> passed(1048576,INT_MAX);//,forbidden(1048576,false);
    //set<int> passed,forbidden;
// END CUT HERE
    tr(forbid,it){
      vector<string> ss = split(*it);
      int al=sz(ss[0]), bl=sz(ss[1]), cl=sz(ss[2]), dl=sz(ss[3]);
      rep(a,al){
        rep(b,bl){
          rep(c,cl){
            rep(d,dl){
              int st=state(ss[0][a], ss[1][b], ss[2][c], ss[3][d]);
// BEGIN CUT HERE
              //forbidden[] = trued;
// END CUT HERE
              passed[st]=-1;// forbidden
// BEGIN CUT HERE
              //forbidden.insert( state(ss[0][a], ss[1][b], ss[2][c], ss[3][d]) );
// END CUT HERE
            }
          }
        }
      }
    }
// BEGIN CUT HERE
    //if(/*found(forbidden,s_state) ||*/ found(forbidden,f_state)) return -1;
    //if(forbidden[f_state]) return -1;
// END CUT HERE
    if(passed[f_state]==-1) return -1;
// BEGIN CUT HERE
    /*
    tr(forbidden,it) {
      cout << state2str(*it) << ", ";
    }
    cout << endl;
    */
// END CUT HERE

    priority_queue<pair<int,int> > pq;
    pq.push(make_pair(0,s_state));

    while (!pq.empty()) {
      int step=-pq.top().first, st=pq.top().second, st_;
      pq.pop();
      if(st==f_state) return step;
// BEGIN CUT HERE
      //cout << "3:" << state2str(st) << endl;
      //if(found(forbidden,st)) continue;
      //if(found(passed,st)) continue;
      //passed.insert(st);
// END CUT HERE
      if(step < passed[st]){
        passed[st]=step;

        step++;
        rep(i,4){
          st_ = incr(st,i);
          if(passed[st_]>step) pq.push(make_pair(-step,st_));

          st_ = decr(st,i);
          if(passed[st_]>step) pq.push(make_pair(-step,st_));
        }
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
	string start = "aaaa"; 
	string finish = "zzzz"; 
	string forbid_[] = {"a a a z", "a a z a", "a z a a", "z a a a", "a z z z", "z a z z", "z z a z", "z z z a"};
	  vector <string> forbid(forbid_, forbid_+sizeof(forbid_)/sizeof(*forbid_)); 
	int RetVal = 8; 
	return verify_case(RetVal, SmartWordToy().minPresses(start, finish, forbid)); }
int Test_(Case_<1>) {
	timer_clear();
	string start = "aaaa"; 
	string finish = "bbbb"; 
	vector <string> forbid; 
	int RetVal = 4; 
	return verify_case(RetVal, SmartWordToy().minPresses(start, finish, forbid)); }
int Test_(Case_<2>) {
	timer_clear();
	string start = "aaaa"; 
	string finish = "mmnn"; 
	vector <string> forbid; 
	int RetVal = 50; 
	return verify_case(RetVal, SmartWordToy().minPresses(start, finish, forbid)); }
int Test_(Case_<3>) {
	timer_clear();
	string start = "aaaa"; 
	string finish = "zzzz"; 
	string forbid_[] = {"bz a a a", "a bz a a", "a a bz a", "a a a bz"};
	  vector <string> forbid(forbid_, forbid_+sizeof(forbid_)/sizeof(*forbid_)); 
	int RetVal = -1; 
	return verify_case(RetVal, SmartWordToy().minPresses(start, finish, forbid)); }
int Test_(Case_<4>) {
	timer_clear();
	string start = "aaaa"; 
	string finish = "zzzz"; 
	string forbid_[] = {"cdefghijklmnopqrstuvwxyz a a a", 
 "a cdefghijklmnopqrstuvwxyz a a", 
 "a a cdefghijklmnopqrstuvwxyz a", 
 "a a a cdefghijklmnopqrstuvwxyz"};
	  vector <string> forbid(forbid_, forbid_+sizeof(forbid_)/sizeof(*forbid_)); 
	int RetVal = 6; 
	return verify_case(RetVal, SmartWordToy().minPresses(start, finish, forbid)); }
int Test_(Case_<5>) {
	timer_clear();
	string start = "aaaa"; 
	string finish = "bbbb"; 
	string forbid_[] = {"b b b b"};
	  vector <string> forbid(forbid_, forbid_+sizeof(forbid_)/sizeof(*forbid_)); 
	int RetVal = -1; 
	return verify_case(RetVal, SmartWordToy().minPresses(start, finish, forbid)); }
int Test_(Case_<6>) {
	timer_clear();
	string start = "zzzz"; 
	string finish = "aaaa"; 
	string forbid_[] = {"abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk"};
	  vector <string> forbid(forbid_, forbid_+sizeof(forbid_)/sizeof(*forbid_)); 
	int RetVal = -1; 
	return verify_case(RetVal, SmartWordToy().minPresses(start, finish, forbid)); }

template<int N> void Run_() { cerr << "Test Case #" << N << "..." << flush; Test_(Case_<N>()); Run_<sizeof(Test_(Case_<N+1>()))==1 ? -1 : N+1>(); }
template<>      void Run_<-1>() {}
int main() { Run_<0>(); }
// END CUT HERE


// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// The toy company "I Can't Believe It Works!" has hired you to help develop educational toys.  The current project is a  word toy that displays four letters at all times.  Below each letter are two buttons that cause the letter above to change to the previous or next letter in alphabetical order.  So, with one click of a button the letter 'c' can be changed to a 'b' or a 'd'.  The alphabet is circular, so for example an 'a' can become a 'z' or a 'b' with one click.


In order to test the toy, you would like to know if  a word can be reached from some starting word, given one or more constraints.  A constraint defines a set of forbidden words that can never be displayed by the toy.  Each constraint is formatted like "X X X X", where each X is a string of lowercase letters.  A word is defined by a constraint if the ith letter of the word is contained in the ith X of the contraint.  For example, the constraint "lf a tc e" defines the words "late", "fate", "lace" and "face".


You will be given a String start, a String finish, and a String[] forbid. Calculate and return the minimum number of button presses required for the toy to show the word finish if the toy was originally showing the word start.  Remember, the toy must never show a forbidden word.  If it is impossible for the toy to ever show the desired word, return -1.

DEFINITION
Class:SmartWordToy
Method:minPresses
Parameters:string, string, vector <string>
Returns:int
Method signature:int minPresses(string start, string finish, vector <string> forbid)


CONSTRAINTS
-start and finish will contain exactly four characters.
-start and finish will contain only lowercase letters.
-forbid will contain between 0 and 50 elements, inclusive.
-Each element of forbid will contain between 1 and 50 characters.
-Each element of forbid will contain lowercase letters and exactly three spaces.
-Each element of forbid will not contain leading, trailing or double spaces.
-Each letter within a group of letters in each element of forbid will be distinct.  Thus "aa a a a" is not allowed.
-start will not be a forbidden word.


EXAMPLES

0)
"aaaa"
"zzzz"
{"a a a z", "a a z a", "a z a a", "z a a a", "a z z z", "z a z z", "z z a z", "z z z a"}

Returns: 8

1)
"aaaa"
"bbbb"
{}

Returns: 4

Simply change each letter one by one to the following letter in the alphabet.

2)
"aaaa"
"mmnn"
{}

Returns: 50

Just as in the previous example, we have no forbidden words.  Simply apply the correct number of button presses for each letter and you're there.

3)
"aaaa"
"zzzz"
{"bz a a a", "a bz a a", "a a bz a", "a a a bz"}

Returns: -1

Here is an example where it is impossible to go to any word from "aaaa".

4)
"aaaa"
"zzzz"
{"cdefghijklmnopqrstuvwxyz a a a", 
 "a cdefghijklmnopqrstuvwxyz a a", 
 "a a cdefghijklmnopqrstuvwxyz a", 
 "a a a cdefghijklmnopqrstuvwxyz"}

Returns: 6

5)
"aaaa"
"bbbb"
{"b b b b"}

Returns: -1

6)
"zzzz"
"aaaa"
{"abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk"}

Returns: -1

*/
// END CUT HERE
