#line 2 "PageNumbers.cpp"
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

class PageNumbers {
  vector<int> res;

  void cu(int d) {
  }
  
 public:
  vector<int> getCounts(int N) {
    res.resize(10); rep(y,10) res[y]=0;
    vector<int> dg;
    int k=0,x=N;
    ll m=1LL;
    while(x){ dg.pb(x%10); k++; x/=10; m*=10;}
    m/=10;
    printf("N=%d ... k=%d,m=%d\n", N, k,(int)m);
    cout << dg << endl;

    int N_ = N,h=1;
    for(int d=k-1,n=m; d>=0; d--,n/=10){
      int di = dg[d];
      ll dn=(ll)d*n;
      printf("  %d ) <di:%d> d=%d  n=%d, d*n=%d\n", N_, di,d,n, (int)dn);
      if (di>0) {
        for(int i=h;i<di;i++) {
          res[i] += n;
          rep(y,10) res[y] += (int)(dn / 10);
        }
        for(int i=1;i<=d;i++){
          rep(y,10) res[y] += d;
        }
        //      printf("  N_ - dd=%d <%d> n=%d, di=%d,dn=%d\n", d,dg[d],n, di,(int)dn);
        printf("(N_ - di * n) + 1 = %d\n", (N_ - di * n) + 1);
        res[di] += (N_ - di * n) + 1;
        
        cout  << res << endl;
        N_ -= di * n; h=0;
      }
    }
    return res;
  }
};

// BEGIN CUT HERE
#include <time.h>
clock_t start_time;
void timer_clear() { start_time = clock(); }
string timer() { clock_t end_time = clock(); double interval = (double)(end_time - start_time)/CLOCKS_PER_SEC; ostringstream os; os << " (" << interval*1000 << " msec)"; return os.str(); }

template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
int verify_case(const vector <int> &Expected, const vector <int> &Received) { if (Expected == Received) cerr << "PASSED" << timer() << endl; else { cerr << "FAILED" << timer() << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } return 0;}

template<int N> struct Case_ {};
char Test_(...);
int Test_(Case_<0>) {
	timer_clear();
	int N = 7; 
	int RetVal_[] = {0, 1, 1, 1, 1, 1, 1, 1, 0, 0 };
	  vector <int> RetVal(RetVal_, RetVal_+sizeof(RetVal_)/sizeof(*RetVal_)); 
	return verify_case(RetVal, PageNumbers().getCounts(N)); }
int Test_(Case_<1>) {
	timer_clear();
	int N = 11; 
	int RetVal_[] = {1, 4, 1, 1, 1, 1, 1, 1, 1, 1 };
	  vector <int> RetVal(RetVal_, RetVal_+sizeof(RetVal_)/sizeof(*RetVal_)); 
	return verify_case(RetVal, PageNumbers().getCounts(N)); }
int Test_(Case_<2>) {
	timer_clear();
	int N = 19; 
	int RetVal_[] = {1, 12, 2, 2, 2, 2, 2, 2, 2, 2 };
	  vector <int> RetVal(RetVal_, RetVal_+sizeof(RetVal_)/sizeof(*RetVal_)); 
	return verify_case(RetVal, PageNumbers().getCounts(N)); }
int Test_(Case_<3>) {
	timer_clear();
	int N = 999; 
	int RetVal_[] = {189, 300, 300, 300, 300, 300, 300, 300, 300, 300 };
	  vector <int> RetVal(RetVal_, RetVal_+sizeof(RetVal_)/sizeof(*RetVal_)); 
	return verify_case(RetVal, PageNumbers().getCounts(N)); }
int Test_(Case_<4>) {
	timer_clear();
	int N = 543212345; 
	int RetVal_[] = {429904664, 541008121, 540917467, 540117067, 533117017, 473117011, 429904664, 429904664, 429904664, 429904664 };
	  vector <int> RetVal(RetVal_, RetVal_+sizeof(RetVal_)/sizeof(*RetVal_)); 
	return verify_case(RetVal, PageNumbers().getCounts(N)); }
int Test_(Case_<5>) {
	timer_clear();
	int N = 1000000000;
	int RetVal_[] = {429904664, 541008121, 540917467, 540117067, 533117017, 473117011, 429904664, 429904664, 429904664, 429904664 };
	  vector <int> RetVal(RetVal_, RetVal_+sizeof(RetVal_)/sizeof(*RetVal_)); 
	return verify_case(RetVal, PageNumbers().getCounts(N)); }

template<int N> void Run_() { cerr << "Test Case #" << N << "..." << flush; Test_(Case_<N>()); Run_<sizeof(Test_(Case_<N+1>()))==1 ? -1 : N+1>(); }
template<>      void Run_<-1>() {}
int main() { Run_<0>(); }
// END CUT HERE


// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
We have a book with N pages, numbered 1 to N.
How many times does each digit occur in the page numbers?



You are given an int N. Return a vector <int> with 10 elements, where for all i between 0 and 9, inclusive, the element i will be the number of times digit i occurs when we write down all the numbers between 1 and N, inclusive.


DEFINITION
Class:PageNumbers
Method:getCounts
Parameters:int
Returns:vector <int>
Method signature:vector <int> getCounts(int N)


NOTES
-You may assume that for any valid input each of the output values fits into an int.


CONSTRAINTS
-N will be between 1 and 1,000,000,000, inclusive.


EXAMPLES

0)
7

Returns: {0, 1, 1, 1, 1, 1, 1, 1, 0, 0 }

The page numbers in this case are simply 1, 2, 3, 4, 5, 6, and 7.

1)
11

Returns: {1, 4, 1, 1, 1, 1, 1, 1, 1, 1 }

In comparison to the previous case, we added the pages 8, 9, 10, and 11. Now we have each digit exactly once, except for the digit 1 that occurs four times: once in 1 and 10, and twice in 11.

2)
19

Returns: {1, 12, 2, 2, 2, 2, 2, 2, 2, 2 }

Digits 2 to 9 now occur twice each, and we have plenty of occurrences of the digit 1.

3)
999

Returns: {189, 300, 300, 300, 300, 300, 300, 300, 300, 300 }

Due to symmetry, each of the digits 1 to 9 occurs equally many times in the sequence 1,2,...,999.

4)
543212345

Returns: {429904664, 541008121, 540917467, 540117067, 533117017, 473117011, 429904664, 429904664, 429904664, 429904664 }

Watch out for the time limit.

*/
// END CUT HERE
