// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// Twin Towns are towns which are paired together to encourage human contact and cultural links.  The government of your country has decided to establish such relationships among a given set of towns.  The following rules must be followed:

Each town must have between 0 and maxPartners twins, inclusive.
The distance between each pair of twin towns must be at least minDistance.  The distance between two towns located at (x1, y1) and (x2, y2) is defined as |x1-x2| + |y1-y2|.



The government will establish as many relationships as possible.  If there are multiple ways to do this, the government will choose the one that minimizes the sum of the distances between each pair of twin towns.  You are given vector <int>s x and y, where (x[i], y[i]) are the coordinates of the i-th town.  Return a vector <int> containing exactly two elements, where the first element is the number of relationships the government will establish, and the second element is the sum of the distances between each pair of twin towns.

DEFINITION
Class:TwinTowns
Method:optimalTwinTowns
Parameters:vector <int>, vector <int>, int, int
Returns:vector <int>
Method signature:vector <int> optimalTwinTowns(vector <int> x, vector <int> y, int maxPartners, int minDistance)


CONSTRAINTS
-maxPartners will be between 1 and 3, inclusive.
-x and y will contain between 1 and 10 elements, inclusive.
-x and y will contain the same number of elements.
-Each element of x and y will be between 0 and 1,000, inclusive.
-minDistance will be between 1 and 2,000, inclusive.
-No two towns will have the same coordinates.


EXAMPLES

0)
{0,0,10}
{0,10,4}
1
1

Returns: {1, 10 }

We have 3 towns here at coordinates (0,0), (0,10), and (10,4).  Each town can have at most one twin.  Since we have only 3 towns, we can establish at most one pair of twin towns.  The best solution pairs the first and second towns, where the distance is 10.

1)
{0,0,10}
{0,10,4}
1
11

Returns: {1, 14 }

These are the same towns from Example 0, but minDistance is now 11.  The first and second towns cannot be twins.  The best solution is to pair the first and third towns, where the distance is 14.

2)
{0,10,0,10}
{0,0,20,20}
1
1

Returns: {2, 20 }

Here we have 4 towns located at the vertices of a rectangle.  Each town can have at most one twin.  The best solution is to pair the first town with the second, and the third town with the fourth.  The distance between each pair is 10.


3)
{0,10,0,10}
{0,0,20,20}
2
10

Returns: {4, 60 }

These are the same towns from Example 2, but now, each town can have up to two twins.  The best solution establishes 4 pairs of twin towns:

the first city at (0,0) with the second city at (10,0), where the distance is 10
the first city at (0,0) with the third city at (0,20), where the distance is 20
the second city at (10,0) with the fourth city at (10,20), where the distance is 20
the third city at (0,20) with the fourth city at (10,20), where the distance is 10

The sum of the distances is 60.

4)
{0,0,0,0,0,0,0,0,0}
{1,2,3,4,5,6,7,8,9}
3
6

Returns: {6, 40 }

We can pair the following list of towns (indexed from 1): 1-7, 1-8, 1-9, 2-8, 2-9, 3-9.

*/
// END CUT HERE

#line 94 "TwinTowns.cpp"
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
#define tr(c,i)  for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); i++)
#define rep(var,n)  for(int var=0;var<(n);var++)

// BEGIN CUT HERE
/*
template <typename T>
  vector<vector<T> > combinations(const vector<T>& list, int r)
{
  int n = list.size();
  int nCr = c(n, r);
  vector<vector<T> > result(nCr);
  vector<int> curr(r); for (int i=0; i<r; i++) curr[i] = i;

  for (int idx=0; idx<nCr; idx++) {
	result[idx].resize(r);
	for (int i=0; i<r; i++) result[idx][i] = list[curr[i]];

	for (int i=r-1; i>=0; i--) {
	  if (curr[i] == n-(r-i)) {
		if (i == 0) return result;
		continue;
	  } else {
		int ofs = curr[i] - i + 1;
		for (int j=i; j<r; j++) curr[j] = j + ofs;
		break;
	  }
	}
  }
}
*/
// END CUT HERE

// BEGIN CUT HERE
string binstr(long long x, int len_min=1)
{
  /*
  if (x == 0) {
	string s = "0";
	return s;
  }
  */
  char buf[65], *p = buf+64;
  *p = 0;

  while (x > 0 || len_min > 0) {
	*(--p) = '0' + (x & 1);
	x >>= 1;
	len_min--;
  }
  // printf("// len=%d, binstr(%d) = '%s'\n", (int)(buf+64-p), (int)x, p);
  string s(p);
  return s;
}
// END CUT HERE

const int D_INFTY = 2001;

