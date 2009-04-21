// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// Tanya has a rectangular table filled with letters.

First, she makes four copies of this table, and arranges the copies as a 2×2 rectangle.

Then she lists all subrectangles of the resulting table.

For example, for the following original table:
OK
she will arrange the copies like this:

OKOK
OKOK

and then she will list the following 30 subrectangles (dots for clarity only):

OKOK .... OKOK OKO. .... OKO. .KOK .... .KOK
OKOK OKOK .... OKO. OKO. .... .KOK .KOK ....

OK.. .... OK.. .KO. .... .KO. ..OK .... ..OK 
OK.. OK.. .... .KO. .KO. .... ..OK ..OK .... 

O... .... O... .K.. .... .K.. ..O. .... ..O. ...K .... ...K 
O... O... .... .K.. .K.. .... ..O. ..O. .... ...K ...K ....

(Note that she is considering all subrectangles based on their positions rather than their content, so the same subrectangle might appear multiple times in the list.  In this case, subrectangle "K" appears four times because it occurs at four different positions.)

Tanya wonders how frequently each letter of the alphabet occurs among all these subrectangles.  You are given a vector <string> table, where the j-th character of the i-th element is the letter at row i, column j of the original table.  Return a vector<long long> containing exactly 26 elements, where the i-th element is the number of occurrences of the i-th letter in the alphabet among all of Tanya's subrectangles.  'A' is the 0-th letter, 'B' is the 1-st letter, etc.


DEFINITION
Class:SubrectanglesOfTable
Method:getQuantity
Parameters:vector <string>
Returns:vector<long long>
Method signature:vector<long long> getQuantity(vector <string> table)


CONSTRAINTS
-table will contain between 1 and 50 elements, inclusive.
-Each element of table will contain between 1 and 50 characters, inclusive.
-Each element of table will contain the same number of characters.
-Each element of table will contain only uppercase letters ('A'-'Z').


EXAMPLES

0)
{"OK"}

Returns: {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 40, 0, 0, 0, 40, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }

The 30 Tanya's rectangles are listed above. There is a total of 40 Ks and 40 Os in these rectangles.

1)
{"GOOD", "LUCK"}

Returns: {0, 0, 320, 280, 0, 0, 280, 0, 0, 0, 280, 280, 0, 0, 640, 0, 0, 0, 0, 0, 320, 0, 0, 0, 0, 0 }

The four copies form the following table:
GOODGOOD
LUCKLUCK
GOODGOOD
LUCKLUCK

Tanya lists 360 rectangles that contain a total of 320 Cs, 280 Ds, 280 Gs, 280 Ks, 280 Ls, 640 Os, and 320 Us.

2)
{"TANYA",
 "HAPPY",
 "BIRTH",
 "DAYYY"}

Returns: {5168, 1280, 0, 1120, 0, 0, 0, 2560, 1472, 0, 0, 0, 0, 1344, 0, 3008, 0, 1536, 0, 2592, 0, 0, 0, 0, 6320, 0 }



*/
// END CUT HERE

#line 84 "SubrectanglesOfTable.cpp"
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

class SubrectanglesOfTable {
public:
  vector<long long> getQuantity(vector<string> table) {
	vector<long long> qty(26,0);

	int th = table.size(), tw = table[0].size();
	int h=th*2,w=tw*2;
// BEGIN CUT HERE
//	cout << h << " x " << w << endl;
// END CUT HERE

	vector<long long> w_(w,0), h_(h,0);
	for (int l=1;l<=w;l++) {
	  for (int x=0;x<=w-l;x++) {
// BEGIN CUT HERE
//		printf("l=%d, x=0..%d, j=0..%d\n", l,w-l-1,l-1);
// END CUT HERE
		for (int j=0;j<l;j++) w_[x+j]++;
	  }
	}
	for (int l=1;l<=h;l++) {
	  for (int y=0;y<=h-l;y++) {
		for (int j=0;j<l;j++) h_[y+j]++;
	  }
	}
	for (int x=0;x<w;x++) {
	  for (int y=0;y<h;y++) {
		int lt = table[y%th][x%tw] - 'A';
		qty[lt] += w_[x] * h_[y];
	  }
	}

	return qty;
  }
};

