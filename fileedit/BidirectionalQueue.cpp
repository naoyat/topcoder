#line 2 "BidirectionalQueue.cpp"
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
#define tr(c,i)  for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); i++)
#define rep(var,n)  for(int var=0;var<(n);var++)

class BidirectionalQueue {
 public:
  int extractElements(int N, vector<int> ids) {
	int n=sz(ids);
    tr(ids,it) (*it)--;
    vector<int> q(N,0);
    rep(i,N) q[i]=i;
    int cur=0, cnt=0;
// BEGIN CUT HERE
    //int mx=*max_element(all(ids));
    //    cout << "ids:" << ids << endl;
    //printf("N=%d, n=%d, mx=%d\n", N,n,mx);
// END CUT HERE
    rep(i,n){
// BEGIN CUT HERE
      //      cout << "i:" << i << ", q:" << q << ", cur:" << cur << endl;
// END CUT HERE
      int hf=N/2;
      int tf=ids[i],at=-1;
      rep(j,N) if (q[j]==tf) {at=j;break;}
      int ofs=at-cur;
      if (ofs>hf) ofs-=N;
      else if (ofs<-hf) ofs+=N;
      cnt += abs(ofs);
// BEGIN CUT HERE
      //      cout << " found "<< tf << " at " << at << endl;
// END CUT HERE
      for(int j=at;j<N-1;j++) q[j]=q[j+1];
      N--;
      cur=at; if (cur==N) cur=0;
    }
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
	int N = 10; 
	int indices_[] = {1, 2, 3};
	  vector <int> indices(indices_, indices_+sizeof(indices_)/sizeof(*indices_)); 
	int RetVal = 0; 
	return verify_case(RetVal, BidirectionalQueue().extractElements(N, indices)); }
int Test_(Case_<1>) {
	timer_clear();
	int N = 10; 
	int indices_[] = {2, 9, 5};
	  vector <int> indices(indices_, indices_+sizeof(indices_)/sizeof(*indices_)); 
	int RetVal = 8; 
	return verify_case(RetVal, BidirectionalQueue().extractElements(N, indices)); }
int Test_(Case_<2>) {
	timer_clear();
	int N = 32; 
	int indices_[] = {27, 16, 30, 11, 6, 23};
	  vector <int> indices(indices_, indices_+sizeof(indices_)/sizeof(*indices_)); 
	int RetVal = 59; 
	return verify_case(RetVal, BidirectionalQueue().extractElements(N, indices)); }
int Test_(Case_<3>) {
	timer_clear();
	int N = 10; 
	int indices_[] = {1, 6, 3, 2, 7, 9, 8, 4, 10, 5};
	  vector <int> indices(indices_, indices_+sizeof(indices_)/sizeof(*indices_)); 
	int RetVal = 14; 
	return verify_case(RetVal, BidirectionalQueue().extractElements(N, indices)); }
int Test_(Case_<4>) {
	timer_clear();
	int N = 1; 
	int indices_[] = {1};
	  vector <int> indices(indices_, indices_+sizeof(indices_)/sizeof(*indices_)); 
	int RetVal = 0; 
	return verify_case(RetVal, BidirectionalQueue().extractElements(N, indices)); }
int Test_(Case_<5>) {
	timer_clear();
	int N = 50; 
	int indices_[] = {1, 6, 3, 2, 7, 9, 8, 4, 10, 5};
	  vector <int> indices(indices_, indices_+sizeof(indices_)/sizeof(*indices_)); 
	int RetVal = 16;
	return verify_case(RetVal, BidirectionalQueue().extractElements(N, indices)); }
int Test_(Case_<6>) {
	timer_clear();
	int N = 50;
	int indices_[] = {50,49,48,47,46,45,44,43,42,41,
                      40,39,38,37,36,35,34,33,32,31,
                      30,29,28,27,26,25,24,23,22,21,
                      20,19,18,17,16,15,14,13,12,11,
                      10,9,8,7,6,5,4,3,2,1};
    vector <int> indices(indices_, indices_+sizeof(indices_)/sizeof(*indices_)); 
	int RetVal = 49;
	return verify_case(RetVal, BidirectionalQueue().extractElements(N, indices)); }

template<int N> void Run_() { cerr << "Test Case #" << N << "..." << flush; Test_(Case_<N>()); Run_<sizeof(Test_(Case_<N+1>()))==1 ? -1 : N+1>(); }
template<>      void Run_<-1>() {}
int main() { Run_<0>(); }
// END CUT HERE


// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// You are given a bidirectional cyclical queue which contains N elements. You need to extract several elements from this queue.

You can do 3 kinds of operations with this queue:

Extract first element. After applying this operation, queue a1, ..., aK becomes a2, ..., aK.

Shift queue elements left. After applying this operation, queue a1, ..., aK becomes a2, ..., aK, a1.

Shift queue elements right. After applying this operation, queue a1, ..., aK becomes aK, a1, ..., aK-1.

You are given the initial number of elements in the queue N and a vector <int> indices which contains the initial (1-based) positions of wanted elements in the queue. Return the minimal number of left and right shifts you'll have to perform to extract the wanted elements in the given order.

DEFINITION
Class:BidirectionalQueue
Method:extractElements
Parameters:int, vector <int>
Returns:int
Method signature:int extractElements(int N, vector <int> indices)


CONSTRAINTS
-N will be between 1 and 50, inclusive.
-indices will contain between 1 and N elements, inclusive.
-Each element of indices will be between 1 and N, inclusive.
-All elements of indices will be distinct.


EXAMPLES

0)
10
{1, 2, 3}

Returns: 0

The elements are extracted in the same order as they appear in the queue, so no shifts are required.

1)
10
{2, 9, 5}

Returns: 8

To extract the first wanted element, 1 left shift is required. After this the next wanted element will be 7th in a queue with 9 elements, so to extract it 3 right shifts are required. Finally, the last wanted element will be 5th in a queue with 8 elements, so either 4 left shifts or 4 right shifts are required.

2)
32
{27, 16, 30, 11, 6, 23}

Returns: 59



3)
10
{1, 6, 3, 2, 7, 9, 8, 4, 10, 5}

Returns: 14



*/
// END CUT HERE
