#line 2 "Mb.cc"
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

#include "bits.h"

class Masterbrain {
// BEGIN CUT HERE
  string enc(int n){
    char s[5] = { '1'+((n/343)%7), '1'+((n/49)%7), '1'+((n/7)%7), '1'+(n%7), 0 };
    return string(s);
  }
// END CUT HERE

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

  //  void x_not_and(vector<int>& a, vector<int>& b){ rep(i,2401) a[i] &= (1 - b[i]); }
  //  void x_and(vector<int>& a, vector<int>& b){ rep(i,2401) a[i] &= b[i]; }
  //  void x_or(vector<int>& a, vector<int>& b){ rep(i,2401) a[i] |= b[i]; }
  
 public:
  int possibleSecrets(vector <string> guesses, vector <string> results) {
    // secret: 7^4 = 2401 patterns
    n = sz(guesses); // 1..10
    vector<Bits*> bits(n,NULL);
    rep(i,n){
      bits[i] = new Bits(2401,0);
      const char *s = results[i].c_str();
      int b = s[0]-'0', w = s[3]-'0';
      //printf("guess #%d: %s => black x %d, white x %d\n", i, guesses[i].c_str(), b, w);
      rep(j,2401) bits[i]->set(j, possible(j,guesses[i],b,w));
    }

    Bits possibles(2401,0);
    rep(u,n){
      Bits a(2401,1);
      rep(i,n){
        if (i==u) a &= ~(*bits[i]);
        else      a &=  (*bits[i]);
      }
      possibles |= a;
    }

    rep(i,n) delete bits[i];
        
    return possibles.popcount();
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

