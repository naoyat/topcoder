#line 2 "TwistedMatrix.cpp"
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
void pp(vector<string> u, string label){
  cout << label << ":" << endl;
  tr(u,t){
    cout << " | " << *t << " | " << endl;
  }
}
// END CUT HERE

ll ubin(const string& s){
  ll n=0LL;
  for (int i=0,c=sz(s); i<c; i++){
    n = (n<<1LL) | (s[i]-'0');
  }
  return n;
}
vector<ll> lex(const vector<string>& A){
  int n=sz(A);
  vector<ll> v(n,0LL);
  rep(i,n){
    v[i] = ubin(A[i]);
  }
  return v;
}
vector<string> turn(const vector<string>& A,int xmin,int ymin,int dir){
  vector<string> At(all(A));
  switch(dir){
    case 1: // cw
      At[ymin][xmin]     = A[ymin+1][xmin];
      At[ymin][xmin+1]   = A[ymin][xmin];
      At[ymin+1][xmin]   = A[ymin+1][xmin+1];
      At[ymin+1][xmin+1] = A[ymin][xmin+1];
      break;
    case -1: // ccw
      At[ymin][xmin]     = A[ymin][xmin+1];
      At[ymin][xmin+1]   = A[ymin+1][xmin+1];
      At[ymin+1][xmin]   = A[ymin][xmin];
      At[ymin+1][xmin+1] = A[ymin+1][xmin];
      break;
  }
  pp(At,"At");
  return At;
}

