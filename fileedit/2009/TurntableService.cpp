#line 2 "TurntableService.cpp"
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

vector<int> map_atoi(vector<string> nums)
{
  vector<int> vals(nums.size());
  for (int i=nums.size()-1; i>=0; i--) vals[i] = atoi(nums[i].c_str());
  return vals;
}

class TurntableService {
 public:
  int calculateTime(vector <string> favorites) {
	int n=sz(favorites); // 1-15
    int ful = (1<<n)-1;
    vector<vector<bool> > fav(n); //, eaten(n,0);
    rep(i,n){
      vi f = map_atoi(split(favorites[i]));
      fav[i].resize(n); rep(j,n) fav[i][j]=false;
      tr(f,it) fav[i][*it]=true;
    }
    //cout << "fav: " << fav << endl;
    set<int> s;
    priority_queue<int> pq; // sc[10?]<<20, {(ofs[4]<<16 | lastcmd[1])<<15 | eaten[15]}

    // eat front
    int eaten=0;
    for(int i=0,m=1;i<n;i++,m<<=1) if (fav[i][i]) eaten |= m;
    int nt=(15<<20)|32768|eaten;
    pq.push(-nt);
    // no eat
    pq.push(-32768);
    
    while(!pq.empty()){
      int t=-pq.top(); pq.pop();
      if (found(s,t&0xfffff)) continue;

      //cout << t << endl;
      int sc=t>>20, ofs=(t>>16)&15, eaten=t&0x7fff;
      //printf("sc:%lld, last:%lld, ofs:%lld, etn:%llx\n", sc,last,ofs,etn);
      s.insert(t&0xfffff);

      if (eaten == ful) return sc;

      if(t&32768){
        // no eat + turn [1..n-1]
        rep(nofs,n){
          int d=nofs-ofs; if(d==0) continue;
          if(d<0)d=-d; if (n<d*2) d=n-d;
          //int nt=((sc+1+d)<<20)|(nofs<<16)|32768|eaten;
          int nt=((sc+1+d)<<20)|nofs*65536|eaten;
          pq.push(-nt);
        }
      } else {
        // all eat front
        for(int i=0,e=ofs,m=1;i<n;i++,e=(e+1)%n,m<<=1) if (fav[i][e]) eaten |= m;
        //int nt=((sc+15)<<20)|(ofs<<16)|eaten;
        int nt=((sc+15)<<20)|ofs*65536|32768|eaten;
        pq.push(-nt);
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
	string favorites_[] = {"0 2", "1", "0 1"};
	  vector <string> favorites(favorites_, favorites_+sizeof(favorites_)/sizeof(*favorites_)); 
	int RetVal = 32; 
	return verify_case(RetVal, TurntableService().calculateTime(favorites)); }
int Test_(Case_<1>) {
	timer_clear();
	string favorites_[] = {"0", "0", "0"};
	  vector <string> favorites(favorites_, favorites_+sizeof(favorites_)/sizeof(*favorites_)); 
	int RetVal = 49; 
	return verify_case(RetVal, TurntableService().calculateTime(favorites)); }
int Test_(Case_<2>) {
	timer_clear();
	string favorites_[] = {"4", "1", "2", "3", "0"};
	  vector <string> favorites(favorites_, favorites_+sizeof(favorites_)/sizeof(*favorites_)); 
	int RetVal = 50; 
	return verify_case(RetVal, TurntableService().calculateTime(favorites)); }
int Test_(Case_<3>) {
	timer_clear();
	string favorites_[] = {"0 004", "2 3", "0 01", "1 2 3 4", "1 1"};
	  vector <string> favorites(favorites_, favorites_+sizeof(favorites_)/sizeof(*favorites_)); 
	int RetVal = 35; 
	return verify_case(RetVal, TurntableService().calculateTime(favorites)); }

int Test_(Case_<4>) { // #5
	timer_clear();
	string favorites_[] = {"2", "10", "12", "1", "5", "14", "7", "6", "13", "2", "9", "3", "11", "8", "0"};
    vector <string> favorites(favorites_, favorites_+sizeof(favorites_)/sizeof(*favorites_)); 
	int RetVal = 158;
	return verify_case(RetVal, TurntableService().calculateTime(favorites)); }
int Test_(Case_<5>) { // #6
	timer_clear();
	string favorites_[] = {"2", "10", "12", "1", "5", "14", "7", "6", "13", "9", "3", "11", "8", "0", "4"};
    vector <string> favorites(favorites_, favorites_+sizeof(favorites_)/sizeof(*favorites_)); 
	int RetVal = 173;
	return verify_case(RetVal, TurntableService().calculateTime(favorites)); }
int Test_(Case_<6>) { // #7
	timer_clear();
    string favorites_[] = {"2 8", "10 7 0", "12 2", "1 6", "5 4", "14 9", "7 8 1", "6 11 14", "13 10", "9 13", "3 5", "11 1", "8 13 2", "0 3", "4 12"};
    vector <string> favorites(favorites_, favorites_+sizeof(favorites_)/sizeof(*favorites_)); 
	int RetVal = 119;
	return verify_case(RetVal, TurntableService().calculateTime(favorites)); }

int Test_(Case_<7>) { // #17
	timer_clear();
    string favorites_[] = {"14 12", "13 10 12", "12 12", "11", "10", "9", "8", "7", "6", "5", "4", "3", "2", "1", "0"};
    vector <string> favorites(favorites_, favorites_+sizeof(favorites_)/sizeof(*favorites_)); 
	int RetVal = 236;
	return verify_case(RetVal, TurntableService().calculateTime(favorites)); }

int Test_(Case_<8>) { // #77
	timer_clear();
    string favorites_[] = {"2", "10", "14", "11", "0", "8", "12", "5", "13", "13", "5", "12", "12", "12", "6"};
    vector <string> favorites(favorites_, favorites_+sizeof(favorites_)/sizeof(*favorites_)); 
	int RetVal = 253;
	return verify_case(RetVal, TurntableService().calculateTime(favorites)); }

template<int N> void Run_() { cerr << "Test Case #" << N << "..." << flush; Test_(Case_<N>()); Run_<sizeof(Test_(Case_<N+1>()))==1 ? -1 : N+1>(); }
template<>      void Run_<-1>() {}
int main() { Run_<0>(); }
// END CUT HERE


// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// You are out for Chinese food with a bunch of friends. You are all sitting at a round table, and in the center of the table is a turntable onto which all of the entrees are placed. There is one entree immediately in front of each of you.

Each of you likes certain items, given as a vector <string> favorites, each element of which is a space delimited list of integers. Each integer corresponds to an entree, where 0 is the entree initially in front of person 0, etc.  Element i of favorites contains the indexes of all the entrees that person i likes. 

The turntable rotates in either direction.  When someone is serving himself, he can only take from the entree that is directly in front of him.  However, he is not required to take the entree presented to him, even if it is one of his favorites.

It takes 2 seconds to rotate the turntable by one position.  But, to rotate it by two positions takes 3 seconds, and in general it takes n+1 seconds to rotate the turntable by n positions.  It takes 15 seconds for a person to serve himself the entree in front of him.  If multiple people have favorite entrees in front of them, they can serve themselves simultaneously.  The turntable cannot be rotated while anyone is serving himself.

You are to return an int indicating the minimum number of seconds it takes for each person to have served himself one entree.



DEFINITION
Class:TurntableService
Method:calculateTime
Parameters:vector <string>
Returns:int
Method signature:int calculateTime(vector <string> favorites)


NOTES
-You may assume that each of the entrees on the turntable is unique.


CONSTRAINTS
-favorites will contain between 1 and 15 elements, inclusive.
-Each element of favorites will be a list of integers, separated by a single space, with no leading or trailing spaces.
-Each element of favorites will contain only digits ('0'-'9') and spaces (' ').
-Each element of favorites will contain between 1 and 50 characters, inclusive.
-Each number in each element of favorites will be between 0 and n - 1, inclusive, where n is the number of elements in favorites.  Leading zeros are permitted, and numbers may be repeated.


EXAMPLES

0)
{"0 2", "1", "0 1"}

Returns: 32

The first two people serve themselves immediately (15 seconds).  Then, we have to turn the turntable one unit, in either direction (2 seconds), so the last person can serve himself (another 15 seconds).  This takes 32 seconds.

1)
{"0", "0", "0"}

Returns: 49

Here, each person only likes one entree, so they have to be served one at a time.  Three servings (15 seconds each) and two single-unit rotations (2 seconds each) takes a total of 49 seconds.

2)
{"4", "1", "2", "3", "0"}

Returns: 50

First, the middle three people take their entrees (15 seconds).  Then, we rotate one unit--either way (2 seconds), serve the entree (15 seconds), and then rotate back two units (3 seconds) and serve the last person (15 seconds).  All together this takes 50 seconds.

3)
{"0 004", "2 3", "0 01", "1 2 3 4", "1 1"}

Returns: 35

Note here that leading zeros are permitted, and that elements may contain repeats.

*/
// END CUT HERE
