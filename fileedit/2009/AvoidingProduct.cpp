// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
You are given a set A of integers and a positive integer n. You must find positive integers x, y and z such that their product is as close to n as possible (minimize |n - x * y * z|), and none of them belongs to A. If there are several such triples, find the one with the smallest x. If there are still several such triples, minimize y. If there is still a tie, minimize z.


You are given the elements of A as a vector <int> a. Return a vector <int> with exactly three elements: x, y and z, in this order.


DEFINITION
Class:AvoidingProduct
Method:getTriple
Parameters:vector <int>, int
Returns:vector <int>
Method signature:vector <int> getTriple(vector <int> a, int n)


CONSTRAINTS
-a will contain between 0 and 50 elements, inclusive.
-Each element of a will be between 1 and 1000, inclusive.
-All elements of a will be distinct.
-n will be between 1 and 1000, inclusive.


EXAMPLES

0)
{2,4}
4

Returns: {1, 1, 3 }

You can get 3=1*1*3 and 5=1*1*5. 3 is better.

1)
{1}
10

Returns: {2, 2, 2 }



2)
{1,2}
10

Returns: {3, 3, 3 }



3)
{1,3}
12

Returns: {2, 2, 2 }



4)
{1,3}
13

Returns: {2, 2, 4 }



5)
{1,15}
90

Returns: {2, 5, 9 }



*/
// END CUT HERE

#line 80 "AvoidingProduct.cpp"
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

#define UPLIM 1001
class AvoidingProduct {
public:
  vector<int> getTriple(vector<int> a, int n) {
	int dmin = 1000;
	int uplim = 2000+a[0]+1;
	
	//	int N=sz(a); sort(all(a));

	set<int> s; tr(a,it) s.insert(*it);

	int amin=1001;
	for(int i=1;i<=1000;i++) {
	  if (s.find(i)==s.end()) {amin=i;break;}
	}
	int am3=amin*amin*amin;
	if (am3>n) { vector<int> ans(3,amin); return ans; }

	vector<int> ans(3,-1);

	for(int x=1;x<=uplim;x++){
	  if (s.find(x)!=s.end()) continue;
	  for(int y=x;y<=uplim;y++){
		if (s.find(y)!=s.end()) continue;
		int xy = x*y;
		if(xy>uplim) break;
		for(int z=y;z<=uplim;z++){
		  if (s.find(z)!=s.end()) continue;
		  int xyz = xy * z;
		  if(xyz>uplim) break;
		  int d = abs(n-xyz);
		  if (d<dmin) {
			dmin = d;
			ans[0]=x; ans[1]=y; ans[2]=z;
		  }
		}
	  }
	}
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
	int a_[] = {2,4};
	  vector <int> a(a_, a_+sizeof(a_)/sizeof(*a_)); 
	int n = 4; 
	int RetVal_[] = {1, 1, 3 };
	  vector <int> RetVal(RetVal_, RetVal_+sizeof(RetVal_)/sizeof(*RetVal_)); 
	return verify_case(RetVal, AvoidingProduct().getTriple(a, n)); }
int Test_(Case_<1>) {
	timer_clear();
	int a_[] = {1};
	  vector <int> a(a_, a_+sizeof(a_)/sizeof(*a_)); 
	int n = 10; 
	int RetVal_[] = {2, 2, 2 };
	  vector <int> RetVal(RetVal_, RetVal_+sizeof(RetVal_)/sizeof(*RetVal_)); 
	return verify_case(RetVal, AvoidingProduct().getTriple(a, n)); }
int Test_(Case_<2>) {
	timer_clear();
	int a_[] = {1,2};
	  vector <int> a(a_, a_+sizeof(a_)/sizeof(*a_)); 
	int n = 10; 
	int RetVal_[] = {3, 3, 3 };
	  vector <int> RetVal(RetVal_, RetVal_+sizeof(RetVal_)/sizeof(*RetVal_)); 
	return verify_case(RetVal, AvoidingProduct().getTriple(a, n)); }
int Test_(Case_<3>) {
	timer_clear();
	int a_[] = {1,3};
	  vector <int> a(a_, a_+sizeof(a_)/sizeof(*a_)); 
	int n = 12; 
	int RetVal_[] = {2, 2, 2 };
	  vector <int> RetVal(RetVal_, RetVal_+sizeof(RetVal_)/sizeof(*RetVal_)); 
	return verify_case(RetVal, AvoidingProduct().getTriple(a, n)); }
int Test_(Case_<4>) {
	timer_clear();
	int a_[] = {1,3};
	  vector <int> a(a_, a_+sizeof(a_)/sizeof(*a_)); 
	int n = 13; 
	int RetVal_[] = {2, 2, 4 };
	  vector <int> RetVal(RetVal_, RetVal_+sizeof(RetVal_)/sizeof(*RetVal_)); 
	return verify_case(RetVal, AvoidingProduct().getTriple(a, n)); }
int Test_(Case_<5>) {
	timer_clear();
	int a_[] = {1,15};
	  vector <int> a(a_, a_+sizeof(a_)/sizeof(*a_)); 
	int n = 90; 
	int RetVal_[] = {2, 5, 9 };
	  vector <int> RetVal(RetVal_, RetVal_+sizeof(RetVal_)/sizeof(*RetVal_)); 
	return verify_case(RetVal, AvoidingProduct().getTriple(a, n)); }
int Test_(Case_<6>) {
	timer_clear();
	int a_[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	  vector <int> a(a_, a_+sizeof(a_)/sizeof(*a_)); 
	int n = 1;
	int RetVal_[] = {11,11,11};
	  vector <int> RetVal(RetVal_, RetVal_+sizeof(RetVal_)/sizeof(*RetVal_)); 
	return verify_case(RetVal, AvoidingProduct().getTriple(a, n)); }
int Test_(Case_<7>) {
	timer_clear();
	int a_[] = {1, 2, 3, 4, 990, 20, 5, 6, 10, 11};
	  vector <int> a(a_, a_+sizeof(a_)/sizeof(*a_)); 
	int n = 990;
	int RetVal_[] = {7,8,18};
	  vector <int> RetVal(RetVal_, RetVal_+sizeof(RetVal_)/sizeof(*RetVal_)); 
	return verify_case(RetVal, AvoidingProduct().getTriple(a, n)); }

template<int N> void Run_() { cerr << "Test Case #" << N << "..." << flush; Test_(Case_<N>()); Run_<sizeof(Test_(Case_<N+1>()))==1 ? -1 : N+1>(); }
template<>      void Run_<-1>() {}
int main() { Run_<0>(); }
// END CUT HERE

