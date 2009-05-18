#line 2 "MazeWandering.cpp"
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

class MazeWandering {
 public:
  double expectedTime(vector <string> maze) {
    int N=sz(maze),M=sz(maze[0]);
    int fx=-1,fy=-1,ne=0,cn=0,fn=-1;
	vector<pair<int,int> > cs;
    map<pair<int,int>,int> sc;
    vector<vector<pair<int,int> > > nes(2500);
    rep(n,N) rep(m,M){
      switch(maze[n][m]){
        case '*':
          fx=n; fy=m; fn=cn;
        case '.':
          cs.pb(make_pair(n,m));
          sc[make_pair(n,m)]=cn;
          nes[cn].clear();
          if(n>=1 && maze[n-1][m]!='X') nes[cn].pb(make_pair(n-1,m));
          if(n<=N-2 && maze[n+1][m]!='X') nes[cn].pb(make_pair(n+1,m));
          if(m>=1 && maze[n][m-1]!='X') nes[cn].pb(make_pair(n,m-1));
          if(m<=M-2 && maze[n][m+1]!='X') nes[cn].pb(make_pair(n,m+1));
          //nes.pb(ne);
          cn++;
          break;
        case 'X':
          break;
      }
    }
    vector<vector<int> > nesi(cn);
    vector<int> nesd(cn);
    rep(i,cn){
      nesi[i].clear();
      tr(nes[i],it) {
        nesi[i].pb(sc[*it]);
      }
      nesd[i] = sz(nesi[i]);
    }
    
    double T=0, lT=-1;
    vector<vector<double> > ps(2);
    ps[0].resize(cn);
    ps[1].resize(cn);
    rep(i,cn) ps[0][i] = 1.0;
    for(int st=0;;st++){
      //printf("st: %d, T: %g, (cn=%d,fn=%d)\n", st, T,cn,fn);
      int a=st%2, b=(st+1)%2;
      ps[a][fn]=0;
      //cout << "a: " << ps[a] << endl;
      rep(i,cn){
        ps[b][i]=0.0;
        tr(nesi[i],it){
          if(*it!=fn){
            //printf(" ps[b][%d] += ps[a][%d]/%d=%g\n",i,*it,nesd[i],ps[a][*it]/nesd[*it]);
            ps[b][i] += ps[a][*it]/nesd[*it];
          }
        }
      }
      //cout << "b: " << ps[b] << endl;
      //printf("T += %g x %g; --%g\n", ps[b][fn], st+1, ps[b][fn]);
      T += ps[b][fn]*(st+1); //ps[b][fn]=0;
      //      if(st%10000==0)
      //cout << T << endl;
      if (T-lT < 1e-10) break;
      lT = T;
    }
    //cout << "... returns " << T/cn << endl;
    return T/cn;
  }
};

// BEGIN CUT HERE
#include <time.h>
clock_t start_time;
void timer_clear() { start_time = clock(); }
string timer() { clock_t end_time = clock(); double interval = (double)(end_time - start_time)/CLOCKS_PER_SEC; ostringstream os; os << " (" << interval*1000 << " msec)"; return os.str(); }

template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
int verify_case(const double &Expected, const double &Received) { double diff = Expected - Received; if (diff < 0) diff = -diff; if (diff < 1e-9) cerr << "PASSED" << timer() << endl; else { cerr << "FAILED" << timer() << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } return 0;}

template<int N> struct Case_ {};
char Test_(...);
int Test_(Case_<0>) {
	timer_clear();
	string maze_[] = {"*",
 "."};
	  vector <string> maze(maze_, maze_+sizeof(maze_)/sizeof(*maze_)); 
	double RetVal = 0.5; 
	return verify_case(RetVal, MazeWandering().expectedTime(maze)); }
int Test_(Case_<1>) {
	timer_clear();
	string maze_[] = {"*.."};
	  vector <string> maze(maze_, maze_+sizeof(maze_)/sizeof(*maze_)); 
	double RetVal = 2.3333333333333335; 
	return verify_case(RetVal, MazeWandering().expectedTime(maze)); }
int Test_(Case_<2>) {
	timer_clear();
	string maze_[] = {"...",
 "X*X",
 "..."};
	  vector <string> maze(maze_, maze_+sizeof(maze_)/sizeof(*maze_)); 
	double RetVal = 4.857142857142857; 
	return verify_case(RetVal, MazeWandering().expectedTime(maze)); }
int Test_(Case_<3>) {
	timer_clear();
	string maze_[] = {".*.",
 ".XX",
 "..."};
	  vector <string> maze(maze_, maze_+sizeof(maze_)/sizeof(*maze_)); 
	double RetVal = 13.714285714285714; 
	return verify_case(RetVal, MazeWandering().expectedTime(maze)); }
