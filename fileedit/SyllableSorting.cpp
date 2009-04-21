// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// Syllable sorting is a method of sorting words based on their syllabic decompositions.  The first step is to decompose each word into syllables.  A syllable is defined as a maximal non-empty substring of consonants followed by a maximal non-empty substring of vowels.  The only vowels are 'a', 'e', 'i', 'o' and 'u'.  All other letters are considered consonants.  All words will start with a consonant and end with a vowel.

To compare two words syllabically, first decompose them into sequences of syllables.  For example, the words "zcdbadaerfe" and "foubsyudba" decompose as follows:


"zcdbadaerfe" = {"zcdba", "dae", "rfe"}
"foubsyudba" = {"fou", "bsyu", "dba"}


Then, sort each sequence of syllables alphabetically.  In the above example, the sequences become:


{"dae", "rfe", "zcdba"}
{"bsyu", "dba", "fou"}


Then, compare these sorted sequences lexicographically.  A sequence S1 comes before a sequence S2 lexicographically if S1 has an alphabetically earlier element at the first index at which they differ.  In the above example, the second sequence comes earlier lexicographically because "bsyu" comes before "dae" alphabetically.

If two sorted sequences are equal, then compare their corresponding unsorted sequences instead.  For example, the words "daba" and "bada" decompose into the same sorted sequence {"ba", "da"}.  Compare the unsorted sequences {"da", "ba"} and {"ba", "da"} to determine that "bada" comes before "daba".

You are given a vector <string> words.  Sort the words using the method above and return the resulting vector <string>.

DEFINITION
Class:SyllableSorting
Method:sortWords
Parameters:vector <string>
Returns:vector <string>
Method signature:vector <string> sortWords(vector <string> words)


CONSTRAINTS
-words will contain between 1 and 50 elements, inclusive.
-Each element of words will contain between 2 and 50 characters, inclusive.
-Each element of words will contain only lowercase letters ('a'-'z').
-The first character of each element of words will be a consonant.
-The last character of each element of words will be a vowel.


EXAMPLES

0)
{"xiaoxiao", "yamagawa", "gawayama"}

Returns: {"gawayama", "yamagawa", "xiaoxiao" }

After decomposing the words into sequences of syllables, we get the following unsorted and sorted sequences of syllables:


   WORD    |    UNSORTED SEQUENCES    |     SORTED SEQUENCES
-----------+--------------------------+--------------------------
"xiaoxiao" | {"xiao", "xiao"}         | {"xiao", "xiao"}
"yamagawa" | {"ya", "ma", "ga", "wa"} | {"ga", "ma", "ya", "wa"}
"gawayama" | {"ga", "wa", "ya", "ma"} | {"ga", "ma", "ya", "wa"}


To compare "xiaoxiao" with the other two words, we use the sorted sequences of syllables. However, to compare "yamagawa" with "gawayama" we have to use the unsorted sequences because the sorted ones are equal.

1)
{"bcedba", "dbabce", "zyuxxo"}

Returns: {"bcedba", "dbabce", "zyuxxo" }



2)
{"hgnibqqaxeiuteuuvksi", "jxbuzui", "zrotyqeruiydozui",
 "ywuuzkto", "lmopbookoagyco", "vredfvavvexliu"}

Returns: {"hgnibqqaxeiuteuuvksi", "vredfvavvexliu", "lmopbookoagyco", "jxbuzui", "zrotyqeruiydozui", "ywuuzkto" }



3)
{"crazgo", "cwsoygiokiuo", "yueoseeu", "tuadiojvugeoe",
 "naumxditui", "sgukkelyoi", "nrohjuasoia", "mgabmo"}

Returns: {"mgabmo", "crazgo", "cwsoygiokiuo", "tuadiojvugeoe", "nrohjuasoia", "sgukkelyoi", "naumxditui", "yueoseeu" }



4)
{"wheewjuguoi", "coutcu", "hqivaa", "sgiibgwi", "ypaqpki",
 "bgyikouapae", "wqakeu", "skolfo", "pzesaa", "ypivhi"}

Returns: {"sgiibgwi", "bgyikouapae", "coutcu", "wheewjuguoi", "hqivaa", "wqakeu", "skolfo", "pzesaa", "ypaqpki", "ypivhi" }



*/
// END CUT HERE

#line 96 "SyllableSorting.cpp"
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

