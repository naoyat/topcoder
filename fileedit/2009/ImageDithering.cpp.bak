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

#line 95 "ImageDithering.cpp"
#include <string>
#include <vector>
// BEGIN CUT HERE
#include <iostream>
// END CUT HERE
#include <sstream>
using namespace std;

class ImageDithering {
	public:
	int count(string dithered, vector<string> screen) {
        int count = 0;
        bool dithcolor[26];
        for(int i=0;i<26;i++) dithcolor[i] = false;
		for (int i=0,c=dithered.size(); i<c; i++)
           dithcolor[ dithered.at(i) - 'A' ] = true;
        for (int row=0; row<screen.size(); row++) {
          string line = screen[row]; int cols = line.size();
          for (int col=0; col<cols; col++) {
            if (dithcolor[line.at(col)-'A']) count++;
          }
        }
        return count;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "BW"; string Arr1[] = {"AAAAAAAA",
 "ABWBWBWA",
 "AWBWBWBA",
 "ABWBWBWA",
 "AWBWBWBA",
 "AAAAAAAA"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 24; verify_case(0, Arg2, count(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "BW"; string Arr1[] = {"BBBBBBBB",
 "BBWBWBWB",
 "BWBWBWBB",
 "BBWBWBWB",
 "BWBWBWBB",
 "BBBBBBBB"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 48; verify_case(1, Arg2, count(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "ACEGIKMOQSUWY"; string Arr1[] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWX",
 "ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWX",
 "ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWX",
 "ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWX",
 "ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWX",
 "ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWX"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 150; verify_case(2, Arg2, count(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "CA"; string Arr1[] = {"BBBBBBB",
 "BBBBBBB",
 "BBBBBBB"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(3, Arg2, count(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "DCBA"; string Arr1[] = {"ACBD"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 4; verify_case(4, Arg2, count(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	ImageDithering ___test;
	___test.run_test(-1);
}
// END CUT HERE
