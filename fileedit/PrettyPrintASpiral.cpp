#line 2 "PrettyPrintASpiral.cpp"
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

class PrettyPrintASpiral {
  vector<vector<int> > mx;
  
  int num(int c, int r){
    // 0 1 2
    // 1 3 5
    int t=max(abs(c),abs(r));
    int t2 = t*2;

    int te=(2*t+1)*(2*t+1);
    if (c==t&&r==t) return te;

    int tb=(2*t-1)*(2*t-1); if(t==0) tb=0;
    if(c==t) return tb+(t-r);
    tb+=t2;
    if(r==-t) return tb+(t-c);
    tb+=t2;
    if(c==-t) return tb+(t+r);
    tb+=t2;
    return tb+(t+c);
  }
  int k(int x){
    int kt=0;
    while(x){kt++;x/=10;}
    return kt;
  }
 public:
  vector<string> getWindow(int row1, int col1, int row2, int col2) {
    int rows = 1+row2-row1,
        cols = 1+col2-col1;
    int maxn = max( max( num(col1,row1), num(col1,row2) ),
                    max( num(col2,row1), num(col2,row2) ) ),
        maxk = k(maxn), w=maxk+1;
    
    //printf("k(%d) =%d\n", maxn,maxk);
    vector<string> ans(rows);
    char buf[w*cols];
    for(int r=row1;r<=row2;r++){
      for(int c=col1;c<=col2;c++){
        int n=num(c,r);
        char *b = &buf[w*(c-col1)] + maxk;
        *b-- = (c==col2)? '\0':' ';
        rep(i,maxk){
          *b-- = (n>0)? ('0'+(n%10)) : ' ';
          n/=10;
        }
      }
      ans[r-row1] = buf;
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
	int row1 = 0; 
	int col1 = 0; 
	int row2 = 0; 
	int col2 = 0; 
	string RetVal_[] = {"1" };
	  vector <string> RetVal(RetVal_, RetVal_+sizeof(RetVal_)/sizeof(*RetVal_)); 
	return verify_case(RetVal, PrettyPrintASpiral().getWindow(row1, col1, row2, col2)); }
int Test_(Case_<1>) {
	timer_clear();
	int row1 = -1; 
	int col1 = -2; 
	int row2 = -1; 
	int col2 = 1; 
	string RetVal_[] = {"18  5  4  3" };
	  vector <string> RetVal(RetVal_, RetVal_+sizeof(RetVal_)/sizeof(*RetVal_)); 
	return verify_case(RetVal, PrettyPrintASpiral().getWindow(row1, col1, row2, col2)); }
int Test_(Case_<2>) {
	timer_clear();
	int row1 = -2; 
	int col1 = 2; 
	int row2 = 0; 
	int col2 = 3; 
	string RetVal_[] = {"13 30", "12 29", "11 28" };
	  vector <string> RetVal(RetVal_, RetVal_+sizeof(RetVal_)/sizeof(*RetVal_)); 
	return verify_case(RetVal, PrettyPrintASpiral().getWindow(row1, col1, row2, col2)); }
int Test_(Case_<3>) {
	timer_clear();
	int row1 = -3; 
	int col1 = -3; 
	int row2 = 2; 
	int col2 = 0; 
	string RetVal_[] = {"37 36 35 34", "38 17 16 15", "39 18  5  4", "40 19  6  1", "41 20  7  8", "42 21 22 23" };
	  vector <string> RetVal(RetVal_, RetVal_+sizeof(RetVal_)/sizeof(*RetVal_)); 
	return verify_case(RetVal, PrettyPrintASpiral().getWindow(row1, col1, row2, col2)); }
int Test_(Case_<4>) {
	timer_clear();
	int row1 = -5000;
	int col1 = -5000;
	int row2 = -5000;
	int col2 = -5000;
	string RetVal_[] = {"37 36 35 34", "38 17 16 15", "39 18  5  4", "40 19  6  1", "41 20  7  8", "42 21 22 23" };
	  vector <string> RetVal(RetVal_, RetVal_+sizeof(RetVal_)/sizeof(*RetVal_)); 
	return verify_case(RetVal, PrettyPrintASpiral().getWindow(row1, col1, row2, col2)); }
int Test_(Case_<5>) {
	timer_clear();
	int row1 = -5000;
	int col1 = -5000;
	int row2 = -5000+49;
	int col2 = -5000+4;
	string RetVal_[] = {"37 36 35 34", "38 17 16 15", "39 18  5  4", "40 19  6  1", "41 20  7  8", "42 21 22 23" };
	  vector <string> RetVal(RetVal_, RetVal_+sizeof(RetVal_)/sizeof(*RetVal_)); 
	return verify_case(RetVal, PrettyPrintASpiral().getWindow(row1, col1, row2, col2)); }

template<int N> void Run_() { cerr << "Test Case #" << N << "..." << flush; Test_(Case_<N>()); Run_<sizeof(Test_(Case_<N+1>()))==1 ? -1 : N+1>(); }
template<>      void Run_<-1>() {}
int main() { Run_<0>(); }
// END CUT HERE


// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
Consider an infinite square grid. Each square in the grid can be represented by a pair of integer coordinates that specify its row and column.



We will fill the entire grid with a spiral of positive integers. We will start by writing the number 1 into the square in row 0, column 0. Then we will write the number 2 into the square in row 0, column 1. From there, the spiral will continue in a counter-clockwise direction. The next few numbers are placed as shown in the scheme below:



                columns
         -3 -2 -1  0  1  2  3
         --------------------
    -3 | 37 36 35 34 33 32 31
    -2 | 38 17 16 15 14 13 30
    -1 | 39 18  5  4  3 12 29
rows 0 | 40 19  6  1  2 11 28
     1 | 41 20  7  8  9 10 27
     2 | 42 21 22 23 24 25 26
     3 | 43 44 45 46 .. .. ..



Your task will be to return a vector <string> containing a pretty-printed version of a rectangular part of the filled grid.



More precisely, you will be given four ints row1, col1, row2, and col2. Here, row1,col1 will be the coordinates of the top left cell, and 
row2,col2 the coordinates of the bottom right cell to be displayed.



The returned vector <string> must be formatted according to the following rules:



The vector <string> contains one element for each row of the displayed rectangle. The elements are ordered by the row coordinate they describe.
Each element is a concatenation of space-separated tokens, each describing a cell in the corresponding row. The tokens are ordered by the column coordinates of cells they describe.
All tokens in the entire output have the same length.
The length of a token is minimal, i.e., equal to the number of digits in the largest number displayed.
Tokens that contain numbers with fewer digits are padded from the left using spaces.


DEFINITION
Class:PrettyPrintASpiral
Method:getWindow
Parameters:int, int, int, int
Returns:vector <string>
Method signature:vector <string> getWindow(int row1, int col1, int row2, int col2)


NOTES
-The constraints guarantee that the returned vector <string> will have at most 50 elements, and the length of each element will be at most 50.


CONSTRAINTS
-row1 will be between -5,000 and 5,000, inclusive.
-col1 will be between -5,000 and 5,000, inclusive.
-row2 will be between -5,000 and 5,000, inclusive.
-col2 will be between -5,000 and 5,000, inclusive.
-row2-row1 will be between 0 and 49, inclusive.
-col2-col1 will be between 0 and 4, inclusive.


EXAMPLES

0)
0
0
0
0

Returns: {"1" }

The spiral starts at coordinates (0,0).

1)
-1
-2
-1
1

Returns: {"18  5  4  3" }

Note that the single-digit values are now padded with spaces.

2)
-2
2
0
3

Returns: {"13 30", "12 29", "11 28" }



3)
-3
-3
2
0

Returns: {"37 36 35 34", "38 17 16 15", "39 18  5  4", "40 19  6  1", "41 20  7  8", "42 21 22 23" }



*/
// END CUT HERE
