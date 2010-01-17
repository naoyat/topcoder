#line 2 "MessageMess.cpp"
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
#define FOR(var,from,to) for(int var=(from);var<=(to);var++)
#define rep(var,n)  for(int var=0;var<(n);var++)
#define all(c)  (c).begin(),(c).end()
#define tr(c,i)  for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); i++)
#define found(s,e)  ((s).find(e)!=(s).end())

typedef pair<int,int> i_i;
#define cons(x,y) make_pair((x),(y))
#define car(x) ((x).first)
#define cdr(x) ((x).second)
//344.01
class MessageMess {
  vector<string> dict;
  int n;

  pair<int,string> sub(string msg,string curr){
    if (msg == "") return cons(1,curr);
    
    int l=sz(msg);
    //printf("sub('%s','%s')..\n", msg.c_str(), curr.c_str() );
    vector<string> res;
    rep(i,n){
      string d = dict[i]; int dl=sz(d);
      if (dl > l) continue;
      if (d[0] != msg[0]) continue;
      if (d != msg.substr(0,dl)) continue;
      pair<int,string> subres = sub(msg.substr(dl), (curr == "") ? d : (curr + " " + d));
      switch(car(subres)) {
        case 0: break;
        case 1: res.pb( cdr(subres) ); break;
        default: return cons(2,"");
      }
    }
    switch(sz(res)){
      case 0: return cons(0,"");
      case 1: return cons(1,res[0]);
      default: return cons(2,"");
    }
  }
  
 public:
  string restore(vector<string> dictionary, string message) {
    dict = dictionary; 
    n=sz(dict);
    //vector<char> msg(all(message));
    pair<int,string> res = sub(message,"");
    switch(car(res)){
      case 0: return "IMPOSSIBLE!";
      case 1: return cdr(res);
      default: return "AMBIGUOUS!";
    }
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
	string dictionary_[] = {"HI", "YOU", "SAY"};
	  vector <string> dictionary(dictionary_, dictionary_+sizeof(dictionary_)/sizeof(*dictionary_)); 
	string message = "HIYOUSAYHI"; 
	string RetVal = "HI YOU SAY HI"; 
	return verify_case(RetVal, MessageMess().restore(dictionary, message)); }
int Test_(Case_<1>) {
	timer_clear();
	string dictionary_[] = {"ABC", "BCD", "CD", "ABCB"};
	  vector <string> dictionary(dictionary_, dictionary_+sizeof(dictionary_)/sizeof(*dictionary_)); 
	string message = "ABCBCD"; 
	string RetVal = "AMBIGUOUS!"; 
	return verify_case(RetVal, MessageMess().restore(dictionary, message)); }
int Test_(Case_<2>) {
	timer_clear();
	string dictionary_[] = {"IMPOSS", "SIBLE", "S"};
	  vector <string> dictionary(dictionary_, dictionary_+sizeof(dictionary_)/sizeof(*dictionary_)); 
	string message = "IMPOSSIBLE"; 
	string RetVal = "IMPOSSIBLE!"; 
	return verify_case(RetVal, MessageMess().restore(dictionary, message)); }
int Test_(Case_<3>) {
	timer_clear();
	string dictionary_[] = {"IMPOSS", "SIBLE", "S", "IMPOSSIBLE"};
	  vector <string> dictionary(dictionary_, dictionary_+sizeof(dictionary_)/sizeof(*dictionary_)); 
	string message = "IMPOSSIBLE"; 
	string RetVal = "IMPOSSIBLE"; 
	return verify_case(RetVal, MessageMess().restore(dictionary, message)); }

template<int N> void Run_() { cerr << "Test Case #" << N << "..." << flush; Test_(Case_<N>()); Run_<sizeof(Test_(Case_<N+1>()))==1 ? -1 : N+1>(); }
template<>      void Run_<-1>() {}
int main() { Run_<0>(); }
// END CUT HERE


// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// It is a common practice in cryptography to remove the spaces from a message 
before encoding it to help to disguise its structure. 
Even after it is then decoded, we are left with the
problem of putting the spaces back in the message.

Create a class MessageMess that contains a method restore that 
takes a vector <string> dictionary of possible words and
a string message as inputs. It returns the message with single spaces inserted to divide the message into words from the dictionary.  If there is more than one way to insert spaces, it returns "AMBIGUOUS!"  If there is no way to insert spaces, it returns "IMPOSSIBLE!" The return should never
have any leading or trailing spaces.



DEFINITION
Class:MessageMess
Method:restore
Parameters:vector <string>, string
Returns:string
Method signature:string restore(vector <string> dictionary, string message)


NOTES
-Don't forget the '!' at the end of the two special returns
-A proper message may require 0 spaces to be inserted


CONSTRAINTS
-dictionary will contain between 1 and 50 elements inclusive
-the elements of dictionary will be distinct
-each element of dictionary will contain between 1 and 50 characters
-message will contain between 1 and 50 characters
-every character in message and in each element of dictionary will be an uppercase letter 'A'-'Z'


EXAMPLES

0)
{"HI", "YOU", "SAY"}
"HIYOUSAYHI"

Returns: "HI YOU SAY HI"


A word from dictionary may appear multiple times in the message.


1)
{"ABC", "BCD", "CD", "ABCB"}
"ABCBCD"

Returns: "AMBIGUOUS!"

"ABC BCD" and "ABCB CD" are both possible interpretations of message.

2)
{"IMPOSS", "SIBLE", "S"}
"IMPOSSIBLE"

Returns: "IMPOSSIBLE!"

There is no way to concatenate words from this dictionary 
to form "IMPOSSIBLE"

3)
{"IMPOSS", "SIBLE", "S", "IMPOSSIBLE"}
"IMPOSSIBLE"

Returns: "IMPOSSIBLE"

This message can be decoded without ambiguity. This requires the insertion of no spaces since the entire message appears as a word in the dictionary.

*/
// END CUT HERE
