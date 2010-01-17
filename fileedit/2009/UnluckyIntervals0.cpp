#line 2 "UnluckyIntervals.cpp"
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

class UnluckyIntervals {
 public:
  vector<int> getLuckiest(vector<int> luckySet, int n) {
    vi res(n,-1);
    int N=sz(luckySet);
    if (n<=N) {
      rep(i,n) res[i]=luckySet[i];
      return res;
    } else {
      rep(i,N) res[i]=luckySet[i];
      n -= N;
    }
// BEGIN CUT HERE
    //cout << "ls: " << luckySet << ", n=" << n<< endl;
// END CUT HERE

	vvi iz;
    priority_queue<pair<ll,int> > pq;

    if (luckySet[0] >= 3) {
      int a=1, b=luckySet[0]-1, w=b;
// BEGIN CUT HERE
      // vi x(3); x[0]=w; x[1]=1; x[2]=b; iz.pb(x);
      //printf("[%d, %d, %d]\n", w,a,b);
// END CUT HERE
      ll z=0;
      for(int c=0,i=a,j=b,p=w-1,m=0; i<=j; c+=2,i++,j--,p--) {
        if (c>n) break;
        z += p-m;
        if (c) m--;
        pq.push(make_pair(-z,-i));
        if (i!=j) pq.push(make_pair(-z,-j));
      }
    }
    rep(i,N-1){
      int a=luckySet[i]+1, b=luckySet[i+1]-1, w=b-a+1;
      if (a<b) {
// BEGIN CUT HERE
        //printf("[%d, %d, %d]\n", w,a,b);
        //vi x(3); x[0]=w; x[1]=a; x[2]=b; iz.pb(x);
// END CUT HERE
        ll z=0;
        for(int c=0,i=a,j=b,p=w-1,m=0; i<=j; c+=2,i++,j--,p--) {
          if (c>n) break;
          z += p-m;
          if (c) m--;
          pq.push(make_pair(-z,-i));
          if (i!=j) pq.push(make_pair(-z,-j));
        }
      }
    }
    {
      int a=luckySet[N-1]+1;
// BEGIN CUT HERE
      //printf("[++, %d, ++]\n", a);
      //vi x(3,b-a+1); x[1]=a; x[2]=b; iz.pb(x);
// END CUT HERE
      ll z=0;
      for(int c=0,i=a; c<n; c++,i++) {
        if (c>n) break;
        //z += p-m;
        z = 10000000000LL + c;
        //if (c) m--;
        pq.push(make_pair(-z,-i));
      }
    }

    rep(i,n){
      pair<ll,int> pr = pq.top(); pq.pop();
      res[N+i] = -pr.second;
    }
// BEGIN CUT HERE
    /*
    while(!pq.empty()){
      pair<ll,int> pr = pq.top();
      pq.pop();
      cout << "- " << -pr.second << endl;
    }
    */
// END CUT HERE
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
	int luckySet_[] = {3};
	  vector <int> luckySet(luckySet_, luckySet_+sizeof(luckySet_)/sizeof(*luckySet_)); 
	int n = 6; 
	int RetVal_[] = {3, 1, 2, 4, 5, 6 };
	  vector <int> RetVal(RetVal_, RetVal_+sizeof(RetVal_)/sizeof(*RetVal_)); 
	return verify_case(RetVal, UnluckyIntervals().getLuckiest(luckySet, n)); }
int Test_(Case_<1>) {
	timer_clear();
	int luckySet_[] = {5, 11, 18};
	  vector <int> luckySet(luckySet_, luckySet_+sizeof(luckySet_)/sizeof(*luckySet_)); 
	int n = 9; 
	int RetVal_[] = {5, 11, 18, 1, 4, 6, 10, 2, 3 };
	  vector <int> RetVal(RetVal_, RetVal_+sizeof(RetVal_)/sizeof(*RetVal_)); 
	return verify_case(RetVal, UnluckyIntervals().getLuckiest(luckySet, n)); }
int Test_(Case_<2>) {
	timer_clear();
	int luckySet_[] = {7, 13, 18};
	  vector <int> luckySet(luckySet_, luckySet_+sizeof(luckySet_)/sizeof(*luckySet_)); 
	int n = 9; 
	int RetVal_[] = {7, 13, 18, 14, 17, 8, 12, 1, 6 };
	  vector <int> RetVal(RetVal_, RetVal_+sizeof(RetVal_)/sizeof(*RetVal_)); 
	return verify_case(RetVal, UnluckyIntervals().getLuckiest(luckySet, n)); }
int Test_(Case_<3>) {
	timer_clear();
	int luckySet_[] = {1000, 1004, 4000, 4003, 5000};
	  vector <int> luckySet(luckySet_, luckySet_+sizeof(luckySet_)/sizeof(*luckySet_)); 
	int n = 19; 
	int RetVal_[] = {1000, 1004, 4000, 4003, 5000, 4001, 4002, 1001, 1003, 1002, 4004, 4999, 1, 999, 4005, 4998, 2, 998, 4006 };
	  vector <int> RetVal(RetVal_, RetVal_+sizeof(RetVal_)/sizeof(*RetVal_)); 
	return verify_case(RetVal, UnluckyIntervals().getLuckiest(luckySet, n)); }
int Test_(Case_<4>) {
	timer_clear();
	int luckySet_[] = {1000000000};
	  vector <int> luckySet(luckySet_, luckySet_+sizeof(luckySet_)/sizeof(*luckySet_)); 
	int n = 8; 
	int RetVal_[] = {1000000000, 1, 999999999, 2, 999999998, 3, 999999997, 4 };
	  vector <int> RetVal(RetVal_, RetVal_+sizeof(RetVal_)/sizeof(*RetVal_)); 
	return verify_case(RetVal, UnluckyIntervals().getLuckiest(luckySet, n)); }

int Test_(Case_<5>) {
	timer_clear();
	int luckySet_[] = {1000000000};
	  vector <int> luckySet(luckySet_, luckySet_+sizeof(luckySet_)/sizeof(*luckySet_)); 
	int n = 50; 
	int RetVal_[] = {1000000000, 1, 999999999, 2, 999999998, 3, 999999997, 4 };
	  vector <int> RetVal(RetVal_, RetVal_+sizeof(RetVal_)/sizeof(*RetVal_)); 
	return verify_case(RetVal, UnluckyIntervals().getLuckiest(luckySet, n)); }
int Test_(Case_<6>) {
	timer_clear();
	int luckySet_[] = {2};
	  vector <int> luckySet(luckySet_, luckySet_+sizeof(luckySet_)/sizeof(*luckySet_)); 
	int n = 50; 
	int RetVal_[] = {1000000000, 1, 999999999, 2, 999999998, 3, 999999997, 4 };
	  vector <int> RetVal(RetVal_, RetVal_+sizeof(RetVal_)/sizeof(*RetVal_)); 
	return verify_case(RetVal, UnluckyIntervals().getLuckiest(luckySet, n)); }
int Test_(Case_<7>) {
	timer_clear();
	int luckySet_[] = {1,3,5};
	  vector <int> luckySet(luckySet_, luckySet_+sizeof(luckySet_)/sizeof(*luckySet_)); 
	int n = 1; 
	int RetVal_[] = {1};
	  vector <int> RetVal(RetVal_, RetVal_+sizeof(RetVal_)/sizeof(*RetVal_)); 
	return verify_case(RetVal, UnluckyIntervals().getLuckiest(luckySet, n)); }

template<int N> void Run_() { cerr << "Test Case #" << N << "..." << flush; Test_(Case_<N>()); Run_<sizeof(Test_(Case_<N+1>()))==1 ? -1 : N+1>(); }
template<>      void Run_<-1>() {}
int main() { Run_<0>(); }
// END CUT HERE


// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// You are given a set of integers called luckySet.  An interval [A,B], where B is greater than A, and A and B are positive integers, is considered unlucky if none of the integers between A and B, inclusive, belongs to luckySet.

An integer x is considered to be luckier than another integer y if the number of unlucky intervals that contain x is smaller than the number of unlucky intervals that contain y.  In case both x and y belong to an equal number of unlucky intervals, or both belong to an infinite number of unlucky intervals, the smallest of them is considered to be luckier than the other.

Given a vector <int> luckySet, return the top n luckiest positive integers sorted in descending order by luckiness (in other words, each element of the vector <int> must be luckier than the next element).

DEFINITION
Class:UnluckyIntervals
Method:getLuckiest
Parameters:vector <int>, int
Returns:vector <int>
Method signature:vector <int> getLuckiest(vector <int> luckySet, int n)


CONSTRAINTS
-luckySet will contain between 1 and 50 elements, inclusive.
-Each element of luckySet will be between 1 and 1000000000, inclusive.
-Each element of luckySet will be distinct.
-n will be between 1 and 100, inclusive.


EXAMPLES

0)
{3}
6

