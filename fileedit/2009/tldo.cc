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

class TheLockDivOne {
 public:
  string exact(int n,ll k){
    if(n<=0) return "";
    string res ="";
    if (k<=0){
      while(n>0)n--,res.pb('0');
      return res;
    }
    ll num=1;
    for(int i=1;i<n;i++)num*=2;
    while(num>=k) n--,num/=2,res.pb('0');
    if (n>0) {
      res.pb('1');
      res+=exact(n-1,k-num-1==0?num:k-num-1);
    }
    return res;
  }
  
  string password(int n, long long k) {
    if (n<=0) return "";
    string res="";
    if (k<=0){
      while (n>0) n--,res.pb('0');
      return res;
    }
    ll num=1;
    for (int i=1;i<n;i++) num*=2;
    while(num>=k) n--,num/=2,res.pb('0');
    if (n>0) {
      res.pb('1');
      n--;

      string l = exact(n,num),r=password(n,k-num-1);
      res += max(l,r);
    }
    return res;
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
	int n = 50; 
	long long k = (1LL<<50)-3;
	string RetVal = "111111111111111"; 
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
