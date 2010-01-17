#line 2 "BedroomFloor.cpp"
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

class BedroomFloor {
 public:
  int cross(int x1,int y1,int x2,int y2, int x3,int y3,int x4,int y4){
    int x5=max(x1,x3), y5=max(y1,y3);
    int x6=min(x2,x4), y6=min(y2,y4);
    return (x5<x6 && y5<y6)? (x6-x5)*(y6-y5) :0;
  }
  void check(vector<long long>&cnt, int x1,int y1,int x2,int y2, int rep=1){
    if (x1==x2 || y1==y2) return;
    vector<long long> mycnt(6,0);
    rep(i,5){
      mycnt[cross(x1,y1,x2,y2, 0,i,5,i+1)]++;
      mycnt[cross(x1,y1,x2,y2, 5,5+i,10,6+i)]++;
      mycnt[cross(x1,y1,x2,y2, 5+i,0,6+i,5)]++;
      mycnt[cross(x1,y1,x2,y2, i,5,i+1,10)]++;
    }
    mycnt[0]=0;
// BEGIN CUT HERE
    printf("(%d,%d)-(%d,%d) <%d> : ", x1,y1,x2,y2, rep);
    cout << mycnt << endl;
// END CUT HERE
    for(int i=1;i<=5;i++) cnt[i]+=mycnt[i]*rep;
  }
  long long numberOfSticks(int x1, int y1, int x2, int y2) {
    vector<long long> cnt(6,0);
    int xa=(x1%10)?(x1-(x1%10)+10):x1, xb=x2-(x2%10);
    int ya=(y1%10)?(y1-(y1%10)+10):y1, yb=y2-(y2%10);
// BEGIN CUT HERE
    printf("x: %d [%d %d] %d\n",x1,xa,xb,x2);
    printf("y: %d [%d %d] %d\n",y1,ya,yb,y2);
// END CUT HERE
    if (xa<xb && ya<yb) cnt[5] = 1LL*(xb-xa)*(yb-ya)/5;
// BEGIN CUT HERE
    cout << "B"<<endl;
    if (xa>xb) {
      if (ya>yb) {
// BEGIN CUT HERE
        // nobreak, nobreak
        printf("[%d-%d]x[%d-%d]\n", x1,x2, y1,y2);
// END CUT HERE
        check(cnt, x1%10,y1%10, x2%10,y2%10);
      } else {
// BEGIN CUT HERE
        // x:nobreak, y:break
        printf("[%d-%d]x[%d-|%d]\n", x1,x2, y1,y2);
// END CUT HERE
        if(y1<ya) check(cnt, x1%10,y1%10, x2%10,10);
        check(cnt, x1%10,0, x2%10,y2%10);
      }
    } else {
      if (ya>yb) {
// BEGIN CUT HERE
        // x:break, y:nobreak
        printf("[%d-|%d]x[%d-%d]\n", x1,x2, y1,y2);
// END CUT HERE
        if(x1<xa) check(cnt, x1%10,y1%10, 10,y2%10);
        check(cnt, 0,y1%10, x2%10,y2%10);
      } else {
// BEGIN CUT HERE
        // x:break, y:break
        printf("[%d-|%d]x[%d-|%d]\n", x1,x2, y1,y2);
// END CUT HERE
        if(x1<xa && y1<ya) check(cnt, x1%10,y1%10, 10,10);
        if(x1<xa) check(cnt, x1%10,0, 10,y2%10);
        if(y1<ya) check(cnt, 0,y1%10, x2%10,10);
        check(cnt, 0,0, x2%10,y2%10);
      }
    }

// BEGIN CUT HERE
    cout << "C"<<endl;
// END CUT HERE
    if (xa<xb) {
      // ===
      if (ya>yb) {
// BEGIN CUT HERE
        // y nobreak
        cout << "1"<<endl;
// END CUT HERE
        check(cnt, 0,y1%10, 10,y2%10, (xb-xa)/10);
      } else {
// BEGIN CUT HERE
        cout << "2"<<endl;
// END CUT HERE
        if(y1<ya) check(cnt, 0,y1%10, 10,10, (xb-xa)/10);
        check(cnt, 0,0, 10,y2%10, (xb-xa)/10);
      }
    }
// BEGIN CUT HERE
    cout << "D"<<endl;
// END CUT HERE
    if (ya<yb) {
      if (xa>xb) {
// BEGIN CUT HERE
        cout << "3"<<endl;
// END CUT HERE
        check(cnt, x1%10,0, x2%10,10, (yb-ya)/10);
      } else {
// BEGIN CUT HERE
        cout << "4"<<endl;
// END CUT HERE
        if(x1<xa) check(cnt, x1%10,0, 10,10, (yb-ya)/10);
        check(cnt, 0,0, x2%10,10, (yb-ya)/10);
      }
    }
    
    long long total=cnt[1]+cnt[2]+cnt[3]+cnt[4]+cnt[5], last;
    while(1){
// BEGIN CUT HERE
      cout << cnt << endl;
// END CUT HERE
      // 4
      int c41=min(cnt[4],cnt[1]);
      cnt[1]-=c41; cnt[4]-=c41; cnt[5]+=c41;
      cnt[5]+=cnt[4]; cnt[4]=0;
      // 3
      int c32=min(cnt[3],cnt[2]);
      cnt[2]-=c32; cnt[3]-=c32; cnt[5]+=c32;
      int c311=min(cnt[3],(cnt[1]+1)/2);
      cnt[3]-=c311; cnt[1]-=c311*2; if(cnt[1]<0)cnt[1]=0; cnt[5]+=c311;
      // 2
      int c22=cnt[2]/2;
      cnt[4]+=c22; cnt[2]-=c22*2;
      int c21=min(cnt[2],cnt[1]);
      cnt[2]-=c21; cnt[1]-=c21; cnt[3]+=c21;

      last=total; total=cnt[1]+cnt[2]+cnt[3]+cnt[4]+cnt[5];
      if(total==last) break;
    }
// BEGIN CUT HERE
    cout << cnt << endl;
// END CUT HERE
    cnt[5] += cnt[1]/5; cnt[1] %= 5;
    int c1=cnt[1]; if(c1>1){ cnt[c1]++; cnt[1]=0; }
    total=cnt[1]+cnt[2]+cnt[3]+cnt[4]+cnt[5];
// BEGIN CUT HERE
    cout << cnt << endl;
// END CUT HERE
    return total;
  }
};

