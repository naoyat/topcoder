#line 2 "StripePainter.cpp"
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
#define FOR(var,from,to) for(int var=(from);var<=(to);var++)
#define RFOR(var,from,to) for(int var=(to);var>=(from);var--)
#define rep(var,n)  for(int var=0;var<(n);var++)
#define all(c)  (c).begin(),(c).end()
#define tr(c,i)  for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); i++)
#define found(s,e)  ((s).find(e)!=(s).end())

typedef pair<int,int> i_i;
#define cons(x,y) make_pair((x),(y))
#define car(x) ((x).first)
#define cdr(x) ((x).second)
//168.12, ok ... 101'30''
class StripePainter {
  i_i non_c(string str, char c){
    int l=sz(str), b=0, e=l;
    FOR(i,0,l-1) { if (str[i]==c) b++; else break; }
    RFOR(i,b,l-1) { if (str[i]==c) e--; else break; }
    return cons(b,e);
  }

  map<pair<vector<char>,string>,int> memo;
  
  int sub(vector<char> curr, string goal){
    int l=sz(goal); if(l==0) return 0;

    pair<vector<char>,string> key = cons(curr,goal);
    if (found(memo,key)) return memo[key];
    cout << "  sub(\"" << string(all(curr)) << "\", \"" << goal << "\")" << endl;

    // deja peint
    {
      int b=0, e=l;
      FOR(i,0,l-1) { if (goal[i]==curr[i]) b++; else break; }
      RFOR(i,b,l-1) { if (goal[i]==curr[i]) e--; else break; }
      if (b!=0 || e!=l) {
        curr = vector<char>(curr.begin()+b, curr.end()-(l-e));
        goal = goal.substr(b,e-b);
        cout << "   ==> (\"" << string(all(curr)) << "\", \"" << goal << "\")" << endl;
      }
    }
    l=sz(goal);
    cout << "  (l=" << l << ") " << endl;
    if(l==0) return memo[key]=0;
    if(l==1) return memo[key]=1;

    int c0=goal[0];
    vector<int> ats;
    rep(i,l) if(goal[i]==c0 && curr[i]!=c0) ats.pb(i);

    int mincnt = INT_MAX;
    tr(ats,it){
      int x = *it + 1;
      printf(" : '%c' at %d (in %d..%d); x=%d\n", c0, x-1, 0,l-1, x);
      int cnt = 0;
      if (x > 0) {
        printf(" : x=%d > 0\n", x);
        if (x == 1) cnt++;
        else cnt += 1+sub( vector<char>(x,c0), goal.substr(0,x) );
        printf(" :: cnt = %d\n", cnt);
      }
      if (l-x > 0) {
        printf("   l-x=%d > 0\n", l-x);
        if (l-x == 1) cnt++;
        else cnt += sub( vector<char>(curr.begin()+x,curr.end()), goal.substr(x,l-x) );
        printf(" :: cnt = %d\n", cnt);
      }
      mincnt = min(cnt,mincnt);
    }
    return memo[key]=mincnt;
  }
 public:
  int minStrokes(string stripes) {
    cout << endl << "minStrokes(" << stripes << ")" << endl;
    int cnt = sub(vector<char>(sz(stripes),' '), stripes);
    cout << "=> " << cnt << endl;
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
	string stripes = "RGBGR"; 
	int RetVal = 3; 
	return verify_case(RetVal, StripePainter().minStrokes(stripes)); }
int Test_(Case_<1>) {
	timer_clear();
	string stripes = "RGRG"; 
	int RetVal = 3; 
	return verify_case(RetVal, StripePainter().minStrokes(stripes)); }
int Test_(Case_<2>) {
	timer_clear();
	string stripes = "ABACADA"; 
	int RetVal = 4; 
	return verify_case(RetVal, StripePainter().minStrokes(stripes)); }
int Test_(Case_<3>) {
	timer_clear();
	string stripes = "AABBCCDDCCBBAABBCCDD"; 
	int RetVal = 7; 
	return verify_case(RetVal, StripePainter().minStrokes(stripes)); }
int Test_(Case_<4>) {
	timer_clear();
	string stripes = "BECBBDDEEBABDCADEAAEABCACBDBEECDEDEACACCBEDABEDADD"; 
	int RetVal = 26; 
	return verify_case(RetVal, StripePainter().minStrokes(stripes)); }
int Test_(Case_<5>) {
	timer_clear();
	string stripes = "RBGBRRRRRBGBRRRRRRRRRRRBGBR";
	int RetVal = 7; 
	return verify_case(RetVal, StripePainter().minStrokes(stripes)); }

template<int N> void Run_() { cerr << "Test Case #" << N << "..." << flush; Test_(Case_<N>()); Run_<sizeof(Test_(Case_<N+1>()))==1 ? -1 : N+1>(); }
template<>      void Run_<-1>() {}
int main() { Run_<0>(); }
// END CUT HERE


// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
Karel is a frustrated painter who works by day in an electrical repair
shop.  Inspired by the color-coded bands on resistors, he is painting
a series of long, narrow canvases with bold colored stripes.  However, 
Karel is lazy and wants to minimize the number of brush strokes it takes 
to paint each canvas.



Abbreviating each color to a single uppercase letter, Karel would
write the stripe pattern red-green-blue-green-red as "RGBGR" 
(quotes added for clarity).  It would take him three brush strokes to
paint this pattern.
The first stroke would cover the entire canvas in red (RRRRR).
The second stroke would leave a band of red on either side and fill
in the rest with green (RGGGR).
The final brush stroke would fill in the blue stripe in the center
(RGBGR).



Given a stripe pattern stripes as a string, calculate the minimum number of
brush strokes required to paint that pattern.


DEFINITION
Class:StripePainter
Method:minStrokes
Parameters:string
Returns:int
Method signature:int minStrokes(string stripes)


NOTES
-The blank canvas is an ugly color and must not show through.


CONSTRAINTS
-stripes will contain only uppercase letters ('A'-'Z', inclusive).
-stripes will contain between 1 and 50 characters, inclusive.


EXAMPLES

0)
"RGBGR"

Returns: 3

Example from introduction.

1)
"RGRG"

Returns: 3

This example cannot be done in two strokes, even though there are only two colors.
Suppose you tried to paint both red stripes in one stroke, followed by both green stripes 
in one stroke.  Then the green stroke would cover up the second red stripe.  If you tried
to paint both green stripes first, followed the red stripes, then the red stroke would
cover up the first green stripe.

2)
"ABACADA"

Returns: 4

One long stroke in color 'A', followed by one stroke each in colors 'B', 'C', and 'D'.

3)
"AABBCCDDCCBBAABBCCDD"

Returns: 7

4)
"BECBBDDEEBABDCADEAAEABCACBDBEECDEDEACACCBEDABEDADD"

Returns: 26

*/
// END CUT HERE
