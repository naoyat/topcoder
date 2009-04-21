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

#define sz(a)  int((a).size())
#define tr(c,i)  for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); i++)
#define all(c)  (c).begin(),(c).end()
#define evenp(x) (((x)&1)==0)
#define oddp(x) (((x)&1)==1)

class SettingTents {
  int count(int w, int h){
    double cx=0.5*w, cy=0.5*h;
    int c=0;
    int x0=0,x2=w;
    set<pair<pair<int,int>,pair<int,int> > > cnt;
// BEGIN CUT HERE
    //set<vector<pair<double,pair<int,int> > > > cnt;
// END CUT HERE
    for(int y0=0;y0<=h;y0++){
// BEGIN CUT HERE
      // (x0:0, y0:[0..h/2])
      // (x2:w, y2:[h..h/2]=h-y0)
// END CUT HERE
      int y2=h-y0;
      if(y2==y0) continue;
      for(int x1=0;x1<=w;x1++){
        int x3=w-x1;
        if(x1==x3) continue;
        int rhs=w*(2*x1-w);
        int l=2*y0-h;
        if(abs(rhs)%abs(l)) continue;
        int yy=rhs/l+h; // 2y
        if(oddp(yy)) continue;
        int y1=yy/2, y3=h-y1;
// BEGIN CUT HERE
        //printf("  (%d,%d)-(%d,%d)-(%d,%d)-(%d,%d)..\n",x0,y0,x1,y1,x2,y2,x3,y3);
        // (y-y0) = (y2-y0)/w (x-x0)
        // y = y0 + (y2-y0)/w (x-x0)
        //double y=1.0*(y2-y0)*(x1-x0)/w + y0;
        //if(y1<y) continue;
        //if(y1>y3)continue;
        //if(y1>y3) {swap(y1,y3);swap(x1,x3);}
// END CUT HERE
        if(y1<0 || h<y1) continue;
        if(y0*y1*y2*y3>0) continue;
        if(x0==x1 && y0==y1) continue;
        if(x2==x1 && y2==y1) continue;
        if(x3==x1 && y3==y1) continue;
// BEGIN CUT HERE
        /*
        if(y0<h/2){
          if(x1<w/2 || y1>h/2) continue;
        }else{
          if(x1>w/2 || y1>h/2) continue;
        }
        */
// END CUT HERE
        vector<pair<double,pair<int,int> > > v(4);
        v[0] = make_pair(atan2(-cy+y0,-cx+x0), make_pair(x0,y0));
        v[1] = make_pair(atan2(-cy+y1,-cx+x1), make_pair(x1,y1));
        v[2] = make_pair(atan2(-cy+y2,-cx+x2), make_pair(x2,y2));
        v[3] = make_pair(atan2(-cy+y3,-cx+x3), make_pair(x3,y3));
// BEGIN CUT HERE
        /*
        cout << v << endl;
        sort(all(v));
        cout << v << endl;
        */
// END CUT HERE
        sort(all(v));
        cnt.insert(make_pair(v[0].second, v[1].second));
// BEGIN CUT HERE
        //printf("(%d,%d) - (%d,%d)\n", x0,y0, x1,y1);
        //if(y0>0 && y1>0) continue;
        //if(x1==0&&y1==y0) continue;
        //(0-w/2,y0-h/2)*(x1-w/2,y1-h/2)
        //=(-w,2y0-h)*(2x1-w,2y1-h)
        //= -w(2x1-w)+(2y0-h)(2y1-h)
        //if((2*y0-h)*(2*y1-h)-w*(2*x1-w)==0){
        //c++;
// END CUT HERE
      }
    }
    c = cnt.size();
// BEGIN CUT HERE
    /*
    tr(cnt,it){
      cout << *it << endl;
    }
    */
    //printf("  %d => %d\n", c, c/2);
    //c*=2;
// END CUT HERE
    if(evenp(w) && evenp(h)) c++;
// BEGIN CUT HERE
    //printf("count(%d,%d)..%d\n", w,h,c);
// END CUT HERE
    return c;
  }
 public:
  int countSites(int N, int M) {
    int c=0;
    for(int w=1;w<=N;w++)
      for(int h=1;h<=M;h++)
        c+=(N-w+1)*(M-h+1)*count(w,h);
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
/*
*/
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