// BEGIN CUT HERE
#include <time.h>
clock_t start_time;
void timer_clear() { start_time = clock(); }
string timer() { clock_t end_time = clock(); double interval = (double)(end_time - start_time)/CLOCKS_PER_SEC; ostringstream os; os << " (" << interval*1000 << " msec)"; return os.str(); }

template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
int verify_case(const long long &Expected, const long long &Received) { if (Expected == Received) cerr << "PASSED" << timer() << endl; else { cerr << "FAILED" << timer() << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } return 0;}

template<int N> struct Case_ {};
char Test_(...);
int Test_(Case_<0>) {
	timer_clear();
	int x1 = 0; 
	int y1 = 0; 
	int x2 = 5; 
	int y2 = 5; 
	long long RetVal = 5LL; 
	return verify_case(RetVal, BedroomFloor().numberOfSticks(x1, y1, x2, y2)); }
int Test_(Case_<1>) {
	timer_clear();
	int x1 = 0; 
	int y1 = 0; 
	int x2 = 10; 
	int y2 = 2; 
	long long RetVal = 5LL; 
	return verify_case(RetVal, BedroomFloor().numberOfSticks(x1, y1, x2, y2)); }
int Test_(Case_<2>) {
	timer_clear();
	int x1 = 2; 
	int y1 = 2; 
	int x2 = 8; 
	int y2 = 8; 
	long long RetVal = 12LL; 
	return verify_case(RetVal, BedroomFloor().numberOfSticks(x1, y1, x2, y2)); }
