// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// In The Sorting Game, you are given a sequence containing a permutation of the integers between 1 and n, inclusive.  In one move, you can take any k consecutive elements of the sequence and reverse their order.  The goal of the game is to sort the sequence in ascending order.  You are given a vector <int> board describing the initial sequence.  Return the fewest number of moves necessary to finish the game successfully, or -1 if it's impossible.

DEFINITION
Class:SortingGame
Method:fewestMoves
Parameters:vector <int>, int
Returns:int
Method signature:int fewestMoves(vector <int> board, int k)


CONSTRAINTS
-board will contain between 2 and 8 elements, inclusive.
-Each integer between 1 and the size of board, inclusive, will appear in board exactly once.
-k will be between 2 and the size of board, inclusive.


EXAMPLES

0)
{1,2,3}
3

Returns: 0

The sequence is already sorted, so we don't need any moves.

1)
{3,2,1}
3

Returns: 1

We can reverse the whole sequence with one move here.

2)
{5,4,3,2,1}
2

Returns: 10

This one is more complex.

3)
{3,2,4,1,5}
4

Returns: -1



4)
{7,2,1,6,8,4,3,5}
4

Returns: 7

*/
// END CUT HERE

#line 64 "SortingGame.cpp"
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

class SortingGame {
  int n;
  int sig(const vector<int> &b){
    int s=0;
    tr(b,it){s=s*n+(*it)-1;}
    return s;
  }
  void reset(vector<int> &b,int sig) {
    for (int i=n-1,s=sig;i>=0;i--,s/=n) b[i]=(s%n)+1;
  }

  public:
  int fewestMoves(vector<int> board, int k) {
    n=sz(board);
    int board_sig=sig(board);
    vector<int> sorted(all(board)); sort(all(sorted));
    int sorted_sig=sig(sorted);
    if(board_sig==sorted_sig) return 0;
    //return sub(board,1);
    priority_queue<pair<int,int> > pq;
    for(int b=0;b<=n-k;b++) {
      reverse(board.begin()+b,board.begin()+b+k);
      int newsig=sig(board);
      if(newsig==sorted_sig) return 1;
      pq.push(make_pair(-1,newsig));
      reset(board,board_sig);
    }
    map<int,int> visited; visited[board_sig]=0;
    while(!pq.empty()) {
      int depth=pq.top().first, sg=pq.top().second;
      pq.pop();
      if(visited.find(sg)!=visited.end()) continue;
      visited[sg]=depth;
      //printf("depth=%d, sg=%d\n", -depth, sg);
      for(int b=0;b<=n-k;b++) {
        //printf("<%d> ",-depth); cout << board;
        reset(board,sg);
        //for (int i=n-1,s=sg;i>=0;i--,s/=n) board[i]=(s%n)+1;
        //printf(", sg=%d... reversing [%d-%d] of ",sg,b,b+k); cout << board << " => " ;
        reverse(board.begin()+b,board.begin()+b+k);
        //cout << board << endl;
        int newsig=sig(board);
        if(newsig==sorted_sig) return -depth+1;
        pq.push(make_pair(depth-1,newsig));
      }
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
	int board_[] = {1,2,3};
	  vector <int> board(board_, board_+sizeof(board_)/sizeof(*board_)); 
	int k = 3; 
	int RetVal = 0; 
	return verify_case(RetVal, SortingGame().fewestMoves(board, k)); }
int Test_(Case_<1>) {
	timer_clear();
	int board_[] = {3,2,1};
	  vector <int> board(board_, board_+sizeof(board_)/sizeof(*board_)); 
	int k = 3; 
	int RetVal = 1; 
	return verify_case(RetVal, SortingGame().fewestMoves(board, k)); }
int Test_(Case_<2>) {
	timer_clear();
	int board_[] = {5,4,3,2,1};
	  vector <int> board(board_, board_+sizeof(board_)/sizeof(*board_)); 
	int k = 2; 
	int RetVal = 10; 
	return verify_case(RetVal, SortingGame().fewestMoves(board, k)); }
int Test_(Case_<3>) {
	timer_clear();
	int board_[] = {3,2,4,1,5};
	  vector <int> board(board_, board_+sizeof(board_)/sizeof(*board_)); 
	int k = 4; 
	int RetVal = -1; 
	return verify_case(RetVal, SortingGame().fewestMoves(board, k)); }
int Test_(Case_<4>) {
	timer_clear();
	int board_[] = {7,2,1,6,8,4,3,5};
	  vector <int> board(board_, board_+sizeof(board_)/sizeof(*board_)); 
	int k = 4; 
	int RetVal = 7; 
	return verify_case(RetVal, SortingGame().fewestMoves(board, k)); }

template<int N> void Run_() { cerr << "Test Case #" << N << "..." << flush; Test_(Case_<N>()); Run_<sizeof(Test_(Case_<N+1>()))==1 ? -1 : N+1>(); }
template<>      void Run_<-1>() {}
int main() { Run_<0>(); }
// END CUT HERE