int Test_(Case_<4>) {
	timer_clear();
	string maze_[] = {"*........",
 "XXX.XXXX.",
 ".XX.X....",
 ".....XX.X"};
	  vector <string> maze(maze_, maze_+sizeof(maze_)/sizeof(*maze_)); 
	double RetVal = 167.2608695652174; 
	return verify_case(RetVal, MazeWandering().expectedTime(maze)); }
int Test_(Case_<5>) {
	timer_clear();
	string maze_[] = {"*"};
    vector <string> maze(maze_, maze_+sizeof(maze_)/sizeof(*maze_)); 
	double RetVal = 0.0; 
	return verify_case(RetVal, MazeWandering().expectedTime(maze)); }
int Test_(Case_<6>) {
	timer_clear();
	string maze_[] = {
      "*.................................................",
      "..................................................",
      "..................................................",
      "..................................................",
      "..................................................",
      "..................................................",
      "..................................................",
      "..................................................",
      "..................................................",
      "..................................................",
      "..................................................",
      "..................................................",
      "..................................................",
      "..................................................",
      "..................................................",
      "..................................................",
      "..................................................",
      "..................................................",
      "..................................................",
      "..................................................",
      "..................................................",
      "..................................................",
      "..................................................",
      "..................................................",
      "..................................................",
      "..................................................",
      "..................................................",
      "..................................................",
      "..................................................",
      "..................................................",
      "..................................................",
      "..................................................",
      "..................................................",
      "..................................................",
      "..................................................",
      "..................................................",
      "..................................................",
      "..................................................",
      "..................................................",
      "..................................................",
      "..................................................",
      "..................................................",
      "..................................................",
      "..................................................",
      "..................................................",
      "..................................................",
      "..................................................",
      "..................................................",
      "..................................................",
      ".................................................."
    };
    vector <string> maze(maze_, maze_+sizeof(maze_)/sizeof(*maze_)); 
	double RetVal = 0.0; 
	return verify_case(RetVal, MazeWandering().expectedTime(maze)); }

template<int N> void Run_() { cerr << "Test Case #" << N << "..." << flush; Test_(Case_<N>()); Run_<sizeof(Test_(Case_<N+1>()))==1 ? -1 : N+1>(); }
template<>      void Run_<-1>() {}
int main() { Run_<0>(); }
// END CUT HERE


// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// According to research conducted recently, listening to classical music increases one's mental abilities, while listening to metal decreases them.  Now, yet another experiment is being conducted to try to prove or disprove this statement.

In this new experiment, a mouse is placed in a rectangular maze consisting of NxM squares.  Each square either contains a wall or is empty.  The maze is structured in such a way that for any two empty squares, there exists exactly one path between them.  A path is a sequence of pairwise distinct empty squares such that every two consecutive squares are neighboring.  Two squares are considered neighboring if they share a common edge.

One of the empty squares in the maze contains a piece of cheese, and the mouse's goal is to reach that square.  The mouse can only move between neighboring empty squares.  The mouse has been listening to metal for a week, so his mental abilities have become absolutely dull.  Not only can he not smell the cheese, he can't even remember where he was heading a moment ago, so he is just wandering randomly.  More precisely, from each square, the mouse will randomly choose one of the neighboring empty squares and move there.  The probability of choosing each of the squares is equal.  Each move takes one second.

You are given a vector <string> maze representing the maze.  It contains N elements, each containing M characters.  Empty squares are denoted by '.', walls are denoted by uppercase 'X', and the square containing the cheese is denoted by '*'.  For each empty square, calculate the expected time required for the mouse to reach the cheese starting from that square.  Return the arithmetical mean of all the expected times.

DEFINITION
Class:MazeWandering
Method:expectedTime
Parameters:vector <string>
Returns:double
Method signature:double expectedTime(vector <string> maze)


NOTES
-The returned value must have an absolute or relative error less than 1e-9. 


CONSTRAINTS
-maze will contain between 1 and 50 elements, inclusive.
-Each element of maze will contain between 1 and 50 characters, inclusive.
-Elements of maze will be of the same length.
-maze will contain only '.', 'X', or '*' characters.
-There will be exactly one '*' character in maze.
-For every pair of empty squares in the maze, there will exist exactly one path between them.


EXAMPLES

0)
{"*",
 "."}

Returns: 0.5

The mouse will need 0 seconds to find the cheese if it is put in the cheese-square and 1 second otherwise.


1)
{"*.."}

Returns: 2.3333333333333335

The expectations for each square are 0.0, 3.0 and 4.0.


2)
{"...",
 "X*X",
 "..."}

Returns: 4.857142857142857



3)
{".*.",
 ".XX",
 "..."}

Returns: 13.714285714285714



4)
{"*........",
 "XXX.XXXX.",
 ".XX.X....",
 ".....XX.X"}

Returns: 167.2608695652174



*/
// END CUT HERE
