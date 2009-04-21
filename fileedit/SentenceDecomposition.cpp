// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// Little Bonnie and her friends were dismayed to learn that their parents were reading all of their private communications.  They decided to invent a new language that would allow them to talk freely.  What they finally came up with was a language where sentences are built using a special method. 


All the valid words that can be used in the new language are given in the vector <string> validWords.  A sentence is a concatenation (with no spaces) of a sequence of valid words.  Each valid word can appear 0 or more times in the sentence.  What makes the language special is that each word can be transformed by rearranging its letters before being used.  The cost to transform a word is defined as the number of character positions where the original word and the transformed word differ.  For example, "abc" can be transformed to "abc" with a cost of 0, to "acb", "cba" or "bac" with a cost of 2, and to "bca" or "cab" with a cost of 3. 


Although several different sequences of valid words can produce the same sentence in this language, only the sequence with the least total transformation cost carries the meaning of the sentence.  The advantage of the new language is that the parents can no longer understand what the kids are saying.  The disadvantage is that the kids themselves also do not understand.  They need your help. 


Given a string sentence, return the total cost of transformation of the sequence of valid words which carries the meaning of the sentence, or -1 if no such sequence exists.

DEFINITION
Class:SentenceDecomposition
Method:decompose
Parameters:string, vector <string>
Returns:int
Method signature:int decompose(string sentence, vector <string> validWords)


NOTES
-If a word is used multiple times in a sentence, each occurrence can be transformed differently.


CONSTRAINTS
-sentence will contain between 1 and 50 lowercase letters ('a'-'z'), inclusive.
-validWords will contain between 1 and 50 elements, inclusive.
-Each element of validWords will contain between 1 and 50 lowercase letters ('a'-'z'), inclusive.


EXAMPLES

0)
"neotowheret"
{"one", "two", "three", "there"}

Returns: 8

The following transformations can be made:

"one" -> "neo" with a cost of 3 
"two" -> "tow" with a cost of 2 
"three" -> "heret" with a cost of 3 
"there" -> "heret" with a cost of 5 

So the sequence {"one", "two", "three"} is the one carrying the meaning of "neotowheret". Its total transformation cost is 3 + 2 + 3 = 8.

1)
"abba"
{"ab", "ac", "ad"}

Returns: 2

The word "ab" is used twice, and each time, it is transformed differently.

2)
"thisismeaningless"
{"this", "is", "meaningful"}

Returns: -1



3)
"ommwreehisymkiml"
{"we", "were", "here", "my", "is", "mom", "here", "si", "milk", "where", "si"}

Returns: 10



4)
"ogodtsneeencs"
{"go", "good", "do", "sentences", "tense", "scen"}

Returns: 8



5)
"sepawaterords"
{"separate","words"}

Returns: -1

You are only allowed to rearrange letters within words, and not in the entire sentence.

*/
// END CUT HERE

#line 94 "SentenceDecomposition.cpp"
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

bool greater_by_length(const string& s1, const string& s2 )
{
  return s1.length() > s2.length();
}
template <typename T> struct better : binary_function<T,T,bool> {
  bool operator()(const T& X, const T& Y) const{
	// at, score
	if (X.first >= Y.first) return X.second < Y.second;
	return false;
  }
};

class SentenceDecomposition {
private:
  bool abc[26];
  bool usable(const string &str) {
	rep(i,str.length()) if (!abc[str[i]-'a']) return false;
	return true;
  }

