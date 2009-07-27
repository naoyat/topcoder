#line 2 "TheLockDivOne.cpp"
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

//
// 二進数
//
string binstr(long long x, int len_min=1)
{
  char buf[65], *p = buf+64;
  *p = 0;

  while (x > 0 || len_min > 0) {
    *(--p) = '0' + (x & 1);
    x >>= 1;
    len_min--;
  }
  string s(p);
  return s;
}

class TheLockDivOne {
 public:
  string password(int n, long long k) {
	long long m=1LL<<n;
    if (k==m) return binstr(m-1,n);
    
    printf("password(n=%d,k=%lld=",n,k); cout << binstr(k,n) << endl;
    vector<bool> foot(32768,false);
    
    ll cur=0LL, lt=0LL;
    cout << 1 << ") " << binstr(cur,n) << endl;
    for(ll i=0LL;i<k-1;i++) {
      //for(ll i=0LL;i<m;i++) {
      ll nxt=m;
      foot[cur]=true;
      for(ll ch=1LL;ch<m;ch++) {
        ll e = cur & ch;
        if (e==ch){ // 11 -> 00
          ll ne=cur-ch;
          if (ne<nxt && !foot[ne]) nxt=ne;
        }else if(e==0LL) { // 00 -> 11
          ll ne=cur+ch;
          if (ne<nxt && !foot[ne]) nxt=ne;
        }
        //if (__builtin_popcount(
      }
      if (nxt==m) {
        cout << "---" << endl;
        break;
      }
      //      cout << binstr(cur,n) << " >> " << binstr(nxt,n) << endl;
      cout << binstr(cur,n) << " >> " << binstr(nxt,n) << endl;
      cur = nxt;

      cout << i+2 << ") " << binstr(cur,n) << endl;
      if (lt<cur)lt=cur;
    }
    cout << " ==> " << binstr(lt,n) << endl;
    return binstr(lt,n);
  }
};

// BEGIN CUT HERE
#include <time.h>
clock_t start_time;
void timer_clear() { start_time = clock(); }
string timer() { clock_t end_time = clock(); double interval = (double)(end_time - start_time)/CLOCKS_PER_SEC; ostringstream os; os << " (" << interval*1000 << " msec)"; return os.str(); }

template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
int verify_case(const string &Expected, const string &Received) { if (Expected == Received) cerr << "PASSED" << timer() << endl; else { cerr << "FAILED" << timer() << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } return 0;}

template<int N> struct Case_ {};
char Test_(...);
int Test_(Case_<0>) {
	timer_clear();
	int n = 2; 
	long long k = 4LL; 
	string RetVal = "11"; 
	return verify_case(RetVal, TheLockDivOne().password(n, k)); }
int Test_(Case_<1>) {
	timer_clear();
	int n = 3; 
	long long k = 8LL; 
	string RetVal = "111"; 
	return verify_case(RetVal, TheLockDivOne().password(n, k)); }
int Test_(Case_<2>) {
	timer_clear();
	int n = 4; 
	long long k = 6LL; 
	string RetVal = "0110"; 
	return verify_case(RetVal, TheLockDivOne().password(n, k)); }
int Test_(Case_<3>) {
	timer_clear();
	int n = 10; 
	long long k = 1LL; 
	string RetVal = "0000000000"; 
	return verify_case(RetVal, TheLockDivOne().password(n, k)); }
int Test_(Case_<4>) {
	timer_clear();
	int n = 7; 
	long long k = 100LL; 
	string RetVal = "1111110"; 
	return verify_case(RetVal, TheLockDivOne().password(n, k)); }
int Test_(Case_<5>) {
	timer_clear();
	int n = 15; 
	long long k = 32767LL; 
	string RetVal = "1111110"; 
	return verify_case(RetVal, TheLockDivOne().password(n, k)); }

template<int N> void Run_() { cerr << "Test Case #" << N << "..." << flush; Test_(Case_<N>()); Run_<sizeof(Test_(Case_<N+1>()))==1 ? -1 : N+1>(); }
template<>      void Run_<-1>() {}
int main() { Run_<0>(); }
// END CUT HERE


// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
John is obsessed with security.
Recently he bought a new electronic lock.
It is protected by a password containing n digits, where each digit is either zero or one.
John decides to change the password every day.
On the first day, the password is all zeroes.
On each day that follows, he will select one or more digits that all have the same value and change their values (so zeroes become ones, and ones become zeroes).
He must select the digits according to the following rules:

During the first 2^n days, he must never use the same password twice.
Each new password must come as early as possible alphabetically while not violating rule 1.




For example, if n is 2, the password on the first day is "00".
The next day, he can change one or both 0's to get "01", "10" or "11".
Of these possibilities, "01" comes earliest alphabetically.
The next day, he can change either the 0 or the 1 to get "11" or "00".
He can't choose "00" because it was already used, so he chooses "11".
The next day, he can change one or both 1's to get "10", "01" or "11".
He has already used "01" and "11", so he must choose "10".



Given ints n and k, return the password that comes latest alphabetically during the first k days.



DEFINITION
Class:TheLockDivOne
Method:password
Parameters:int, long long
Returns:string
Method signature:string password(int n, long long k)


NOTES
-If A and B are two strings of the same length, then A comes earlier alphabetically than B if it contains a smaller character at the first position where the strings differ.


CONSTRAINTS
-n will be between 1 and 50, inclusive.
-k will be between 1 and 2^n, inclusive.


EXAMPLES

0)
2
4

Returns: "11"

This is the example from the statement.
The password sequence is the following - "00", "01", "11", "10".

1)
3
8

Returns: "111"

"000", "001", "011", "010", "110", "100", "101", "111".

2)
4
6

Returns: "0110"



3)
10
1

Returns: "0000000000"



4)
7
100

Returns: "1111110"



*/
// END CUT HERE
