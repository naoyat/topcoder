#line 2 "Underprimes.cpp"
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
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
#define sz(a)  int((a).size())
#define pb  push_back
#define all(c)  (c).begin(),(c).end()
#define tr(c,i)  for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); i++)
#define rep(var,n)  for(int var=0;var<(n);var++)

int primes[100000];

class Underprimes {
 public:
  int e_sieve(int till) {
    vector<bool> sieve(till+1,true);
    int primes_cnt = 0;
    
    sieve[2] = true;
    primes[primes_cnt++] = 2;
    for (int prime=3;;) {
      primes[primes_cnt++] = prime;
      for (int i=prime*3;i<=till;i+=(prime*2)) sieve[i] = false;
      
      int next_prime = -1;
      for (int j=prime+2; j<=till; j+=2) {
          if (sieve[j]) { next_prime = j; break; }
        }

        if (next_prime == -1) break;
        prime = next_prime;
  }

  return primes_cnt;
}

  int howMany(int A, int B) {
    vector<bool> pz(100001,false);
    vector<int> cnt(100001,0);
    int pc = e_sieve(100000);
    rep(i,pc) {
      int pr=primes[i];
      pz[pr]=true; cnt[pr]=1;
    }            
    rep(t,14) {
      rep(i,100001){
        int c=cnt[i];
        if(c){
          rep(j,pc){
            int k=primes[j]*i;
            if(k>B) break;
            if(!cnt[k]) cnt[k]=c+1;
          }
        }
      }
    }
    int ans =0;
    for(int i=A;i<=B;i++) if(pz[cnt[i]])ans++;
    return ans;
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
	int A = 2; 
	int B = 10; 
	int RetVal = 5; 
	return verify_case(RetVal, Underprimes().howMany(A, B)); }
int Test_(Case_<1>) {
	timer_clear();
	int A = 100; 
	int B = 105; 
	int RetVal = 2; 
	return verify_case(RetVal, Underprimes().howMany(A, B)); }
int Test_(Case_<2>) {
	timer_clear();
	int A = 17; 
	int B = 17; 
	int RetVal = 0; 
	return verify_case(RetVal, Underprimes().howMany(A, B)); }
int Test_(Case_<3>) {
	timer_clear();
	int A = 123; 
	int B = 456; 
	int RetVal = 217; 
	return verify_case(RetVal, Underprimes().howMany(A, B)); }
int Test_(Case_<4>) {
	timer_clear();
	int A = 2; 
	int B = 100000; 
	int RetVal = 63255; 
	return verify_case(RetVal, Underprimes().howMany(A, B)); }
int Test_(Case_<5>) {
	timer_clear();
	int A = 2; 
	int B = 2;
	int RetVal = 0;
	return verify_case(RetVal, Underprimes().howMany(A, B)); }
int Test_(Case_<6>) {
	timer_clear();
	int A = 100000; 
	int B = 100000; 
	int RetVal = 0; 
	return verify_case(RetVal, Underprimes().howMany(A, B)); }

template<int N> void Run_() { cerr << "Test Case #" << N << "..." << flush; Test_(Case_<N>()); Run_<sizeof(Test_(Case_<N+1>()))==1 ? -1 : N+1>(); }
template<>      void Run_<-1>() {}
int main() { Run_<0>(); }
// END CUT HERE


// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// The prime factorization of a number X is the list of prime numbers that multiply together to form X.  For example, the prime factorization of 12 is 2 * 2 * 3.  Note that 1 is not a prime number.
An underprime is a number whose prime factorization contains a prime number of elements.  For example, 12 is an underprime because its prime factorization contains 3 elements, and 3 is a prime number.  Given ints A and B, return the number of underprimes between A and B, inclusive.

DEFINITION
Class:Underprimes
Method:howMany
Parameters:int, int
Returns:int
Method signature:int howMany(int A, int B)


NOTES
-A positive integer number is called prime if it has exactly two divisors - 1 and itself. For example, 2, 3, 5 and 7 are prime numbers, and 4, 6, 8 and 9 are not prime. By convention, 1 is not considered to be a prime number.
-All prime factorizations of the same integer always contain the same prime numbers and can only differ by the order of primes within them.


CONSTRAINTS
-A will be between 2 and 100000, inclusive.
-B will be between A and 100000, inclusive.


EXAMPLES

0)
2
10

Returns: 5

The underprimes in this interval are: 4, 6, 8, 9, 10.

1)
100
105

Returns: 2

The underprimes in this interval are 102 = 2 * 3 * 17 and 105 = 3 * 5 * 7.

2)
17
17

Returns: 0

17 is a prime number, so its prime factorization contains one element. 1 is not a prime, so 17 is not an underprime.

3)
123
456

Returns: 217



*/
// END CUT HERE
