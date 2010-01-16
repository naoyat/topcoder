// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// A word is grouped if, for each letter in the word, all occurrences of that letter form exactly one consecutive sequence.  In other words, no two equal letters are separated by one or more letters that are different.  For example, the words "ccazzzzbb" and "code" are grouped, while "aabbbccb" and "topcoder" are not.

A grouped word was divided into several parts.  You are given all the parts in random order as a vector <string>.  Reconstruct the original word and return it.  If there is more than one possible answer, return "MANY" instead.  If no grouped word could have resulted in the given parts, return "IMPOSSIBLE" instead (all quotes for clarity).


DEFINITION
Class:GroupedWord
Method:restore
Parameters:vector <string>
Returns:string
Method signature:string restore(vector <string> parts)


CONSTRAINTS
-parts will contain between 1 and 50 elements, inclusive.
-Each element of parts will contain between 1 and 20 characters, inclusive.
-Each element of parts will contain only lowercase letters ('a' - 'z').


EXAMPLES

0)
{"aaa", "a", "aa"}

Returns: "aaaaaa"

These parts could only have come from the word "aaaaaa", which is a grouped word.

1)
{"ab", "bba"}

Returns: "IMPOSSIBLE"

The only possible original words are "abbba" and "bbaab", and neither of them are grouped words.

2)
{"te", "st"}

Returns: "stte"



3)
{"te", "s", "t"}

Returns: "MANY"

The initial word could be either "stte" or "ttes".

4)
{"orr", "rd", "woo", "www"}

Returns: "wwwwooorrrd"



5)
{"abcb"}

Returns: "IMPOSSIBLE"

*/
// END CUT HERE

#line 69 "GroupedWord.cpp"
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
//#define sz  size()
// #define lh  length()
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

// BEGIN CUT HERE
string binstr(long long x, int len_min=1)
{
  char buf[65], *p = buf+64;
  *p = 0;

  while (x > 0 || len_min > 0) {
    *(--p) = '0' + (x & 1);
    x >>= 1;
    len_min--;
  }
  string s(p);
  return s;
}
// END CUT HERE

class GroupedWord {
  int n;
  vs ps;
  vi chs;
  vi lastcs;
  map<pair<string,pair<int,ll> >,string> memo;

