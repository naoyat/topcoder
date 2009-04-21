// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// In this problem you will be given a  string text and you will need to find the substring of the text that matches a given template in the best way.
The template will be represented by two strings: prefix and suffix.
Consider a string S. The prefix match score of S with respect to a given template is the maximal n >= 0 such that the first n characters of S are equal to the last n characters of prefix and occur in the same exact order. Analogously, the suffix match score of S is the maximal m >= 0 such that the last m characters of S are equal to the first m characters of suffix and occur in the same exact order.

For example, if S = "something", prefix = "awesome", and suffix = "ingenious", than the prefix score of S is 4 (the matched characters are "some") and the suffix score is 3 (the matched characters are "ing").

The match score of a string S with respect to a given template is the sum of its prefix and suffix match scores. Find the non-empty substring of text with the maximal match score according to the template (prefix, suffix). In case of a tie, return the substring with the maximal prefix score. If there are still several candidates, return one that comes first lexicographically.

DEFINITION
Class:TemplateMatching
Method:bestMatch
Parameters:string, string, string
Returns:string
Method signature:string bestMatch(string text, string prefix, string suffix)


NOTES
-String A comes before string B lexicographically if A is a proper prefix of B, or if A has a smaller character at the first position where the strings differ. When comparing the characters, refer to the following list of characters in ascending order: ' ', 'a', 'b', ..., 'z'.


CONSTRAINTS
-text will contain between 1 and 50 characters, inclusive.
-prefix will contain between 1 and 50 characters, inclusive.
-suffix will contain between 1 and 50 characters, inclusive.
-text, prefix and suffix will contain only lowercase letters ('a'-'z') and spaces (' ').


EXAMPLES

0)
"something"
"awesome"
"ingenious"

Returns: "something"

The example from the problem statement.

1)
"havka"
"eto"
"papstvo"

Returns: "a"

The return value must be non-empty string, so the correct answer is "a".

2)
"abracadabra"
"habrahabr"
"bracket"

Returns: "abrac"



3)
"mississippi"
"promise"
"piccolo"

Returns: "ippi"



4)
"a a a a a a"
"a a"
"a"

Returns: "a a"



5)
"ab"
"b"
"a"

Returns: "b"



*/
// END CUT HERE

#line 91 "TemplateMatching.cpp"
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

class TemplateMatching {
private:
  int cross(string s1, string s2) {
// BEGIN CUT HERE
	//cout << "cross(\"" << s1 << "\", \"" << s2 << "\")\n";
// END CUT HERE
	int len1 = s1.length(), len2 = s2.length();
	int maxcross = min(len1, len2);
	for (int i=maxcross; i>0; i--) {
// BEGIN CUT HERE
	  //cout << "  i=" << i << ", comparing \"" << s1.substr(len1-i,i) << "\" with \"" << s2.substr(0,i) << "\" ..." << endl;
// END CUT HERE
	  if (s1.substr(len1-i,i) == s2.substr(0,i)) return i;
	}
	return 0;
  }
public:
  string bestMatch(string text, string prefix, string suffix) {
	set<string> words;
// BEGIN CUT HERE
	//map<string,int> substrs;
// END CUT HERE
	int n = text.length();
	for (int i=0; i<n; i++) {
	  for (int l=1; l<=(n-i); l++) {
		words.insert(text.substr(i,l));
// BEGIN CUT HERE
		/*
		  printf("%s [%d..%d] => ", text.c_str(), i, l);
		  cout << text.substr(i,l) << endl;
		*/
// END CUT HERE
	  }
	}
// BEGIN CUT HERE
	/*
	char *px = prefix.c_str(), *sx = suffix.c_str();
	int pl = prefix.length(), sl = suffix.length();
	*/
	//map<int,string> hiscore;
// END CUT HERE
	int hi_score = -1, hi_pscore = -1;
	string hi_score_at;

	tr(words,it) {
	  int pscore = cross(prefix, *it), sscore = cross(*it, suffix);
	  int score = pscore + sscore;
// BEGIN CUT HERE
	  //cout << *it << " => " << score << endl;
// END CUT HERE
	  if (hi_score < score) {
		hi_score = score; hi_score_at = *it;
		hi_pscore = pscore;
	  } else if (hi_score == score && hi_pscore < pscore) {
		hi_score = score; hi_score_at = *it;
		hi_pscore = pscore;
	  }
	}
	return hi_score_at;
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
	string text = "something"; 
	string prefix = "awesome"; 
	string suffix = "ingenious"; 
	string RetVal = "something"; 
	return verify_case(RetVal, TemplateMatching().bestMatch(text, prefix, suffix)); }
int Test_(Case_<1>) {
	timer_clear();
	string text = "havka"; 
	string prefix = "eto"; 
	string suffix = "papstvo"; 
	string RetVal = "a"; 
	return verify_case(RetVal, TemplateMatching().bestMatch(text, prefix, suffix)); }
int Test_(Case_<2>) {
	timer_clear();
	string text = "abracadabra"; 
	string prefix = "habrahabr"; 
	string suffix = "bracket"; 
	string RetVal = "abrac"; 
	return verify_case(RetVal, TemplateMatching().bestMatch(text, prefix, suffix)); }
int Test_(Case_<3>) {
	timer_clear();
	string text = "mississippi"; 
	string prefix = "promise"; 
	string suffix = "piccolo"; 
	string RetVal = "ippi"; 
	return verify_case(RetVal, TemplateMatching().bestMatch(text, prefix, suffix)); }
int Test_(Case_<4>) {
	timer_clear();
	string text = "a a a a a a"; 
	string prefix = "a a"; 
	string suffix = "a"; 
	string RetVal = "a a"; 
	return verify_case(RetVal, TemplateMatching().bestMatch(text, prefix, suffix)); }
int Test_(Case_<5>) {
	timer_clear();
	string text = "ab"; 
	string prefix = "b"; 
	string suffix = "a"; 
	string RetVal = "b"; 
	return verify_case(RetVal, TemplateMatching().bestMatch(text, prefix, suffix)); }

template<int N> void Run_() { cerr << "Test Case #" << N << "..." << flush; Test_(Case_<N>()); Run_<sizeof(Test_(Case_<N+1>()))==1 ? -1 : N+1>(); }
template<>      void Run_<-1>() {}
int main() { Run_<0>(); }
// END CUT HERE

