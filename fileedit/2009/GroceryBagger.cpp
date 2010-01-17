#line 2 "GroceryBagger.cpp"
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
#define all(c)  (c).begin(),(c).end()
#define tr(c,i)  for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); i++)
#define rep(var,n)  for(int var=0;var<(n);var++)
#define found(s,e)  ((s).find(e)!=(s).end())

class GroceryBagger {
 public:
  int minimumBags(int strength, vector <string> itemType) {
	map<string,int> m;
    tr(itemType,it){
      if(found(m,*it)) m[*it]++;
      else m[*it]=1;
    }
    int cnt=0;
    tr(m,it){
      cnt += (it->second + strength - 1) / strength;
    }
    return cnt;
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
	int strength = 2; 
	string itemType_[] = {"DAIRY",
 "DAIRY",
 "PRODUCE",
 "PRODUCE",
 "PRODUCE",
 "MEAT"};
	  vector <string> itemType(itemType_, itemType_+sizeof(itemType_)/sizeof(*itemType_)); 
	int RetVal = 4; 
	return verify_case(RetVal, GroceryBagger().minimumBags(strength, itemType)); }
int Test_(Case_<1>) {
	timer_clear();
	int strength = 3; 
	string itemType_[] = {"DAIRY",
 "DAIRY",
 "PRODUCE",
 "PRODUCE",
 "PRODUCE",
 "MEAT"};
	  vector <string> itemType(itemType_, itemType_+sizeof(itemType_)/sizeof(*itemType_)); 
	int RetVal = 3; 
	return verify_case(RetVal, GroceryBagger().minimumBags(strength, itemType)); }
int Test_(Case_<2>) {
	timer_clear();
	int strength = 10; 
	vector <string> itemType; 
	int RetVal = 0; 
	return verify_case(RetVal, GroceryBagger().minimumBags(strength, itemType)); }
int Test_(Case_<3>) {
	timer_clear();
	int strength = 5; 
	string itemType_[] = {"CANNED",   "CANNED",  "PRODUCE",
 "DAIRY",    "MEAT",    "BREAD",
 "HOUSEHOLD","PRODUCE", "FROZEN",
 "PRODUCE", "DAIRY"};
	  vector <string> itemType(itemType_, itemType_+sizeof(itemType_)/sizeof(*itemType_)); 
	int RetVal = 7; 
	return verify_case(RetVal, GroceryBagger().minimumBags(strength, itemType)); }
int Test_(Case_<4>) {
	timer_clear();
	int strength = 2; 
	string itemType_[] = {"CANNED",   "CANNED",  "PRODUCE",
 "DAIRY",    "MEAT",    "BREAD",
 "HOUSEHOLD","PRODUCE", "FROZEN",
 "PRODUCE", "DAIRY"};
	  vector <string> itemType(itemType_, itemType_+sizeof(itemType_)/sizeof(*itemType_)); 
	int RetVal = 8; 
	return verify_case(RetVal, GroceryBagger().minimumBags(strength, itemType)); }

template<int N> void Run_() { cerr << "Test Case #" << N << "..." << flush; Test_(Case_<N>()); Run_<sizeof(Test_(Case_<N+1>()))==1 ? -1 : N+1>(); }
template<>      void Run_<-1>() {}
int main() { Run_<0>(); }
// END CUT HERE


// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// You have just begun working as a grocery bagger at the local TopGrocer food store.  Your job is to place all of a customer's items into bags, so they can be carried from the store.  Your manager has instructed you to use as few bags as possible, to minimize the store's overall cost.  However, for the customer's convenience, you are instructed that only items of the same type can be placed in the same bag.  For instance, a produce item can be bagged with any other produce items, but not with dairy items.

You are given a vector <string> itemType indicating the type of each item that needs to be bagged.  You are also given an int strength indicating the maximum number of items that can be placed in each bag.  You are to return an int indicating the minimum number of bags required to package the customer's items.


DEFINITION
Class:GroceryBagger
Method:minimumBags
Parameters:int, vector <string>
Returns:int
Method signature:int minimumBags(int strength, vector <string> itemType)


CONSTRAINTS
-strength will be between 1 and 50, inclusive.
-itemType will contain between 0 and 50 elements, inclusive.
-Each element of itemType will contain between 1 and 50 characters, inclusive.
-Each element of itemType will contain only the characters 'A'-'Z'.


EXAMPLES

0)
2
{"DAIRY",
 "DAIRY",
 "PRODUCE",
 "PRODUCE",
 "PRODUCE",
 "MEAT"}

Returns: 4

Here, you have six items.  You could put two items in each bag, but you would have to mix item types.  The single meat item must get its own bag.  The two dairy items fit in one bag.  The three produce items will require two bags.

1)
3
{"DAIRY",
 "DAIRY",
 "PRODUCE",
 "PRODUCE",
 "PRODUCE",
 "MEAT"}

Returns: 3

Similar to above, but now we have stronger bags.  Note again, though, that if we were allowed to mix item types, we could get away with only 2 bags.  But since item types cannot be mixed, we need 3 bags.

2)
10
{}

Returns: 0

The bags are really strong, but we didn't buy anything.

3)
5
{"CANNED",   "CANNED",  "PRODUCE",
 "DAIRY",    "MEAT",    "BREAD",
 "HOUSEHOLD","PRODUCE", "FROZEN",
 "PRODUCE", "DAIRY"}

Returns: 7

Notice that a customer doesn't necessarily pay for the items in any particular order, but the bagger still has to be responsible for sorting them out.  In this case, though, one bag for each item type suffices.

4)
2
{"CANNED",   "CANNED",  "PRODUCE",
 "DAIRY",    "MEAT",    "BREAD",
 "HOUSEHOLD","PRODUCE", "FROZEN",
 "PRODUCE", "DAIRY"}

Returns: 8

As above, but our produce requires two bags now.

*/
// END CUT HERE