Returns: {3, 1, 2, 4, 5, 6 }

0 unlucky intervals contain 3.
1 unlucky interval contains 1: [1,2].
1 unlucky interval contains 2: [1, 2].
Since 1 and 2 are inside an equal number of intervals, 1 is considered luckier because it is less than 2.
For every number greater than 3, there is an infinite number of unlucky intervals that contain it. However, 4 and 5 are considered to be the luckiest among them, as they are smallest.

1)
{5, 11, 18}
9

Returns: {5, 11, 18, 1, 4, 6, 10, 2, 3 }

3 unlucky intervals: [1,2], [1,3] and [1,4] include 1. 
3 unlucky intervals: [1,4], [2,4] and [3,4] include 4. 
4 unlucky intervals: [6,7], [6,8], [6,9] and [6,10] include 6. 
4 unlucky intervals: [6,10], [7,10], [8,10] and [9,10] include 10. 
5 unlucky intervals: [1,2], [1,3], [1,4], [2,3] and [2,4] include 2. 
5 unlucky intervals: [1,3], [1,4], [2,3], [2,4] and [3,4] include 3. 



2)
{7, 13, 18}
9

Returns: {7, 13, 18, 14, 17, 8, 12, 1, 6 }



3)
{1000, 1004, 4000, 4003, 5000}
19

Returns: {1000, 1004, 4000, 4003, 5000, 4001, 4002, 1001, 1003, 1002, 4004, 4999, 1, 999, 4005, 4998, 2, 998, 4006 }



4)
{1000000000}
8

Returns: {1000000000, 1, 999999999, 2, 999999998, 3, 999999997, 4 }



*/
// END CUT HERE