  string strsort(const string &str) {
	vector<char> buf(all(str));
	sort(all(buf));
	string sorted(all(buf));
// BEGIN CUT HERE
	//cout << str << " => " << sorted << endl;
// END CUT HERE
	return sorted;
  }
  int score(string orig, string word) {
	int d = orig.length();
	for (int i=d-1; i>=0; i--)
	  if (orig[i] == word[i]) d--;
	
// BEGIN CUT HERE
	//cout << "score(" << orig << ", " << word << ") => " << d << endl;
// END CUT HERE
	return d;
  }
public:
  int decompose(string sentence, vector<string> validWords) {
	int l=sentence.length();

	rep(i,26) abc[i] = false;
	rep(i,l) abc[sentence[i]-'a'] = true;

	set<string> s;
	tr(validWords,wt) if (usable(*wt)) s.insert(*wt);

	vector<string> valids(all(s));
	sort(all(valids),greater_by_length);

	int n=valids.size();
	vector<string> words(n);
	rep(i,n) {
	  words[i] = strsort(valids[i]);
	}
// BEGIN CUT HERE
/*
	cout << "sentence: " << sentence << endl;
	cout << "valids: " << valids << endl;
	cout << "words: " << words << endl;
*/
	//priority_queue<pair<int,int>, vector<pair<int,int> >, better<pair<int,int> > > pq;
	//priority_queue<pair<int,int> > pq;
// END CUT HERE
	priority_queue<pair<int,int>, vector<pair<int,int> >, better<pair<int,int> > > pq;
	//	priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > pq;
	
	vector<int> said(l+1,INT_MAX);
	//set<pair<int,int> > said;

	rep(i,n) {
	  int wl = words[i].length();
	  if (0+wl <= l) {
		string ss = sentence.substr(0,wl);
		if (strsort(ss) == words[i]) {
		  int sc = score(valids[i],ss);
		  if (sc < said[wl]) {
			pair<int,int> p = make_pair(wl,sc);
			pq.push(p);
			said[wl] = sc;
		  }
		}
	  }
	}

// BEGIN CUT HERE
	//priority_queue<int,vector<int>,greater<int> > topscores;
// END CUT HERE
	int topscore = INT_MAX;
	
	while (!pq.empty()) {
// BEGIN CUT HERE
//	  cout << " > " << pq.top() << endl;
// END CUT HERE
	  int at = pq.top().first, pt = pq.top().second;
// BEGIN CUT HERE
/*
	  if (at == l) {
		// cout << " !! " << pq.top() << endl;
		topscore = pt;
	  }
*/
// END CUT HERE
	  pq.pop();

	  if (at == l) {
		topscore = min(topscore,pt);
		continue;
	  }

	  rep(i,n) {
		int wl = words[i].length();
		if (at+wl <= l) {
		  string ss = sentence.substr(at,wl);
		  if (strsort(ss) == words[i]) {
// BEGIN CUT HERE
/*
			printf(" pq.push(%d+%d=%d, %d+score(%s,%s)=%d)\n",
				   at,wl, at+wl,
				   pt,valids[i].c_str(),ss.c_str(),
				   pt+score(valids[i].c_str(),ss.c_str()) );
*/
// END CUT HERE
			int newscore = pt+score(valids[i],ss);
			if (newscore < topscore) {
			  if (newscore < said[at+wl]) {
				pair<int,int> p = make_pair(at+wl,newscore);
				pq.push(p);
				said[at+wl] = newscore;
			  }
			}
		  }
		}
	  }
	}

	return (topscore == INT_MAX)? -1 : topscore;
// BEGIN CUT HERE
	//return topscores.empty()? -1: topscores.top();
// END CUT HERE
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
	string sentence = "neotowheret"; 
	string validWords_[] = {"one", "two", "three", "there"};
	  vector <string> validWords(validWords_, validWords_+sizeof(validWords_)/sizeof(*validWords_)); 
	int RetVal = 8; 
	return verify_case(RetVal, SentenceDecomposition().decompose(sentence, validWords)); }
int Test_(Case_<1>) {
	timer_clear();
	string sentence = "abba"; 
	string validWords_[] = {"ab", "ac", "ad"};
	  vector <string> validWords(validWords_, validWords_+sizeof(validWords_)/sizeof(*validWords_)); 
	int RetVal = 2; 
	return verify_case(RetVal, SentenceDecomposition().decompose(sentence, validWords)); }
int Test_(Case_<2>) {
	timer_clear();
	string sentence = "thisismeaningless"; 
	string validWords_[] = {"this", "is", "meaningful"};
	  vector <string> validWords(validWords_, validWords_+sizeof(validWords_)/sizeof(*validWords_)); 
	int RetVal = -1; 
	return verify_case(RetVal, SentenceDecomposition().decompose(sentence, validWords)); }
int Test_(Case_<3>) {
	timer_clear();
	string sentence = "ommwreehisymkiml"; 
	string validWords_[] = {"we", "were", "here", "my", "is", "mom", "here", "si", "milk", "where", "si"};
	  vector <string> validWords(validWords_, validWords_+sizeof(validWords_)/sizeof(*validWords_)); 
	int RetVal = 10; 
	return verify_case(RetVal, SentenceDecomposition().decompose(sentence, validWords)); }
int Test_(Case_<4>) {
	timer_clear();
	string sentence = "ogodtsneeencs"; 
	string validWords_[] = {"go", "good", "do", "sentences", "tense", "scen"};
	  vector <string> validWords(validWords_, validWords_+sizeof(validWords_)/sizeof(*validWords_)); 
	int RetVal = 8; 
	return verify_case(RetVal, SentenceDecomposition().decompose(sentence, validWords)); }
int Test_(Case_<5>) {
	timer_clear();
	string sentence = "sepawaterords"; 
	string validWords_[] = {"separate","words"};
	  vector <string> validWords(validWords_, validWords_+sizeof(validWords_)/sizeof(*validWords_)); 
	int RetVal = -1; 
	return verify_case(RetVal, SentenceDecomposition().decompose(sentence, validWords)); }
int Test_(Case_<6>) {
	timer_clear();
	string sentence = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
	string validWords_[] = {"a", "b", "aaa", "ab"};
	vector <string> validWords(validWords_, validWords_+sizeof(validWords_)/sizeof(*validWords_)); 
	int RetVal = 0;
	return verify_case(RetVal, SentenceDecomposition().decompose(sentence, validWords)); }
int Test_(Case_<7>) {
	timer_clear();
	string sentence = "bccccaaabcaaacccaaaaacabbbcccbabbcabccaabcbacacbcb";
	string validWords_[] = {"a", "bbca", "a", "aaacb", "tbyjphp", "bbca", "txywddtnbrjhjjncyyldfoifzxaszcvklupoyeb", "rtaewtox", "bbc", "bcc", "bcc", "abca", "bacaaaa", "bcabc", "babaaccc", "cbbba", "aabaabac", "babaaccc", "a", "bcabc", "cbcbbacb", "abacb", "bbcccaa", "c", "cc", "bccc", "bccc", "bac", "babaaccc", "rtaewtox", "caacbcaac", "caacaccb", "cacccb", "caacbcaac", "aca", "dxizpgbeavbwboyehwuwrnouvtmbgrvouddyx", "bccabbacc", "bbca", "acaa", "aaa", "aabaabac", "afsmaukgqtfuhopwqxfejjdbljzcfmixvlvvcyg", "bcc", "aabaabac", "afsmaukgqtfuhopwqxfejjdbljzcfmixvlvvcyg", "cbcbbacb", "txywddtnbrjhjjncyyldfoifzxaszcvklupoyeb", "aaacb", "ccaa", "encemanewrmuhkhakbrvkhejrkqmiomjcwv"};
	vector <string> validWords(validWords_, validWords_+sizeof(validWords_)/sizeof(*validWords_)); 
	int RetVal = 8;
	return verify_case(RetVal, SentenceDecomposition().decompose(sentence, validWords)); }
int Test_(Case_<8>) {
	timer_clear();
	string sentence = "badabdcbcbdedbaabdccecbcbcbaceeebdacddababecccaacc";
	string validWords_[] = {"ebde", "edbdbeeacccadabecca", "bbacccbebedcecaaeaccbddb", "dacbadbcb", "aadbb", "ca", "dadceabbad", "cacabcbbdcecb", "ba", "badeadbbddcbbc", "e", "a", "caac", "bcceedbdacbbbacedccdadcebabbabdecdbbdcaa", "edbccdcbdbaae", "dcdaabcecb", "c", "caacccce", "dacbddbcbcbcbcdecbabecdaeadcccdacbacbbbeeacaaeacbd", "abcbcb", "debabda", "cccaacc", "dbcecdb", "bceee", "accbbdbccec", "ed", "cca", "dab", "cbbdabc"};
	vector <string> validWords(validWords_, validWords_+sizeof(validWords_)/sizeof(*validWords_)); 
	int RetVal = 24;
	return verify_case(RetVal, SentenceDecomposition().decompose(sentence, validWords)); }
int Test_(Case_<9>) {
  timer_clear();
  string sentence = "nnkamcnlywen";
  string validWords_[] = {"nacnmk", "n", "n", "ywel", "y", "e", "wamklcyn", "naklcym", "wly", "lyn", "lcknmynna", "e", "e", "nnkcalmn", "clnamnky", "n", "klanymnc", "l", "wy", "y", "lwenny", "lywamckne", "ln", "wyen", "nnwley", "ak", "n", "e", "ly", "nywe", "ne", "mkca", "w", "n", "nn", "w", "w", "nmcnknyal", "nn", "ywnl", "ne", "wknlyncman", "en", "wenlny", "n", "kncmawlnye", "ew", "ynl", "nckma", "w"};
  vector <string> validWords(validWords_, validWords_+sizeof(validWords_)/sizeof(*validWords_)); 
  int RetVal = 3;
  return verify_case(RetVal, SentenceDecomposition().decompose(sentence, validWords)); }

template<int N> void Run_() { cerr << "Test Case #" << N << "..." << flush; Test_(Case_<N>()); Run_<sizeof(Test_(Case_<N+1>()))==1 ? -1 : N+1>(); }
template<>      void Run_<-1>() {}
int main() { Run_<0>(); }
// END CUT HERE

