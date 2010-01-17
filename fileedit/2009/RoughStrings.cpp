// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// Given a string s, its roughness is calculated as follows:  Let c1 be the letter that appears most frequently in s, and let c2 be the letter that appears least frequently (c2 must appear at least once).  The roughness of s is the number of occurrences of c1 minus the number of occurrences of c2.

You are allowed to modify s by erasing between 0 and n characters, inclusive (see example 1 for clarification).  Return the minimum possible roughness that can be achieved by such a modification.

DEFINITION
Class:RoughStrings
Method:minRoughness
Parameters:string, int
Returns:int
Method signature:int minRoughness(string s, int n)


CONSTRAINTS
-s will contain between 1 and 50 characters, inclusive.
-s will contain only lowercase letters ('a'-'z').
-n will be between 0 and m-1, inclusive, where m is the number of characters in s.


EXAMPLES

0)
"aaaaabbc"
1

Returns: 3

We may remove one 'a' or one 'c' to obtain the minimal roughness of 3.

1)
"aaaabbbbc"
5

Returns: 0

One of the ways is to remove 'c' and all occurrences of 'a'.

2)
"veryeviltestcase"
1

Returns: 2



3)
"gggggggooooooodddddddllllllluuuuuuuccckkk"
5

Returns: 3



4)
"zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz"
17

Returns: 0



5)
"bbbccca"
2

Returns: 0

Sometimes you may want to remove less than n characters.

*/
// END CUT HERE

#line 76 "RoughStrings.cpp"
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
#define all(c)  (c).begin(),(c).end()
#define tr(c,i)  for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); i++)
#define rep(var,n)  for(int var=0;var<(n);var++)
#define found(s,e)  ((s).find(e)!=(s).end())
#define remove_(c,val) (c).erase(remove((c).begin(),(c).end(),(val)),(c).end())

class RoughStrings {
  int n_;
  map<vector<int>,int> memo;

  int sub(vector<int> v, int d){
    remove_(v,0);//v.erase(remove(all(v),0),v.end());
    if(found(memo,v)) return memo[v];
    int l=v.size(); if(l<=1) return 0;
    sort(all(v));
    int minr = v[l-1]-v[0];
    if(d==n_) return memo[v]=minr;

    if (v[0]>0) {
      v[0]--;
      minr = min(minr,sub(v,d+1));
      v[0]++;
    }
    v[l-1]--;
    minr = min(minr,sub(v,d+1));
    v[l-1]++;
    return memo[v]=minr;
  }
public:
  int minRoughness(string s, int n) {
    n_=n;
    vector<int>cn(26,0);
    int m=s.length(); //1-50
    rep(i,m) cn[s[i]-'a']++;
    return sub(cn,0);
// BEGIN CUT HERE
    /*
    cn.erase(remove(all(cn),0),cn.end());
    int l=cn.size(); if(l<=1) return 0;
    //int a=0; tr(cn,it) a+=*it; a/=l;
    sort(all(cn));
    int minr = cn[l-1]-cn[0];

    if (cn[0]>0) {
      cn[0]--;
      minr = min(minr,sub(cn,1));
      cn[0]++;
    }
    cn[l-1]--;
    minr = min(minr,sub(cn,1));
    cn[l-1]++;
    return minr;
    */
// END CUT HERE
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
	string s = "aaaaabbc"; 
	int n = 1; 
	int RetVal = 3; 
	return verify_case(RetVal, RoughStrings().minRoughness(s, n)); }
int Test_(Case_<1>) {
	timer_clear();
	string s = "aaaabbbbc"; 
	int n = 5; 
	int RetVal = 0; 
	return verify_case(RetVal, RoughStrings().minRoughness(s, n)); }
int Test_(Case_<2>) {
	timer_clear();
	string s = "veryeviltestcase"; 
	int n = 1; 
	int RetVal = 2; 
	return verify_case(RetVal, RoughStrings().minRoughness(s, n)); }
int Test_(Case_<3>) {
	timer_clear();
	string s = "gggggggooooooodddddddllllllluuuuuuuccckkk"; 
	int n = 5; 
	int RetVal = 3; 
	return verify_case(RetVal, RoughStrings().minRoughness(s, n)); }
int Test_(Case_<4>) {
	timer_clear();
	string s = "zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz"; 
	int n = 17; 
	int RetVal = 0; 
	return verify_case(RetVal, RoughStrings().minRoughness(s, n)); }
int Test_(Case_<5>) {
	timer_clear();
	string s = "bbbccca"; 
	int n = 2; 
	int RetVal = 0; 
	return verify_case(RetVal, RoughStrings().minRoughness(s, n)); }
int Test_(Case_<6>) {
	timer_clear();
	string s = "ytyyyyybbyybsyyysyyyycyysbyyybyyyyy";
	int n = 29;
	int RetVal = 0;
	return verify_case(RetVal, RoughStrings().minRoughness(s, n)); }
int Test_(Case_<7>) {
	timer_clear();
	string s = "mdyjfrwcwrhstqpwuygrtwoowubdnjgal";
	int n = 28;
	int RetVal = 0;
	return verify_case(RetVal, RoughStrings().minRoughness(s, n)); }

template<int N> void Run_() { cerr << "Test Case #" << N << "..." << flush; Test_(Case_<N>()); Run_<sizeof(Test_(Case_<N+1>()))==1 ? -1 : N+1>(); }
template<>      void Run_<-1>() {}
int main() { Run_<0>(); }
// END CUT HERE

