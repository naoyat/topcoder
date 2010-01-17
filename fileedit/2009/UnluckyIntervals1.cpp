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
    int N=sz(luckySet);
    sort(all(luckySet));
    priority_queue<pair<ll,int> > pq;
    tr(luckySet,it) pq.push(make_pair(0,-(*it)));
// BEGIN CUT HERE
    /*
    if (n<=N) {
      rep(i,n) res[i]=luckySet[i];
      return res;
    } else {
      rep(i,N) res[i]=luckySet[i];
      n -= N;
    }
    */
    cout << "ls: " << luckySet << ", n=" << n<< endl;
// END CUT HERE
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
    } else if (luckySet[0] == 2) {
      pq.push(make_pair(0,-1));
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
      } else {
        pq.push(make_pair(0,-a));
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
// BEGIN CUT HERE
        //z += p-m;
// END CUT HERE
        z = LONG_LONG_MAX; //10000000000LL + c;
// BEGIN CUT HERE
        //if (c) m--;
// END CUT HERE
        pq.push(make_pair(-z,-i));
      }
    }

    vi res;
    rep(i,n){
      pair<ll,int> pr = pq.top(); pq.pop();
      printf("- %lld : %d\n", -pr.first, -pr.second);
      res.pb(-pr.second);
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
/*
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
*/
int Test_(Case_<5>) {
	timer_clear();
	int luckySet_[] = {900534849, 431900333, 236426757, 336035476, 760889640, 134024802, 739683548, 694137081, 739667250};
    vector <int> luckySet(luckySet_, luckySet_+sizeof(luckySet_)/sizeof(*luckySet_)); 
	int n = 88; 
	int RetVal_[] = {134024802, 236426757, 336035476, 431900333, 694137081, 739667250, 739683548, 760889640, 900534849, 739667251, 739683547, 739667252, 739683546, 739667253, 739683545, 739667254, 739683544, 739667255, 739683543, 739667256, 739683542, 739667257, 739683541, 739667258, 739683540, 739667259, 739683539, 739667260, 739683538, 739667261, 739683537, 739667262, 739683536, 739667263, 739683535, 739667264, 739683534, 739667265, 739683533, 739667266, 739683532, 739667267, 739683531, 739667268, 739683530, 739667269, 739683529, 739667270, 739683528, 739667271, 739683527, 739667272, 739683526, 739667273, 739683525, 739667274, 739683524, 739667275, 739683523, 739667276, 739683522, 739667277, 739683521, 739667278, 739683520, 739667279, 739683519, 739667280, 739683518, 739667281, 739683517, 739667282, 739683516, 739667283, 739683515, 739667284, 739683514, 739667285, 739683513, 739667286, 739683512, 739667287, 739683511, 739667288, 739683510, 739667289, 739683509, 739667290};
    vector <int> RetVal(RetVal_, RetVal_+sizeof(RetVal_)/sizeof(*RetVal_)); 
	return verify_case(RetVal, UnluckyIntervals().getLuckiest(luckySet, n)); }
int Test_(Case_<6>) { //#9
	timer_clear();
	int luckySet_[] = {469825111, 162938444, 834816556, 61345101, 739600198, 986280760, 581242249, 14068091, 284202170, 936571762, 936558193, 66849434, 703492306, 59921355, 29754774, 258048991, 782356075, 218269017, 438747305, 858296565, 79002029, 378112910, 949230491, 509315948, 466691612, 947471482, 599532213, 633376623, 188254943, 259828453};
    vector <int> luckySet(luckySet_, luckySet_+sizeof(luckySet_)/sizeof(*luckySet_)); 
	int n = 91;
	int RetVal_[] = {14068091, 29754774, 59921355, 61345101, 66849434, 79002029, 162938444, 188254943, 218269017, 258048991, 259828453, 284202170, 378112910, 438747305, 466691612, 469825111, 509315948, 581242249, 599532213, 633376623, 703492306, 739600198, 782356075, 834816556, 858296565, 936558193, 936571762, 947471482, 949230491, 986280760, 936558194, 936571761, 936558195, 936571760, 936558196, 936571759, 936558197, 936571758, 936558198, 936571757, 936558199, 936571756, 936558200, 936571755, 936558201, 936571754, 936558202, 936571753, 936558203, 936571752, 936558204, 936571751, 936558205, 936571750, 936558206, 936571749, 936558207, 936571748, 936558208, 936571747, 936558209, 936571746, 936558210, 936571745, 936558211, 936571744, 936558212, 936571743, 936558213, 936571742, 936558214, 936571741, 936558215, 936571740, 936558216, 936571739, 936558217, 936571738, 936558218, 936571737, 936558219, 936571736, 936558220, 936571735, 936558221, 936571734, 936558222, 936571733, 936558223, 936571732, 936558224};
    vector <int> RetVal(RetVal_, RetVal_+sizeof(RetVal_)/sizeof(*RetVal_)); 
	return verify_case(RetVal, UnluckyIntervals().getLuckiest(luckySet, n)); }
int Test_(Case_<7>) {
	timer_clear();
	int luckySet_[] = {35497530, 9880208, 390531684, 372324005, 85099192, 142657156, 124562879, 193370319, 235690551, 79996481, 1349768, 29438793, 98742046, 127879127, 766446, 4843077, 170374848, 259079865, 65109444, 17666073, 17719108, 33761599, 56020222, 49883177, 1634400, 227418981};
    vector <int> luckySet(luckySet_, luckySet_+sizeof(luckySet_)/sizeof(*luckySet_)); 
	int n = 90; 
	int RetVal_[] = {766446, 1349768, 1634400, 4843077, 9880208, 17666073, 17719108, 29438793, 33761599, 35497530, 49883177, 56020222, 65109444, 79996481, 85099192, 98742046, 124562879, 127879127, 142657156, 170374848, 193370319, 227418981, 235690551, 259079865, 372324005, 390531684, 17666074, 17719107, 17666075, 17719106, 17666076, 17719105, 17666077, 17719104, 17666078, 17719103, 1349769, 1634399, 17666079, 17719102, 17666080, 17719101, 17666081, 17719100, 17666082, 17719099, 17666083, 17719098, 1349770, 1634398, 17666084, 17719097, 766447, 1349767, 17666085, 17719096, 17666086, 17719095, 17666087, 17719094, 1, 766445, 17666088, 17719093, 17666089, 17719092, 1349771, 1634397, 17666090, 17719091, 17666091, 17719090, 17666092, 17719089, 17666093, 17719088, 17666094, 17719087, 1349772, 1634396, 17666095, 17719086, 766448, 1349766, 17666096, 17719085, 17666097, 17719084, 17666098, 17719083};
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
