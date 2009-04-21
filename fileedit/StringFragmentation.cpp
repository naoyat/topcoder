// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// You are given a string containing a list of words separated by single spaces, with no leading or trailing spaces. You have a panel on which you would like to write these words, in order, possibly over multiple lines. The words must go from left to right within each line, and the lines must go from top to bottom. Each line must contain only complete words, and each pair of adjacent words in a line must be separated by a single space. There must be no leading or trailing spaces.

You must write the words in a font size greater than 7. In a font of size N, the height of each letter is 2*N pixels, and the width of each character (letters and spaces) is N+2 pixels. There is no space between adjacent characters and adjacent lines.

You are given a string text containing the words you must write. The dimensions of the panel in pixels are given in the ints width and height. You are not allowed to rotate the panel. Return the largest integer font size strictly greater than 7 that you can use to write the words on the panel, or -1 if it is impossible.

DEFINITION
Class:StringFragmentation
Method:largestFontSize
Parameters:string, int, int
Returns:int
Method signature:int largestFontSize(string text, int width, int height)


NOTES
-If you start a new line between two words, then the space that separated them in the input doesn't get written to the panel.


CONSTRAINTS
-text will contain between 1 and 50 characters, inclusive.
-Each character in text will be an uppercase letter ('A'-'Z') or a space (' ').
-text must be a list of words separated by single spaces, with no leading or trailing spaces, where each word is one or more uppercase letters.
-width and height will be between 1 and 10000, inclusive.


EXAMPLES

0)
"ONE TWO THREE FOUR FIVE"
150
40

Returns: 9

With a font size of 9, we can write "ONE TWO THREE" on the first line and "FOUR FIVE" on the second line.
The width of the first line is 13 characters * (9+2) pixels = 143 pixels.
The width of the second line is 9 characters * (9+2) pixels = 99 pixels.
The total height is 2 lines * (2*9) pixels = 36 pixels.
The total size is therefore 143 x 36 pixels, which fits inside the 150 x 40 pixel panel.
If you used a font size of 10, it would be 156 x 40 pixels, which would not fit.

1)
"ONE TWO THREE FOUR FIVE"
150
60

Returns: 10

Now we can write it in a font size of 10 by separating the text into three lines: "ONE TWO", "THREE", "FOUR FIVE".

2)
"ONE TWO THREE FOUR FIVE"
150
10000

Returns: 28

If you write each word on a separate line, you can use a font size of 28. The widest line would be "THREE", which is 150 pixels wide.

3)
"ONE TWO THREE FOUR FIVE"
10000
10000

Returns: 1250



4)
"ONE TWO THREE FOUR FIVE"
50
50

Returns: -1



5)
"A"
9
14

Returns: -1

Note that font size must be strictly greater than 7.

*/
// END CUT HERE

#line 94 "StringFragmentation.cpp"
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
#define found(s,e)  ((s).find(e)!=(s).end())
#define remove_(c,val) (c).erase(remove((c).begin(),(c).end(),(val)),(c).end())
#define lastc(str) (*((str).end()-1))

typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<long long> vll;

vector<string> split(string str, int delim=' ')
{
  vector<string> result;

  const char *s = str.c_str();
  if (delim == ' ') {
    for (const char *p=s; *p; p++) {
      if (*p == delim)
        s++;
      else
        break;
    }
    if (!*s) return result;

    for (const char *p=s; *p; p++) {
      if (*p == delim) {
        if (s < p) {
          string a(s,p-s);
          result.push_back(a);
        }
        s = p + 1;
      }
    }
    if (*s) result.push_back(s);
  } else {
    for (const char *p=s; *p; p++) {
      if (*p == delim) {
        string a(s,p-s);
        result.push_back(a);
        s = p + 1;
        if (*s == '\0') result.push_back("");
      }
    }
    if (*s) result.push_back(s);
  }

  return result;
}

class StringFragmentation {
 public:
  int largestFontSize(string text, int width, int height) {
    vector<string> words=split(text);//1-50
    int n=sz(words);
    int longest=0;
    tr(words,it) longest=max(sz(*it),longest);
    int pt_max=(10000/longest)-2; /// longest*(N+2) <= 10000
	for(int pt=pt_max;pt>7;pt--){
      int x=0,y=pt*2;
      rep(i,n){
        const string word=words[i];
        int w=sz(word)*(pt+2);
        x+=w;
        if(x>width){
          y+=pt*2; x=w;
          if(x>width) goto next;
        }
        x+=(pt+2);
      }
      if(y<=height) return pt;
   next:;
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
	string text = "ONE TWO THREE FOUR FIVE"; 
	int width = 150; 
	int height = 40; 
	int RetVal = 9; 
	return verify_case(RetVal, StringFragmentation().largestFontSize(text, width, height)); }
int Test_(Case_<1>) {
	timer_clear();
	string text = "ONE TWO THREE FOUR FIVE"; 
	int width = 150; 
	int height = 60; 
	int RetVal = 10; 
	return verify_case(RetVal, StringFragmentation().largestFontSize(text, width, height)); }
int Test_(Case_<2>) {
	timer_clear();
	string text = "ONE TWO THREE FOUR FIVE"; 
	int width = 150; 
	int height = 10000; 
	int RetVal = 28; 
	return verify_case(RetVal, StringFragmentation().largestFontSize(text, width, height)); }
int Test_(Case_<3>) {
	timer_clear();
	string text = "ONE TWO THREE FOUR FIVE"; 
	int width = 10000; 
	int height = 10000; 
	int RetVal = 1250; 
	return verify_case(RetVal, StringFragmentation().largestFontSize(text, width, height)); }
int Test_(Case_<4>) {
	timer_clear();
	string text = "ONE TWO THREE FOUR FIVE"; 
	int width = 50; 
	int height = 50; 
	int RetVal = -1; 
	return verify_case(RetVal, StringFragmentation().largestFontSize(text, width, height)); }
int Test_(Case_<5>) {
	timer_clear();
	string text = "A"; 
	int width = 9; 
	int height = 14; 
	int RetVal = -1; 
	return verify_case(RetVal, StringFragmentation().largestFontSize(text, width, height)); }

template<int N> void Run_() { cerr << "Test Case #" << N << "..." << flush; Test_(Case_<N>()); Run_<sizeof(Test_(Case_<N+1>()))==1 ? -1 : N+1>(); }
template<>      void Run_<-1>() {}
int main() { Run_<0>(); }
// END CUT HERE

