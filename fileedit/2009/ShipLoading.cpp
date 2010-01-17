// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// You have to load a ship with some cargo. All the cargo is put in boxes. There are some cranes and each of them can put one box in the ship per minute. All cranes can work simultaneously. Each crane has a weight limit - it cannot move a box whose weight is greater than that limit. Return the minimal time (measured in minutes) needed to load the ship with all cargo or -1 if it is impossible.You are given a vector <int> cranes, the i-th element of which is the weight limit of the i-th crane.  You are also given a vector <string> boxes.  Concatenate the elements of boxes to get a space-separated list of the boxes' weights.


DEFINITION
Class:ShipLoading
Method:minimumTime
Parameters:vector <int>, vector <string>
Returns:int
Method signature:int minimumTime(vector <int> cranes, vector <string> boxes)


CONSTRAINTS
-cranes will contain between 1 and 50 elements, inclusive. 
-boxes will contain between 1 and 50 elements, inclusive. 
-Each element of boxes will contain between 0 and 50 characters, inclusive. 
-The concatenation of all elements of boxes will be a non-empty space-separated list of integers with no leading zeroes. It will contain no leading, trailing, or consecutive spaces. 
-Each element of cranes will be between 1 and 1,000,000, inclusive. 
-Each box weight will be between 1 and 1,000,000, inclusive. 


EXAMPLES

0)
{6,8,9}
{"2 5 2 4 7"}

Returns: 2

Everything can be done in 2 minutes.

1)
{19,20}
{"14 12 16 19 16 1 5"}

Returns: 4

Only two cranes, but each of them can move any of the boxes.

2)
{23,32,25,28}
{"5 27 10 16 24 20 2 32 18 7"}

Returns: 3

3)
{11,17,5,2,20,7,5,5,20,7}
{"18 18 15 15 17"}

Returns: 2

4)
{56,114,979,120,120,87,480}
{"221 882 504 358 642 674 212 679 203 279 632 799 79","6 502 275 823 372 594 482 343"}

Returns: 12

Note that you should not add spaces between elements of boxes during their concatenation.

*/
// END CUT HERE

#line 66 "ShipLoading.cpp"
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
using namespace std;

#define sz(a)  int((a).size())
#define pb  push_back
#define all(c)  (c).begin(),(c).end()
#define rall(c)  (c).rbegin(),(c).rend()
#define tr(c,i)  for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); i++)

vector<string> split(string str, int delim=' ')
{
  vector<string> result;

  const char *s = str.c_str();
  if (delim == ' ') {
    for (const char *p=s; *p; p++) {
      if (*p == delim)
        s++;
      else
        break;
    }
    if (!*s) return result;

    for (const char *p=s; *p; p++) {
      if (*p == delim) {
        if (s < p) {
          string a(s,p-s);
          result.push_back(a);
        }
        s = p + 1;
      }
    }
    if (*s) result.push_back(s);
  } else {
    for (const char *p=s; *p; p++) {
      if (*p == delim) {
        string a(s,p-s);
        result.push_back(a);
        s = p + 1;
        if (*s == '\0') result.push_back("");
      }
    }
    if (*s) result.push_back(s);
  }

  return result;
}

vector<int> map_atoi(vector<string> nums)
{
  vector<int> vals(nums.size());
  for (int i=nums.size()-1; i>=0; i--) vals[i] = atoi(nums[i].c_str());
  return vals;
}

