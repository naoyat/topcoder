#line 2 "BinaryFlips.cpp"
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

typedef pair<int,pair<int,int> > tre;

class BinaryFlips {
 public:
  int w[200002],d[200002];
  int minimalMoves(int A, int B, int K) {
    int N=A+B; if(N<K) {
      if(A==0)return 0;
      return -1;
    }
    memset(w,255,sizeof(w));
    w[N]=0;
    vector<int>q;q.pb(N);
    int l=0;
    memset(d,255,sizeof(d));
    while(l<q.size()) {
      int b=q[l],a=N-b;
      int L=max(max(K-b,(K-b+1)/2),0);
      int R=min(a,(a+K)/2);
      bool kpyto=true;
      for(int x=L;x<=R&&b-K+2*x<N;x++) if(w[b-K+2*x]<0) {
          w[b-K+2*x] = w[b]+1;
          d[b-K+2*x] = b;
          q.pb(b-K+2*x);
          kpyto=true;
        } else if (kpyto) {
          int bb=d[b-K+2*x];
          int rr=min((N-bb),(N-bb+K)/2);
          x=((bb-b)+2*rr)/2;
          kpyto=false;
        }
      l++;
    }
    return w[B];                                      
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
	int A = 3; 
	int B = 0; 
	int K = 3; 
	int RetVal = 1; 
	return verify_case(RetVal, BinaryFlips().minimalMoves(A, B, K)); }
int Test_(Case_<1>) {
	timer_clear();
	int A = 4; 
	int B = 0; 
	int K = 3; 
	int RetVal = 4; 
	return verify_case(RetVal, BinaryFlips().minimalMoves(A, B, K)); }
int Test_(Case_<2>) {
	timer_clear();
	int A = 4; 
	int B = 1; 
	int K = 3; 
	int RetVal = 2; 
	return verify_case(RetVal, BinaryFlips().minimalMoves(A, B, K)); }
int Test_(Case_<3>) {
	timer_clear();
	int A = 3; 
	int B = 2; 
	int K = 5; 
	int RetVal = -1; 
	return verify_case(RetVal, BinaryFlips().minimalMoves(A, B, K)); }
int Test_(Case_<4>) {
	timer_clear();
	int A = 100000; 
	int B = 100000; 
	int K = 578; 
	int RetVal = 174; 
	return verify_case(RetVal, BinaryFlips().minimalMoves(A, B, K)); }
int Test_(Case_<5>) {
	timer_clear();
	int A = 0; 
	int B = 0; 
	int K = 1; 
	int RetVal = 0; 
	return verify_case(RetVal, BinaryFlips().minimalMoves(A, B, K)); }
int Test_(Case_<6>) {
	timer_clear();
	int A = 4; 
	int B = 44; 
	int K = 50; 
	int RetVal = -1; 
	return verify_case(RetVal, BinaryFlips().minimalMoves(A, B, K)); }

int Test_(Case_<7>) {
	timer_clear();
	int A = 100000; 
	int B = 100000; 
	int K = 100000; 
	int RetVal = 1; 
	return verify_case(RetVal, BinaryFlips().minimalMoves(A, B, K)); }
int Test_(Case_<8>) {
    timer_clear();
	int A = 100000; 
	int B = 100000; 
	int K = 65537; 
	int RetVal = 2; 
	return verify_case(RetVal, BinaryFlips().minimalMoves(A, B, K)); }
int Test_(Case_<9>) {
    timer_clear();
	int A = 99999; 
	int B = 100000; 
	int K = 65537; 
	int RetVal = 3; 
	return verify_case(RetVal, BinaryFlips().minimalMoves(A, B, K)); }
int Test_(Case_<10>) {
    timer_clear();
	int A = 99999; 
	int B = 100000; 
	int K = 65536; 
	int RetVal = -1; 
	return verify_case(RetVal, BinaryFlips().minimalMoves(A, B, K)); }
int Test_(Case_<11>) {
    timer_clear();
	int A = 100000; 
	int B = 100000; 
	int K = 2; 
	int RetVal = 50000; 
	return verify_case(RetVal, BinaryFlips().minimalMoves(A, B, K)); }

template<int N> void Run_() { cerr << "Test Case #" << N << "..." << flush; Test_(Case_<N>()); Run_<sizeof(Test_(Case_<N+1>()))==1 ? -1 : N+1>(); }
template<>      void Run_<-1>() {}
int main() { Run_<0>(); }
// END CUT HERE


// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// You are playing a game where you initially have A zeros and B ones.  Your goal is to end up with all ones.  In each move, you must choose exactly K of the numbers and flip their values (zeros change to ones, and vice-versa).  You can choose any K numbers each time, regardless of their current values or whether you have flipped them before.  Return the minimal number of moves required to win the game, or -1 if it is impossible.


DEFINITION
Class:BinaryFlips
Method:minimalMoves
Parameters:int, int, int
Returns:int
Method signature:int minimalMoves(int A, int B, int K)


CONSTRAINTS
-A will be between 0 and 100,000, inclusive.
-B will be between 0 and 100,000, inclusive.
-K will be between 1 and 100,000, inclusive.


EXAMPLES

0)
3
0
3

Returns: 1

You initially have 3 zeros and 0 ones, and you must flip 3 numbers in each move.  Your only possible move is to flip every number.  After the first move, you end up with all ones and win the game.


1)
4
0
3

Returns: 4

This is similar to the previous example, but this time, you have 4 zeros.  Here's one minimal sequence of moves that will lead to a win:

0. 0000 (the initial state)
1. 1110 (first three numbers flipped)
2. 1001 (last three numbers flipped)
3. 0100 (first, second and fourth numbers flipped)
4. 1111 (first, third and fourth numbers flipped)


2)
4
1
3

Returns: 2

3)
3
2
5

Returns: -1

4)
100000
100000
578

Returns: 174

5)
0
0
1

Returns: 0

6)
4
44
50

Returns: -1
*/
// END CUT HERE
