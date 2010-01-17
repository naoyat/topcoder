#line 2 "BinaryCode.cpp"
// 239.07
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
// BEGIN CUT HERE
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<string> vs;
typedef vector<long long> vll;
// END CUT HERE
#define sz(a)  int((a).size())
#define pb  push_back
#define FOR(var,from,to) for(int var=(from);var<=(to);var++)
#define rep(var,n)  for(int var=0;var<(n);var++)
// BEGIN CUT HERE
#define all(c)  (c).begin(),(c).end()
#define tr(c,i)  for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); i++)
#define RFOR(var,from,to) for(int var=(to);var>=(from);var--)
#define found(s,e)  ((s).find(e)!=(s).end())
#define mset(arr,val)  memset(arr,val,sizeof(arr))
#define remove_(c,val) (c).erase(remove((c).begin(),(c).end(),(val)),(c).end())
#define lastc(str) (*((str).end()-1))

typedef pair<int,int> i_i;
typedef pair<ll,ll> ll_ll;
typedef pair<double,double> d_d;
typedef pair<int,pair<int,int> > i_ii;
#define cons(x,y) make_pair((x),(y))
#define car(x) ((x).first)
#define cdr(x) ((x).second)
#define cadr(x) (x).second.first
#define cddr(x) (x).second.second
// END CUT HERE

