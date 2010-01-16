#line 2 "FriendScore.cpp"
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
#define sz(a)  int((a).size())
#define pb  push_back
#define all(c)  (c).begin(),(c).end()
#define tr(c,i)  for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); i++)
#define rep(var,n)  for(int var=0;var<(n);var++)

class FriendScore {
 public:
  int highestScore(vector<string> fz) {
    int n=sz(fz),max=0;
    rep(i,n){
      int count=0;
      vector<int> people(n,0);
      rep(j,n){
        if(fz[i][j]=='Y') {
          people[j]=1;
          rep(k,n){
            if(fz[j][k]=='Y') people[k]=1;
          }
        }
      }
      int cnt=0;
      rep(j,n){
        if(people[j]==1)cnt++;
      }
      cnt--;
      if(cnt>max) max=cnt;
    }
    return max;
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
	string friends_[] = {"NNN",
 "NNN",
 "NNN"};
	  vector <string> friends(friends_, friends_+sizeof(friends_)/sizeof(*friends_)); 
	int RetVal = 0; 
	return verify_case(RetVal, FriendScore().highestScore(friends)); }
int Test_(Case_<1>) {
	timer_clear();
	string friends_[] = {"NYY",
 "YNY",
 "YYN"};
	  vector <string> friends(friends_, friends_+sizeof(friends_)/sizeof(*friends_)); 
	int RetVal = 2; 
	return verify_case(RetVal, FriendScore().highestScore(friends)); }
int Test_(Case_<2>) {
	timer_clear();
	string friends_[] = {"NYNNN",
 "YNYNN", 
 "NYNYN", 
 "NNYNY", 
 "NNNYN"};
	  vector <string> friends(friends_, friends_+sizeof(friends_)/sizeof(*friends_)); 
	int RetVal = 4; 
	return verify_case(RetVal, FriendScore().highestScore(friends)); }
int Test_(Case_<3>) {
	timer_clear();
	string friends_[] = {"NNNNYNNNNN",
 "NNNNYNYYNN",
 "NNNYYYNNNN",
 "NNYNNNNNNN",
 "YYYNNNNNNY",
 "NNYNNNNNYN",
 "NYNNNNNYNN",
 "NYNNNNYNNN",
 "NNNNNYNNNN",
 "NNNNYNNNNN"};
	  vector <string> friends(friends_, friends_+sizeof(friends_)/sizeof(*friends_)); 
	int RetVal = 8; 
	return verify_case(RetVal, FriendScore().highestScore(friends)); }
int Test_(Case_<4>) {
	timer_clear();
	string friends_[] = {"NNNNNNNNNNNNNNY",
 "NNNNNNNNNNNNNNN",
 "NNNNNNNYNNNNNNN",
 "NNNNNNNYNNNNNNY",
 "NNNNNNNNNNNNNNY",
 "NNNNNNNNYNNNNNN",
 "NNNNNNNNNNNNNNN",
 "NNYYNNNNNNNNNNN",
 "NNNNNYNNNNNYNNN",
 "NNNNNNNNNNNNNNY",
 "NNNNNNNNNNNNNNN",
 "NNNNNNNNYNNNNNN",
 "NNNNNNNNNNNNNNN",
 "NNNNNNNNNNNNNNN",
 "YNNYYNNNNYNNNNN"};
	  vector <string> friends(friends_, friends_+sizeof(friends_)/sizeof(*friends_)); 
	int RetVal = 6; 
	return verify_case(RetVal, FriendScore().highestScore(friends)); }

int Test_(Case_<5>) {
	timer_clear();
	string friends_[] = {"N"};
    vector <string> friends(friends_, friends_+sizeof(friends_)/sizeof(*friends_)); 
    int RetVal = 0; 
	return verify_case(RetVal, FriendScore().highestScore(friends)); }

template<int N> void Run_() { cerr << "Test Case #" << N << "..." << flush; Test_(Case_<N>()); Run_<sizeof(Test_(Case_<N+1>()))==1 ? -1 : N+1>(); }
template<>      void Run_<-1>() {}
int main() { Run_<0>(); }
// END CUT HERE


// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// You want to determine the most popular person in a social network.  To do this, you will count the number of "2-friends" that each person has.  Person A is called a 2-friend of another person B if they are friends with each other or if there exists some person C who is a friend of both A and B.  The most popular person is the person with the highest number of 2-friends.  (There might be more than one if multiple people all have the maximal number of 2-friends.)

You are given a vector <string> friends, where the j-th character of the i-th element is 'Y' if person i and person j are friends, and 'N' otherwise.  Return the number of 2-friends of the most popular person in this social network.

DEFINITION
Class:FriendScore
Method:highestScore
Parameters:vector <string>
Returns:int
Method signature:int highestScore(vector <string> friends)


CONSTRAINTS
-friends will contain between 1 and 50 elements, inclusive. 
-Each element of friends will contain exactly N characters 'Y' or 'N', where N is the number of elements in friends. 
-For each i and j, friends[i][j] will be equal to friends[j][i]. 
-For each i, friends[i][i] will be equal to 'N'. 


EXAMPLES

0)
{"NNN",
 "NNN",
 "NNN"}

Returns: 0

Here, there are 3 people and none of them are friends, so everybody has zero 2-friends.

1)
{"NYY",
 "YNY",
 "YYN"}

Returns: 2

Each person has two 2-friends.

2)
{"NYNNN",
 "YNYNN", 
 "NYNYN", 
 "NNYNY", 
 "NNNYN"}

Returns: 4

Persons 0 and 4 have two 2-friends, persons 1 and 3 have three 2-friends. Person 2 is the most popular one - four 2-friends.

3)
{"NNNNYNNNNN",
 "NNNNYNYYNN",
 "NNNYYYNNNN",
 "NNYNNNNNNN",
 "YYYNNNNNNY",
 "NNYNNNNNYN",
 "NYNNNNNYNN",
 "NYNNNNYNNN",
 "NNNNNYNNNN",
 "NNNNYNNNNN"}

Returns: 8



4)
{"NNNNNNNNNNNNNNY",
 "NNNNNNNNNNNNNNN",
 "NNNNNNNYNNNNNNN",
 "NNNNNNNYNNNNNNY",
 "NNNNNNNNNNNNNNY",
 "NNNNNNNNYNNNNNN",
 "NNNNNNNNNNNNNNN",
 "NNYYNNNNNNNNNNN",
 "NNNNNYNNNNNYNNN",
 "NNNNNNNNNNNNNNY",
 "NNNNNNNNNNNNNNN",
 "NNNNNNNNYNNNNNN",
 "NNNNNNNNNNNNNNN",
 "NNNNNNNNNNNNNNN",
 "YNNYYNNNNYNNNNN"}

Returns: 6



*/
// END CUT HERE
