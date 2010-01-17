#line 2 "grafixCorrupt.cpp"
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
#define all(c)  (c).begin(),(c).end()
#define tr(c,i)  for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); i++)
#define rep(var,n)  for(int var=0;var<(n);var++)

class grafixCorrupt {
 public:
  int match(const string& s1, const string& s2){
    int l=sz(s1),c=0;
    rep(i,l){
      if(s1[i]==s2[i]) c++;
    }
    return c;
  }
  
  int selectWord(vector <string> dictionary, string candidate) {
	int n=sz(dictionary);
    int at=-1,sc=0;
    rep(i,n){
      int s=match(dictionary[i],candidate);
      if (s>sc) {sc=s; at=i;}
    }
    return at;
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
	string dictionary_[] = {"cat", "cab", "lab"};
	  vector <string> dictionary(dictionary_, dictionary_+sizeof(dictionary_)/sizeof(*dictionary_)); 
	string candidate = "dab"; 
	int RetVal = 1; 
	return verify_case(RetVal, grafixCorrupt().selectWord(dictionary, candidate)); }
int Test_(Case_<1>) {
	timer_clear();
	string dictionary_[] = {"cat", "cab", "lab"};
	  vector <string> dictionary(dictionary_, dictionary_+sizeof(dictionary_)/sizeof(*dictionary_)); 
	string candidate = "lag"; 
	int RetVal = 2; 
	return verify_case(RetVal, grafixCorrupt().selectWord(dictionary, candidate)); }
int Test_(Case_<2>) {
	timer_clear();
	string dictionary_[] = {"cat", "cab", "lab"};
	  vector <string> dictionary(dictionary_, dictionary_+sizeof(dictionary_)/sizeof(*dictionary_)); 
	string candidate = "bic"; 
	int RetVal = -1; 
	return verify_case(RetVal, grafixCorrupt().selectWord(dictionary, candidate)); }
int Test_(Case_<3>) {
	timer_clear();
	string dictionary_[] = {"zkv", "izs", "fed", "waa", "ttx", "bgt", "quy", "dtq", "dgo", "yrs",
 "cid", "nln", "pvz", "txt", "zun", "erd", "jen", "klh", "kxy", "emf",
 "mqt", "lza", "dzb", "ndx", "vfr", "jhs", "dkm", "elb"};
	  vector <string> dictionary(dictionary_, dictionary_+sizeof(dictionary_)/sizeof(*dictionary_)); 
	string candidate = "cwd"; 
	int RetVal = 10; 
	return verify_case(RetVal, grafixCorrupt().selectWord(dictionary, candidate)); }
int Test_(Case_<4>) {
	timer_clear();
	string dictionary_[] = {"zhadjsg", "vzptftx", "fbaslxs", "ejejncm", "xpxkeae", "ixrrtzw",
 "ovctbzx", "sfzekhh", "lxzixjk", "jixdpik", "bkianck", "laclyin",
 "uqmdkfx", "dimswqo", "fojhetr", "grntrce", "obdtqwx", "bhojwcy",
 "zuuuvst", "mvqtoly", "aftmupx", "govuidx", "qklpret", "yptccki",
 "uxdnslh", "wudrusz", "uwxbvou", "ouytqun", "pjdexqe", "xraaqdw",
 "lxmoncl", "sjnjfgb", "qrlqgvc", "fgvoadm", "yohsrxw", "udpvrsr",
 "mklucgt"};
	  vector <string> dictionary(dictionary_, dictionary_+sizeof(dictionary_)/sizeof(*dictionary_)); 
	string candidate = "vklikgf"; 
	int RetVal = 36; 
	return verify_case(RetVal, grafixCorrupt().selectWord(dictionary, candidate)); }

template<int N> void Run_() { cerr << "Test Case #" << N << "..." << flush; Test_(Case_<N>()); Run_<sizeof(Test_(Case_<N+1>()))==1 ? -1 : N+1>(); }
template<>      void Run_<-1>() {}
int main() { Run_<0>(); }
// END CUT HERE


// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 

In the grafix file format, a bitmap is encoded as a
sequence of lowercase alphabetic words. All of these words are drawn from
a dictionary that has been built specially for the bitmap by a compression
algorithm. Each word in the dictionary has the same length.





It can occur that words in a grafix file are corrupted by poor
transmission or storage media. In such cases, grafix attempts to
reconstruct the original file by matching each corrupted word to a
dictionary word that contains one or more of the same characters at the same
positions.




You are given a vector <string>, dictionary, containing
every word in a grafix file's dictionary, and a string,
candidate, which is a possibly corrupted word in that file. If
there is no dictionary word that has at least one character in the
same position as candidate, then return the int
value -1. Otherwise, return the zero-based index of the dictionary word
that has the greatest number of characters at the same positions as
candidate. In the event of a tie, favor the lowest index.




DEFINITION
Class:grafixCorrupt
Method:selectWord
Parameters:vector <string>, string
Returns:int
Method signature:int selectWord(vector <string> dictionary, string candidate)


CONSTRAINTS
-dictionary contains between 1 and 50 elements, inclusive
-candidate is between 1 and 20 characters long, inclusive
-each element of dictionary has the same length as candidate
-only the characters 'a' to 'z' are permitted in candidate and dictionary


EXAMPLES

0)
{"cat", "cab", "lab"}
"dab"

Returns: 1

The word "dab" has two letters in the same position as both "cab" and "lab", but "cab" comes first.

1)
{"cat", "cab", "lab"}
"lag"

Returns: 2

Here, "lab" is the best fit.

2)
{"cat", "cab", "lab"}
"bic"

Returns: -1

The word "bic" contains a 'c' and a 'b', but neither character is at the same position in any dictionary word.

3)
{"zkv", "izs", "fed", "waa", "ttx", "bgt", "quy", "dtq", "dgo", "yrs",
 "cid", "nln", "pvz", "txt", "zun", "erd", "jen", "klh", "kxy", "emf",
 "mqt", "lza", "dzb", "ndx", "vfr", "jhs", "dkm", "elb"}
"cwd"

Returns: 10

4)
{"zhadjsg", "vzptftx", "fbaslxs", "ejejncm", "xpxkeae", "ixrrtzw",
 "ovctbzx", "sfzekhh", "lxzixjk", "jixdpik", "bkianck", "laclyin",
 "uqmdkfx", "dimswqo", "fojhetr", "grntrce", "obdtqwx", "bhojwcy",
 "zuuuvst", "mvqtoly", "aftmupx", "govuidx", "qklpret", "yptccki",
 "uxdnslh", "wudrusz", "uwxbvou", "ouytqun", "pjdexqe", "xraaqdw",
 "lxmoncl", "sjnjfgb", "qrlqgvc", "fgvoadm", "yohsrxw", "udpvrsr",
 "mklucgt"}
"vklikgf"

Returns: 36

*/
// END CUT HERE
