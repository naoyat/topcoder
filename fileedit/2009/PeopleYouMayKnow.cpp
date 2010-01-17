#line 2 "PeopleYouMayKnow.cpp"
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

class PeopleYouMayKnow {
 public:
  int maximalScore(vector<string> friends, int person1, int person2) {
    int N=sz(friends);
    // 1-fr
    //set<pair<int,ll> > v; v.insert(person1);
    set<pair<int,ll> > f1,f2,f3;
    //ll m1=1LL<<person1;
	rep(i,N){
      ll m0=1LL<<i;
      if (i==person1)continue;
      if (friends[person1][i]=='N')continue;
      f1.insert(make_pair(i,m0));// v.insert(i);
    }
    cout << "1-friends: " << f1 << endl;
    // A, 1 . p1

    tr(f1,it){
      int i=it->first;
      ll m0=it->second;
      rep(j,N){
        if (j==i)continue;
        ll m1=1LL<<j;
        //if (found(v,i))continue;
        if(friends[i][j]=='N')continue;
        //if((m0&m1)==m1)continue;
        f2.insert(make_pair(j,m0|m1));
      }
    }
    cout << "2-friends: " << f2 << endl;
    // B, 2 . [A p1]

    tr(f2,it){
      int i=it->first;
      ll m1=it->second;
      rep(j,N){
        if (j==i)continue;
        ll m2=1LL<<j;
        //if (found(v,i))continue;
        if(friends[i][j]=='N')continue;
        if((m1&m2)==m2)continue;
        f3.insert(make_pair(j,m1|m2));
      }
    }
    cout << "3-friends: " << f3 << endl;
    return -1;
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
	string friends_[] = {"NN"
,"NN"};
	  vector <string> friends(friends_, friends_+sizeof(friends_)/sizeof(*friends_)); 
	int person1 = 0; 
	int person2 = 1; 
	int RetVal = 0; 
	return verify_case(RetVal, PeopleYouMayKnow().maximalScore(friends, person1, person2)); }
int Test_(Case_<1>) {
	timer_clear();
	string friends_[] = {"NYNN"
,"YNYN"
,"NYNY"
,"NNYN"};
	  vector <string> friends(friends_, friends_+sizeof(friends_)/sizeof(*friends_)); 
	int person1 = 0; 
	int person2 = 3; 
	int RetVal = 1; 
	return verify_case(RetVal, PeopleYouMayKnow().maximalScore(friends, person1, person2)); }
int Test_(Case_<2>) {
	timer_clear();
	string friends_[] = {"NYNYYYN"
,"YNYNNYY"
,"NYNNNNY"
,"YNNNNNN"
,"YNNNNYN"
,"YYNNYNY"
,"NYYNNYN"};
	  vector <string> friends(friends_, friends_+sizeof(friends_)/sizeof(*friends_)); 
	int person1 = 2; 
	int person2 = 3; 
	int RetVal = 1; 
	return verify_case(RetVal, PeopleYouMayKnow().maximalScore(friends, person1, person2)); }
int Test_(Case_<3>) {
	timer_clear();
	string friends_[] = {"NYYYYNNNN"
,"YNNNNYYYN"
,"YNNNNNNYN"
,"YNNNNNNYN"
,"YNNNNNNNY"
,"NYNNNNNNY"
,"NYNNNNNNY"
,"NYYYNNNNY"
,"NNNNYYYYN"};
	  vector <string> friends(friends_, friends_+sizeof(friends_)/sizeof(*friends_)); 
	int person1 = 8; 
	int person2 = 0; 
	int RetVal = 3; 
	return verify_case(RetVal, PeopleYouMayKnow().maximalScore(friends, person1, person2)); }
int Test_(Case_<4>) {
	timer_clear();
	string friends_[] = {
      "NYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY",
      "YNYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY",
      "YYNYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY",
      "YYYNYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY",
      "YYYYNYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY",
      "YYYYYNYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY",
      "YYYYYYNYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY",
      "YYYYYYYNYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY",
      "YYYYYYYYNYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY",
      "YYYYYYYYYNYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY",
      "YYYYYYYYYYNYYYYYYYYYYYYYYYYYYYYYYYYYYYYY",
      "YYYYYYYYYYYNYYYYYYYYYYYYYYYYYYYYYYYYYYYY",
      "YYYYYYYYYYYYNYYYYYYYYYYYYYYYYYYYYYYYYYYY",
      "YYYYYYYYYYYYYNYYYYYYYYYYYYYYYYYYYYYYYYYY",
      "YYYYYYYYYYYYYYNYYYYYYYYYYYYYYYYYYYYYYYYY",
      "YYYYYYYYYYYYYYYNYYYYYYYYYYYYYYYYYYYYYYYY",
      "YYYYYYYYYYYYYYYYNYYYYYYYYYYYYYYYYYYYYYYY",
      "YYYYYYYYYYYYYYYYYNYYYYYYYYYYYYYYYYYYYYYY",
      "YYYYYYYYYYYYYYYYYYNYYYYYYYYYYYYYYYYYYYYY",
      "YYYYYYYYYYYYYYYYYYYNYYYYYYYYYYYYYYYYYYYY",
      "YYYYYYYYYYYYYYYYYYYYNYYYYYYYYYYYYYYYYYYY",
      "YYYYYYYYYYYYYYYYYYYYYNYYYYYYYYYYYYYYYYYY",
      "YYYYYYYYYYYYYYYYYYYYYYNYYYYYYYYYYYYYYYYY",
      "YYYYYYYYYYYYYYYYYYYYYYYNYYYYYYYYYYYYYYYY",
      "YYYYYYYYYYYYYYYYYYYYYYYYNYYYYYYYYYYYYYYY",
      "YYYYYYYYYYYYYYYYYYYYYYYYYNYYYYYYYYYYYYYY",
      "YYYYYYYYYYYYYYYYYYYYYYYYYYNYYYYYYYYYYYYY",
      "YYYYYYYYYYYYYYYYYYYYYYYYYYYNYYYYYYYYYYYY",
      "YYYYYYYYYYYYYYYYYYYYYYYYYYYYNYYYYYYYYYYY",
      "YYYYYYYYYYYYYYYYYYYYYYYYYYYYYNYYYYYYYYYY",
      "YYYYYYYYYYYYYYYYYYYYYYYYYYYYYYNYYYYYYYYY",
      "YYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYNYYYYYYYY",
      "YYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYNYYYYYYY",
      "YYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYNYYYYYY",
      "YYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYNYYYYY",
      "YYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYNYYYY",
      "YYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYNYYY",
      "YYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYNYY",
      "YYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYNY",
      "YYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYN"};
	  vector <string> friends(friends_, friends_+sizeof(friends_)/sizeof(*friends_)); 
	int person1 = 8; 
	int person2 = 0; 
	int RetVal = 37; 
	return verify_case(RetVal, PeopleYouMayKnow().maximalScore(friends, person1, person2)); }

template<int N> void Run_() { cerr << "Test Case #" << N << "..." << flush; Test_(Case_<N>()); Run_<sizeof(Test_(Case_<N+1>()))==1 ? -1 : N+1>(); }
template<>      void Run_<-1>() {}
int main() { Run_<0>(); }
// END CUT HERE


// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// Tim wants to improve "People You May Know" feature of Facebook. This is a feature that attempts to automatically connect people who may know each other in reality, but haven't yet added each other as friends on Facebook.


Friendship on Facebook is symmetric, meaning that if B is a friend of A, then A is also a friend of B.  However, it is not necessarily transitive, so if A and B are friends and B and C are friends, then A and C are not necessarily friends.

Tim has defined the term "n-friends" as follows.  If two people are friends, they are called 1-friends.  For n >= 1, two people A and B are called (n+1)-friends if A and B are n-friends, or if there exists a person C such that A and C are n-friends and C and B are friends.

To determine how likely it is that two people know each other, Tim has introduced the concept of a "Distance Score".  If two people A and B are not friends, then their Distance Score is the fewest number of people (other than A and B themselves) who must be removed from the network in order for A and B to not be 3-friends.  The higher the Distance Score, the more likely it is that A and B know each other.


You are given vector <string> friends containing exactly N elements, where N is the number of people in the network. People are numbered from 0 to N-1.  The j-th character of the i-th element of friends is 'Y' if i and j are friends, and 'N' otherwise.  Return the Distance Score for person1 and person2.


DEFINITION
Class:PeopleYouMayKnow
Method:maximalScore
Parameters:vector <string>, int, int
Returns:int
Method signature:int maximalScore(vector <string> friends, int person1, int person2)


CONSTRAINTS
-friends will contain N elements, where N is between 2 and 40, inclusive.
-Each element of friends will contain exactly N characters. 
-Each character in friends will be 'Y' or 'N'. 
-For all i and j, friends[i][j] will be equal to friends[j][i]. 
-For all i, friends[i][i] will be equal to 'N'. 
-person1 and person2 will each be between 0 and N-1, inclusive. 
-person1 and person2 will not be equal. 
-friends[person1][person2] will be equal to 'N'.


EXAMPLES

0)
{"NN"
,"NN"}
0
1

Returns: 0

You don't need to remove any people.

1)
{"NYNN"
,"YNYN"
,"NYNY"
,"NNYN"}
0
3

Returns: 1

You need to remove person 1 or person 2.

2)
{"NYNYYYN"
,"YNYNNYY"
,"NYNNNNY"
,"YNNNNNN"
,"YNNNNYN"
,"YYNNYNY"
,"NYYNNYN"}
2
3

Returns: 1

You need to remove person 0 or person 1.

3)
{"NYYYYNNNN"
,"YNNNNYYYN"
,"YNNNNNNYN"
,"YNNNNNNYN"
,"YNNNNNNNY"
,"NYNNNNNNY"
,"NYNNNNNNY"
,"NYYYNNNNY"
,"NNNNYYYYN"}
8
0

Returns: 3

You need to remove person 4 (who knows both 0 and 8), person 1 (friend of 0) and person 7 (friend of 8).

*/
// END CUT HERE
