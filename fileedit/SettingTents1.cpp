#line 2 "SettingTents.cpp"
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

#define evenp(x) (((x)&1)==0)
#define oddp(x) (((x)&1)==1)

class SettingTents {
  int count(int w, int h){
    //if(w==h) return w;
    
    if(w<=h)swap(w,h); //w>=h
    int c=0;
    for(int x=w/2+1;x<=w;x++){
      for(int y=h/2+1;y<=h;y++){
        if(h*(2*y-h)==w*(2*x-w)){
          c+=2;
        }
      }
    }
    if(w==h)c--;
    
    for(int a=1;a<h/2;a++){
      for(int b=w/2+1;b<w;b++){
        if((h-2*a)*h==w*(2*b-w)){
          c+=2;
        }
      }
    }
    if(evenp(h) && evenp(w)) c++;

// BEGIN CUT HERE
    //printf("count(%d,%d)..%d\n", w,h,c);
// END CUT HERE
    return c;
  }
 public:
  int countSites(int N, int M) {
    int c=0;
    for(int w=1;w<=N;w++){
      for(int h=1;h<=M;h++){
// BEGIN CUT HERE
        /*
        printf("c += %d*%d*count(%d,%d) = %d*%d*%d = %d\n",
               N-w+1, M-h+1, w,h,
               N-w+1, M-h+1, count(w,h),
               (N-w+1)*(M-h+1)*count(w,h)
               );
        */
// END CUT HERE
        c+=(N-w+1)*(M-h+1)*count(w,h);
      }
    }
    return c;
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
	int N = 2; 
	int M = 2; 
	int RetVal = 6; 
	return verify_case(RetVal, SettingTents().countSites(N, M)); }
int Test_(Case_<1>) {
	timer_clear();
	int N = 1; 
	int M = 6; 
	int RetVal = 6; 
	return verify_case(RetVal, SettingTents().countSites(N, M)); }
int Test_(Case_<2>) {
	timer_clear();
	int N = 6; 
	int M = 8; 
	int RetVal = 527; 
	return verify_case(RetVal, SettingTents().countSites(N, M)); }
int Test_(Case_<3>) {
	timer_clear();
	int N = 100; 
	int M = 100; 
	int RetVal = 38235298;
	return verify_case(RetVal, SettingTents().countSites(N, M)); }
int Test_(Case_<4>) {
	timer_clear();
	int N = 1; 
	int M = 1; 
	int RetVal = 1; 
	return verify_case(RetVal, SettingTents().countSites(N, M)); }
int Test_(Case_<5>) {
	timer_clear();
	int N = 3; 
	int M = 3; 
	int RetVal = 22; 
	return verify_case(RetVal, SettingTents().countSites(N, M)); }

template<int N> void Run_() { cerr << "Test Case #" << N << "..." << flush; Test_(Case_<N>()); Run_<sizeof(Test_(Case_<N+1>()))==1 ? -1 : N+1>(); }
template<>      void Run_<-1>() {}
int main() { Run_<0>(); }
// END CUT HERE


// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
Once upon a time, there lived a migrant barbarian tribe.  Every time it settled down, a tent was set for the chief of the tribe.  First, an area was selected and divided into NxM squares with side lengths of 1 unit.  Then, they chose a site for the tent in such a way that every vertex of its base coincided with some vertex of one of the squares.  According to an ancient tradition, the base had to be a rhomb.  For example, there are all 6 different possible sites for the tent in a 2x2 area:



   
   

   
   



An example of a tent in a 4x2 area:


   




For a given N and M, return the number of different possible sites for the chief's tent.  Two sites are different if there is at least one vertex which belongs to one site but not the other.	



DEFINITION
Class:SettingTents
Method:countSites
Parameters:int, int
Returns:int
Method signature:int countSites(int N, int M)


NOTES
-A rhomb is a four-sided polygon with sides of equal length.
-The tent must have non-zero area.


CONSTRAINTS
-N will be between 1 and 100, inclusive.
-M will be between 1 and 100, inclusive.


EXAMPLES

0)
2
2

Returns: 6

The example from the problem statement.

1)
1
6

Returns: 6

The only possible sites are the squares of the area themselves.

2)
6
8

Returns: 527

*/
// END CUT HERE
