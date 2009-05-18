#line 2 "WalkingHome.cpp"
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
#define pb  push_back
#define all(c)  (c).begin(),(c).end()
#define mset(arr,val)  memset(arr,val,sizeof(arr))
#define tr(c,i)  for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); i++)
#define rep(var,n)  for(int var=0;var<(n);var++)
#define forr(var,from,to) for(int var=(from);var<=(to);var++) 
#define found(s,e)  ((s).find(e)!=(s).end())
#define remove_(c,val) (c).erase(remove((c).begin(),(c).end(),(val)),(c).end())
#define lastc(str) (*((str).end()-1))

class WalkingHome {
 public:
  int fewestCrossings(vector <string> m) {
// BEGIN CUT HERE
    /*
    cout << endl;
    tr(m,it){
      cout << *it << endl;
    }
    */
// END CUT HERE
	int w=sz(m[0]),h=sz(m);
    int start_x=-1, start_y=-1, goal_x=-1, goal_y=-1;
    vector<vector<bool> > fu(h);
    rep(y,h) { fu[y].resize(w); rep(x,w) fu[y][x]=true; }
    rep(y,h) rep(x,w) {
      switch(m[y][x]){
        case 'S': start_x=x; start_y=y; break;
        case 'H': goal_x=x; goal_y=y; break;
        case '*':
        case 'F': fu[y][x] = false; break;
        case '|': case '-':
        case '.':
          break;
      }
    }
    priority_queue<pair<int,pair<int,int> > > pq;
    pq.push(make_pair(0,make_pair(start_x,start_y)));
    while(!pq.empty()){
      int sc=-pq.top().first;
      int x=pq.top().second.first, y=pq.top().second.second;
// BEGIN CUT HERE
      //      cout << "sc: " << sc << ", (x,y): " << x << "," << y << endl;
// END CUT HERE
      if (x==goal_x && y==goal_y) return sc;
      pq.pop();
      if(fu[y][x]){
// BEGIN CUT HERE
        // cout << " . yes" << endl;
// END CUT HERE
        int cur = m[y][x];
        if (0<=x-1) { // <
          if (fu[y][x-1]) {
            int nxt=m[y][x-1], nsc=sc;
            switch(nxt){
              case '-': case '*': case 'S': case 'F': break;
              case '|':
                if (cur=='-') break; // #2
                if (cur!='|') nsc++; //thru
              case '.': case 'H':
                //printf("  (%d,%d) < (%d,%d)\n",x,y, x-1,y);
                pq.push(make_pair(-nsc,make_pair(x-1,y)));
                break;
            }
          }
        }
        if (x+1<=w-1) { // >
          if (fu[y][x+1]) {
            int nxt=m[y][x+1], nsc=sc;
            switch(nxt){
              case '-': case '*': case 'S': case 'F': break;
              case '|':
                if (cur=='-') break; // #2
                if (cur!='|') nsc++; //thru
              case '.': case 'H':
                //printf("  (%d,%d) > (%d,%d)\n",x,y, x+1,y);
                pq.push(make_pair(-nsc,make_pair(x+1,y)));
                break;
            }
          }
        }
        
        if (0<=y-1) { // ^
          if (fu[y-1][x]) {
            int nxt=m[y-1][x], nsc=sc;
            switch(nxt){
              case '|': case '*': case 'S': case 'F': break;
              case '-':
                if (cur=='|') break; // #2
                if (cur!='-') nsc++; //thru
              case '.': case 'H':
                //printf("  (%d,%d) ^ (%d,%d)\n",x,y, x,y-1);
                pq.push(make_pair(-nsc,make_pair(x,y-1)));
                break;
            }
          }
        }
        if (y+1<=h-1) { // v
          if (fu[y+1][x]) {
            int nxt=m[y+1][x], nsc=sc;
            switch(nxt){
              case '|': case '*': case 'S': case 'F': break;
              case '-':
                if (cur=='|') break; // #2
                if (cur!='-') nsc++; //thru
              case '.': case 'H':
                //printf("  (%d,%d) v (%d,%d)\n",x,y, x,y+1);
                pq.push(make_pair(-nsc,make_pair(x,y+1)));
                break;
            }
          }
        }
      }
      fu[y][x] = false;
    }
    return -1;
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
	string m_[] = {
      "S.|..",
      "..|.H"};
	  vector <string> m(m_, m_+sizeof(m_)/sizeof(*m_)); 
	int RetVal = 1; 
	return verify_case(RetVal, WalkingHome().fewestCrossings(m)); }
int Test_(Case_<1>) {
	timer_clear();
	string m_[] = {"S.|..",
 "..|.H",
 "..|..",
 "....."};
	  vector <string> m(m_, m_+sizeof(m_)/sizeof(*m_)); 
	int RetVal = 0; 
	return verify_case(RetVal, WalkingHome().fewestCrossings(m)); }
int Test_(Case_<2>) {
	timer_clear();
	string m_[] = {"S.||...",
 "..||...",
 "..||...",
 "..||..H"};
	  vector <string> m(m_, m_+sizeof(m_)/sizeof(*m_)); 
	int RetVal = 1; 
	return verify_case(RetVal, WalkingHome().fewestCrossings(m)); }
int Test_(Case_<3>) {
	timer_clear();
	string m_[] = {"S.....",
 "---*--",
 "...|..",
 "...|.H"};
	  vector <string> m(m_, m_+sizeof(m_)/sizeof(*m_)); 
	int RetVal = 1; 
	return verify_case(RetVal, WalkingHome().fewestCrossings(m)); }
int Test_(Case_<4>) {
	timer_clear();
	string m_[] = {
      "S.F..",
      "..F..",
      "--*--",
      "..|..",
      "..|.H"};
	  vector <string> m(m_, m_+sizeof(m_)/sizeof(*m_)); 
	int RetVal = 2; 
	return verify_case(RetVal, WalkingHome().fewestCrossings(m)); }
int Test_(Case_<5>) {
	timer_clear();
	string m_[] = {"H|.|.|.|.|.|.|.|.|.|.|.|.|.",
 "F|F|F|F|F|F|F|F|F|F|F|F|F|-",
 "S|.|.|.|.|.|.|.|.|.|.|.|.|."};
	  vector <string> m(m_, m_+sizeof(m_)/sizeof(*m_)); 
	int RetVal = 27; 
	return verify_case(RetVal, WalkingHome().fewestCrossings(m)); }
int Test_(Case_<6>) {
	timer_clear();
	string m_[] = {"S-H"};
	  vector <string> m(m_, m_+sizeof(m_)/sizeof(*m_)); 
	int RetVal = -1; 
	return verify_case(RetVal, WalkingHome().fewestCrossings(m)); }

int Test_(Case_<7>) { // 5
	timer_clear();
	string m_[] = {
      "S|||||||",
      "--------",
      "|||.....",
      "|||.....",
      "|||....H"};
	  vector <string> m(m_, m_+sizeof(m_)/sizeof(*m_)); 
	int RetVal = -1; 
	return verify_case(RetVal, WalkingHome().fewestCrossings(m)); }

int Test_(Case_<8>) { // 12
	timer_clear();
	string m_[] = {
      "|....|",
      "|....|",
      "|....|",
      "|...F|",
      "|---F|",
      "|...F|",
      "|...F|",
      "|...F|",
      "|...FH",
      "|....|",
      "|....|",
      "|FS..|",
      "|....|",
      "|....|",
      "|....|",
      "|....|",
      "|....|",
      "|....|",
      "|....|",
      "|....|",
      "|....|",
      "|....|",
      "|....|",
      "|....|",
      "|....|",
      "|....|",
      "|....|",
      "|....|",
      "|....|",
      "|----|",
      "|....|",
      "|....|",
      "|....|",
      "|....|",
      "*----*",
      "|....|",
      "|....|",
      "|....|",
      "|....|"};
    vector <string> m(m_, m_+sizeof(m_)/sizeof(*m_)); 
    int RetVal = -1; 
    return verify_case(RetVal, WalkingHome().fewestCrossings(m)); }



template<int N> void Run_() { cerr << "Test Case #" << N << "..." << flush; Test_(Case_<N>()); Run_<sizeof(Test_(Case_<N+1>()))==1 ? -1 : N+1>(); }
template<>      void Run_<-1>() {}
int main() { Run_<0>(); }
// END CUT HERE


// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// Johnny has to walk home from school, and wants to m out the best route to take, so that he has to cross as few streets as possible.
You are given a vector <string> m that ms the roadway layout of Johnny's
town.  The location of Johnny's school is designated with a 'S' character, and the location of
Johnny's home is designated with a 'H' character.  North-South roads are denoted by a '|' character, while East-West roads are denoted by a '-' character.
Intersections, which can never be crossed, are indicated by '*' characters.  Fences, indicated by
a 'F' character, can also never be crossed.  All other areas are indicated by '.' characters; Johnny can walk freely over these areas.
For maximum safety, Johnny may only walk directly across a road, perpendicular to the traffic, never diagonally.  All of Johnny's movements, onto and off of a road, and walking around town, should be in one of the four cardinal directions.  Johnny may, however, cross roads that are multiple lanes wide, and doing so only counts as a single crossing.  Two or more adjacent || characters are always considered to be a single road, and this works similarly for '-' characters that appear adjacent vertically.
For instance, the following requires only a single crossing, since it's a single two-lane road:
S.||.H
Also, a situation such as the following leaves Johnny with no safe way to walk home, since he cannot cross the road diagonally, and can only step onto and off a road in a direction perpendicular to the road:

S||
||H

Also notice that because Johnny can never move diagonally, in the following case, Johnny cannot get home:

S.F
.F.
F.H

You are to return an int indicating the fewest number of times Johnny must cross
the street on his way home.  If there is no safe way for Johnny to get home, return -1.

DEFINITION
Class:WalkingHome
Method:fewestCrossings
Parameters:vector <string>
Returns:int
Method signature:int fewestCrossings(vector <string> m)


NOTES
-If a street is more than one unit wide, it still only counts as a single crossing.


CONSTRAINTS
-m will contain between 1 and 50 elements, inclusive.
-Each element of m will contain between 1 and 50 characters, inclusive.
-Each element of m will contain only the characters '.', '-', '|', '*', 'F', 'S', 'H'.
-There will be exactly one occurrence each of 'S' and 'H' in m.
-Each element of m will contain the same number of characters.


EXAMPLES

0)
{"S.|..",
 "..|.H"}

