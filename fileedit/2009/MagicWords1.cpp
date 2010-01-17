#line 2 "MagicWords.cpp"
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
#define sz(a)  int((a).size())
#define pb  push_back
#define all(c)  (c).begin(),(c).end()
#define tr(c,i)  for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); i++)
#define rep(var,n)  for(int var=0;var<(n);var++)
#define found(s,e)  ((s).find(e)!=(s).end())

class MagicWords {
 public:
  int count(vector<string> S, int K) {
    map<string,int> memo;
    int N=sz(S);//1-8
	vi iota(N); rep(i,N)iota[i]=i;
    int cnt=0;
    int l=-1;
    do{
      string w="";
      rep(i,N) w+=S[iota[i]];
      if(found(memo,w)) cnt+=memo[w];//continue;
      else{
        if(l<0) l=sz(w);
        int c=0;
        rep(f,l){
          int d=0;
          rep(i,l){
            if(w[i]==w[(f+i)%l]) d++;
            else break;
          }
          if(d==l) c++;
          if(c>K) goto next;
        }
        if(c==K){
          memo[w]=1;
          cnt++;
        }
      }
   next:;
    }while(next_permutation(all(iota)));
    return cnt;
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
	string S_[] = {"CAD","ABRA","ABRA"};
	  vector <string> S(S_, S_+sizeof(S_)/sizeof(*S_)); 
	int K = 1; 
	int RetVal = 6; 
	return verify_case(RetVal, MagicWords().count(S, K)); }
int Test_(Case_<1>) {
	timer_clear();
	string S_[] = {"AB","RAAB","RA"};
	  vector <string> S(S_, S_+sizeof(S_)/sizeof(*S_)); 
	int K = 2; 
	int RetVal = 3; 
	return verify_case(RetVal, MagicWords().count(S, K)); }
int Test_(Case_<2>) {
	timer_clear();
	string S_[] = {"AA","AA","AAA","A"};
	  vector <string> S(S_, S_+sizeof(S_)/sizeof(*S_)); 
	int K = 1; 
	int RetVal = 0; 
	return verify_case(RetVal, MagicWords().count(S, K)); }
int Test_(Case_<3>) {
	timer_clear();
	string S_[] = {"AA","AA","AAA","A","AAA","AAAA"};
	  vector <string> S(S_, S_+sizeof(S_)/sizeof(*S_)); 
	int K = 15; 
	int RetVal = 720; 
	return verify_case(RetVal, MagicWords().count(S, K)); }
int Test_(Case_<4>) {
	timer_clear();
	string S_[] = {"ABC","AB","ABC","CA"};
	  vector <string> S(S_, S_+sizeof(S_)/sizeof(*S_)); 
	int K = 3; 
	int RetVal = 0; 
	return verify_case(RetVal, MagicWords().count(S, K)); }
int Test_(Case_<5>) {
	timer_clear();
	string S_[] = {"A","B","C","A","B","C"};
	  vector <string> S(S_, S_+sizeof(S_)/sizeof(*S_)); 
	int K = 1; 
	int RetVal = 672; 
	return verify_case(RetVal, MagicWords().count(S, K)); }
int Test_(Case_<6>) {
	timer_clear();
	string S_[] = {"AAAAAAAAAAAAAAAAAAAA",
 "AAAAAAAAAAAAAAAAAAAA",
 "AAAAAAAAAAAAAAAAAAAA",
 "AAAAAAAAAAAAAAAAAAAA",
 "AAAAAAAAAAAAAAAAAAAA",
 "AAAAAAAAAAAAAAAAAAAA",
 "AAAAAAAAAAAAAAAAAAAA",
 "AAAAAAAAAAAAAAAAAAAB"};
    vector <string> S(S_, S_+sizeof(S_)/sizeof(*S_)); 
	int K = 1; 
	int RetVal = 40320; 
	return verify_case(RetVal, MagicWords().count(S, K)); }
int Test_(Case_<7>) {
	timer_clear();
	string S_[] = {"AAAAAAAAAAAAAAAAAAAA",
                   "BBBBBBBBBBBBBBBBBBBB",
                   "CCCCCCCCCCCCCCCCCCCC",
                   "DDDDDDDDDDDDDDDDDDDD",
                   "EEEEEEEEEEEEEEEEEEEE",
                   "FFFFFFFFFFFFFFFFFFFF",
                   "GGGGGGGGGGGGGGGGGGGG",
                   "HHHHHHHHHHHHHHHHHHHH"};
    vector <string> S(S_, S_+sizeof(S_)/sizeof(*S_)); 
	int K = 200; 
	int RetVal = 40320; 
	return verify_case(RetVal, MagicWords().count(S, K)); }
int Test_(Case_<8>) {
	timer_clear();
	string S_[] = {"AAAAAAAAAAAAAAAAAAAA",
 "AAAAAAAAAAAAAAAAAAAA",
 "AAAAAAAAAAAAAAAAAAAA",
 "AAAAAAAAAAAAAAAAAAAA",
 "AAAAAAAAAAAAAAAAAAAA",
 "AAAAAAAAAAAAAAAAAAAA",
 "AAAAAAAAAAAAAAAAAAAA",
 "AAAAAAAAAAAAAAAAAAAA"};
    vector <string> S(S_, S_+sizeof(S_)/sizeof(*S_)); 
	int K = 1; 
	int RetVal = 40320; 
	return verify_case(RetVal, MagicWords().count(S, K)); }
int Test_(Case_<9>) {
	timer_clear();
	string S_[] = {"ABABABABABABABABABAB",
                   "ABABABABABABABABABAB",
                   "ABABABABABABABABABAB",
                   "ABABABABABABABABABAB",
                   "ABABABABABABABABABAB",
                   "ABABABABABABABABABAB",
                   "ABABABABABABABABABAB",
                   "ABABABABABABABABABAB"};
    vector <string> S(S_, S_+sizeof(S_)/sizeof(*S_)); 
	int K = 1; 
	int RetVal = 40320; 
	return verify_case(RetVal, MagicWords().count(S, K)); }
int Test_(Case_<10>) {
	timer_clear();
	string S_[] = {"AAAAAAAAAAAAAAAAAAAA",
 "AAAAAAAAAAAAAAAAAAAA",
 "AAAAAAAAAAAAAAAAAAAA",
 "AAAAAAAAAAAAAAAAAAAA",
 "AAAAAAAAAAAAAAAAAAAA",
 "AAAAAAAAAAAAAAAAAAAA",
 "AAAAAAAAAAAAAAAAAAAA",
 "AAAAAAAAAAAAAAAAAAAA"};
    vector <string> S(S_, S_+sizeof(S_)/sizeof(*S_)); 
	int K = 1; 
	int RetVal = 40320; 
	return verify_case(RetVal, MagicWords().count(S, K)); }
int Test_(Case_<11>) {
	timer_clear();
	string S_[] = {"AAAAAAAAAAAAAAAAAAAA",
                   "BAAAAAAAAAAAAAAAAAAA",
                   "CAAAAAAAAAAAAAAAAAAA",
                   "DAAAAAAAAAAAAAAAAAAA",
                   "EAAAAAAAAAAAAAAAAAAA",
                   "FAAAAAAAAAAAAAAAAAAA",
                   "GAAAAAAAAAAAAAAAAAAA",
                   "HAAAAAAAAAAAAAAAAAAA"};
    vector <string> S(S_, S_+sizeof(S_)/sizeof(*S_)); 
	int K = 1; 
	int RetVal = 40320; 
	return verify_case(RetVal, MagicWords().count(S, K)); }
int Test_(Case_<12>) {//32
	timer_clear();
	string S_[] = {"AAAAAAAAAAAAAAAAAAAA",
                   "AAAAAAAAAAAAAAAAAAAA",
                   "AAAAAAAAAAAAAAAAAAAA",
                   "AAAAAAAAAAAAAAAAAAAA",
                   "AAAAAAAAAAAAAAAAAAAA",
                   "AAAAAAAAAAAAAAAAAAAA",
                   "AAAAAAAAAAAAAAAAAAAA",
                   "AAAAAAAAAAAAAAAAAAAB"};
    vector <string> S(S_, S_+sizeof(S_)/sizeof(*S_)); 
	int K = 8;
	int RetVal = 0;
	return verify_case(RetVal, MagicWords().count(S, K)); }

template<int N> void Run_() { cerr << "Test Case #" << N << "..." << flush; Test_(Case_<N>()); Run_<sizeof(Test_(Case_<N+1>()))==1 ? -1 : N+1>(); }
template<>      void Run_<-1>() {}
int main() { Run_<0>(); }
// END CUT HERE


// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// Consider a string T containing exactly L characters.  The string T(i) is a cyclic shift of T starting from position i (0 <= i < L).  T(i) contains exactly the same number of characters as T.  For each j between 0 and L-1, inclusive, character j of T(i) is equal to character (i+j)%L of T.  Let's call T a magic word if there are exactly K positions i such that T(i) = T.

You are given a vector <string> S containing exactly N words.  For each permutation p = (p[0], p[1], ..., p[N-1]) of integers between 0 and N-1, inclusive, we can define a string generated by this permutation as a concatenation S[p[0]] + S[p[1]] + ... + S[p[N-1]].  Return the number of permutations that generate magic words.  All indices in this problem as 0-based.


DEFINITION
Class:MagicWords
Method:count
Parameters:vector <string>, int
Returns:int
Method signature:int count(vector <string> S, int K)


CONSTRAINTS
-S will contain between 1 and 8 elements, inclusive.
-Each element of S will contain between 1 and 20 characters, inclusive.
-Each element of S will contain only uppercase letters ('A'-'Z').
-K will be between 1 and 200, inclusive.


EXAMPLES

0)
{"CAD","ABRA","ABRA"}
1

