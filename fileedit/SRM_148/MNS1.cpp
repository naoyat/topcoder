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

class MNS {
  vector<int>ns;
  int th;
  int third(int mask,int x,int y,int z){
    //set<int> ghi;
    int cnt=0;
    FOR(i,0,8){ if(mask&(1<<i)) continue;
      if (ns[i]!=x)continue;
      FOR(j,i+1,8){ if(mask&(1<<j)) continue;
        if (ns[j]!=x)continue;
        FOR(k,j+1,8){ if(mask&(1<<k)) continue;
          if (ns[k]!=x)continue;
          //if(numbers[i]+numbers[j]+numbers[k]!=th) continue;
          //int key = 100*ns[i] + 10*ns[j] + ns[k];
          //ghi.insert(key);
          printf("      <3> %d:%d %d:%d %d:%d => %d\n", i,ns[i], j,ns[j], k,ns[k], cnt);
          //printf("   third(%d, %d,%d,%d): %d %d %d\n", mask,x,y,z, ns[i],ns[j],ns[k]);
          cnt++;
        }
      }
    }
    return cnt;
  }
  int second(int mask,int a,int b,int c){
    int cnt=0;
    FOR(i,0,8){ if(mask&(1<<i)) continue;
      FOR(j,i+1,8){ if(mask&(1<<j)) continue;
        FOR(k,j+1,8){ if(mask&(1<<k)) continue;
          if(ns[i]+ns[j]+ns[k]!=th) continue;
          //int key = 100*ns[i] + 10*ns[j] + ns[k];
          cnt += third(mask|(1<<i)|(1<<j)|(1<<k),th-ns[i],th-ns[j],th-ns[k]);
          printf("    <2> %d:%d %d:%d %d:%d => %d\n", i,ns[i], j,ns[j], k,ns[k], cnt);
        }
      }
    }
    printf("  second(%d, %d,%d,%d) => %d\n", mask, a,b,c, cnt);
    return cnt;
  }
 public:
  int combos(vector <int> numbers) {
	int sum=0; rep(i,9)sum+=numbers[i];
    if (sum%3) return 0;
    ns=numbers;
    th=sum/3;

    int cnt=0;
    FOR(i,0,8){
      FOR(j,i+1,8){
        FOR(k,j+1,8){
          if(numbers[i]+numbers[j]+numbers[k]!=th) continue;
          cnt += second((1<<i)|(1<<j)|(1<<k),i,j,k);
          printf("  <1> %d:%d %d:%d %d:%d => %d\n", i,ns[i], j,ns[j], k,ns[k], cnt);
        }
      }
    }
    return cnt;
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

template<int N> void Run_() { cerr << "Test Case #" << N << "..." << flush; Test_(Case_<N>()); Run_<sizeof(Test_(Case_<N+1>()))==1 ? -1 : N+1>(); }
template<>      void Run_<-1>() {}
int main() { Run_<0>(); }
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
