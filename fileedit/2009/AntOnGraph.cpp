#line 2 "AntOnGraph.cpp"
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

// BEGIN CUT HERE
string binstr(long long x, int len_min=1)
{
  char buf[65], *p = buf+64;
  *p = 0;

  while (x > 0 || len_min > 0) {
    *(--p) = '0' + (x & 1);
    x >>= 1;
    len_min--;
  }
  string s(p);
  return s;
}
// END CUT HERE

class AntOnGraph {
 public:
  string maximumBonus(vector <string> p0, vector <string> p1, vector <string> p2, int stepsPerSecond, int timeLimit) {
	int n=sz(p0);
    vector<vector<int> > a(n,vector<int>(n));
    vector<vector<bool> > e(n,vector<bool>(n,false));
    rep(i,n)rep(j,n){
      int A = (p0[i][j]-'0')*100 + (p1[i][j]-'0')*10 + (p2[i][j]-'0');
      e[i][j] = (A != 0);
      a[i][j] = A - 500;
    }
// BEGIN CUT HERE
    cout << e << endl;
    cout << a << endl;
// END CUT HERE
    vector<vector<vector<ll> > > sc(n,vector<vector<ll> >(n,vector<ll>(n,LONG_LONG_MIN)));
    //    vector<vector<vector<vector<ll> > > > ms(n,vector<vector<vector<ll> > >(n,vector<vector<ll> >(n,vector<ll>(0))));
    vector<vector<vector<set<ll> > > > ms(n,vector<vector<set<ll> > >(n,vector<set<ll> >(n)));
    rep(i,n)rep(j,n){
      if(e[i][j]) {
        sc[i][j][1] = a[i][j]; // 1 step
        ms[i][j][1].clear();
        ms[i][j][1].insert((1LL << i) | (1LL << j));
      }
    }
    for(int st=2;st<n;st++){
      rep(i,n)rep(j,n){
        ll s1=sc[i][j][st-1];
        if (s1 > LONG_LONG_MIN) {
          set<ll> m1=ms[i][j][st-1];
          rep(k,n){
            if (e[j][k]) {
              ll s2=s1+a[j][k];
              ll m_=1LL<<k;
              if (s2 > sc[i][k][st]) {
                sc[i][k][st] = s2;
                tr(m1,it){
                  ms[i][k][st].clear();
                  ms[i][k][st].insert(*it|m_);
                }
              } else if (s2 == sc[i][k][st]) {
                // sc[i][k][st] = s2;
                tr(m1,it){
                  ms[i][k][st].insert(*it|m_);
                }
              }
            }
          }
        }
      }
    }
// BEGIN CUT HERE
    // stepsPerSecond x k
    // timeLimit: 1 - 10^9
    //    cout << e << endl;
    //    cout << a << endl;
    rep(i,n)rep(j,n)rep(s,n){
      if (sc[i][j][s] > LONG_LONG_MIN) {
        //        printf("%d => %d in step %d ... %lld,", i,j,s, sc[i][j][s]);
        //        cout << ms[i][j][s] << endl;
      }
    }
            //cout << "sc: " << sc << endl;
// END CUT HERE
    bool possible = false;
    ll maxscore = LONG_LONG_MIN;
    rep(s,n){
      if (sc[0][1][s] > LONG_LONG_MIN) {
        printf("step %d: %lld, ", s, sc[0][1][s]);
        tr(ms[0][1][s],it){
          cout << "  + " << binstr(*it) << endl;
        }
        possible = true;
      }
    }
    if (!possible) return "IMPOSSIBLE";

    stringstream ss;
    ss << maxscore;
    return ss.str();
  }
};

// BEGIN CUT HERE
#include <time.h>
clock_t start_time;
void timer_clear() { start_time = clock(); }
string timer() { clock_t end_time = clock(); double interval = (double)(end_time - start_time)/CLOCKS_PER_SEC; ostringstream os; os << " (" << interval*1000 << " msec)"; return os.str(); }

template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
int verify_case(const string &Expected, const string &Received) { if (Expected == Received) cerr << "PASSED" << timer() << endl; else { cerr << "FAILED" << timer() << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } return 0;}

