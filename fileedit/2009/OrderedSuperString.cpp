// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// A string X is an ordered superstring of the vector <string> words if

  Each element of words is a substring of X.
  There exists a sequence of indices x_1 <= x_2 <= ... <= x_n, where n is the number of elements in words. For each element k of words, where k is a 1-based index, there is an occurrence of words[k] that starts at the x_k-th letter of X.
  

For example "abca" is an ordered superstring of {"abc", "ca"}, but "cabc" is not.


Given a vector <string> words, return the length of its shortest ordered superstring.


DEFINITION
Class:OrderedSuperString
Method:getLength
Parameters:vector <string>
Returns:int
Method signature:int getLength(vector <string> words)


CONSTRAINTS
-words will contain between 1 and 50 elements, inclusive.
-Each element of words will contain between 1 and 50 lowercase letters ('a'-'z'), inclusive.


EXAMPLES

0)
{"abc","ca"}

Returns: 4

This is the example from the problem statement. The shortest ordered superstring is "abca". The sequence of indices is {0, 2}. There is an occurrence of "abc" starting at character 0 of "abca", and there is an occurrence of "ca" starting at character 2 of "abca".

1)
{"a","a","b","a"}

Returns: 3

Although the given words are all substrings of "ab", they do not appear in the proper order. The shortest ordered superstring is "aba".

2)
{"abcdef", "ab","bc", "de","ef"}

Returns: 6



3)
{"ab","bc", "de","ef","abcdef"}

Returns: 12



*/
// END CUT HERE

#line 63 "OrderedSuperString.cpp"
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

class OrderedSuperString {
public:
  int getLength(vector<string> words) {
	int n=words.size();

	string w0=words[0];
	int l0=w0.length();
	if(n==1) return l0;
	int a0=0;

	for (int i=1;i<n;i++) {
	  string wi=words[i];
	  int li=wi.length();
// BEGIN CUT HERE
	  //cout << "[i:"<<i<<"] a0=" << a0 << "," << w0 << " | " << wi << endl;
	  //cout << "w0=" << w0 <<", l0= "<<l0 <<", a0=" << a0<<endl;
// END CUT HERE
	  if (l0>=li) {
		for(int a=a0;a<=l0-li;a++) {
		  if(w0.substr(a,li)==wi) {a0=a; goto next;}
		}
	  }
	  for(int w=min(l0,li-1);w>0;w--){
		if(l0-w<a0)continue;
// BEGIN CUT HERE
		//cout << "w="<<w << "; "<<w0.substr(l0-w,w) << ", " << wi.substr(0,w) << endl;
// END CUT HERE
		if (w0.substr(l0-w,w)==wi.substr(0,w)) {w0+=wi.substr(w,li-w);a0=l0-w;l0+=li-w;goto next;}
	  }
	  a0 = l0; w0 += wi; l0 += li;
	next:
	  ;	
// BEGIN CUT HERE
	  //cout << "i="<<i <<": "<< w0 << " (" <<l0 << ")" <<endl;
// END CUT HERE
	}
	return l0;
  }
};
u
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
	string words_[] = {"abc","ca"};
	  vector <string> words(words_, words_+sizeof(words_)/sizeof(*words_)); 
	int RetVal = 4; 
	return verify_case(RetVal, OrderedSuperString().getLength(words)); }
int Test_(Case_<1>) {
	timer_clear();
	string words_[] = {"a","a","b","a"};
	  vector <string> words(words_, words_+sizeof(words_)/sizeof(*words_)); 
	int RetVal = 3; 
	return verify_case(RetVal, OrderedSuperString().getLength(words)); }
int Test_(Case_<2>) {
	timer_clear();
	string words_[] = {"abcdef", "ab","bc", "de","ef"};
	  vector <string> words(words_, words_+sizeof(words_)/sizeof(*words_)); 
	int RetVal = 6; 
	return verify_case(RetVal, OrderedSuperString().getLength(words)); }
int Test_(Case_<3>) {
	timer_clear();
	string words_[] = {"ab","bc", "de","ef","abcdef"};
	  vector <string> words(words_, words_+sizeof(words_)/sizeof(*words_)); 
	int RetVal = 12; 
	return verify_case(RetVal, OrderedSuperString().getLength(words)); }
int Test_(Case_<4>) {
	timer_clear();
	string words_[] = {"aaaaaaaaaaabaaaaaaaa", "bac", "aaaabacaaa", "ab", "ba", "a", "ca"};
	vector <string> words(words_, words_+sizeof(words_)/sizeof(*words_)); 
	int RetVal = 33; 
	return verify_case(RetVal, OrderedSuperString().getLength(words)); }

template<int N> void Run_() { cerr << "Test Case #" << N << "..." << flush; Test_(Case_<N>()); Run_<sizeof(Test_(Case_<N+1>()))==1 ? -1 : N+1>(); }
template<>      void Run_<-1>() {}
int main() { Run_<0>(); }
// END CUT HERE