int Test_(Case_<3>) {
	timer_clear();
	int x1 = 8; 
	int y1 = 5; 
	int x2 = 20; 
	int y2 = 16; 
	long long RetVal = 27LL; 
	return verify_case(RetVal, BedroomFloor().numberOfSticks(x1, y1, x2, y2)); }
int Test_(Case_<4>) {
	timer_clear();
	int x1 = 0; 
	int y1 = 0; 
	int x2 = 1000000; 
	int y2 = 1000000; 
	long long RetVal = 200000000000LL; 
	return verify_case(RetVal, BedroomFloor().numberOfSticks(x1, y1, x2, y2)); }
int Test_(Case_<5>) {
	timer_clear();
	int x1 = 9; 
	int y1 = 3; 
	int x2 = 10;
	int y2 = 9;
	long long RetVal = 2;
	return verify_case(RetVal, BedroomFloor().numberOfSticks(x1, y1, x2, y2)); }
int Test_(Case_<6>) {
	timer_clear();
	int x1 = 101; 
	int y1 = 102; 
	int x2 = 203;
	int y2 = 204;
	long long RetVal = 2142;
	return verify_case(RetVal, BedroomFloor().numberOfSticks(x1, y1, x2, y2)); }

template<int N> void Run_() { cerr << "Test Case #" << N << "..." << flush; Test_(Case_<N>()); Run_<sizeof(Test_(Case_<N+1>()))==1 ? -1 : N+1>(); }
template<>      void Run_<-1>() {}
int main() { Run_<0>(); }
// END CUT HERE


// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
You have decided to put new floor tiles on your bedroom floor. Consider an infinite pattern made of 1x5 wooden panels as in the picture below. The top-left corner of the picture has coordinates (0, 0).  X coordinates increase from left to right, and y coordinates increase from top to bottom.



You have chosen a rectangular area within this infinite pattern that matches the exact size of your bedroom.  The top-left corner of the rectangle is at (x1, y1) and the bottom-right corner is at (x2, y2).  You want to reproduce this section on your bedroom floor.



The store that sells wooden floor panels only carries 1x5 panels.  You can cut panels to get smaller panels, but you can't glue panels together to get larger ones.  For example, you can cut a 1x5 panel to get one 1x3 panel and one 1x2 panel, or two 1x2 panel and one 1x1 panel, etc.




The picture above shows the rectangular area (8, 5, 20, 16). You need twenty-three 1x5 panels, six 1x2 panels and five 1x1 panels. You have to buy total of 27 panels to make these.



You are given ints x1, y1, x2 and y2. Return the minimum number of panels you must buy at the store to produce the pattern in the given rectangular area.


DEFINITION
Class:BedroomFloor
Method:numberOfSticks
Parameters:int, int, int, int
Returns:long long
Method signature:long long numberOfSticks(int x1, int y1, int x2, int y2)


NOTES
-You can throw away any part of a panel that you don't need.


CONSTRAINTS
-x1, y1, x2 and x2 will be between 0 and 1000000, inclusive.
-x2 will be strictly greater than x1.
-y2 will be strictly greater than y1.


EXAMPLES

0)
0
0
5
5

Returns: 5

This rectangular area contains five 1x5 panels.

1)
0
0
10
2

Returns: 5

This rectangular area contains two 1x5 panels and five 1x2 panels.  We have to buy 5 panels to make these.

2)
2
2
8
8

Returns: 12

This rectangle contains twelve 1x3 panels.  We can't glue panels together, so we have to buy 12 panels.

3)
8
5
20
16

Returns: 27

The example depicted in the problem statement.

4)
0
0
1000000
1000000

Returns: 200000000000



*/
// END CUT HERE
