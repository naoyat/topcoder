// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// Most word processors available today allow several standard ways to format lines in a paragraph.  One of those ways is to 'justify' each line to a given width.  The precise definition for that operation is as follows:
Assume that a line of text consists of several words separated by spaces (for simplicity, there will be no punctuation).  Define a gap as the sequence of spaces between a pair of adjacent words.  When reformatting a line, each gap can be replaced with a gap of a different non-zero length.  The line is said to be justified to width w if it is exactly w characters long, has no leading or trailing spaces, and all gaps are as evenly distributed as possible.  This means that the gaps should all be of equal length, or, if that is not possible, the difference in length between the longest and smallest gaps must be 1.
To better illustrate the results of the justification operation, we will use underscores ('_') in place of spaces.
Obviously, the above rules dont uniquely define the result of a justification.  If there are multiple ways to justify a line of text, the one that comes earliest lexicographically is used.  Note that an underscore comes after uppercase letters but before lowercase letters in the ASCII ordering.
You are given a vector <string> words containing all the words in a line of text.  The words are given in the order that they appear in the line.  Return the line of text justified to the given width, using underscores as spaces.


DEFINITION
Class:UnderscoreJustification
Method:justifyLine
Parameters:vector <string>, int
Returns:string
Method signature:string justifyLine(vector <string> words, int width)


NOTES
-Note that you must make all the gaps have equal length if possible.  Only if that is impossible, the longest gap will be one longer than the shortest.
-Remember that 'A' < 'B' < 'C' < ... < 'Z' < '_' < 'a' < 'b' < 'c' < ... < 'z'.
-A string is lexicographically smaller than another string if it contains a smaller character in the first position where they differ.


CONSTRAINTS
-words will contain between 2 and 10 elements, inclusive.
-Each element of words will contain between 1 and 10 characters, inclusive.
-Each element of words will contain only letters ('A'-'Z', 'a'-'z').
-width will be between 3 and 200, inclusive.
-width will be greater than or equal to len+n-1, where n is the number of elements in words, and len is the total number of characters in words, to allow at least one space between adjacent words.


EXAMPLES

0)
{"A", "quick", "brown", "fox", "jumps", "over", "the", "lazy", "dog"}
50

Returns: "A___quick__brown__fox__jumps__over__the__lazy__dog"

We have 7 groups of 2 underscores and 1 group of 3 underscores to put between our words. If the first gap contains 2 underscores, then the string would start with "A__q", which is lexicographically larger than "A___", so its advantageous to put 3 underscores in the first gap.

1)
{"Alpha", "Beta", "Gamma", "Delta", "Epsilon"}
32

Returns: "Alpha_Beta_Gamma__Delta__Epsilon"

There are six possible variants:
Alpha_Beta_Gamma__Delta__Epsilon
Alpha_Beta__Gamma_Delta__Epsilon
Alpha_Beta__Gamma__Delta_Epsilon
Alpha__Beta_Gamma_Delta__Epsilon
Alpha__Beta_Gamma__Delta_Epsilon
Alpha__Beta__Gamma_Delta_Epsilon
The former is the lexicographically smallest one.


2)
{"Hello", "world", "John", "said"}
29

Returns: "Hello____world___John____said"

Sometimes its better to mix large and small groups of underscores.

*/
// END CUT HERE

#line 71 "UnderscoreJustification.cpp"
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

class UnderscoreJustification {
 public:
  string justifyLine(vector<string> words, int width) {
    int n=words.size(), gaps=n-1, len=0;
    tr(words,it)len+=it->length();
    int minspaces=len+gaps, ds=width-minspaces, dsall=1+ds/gaps,dsr=ds%gaps;
    int cn=1<<gaps;
    vector<string> candidates(cn,"");
    rep(i,cn) {
      if(__builtin_popcount(i)!=dsr) continue;
      stringstream ss;
      ss << words[0];
      for(int j=1,b=1;j<=gaps;j++,b<<=1){
        string s_(dsall+((i&b)?1:0), '_');
        ss << s_ << words[j];
      }
      candidates[i] = ss.str();
    }
    remove_(candidates,"");
    sort(all(candidates));
    return candidates[0];
  }
};

// BEGIN CUT HERE
#include <time.h>
clock_t start_time;
void timer_clear() { start_time = clock(); }
string timer() { clock_t end_time = clock(); double interval = (double)(end_time - start_time)/CLOCKS_PER_SEC; ostringstream os; os << " (" << interval*1000 << " msec)"; return os.str(); }

template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
int verify_case(const string &Expected, const string &Received) { if (Expected == Received) cerr << "PASSED" << timer() << endl; else { cerr << "FAILED" << timer() << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } return 0;}

template<int N> struct Case_ {};
char Test_(...);
int Test_(Case_<0>) {
	timer_clear();
	string words_[] = {"A", "quick", "brown", "fox", "jumps", "over", "the", "lazy", "dog"};
	  vector <string> words(words_, words_+sizeof(words_)/sizeof(*words_)); 
	int width = 50; 
	string RetVal = "A___quick__brown__fox__jumps__over__the__lazy__dog"; 
	return verify_case(RetVal, UnderscoreJustification().justifyLine(words, width)); }
int Test_(Case_<1>) {
	timer_clear();
	string words_[] = {"Alpha", "Beta", "Gamma", "Delta", "Epsilon"};
	  vector <string> words(words_, words_+sizeof(words_)/sizeof(*words_)); 
	int width = 32; 
	string RetVal = "Alpha_Beta_Gamma__Delta__Epsilon"; 
	return verify_case(RetVal, UnderscoreJustification().justifyLine(words, width)); }
int Test_(Case_<2>) {
	timer_clear();
	string words_[] = {"Hello", "world", "John", "said"};
	  vector <string> words(words_, words_+sizeof(words_)/sizeof(*words_)); 
	int width = 29; 
	string RetVal = "Hello____world___John____said"; 
	return verify_case(RetVal, UnderscoreJustification().justifyLine(words, width)); }

template<int N> void Run_() { cerr << "Test Case #" << N << "..." << flush; Test_(Case_<N>()); Run_<sizeof(Test_(Case_<N+1>()))==1 ? -1 : N+1>(); }
template<>      void Run_<-1>() {}
int main() { Run_<0>(); }
// END CUT HERE

