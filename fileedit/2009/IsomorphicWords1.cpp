// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// Two words are called isomorphic if the letters in one word can be remapped to get the second word.  Remapping a letter means replacing all occurrences of it with another letter. The ordering of the letters remains unchanged. No two letters may map to the same letter, but a letter may map to itself.

For example, the words "abca" and "zbxz" are isomorphic because we can map 'a' to 'z', 'b' to 'b' and 'c' to 'x'.

Given a vector <string> words, return how many (unordered) pairs of words are isomorphic.


DEFINITION
Class:IsomorphicWords
Method:countPairs
Parameters:vector <string>
Returns:int
Method signature:int countPairs(vector <string> words)


CONSTRAINTS
-words will contain between 2 and 50 elements, inclusive.
-Each element of words will contain between 1 and 50 lowercase letters ('a'-'z'), inclusive.
-All elements of words will have the same length.
-There will be no duplicates in words.


EXAMPLES

0)
{"abca", "zbxz", "opqr"}

Returns: 1

"abca" and "zbxz" are isomorphic, but none of the two is isomorphic with "opqr".

1)
{"aa", "ab", "bb", "cc", "cd"}

Returns: 4

The four isomorphic pairs are {"aa", "bb"}, {"aa", "cc"}, {"bb", "cc"} and {"ab", "cd"}.

2)
{ "cacccdaabc", "cdcccaddbc", "dcdddbccad", "bdbbbaddcb",
  "bdbcadbbdc", "abaadcbbda", "babcdabbac", "cacdbaccad",
  "dcddabccad", "cacccbaadb", "bbcdcbcbdd", "bcbadcbbca" }

Returns: 13



*/
// END CUT HERE

#line 55 "IsomorphicWords.cpp"
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

long long c(int n, int r)
{
  if (n == 0 || r == 0 || r == n) return 1LL;
  if (r > n-r) r = n-r;
  return c(n-1,r-1) * n / r;
}

class IsomorphicWords {
  map<string,int> memo;
  int sig_;
  int sig(string s){
	if(found(memo,s)) return memo[s];
	//cout << "sig( " << cs << " ) => " << sig_+1 <<endl;
	return memo[s]=++sig_;
  }
public:
  int countPairs(vector<string> words) {
	sig_=0;

	int n=sz(words),l=words[0].length(); //2-50
	vector<int> sigs(n,-1);
	string buf = words[0];
	//char buf[51]; buf[l] = 0;
	rep(j,n){
	  const string word=words[j];
	  vector<int> cs(26,0);
	  rep(i,l) cs[word[i]-'a']++;
	  vector<int> cs_(all(cs)); remove_(cs_,0); sort(all(cs_));
	  tr(cs_,it){
		int id=-1; rep(i,26) if(*it==cs[i]) {id=i;break;}
		//printf("*it=%d, id=%d\n", *it, id);
		rep(k,l) if(word[k]=='a'+id) buf[k]='0'+id;
		cs[id] = -1;
	  }
	  sigs[j] = sig(buf);
	  cout << word << " => " << cs << " => " << buf << " => " << sigs[j] << endl;
	}
	cout << "sigs: " << sigs << endl;
	map<int,int> cnt;
	tr(sigs,it){
	  if(found(cnt,*it)) cnt[*it]++;
	  else cnt[*it]=1;
	}
	int total=0;
	cout << cnt <<endl;
	tr(cnt,it){
	  cout << *it<< endl;
	  if(it->second==1) continue;
	  total += c(it->second,2);
	}
	return total;
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
	string words_[] = {"abca", "zbxz", "opqr"};
	  vector <string> words(words_, words_+sizeof(words_)/sizeof(*words_)); 
	int RetVal = 1; 
	return verify_case(RetVal, IsomorphicWords().countPairs(words)); }
int Test_(Case_<1>) {
	timer_clear();
	string words_[] = {"aa", "ab", "bb", "cc", "cd"};
	  vector <string> words(words_, words_+sizeof(words_)/sizeof(*words_)); 
	int RetVal = 4; 
	return verify_case(RetVal, IsomorphicWords().countPairs(words)); }
int Test_(Case_<2>) {
	timer_clear();
	string words_[] = { "cacccdaabc", "cdcccaddbc", "dcdddbccad", "bdbbbaddcb",
  "bdbcadbbdc", "abaadcbbda", "babcdabbac", "cacdbaccad",
  "dcddabccad", "cacccbaadb", "bbcdcbcbdd", "bcbadcbbca" };
	  vector <string> words(words_, words_+sizeof(words_)/sizeof(*words_)); 
	int RetVal = 13; 
	return verify_case(RetVal, IsomorphicWords().countPairs(words)); }

template<int N> void Run_() { cerr << "Test Case #" << N << "..." << flush; Test_(Case_<N>()); Run_<sizeof(Test_(Case_<N+1>()))==1 ? -1 : N+1>(); }
template<>      void Run_<-1>() {}
int main() { Run_<0>(); }
// END CUT HERE