  string sub(const string &str, int last, int len, ll av, ll chs_used){
    if(len==n) return str;
    if(av==0LL) return "";
    pair<string,pair<int,ll> > key=make_pair(str,make_pair(len,av));
    if(found(memo,key)) return memo[key];
// BEGIN CUT HERE
    //printf("sub(\"%s\", %s, %s)\n", str.c_str(), binstr(av,n).c_str(), binstr(chs_used,26).c_str());
    //pair<int,string> p=make_pair(0,"");
    //    int last = sz(str)>0 ? lastc(str) : -1;
// END CUT HERE
    string p=""; int pcnt=0;
    for(ll i=0,mi=1LL;i<n;i++,mi<<=1){
      if(!(av&mi)) continue;
      ll dub=chs[i]&chs_used;
      if(ps[i][0]==last) dub-=(1LL<<(last-'a'));
      if(dub) continue;
// BEGIN CUT HERE
      //printf("  \"%s\"+\"%s\" ..\n", str.c_str(), ps[i].c_str());
      //int ilast = lastc(ps[i]);
// END CUT HERE
      ll av_new=av-mi, chs_new=chs_used|chs[i];
      for(ll j=0,mj=1LL;j<n;j++,mj<<=1){
        if((av_new&mj)==0) continue;
        if((chs_new&chs[j])==0) continue;
        if(lastcs[i]==ps[j][0]) continue;
        av_new-=mj;
      }
      string s=sub(str+ps[i],lastcs[i],len+1,av_new,chs_new);
      if(s!="") {
        if(s=="@") return "MANY";
        if(pcnt==1 && p!=s) return "MANY";
        p=s; pcnt=1;
      }
    }
// BEGIN CUT HERE
    //cout << "p:" << p << endl;
// END CUT HERE
    return memo[key]=p;
  }
  ll used_chars(const string &s){
    ll m=0LL;
    rep(i,sz(s)){
      ll mi=1LL<<(s[i]-'a');
      if((m&mi) && (i>0 && s[i-1]!=s[i])) return -1;
      m |= mi;
    }
    return m;
  }
 public:
  string restore(vector<string> parts) {
    n=sz(parts);
    ps=parts;
    chs.resize(n); lastcs.resize(n);
    rep(i,n) if((chs[i]=used_chars(parts[i]))<0) return "IMPOSSIBLE";
    rep(i,n) lastcs[i]=lastc(parts[i]);
// BEGIN CUT HERE
    /*    rep(i,n){
      cout << parts[i] << " => " << binstr(chs[i],26) << endl;
      }*/
// END CUT HERE
    string result = sub("", -1, 0, (1LL<<n)-1LL, 0LL);
    return (result=="")?"IMPOSSIBLE":result;
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
	string parts_[] = {"aaa", "a", "aa"};
	  vector <string> parts(parts_, parts_+sizeof(parts_)/sizeof(*parts_)); 
	string RetVal = "aaaaaa"; 
	return verify_case(RetVal, GroupedWord().restore(parts)); }
int Test_(Case_<1>) {
	timer_clear();
	string parts_[] = {"ab", "bba"};
	  vector <string> parts(parts_, parts_+sizeof(parts_)/sizeof(*parts_)); 
	string RetVal = "IMPOSSIBLE"; 
	return verify_case(RetVal, GroupedWord().restore(parts)); }
int Test_(Case_<2>) {
	timer_clear();
	string parts_[] = {"te", "st"};
	  vector <string> parts(parts_, parts_+sizeof(parts_)/sizeof(*parts_)); 
	string RetVal = "stte"; 
	return verify_case(RetVal, GroupedWord().restore(parts)); }
int Test_(Case_<3>) {
	timer_clear();
	string parts_[] = {"te", "s", "t"};
	  vector <string> parts(parts_, parts_+sizeof(parts_)/sizeof(*parts_)); 
	string RetVal = "MANY"; 
	return verify_case(RetVal, GroupedWord().restore(parts)); }
int Test_(Case_<4>) {
	timer_clear();
	string parts_[] = {"orr", "rd", "woo", "www"};
	  vector <string> parts(parts_, parts_+sizeof(parts_)/sizeof(*parts_)); 
	string RetVal = "wwwwooorrrd"; 
	return verify_case(RetVal, GroupedWord().restore(parts)); }
int Test_(Case_<5>) {
	timer_clear();
	string parts_[] = {"abcb"};
	  vector <string> parts(parts_, parts_+sizeof(parts_)/sizeof(*parts_)); 
	string RetVal = "IMPOSSIBLE"; 
	return verify_case(RetVal, GroupedWord().restore(parts)); }
int Test_(Case_<6>) {
	timer_clear();
	string parts_[] = {"a", "b"};
	  vector <string> parts(parts_, parts_+sizeof(parts_)/sizeof(*parts_)); 
	string RetVal = "MANY"; 
	return verify_case(RetVal, GroupedWord().restore(parts)); }
int Test_(Case_<7>) { //27
	timer_clear();
	string parts_[] = {"fffff", "hggggggg", "fh", "hhh", "ddde", "ddddd", "cccccc", "ccccoo", "oooodd", "cccccc", "ooooooo", "oo", "eeeeeeeee", "ee", "ddddddd", "ggggggg", "fff"};
    vector <string> parts(parts_, parts_+sizeof(parts_)/sizeof(*parts_)); 
	string RetVal = "MANY"; 
	return verify_case(RetVal, GroupedWord().restore(parts)); }
int Test_(Case_<8>) {
	timer_clear();
	string parts_[] = {"a", "a", "b", "b", "x", "x", "x", "a", "x", "a", "ax", "x", "x", "ba"};
    vector <string> parts(parts_, parts_+sizeof(parts_)/sizeof(*parts_)); 
	string RetVal = "bbbaaaaaaxxxxxxx";
	return verify_case(RetVal, GroupedWord().restore(parts)); }

template<int N> void Run_() { cerr << "Test Case #" << N << "..." << flush; Test_(Case_<N>()); Run_<sizeof(Test_(Case_<N+1>()))==1 ? -1 : N+1>(); }
template<>      void Run_<-1>() {}
int main() { Run_<0>(); }
// END CUT HERE

