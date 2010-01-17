#line 2 "FindingSquareInTable.cpp"
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
#define found(s,e)  ((s).find(e)!=(s).end())

class FindingSquareInTable {
  set<int> psqs;
  bool psq(int n){ return found(psqs,n) ? true : false; }
 public:
  int findMaximalSquare(vector<string> table) {
    for(int i=0;i<=31622; i++) psqs.insert(i*i);

    int maxn = -1;
    int h=sz(table), w=sz(table[0]);
	vector<vector<int> > t(h);
    rep(i,h) { t[i].resize(w); rep(j,w) t[i][j] = table[i][j] - '0'; }
    rep(j0,h) rep(i0,w){
      for(int sy=-(h-1);sy<=h-1;sy++){
        for(int sx=-(w-1);sx<=w-1;sx++){
          int j=j0, i=i0;
          int n=t[j][i];
          if(sx==0 && sy==0) goto jm;
          while(true){
            i+=sx; j+=sy;
            if (i < 0 || w <= i || j < 0 || h <= j) break;
            n = n*10 + t[j][i];
          }
       jm:
          if (psq(n)) maxn = max(maxn,n);
        }
      }
    }
    return maxn;
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
	string table_[] = {"123",
 "456"};
	  vector <string> table(table_, table_+sizeof(table_)/sizeof(*table_)); 
	int RetVal = 64; 
	return verify_case(RetVal, FindingSquareInTable().findMaximalSquare(table)); }
int Test_(Case_<1>) {
	timer_clear();
	string table_[] = {"00000",
 "00000",
 "00200",
 "00000",
 "00000"};
	  vector <string> table(table_, table_+sizeof(table_)/sizeof(*table_)); 
	int RetVal = 0; 
	return verify_case(RetVal, FindingSquareInTable().findMaximalSquare(table)); }
int Test_(Case_<2>) {
	timer_clear();
	string table_[] = {"3791178",
 "1283252",
 "4103617",
 "8233494",
 "8725572",
 "2937261"};
	  vector <string> table(table_, table_+sizeof(table_)/sizeof(*table_)); 
	int RetVal = 320356; 
	return verify_case(RetVal, FindingSquareInTable().findMaximalSquare(table)); }
int Test_(Case_<3>) {
	timer_clear();
	string table_[] = {"135791357",
 "357913579",
 "579135791",
 "791357913",
 "913579135"}
;
	  vector <string> table(table_, table_+sizeof(table_)/sizeof(*table_)); 
	int RetVal = 9; 
	return verify_case(RetVal, FindingSquareInTable().findMaximalSquare(table)); }
int Test_(Case_<4>) {
	timer_clear();
	string table_[] = {"553333733",
 "775337775",
 "777537775",
 "777357333",
 "755553557",
 "355533335",
 "373773573",
 "337373777",
 "775557777"};
	  vector <string> table(table_, table_+sizeof(table_)/sizeof(*table_)); 
	int RetVal = -1; 
	return verify_case(RetVal, FindingSquareInTable().findMaximalSquare(table)); }
int Test_(Case_<5>) {
	timer_clear();
	string table_[] = {"257240281",
 "197510846",
 "014345401",
 "035562575",
 "974935632",
 "865865933",
 "684684987",
 "768934659",
 "287493867"};
	  vector <string> table(table_, table_+sizeof(table_)/sizeof(*table_)); 
	int RetVal = 95481; 
	return verify_case(RetVal, FindingSquareInTable().findMaximalSquare(table)); }

template<int N> void Run_() { cerr << "Test Case #" << N << "..." << flush; Test_(Case_<N>()); Run_<sizeof(Test_(Case_<N+1>()))==1 ? -1 : N+1>(); }
template<>      void Run_<-1>() {}
int main() { Run_<0>(); }
// END CUT HERE


// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// You are given a vector <string> table representing a rectangular grid where each cell contains a digit.  The j-th character of the i-th element of table is the digit in the cell at row i, column j of the grid.

Consider a sequence of distinct cells in this table where the row numbers of the cells (in the order they appear in the sequence) form an arithmetic progression, and the column numbers also form an arithmetic progression.  Concatenate the digits in the cells of this sequence to obtain a number.

Among all numbers that can be obtained in this manner, find and return the largest perfect square (a square of an integer).  If there are no perfect squares, return -1 instead.

DEFINITION
Class:FindingSquareInTable
Method:findMaximalSquare
Parameters:vector <string>
Returns:int
Method signature:int findMaximalSquare(vector <string> table)


NOTES
-An arithmetic progression is a sequence of numbers where the difference between each number and the previous number is constant.


CONSTRAINTS
-table will contain between 1 and 9 elements, inclusive.
-Each element of table will contain between 1 and 9 characters, inclusive.
-All elements of table will be of the same length.
-Each element of table will contain only digits ('0'-'9').


EXAMPLES

0)
{"123",
 "456"}

Returns: 64

Several three-digit numbers can be obtained: 123, 321, 456, and 654, but none of them is a perfect square.
The largest obtainable perfect square is 64.

1)
{"00000",
 "00000",
 "00200",
 "00000",
 "00000"}

Returns: 0

0 is a perfect square. It is the largest one that can be obtained in this table.

2)
{"3791178",
 "1283252",
 "4103617",
 "8233494",
 "8725572",
 "2937261"}

Returns: 320356

Take the i-th digit of each row i, and you'll get 320356 = 566 × 566.

3)
{"135791357",
 "357913579",
 "579135791",
 "791357913",
 "913579135"}


Returns: 9

It is known that a perfect square can't end with two odd digits. Therefore, the largest perfect square that contains only odd digits is 9.

4)
{"553333733",
 "775337775",
 "777537775",
 "777357333",
 "755553557",
 "355533335",
 "373773573",
 "337373777",
 "775557777"}

Returns: -1

There exists no perfect square that contains only digits 3, 5, and 7.

5)
{"257240281",
 "197510846",
 "014345401",
 "035562575",
 "974935632",
 "865865933",
 "684684987",
 "768934659",
 "287493867"}

Returns: 95481

The sequence of digits that forms 95481 is shown in bold:
257240281
197510846
014345401
035562575
974935632
865865933
684684987
768934659
287493867

*/
// END CUT HERE
