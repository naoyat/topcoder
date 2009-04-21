#line 2 "CellRemoval.cpp"
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
#define tr(c,i)  for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); i++)
#define rep(var,n)  for(int var=0;var<(n);var++)

class CellRemoval {
  int N;
  vector<bool> ch,m;
 public:
  int cellsLeft(vector<int> parent, int deletedCell) {
    N=sz(parent);
    ch.resize(N);m.resize(N); rep(i,N) ch[i]=m[i]=false;
    queue<int> q;
    rep(j,N)if(parent[j]==-1){ch[j]=true;q.push(j);break;}
    while(!q.empty()){
      int t=q.front(); q.pop();
      if(t==deletedCell){ch[t]=false;continue;}
      rep(j,N){
        if(parent[j]==t){m[t]=true;ch[j]=true;q.push(j);}
      }
    }
    int cnt=0; rep(j,N) if(ch[j]==true&&m[j]==false)cnt++;
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
	int parent_[] = {-1,0,0,1,1};
	  vector <int> parent(parent_, parent_+sizeof(parent_)/sizeof(*parent_)); 
	int deletedCell = 2; 
	int RetVal = 2; 
	return verify_case(RetVal, CellRemoval().cellsLeft(parent, deletedCell)); }
int Test_(Case_<1>) {
	timer_clear();
	int parent_[] = {-1,0,0,1,1};
	  vector <int> parent(parent_, parent_+sizeof(parent_)/sizeof(*parent_)); 
	int deletedCell = 1; 
	int RetVal = 1; 
	return verify_case(RetVal, CellRemoval().cellsLeft(parent, deletedCell)); }
int Test_(Case_<2>) {
	timer_clear();
	int parent_[] = {-1,0,0,1,1};
	  vector <int> parent(parent_, parent_+sizeof(parent_)/sizeof(*parent_)); 
	int deletedCell = 0; 
	int RetVal = 0; 
	return verify_case(RetVal, CellRemoval().cellsLeft(parent, deletedCell)); }
int Test_(Case_<3>) {
	timer_clear();
	int parent_[] = {-1,0,0,2,2,4,4,6,6};
	  vector <int> parent(parent_, parent_+sizeof(parent_)/sizeof(*parent_)); 
	int deletedCell = 4; 
	int RetVal = 2; 
	return verify_case(RetVal, CellRemoval().cellsLeft(parent, deletedCell)); }
int Test_(Case_<4>) {
	timer_clear();
	int parent_[] = {26,2,32,36,40,19,43,24,30,13,21,14,24,21,19,4,30,10,44,12,7,32,17,43,
 35,18,7,36,10,16,5,38,35,4,13,-1,16,26,1,12,2,5,18,40,1,17,38,44,14};
	  vector <int> parent(parent_, parent_+sizeof(parent_)/sizeof(*parent_)); 
	int deletedCell = 24; 
	int RetVal = 14; 
	return verify_case(RetVal, CellRemoval().cellsLeft(parent, deletedCell)); }
int Test_(Case_<5>) {
	timer_clear();
	int parent_[] = {2,2,4,4,6,6,8,8,10,10,12,12,14,14,16,16,18,18,20,20,22,22,24,24,26,26,28,28,30,30,32,32,34,34,36,36,38,38,40,40,42,42,44,44,46,46,48,48,-1};
	  vector <int> parent(parent_, parent_+sizeof(parent_)/sizeof(*parent_)); 
	int deletedCell = 48;
	int RetVal = 0;
	return verify_case(RetVal, CellRemoval().cellsLeft(parent, deletedCell)); }
int Test_(Case_<6>) {
	timer_clear();
	int parent_[] = {2,2,4,4,6,6,8,8,10,10,12,12,14,14,16,16,18,18,20,20,22,22,24,24,26,26,28,28,30,30,32,32,34,34,36,36,38,38,40,40,42,42,44,44,46,46,48,48,-1};
	  vector <int> parent(parent_, parent_+sizeof(parent_)/sizeof(*parent_)); 
	int deletedCell = 2;
	int RetVal = 23;
	return verify_case(RetVal, CellRemoval().cellsLeft(parent, deletedCell)); }

template<int N> void Run_() { cerr << "Test Case #" << N << "..." << flush; Test_(Case_<N>()); Run_<sizeof(Test_(Case_<N+1>()))==1 ? -1 : N+1>(); }
template<>      void Run_<-1>() {}
int main() { Run_<0>(); }
// END CUT HERE


// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// In biology, organisms have the following property: Starting from the first cell (the zygote), each cell during an organism's development process either divides into 2 other cells or does not divide at all.  An organism is mature when all of its cells will not divide any further.

Let's assign a unique number to each cell in an organism's development process.  For example, consider a species in which each organism starts with cell 0, which divides into cells 1 and 2.  Cell 1 divides into cells 3 and 4.  Cells 2, 3 and 4 do not divide.  Every mature organism of this species will consist of exactly 3 cells - 2, 3 and 4.


During the development process, if we kill a cell, it will be absent in the mature form of the organism.  If that cell happens to be a cell that divides, then the mature organism will be missing all of the cell's descendants as well because the cell is killed before it has a chance to divide.  For example, in the organism described above, if we kill cell 1 during the development process, the mature organism will contain only cell 2.



You are given a vector <int> parentCell describing the development process of an organism.  The i-th element of parentCell is the parent cell of cell i (where i is a 0-based index).  The zygote's parent is -1.  Return the number of cells the mature form of this organism would have if you killed cell deletedCell during the development process.

DEFINITION
Class:CellRemoval
Method:cellsLeft
Parameters:vector <int>, int
Returns:int
Method signature:int cellsLeft(vector <int> parent, int deletedCell)


CONSTRAINTS
-parentCell will contain exactly N elements, where N is an odd integer between 1 and 50, inclusive.
-There will be exactly one "-1" element in parentCell.
-Every element of parentCell will be between -1 and N-1, inclusive.
-parentCell will form a binary tree.
-deletedCell will be between 0 and N-1, inclusive.


EXAMPLES

0)
{-1,0,0,1,1}
2

Returns: 2

This is the example organism from the problem statement.  If we kill cell 2, there will still be two cells left (3 and 4).

1)
{-1,0,0,1,1}
1

Returns: 1

This is the example organism from the problem statement.  If we kill cell 1, the only cell left will be cell 2.  Cells 3 and 4 will not exist because cell 1 is their ancestor.

2)
{-1,0,0,1,1}
0

Returns: 0

If we kill the zygote, there is nothing left.

3)
{-1,0,0,2,2,4,4,6,6}
4

Returns: 2



4)
{26,2,32,36,40,19,43,24,30,13,21,14,24,21,19,4,30,10,44,12,7,32,17,43,
 35,18,7,36,10,16,5,38,35,4,13,-1,16,26,1,12,2,5,18,40,1,17,38,44,14}
24

Returns: 14



*/
// END CUT HERE
