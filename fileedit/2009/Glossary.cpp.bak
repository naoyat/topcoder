#line 2 "Glossary.cpp"
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

string to_lower(string s)
{
  stringstream ss;
  rep(i,sz(s)) ss << (char)tolower(s[i]);
  return ss.str();
}
string to_upper(string s)
{
  stringstream ss;
  rep(i,sz(s)) ss << (char)toupper(s[i]);
  return ss.str();
}

class Glossary {
 public:
  vector<string> buildGlossary(vector<string> items) {
    tr(items,it){
      string s=*it, s_=to_lower(s);
      
      //int ca=s[0];if(ca<='Z')
    }
	vector<string> atom, ntoz;
    return atom;
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
	string items_[] = {"Canada", "France", "Germany", "Italy", "Japan", "Russia", 
 "United Kingdom", "United States"};
	  vector <string> items(items_, items_+sizeof(items_)/sizeof(*items_)); 
	string RetVal_[] = {"C                    R                  ", "-------------------  -------------------", "  Canada               Russia           ", "F                    U                  ", "-------------------  -------------------", "  France               United Kingdom   ", "G                      United States    ", "-------------------                     ", "  Germany                               ", "I                                       ", "-------------------                     ", "  Italy                                 ", "J                                       ", "-------------------                     ", "  Japan                                 " };
	  vector <string> RetVal(RetVal_, RetVal_+sizeof(RetVal_)/sizeof(*RetVal_)); 
	return verify_case(RetVal, Glossary().buildGlossary(items)); }
int Test_(Case_<1>) {
	timer_clear();
	string items_[] = {"alpha", "beta", "gamma", "delta", "omega"};
	  vector <string> items(items_, items_+sizeof(items_)/sizeof(*items_)); 
	string RetVal_[] = {"A                    O                  ", "-------------------  -------------------", "  alpha                omega            ", "B                                       ", "-------------------                     ", "  beta                                  ", "D                                       ", "-------------------                     ", "  delta                                 ", "G                                       ", "-------------------                     ", "  gamma                                 " };
	  vector <string> RetVal(RetVal_, RetVal_+sizeof(RetVal_)/sizeof(*RetVal_)); 
	return verify_case(RetVal, Glossary().buildGlossary(items)); }
int Test_(Case_<2>) {
	timer_clear();
	string items_[] = {"AVL tree", "backtracking", "array", "balanced tree", "binary search"};
	  vector <string> items(items_, items_+sizeof(items_)/sizeof(*items_)); 
	string RetVal_[] = {"A                                       ", "-------------------                     ", "  array                                 ", "  AVL tree                              ", "B                                       ", "-------------------                     ", "  backtracking                          ", "  balanced tree                         ", "  binary search                         " };
	  vector <string> RetVal(RetVal_, RetVal_+sizeof(RetVal_)/sizeof(*RetVal_)); 
	return verify_case(RetVal, Glossary().buildGlossary(items)); }
int Test_(Case_<3>) {
	timer_clear();
	string items_[] = {"XXXXXXXXXXXXXXXXX", 
 "YYYYYYYYYYYYYYYYY",
 "ZZZZZZZZZZZZZZZZZ"};
	  vector <string> items(items_, items_+sizeof(items_)/sizeof(*items_)); 
	string RetVal_[] = {"                     X                  ", "                     -------------------", "                       XXXXXXXXXXXXXXXXX", "                     Y                  ", "                     -------------------", "                       YYYYYYYYYYYYYYYYY", "                     Z                  ", "                     -------------------", "                       ZZZZZZZZZZZZZZZZZ" };
	  vector <string> RetVal(RetVal_, RetVal_+sizeof(RetVal_)/sizeof(*RetVal_)); 
	return verify_case(RetVal, Glossary().buildGlossary(items)); }
int Test_(Case_<4>) {
	timer_clear();
	string items_[] = {"Asteria", "Astraeus", "Atlas", "Clymene", "Coeus", "Crius", 
 "Cronus", "Dione", "Epimetheus", "Helios", "Hyperion", "Iapetus", 
 "Leto", "Mnemosyne", "Oceanus", "Ophion", "Phoebe", "Prometheus", 
 "Rhea", "Tethys", "Theia", "Themis"};
	  vector <string> items(items_, items_+sizeof(items_)/sizeof(*items_)); 
	string RetVal_[] = {"A                    O                  ", "-------------------  -------------------", "  Asteria              Oceanus          ", "  Astraeus             Ophion           ", "  Atlas              P                  ", "C                    -------------------", "-------------------    Phoebe           ", "  Clymene              Prometheus       ", "  Coeus              R                  ", "  Crius              -------------------", "  Cronus               Rhea             ", "D                    T                  ", "-------------------  -------------------", "  Dione                Tethys           ", "E                      Theia            ", "-------------------    Themis           ", "  Epimetheus                            ", "H                                       ", "-------------------                     ", "  Helios                                ", "  Hyperion                              ", "I                                       ", "-------------------                     ", "  Iapetus                               ", "L                                       ", "-------------------                     ", "  Leto                                  ", "M                                       ", "-------------------                     ", "  Mnemosyne                             " };
	  vector <string> RetVal(RetVal_, RetVal_+sizeof(RetVal_)/sizeof(*RetVal_)); 
	return verify_case(RetVal, Glossary().buildGlossary(items)); }

template<int N> void Run_() { cerr << "Test Case #" << N << "..." << flush; Test_(Case_<N>()); Run_<sizeof(Test_(Case_<N+1>()))==1 ? -1 : N+1>(); }
template<>      void Run_<-1>() {}
int main() { Run_<0>(); }
// END CUT HERE


// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// A glossary is an alphabetical list of terms in some specialized field of knowledge, usually published as an appendix to a text on that field.


In this problem, you will be given a vector <string> items, where each element is a single term.  You must build a two column glossary of these terms using the following method:

For each letter 'A'-'Z', if there is at least one term that begins with that letter (case-insensitive), create an entry for the letter in the following format:

Place the uppercase letter on the first line.
Place 19 dashes ('-') on the second line.
Place each term that begins with the letter on a new line, in alphabetical order (again, case-insensitive).  Each term should be preceded by exactly 2 spaces.
Pad all lines with spaces on the right side until they are exactly 19 characters wide.




Now, sort these entries alphabetically by their letter, and split them into two columns.  The left column should contain the entries for letters 'A' through 'M', inclusive, and the right column should contain the entries for letters 'N' through 'Z', inclusive.  Each column must be exactly 19 characters wide, and the two columns must be separated by exactly 2 spaces.  See examples for clarification.


DEFINITION
Class:Glossary
Method:buildGlossary
Parameters:vector <string>
Returns:vector <string>
Method signature:vector <string> buildGlossary(vector <string> items)


NOTES
-Two strings differing only in capitalization are considered the same, for example "aa" and "aA" are same.


CONSTRAINTS
-items will contain between 1 and 50 elements, inclusive.
-Each element of items will contain between 1 and 17 characters, inclusive.
-Each element of items will contain letters ('A' - 'Z', 'a' - 'z') and spaces (' ') only.
-Each element of items will start with a letter.
-Each term will appear at most once in items.


EXAMPLES

0)
{"Canada", "France", "Germany", "Italy", "Japan", "Russia", 
 "United Kingdom", "United States"}