template<int N> struct Case_ {};
char Test_(...);
int Test_(Case_<0>) {
	timer_clear();
	string p0_[] = {"05","50"};
	  vector <string> p0(p0_, p0_+sizeof(p0_)/sizeof(*p0_)); 
	string p1_[] = {"00","00"};
	  vector <string> p1(p1_, p1_+sizeof(p1_)/sizeof(*p1_)); 
	string p2_[] = {"01","10"};
	  vector <string> p2(p2_, p2_+sizeof(p2_)/sizeof(*p2_)); 
	int stepsPerSecond = 3; 
	int timeLimit = 2; 
	string RetVal = "3"; 
	return verify_case(RetVal, AntOnGraph().maximumBonus(p0, p1, p2, stepsPerSecond, timeLimit)); }
int Test_(Case_<1>) {
	timer_clear();
	string p0_[] = {"05","50"};
	  vector <string> p0(p0_, p0_+sizeof(p0_)/sizeof(*p0_)); 
	string p1_[] = {"00","00"};
	  vector <string> p1(p1_, p1_+sizeof(p1_)/sizeof(*p1_)); 
	string p2_[] = {"01","10"};
	  vector <string> p2(p2_, p2_+sizeof(p2_)/sizeof(*p2_)); 
	int stepsPerSecond = 2; 
	int timeLimit = 3; 
	string RetVal = "IMPOSSIBLE"; 
	return verify_case(RetVal, AntOnGraph().maximumBonus(p0, p1, p2, stepsPerSecond, timeLimit)); }
int Test_(Case_<2>) {
	timer_clear();
	string p0_[] = {"0550","0000","0005","5000"};
	  vector <string> p0(p0_, p0_+sizeof(p0_)/sizeof(*p0_)); 
	string p1_[] = {"0000","0000","0000","0000"};
	  vector <string> p1(p1_, p1_+sizeof(p1_)/sizeof(*p1_)); 
	string p2_[] = {"0110","0000","0001","1000"};
	  vector <string> p2(p2_, p2_+sizeof(p2_)/sizeof(*p2_)); 
	int stepsPerSecond = 7; 
	int timeLimit = 9; 
	string RetVal = "49"; 
	return verify_case(RetVal, AntOnGraph().maximumBonus(p0, p1, p2, stepsPerSecond, timeLimit)); }
int Test_(Case_<3>) {
	timer_clear();
	string p0_[] = {"0540","0000","0004","4000"};
	  vector <string> p0(p0_, p0_+sizeof(p0_)/sizeof(*p0_)); 
	string p1_[] = {"0090","0000","0009","9000"};
	  vector <string> p1(p1_, p1_+sizeof(p1_)/sizeof(*p1_)); 
	string p2_[] = {"0190","0000","0009","9000"};
	  vector <string> p2(p2_, p2_+sizeof(p2_)/sizeof(*p2_)); 
	int stepsPerSecond = 7; 
	int timeLimit = 9; 
	string RetVal = "-5"; 
	return verify_case(RetVal, AntOnGraph().maximumBonus(p0, p1, p2, stepsPerSecond, timeLimit)); }
int Test_(Case_<4>) {
	timer_clear();
	string p0_[] = {"079269665406","506042219642","720809987956",
 "315099331918","952306192584","406390344278",
 "999241035142","370785209189","728363760165",
 "019367419000","279718007804","610188263490"};
	  vector <string> p0(p0_, p0_+sizeof(p0_)/sizeof(*p0_)); 
	string p1_[] = {"038604914953","804585763146","350629473403",
 "028096403898","575205051686","427800322647",
 "655168017864","582553303278","980402170192",
 "620737714031","686142310509","092421645460"};
	  vector <string> p1(p1_, p1_+sizeof(p1_)/sizeof(*p1_)); 
	string p2_[] = {"063231394554","109852259379","740182746422",
 "853015982521","476805512496","898530717993",
 "430534005863","440162807186","132879980431",
 "685312177072","780267345400","959947501200"};
	  vector <string> p2(p2_, p2_+sizeof(p2_)/sizeof(*p2_)); 
	int stepsPerSecond = 37; 
	int timeLimit = 1221; 
	string RetVal = "20992235"; 
	return verify_case(RetVal, AntOnGraph().maximumBonus(p0, p1, p2, stepsPerSecond, timeLimit)); }

template<int N> void Run_() { cerr << "Test Case #" << N << "..." << flush; Test_(Case_<N>()); Run_<sizeof(Test_(Case_<N+1>()))==1 ? -1 : N+1>(); }
template<>      void Run_<-1>() {}
int main() { Run_<0>(); }
// END CUT HERE


// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// You are given a directed graph with n vertices, labeled 0 to n-1. The edges of the graph contain values, and each time you traverse an edge, the value of that edge gets added to your total score. If the same edge is traversed multiple times, its value gets added every time. Values can be any number between -499 and 499, inclusive. There are no edges that connect a vertex to itself.

There's an ant at vertex 0 and it wants to get to vertex 1.  It must do this in an integer number of seconds between 1 and timeLimit, inclusive. The ant must make exactly stepsPerSecond steps each second, where each step consists of moving from its current vertex V to an adjacent vertex W (W is adjacent to V if there's a directed edge from V to W in the graph). The ant's goal is to get the highest score possible.

The graph is given as three vector <string>s p0, p1 and p2. Concatenate the j-th characters of the i-th elements of p0, p1 and p2 (in that order) to get a 3-digit String S. If S is "000", then there is no edge from vertex i to vertex j.  Otherwise, there is an edge from vertex i to vertex j, and its value is A - 500, where A is the integer value of S. For example, if S is "100", then the value is -400, and if S is "999", the value is 499.  Return the decimal representation of the highest possible score as a string with no extra leading zeroes.  If it is impossible to reach vertex 1 under the given constraints, return "IMPOSSIBLE" (quotes for clarity) instead.

DEFINITION
Class:AntOnGraph
Method:maximumBonus
Parameters:vector <string>, vector <string>, vector <string>, int, int
Returns:string
Method signature:string maximumBonus(vector <string> p0, vector <string> p1, vector <string> p2, int stepsPerSecond, int timeLimit)


CONSTRAINTS
-p0 will contain between 2 and 50 elements, inclusive.
-p1 and p2 will each contain the same number of elements as p0.
-Each element in p0, p1 and p2 will contain exactly n characters, where n is the number of elements in p0.
-Each character in p0, p1 and p2 will be a digit ('0'-'9').
-The i-th character of the i-th element of p0, p1 and p2 will be '0'.
-stepsPerSecond will be between 1 and 100, inclusive.
-timeLimit will be between 1 and 1000000000 (10^9), inclusive.


EXAMPLES

0)
{"05","50"}
{"00","00"}
{"01","10"}
3
2

Returns: "3"

Here, there are two vertices.  There's an edge from vertex 0 to vertex 1 and an edge from vertex 1 to vertex 0.  Both edges have a value of 1.  The ant must make exactly 3 steps per second, so during the first second, it will make the following moves: 0->1, 1->0, 0->1.  The time limit is 2, so there's time for 3 more moves.  However, that would place the ant back at vertex 0, so the ant should stop after the first second.

1)
{"05","50"}
{"00","00"}
{"01","10"}
2
3

Returns: "IMPOSSIBLE"

This is the same graph as the previous example, but this time, the ant must make exactly 2 steps per second.  The ant can therefore never reach vertex 1 because it will always return to vertex 0 after each second.

2)
{"0550","0000","0005","5000"}
{"0000","0000","0000","0000"}
{"0110","0000","0001","1000"}
7
9

Returns: "49"

In this case the ant can traverse cycle 0->2->3->0 and earn 3 points. The ant will keep moving along this cycle and finally go to vertex 1 and earn another point. Thus the number of points modulo 3 is 1. Among all multiple of 7 less than or equal to 63, 49 is the biggest one that satisfies the constraints.

3)
{"0540","0000","0004","4000"}
{"0090","0000","0009","9000"}
{"0190","0000","0009","9000"}
7
9

Returns: "-5"

This is the same as the previous example, but this time, the score for the cycle is -3.

4)
{"079269665406","506042219642","720809987956",
 "315099331918","952306192584","406390344278",
 "999241035142","370785209189","728363760165",
 "019367419000","279718007804","610188263490"}
{"038604914953","804585763146","350629473403",
 "028096403898","575205051686","427800322647",
 "655168017864","582553303278","980402170192",
 "620737714031","686142310509","092421645460"}
{"063231394554","109852259379","740182746422",
 "853015982521","476805512496","898530717993",
 "430534005863","440162807186","132879980431",
 "685312177072","780267345400","959947501200"}
37
1221

Returns: "20992235"



*/
// END CUT HERE
