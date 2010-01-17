#line 2 "PalindromePhrases.cpp"
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


class PalindromePhrases {
  int n,full;
  vector<string> wds;
  vector<string> sdw;
  vector<bool> nat;
  vector<int> wl;

  map<pair<string,string>,int> mm;
  set<string> dic;

 public:
  string reverse(string s){
    int l=sz(s);
    char buf[l+1];
    rep(i,l) buf[i]=s[l-i-1];
    buf[l]=0;
    return buf;
  }
  bool pa(const string s){ return (s == reverse(s)); }

  long long sub(string pre,string pre_, string post,string post_, string rpost, int unused){
    pair<string,string> key=make_pair(pre_,post_);
    //    if(found(mm,key)) return mm[key];
    
    cout << ": '" << pre << "' ... '" << post << "'" << endl;

    long long c=0;
    if (pa(pre+post)){
      string tot=(post=="")?pre_ : (pre_+" "+post_);
      //if(found(dic,tot)) return mm[key];
      dic.insert(tot);
      c++;
    } else {
      int pl=sz(pre), rl=sz(rpost);
      if (rl==0){
        ;
      }if (pl<rl){
        if (pre!=rpost.substr(0,pl)){
          mm[key] = 0;
          return 0;
        }
      }else if(pl==rl){
        if (pre!=rpost){
          mm[key] = 0;
          return 0;
        }
      }else {
        if (pre.substr(0,rl)!=rpost){
          mm[key] = 0;
          return 0;
        }
      }
    }

    if(unused==0){
      mm[key] = c;
      return c;
    }

    cout << "alive" << endl;
            

    int la=sz(pre), lz=sz(post);
    if(la<lz){
      // 前のばし
      int lackl=lz-la;
      string lack = reverse(post.substr(0,lackl));
      cout << "    前のばし" << lz-la << ":" << lack << endl;
      for(int i=0,m=1;i<n;i++,m<<=1){
        if(unused & m){
          bool use=false;
          if (wl[i]<lackl){
            if (wds[i]==lack.substr(0,wl[i])) use=true;
          }else if(wl[i]==lackl){
            if (wds[i]==lack) use=true;
          }else{
            if (wds[i].substr(0,lackl)==lack) use=true;
          }
          if (use) {
            cout << "      using " << wds[i];
            c += sub(pre+wds[i],pre_+" "+wds[i], post,post_, rpost, unused-m);
          }
        }
      }
    } else if(la==lz){
      // 前から任意
      cout << "    前から任意" << endl;
      for(int i=0,m=1;i<n;i++,m<<=1){
        if(unused & m){
          cout << "      using " << wds[i];
          c += sub(pre+wds[i],pre_+" "+wds[i], post,post_, rpost, unused-m);
        }
      }
    } else {
      // 後ろ伸ばし
      int lackl = la-lz;
      string lack = reverse(pre.substr(lz,la));
      cout << "    後ろのばし" << la-lz << ":" << lack << endl;
      for(int i=0,m=1;i<n;i++,m<<=1){
        if(unused & m){
          bool use=false;
          if (wl[i]<lackl){
            if (wds[i]==lack.substr(lackl-wl[i],lackl)) use=true;
          }else if(wl[i]==lackl){
            if (wds[i]==lack) use=true;
          }else{
            if (wds[i].substr(wl[i]-lackl,wl[i])==lack) use=true;
          }
          if (use) {
            cout << "      using " << wds[i];
            if (post==""){
              c += sub(pre,pre_, wds[i],wds[i], rpost, unused-m);
            }else{
              c += sub(pre,pre_, wds[i]+post,wds[i]+" "+post_, rpost+sdw[i], unused-m);
            }
          }
        }
      }
      
    }

    mm[key] = c;
    return c;
  }
  
  long long getAmount(vector<string> words) {
	n=sz(words); full=(1<<n)-1;
    wds.resize(n); wl.resize(n); sdw.resize(n); nat.resize(n);
    rep(i,n) {
      wds[i] = words[i]; wl[i] = sz(wds[i]);
      sdw[i] = reverse(wds[i]);
      nat[i] = (wds[i]==sdw[i]);
    }

    long long c =0;
    for(int i=0,m=1;i<n;i++,m<<=1){
      c += sub(wds[i],wds[i], "","","", full-m);
    }

    cout << "dic: " << dic << endl;
    return sz(dic);
    //return c;
  }
};

