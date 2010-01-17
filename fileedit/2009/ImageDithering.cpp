#line 2 "ImageDithering.cpp"
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

class ImageDithering {
	public:
	int count(string dithered, vector <string> screen) {
		
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
	string dithered = "BW"; 
	string screen_[] = {"AAAAAAAA",
 "ABWBWBWA",
 "AWBWBWBA",
 "ABWBWBWA",
 "AWBWBWBA",
 "AAAAAAAA"};
	  vector <string> screen(screen_, screen_+sizeof(screen_)/sizeof(*screen_)); 
	int RetVal = 24; 
	return verify_case(RetVal, ImageDithering().count(dithered, screen)); }
int Test_(Case_<1>) {
	timer_clear();
	string dithered = "BW"; 
	string screen_[] = {"BBBBBBBB",
 "BBWBWBWB",
 "BWBWBWBB",
 "BBWBWBWB",
 "BWBWBWBB",
 "BBBBBBBB"};
	  vector <string> screen(screen_, screen_+sizeof(screen_)/sizeof(*screen_)); 
	int RetVal = 48; 
	return verify_case(RetVal, ImageDithering().count(dithered, screen)); }
int Test_(Case_<2>) {
	timer_clear();
	string dithered = "ACEGIKMOQSUWY"; 
	string screen_[] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWX",
 "ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWX",
 "ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWX",
 "ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWX",
 "ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWX",
 "ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWX"};
	  vector <string> screen(screen_, screen_+sizeof(screen_)/sizeof(*screen_)); 
	int RetVal = 150; 
	return verify_case(RetVal, ImageDithering().count(dithered, screen)); }
int Test_(Case_<3>) {
	timer_clear();
	string dithered = "CA"; 
	string screen_[] = {"BBBBBBB",
 "BBBBBBB",
 "BBBBBBB"};
	  vector <string> screen(screen_, screen_+sizeof(screen_)/sizeof(*screen_)); 
	int RetVal = 0; 
	return verify_case(RetVal, ImageDithering().count(dithered, screen)); }
int Test_(Case_<4>) {
	timer_clear();
	string dithered = "DCBA"; 
	string screen_[] = {"ACBD"};
	  vector <string> screen(screen_, screen_+sizeof(screen_)/sizeof(*screen_)); 
	int RetVal = 4; 
	return verify_case(RetVal, ImageDithering().count(dithered, screen)); }

template<int N> void Run_() { cerr << "Test Case #" << N << "..." << flush; Test_(Case_<N>()); Run_<sizeof(Test_(Case_<N+1>()))==1 ? -1 : N+1>(); }
template<>      void Run_<-1>() {}
int main() { Run_<0>(); }
// END CUT HERE


// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
Sometimes when computer programs have a limited number of colors to use, they use a technique called dithering.  Dithering is when you use a pattern made up of different colors such that when the colors are viewed together, they appear like another color.  For example, you can use a checkerboard pattern of black and white pixels to achieve the illusion of gray.



You are writing a program to determine how much of the screen is covered by a certain dithered color.  Given a computer screen where each pixel has a certain color, and a list of all the solid colors that make up the dithered color, return the number of pixels on the screen that are used to make up the dithered color.  Each pixel will be represented by a character in screen.  Each character in screen and in dithered will be an uppercase letter ('A'-'Z') representing a color.



Assume that any pixel which is a color contained in dithered is part of the dithered color.


DEFINITION
Class:ImageDithering
Method:count
Parameters:string, vector <string>
Returns:int
Method signature:int count(string dithered, vector <string> screen)


CONSTRAINTS
-dithered will contain between 2 and 26 upper case letters ('A'-'Z'), inclusive.
-There will be no repeated characters in dithered.
-screen will have between 1 and 50 elements, inclusive.
-Each element of screen will contain between 1 and 50 upper case letters ('A'-'Z'), inclusive.
-All elements of screen will contain the same number of characters.


EXAMPLES

0)
"BW"
{"AAAAAAAA",
 "ABWBWBWA",
 "AWBWBWBA",
 "ABWBWBWA",
 "AWBWBWBA",
 "AAAAAAAA"}

Returns: 24

Here, our dithered color could consist of black (B) and white (W) pixels, composing a shade of gray.  In the picture, there is a dithered gray square surrounded by another color (A).

1)
"BW"
{"BBBBBBBB",
 "BBWBWBWB",
 "BWBWBWBB",
 "BBWBWBWB",
 "BWBWBWBB",
 "BBBBBBBB"}

Returns: 48

Here is the same picture, but with the outer color replaced with black pixels.  Although in reality, the outer pixels do not form a dithered color, your algorithm should still assume they are part of the dithered pattern.

2)
"ACEGIKMOQSUWY"
{"ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWX",
 "ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWX",
 "ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWX",
 "ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWX",
 "ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWX",
 "ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWX"}

Returns: 150

A picture of vertical stripes, every other stripe is considered part of the dithered color.

3)
"CA"
{"BBBBBBB",
 "BBBBBBB",
 "BBBBBBB"}

Returns: 0

The dithered color is not present.

4)
"DCBA"
{"ACBD"}

Returns: 4

The order of the colors doesn't matter.

*/
// END CUT HERE
