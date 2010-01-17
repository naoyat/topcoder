#line 2 "MNS.cpp"
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
#define FOR(var,from,to) for(int var=(from);var<=(to);var++)
#define rep(var,n)  for(int var=0;var<(n);var++)
#define all(c)  (c).begin(),(c).end()
#define tr(c,i)  for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); i++)
#define found(s,e)  ((s).find(e)!=(s).end())
#define mset(arr,val)  memset(arr,val,sizeof(arr))

class MNS {
  vector<int>ns;
  int th;

  map<int,set<int> > mm;
  set<int> pat;
  int goal;

  
  void sub(int m1,int m2,int m3){
    tr(mm[m1],t1){
      tr(mm[m2],t2){
        tr(mm[m3],t3){
          if (*t1 + *t2 + *t3 == goal) {
            pat.insert((*t1 << 16) | *t2);
          }
        }
      }
    }
  }
  
  void check(int m1,int m2,int m3){
    sub(m1,m2,m3); sub(m1,m3,m2);
    sub(m2,m3,m1); sub(m2,m1,m3);
    sub(m3,m1,m2); sub(m3,m2,m1);
  }

 public:
  int combos(vector <int> numbers) {
    ns=numbers;
    
	int sum=0; rep(i,9)sum+=numbers[i];
    if (sum%3) return 0;
    th=sum/3;

    set<int> tri;

    mm.clear();
    FOR(i,0,6){
      FOR(j,i+1,7){
        FOR(k,j+1,8){
          int m = (1<<i) | (1<<j) | (1<<k);
          int a=numbers[i], b=numbers[j], c=numbers[k];
          if (a+b+c == th) {
            tri.insert( m );
            set<int> s;
            s.insert((a<<10)|(b<<5)|c);
            s.insert((a<<10)|(c<<5)|b);
            s.insert((b<<10)|(c<<5)|a);
            s.insert((b<<10)|(a<<5)|c);
            s.insert((c<<10)|(a<<5)|b);
            s.insert((c<<10)|(b<<5)|a);
            mm[m] = s;
          }
        }
      }
    }
    //cout << tri << endl;
    vector<int> tv(all(tri)); int n = sz(tv);

    // map<int,set<int> > mm;

    pat.clear();
    goal = th*(1024+32+1);
    //cout << triv << endl;
    FOR(i,0,n-3){
      FOR(j,i+1,n-2){ if (tv[i]&tv[j]) continue;
        FOR(k,j+1,n-1){ if (tv[k]&(tv[i]|tv[j])) continue;
          check(tv[i],tv[j],tv[k]);
        }
      }
    }
    
    return sz(pat);
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
	int numbers_[] = {1,2,3,3,2,1,2,2,2};
	  vector <int> numbers(numbers_, numbers_+sizeof(numbers_)/sizeof(*numbers_)); 
	int RetVal = 18; 
	return verify_case(RetVal, MNS().combos(numbers)); }
int Test_(Case_<1>) {
	timer_clear();
	int numbers_[] = {4,4,4,4,4,4,4,4,4};
	  vector <int> numbers(numbers_, numbers_+sizeof(numbers_)/sizeof(*numbers_)); 
	int RetVal = 1; 
	return verify_case(RetVal, MNS().combos(numbers)); }
int Test_(Case_<2>) {
	timer_clear();
	int numbers_[] = {1,5,1,2,5,6,2,3,2};
	  vector <int> numbers(numbers_, numbers_+sizeof(numbers_)/sizeof(*numbers_)); 
	int RetVal = 36; 
	return verify_case(RetVal, MNS().combos(numbers)); }
int Test_(Case_<3>) {
	timer_clear();
	int numbers_[] = {1,2,6,6,6,4,2,6,4};
	  vector <int> numbers(numbers_, numbers_+sizeof(numbers_)/sizeof(*numbers_)); 
	int RetVal = 0; 
	return verify_case(RetVal, MNS().combos(numbers)); }
int Test_(Case_<4>) {
	timer_clear();
	int numbers_[] = {0,1,2,3,4,5,6,7,8};
	  vector <int> numbers(numbers_, numbers_+sizeof(numbers_)/sizeof(*numbers_)); 
	int RetVal = 72; 
	return verify_case(RetVal, MNS().combos(numbers)); }

template<int N> void Run_() { cerr << "Test Case #" << N << "..." << flush; Test_(Case_<N>()); Run_<sizeof(Test_(Case_<N+1>()))==1 ? -1 : N+1>(); }
template<>      void Run_<-1>() {}
int main() { Run_<0>(); }
//211.06
// END CUT HERE


// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
9 numbers need to be arranged in a magic number square.  A magic number square is a square of numbers that is arranged such that every row and column has the same sum.  For example:


1 2 3
3 2 1
2 2 2


Create a class MNS containing a method combos which takes as an argument a vector <int> numbers and returns the number of distinct ways those numbers can be arranged in a magic number square.  Two magic number squares are distinct if they differ in value at one or more positions.  For example, there is only one magic number square that can be made of 9 instances of the same number.


DEFINITION
Class:MNS
Method:combos
Parameters:vector <int>
Returns:int
Method signature:int combos(vector <int> numbers)


NOTES
-Unlike some versions of the magic number square, the numbers do not have to be unique.


CONSTRAINTS
-numbers will contain exactly 9 elements.
-each element of numbers will be between 0 and 9, inclusive.


EXAMPLES

0)
{1,2,3,3,2,1,2,2,2}

Returns: 18

1)
{4,4,4,4,4,4,4,4,4}

Returns: 1

2)
{1,5,1,2,5,6,2,3,2}

Returns: 36

3)
{1,2,6,6,6,4,2,6,4}

Returns: 0

*/
// END CUT HERE