// BEGIN CUT HERE
#include <time.h>
clock_t start_time;
void timer_clear() { start_time = clock(); }
string timer() { clock_t end_time = clock(); double interval = (double)(end_time - start_time)/CLOCKS_PER_SEC; ostringstream os; os << " (" << interval*1000 << " msec)"; return os.str(); }

template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
int verify_case(const vector<long long> &Expected, const vector<long long> &Received) { if (Expected == Received) cerr << "PASSED" << timer() << endl; else { cerr << "FAILED" << timer() << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } return 0;}

template<int N> struct Case_ {};
char Test_(...);
int Test_(Case_<0>) {
	timer_clear();
	string table_[] = {"OK"};
	  vector <string> table(table_, table_+sizeof(table_)/sizeof(*table_)); 
	long RetVal_[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 40, 0, 0, 0, 40, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	  vector<long long> RetVal(RetVal_, RetVal_+sizeof(RetVal_)/sizeof(*RetVal_)); 
	return verify_case(RetVal, SubrectanglesOfTable().getQuantity(table)); }
int Test_(Case_<1>) {
	timer_clear();
	string table_[] = {"GOOD", "LUCK"};
	  vector <string> table(table_, table_+sizeof(table_)/sizeof(*table_)); 
	long RetVal_[] = {0, 0, 320, 280, 0, 0, 280, 0, 0, 0, 280, 280, 0, 0, 640, 0, 0, 0, 0, 0, 320, 0, 0, 0, 0, 0 };
	  vector<long long> RetVal(RetVal_, RetVal_+sizeof(RetVal_)/sizeof(*RetVal_)); 
	return verify_case(RetVal, SubrectanglesOfTable().getQuantity(table)); }
int Test_(Case_<2>) {
	timer_clear();
	string table_[] = {"TANYA",
 "HAPPY",
 "BIRTH",
 "DAYYY"};
	  vector <string> table(table_, table_+sizeof(table_)/sizeof(*table_)); 
	long RetVal_[] = {5168, 1280, 0, 1120, 0, 0, 0, 2560, 1472, 0, 0, 0, 0, 1344, 0, 3008, 0, 1536, 0, 2592, 0, 0, 0, 0, 6320, 0 };
	  vector<long long> RetVal(RetVal_, RetVal_+sizeof(RetVal_)/sizeof(*RetVal_)); 
	return verify_case(RetVal, SubrectanglesOfTable().getQuantity(table)); }
int Test_(Case_<3>) {
	timer_clear();
	string table_[] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWX",
					   "ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWX",
					   "ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWX",
					   "ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWX",
					   "ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWX",
					   "ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWX",
					   "ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWX",
					   "ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWX",
					   "ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWX",
					   "ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWX",
"ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWX",
					   "ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWX",
					   "ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWX",
					   "ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWX",
					   "ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWX",
"ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWX",
					   "ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWX",
					   "ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWX",
					   "ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWX",
					   "ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWX",
"ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWX",
					   "ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWX",
					   "ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWX",
					   "ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWX",
					   "ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWX",
"ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWX",
					   "ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWX",
					   "ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWX",
					   "ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWX",
					   "ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWX",
"ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWX",
					   "ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWX",
					   "ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWX",
					   "ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWX",
					   "ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWX",
					   "ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWX",
					   "ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWX",
					   "ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWX",
					   "ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWX",
					   "ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWX",
					   "ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWX",
					   "ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWX",
					   "ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWX",
					   "ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWX",
					   "ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWX",
					   "ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWX",
					   "ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWX",
					   "ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWX",
					   "ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWX",
					   "ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWX"};
	  vector <string> table(table_, table_+sizeof(table_)/sizeof(*table_)); 
	long RetVal_[] = {0, 0, 320, 280, 0, 0, 280, 0, 0, 0, 280, 280, 0, 0, 640, 0, 0, 0, 0, 0, 320, 0, 0, 0, 0, 0 };
	  vector<long long> RetVal(RetVal_, RetVal_+sizeof(RetVal_)/sizeof(*RetVal_)); 
	return verify_case(RetVal, SubrectanglesOfTable().getQuantity(table)); }

template<int N> void Run_() { cerr << "Test Case #" << N << "..." << flush; Test_(Case_<N>()); Run_<sizeof(Test_(Case_<N+1>()))==1 ? -1 : N+1>(); }
template<>      void Run_<-1>() {}
int main() { Run_<0>(); }
// END CUT HERE

