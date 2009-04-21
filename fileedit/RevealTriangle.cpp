// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
	Suppose there is a triangle of digits like the following:

74932
1325
457
92
1

	Each digit, with the exception of those in the top row, is equal to the last digit of the sum of 
	its upper and upper-right neighboring digits.


	You will be given a vector <string> questionMarkTriangle containing a triangle where 
	only one digit in each row is known and all others are represented by '?'s 
	(see example 0 for clarification).
	Each element of questionMarkTriangle represents a row of the triangle, and the rows are given 
	from top to bottom. Each element contains exactly one digit ('0'-'9') and 
	the remaining characters are all '?'s. Restore the triangle and return it as a 
	vector <string> without '?'s.



DEFINITION
Class:RevealTriangle
Method:calcTriangle
Parameters:vector <string>
Returns:vector <string>
Method signature:vector <string> calcTriangle(vector <string> questionMarkTriangle)


CONSTRAINTS
-questionMarkTriangle will contain between 1 and 50 elements, inclusive.
-Element i (0 indexed) of questionMarkTriangle will contain exactly n-i characters, where n is the number of elements in questionMarkTriangle.
-Each element of questionMarkTriangle will contain exactly one digit ('0'-'9') and all others characters will be '?'s.


EXAMPLES

0)
{"4??", 
 "?2", 
 "1"}

Returns: {"457", "92", "1" }

Let's substitute '?'s with unknown variables:

4ab 
c2 
1


Having done that, we start solving for the variables from the bottom to the top. First, we know that the last digit of (c + 2) is 1. Therefore, c must be 9:


4ab 
92 
1

Now we know that the last digit of (4 + a) is 9, which means a is 5:

45b 
92 
1


And, finally, the last digit of (5 + b) is 2, so b is 7.

1)
{"1"}

Returns: {"1" }

2)
{"???2", "??2", "?2", "2"}

Returns: {"0002", "002", "02", "2" }

3)
{"??5?", "??9", "?4", "6"}

Returns: {"7054", "759", "24", "6" }

*/
// END CUT HERE

#line 92 "RevealTriangle.cpp"
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

class RevealTriangle {
public:
  vector<string> calcTriangle(vector<string> questionMarkTriangle) {
	int rows=questionMarkTriangle.size();//1-50

	vector<vector<int> > v(rows);
	rep(row,rows){
	  v[row].resize(rows-row);
	  rep(i,rows-row){
		int c = questionMarkTriangle[row][i]-'0';
		v[row][i] = (c < 0||9<c)?-1:c;
	  }
	}

	for(int row=rows-1;row>=0;row--){
	  int l=rows-row;
	  string qmt= questionMarkTriangle[row];
	  rep(z,l){
		rep(i,l) {
		  if (v[row][i]<0) {
			if (i>0 && v[row][i-1]>=0) {
			  //printf("%d - ? - // %d\n", v[row][i-1], v[row+1][i-1]);
			  v[row][i] = (10 + v[row+1][i-1] - v[row][i-1])%10;
			} else if (i+1<l && v[row][i+1]>=0) {
			  //printf("- ? - %d // %d\n", v[row][i+1], v[row+1][i]);
			  v[row][i] = (10 + v[row+1][i] - v[row][i+1])%10;
			}
		  }
		}
	  }
	}
	vector<string> result(rows,"");
	rep(row,rows){
	  stringstream ss;
	  rep(i,rows-row) ss << (char)(48+v[row][i]);
	  result[row] = ss.str();
	}
	return result;
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
	string questionMarkTriangle_[] = {"4??", 
 "?2", 
 "1"};
	  vector <string> questionMarkTriangle(questionMarkTriangle_, questionMarkTriangle_+sizeof(questionMarkTriangle_)/sizeof(*questionMarkTriangle_)); 
	string RetVal_[] = {"457", "92", "1" };
	  vector <string> RetVal(RetVal_, RetVal_+sizeof(RetVal_)/sizeof(*RetVal_)); 
	return verify_case(RetVal, RevealTriangle().calcTriangle(questionMarkTriangle)); }
int Test_(Case_<1>) {
	timer_clear();
	string questionMarkTriangle_[] = {"1"};
	  vector <string> questionMarkTriangle(questionMarkTriangle_, questionMarkTriangle_+sizeof(questionMarkTriangle_)/sizeof(*questionMarkTriangle_)); 
	string RetVal_[] = {"1" };
	  vector <string> RetVal(RetVal_, RetVal_+sizeof(RetVal_)/sizeof(*RetVal_)); 
	return verify_case(RetVal, RevealTriangle().calcTriangle(questionMarkTriangle)); }
int Test_(Case_<2>) {
	timer_clear();
	string questionMarkTriangle_[] = {"???2", "??2", "?2", "2"};
	  vector <string> questionMarkTriangle(questionMarkTriangle_, questionMarkTriangle_+sizeof(questionMarkTriangle_)/sizeof(*questionMarkTriangle_)); 
	string RetVal_[] = {"0002", "002", "02", "2" };
	  vector <string> RetVal(RetVal_, RetVal_+sizeof(RetVal_)/sizeof(*RetVal_)); 
	return verify_case(RetVal, RevealTriangle().calcTriangle(questionMarkTriangle)); }
int Test_(Case_<3>) {
	timer_clear();
	string questionMarkTriangle_[] = {"??5?", "??9", "?4", "6"};
	  vector <string> questionMarkTriangle(questionMarkTriangle_, questionMarkTriangle_+sizeof(questionMarkTriangle_)/sizeof(*questionMarkTriangle_)); 
	string RetVal_[] = {"7054", "759", "24", "6" };
	  vector <string> RetVal(RetVal_, RetVal_+sizeof(RetVal_)/sizeof(*RetVal_)); 
	return verify_case(RetVal, RevealTriangle().calcTriangle(questionMarkTriangle)); }

template<int N> void Run_() { cerr << "Test Case #" << N << "..." << flush; Test_(Case_<N>()); Run_<sizeof(Test_(Case_<N+1>()))==1 ? -1 : N+1>(); }
template<>      void Run_<-1>() {}
int main() { Run_<0>(); }
// END CUT HERE