class BinaryCode {
 public:
  vector <string> decode(string message) {
	int N=sz(message);
    vector<int> Q(N); rep(i,N) Q[i] = message[i]-'0';
    vector<string> ans;
    FOR(p0,0,1){
      int ok = 1;
      vector<int> P(N);
      P[0] = p0;
      if (N==1) {
        // check
        if (Q[0]!=P[0]) ok=0;
      } else if (N==2) {
        // P: p0, p1
        // Q: p0+p1, p0+p1
        P[1] = Q[0] - P[0];
        // check
        if (Q[1] != Q[0]) ok=0;
      } else {
        P[1] = Q[0] - P[0];
        FOR(i,2,N-1) {
          P[i] = Q[i-1] - P[i-1] - P[i-2];
        }
        //check
        if (Q[N-1]!=P[N-1]+P[N-2]) ok=0;
      }
      
      // [01]
      rep(i,N){
        if (P[i] != 0 && P[i] != 1) { ok=0; break; }
      }
      
      if (ok) {
        char buf[256]; rep(i,N) buf[i]='0'+P[i]; buf[N] = 0;
        ans.pb(buf);
      } else {
        ans.pb("NONE");
      }
    }
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
	string message = "123210122"; 
	string RetVal_[] = { "011100011",  "NONE" };
	  vector <string> RetVal(RetVal_, RetVal_+sizeof(RetVal_)/sizeof(*RetVal_)); 
	return verify_case(RetVal, BinaryCode().decode(message)); }
int Test_(Case_<1>) {
	timer_clear();
	string message = "11"; 
	string RetVal_[] = { "01",  "10" };
	  vector <string> RetVal(RetVal_, RetVal_+sizeof(RetVal_)/sizeof(*RetVal_)); 
	return verify_case(RetVal, BinaryCode().decode(message)); }
int Test_(Case_<2>) {
	timer_clear();
	string message = "22111"; 
	string RetVal_[] = { "NONE",  "11001" };
	  vector <string> RetVal(RetVal_, RetVal_+sizeof(RetVal_)/sizeof(*RetVal_)); 
	return verify_case(RetVal, BinaryCode().decode(message)); }
int Test_(Case_<3>) {
	timer_clear();
	string message = "123210120"; 
	string RetVal_[] = { "NONE",  "NONE" };
	  vector <string> RetVal(RetVal_, RetVal_+sizeof(RetVal_)/sizeof(*RetVal_)); 
	return verify_case(RetVal, BinaryCode().decode(message)); }
int Test_(Case_<4>) {
	timer_clear();
	string message = "3"; 
	string RetVal_[] = { "NONE",  "NONE" };
	  vector <string> RetVal(RetVal_, RetVal_+sizeof(RetVal_)/sizeof(*RetVal_)); 
	return verify_case(RetVal, BinaryCode().decode(message)); }
int Test_(Case_<5>) {
	timer_clear();
	string message = "12221112222221112221111111112221111"; 
	string RetVal_[] = { "01101001101101001101001001001101001",  "10110010110110010110010010010110010" };
	  vector <string> RetVal(RetVal_, RetVal_+sizeof(RetVal_)/sizeof(*RetVal_)); 
	return verify_case(RetVal, BinaryCode().decode(message)); }
int Test_(Case_<6>) {
	timer_clear();
	string message = "0"; 
	string RetVal_[] = { "0",  "NONE" };
	  vector <string> RetVal(RetVal_, RetVal_+sizeof(RetVal_)/sizeof(*RetVal_)); 
	return verify_case(RetVal, BinaryCode().decode(message)); }
int Test_(Case_<7>) {
	timer_clear();
	string message = "1"; 
	string RetVal_[] = { "NONE", "1" };
	  vector <string> RetVal(RetVal_, RetVal_+sizeof(RetVal_)/sizeof(*RetVal_)); 
	return verify_case(RetVal, BinaryCode().decode(message)); }
int Test_(Case_<8>) {
	timer_clear();
	string message = "00"; 
	string RetVal_[] = { "00", "NONE" };
	  vector <string> RetVal(RetVal_, RetVal_+sizeof(RetVal_)/sizeof(*RetVal_)); 
	return verify_case(RetVal, BinaryCode().decode(message)); }

template<int N> void Run_() { cerr << "Test Case #" << N << "..." << flush; Test_(Case_<N>()); Run_<sizeof(Test_(Case_<N+1>()))==1 ? -1 : N+1>(); }
template<>      void Run_<-1>() {}
int main() { Run_<0>(); }
// END CUT HERE


// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// Let's say you have a binary string such as the following:

011100011

One way to encrypt this string is to add to each digit the sum of its adjacent digits.  For example, the above string would become:

123210122

In particular, if P is the original string, and Q is the encrypted string, then Q[i] = P[i-1] + P[i] + P[i+1] for all digit positions i.  Characters off the left and right edges of the string are treated as zeroes.

An encrypted string given to you in this format can be decoded as follows (using 123210122 as an example):

Assume P[0] = 0.
Because Q[0] = P[0] + P[1] = 0 + P[1] = 1, we know that P[1] = 1.
Because Q[1] = P[0] + P[1] + P[2] = 0 + 1 + P[2] = 2, we know that P[2] = 1.
Because Q[2] = P[1] + P[2] + P[3] = 1 + 1 + P[3] = 3, we know that P[3] = 1.
Repeating these steps gives us P[4] = 0, P[5] = 0, P[6] = 0, P[7] = 1, and P[8] = 1.
We check our work by noting that Q[8] = P[7] + P[8] = 1 + 1 = 2.  Since this equation works out, we are finished, and we have recovered one possible original string.

Now we repeat the process, assuming the opposite about P[0]:

Assume P[0] = 1.
Because Q[0] = P[0] + P[1] = 1 + P[1] = 0, we know that P[1] = 0.
Because Q[1] = P[0] + P[1] + P[2] = 1 + 0 + P[2] = 2, we know that P[2] = 1.
Now note that Q[2] = P[1] + P[2] + P[3] = 0 + 1 + P[3] = 3, which leads us to the conclusion that P[3] = 2.  However, this violates the fact that each character in the original string must be '0' or '1'.  Therefore, there exists no such original string P where the first digit is '1'.

Note that this algorithm produces at most two decodings for any given encrypted string.  There can never be more than one possible way to decode a string once the first binary digit is set.

Given a string message, containing the encrypted string, return a vector <string> with exactly two elements.  The first element should contain the decrypted string assuming the first character is '0'; the second element should assume the first character is '1'.  If one of the tests fails, return the string "NONE" in its place.  For the above example, you should return {"011100011", "NONE"}.

DEFINITION
Class:BinaryCode
Method:decode
Parameters:string
Returns:vector <string>
Method signature:vector <string> decode(string message)


CONSTRAINTS
-message will contain between 1 and 50 characters, inclusive.
-Each character in message will be either '0', '1', '2', or '3'.


EXAMPLES

0)
"123210122"

Returns: { "011100011",  "NONE" }

The example from above.

1)
"11"

Returns: { "01",  "10" }

We know that one of the digits must be '1', and the other must be '0'.  We return both cases.

2)
"22111"

Returns: { "NONE",  "11001" }

Since the first digit of the encrypted string is '2', the first two digits of the original string must be '1'.  Our test fails when we try to assume that P[0] = 0.

3)
"123210120"

Returns: { "NONE",  "NONE" }

This is the same as the first example, but the rightmost digit has been changed to something inconsistent with the rest of the original string.  No solutions are possible.

4)
"3"

Returns: { "NONE",  "NONE" }

5)
"12221112222221112221111111112221111"

Returns: { "01101001101101001101001001001101001",  "10110010110110010110010010010110010" }

*/
// END CUT HERE