Returns: 6

Every permutation generates a magic word here.

1)
{"AB","RAAB","RA"}
2

Returns: 3

The magic words are "ABRAABRA" and "RAABRAAB". The first word is generated only by the permutation (0, 1, 2), and the second word is generated by the two permutations (1, 2, 0) and (2, 0, 1).

2)
{"AA","AA","AAA","A"}
1

Returns: 0

All permutations generate the string "AAAAAAAA" and it clearly is not a magic word because all its cyclic shifts are the same as the original string.

3)
{"AA","AA","AAA","A","AAA","AAAA"}
15

Returns: 720

4)
{"ABC","AB","ABC","CA"}
3

Returns: 0



5)
{"A","B","C","A","B","C"}
1

Returns: 672



6)
{"AAAAAAAAAAAAAAAAAAAA",
 "AAAAAAAAAAAAAAAAAAAA",
 "AAAAAAAAAAAAAAAAAAAA",
 "AAAAAAAAAAAAAAAAAAAA",
 "AAAAAAAAAAAAAAAAAAAA",
 "AAAAAAAAAAAAAAAAAAAA",
 "AAAAAAAAAAAAAAAAAAAA",
 "AAAAAAAAAAAAAAAAAAAB"}
1

Returns: 40320



*/
// END CUT HERE
