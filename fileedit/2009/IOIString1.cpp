#line 2 "IOIString.cpp"
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

#define MODULO 1000000007LL;

class IOIString {
  vector<int> ex;
  
  map<string,ll> m;
  
 public:
  ll sub(string _s){
    if (_s.length() < 3) return 0LL;

    ll res=0LL;
    if (found(m,_s)) return m[_s];

    // omit O
    int l=_s.length(), k;
    int z=0; rep(i,l) { if (_s[i]=='O') z++; else break; }
    
    string s = _s.substr(z); l=s.length(), k=(l-1)/2;
    if (l<3) goto zero;

    FOR(i,1,k){
      if(s[0]=='O' || s[i]=='I' || s[i*2]=='O')continue;
      
    }
    
    
    if (l>3) res = (res + sub(s.substr(1))) % MODULO;
 zero:
    m[_s] = res;
    return res;
  }
  
  int countIOIs(vector<string> mask) {
	string s; tr(mask,it) s += *it;

    ex.resize(2501); ex[0]=1;
    FOR(i,1,2500) ex[i]=(ex[i-1]*2)%MODULO;

    m.clear();

    ll x = sub(s) % MODULO;
    return (int)x;
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
	string mask_[] = {"IO?"};
	  vector <string> mask(mask_, mask_+sizeof(mask_)/sizeof(*mask_)); 
	int RetVal = 1; 
	return verify_case(RetVal, IOIString().countIOIs(mask)); }
int Test_(Case_<1>) {
	timer_clear();
	string mask_[] = {"????"};
	  vector <string> mask(mask_, mask_+sizeof(mask_)/sizeof(*mask_)); 
	int RetVal = 4; 
	return verify_case(RetVal, IOIString().countIOIs(mask)); }
int Test_(Case_<2>) {
	timer_clear();
	string mask_[] = {"?II"};
	  vector <string> mask(mask_, mask_+sizeof(mask_)/sizeof(*mask_)); 
	int RetVal = 0; 
	return verify_case(RetVal, IOIString().countIOIs(mask)); }
int Test_(Case_<3>) {
	timer_clear();
	string mask_[] = {"I??O??I"};
	  vector <string> mask(mask_, mask_+sizeof(mask_)/sizeof(*mask_)); 
	int RetVal = 16; 
	return verify_case(RetVal, IOIString().countIOIs(mask)); }
int Test_(Case_<4>) {
	timer_clear();
	string mask_[] = {"???I???????O???","???????????O??IO????????I???"};
	  vector <string> mask(mask_, mask_+sizeof(mask_)/sizeof(*mask_)); 
	int RetVal = 438952513; 
	return verify_case(RetVal, IOIString().countIOIs(mask)); }

int Test_(Case_<5>) {
	timer_clear();
	string mask_[] = {"OIO?"};
	  vector <string> mask(mask_, mask_+sizeof(mask_)/sizeof(*mask_)); 
	int RetVal = 1; 
	return verify_case(RetVal, IOIString().countIOIs(mask)); }

template<int N> void Run_() { cerr << "Test Case #" << N << "..." << flush; Test_(Case_<N>()); Run_<sizeof(Test_(Case_<N+1>()))==1 ? -1 : N+1>(); }
template<>      void Run_<-1>() {}
int main() { Run_<0>(); }
// END CUT HERE


// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// A string s is called an IOI string if it satisfies the following two conditions:

s contains only uppercase 'I' and uppercase 'O' letters.
There is at least one pair of non-negative integers (a,b) such that the a-th (0-indexed) character of s is 'I', the (a+b)-th character is 'O', and the (a+2*b)-th character is 'I'.

You are given a vector <string> mask. Concatenate the elements of mask to get one string. Each '?' character in mask can be replaced with either 'I' or 'O'.


Return the number of different IOI strings that can be formed, modulo 1,000,000,007 (1E9+7).


DEFINITION
Class:IOIString
Method:countIOIs
Parameters:vector <string>
Returns:int
Method signature:int countIOIs(vector <string> mask)


CONSTRAINTS
-mask will contain between 1 and 50 elements, inclusive.
-Each element of mask will contain between 1 and 50 characters, inclusive.
-Each character in mask will be uppercase 'I' or uppercase 'O' or '?'.


EXAMPLES

0)
{"IO?"}

Returns: 1

Two strings can be formed here : "IOI" and "IOO". Only "IOI" is an IOI string.

1)
{"????"}

Returns: 4

There are four IOI strings of length 4 : "IIOI", "IOII", "IOIO", and "OIOI".

2)
{"?II"}

Returns: 0

No IOI string can be formed from "?II".

3)
{"I??O??I"}

Returns: 16

Character 0 is 'I', character 3 is 'O', and character 6 is 'I'.
Therefore, all possible strings are IOI strings here.

4)
{"???I???????O???","???????????O??IO????????I???"}

Returns: 438952513

Don't forget to concatenate strings.

*/
// END CUT HERE
