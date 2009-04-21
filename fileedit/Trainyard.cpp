#line 78 "Trainyard.cpp"
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

#define sz(a)  int((a).size())
#define pb  push_back
#define all(c)  (c).begin(),(c).end()
#define tr(c,i)  for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); i++)
#define rep(var,n)  for(int var=0;var<(n);var++)
#define found(s,e)  ((s).find(e)!=(s).end())
#define remove_(c,val) (c).erase(remove((c).begin(),(c).end(),(val)),(c).end())

class Trainyard {
  bool ns(int c){return (c=='.'||c=='-')?false:true;}
  bool ew(int c){return (c=='.'||c=='|')?false:true;}
 public:
  int reachableSquares(vector<string> lo, int fuel) {
    int w=sz(lo[0]),h=sz(lo);
    //printf("w=%d, h=%d\n", w,h);
    int sx,sy;
    vector<vector<int> > r(h);
    vector<vector<bool> > v(h);
    rep(y,h){r[y].resize(w); v[y].resize(w);}
    rep(y,h)rep(x,w){ r[y][x]=-1; v[y][x]=false; if(lo[y][x]=='S') {sy=y;sx=x;r[y][x]=fuel;} }
    queue<pair<int,int> > q;
    q.push(make_pair(sy,sx));
    while(!q.empty()){
      //cout << q.front() << endl;
      int y=q.front().first, x=q.front().second;
      v[y][x]=true; int r_=r[y][x];
      q.pop();
      if(r_<=0) continue;

      int c=lo[y][x];
      //printf("lo[%d][%d]=%c, ns=%c,ew=%c\n", y,x,c, ns(c)?'o':'.', ew(c)?'o':'.');
      if(ns(c)){
        if(y>0){
          if(ns(lo[y-1][x])&&!v[y-1][x]) {r[y-1][x]=r_-1; q.push(make_pair(y-1,x));}
        }
        if(y<h-1){
          if(ns(lo[y+1][x])&&!v[y+1][x]) {r[y+1][x]=r_-1; q.push(make_pair(y+1,x));}
        }
      }
      if(ew(c)){
        if(x>0){
          if(ew(lo[y][x-1])&&!v[y][x-1]) {r[y][x-1]=r_-1; q.push(make_pair(y,x-1));}
        }
        if(x<w-1){
          if(ew(lo[y][x+1])&&!v[y][x+1]) {r[y][x+1]=r_-1; q.push(make_pair(y,x+1));}
        }
      }
    }
    
    int cnt=0;
    rep(y,h)rep(x,w) if(r[y][x]>=0)cnt++;
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
  string layout_[] = {
    ".-....",
    "-S---.",
    "......"};
  vector <string> layout(layout_, layout_+sizeof(layout_)/sizeof(*layout_)); 
  int fuel = 2; 
  int RetVal = 4; 
  return verify_case(RetVal, Trainyard().reachableSquares(layout, fuel)); }
int Test_(Case_<1>) {
  timer_clear();
  string layout_[] = {
    "..+-+.",
    "..|.|.",
    "S-+-+."};
  vector <string> layout(layout_, layout_+sizeof(layout_)/sizeof(*layout_)); 
  int fuel = 10; 
  int RetVal = 10; 
  return verify_case(RetVal, Trainyard().reachableSquares(layout, fuel)); }
int Test_(Case_<2>) {
  timer_clear();
  string layout_[] = {
    "-....-",
    "|....+",
    "+-S++|",
    "|.|..|",
    "..+-++"};
  vector <string> layout(layout_, layout_+sizeof(layout_)/sizeof(*layout_)); 
  int fuel = 8; 
  int RetVal = 15; 
  return verify_case(RetVal, Trainyard().reachableSquares(layout, fuel)); }
int Test_(Case_<3>) {
  timer_clear();
  string layout_[] = {
    ".|...",
    "-+S+|",
    ".|..."};
  vector <string> layout(layout_, layout_+sizeof(layout_)/sizeof(*layout_)); 
  int fuel = 5; 
  int RetVal = 6; 
  return verify_case(RetVal, Trainyard().reachableSquares(layout, fuel)); }

template<int N> void Run_() { cerr << "Test Case #" << N << "..." << flush; Test_(Case_<N>()); Run_<sizeof(Test_(Case_<N+1>()))==1 ? -1 : N+1>(); }
template<>      void Run_<-1>() {}
int main() { Run_<0>(); }
// END CUT HERE

