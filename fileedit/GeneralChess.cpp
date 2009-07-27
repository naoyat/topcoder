#line 2 "GeneralChess.cpp"
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
typedef pair<int,int> ii;
#define sz(a)  int((a).size())
#define pb  push_back
#define all(c)  (c).begin(),(c).end()
#define tr(c,i)  for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); i++)
#define rep(var,n)  for(int var=0;var<(n);var++)
#define found(s,e)  ((s).find(e)!=(s).end())

vector<string> split(string str, int delim=' ')
{
  vector<string> result;

  const char *s = str.c_str();
  if (delim == ' ') {
    for (const char *p=s; *p; p++) {
      if (*p == delim) s++;
      else break;
    }
    if (!*s) return result;

    for (const char *p=s; *p; p++) {
      if (*p == delim) {
        if (s < p) {
          string a(s,p-s);
          result.push_back(a);
        }
        s = p + 1;
      }
    }
    if (*s) result.push_back(s);
  } else {
    for (const char *p=s; *p; p++) {
      if (*p == delim) {
        string a(s,p-s);
        result.push_back(a);
        s = p + 1;
        if (*s == '\0') result.push_back("");
      }
    }
    if (*s) result.push_back(s);
  }

  return result;
}

vector<int> map_atoi(vector<string> nums)
{
  vector<int> vals(nums.size());
  for (int i=nums.size()-1; i>=0; i--) vals[i] = atoi(nums[i].c_str());
  return vals;
}

int knight[8][2] = { {-2,-1}, {-2,1}, {-1,-2}, {-1,2}, {1,-2}, {1,2}, {2,-1}, {2,1} };

class GeneralChess {
 public:
  vector <string> attackPositions(vector <string> pieces) {
	int n=sz(pieces);
    map<ii,int> m;
    rep(i,n){
      vi xy = map_atoi(split(pieces[i],','));
      rep(j,8){
        ii xy_ = make_pair(xy[0] + knight[j][0],
                           xy[1] + knight[j][1]);
        if (found(m,xy_)) m[xy_]++;
        else m[xy_]=1;
      }
    }
    // cout << "m:" << m << endl;
    vector<ii> v;
    tr(m,it){
      if(it->second==n) v.pb(it->first);
    }
    sort(all(v));
    // cout << "v:" << v << endl;
    vector<string> ans;
    tr(v,it){
      char buf[14];
      sprintf(buf,"%d,%d", it->first, it->second);
      ans.pb(buf);
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
int verify_case(const vector <string> &Expected, const vector <string> &Received) { if (Expected == Received) cerr << "PASSED" << timer() << endl; else { cerr << "FAILED" << timer() << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } return 0;}

template<int N> struct Case_ {};
char Test_(...);
int Test_(Case_<0>) {
	timer_clear();
	string pieces_[] = {"0,0"};
	  vector <string> pieces(pieces_, pieces_+sizeof(pieces_)/sizeof(*pieces_)); 
	string RetVal_[] = { "-2,-1",  "-2,1",  "-1,-2",  "-1,2",  "1,-2",  "1,2",  "2,-1",  "2,1" };
	  vector <string> RetVal(RetVal_, RetVal_+sizeof(RetVal_)/sizeof(*RetVal_)); 
	return verify_case(RetVal, GeneralChess().attackPositions(pieces)); }
int Test_(Case_<1>) {
	timer_clear();
	string pieces_[] = {"2,1", "-1,-2"};
	  vector <string> pieces(pieces_, pieces_+sizeof(pieces_)/sizeof(*pieces_)); 
	string RetVal_[] = { "0,0",  "1,-1" };
	  vector <string> RetVal(RetVal_, RetVal_+sizeof(RetVal_)/sizeof(*RetVal_)); 
	return verify_case(RetVal, GeneralChess().attackPositions(pieces)); }
int Test_(Case_<2>) {
	timer_clear();
	string pieces_[] = {"0,0", "2,1"};
	  vector <string> pieces(pieces_, pieces_+sizeof(pieces_)/sizeof(*pieces_)); 
	vector <string> RetVal; 
	return verify_case(RetVal, GeneralChess().attackPositions(pieces)); }
int Test_(Case_<3>) {
	timer_clear();
	string pieces_[] = {"-1000,1000", "-999,999", "-999,997"};
	  vector <string> pieces(pieces_, pieces_+sizeof(pieces_)/sizeof(*pieces_)); 
	string RetVal_[] = { "-1001,998" };
	  vector <string> RetVal(RetVal_, RetVal_+sizeof(RetVal_)/sizeof(*RetVal_)); 
	return verify_case(RetVal, GeneralChess().attackPositions(pieces)); }

template<int N> void Run_() { cerr << "Test Case #" << N << "..." << flush; Test_(Case_<N>()); Run_<sizeof(Test_(Case_<N+1>()))==1 ? -1 : N+1>(); }
template<>      void Run_<-1>() {}
int main() { Run_<0>(); }
// END CUT HERE


// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// You have decided that too many people do not know how to play chess.  So, in an effort to teach the rules you must write some software that helps to understand how chess-pieces affect one another.  Your current project involves the knight and its ability to threaten one or more pieces at once.  The knight has an unusual style of "jumping" around the board.  One move consists of traveling two squares in one of the four cardinal directions, followed by one square perpendicular to the original direction.  For example, if a knight is on (0,0), it may move to (2,1), (2,-1), (1,2), (1,-2), (-2, 1), (-2,-1), (-1,2), or (-1,-2).  In addition, if a piece is on any of those locations, it is threatened by the knight on (0,0).

You will be given a vector <string> pieces, where each element is a comma delimited set of coordinates.  Every element in pieces is formatted as "<x-coordinate>,<y-coordinate>" (quotes and angle brackets for clarity).  Calculate and return a vector <string> where each element represents a position from which a knight threatens every piece in pieces.  Your return vector <string> must be in the same format as pieces and sorted in increasing order by the x-coordinate.  If two sets of coordinates have the same x-coordinate, the one with the smaller y-coordinate must come first.

DEFINITION
Class:GeneralChess
Method:attackPositions
Parameters:vector <string>
Returns:vector <string>
Method signature:vector <string> attackPositions(vector <string> pieces)


CONSTRAINTS
-pieces will contain between 1 and 8 elements, inclusive.
-Each element in pieces will be formatted as "<x-coordinate>,<y-coordinate>" (quotes and angle brackets for clarity).
-Each <x-coordinate> will be an integer between -10000 and 10000, inclusive and will not contain leading zeros.
-Each <y-coordinate> will be an integer between -10000 and 10000, inclusive and will not contain leading zeros.
-Each element in pieces will be unique.


EXAMPLES

0)
{"0,0"}

Returns: { "-2,-1",  "-2,1",  "-1,-2",  "-1,2",  "1,-2",  "1,2",  "2,-1",  "2,1" }

This location is threatened from eight different places.

1)
{"2,1", "-1,-2"}

Returns: { "0,0",  "1,-1" }

A knight may be in two places such that both pieces are threatened.  In chess, placing your pieces in such positions is usually undesirable when your opponent has a knight.

2)
{"0,0", "2,1"}

Returns: { }

3)
{"-1000,1000", "-999,999", "-999,997"}

Returns: { "-1001,998" }

No three pieces can ever be threatened by a knight from more than one position.

*/
// END CUT HERE