Returns: 1

Here, Johnny lives right across the street from the school, so inevitably, he's crossing the street once to get home.

1)
{"S.|..",
 "..|.H",
 "..|..",
 "....."}

Returns: 0

Similar to above, but since the road has a dead end (maybe even a cul-de-sac at the end), Johnny can get home without actually having to cross the road.

2)
{"S.||...",
 "..||...",
 "..||...",
 "..||..H"}

Returns: 1

Notice here that even though it's a 2-lane highway, it only counts as a single crossing.

3)
{"S.....",
 "---*--",
 "...|..",
 "...|.H"}

Returns: 1

Here, Johnny could go down across the street and then right across another street to his house.  However, if he first goes to the right before crossing down, he will only cross 1 street.

4)
{"S.F..",
 "..F..",
 "--*--",
 "..|..",
 "..|.H"}

Returns: 2

Similar to above, but because there's a fence around the school, Johnny has no choice but to cross twice.

5)
{"H|.|.|.|.|.|.|.|.|.|.|.|.|.",
 "F|F|F|F|F|F|F|F|F|F|F|F|F|-",
 "S|.|.|.|.|.|.|.|.|.|.|.|.|."}

Returns: 27

Poor Johnny lives so close to school, but that fence makes him cross the street quite a bit just to get home.

6)
{"S-H"}

Returns: -1

*/
// END CUT HERE