inline int get_at(long long arcs, int idx)
{
  return (arcs >> (idx * 2)) & 0x3;
}
inline long long set_at(long long arcs, int idx, int val)
{
  long long mask = 3LL << (idx * 2);
  long long vall = (long long)val << (idx * 2);
  return (arcs & (~mask)) | vall;
}

class TwinTowns {
  int n, maxP;
  int distance[10][10];
  bool available[10][10];//, pat[10];

  //vector<map<vector<int>,int> > memo;
  map<pair<int,vector<int> >,vector<int> > memo;

private:
  int findMaximum(long long arcs, int till) {
	/*
	pair<int,vector<int> > key = make_pair(till,arcs);
	if (memo.find(key) != memo.end()) return memo[key];
	*/
// BEGIN CUT HERE
	/*
	printf("findMaximum(arcs,%d):\n", till);
	cout << "  arcs: " << arcs << endl;
	*/
// END CUT HERE
	if (till == 0) {
// BEGIN CUT HERE
	  //cout << "  arcs: " << arcs << endl;
// END CUT HERE
	  //vector<int> ans(2);
	  int pcnt = 0; rep(i,n) pcnt += get_at(arcs,i);
	  //ans[0] = pcnt / 2; ans[1] = 0;
// BEGIN CUT HERE
	  //cout << "ans= " << ans << endl;
// END CUT HERE
	  //memo[key] = ans;
	  //return ans;
	  return pcnt / 2;
	}

	int pmax = 0, dmin = INT_MAX;//D_INFTY;
	int count = get_at(arcs,till);

	long long arcs_ = arcs;

	int pat_max = (1 << till) - 1;
	int c_max = maxP - count;

	for (int pat=0; pat<=pat_max; pat++) {
	  int c = __builtin_popcount(pat);
	  if (c > c_max) continue;

// BEGIN CUT HERE
	  //printf(" pat:%s, c:%d,\n", binstr(pat,n).c_str(), c);
// END CUT HERE
	  arcs_ = set_at(arcs_, till, count + c);
	  
	  int d = 0;
	  for (int i=0,m=1;i<till;i++,m<<=1) {
// BEGIN CUT HERE
		//printf("    till=%d, i=%d, m=%s\n", till, i, binstr(pat,n).c_str());
// END CUT HERE
		if ((pat & m) == 0) continue;
		if (! available[till][i]) goto next_pat;
		if (get_at(arcs_,i) == maxP) goto next_pat;
// BEGIN CUT HERE
		//printf("   d += %d\n", distance[till][i]);
// END CUT HERE
		arcs_ = set_at(arcs_, i, get_at(arcs_,i) + 1);
		/*arcs_[i]++; */ d += distance[till][i];
	  }
// BEGIN CUT HERE
	  //printf(" d:%d\n", d);
// END CUT HERE
	  {
		int ans = findMaximum(arcs_, till-1);
		int ans_p = ans & 31, ans_d = ans >> 5;
		ans_d += d;
		if (ans_p > pmax) {
		  pmax = ans_p; dmin = ans_d;
		} else if (ans_p == pmax) {
		  if (ans_d < dmin) dmin = ans_d;
		}
	  }
	next_pat:
	  arcs_ = arcs;
	}

	/*
	vector<int> ans(2,0);
	ans[0] = pmax; ans[1] = dmin;
	//memo[key] = ans;
	return ans;
	*/
	return (dmin << 5) | pmax;
  }
  
public:
  vector<int> optimalTwinTowns(vector<int> x, vector<int> y, int maxPartners, int minDistance) {
// BEGIN CUT HERE
	/*
	cout << "x[]: " << x << endl;
	cout << "y[]: " << y << endl;
	cout << "maxPartners: " << maxPartners << ", minDistance: " << minDistance << endl;
	*/
// END CUT HERE
	n = x.size();
	if (n == 1) {
	  vector<int> ans(2,0);
	  return ans;
	}

	maxP = min(maxPartners,n-1);
// BEGIN CUT HERE
	// maxPartners: 1-3
	// n:1-10, 座標値は0-1000
	// minDistance:1-2000
// END CUT HERE
	rep(i,n) rep(j,n) available[i][j] = false;

	rep(j,n) {
	  rep(i,n) {
		if (i == j) continue;
		int dist = abs(x[i]-x[j]) + abs(y[i]-y[j]); // 1-2000
// BEGIN CUT HERE
		/*
		printf("(%d,%d) - (%d,%d) = |%d-%d| + |%d-%d| = %d %s %d\n",
			   x[i],y[i], x[j],y[j], x[i],x[j], y[i],y[j],
			   dist, (dist >= minDistance)? ">=" : "<", minDistance);
		*/
// END CUT HERE
		if (dist >= minDistance) {
		  distance[i][j] = distance[j][i] = dist;
		  available[i][j] = available[j][i] = true;
		}
	  }
	}

	/*
	vector<int> arcs(n,0);
	return findMaximum(arcs, n-1);
	*/
	int a = findMaximum(0, n-1);
	vector<int> ans(2,0);
	ans[0] = a & 31; ans[1] = a >> 5;
	return ans;
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
	int x_[] = {0,0,10};
	  vector <int> x(x_, x_+sizeof(x_)/sizeof(*x_)); 
	int y_[] = {0,10,4};
	  vector <int> y(y_, y_+sizeof(y_)/sizeof(*y_)); 
	int maxPartners = 1; 
	int minDistance = 1; 
	int RetVal_[] = {1, 10 };
	  vector <int> RetVal(RetVal_, RetVal_+sizeof(RetVal_)/sizeof(*RetVal_)); 
	return verify_case(RetVal, TwinTowns().optimalTwinTowns(x, y, maxPartners, minDistance)); }
int Test_(Case_<1>) {
	timer_clear();
	int x_[] = {0,0,10};
	  vector <int> x(x_, x_+sizeof(x_)/sizeof(*x_)); 
	int y_[] = {0,10,4};
	  vector <int> y(y_, y_+sizeof(y_)/sizeof(*y_)); 
	int maxPartners = 1; 
	int minDistance = 11; 
	int RetVal_[] = {1, 14 };
	  vector <int> RetVal(RetVal_, RetVal_+sizeof(RetVal_)/sizeof(*RetVal_)); 
	return verify_case(RetVal, TwinTowns().optimalTwinTowns(x, y, maxPartners, minDistance)); }
int Test_(Case_<2>) {
	timer_clear();
	int x_[] = {0,10,0,10};
	  vector <int> x(x_, x_+sizeof(x_)/sizeof(*x_)); 
	int y_[] = {0,0,20,20};
	  vector <int> y(y_, y_+sizeof(y_)/sizeof(*y_)); 
	int maxPartners = 1; 
	int minDistance = 1; 
	int RetVal_[] = {2, 20 };
	  vector <int> RetVal(RetVal_, RetVal_+sizeof(RetVal_)/sizeof(*RetVal_)); 
	return verify_case(RetVal, TwinTowns().optimalTwinTowns(x, y, maxPartners, minDistance)); }
int Test_(Case_<3>) {
	timer_clear();
	int x_[] = {0,10,0,10};
	  vector <int> x(x_, x_+sizeof(x_)/sizeof(*x_)); 
	int y_[] = {0,0,20,20};
	  vector <int> y(y_, y_+sizeof(y_)/sizeof(*y_)); 
	int maxPartners = 2; 
	int minDistance = 10; 
	int RetVal_[] = {4, 60 };
	  vector <int> RetVal(RetVal_, RetVal_+sizeof(RetVal_)/sizeof(*RetVal_)); 
	return verify_case(RetVal, TwinTowns().optimalTwinTowns(x, y, maxPartners, minDistance)); }
int Test_(Case_<4>) {
	timer_clear();
	int x_[] = {0,0,0,0,0,0,0,0,0};
	  vector <int> x(x_, x_+sizeof(x_)/sizeof(*x_)); 
	int y_[] = {1,2,3,4,5,6,7,8,9};
	  vector <int> y(y_, y_+sizeof(y_)/sizeof(*y_)); 
	int maxPartners = 3; 
	int minDistance = 6; 
	int RetVal_[] = {6, 40 };
	  vector <int> RetVal(RetVal_, RetVal_+sizeof(RetVal_)/sizeof(*RetVal_)); 
	return verify_case(RetVal, TwinTowns().optimalTwinTowns(x, y, maxPartners, minDistance)); }
int Test_(Case_<5>) {
	timer_clear();
	int x_[] = {0};
	  vector <int> x(x_, x_+sizeof(x_)/sizeof(*x_)); 
	int y_[] = {0};
	  vector <int> y(y_, y_+sizeof(y_)/sizeof(*y_)); 
	int maxPartners = 1;
	int minDistance = 1;
	int RetVal_[] = { 0, 0 };
	  vector <int> RetVal(RetVal_, RetVal_+sizeof(RetVal_)/sizeof(*RetVal_)); 
	return verify_case(RetVal, TwinTowns().optimalTwinTowns(x, y, maxPartners, minDistance)); }
int Test_(Case_<6>) {
	timer_clear();
	int x_[] = {0,1};
	vector <int> x(x_, x_+sizeof(x_)/sizeof(*x_)); 
	int y_[] = {0,1};
	  vector <int> y(y_, y_+sizeof(y_)/sizeof(*y_)); 
	int maxPartners = 1;
	int minDistance = 1;
	int RetVal_[] = { 1, 2 };
	  vector <int> RetVal(RetVal_, RetVal_+sizeof(RetVal_)/sizeof(*RetVal_)); 
	return verify_case(RetVal, TwinTowns().optimalTwinTowns(x, y, maxPartners, minDistance)); }
int Test_(Case_<7>) {
	timer_clear();
	int x_[] = {0,1};
	vector <int> x(x_, x_+sizeof(x_)/sizeof(*x_)); 
	int y_[] = {0,1};
	  vector <int> y(y_, y_+sizeof(y_)/sizeof(*y_)); 
	int maxPartners = 1;
	int minDistance = 3;
	int RetVal_[] = { 0, 0 };
	  vector <int> RetVal(RetVal_, RetVal_+sizeof(RetVal_)/sizeof(*RetVal_)); 
	return verify_case(RetVal, TwinTowns().optimalTwinTowns(x, y, maxPartners, minDistance)); }

int Test_(Case_<8>) { // 27
	timer_clear();
	int x_[] = {89, 269, 914, 961, 768, 365, 592, 250, 566, 87};
	vector <int> x(x_, x_+sizeof(x_)/sizeof(*x_)); 
	int y_[] = {240, 492, 286, 836, 14, 421, 94, 21, 438, 9};
	vector <int> y(y_, y_+sizeof(y_)/sizeof(*y_)); 
	int maxPartners = 2;
	int minDistance = 737;
	int RetVal_[] = {7, 6149};
	  vector <int> RetVal(RetVal_, RetVal_+sizeof(RetVal_)/sizeof(*RetVal_)); 
	return verify_case(RetVal, TwinTowns().optimalTwinTowns(x, y, maxPartners, minDistance)); }
int Test_(Case_<9>) { // 28
  timer_clear();
  int x_[] = {784, 610, 16, 418, 68, 130, 935, 912, 273, 678};
  vector <int> x(x_, x_+sizeof(x_)/sizeof(*x_)); 
  int y_[] = {861, 417, 877, 351, 666, 999, 313, 911, 437, 287};
  vector <int> y(y_, y_+sizeof(y_)/sizeof(*y_)); 
  int maxPartners = 2;
  int minDistance = 892;
  int RetVal_[] = {9, 9306};
  vector <int> RetVal(RetVal_, RetVal_+sizeof(RetVal_)/sizeof(*RetVal_)); 
  return verify_case(RetVal, TwinTowns().optimalTwinTowns(x, y, maxPartners, minDistance)); }
int Test_(Case_<10>) { // 6
  timer_clear();
  int x_[] = {899, 2, 726, 102, 721, 243, 650, 40, 707, 487};
  vector <int> x(x_, x_+sizeof(x_)/sizeof(*x_)); 
  int y_[] = {397, 498, 773, 605, 225, 263, 151, 533, 205, 6};
  vector <int> y(y_, y_+sizeof(y_)/sizeof(*y_)); 
  int maxPartners = 3;
  int minDistance = 1;
  int RetVal_[] = {15, 5475};
  vector <int> RetVal(RetVal_, RetVal_+sizeof(RetVal_)/sizeof(*RetVal_)); 
  return verify_case(RetVal, TwinTowns().optimalTwinTowns(x, y, maxPartners, minDistance)); }

template<int N> void Run_() { cerr << "Test Case #" << N << "..." << flush; Test_(Case_<N>()); Run_<sizeof(Test_(Case_<N+1>()))==1 ? -1 : N+1>(); }
template<>      void Run_<-1>() {}
//int main() { Run_<0>(); }
int main(int argc, char *argv[])
{
  int n = (argc == 2)? atoi(argv[1]) : -1;
  if (n >= 0) {
	cerr << "Test Case #" << n << "..." << flush;
	switch (n) {
	case 0:	Test_(Case_<0>()); break;
	case 1:	Test_(Case_<1>()); break;
	case 2:	Test_(Case_<2>()); break;
	case 3:	Test_(Case_<3>()); break;
	case 4:	Test_(Case_<4>()); break;
	case 5:	Test_(Case_<5>()); break;
	case 6:	Test_(Case_<6>()); break;
	case 7:	Test_(Case_<7>()); break;
	case 8:	Test_(Case_<8>()); break;
	case 9:	Test_(Case_<9>()); break;
	case 10:	Test_(Case_<10>()); break;
	default: Run_<0>(); break;
	}
  } else {
	Run_<0>();
  }
}
// END CUT HERE
