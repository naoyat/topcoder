// BEGIN CUT HERE
/* 286.47 in 600
// PROBLEM STATEMENT
// Masterbrain is a two player board game in which one player decides on a secret combination of digits, while the other must figure it out in 10 guesses or less. The game differs from Mastermind in that the player making the secret combination is allowed to lie once.
The game consists of one player making a sequence of guesses about what the secret combination is, and the other player giving him or her certain information about the quality of the guess.  The following is how each guess is analyzed: if a digit is in the correct position then a black peg is given. If a digit is in the guess but in the wrong position then a white peg is given. For all other cases no pegs are given.
For example, if guess = "1234", secret = "2335". Analyzing the guess digit by digit; the '1' is not in secret - no pegs given. The '2' is in secret but not in the right place - white peg given. The '3' is in secret and in the right place - black peg given. The '4' is not in secret - no pegs given. Result should be "1b 1w", meaning one black peg and one white peg. Now, if guess is "2334" and secret is "3224", we have the following: '2' is in secret, but not in the right place - white peg given. The first '3' is in secret, but not in the right place - white peg given. Since the '3' in secret has been used, the second '3' in guess should return no pegs. The '4' is in secret and in the right place - black peg given. Result should be "1b 2w".
Given a vector <string> of guesses and a vector <string> of results for those guesses, return the total number of possible secret combinations, assuming that exactly one of the results is incorrect. Each element of results will be formatted as "<x>b <y>w", where <x> and <y> are the number of black and white pegs respectively.

DEFINITION
Class:Masterbrain
Method:possibleSecrets
Parameters:vector <string>, vector <string>
Returns:int
Method signature:int possibleSecrets(vector <string> guesses, vector <string> results)


NOTES
-The second player must lie exactly once.
-Black pegs always take precedence over white pegs.  Thus, when analyzing a guess, black pegs are assigned first, and then white pegs are assigned.
-No digit in either a guess or a secret combination may be involved in giving more than one peg.


CONSTRAINTS
-guesses and results will have the same number of elements.
-guesses will have between 1 and 10 elements inclusive.
-results will have between 1 and 10 elements inclusive.
-each element in guesses will contain exactly 4 characters and will only contain digits between '1' and '7' inclusive.
-each element in results will contain exactly 5 characters.
-each element of results will be formatted as follows: "<x>b <y>w", where <x> represents the number of black pegs and <y> represents the number of white pegs in a guess. <x> and <y> are non-negative integers whose sum is less than or equal to 4.
-results will never have "3b 1w", because that is impossible.


EXAMPLES

0)
{"1575"} 
{"4b 0w"}

Returns: 2400

If the result was true, we would conclude that 1575 is the only possible combination. However, we know that the second player must lie exactly once, thus we know that 1575 is the only combination NOT possible. Since there are 7^4 = 2401 total combinations, the method should return 2401-1 = 2400.

1)
{"1234"}
{"0b 4w"}

Returns: 2392

If the result was true then the set of secret combinations would have 9 elements: {2143, 2341, 2413, 3142, 3412, 3421, 4123, 4312, 4321}. But since the result is false, we must subtract this number from the total. The method should return 2401-9 = 2392.

2)
{"6172","6162","3617"}
{"3b 0w","2b 1w","0b 3w"}

Returns: 14

If all results were true, then the secret must be 6176. If the first result is false then the set of secret combinations is {1362, 1762, 2163, 6123, 6136, 6176, 6361, 6761, 7166}. If the second result is false then set is {6132, 6171, 6174, 6175, 6176, 6372}. Finally, if the third result is false then the set is {6176, 6672}. Thus the method should return (9-1)+(6-1)+(2-1) = 14.

3)
{"1513","5654","4564","1377","1671","1342"}
{"1b 0w","0b 1w","1b 0w","1b 0w","0b 1w","0b 1w"}

Returns: 6

4)
{"2611", "1371", "7417", "2647", "3735", "4272", "2442", "3443", "1252", "3353"}
{"0b 2w","0b 2w","0b 1w","0b 2w","1b 0w","1b 0w","1b 0w","0b 1w","1b 1w","0b 1w"}

Returns: 1

*/
// END CUT HERE

#line 75 "Masterbrain.cpp"
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
#define sz(a)  int((a).size())
#define rep(var,n)  for(int var=0;var<(n);var++)

class Masterbrain {
  string enc(int n){
    char s[5] = { '1'+((n/343)%7), '1'+((n/49)%7), '1'+((n/7)%7), '1'+(n%7), 0 };
    return string(s);
  }
  
