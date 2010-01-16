#line 78 "BitwiseEquations.cpp"
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


class BitwiseEquations {
public:
  long long kthPlusOrSolution(int x,int k){
	int xx=x;
	long long ret=0, n=0;
	while(x!=0 || k!=0) {
	  if(x&1) {
		ret += 1LL << n;
	  } else{
		long long u = (k&1) << n;
		printf("x=%d,k=%d ;; (k&1) << n = %d << %d", x,k,
			   k & 1, n);
		printf(" => %d (%lld)\n", 
			   (k & 1) << n, u);
		printf(" ret: %lld ", ret);
		ret += (k&1) << n;
		printf(" => %lld\n ", ret);
		k>>=1;
	  }
	  x>>=1;
	  n++;
	}
	return ret - xx;
  }
};

// BEGIN CUT HERE
#include <time.h>
clock_t start_time;
void timer_clear() { start_time = clock(); }
string timer() { clock_t end_time = clock(); double interval = (double)(end_time - start_time)/CLOCKS_PER_SEC; ostringstream os; os << " (" << interval*1000 << " msec)"; return os.str(); }

template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
int verify_case(const long long &Expected, const long long &Received) { if (Expected == Received) cerr << "PASSED" << timer() << endl; else { cerr << "FAILED" << timer() << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } return 0;}

template<int N> struct Case_ {};
char Test_(...);
int Test_(Case_<0>) {
	timer_clear();
	int x = 5; 
	int k = 1; 
	long long RetVal = 2LL; 
	return verify_case(RetVal, BitwiseEquations().kthPlusOrSolution(x, k)); }
int Test_(Case_<1>) {
	timer_clear();
	int x = 5; 
	int k = 5; 
	long long RetVal = 18LL; 
	return verify_case(RetVal, BitwiseEquations().kthPlusOrSolution(x, k)); }
int Test_(Case_<2>) {
	timer_clear();
	int x = 10; 
	int k = 3; 
	long long RetVal = 5LL; 
	return verify_case(RetVal, BitwiseEquations().kthPlusOrSolution(x, k)); }
int Test_(Case_<3>) {
	timer_clear();
	int x = 1; 
	int k = 1000000000; 
	long long RetVal = 2000000000LL; 
	return verify_case(RetVal, BitwiseEquations().kthPlusOrSolution(x, k)); }
int Test_(Case_<4>) {
	timer_clear();
	int x = 1; 
	int k = 1; 
	long long RetVal = 2LL; 
	return verify_case(RetVal, BitwiseEquations().kthPlusOrSolution(x, k)); }
int Test_(Case_<5>) {
	timer_clear();
	int x = 2000000000;
	int k = 2000000000;
	long long RetVal = 2LL; 
	return verify_case(RetVal, BitwiseEquations().kthPlusOrSolution(x, k)); }

template<int N> void Run_() { cerr << "Test Case #" << N << "..." << flush; Test_(Case_<N>()); Run_<sizeof(Test_(Case_<N+1>()))==1 ? -1 : N+1>(); }
template<>      void Run_<-1>() {}
int main() { Run_<0>(); }
// END CUT HERE