class TwistedMatrix {
  int N,M;
 public:
  int d(int c1, int c2){
    if (c1==c2) return 0;
    if (c2=='?') return 9;
    return c2-c1;
  }
  vector <string> solve(vector <string> A, vector <string> B) {
// BEGIN CUT HERE
    pp(A,"A");
    pp(B,"B");
    // N, M: 2-30
// END CUT HERE
	N=sz(A);
    M=sz(A[0]);
    vector<vector<int> > diff(N,vector<int>(M,0));
    int xmin=99,xmax=-1,ymin=99,ymax=-1;
    rep(n,N){
      rep(m,M){
        int z = diff[n][m] = d(A[n][m],B[n][m]);
        if (z==1 || z==-1) {
          ymin = min(ymin,n); ymax = max(ymax,n);
          xmin = min(xmin,m); xmax = max(xmax,m);
        }
      }
    }
// BEGIN CUT HERE
    cout << diff << endl;
    printf("y: %d..%d // %d\n", ymin,ymax, N);
    printf("x: %d..%d // %d\n", xmin,xmax, M);
// END CUT HERE
    int dx = xmax-xmin+1, dy = ymax-ymin+1;

    vector<string> ans(0);
    if (dx>2 || dy>2) return ans;
    else if (dx==2 && dy==2){
      vector<string> At1 = turn(A,xmin,ymin,1),
          At2 = turn(A,xmin,ymin,-1);
      return (lex(At1) <= lex(At2))? At1 : At2;
    } else if (dx==2 && dy==1) {
    } else if (dx==1 && dy==2) {
    } else if (dx==1 && dy==1) {
    } else {
      vector<ll> minlex(N, (1LL << M) - 1LL);
      rep(n,N-1){
        rep(m,M-1){
          vector<string> At1 = turn(A,m,n,1), At2 = turn(A,m,n,-1);
          if (lex(At1) < minlex) { ans = At1; minlex = lex(At1); }
          if (lex(At2) < minlex) { ans = At1; minlex = lex(At2); }
        }
      }
      return ans;
      // 任意
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
	string A_[] = {"1000",
 "0000",
 "0000",
 "0000"};
	  vector <string> A(A_, A_+sizeof(A_)/sizeof(*A_)); 
	string B_[] = {"0000",
 "?000",
 "0000",
 "0000"};
	  vector <string> B(B_, B_+sizeof(B_)/sizeof(*B_)); 
	string RetVal_[] = {"0000", "1000", "0000", "0000" };
	  vector <string> RetVal(RetVal_, RetVal_+sizeof(RetVal_)/sizeof(*RetVal_)); 
	return verify_case(RetVal, TwistedMatrix().solve(A, B)); }
int Test_(Case_<1>) {
	timer_clear();
	string A_[] = {"11",
 "01"};
	  vector <string> A(A_, A_+sizeof(A_)/sizeof(*A_)); 
	string B_[] = {"??",
 "??"};
	  vector <string> B(B_, B_+sizeof(B_)/sizeof(*B_)); 
	string RetVal_[] = {"01", "11" };
	  vector <string> RetVal(RetVal_, RetVal_+sizeof(RetVal_)/sizeof(*RetVal_)); 
	return verify_case(RetVal, TwistedMatrix().solve(A, B)); }
int Test_(Case_<2>) {
	timer_clear();
	string A_[] = {"000",
 "0?0",
 "000"};
	  vector <string> A(A_, A_+sizeof(A_)/sizeof(*A_)); 
	string B_[] = {"111",
 "1?1",
 "111"};
	  vector <string> B(B_, B_+sizeof(B_)/sizeof(*B_)); 
	vector <string> RetVal; 
	return verify_case(RetVal, TwistedMatrix().solve(A, B)); }
int Test_(Case_<3>) {
	timer_clear();
	string A_[] = {"?1111",
 "11111",
 "11011",
 "10111"};
	  vector <string> A(A_, A_+sizeof(A_)/sizeof(*A_)); 
	string B_[] = {"?1111",
 "11111",
 "1??11",
 "1??11"};
	  vector <string> B(B_, B_+sizeof(B_)/sizeof(*B_)); 
	string RetVal_[] = {"01111", "11111", "10011", "11111" };
	  vector <string> RetVal(RetVal_, RetVal_+sizeof(RetVal_)/sizeof(*RetVal_)); 
	return verify_case(RetVal, TwistedMatrix().solve(A, B)); }
int Test_(Case_<4>) {
	timer_clear();
	string A_[] = {"00111",
 "00111",
 "11111",
 "11111"};
	  vector <string> A(A_, A_+sizeof(A_)/sizeof(*A_)); 
	string B_[] = {"??1??",
 "??1??",
 "?????",
 "?????"};
	  vector <string> B(B_, B_+sizeof(B_)/sizeof(*B_)); 
	string RetVal_[] = {"00111", "00111", "11111", "11111" };
	  vector <string> RetVal(RetVal_, RetVal_+sizeof(RetVal_)/sizeof(*RetVal_)); 
	return verify_case(RetVal, TwistedMatrix().solve(A, B)); }

template<int N> void Run_() { cerr << "Test Case #" << N << "..." << flush; Test_(Case_<N>()); Run_<sizeof(Test_(Case_<N+1>()))==1 ? -1 : N+1>(); }
template<>      void Run_<-1>() {}
int main() { Run_<0>(); }
// END CUT HERE


// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// NOTE: This problem statement contains images that may not display properly if viewed outside of the applet.

"Twisted Matrix" is a strange game in which you are given a binary matrix (containing only '1' or '0') and must perform a series of twist operations in order to reach a certain goal matrix. A twist operation involves taking any 2x2 block inside the matrix and then rotating the elements within the block 90 degrees clockwise or counterclockwise.
The following image shows two consecutive twist operations performed on a initial matrix.


Little Johnny has won the first prize in a world wide Twisted Matrix tournament. Unfortunately, his friends do not believe him. The situation is not helped by the fact that little Johnny has a very bad memory and cannot clearly remember the last move he made in order to reach the goal matrix in the finals. He only partially remembers the last two matrices in the game. You are given matrices A and B. Each matrix is given as vector <string>, the j-th character of the i-th element of each vector <string> describes the cell at row i, column j of the matrix. Each cell contains '0' or '1' if little Johnny remembers the number in that cell or '?' otherwise. Matrix B was the last matrix in the game and A was the matrix preceeding it, which means that performing one twist operation on A must transform it into B. Return a vector <string> representing the complete contents of the matrix B. If there are many valid solutions then return the lexicographically first solution. If no solution is possible then return an empty vector <string>.

DEFINITION
Class:TwistedMatrix
Method:solve
Parameters:vector <string>, vector <string>
Returns:vector <string>
Method signature:vector <string> solve(vector <string> A, vector <string> B)


NOTES
-The lexicographically first of two matrices is the one with the lexicographically earlier row at the first row at which they differ.
-The lexicographically first of two rows is the one with the smaller cell at the first column at which they differ.


CONSTRAINTS
-A and B will each contain N elements, where N is between 2 and 30, inclusive.
-Each element of A and B will contain M characters, where M is between 2 and 30, inclusive.
-Each character in each element of A and B will be '1', '0' or '?'.


EXAMPLES

0)
{"1000",
 "0000",
 "0000",
 "0000"}
{"0000",
 "?000",
 "0000",
 "0000"}

Returns: {"0000", "1000", "0000", "0000" }



1)
{"11",
 "01"}
{"??",
 "??"}

Returns: {"01", "11" }

Another possibility is {"11","10"} but {"01","11"} comes earlier lexicographically.

2)
{"000",
 "0?0",
 "000"}
{"111",
 "1?1",
 "111"}

Returns: { }



3)
{"?1111",
 "11111",
 "11011",
 "10111"}
{"?1111",
 "11111",
 "1??11",
 "1??11"}

Returns: {"01111", "11111", "10011", "11111" }



4)
{"00111",
 "00111",
 "11111",
 "11111"}
{"??1??",
 "??1??",
 "?????",
 "?????"}

Returns: {"00111", "00111", "11111", "11111" }

In order to get the lexicographically earliest solution, you must rotate the 2x2 block containing only zeros. Note that this movement does not modify the matrix, but it is still valid.

*/
// END CUT HERE
