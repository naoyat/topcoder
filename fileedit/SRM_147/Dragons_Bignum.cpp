// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
There is a small cube planet somewhere. On each side of the cube there lives a four-armed dragon. It is time for dinner now. Each dragon sits in front of his bowl with food. 

During each round, the following happens: Each dragon is trying to steal food from his neighbors (living on four neighboring sides of the cube). He spreads his four arms there (each arm goes to 
each separate neighbor). As other dragons do the same, four hands meet in each bowl of food. Four hands fight for a while and each takes one quarter of the food in this bowl to its own bowl. Hence, each round the food distribution changes.

Given the initial amount of food in each bowl and the number of rounds, return the amount of food the dragons' boss Snaug will have after these rounds.

In more detail:

The initial amount of food will be given in the following order: front, back, up, down, left, right. The dragons' boss Snaug lives on the "up" side of the cube. If the answer is an integer, return this integer. If the answer is a fraction, return the answer in the format X/Y, where X and Y are integers without common factors. Extra leading zeroes shouldn't be present in your answer.

Example.

Suppose that the initial distribution of food is the following: 0, 0, 4, 0, 0, 0. That is Snaug has 4 and everybody else has 0 amount of food in their bowls. After the first round the distribution of food will be the following: 1, 1, 0, 0, 1, 1, that is every neighbor of Snaug steals from him one quarter of his food. After the second round the distribution of food will be the following: 1/2, 1/2, 1, 1, 1/2, 1/2.


DEFINITION
Class:Dragons
Method:snaug
Parameters:vector <int>, int
Returns:string
Method signature:string snaug(vector <int> initialFood, int rounds)


CONSTRAINTS
-initialFood has exactly 6 elements
-each element of initialFood is between 0 and 1,000 inclusive
-rounds is between 0 and 45 inclusive


EXAMPLES

0)
{0, 0, 4, 0, 0, 0}
2

Returns: "1"

See the explanation above

1)
{0, 0, 4, 0, 0, 0}
3

Returns: "1/2"

2)
{1000, 1000, 1000, 1000, 1000, 1000}
45

Returns: "1000"

When everybody has the same amount of food, they continue to have the same amount of food after each round

3)
{1, 2, 3, 4, 5, 6}
45

Returns: "7/2"

*/
// END CUT HERE

#line 69 "Dragons.cpp"
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
#define FOR(var,from,to) for(int var=(from);var<=(to);var++)
#define rep(var,n)  for(int var=0;var<(n);var++)
#define all(c)  (c).begin(),(c).end()
#define tr(c,i)  for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); i++)
#define found(s,e)  ((s).find(e)!=(s).end())
#define mset(arr,val)  memset(arr,val,sizeof(arr))
#define remove_(c,val) (c).erase(remove((c).begin(),(c).end(),(val)),(c).end())
#define lastc(str) (*((str).end()-1))

typedef pair<int,int> i_i;
typedef pair<ll,ll> ll_ll;
typedef pair<double,double> d_d;
typedef pair<int,pair<int,int> > i_ii;
#define cons(x,y) make_pair((x),(y))
#define car(x) ((x).first)
#define cdr(x) ((x).second)
#define cadr(x) (x).second.first
#define cddr(x) (x).second.second

#include "Bignum.h"
#include "Fraction.h"

typedef Fraction<ll> LLF;
typedef Fraction<Bignum> LLB;

class Dragons {
 public:
  string snaug(vector<int> initialFood, int rounds) {
    //	vector<Fraction<ll> > bowl(all(initialFood));
    //    vector<vector<LLF> > bowl(2,vector<LLF>(6));
    vector<vector<LLB> > bowl(2,vector<LLB>(6));
    rep(i,6) {
      bowl[0][i].init(Bignum(initialFood[i]),Bignum(1));
      bowl[1][i].init(Bignum(0),Bignum(1));
    }
    //cout << initialFood << endl;
    //rep(i,6) bowl[i] /= 3;
    //vector<Fraction<ll> > bowl(6);
    //vector<Fraction<ll> > bowl(all(initialFood));
    // front, back, up, down, left, right
    enum { FR=0, BK,UP,DN,LF,RG };
    
    rep(r,rounds){
      int i0=r%2, i1=(r+1)%2;
      cout << "#" << r << ": " << bowl[i0] << endl;
      bowl[i1][FR] = (bowl[i0][UP] + bowl[i0][DN] + bowl[i0][LF] + bowl[i0][RG])/4;
      bowl[i1][BK] = (bowl[i0][UP] + bowl[i0][DN] + bowl[i0][LF] + bowl[i0][RG])/4;
      bowl[i1][UP] = (bowl[i0][FR] + bowl[i0][BK] + bowl[i0][LF] + bowl[i0][RG])/4;
      bowl[i1][DN] = (bowl[i0][FR] + bowl[i0][BK] + bowl[i0][LF] + bowl[i0][RG])/4;
      bowl[i1][LF] = (bowl[i0][FR] + bowl[i0][BK] + bowl[i0][UP] + bowl[i0][DN])/4;
      bowl[i1][RG] = (bowl[i0][FR] + bowl[i0][BK] + bowl[i0][UP] + bowl[i0][DN])/4;
    }
    cout << "#" << rounds << ": " << bowl[rounds%2] << endl;
    return bowl[rounds%2][UP].desc();
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
	int initialFood_[] = {0, 0, 4, 0, 0, 0};
	  vector <int> initialFood(initialFood_, initialFood_+sizeof(initialFood_)/sizeof(*initialFood_)); 
	int rounds = 2; 
	string RetVal = "1"; 
	return verify_case(RetVal, Dragons().snaug(initialFood, rounds)); }
int Test_(Case_<1>) {
	timer_clear();
	int initialFood_[] = {0, 0, 4, 0, 0, 0};
	  vector <int> initialFood(initialFood_, initialFood_+sizeof(initialFood_)/sizeof(*initialFood_)); 
	int rounds = 3; 
	string RetVal = "1/2"; 
	return verify_case(RetVal, Dragons().snaug(initialFood, rounds)); }
int Test_(Case_<2>) {
	timer_clear();
	int initialFood_[] = {1000, 1000, 1000, 1000, 1000, 1000};
	  vector <int> initialFood(initialFood_, initialFood_+sizeof(initialFood_)/sizeof(*initialFood_)); 
	int rounds = 45; 
	string RetVal = "1000"; 
	return verify_case(RetVal, Dragons().snaug(initialFood, rounds)); }
int Test_(Case_<3>) {
	timer_clear();
	int initialFood_[] = {1, 2, 3, 4, 5, 6};
	  vector <int> initialFood(initialFood_, initialFood_+sizeof(initialFood_)/sizeof(*initialFood_)); 
	int rounds = 45; 
	string RetVal = "7/2"; 
	return verify_case(RetVal, Dragons().snaug(initialFood, rounds)); }

template<int N> void Run_() { cerr << "Test Case #" << N << "..." << flush; Test_(Case_<N>()); Run_<sizeof(Test_(Case_<N+1>()))==1 ? -1 : N+1>(); }
template<>      void Run_<-1>() {}
int main() { Run_<0>(); }
// END CUT HERE