class ShipLoading {
public:
  int minimumTime(vector<int> cranes, vector<string> boxes) {
	int N = cranes.size();// 各1-50要素
	sort(all(cranes));
// BEGIN CUT HERE
	///	sort(all(cranes),greater<int>());
	//	cout << "cranes: " << cranes << endl;
	// cranes[i] : 1-1000000
	// weight: 1-1000000
	// 6,8,9
	// "2 5 2 4 7"
// END CUT HERE
	stringstream ss;
	tr(boxes,it) ss << *it;
	vector<int> weights = map_atoi( split(ss.str()) );
	sort(all(weights));
// BEGIN CUT HERE
	// cout << "weights: " << weights << endl;
// END CUT HERE

	int wn = weights.size(), ws = wn;
	int time = 0;

	while (ws > 0) {
// BEGIN CUT HERE
	  // printf("%d) last_ws=%d with ", time+1, ws);
	  // cout << "cranes: " << cranes << endl;
// END CUT HERE
	  int last_ws = ws;
	  
	  for (int cid=0; cid<N; cid++) {
		int limit = cranes[cid];
		for (int u=wn-1; u>=0; u--) {
		  int w = weights[u]; if (w < 0) continue;
		  if (w <= limit) {
// BEGIN CUT HERE
			// printf("  - taking box#%d<%d> by crane#%d<%d>\n", u, w, cid, limit);
// END CUT HERE
			weights[u] = -1; ws--;
			break;
		  }
		}
	  }
// BEGIN CUT HERE
	  // cout << "  " << weights << endl;
	  //printf("- weights[%d] = %d, cranes[%d] = %d\n", u, w, cid, cranes[cid]);
	  // if (w > cranes[cid]) { cid++; continue; } // next it
		
	  // weights.erase(it);
// END CUT HERE

	  if (ws == last_ws) return -1;
	  time++;
	}

	return time;
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
	int cranes_[] = {6,8,9};
	  vector <int> cranes(cranes_, cranes_+sizeof(cranes_)/sizeof(*cranes_)); 
	string boxes_[] = {"2 5 2 4 7"};
	  vector <string> boxes(boxes_, boxes_+sizeof(boxes_)/sizeof(*boxes_)); 
	int RetVal = 2; 
	return verify_case(RetVal, ShipLoading().minimumTime(cranes, boxes)); }
int Test_(Case_<1>) {
	timer_clear();
	int cranes_[] = {19,20};
	  vector <int> cranes(cranes_, cranes_+sizeof(cranes_)/sizeof(*cranes_)); 
	string boxes_[] = {"14 12 16 19 16 1 5"};
	  vector <string> boxes(boxes_, boxes_+sizeof(boxes_)/sizeof(*boxes_)); 
	int RetVal = 4; 
	return verify_case(RetVal, ShipLoading().minimumTime(cranes, boxes)); }
int Test_(Case_<2>) {
	timer_clear();
	int cranes_[] = {23,32,25,28};
	  vector <int> cranes(cranes_, cranes_+sizeof(cranes_)/sizeof(*cranes_)); 
	string boxes_[] = {"5 27 10 16 24 20 2 32 18 7"};
	  vector <string> boxes(boxes_, boxes_+sizeof(boxes_)/sizeof(*boxes_)); 
	int RetVal = 3; 
	return verify_case(RetVal, ShipLoading().minimumTime(cranes, boxes)); }
int Test_(Case_<3>) {
	timer_clear();
	int cranes_[] = {11,17,5,2,20,7,5,5,20,7};
	  vector <int> cranes(cranes_, cranes_+sizeof(cranes_)/sizeof(*cranes_)); 
	string boxes_[] = {"18 18 15 15 17"};
	  vector <string> boxes(boxes_, boxes_+sizeof(boxes_)/sizeof(*boxes_)); 
	int RetVal = 2; 
	return verify_case(RetVal, ShipLoading().minimumTime(cranes, boxes)); }
int Test_(Case_<4>) {
	timer_clear();
	int cranes_[] = {56,114,979,120,120,87,480};
	  vector <int> cranes(cranes_, cranes_+sizeof(cranes_)/sizeof(*cranes_)); 
	string boxes_[] = {"221 882 504 358 642 674 212 679 203 279 632 799 79","6 502 275 823 372 594 482 343"};
	  vector <string> boxes(boxes_, boxes_+sizeof(boxes_)/sizeof(*boxes_)); 
	int RetVal = 12; 
	return verify_case(RetVal, ShipLoading().minimumTime(cranes, boxes)); }

template<int N> void Run_() { cerr << "Test Case #" << N << "..." << flush; Test_(Case_<N>()); Run_<sizeof(Test_(Case_<N+1>()))==1 ? -1 : N+1>(); }
template<>      void Run_<-1>() {}
int main() { Run_<0>(); }
// END CUT HERE

