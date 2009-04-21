#line 2 "MismatchedStrings.cpp"
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

class MismatchedStrings {
 public:
  string getString(int N, long long K) {
	/*
      0011
      nCh, n<=50  ;126410606437752 = 46.845
      "",
      01,
      0011 / 01 01,
      000111 / 01 0011, 0011 01 / 01 01 01
      // <1> 6 / <2> 2+4, 4+2 / 
      00001111 / 01 000111, 0011 0011, 000111 01 / 01 01 0011, 01 0011 01, 0011 01 01 / 01 01 01 01
      00100111 (()(()))
      
      // <1> 8 / <2> 2+6, 4+4, 6+2 / <3> 2+2+4, 2+4+2, 4+2+2 / <4> 2+2+2+2
      // 長さL=2なら2^(L-1)
      L:c = 2:1 4:2 6:4 8:8 10:16
      L/2:   1  2   3   4   5
      L/2-1: 0  1  2  3  4
      L50: L/2-1=24, 2^24=16777216
       
      




     */
    return "";
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
	int N = 4; 
	long long K = 0LL; 
	string RetVal = "(((("; 
	return verify_case(RetVal, MismatchedStrings().getString(N, K)); }
int Test_(Case_<1>) {
	timer_clear();
	int N = 4; 
	long long K = 4LL; 
	string RetVal = "())("; 
	return verify_case(RetVal, MismatchedStrings().getString(N, K)); }
int Test_(Case_<2>) {
	timer_clear();
	int N = 6; 
	long long K = 63LL; 
	string RetVal = ""; 
	return verify_case(RetVal, MismatchedStrings().getString(N, K)); }
int Test_(Case_<3>) {
	timer_clear();
	int N = 7; 
	long long K = 13LL; 
	string RetVal = "((())()"; 
	return verify_case(RetVal, MismatchedStrings().getString(N, K)); }

template<int N> void Run_() { cerr << "Test Case #" << N << "..." << flush; Test_(Case_<N>()); Run_<sizeof(Test_(Case_<N+1>()))==1 ? -1 : N+1>(); }
template<>      void Run_<-1>() {}
int main() { Run_<0>(); }
// END CUT HERE


// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
Well-parenthesized strings are defined using the following rules:


The empty string is well-parenthesized.
If S is a well-parenthesized string, then (S) is a well-parenthesized string.
If S and T are well-parenthesized strings, then ST is a well-parenthesized string.
Every well-parenthesized string can be created using the previous rules only.



In this problem we will deal with the complement of this set of strings: The strings that consist only of the characters '(' and ')', but are not well-parenthesized. We will call these strings mismatched.



You are given an int N and a long long K. All mismatched strings of length N can be ordered lexicographically, and numbered sequentially, starting with zero. Return the string that will get the number K in this order. If there is no such string, return the empty string instead.



DEFINITION
Class:MismatchedStrings
Method:getString
Parameters:int, long long
Returns:string
Method signature:string getString(int N, long long K)


NOTES
-Given two different strings S and T of equal length, S is lexicographically smaller than T if it has a smaller character at the first position where they differ.
-The ASCII value of '(' is less than the ASCII value of ')'.


CONSTRAINTS
-N will be between 1 and 50, inclusive.
-K will be between 0 and 2^N - 1, inclusive.


EXAMPLES

0)
4
0

Returns: "(((("

For any length, the lexicographically smallest mismatched string consists of '(' characters only.

1)
4
4

Returns: "())("

There are 14 mismatched strings of length 4. The first five are 
"((((",
"((()",
"(()(",
"()((",
and
"())(".
Note that we use a 0-based index, hence K=4 corresponds to the fifth mismatched string.

2)
6
63

Returns: ""

There are less than 64 mismatched strings of length 6.

3)
7
13

Returns: "((())()"



*/
// END CUT HERE