Returns: {"C                    R                  ", "-------------------  -------------------", "  Canada               Russia           ", "F                    U                  ", "-------------------  -------------------", "  France               United Kingdom   ", "G                      United States    ", "-------------------                     ", "  Germany                               ", "I                                       ", "-------------------                     ", "  Italy                                 ", "J                                       ", "-------------------                     ", "  Japan                                 " }

The Group of Eight. Together, these countries represent about 65% of the world economy.

1)
{"alpha", "beta", "gamma", "delta", "omega"}

Returns: {"A                    O                  ", "-------------------  -------------------", "  alpha                omega            ", "B                                       ", "-------------------                     ", "  beta                                  ", "D                                       ", "-------------------                     ", "  delta                                 ", "G                                       ", "-------------------                     ", "  gamma                                 " }



2)
{"AVL tree", "backtracking", "array", "balanced tree", "binary search"}

Returns: {"A                                       ", "-------------------                     ", "  array                                 ", "  AVL tree                              ", "B                                       ", "-------------------                     ", "  backtracking                          ", "  balanced tree                         ", "  binary search                         " }

The second column might be empty, but you need to pad each line of the result with spaces.

3)
{"XXXXXXXXXXXXXXXXX", 
 "YYYYYYYYYYYYYYYYY",
 "ZZZZZZZZZZZZZZZZZ"}

Returns: {"                     X                  ", "                     -------------------", "                       XXXXXXXXXXXXXXXXX", "                     Y                  ", "                     -------------------", "                       YYYYYYYYYYYYYYYYY", "                     Z                  ", "                     -------------------", "                       ZZZZZZZZZZZZZZZZZ" }

The first column may be empty too.

4)
{"Asteria", "Astraeus", "Atlas", "Clymene", "Coeus", "Crius", 
 "Cronus", "Dione", "Epimetheus", "Helios", "Hyperion", "Iapetus", 
 "Leto", "Mnemosyne", "Oceanus", "Ophion", "Phoebe", "Prometheus", 
 "Rhea", "Tethys", "Theia", "Themis"}

Returns: {"A                    O                  ", "-------------------  -------------------", "  Asteria              Oceanus          ", "  Astraeus             Ophion           ", "  Atlas              P                  ", "C                    -------------------", "-------------------    Phoebe           ", "  Clymene              Prometheus       ", "  Coeus              R                  ", "  Crius              -------------------", "  Cronus               Rhea             ", "D                    T                  ", "-------------------  -------------------", "  Dione                Tethys           ", "E                      Theia            ", "-------------------    Themis           ", "  Epimetheus                            ", "H                                       ", "-------------------                     ", "  Helios                                ", "  Hyperion                              ", "I                                       ", "-------------------                     ", "  Iapetus                               ", "L                                       ", "-------------------                     ", "  Leto                                  ", "M                                       ", "-------------------                     ", "  Mnemosyne                             " }

Titans.

*/
// END CUT HERE
