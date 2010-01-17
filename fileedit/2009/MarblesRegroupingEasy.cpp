// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
John is a marble collector. He keeps his marbles in boxes. He also likes to keep things in order.



One day, his younger brother was playing with the marbles.  After he was done, he put all the marbles back in boxes, but he did it randomly, so certain boxes might now contain marbles of different colors. John wants him to regroup the marbles so that the grouping satisfies the following restrictions:



At most one box, called the joker box, may contain marbles of different colors. We can choose any box as a joker box.
Every box except the joker box must either be empty or only contain marbles of the same color.
All marbles of the same color, except those in the joker box, must be in the same box. It's possible that all marbles of the same color are in the joker box.



You are given a vector <string> boxes, where the j-th digit of the i-th element is the number of marbles of color j in the i-th box. Return the minimal number of moves necessary to regroup the marbles, where each move consists of taking any number of marbles from one box (not necessarily of the same color) and putting them into another.


DEFINITION
Class:MarblesRegroupingEasy
Method:minMoves
Parameters:vector <string>
Returns:int
Method signature:int minMoves(vector <string> boxes)


CONSTRAINTS
-boxes will contain between 1 and 50 elements, inclusive.
-Each element of boxes will contain between 1 and 50 characters, inclusive.
-All elements of boxes will contain the same number of characters.
-Each element of boxes will contain only digits ('0'-'9').


EXAMPLES

0)
{"20",
 "11"}

Returns: 0

Let box 1 be the joker box. All marbles of color 0, except those in the joker box, are in box 0. Box 0 contain only marbles of the color 0. So, all restrictions are already satisfied.


1)
{"11",
 "11",
 "10"}

Returns: 1

There are several possible solutions:

Move all marbles from box 0 into box 1. Box 1 is the joker box.
Move all marbles from box 1 into box 0. Box 0 is the joker box.
Move the marble of color 0 from box 0 into box 1 or 2. Box 1 is the joker box.
Move the marble of color 0 from box 1 into box 0 or 2. Box 0 is the joker box.



2)
{"10",
 "10",
 "01",
 "01"}

Returns: 1

Let box 0 be the joker box. Now we only need to group all marbles of  color 1 into one box.

3)
{"11",
 "11",
 "11",
 "10",
 "10",
 "01"}

Returns: 3



4)
{"020008000070",
 "000004000000",
 "060000600000",
 "006000000362",
 "000720000000",
 "000040000000", 
 "004009003000",
 "000800000000", 
 "020030003000",
 "000500200000",
 "000000300000"}

Returns: 6



*/
// END CUT HERE

#line 107 "MarblesRegroupingEasy.cpp"
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
#define found(s,e)  ((s).find(e)!=(s).end())
#define remove_(c,val) (c).erase(remove((c).begin(),(c).end(),(val)),(c).end())

class MarblesRegroupingEasy {
  vector<string> bx;
  int bn, cn;
  int joker;

  int sub(int moves) {
	vector<vector<bool> > b(bn);
	vector<vector<bool> > c(cn);

	int jbc=0;
	vector<int> b_(bn,0);
	rep(i,bn) {
	  if(i==joker) continue;
	  b[i].resize(cn);
	  rep(j,cn) {
		bool t=(bx[i][j]>'0');
		b[i][j]=t; if(t) b_[i]++;
	  }
	  if(b_[i]>1) jbc++;
	}
	if(jbc==0) return 0;
	//cout << "jbc=" << jbc << ":" << b_ <<endl;

	int nc=0;
	vector<int> c_(cn,0);
	rep(i,cn) { c[i].resize(bn);
	  rep(j,bn) {
		if (j==joker)continue;
		bool t=b[j][i];
		c[i][j]=t; if(t) c_[i]++;
	  }
	  if(c_[i]>1) nc++;
	}
	cout << "nc=" << nc << ":" << c_ <<endl;
	if(nc==0) return 0;

	return INT_MAX;
  }
public:
  int minMoves(vector<string> boxes) {
	bx = boxes;
	bn=sz(boxes);//1-50
	cn=boxes[0].length();

	int mmv = INT_MAX;
	for(joker=0;joker<bn;joker++) {
	  mmv = min(mmv,sub(0));
	}
	return mmv;
  }
  /*
	vector<long long> st(bn);
	rep(i,bn){
	  long long s=0;
	  for(long long j=0,m=1;j<cn;j++,m<<=1){
		if (b[i][j]) s|=m;
	  }
	  st[i] = s;
	}
	cout << "ST:"<<st << endl;
	//	cout << b_ << endl;
	//	cout << c_ << endl;
	return -1;
  }
  */
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
	string boxes_[] = {"20",
 "11"};
	  vector <string> boxes(boxes_, boxes_+sizeof(boxes_)/sizeof(*boxes_)); 
	int RetVal = 0; 
	return verify_case(RetVal, MarblesRegroupingEasy().minMoves(boxes)); }
int Test_(Case_<1>) {
	timer_clear();
	string boxes_[] = {"11",
 "11",
 "10"};
	  vector <string> boxes(boxes_, boxes_+sizeof(boxes_)/sizeof(*boxes_)); 
	int RetVal = 1; 
	return verify_case(RetVal, MarblesRegroupingEasy().minMoves(boxes)); }
int Test_(Case_<2>) {
	timer_clear();
	string boxes_[] = {"10",
 "10",
 "01",
 "01"};
	  vector <string> boxes(boxes_, boxes_+sizeof(boxes_)/sizeof(*boxes_)); 
	int RetVal = 1; 
	return verify_case(RetVal, MarblesRegroupingEasy().minMoves(boxes)); }
int Test_(Case_<3>) {
	timer_clear();
	string boxes_[] = {"11",
 "11",
 "11",
 "10",
 "10",
 "01"};
	  vector <string> boxes(boxes_, boxes_+sizeof(boxes_)/sizeof(*boxes_)); 
	int RetVal = 3; 
	return verify_case(RetVal, MarblesRegroupingEasy().minMoves(boxes)); }
int Test_(Case_<4>) {
	timer_clear();
	string boxes_[] = {"020008000070",
 "000004000000",
 "060000600000",
 "006000000362",
 "000720000000",
 "000040000000", 
 "004009003000",
 "000800000000", 
 "020030003000",
 "000500200000",
 "000000300000"};
	  vector <string> boxes(boxes_, boxes_+sizeof(boxes_)/sizeof(*boxes_)); 
	int RetVal = 6; 
	return verify_case(RetVal, MarblesRegroupingEasy().minMoves(boxes)); }

template<int N> void Run_() { cerr << "Test Case #" << N << "..." << flush; Test_(Case_<N>()); Run_<sizeof(Test_(Case_<N+1>()))==1 ? -1 : N+1>(); }
template<>      void Run_<-1>() {}
int main() { Run_<0>(); }
// END CUT HERE

