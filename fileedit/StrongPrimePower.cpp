// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 

NOTE: This problem statement contains superscripts that may not display properly if viewed outside of the applet.



A number which can be represented as pq, where p is a prime number and q is an integer greater than 0, is called a prime power. If q is larger than 1, we call the number a strong prime power. You are given an integer n.  If n is a strong prime power, return an vector <int> containing exactly two elements.  The first element is p and the second element is q.  If n is not a strong prime power, return an empty vector <int>.


DEFINITION
Class:StrongPrimePower
Method:baseAndExponent
Parameters:string
Returns:vector <int>
Method signature:vector <int> baseAndExponent(string n)


CONSTRAINTS
-n will contain digits ('0' - '9') only.
-n will represent an integer between 2 and 10^18, inclusive.
-n will have no leading zeros.


EXAMPLES

0)
"27"

Returns: {3, 3 }

27 = 33. This is a strong prime power.

1)
"10"

Returns: { }

10 = 2 * 5. This is not a strong prime power.

2)
"7"

Returns: { }

A prime number is not a strong prime power.

3)
"1296"

Returns: { }



4)
"576460752303423488"

Returns: {2, 59 }



5)
"999999874000003969"

Returns: {999999937, 2 }



*/
// END CUT HERE

#line 75 "StrongPrimePower.cpp"
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
//#include "math.h"
using namespace std;

#define sz(a)  int((a).size())
#define pb  push_back
#define all(c)  (c).begin(),(c).end()
#define tr(c,i)  for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); i++)
#define rep(var,n)  for(int var=0;var<(n);var++)

template <typename T> T expt(T x, int n) // x^n
{
  T y=1; for(int i=0;i<n;i++) y*=x; return y;
}

long long random(long long n)
{
  return (long long)rand() % n;
}
long long check_nontrivial_sqrt_1(long long m, long long a)
{
  long long r = (a * a) % m;
  return (1LL < a && a < m-1 && r == 1)? 0LL : r;
}
long long expmod(long long base, long long exp, long long m)
{
  if (exp == 0)
        return 1LL;
  else if (!(exp & 1))
        return check_nontrivial_sqrt_1(m,expmod(base,exp/2,m));
  else
        return (base*expmod(base,exp-1,m)) % m;
}
bool miller_rabin_test(long long n)
{
  return expmod((1LL+random(n-1)),n-1,n) == 1LL;
}
bool fast_prime(long long n, int times)
{
  if (n == 1) return false;
  if (n == 2) return true;
  else if (!(n & 1)) return false;
  
  for (int i=times; i>0; i--)
        if (!miller_rabin_test(n)) return false;
  return true;
}

class StrongPrimePower {
public:
  vector<int> baseAndExponent(string n) {
    long long n_ = 0; // 2-10^18=1000^6<2^60
    for(int i=0;i<n.length();i++) {n_*=10; n_+=n[i]-'0';}

    for (int q=59;q>=2;q--) {
      double q_ = 1.0 / q;
      double d_ = pow(n_,q_); long long p = (long long)(d_ + 0.0001);
      if (p == 0) continue;
      if (!fast_prime(p,3)) continue;
      if (expt(p,q)==n_) {
        vector<int> ans(2);
        ans[0]=p; ans[1]=q; return ans;
      }
    }
    vector<int> ans; return ans;
  }
};

// BEGIN CUT HERE
#include <time.h>
clock_t start_time;
void timer_clear() { start_time = clock(); }
string timer() { clock_t end_time = clock(); double interval = (double)(end_time - start_time)/CLOCKS_PER_SEC; ostringstream os; os << " (" << interval*1000 << " msec)"; return os.str(); }

template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
int verify_case(const vector <int> &Expected, const vector <int> &Received) { if (Expected == Received) cerr << "PASSED" << timer() << endl; else { cerr << "FAILED" << timer() << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } return 0;}

template<int N> struct Case_ {};
char Test_(...);
int Test_(Case_<0>) {
    timer_clear();
    string n = "27"; 
    int RetVal_[] = {3, 3 };
      vector <int> RetVal(RetVal_, RetVal_+sizeof(RetVal_)/sizeof(*RetVal_)); 
    return verify_case(RetVal, StrongPrimePower().baseAndExponent(n)); }
int Test_(Case_<1>) {
    timer_clear();
    string n = "10"; 
    vector <int> RetVal; 
    return verify_case(RetVal, StrongPrimePower().baseAndExponent(n)); }
int Test_(Case_<2>) {
    timer_clear();
    string n = "7"; 
    vector <int> RetVal; 
    return verify_case(RetVal, StrongPrimePower().baseAndExponent(n)); }
int Test_(Case_<3>) {
    timer_clear();
    string n = "1296"; 
    vector <int> RetVal; 
    return verify_case(RetVal, StrongPrimePower().baseAndExponent(n)); }
int Test_(Case_<4>) {
    timer_clear();
    string n = "576460752303423488"; 
    int RetVal_[] = {2, 59 };
      vector <int> RetVal(RetVal_, RetVal_+sizeof(RetVal_)/sizeof(*RetVal_)); 
    return verify_case(RetVal, StrongPrimePower().baseAndExponent(n)); }
int Test_(Case_<5>) {
    timer_clear();
    string n = "999999874000003969"; 
    int RetVal_[] = {999999937, 2 };
      vector <int> RetVal(RetVal_, RetVal_+sizeof(RetVal_)/sizeof(*RetVal_)); 
    return verify_case(RetVal, StrongPrimePower().baseAndExponent(n)); }

template<int N> void Run_() { cerr << "Test Case #" << N << "..." << flush; Test_(Case_<N>()); Run_<sizeof(Test_(Case_<N+1>()))==1 ? -1 : N+1>(); }
template<>      void Run_<-1>() {}
int main() { Run_<0>(); }
// END CUT HERE