string join(const vector<string> &v){
  stringstream ss;
  tr(v,it) ss << *it;
  return ss.str();
}
class SyllableSorting {
  int vowelp(int c){
    switch(c){
      case 'a':case 'e':case 'i':case 'o':case 'u': return true;
      default: return false;
    }
  }
  vector<string> parse(string s){
    vector<string> res;
    int st=1,l=sz(s),b=0;
    for(int i=0;i<l;i++){
      if(vowelp(s[i])){
        st=2;
      }else{
        if(st==2){
          res.pb(s.substr(b,i-b));
          b=i;
          st=1;
        }
      }
    }
    if(b<l) res.pb(s.substr(b));
    //cout << s << " => " << res << endl;
    return res;
  }
 public:
  vector<string> sortWords(vector<string> words) {
    int n=sz(words);
    vector<pair<vector<string>,pair<vector<string>,string> > > res(n);
    rep(i,n){
      vector<string> syls=parse(words[i]);
      vector<string> sorted(all(syls));
      sort(all(sorted));
      res[i]=make_pair(sorted,make_pair(syls,words[i]));
      //cout << res[i] << endl;
    }
    sort(all(res));
    //cout << res << endl;
    vector<string> ans(n);
    rep(i,n) ans[i]=res[i].second.second;
    return ans;
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
	string words_[] = {"xiaoxiao", "yamagawa", "gawayama"};
	  vector <string> words(words_, words_+sizeof(words_)/sizeof(*words_)); 
	string RetVal_[] = {"gawayama", "yamagawa", "xiaoxiao" };
	  vector <string> RetVal(RetVal_, RetVal_+sizeof(RetVal_)/sizeof(*RetVal_)); 
	return verify_case(RetVal, SyllableSorting().sortWords(words)); }
int Test_(Case_<1>) {
	timer_clear();
	string words_[] = {"bcedba", "dbabce", "zyuxxo"};
	  vector <string> words(words_, words_+sizeof(words_)/sizeof(*words_)); 
	string RetVal_[] = {"bcedba", "dbabce", "zyuxxo" };
	  vector <string> RetVal(RetVal_, RetVal_+sizeof(RetVal_)/sizeof(*RetVal_)); 
	return verify_case(RetVal, SyllableSorting().sortWords(words)); }
int Test_(Case_<2>) {
	timer_clear();
	string words_[] = {"hgnibqqaxeiuteuuvksi", "jxbuzui", "zrotyqeruiydozui",
 "ywuuzkto", "lmopbookoagyco", "vredfvavvexliu"};
	  vector <string> words(words_, words_+sizeof(words_)/sizeof(*words_)); 
	string RetVal_[] = {"hgnibqqaxeiuteuuvksi", "vredfvavvexliu", "lmopbookoagyco", "jxbuzui", "zrotyqeruiydozui", "ywuuzkto" };
	  vector <string> RetVal(RetVal_, RetVal_+sizeof(RetVal_)/sizeof(*RetVal_)); 
	return verify_case(RetVal, SyllableSorting().sortWords(words)); }
int Test_(Case_<3>) {
	timer_clear();
	string words_[] = {"crazgo", "cwsoygiokiuo", "yueoseeu", "tuadiojvugeoe",
 "naumxditui", "sgukkelyoi", "nrohjuasoia", "mgabmo"};
	  vector <string> words(words_, words_+sizeof(words_)/sizeof(*words_)); 
	string RetVal_[] = {"mgabmo", "crazgo", "cwsoygiokiuo", "tuadiojvugeoe", "nrohjuasoia", "sgukkelyoi", "naumxditui", "yueoseeu" };
	  vector <string> RetVal(RetVal_, RetVal_+sizeof(RetVal_)/sizeof(*RetVal_)); 
	return verify_case(RetVal, SyllableSorting().sortWords(words)); }
int Test_(Case_<4>) {
	timer_clear();
	string words_[] = {"wheewjuguoi", "coutcu", "hqivaa", "sgiibgwi", "ypaqpki",
 "bgyikouapae", "wqakeu", "skolfo", "pzesaa", "ypivhi"};
	  vector <string> words(words_, words_+sizeof(words_)/sizeof(*words_)); 
	string RetVal_[] = {"sgiibgwi", "bgyikouapae", "coutcu", "wheewjuguoi", "hqivaa", "wqakeu", "skolfo", "pzesaa", "ypaqpki", "ypivhi" };
	  vector <string> RetVal(RetVal_, RetVal_+sizeof(RetVal_)/sizeof(*RetVal_)); 
	return verify_case(RetVal, SyllableSorting().sortWords(words)); }
int Test_(Case_<5>) {
	timer_clear();
	string words_[] = {"baqibae", "baebaqi"};
    vector <string> words(words_, words_+sizeof(words_)/sizeof(*words_)); 
	string RetVal_[] = {"baqibae", "baebaqi"};
    vector <string> RetVal(RetVal_, RetVal_+sizeof(RetVal_)/sizeof(*RetVal_)); 
	return verify_case(RetVal, SyllableSorting().sortWords(words)); }

template<int N> void Run_() { cerr << "Test Case #" << N << "..." << flush; Test_(Case_<N>()); Run_<sizeof(Test_(Case_<N+1>()))==1 ? -1 : N+1>(); }
template<>      void Run_<-1>() {}
int main() { Run_<0>(); }
// END CUT HERE

