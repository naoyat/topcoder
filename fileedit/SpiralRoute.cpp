// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// The King of Elbonia lives in a palace that is width meters by length meters. Since he makes his subjects live in mud, he is not very popular. He wants the palace partitioned so that visitors have to walk a long way to reach him. His security advisors have settled on a spiral. A visitor enters the palace at the South-West corner and starts walking East. Every time the visitor reaches an outer wall or his own path, he turns left. The corridors in the spiral are 1 meter wide. The diagram below shows an example of a spiral path: the visitor moves from a (the South-West corner) through the alphabet to x, the throne.

nmlkji
oxwvuh
pqrstg
abcdef

The King wants to have his throne correctly placed before all the partitioning is done, so he needs to know where the spiral will end. Write a class SpiralRoute with a method thronePosition that returns two integers, indicating the coordinates of the throne. The South-West corner is (0, 0), the South-East corner is (width - 1, 0) and the North-East corner is (width - 1, length - 1).


DEFINITION
Class:SpiralRoute
Method:thronePosition
Parameters:int, int
Returns:vector <int>
Method signature:vector <int> thronePosition(int width, int length)


CONSTRAINTS
-width and length will both be between 1 and 5000, inclusive.


EXAMPLES

0)
6
4

Returns: {1, 2 }

This is the example above.

1)
6
5

Returns: {3, 2 }



2)
1
11

Returns: {0, 10 }



3)
12
50

Returns: {5, 6 }



4)
5000
5000

Returns: {2499, 2500 }



*/
// END CUT HERE

#line 72 "SpiralRoute.cpp"
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

// BEGIN CUT HERE
#define sz(a)  int((a).size())
#define pb  push_back
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
// END CUT HERE

class SpiralRoute {
 public:
  vector<int> thronePosition(int w, int l) {
    int xmax=w-1, ymax=l-1, xmin=0, ymin=0;
    vector<int> ans(2,0);
    while(w>2 && l>2){
      w-=2; l-=2; xmax--; ymax--; xmin++; ymin++;
    }
// BEGIN CUT HERE
    //    printf("(%d,%d) %d-%d, %d-%d\n", w,l, xmin,xmax, ymin,ymax);
// END CUT HERE
    if(w==l){
      ans[0]=xmin;
      ans[1]=(w==2)?ymax:ymin;
    }else if(w>l){
      ans[0]=(l==1)?xmax:xmin;
      ans[1]=ymax;
    }else{
      ans[0]=xmin;
      ans[1]=(w==1)?ymax:(ymin+1);
    }
    return ans;
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
	int width = 6; 
	int length = 4; 
	int RetVal_[] = {1, 2 };
	  vector <int> RetVal(RetVal_, RetVal_+sizeof(RetVal_)/sizeof(*RetVal_)); 
	return verify_case(RetVal, SpiralRoute().thronePosition(width, length)); }
int Test_(Case_<1>) {
	timer_clear();
	int width = 6; 
	int length = 5; 
	int RetVal_[] = {3, 2 };
	  vector <int> RetVal(RetVal_, RetVal_+sizeof(RetVal_)/sizeof(*RetVal_)); 
	return verify_case(RetVal, SpiralRoute().thronePosition(width, length)); }
int Test_(Case_<2>) {
	timer_clear();
	int width = 1; 
	int length = 11; 
	int RetVal_[] = {0, 10 };
	  vector <int> RetVal(RetVal_, RetVal_+sizeof(RetVal_)/sizeof(*RetVal_)); 
	return verify_case(RetVal, SpiralRoute().thronePosition(width, length)); }
int Test_(Case_<3>) {
	timer_clear();
	int width = 12; 
	int length = 50; 
	int RetVal_[] = {5, 6 };
	  vector <int> RetVal(RetVal_, RetVal_+sizeof(RetVal_)/sizeof(*RetVal_)); 
	return verify_case(RetVal, SpiralRoute().thronePosition(width, length)); }
int Test_(Case_<4>) {
	timer_clear();
	int width = 5000; 
	int length = 5000; 
	int RetVal_[] = {2499, 2500 };
	  vector <int> RetVal(RetVal_, RetVal_+sizeof(RetVal_)/sizeof(*RetVal_)); 
	return verify_case(RetVal, SpiralRoute().thronePosition(width, length)); }

template<int N> void Run_() { cerr << "Test Case #" << N << "..." << flush; Test_(Case_<N>()); Run_<sizeof(Test_(Case_<N+1>()))==1 ? -1 : N+1>(); }
template<>      void Run_<-1>() {}
int main() { Run_<0>(); }
// END CUT HERE