// BEGIN CUT HERE
#include <time.h>
clock_t start_time;
void timer_clear() { start_time = clock(); }
string timer() { clock_t end_time = clock(); double interval = (double)(end_time - start_time)/CLOCKS_PER_SEC; ostringstream os; os << " (" << interval*1000 << " msec)"; return os.str(); }

template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
int verify_case(const long long &Expected, const long long &Received) { if (Expected == Received) cerr << "PASSED" << timer() << endl; else { cerr << "FAILED" << timer() << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } return 0;}

template<int N> struct Case_ {};
char Test_(...);
int Test_(Case_<0>) {
	timer_clear();
	string words_[] = {"a","ba"};
	  vector <string> words(words_, words_+sizeof(words_)/sizeof(*words_)); 
	long long RetVal = 2LL; 
	return verify_case(RetVal, PalindromePhrases().getAmount(words)); }
int Test_(Case_<1>) {
	timer_clear();
	string words_[] = {"ab","bcd","efg"};
	  vector <string> words(words_, words_+sizeof(words_)/sizeof(*words_)); 
	long long RetVal = 0LL; 
	return verify_case(RetVal, PalindromePhrases().getAmount(words)); }
int Test_(Case_<2>) {
	timer_clear();
	string words_[] = {"a", "bba", "abb"};
	  vector <string> words(words_, words_+sizeof(words_)/sizeof(*words_)); 
	long long RetVal = 7LL; 
	return verify_case(RetVal, PalindromePhrases().getAmount(words)); }
int Test_(Case_<3>) {
	timer_clear();
	string words_[] = {"aabccc", "ccbbca", "a", "acaabb", "aaa", "aab", "c", "babb", "aacaa", "b"};
	  vector <string> words(words_, words_+sizeof(words_)/sizeof(*words_)); 
	long long RetVal = 47LL; 
	return verify_case(RetVal, PalindromePhrases().getAmount(words)); }

template<int N> void Run_() { cerr << "Test Case #" << N << "..." << flush; Test_(Case_<N>()); Run_<sizeof(Test_(Case_<N+1>()))==1 ? -1 : N+1>(); }
template<>      void Run_<-1>() {}
int main() { Run_<0>(); }
// END CUT HERE


// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// One of your friends has given you several words and asked you how many palindromic phrases you can compose with those words.  
To save yourself some time, you've decided to write a program to answer this question.  In this problem, a word is defined as a non-empty sequence
of lowercase letters ('a'-'z').  A phrase is a non-empty sequence of words, where each pair of consecutive words is separated with exactly one space character.  A phrase is palindromic if it reads the same forward and backward, ignoring space characters.

You are given a vector <string> words.  Return the number of different palindromic phrases that can be composed with the given words.  Each word in words can be used at most once within each phrase.  Two phrases are considered different if they are different strings, even if they read the same when ignoring spaces (for example, "a ba" and "ab a" are different phrases).

DEFINITION
Class:PalindromePhrases
Method:getAmount
Parameters:vector <string>
Returns:long long
Method signature:long long getAmount(vector <string> words)


CONSTRAINTS
-words will contain between 1 and 13 elements, inclusive.
-Each element of words will contain between 1 and 13 lowercase letters ('a'-'z'), inclusive.
-All elements of words will be distinct.


EXAMPLES

0)
{"a","ba"}

Returns: 2

You can construct two palindromic phrases "a" and "a ba".

1)
{"ab","bcd","efg"}

Returns: 0

No palindromic phrases can be built.

2)
{"a", "bba", "abb"}

Returns: 7

Here we have 7 palindromic phrases: "a", "a bba", "abb a", "abb bba", "bba abb", "abb a bba", "bba a abb".
Note that even though "a bba" and "abb a" represent the same palindrome, they differ as strings, so we count both of them.

3)
{"aabccc", "ccbbca", "a", "acaabb", "aaa", "aab", "c", "babb", "aacaa", "b"}

Returns: 47



*/
// END CUT HERE