  int n;
  int possible(int secret, string guess, int result_b, int result_w){
    int s[4] = { (secret/343)%7, (secret/49)%7, (secret/7)%7, secret%7 };
    int g[4]; rep(i,4) g[i] = guess[i]-'1';
    int b=0, w=0; 
    rep(i,4) if(g[i]==s[i]){ b++; g[i]=s[i]=-1;}
    rep(i,4) rep(j,4) {
      if (i==j || g[i]<0 || s[j]<0) continue;
      if (g[i]==s[j]){ w++; g[i]=-1; s[j]=-1; break; }
    }
    //printf("possible? (%s, %s) = %d b + %d w\n", enc(secret).c_str(), guess.c_str(), b,w);
    return (b==result_b && w==result_w)?1:0;
  }

  void x_not_and(vector<int>& a, vector<int>& b){ rep(i,2401) a[i] &= (1 - b[i]); }
  void x_and(vector<int>& a, vector<int>& b){ rep(i,2401) a[i] &= b[i]; }
  void x_or(vector<int>& a, vector<int>& b){ rep(i,2401) a[i] |= b[i]; }
  
 public:
  int possibleSecrets(vector <string> guesses, vector <string> results) {
    // secret: 7^4 = 2401 patterns
    n = sz(guesses); // 1..10
    vector<vector<int> > bits(n);
    rep(i,n){
      const char *s = results[i].c_str();
      int b = s[0]-'0', w = s[3]-'0';
      //printf("guess #%d: %s => black x %d, white x %d\n", i, guesses[i].c_str(), b, w);
      vector<int> bit(2401,0);
      rep(n,2401){
        bit[n] = possible(n,guesses[i],b,w);
      }
      bits[i] = bit;
    }

    vector<int> possibles(2401,0);

    rep(u,n){
      vector<int> a(2401,1);
      rep(i,n){
        if(i==u){
          x_not_and(a,bits[i]);
        } else {
          x_and(a,bits[i]);
        }
      }
      
      x_or(possibles,a);
    }
    int bitcnt=0;
    rep(i,2401) bitcnt+=possibles[i]; //if(possibles[i]) cout << enc(i) << endl; }
    return bitcnt;
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
	string guesses_[] = {"1575"} ;
	  vector <string> guesses(guesses_, guesses_+sizeof(guesses_)/sizeof(*guesses_)); 
	string results_[] = {"4b 0w"};
	  vector <string> results(results_, results_+sizeof(results_)/sizeof(*results_)); 
	int RetVal = 2400; 
	return verify_case(RetVal, Masterbrain().possibleSecrets(guesses, results)); }
int Test_(Case_<1>) {
	timer_clear();
	string guesses_[] = {"1234"};
	  vector <string> guesses(guesses_, guesses_+sizeof(guesses_)/sizeof(*guesses_)); 
	string results_[] = {"0b 4w"};
	  vector <string> results(results_, results_+sizeof(results_)/sizeof(*results_)); 
	int RetVal = 2392; 
	return verify_case(RetVal, Masterbrain().possibleSecrets(guesses, results)); }
int Test_(Case_<2>) {
	timer_clear();
	string guesses_[] = {"6172","6162","3617"};
	  vector <string> guesses(guesses_, guesses_+sizeof(guesses_)/sizeof(*guesses_)); 
	string results_[] = {"3b 0w","2b 1w","0b 3w"};
	  vector <string> results(results_, results_+sizeof(results_)/sizeof(*results_)); 
	int RetVal = 14; 
	return verify_case(RetVal, Masterbrain().possibleSecrets(guesses, results)); }
int Test_(Case_<3>) {
	timer_clear();
	string guesses_[] = {"1513","5654","4564","1377","1671","1342"};
	  vector <string> guesses(guesses_, guesses_+sizeof(guesses_)/sizeof(*guesses_)); 
	string results_[] = {"1b 0w","0b 1w","1b 0w","1b 0w","0b 1w","0b 1w"};
	  vector <string> results(results_, results_+sizeof(results_)/sizeof(*results_)); 
	int RetVal = 6; 
	return verify_case(RetVal, Masterbrain().possibleSecrets(guesses, results)); }
int Test_(Case_<4>) {
	timer_clear();
	string guesses_[] = {"2611", "1371", "7417", "2647", "3735", "4272", "2442", "3443", "1252", "3353"};
	  vector <string> guesses(guesses_, guesses_+sizeof(guesses_)/sizeof(*guesses_)); 
	string results_[] = {"0b 2w","0b 2w","0b 1w","0b 2w","1b 0w","1b 0w","1b 0w","0b 1w","1b 1w","0b 1w"};
	  vector <string> results(results_, results_+sizeof(results_)/sizeof(*results_)); 
	int RetVal = 1; 
	return verify_case(RetVal, Masterbrain().possibleSecrets(guesses, results)); }

template<int N> void Run_() { cerr << "Test Case #" << N << "..." << flush; Test_(Case_<N>()); Run_<sizeof(Test_(Case_<N+1>()))==1 ? -1 : N+1>(); }
template<>      void Run_<-1>() {}
int main() { Run_<0>(); }
// END CUT HERE

