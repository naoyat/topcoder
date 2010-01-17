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
#include <time.h>
// END CUT HERE
#include <sstream>
#include <cmath>
using namespace std;

#define sz(a)  int((a).size())
#define pb  push_back
#define all(c)  (c).begin(),(c).end()
#define tr(c,i)  for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); i++)

class LaggedGenerator {
public:
  vector<int> crack(vector<int> S, int P, int M) {
	int K = S.size();
// BEGIN CUT HERE
	cout << "crack(" << S << ", P=" << P << ", M=" << M << endl;
	// S[]: last K outputs of the pseudorandom number generator
	// P: 素数 [101 - 40000)
	// M: 欲しい個数 // = floor(rand() * rand() * 996) + 5 = [5..1000]
// END CUT HERE
	// D: 次元, { 1, 2, 3 }
	//for (M=5; M<=1000; M++) {
	for (int D=1; D<=3; D++) {
	  int max_ = 1 + M;
	  if (D > 1) max_ += M * (M+1) / 2;
	  if (D > 2) max_ += M * (M+1) * (M+2) / 6;
	  int x = min(200, max_);
	  for (int n_terms=2; n_terms<=x; n_terms++) {
		printf("M=%d D=%d NumOfTerms=%d; each term degree:[0..%d]\n", M,D,n_terms, D);
	  }
	  //printf("M=%d, D=%d: The number of terms will then be chosen in [2,%d]\n", M, D, x);
	  //printf("  and each term will be generated with a degree in [0,%d]\n", D);
		
	}
	
	vector<int> result(M,0);
	return result;
  }

// BEGIN CUT HERE
  clock_t start;
  void timer_clear()
  {
	start = clock();
  }
  char *timer()
  {
	clock_t end = clock();
	double interval = (double)(end - start)/CLOCKS_PER_SEC;
	
	char *ret = NULL;
	asprintf(&ret, " (%g msec)", interval*1000);
	return ret;
  }
// END CUT HERE
	
// BEGIN CUT HERE
public:
  void run_test(int Case) {
	if ((Case == -1) || (Case == 0)) test_case_0();
	if ((Case == -1) || (Case == 1)) test_case_1();
	/*
	if ((Case == -1) || (Case == 2)) test_case_2();
	if ((Case == -1) || (Case == 3)) test_case_3();
	if ((Case == -1) || (Case == 4)) test_case_4();
	if ((Case == -1) || (Case == 5)) test_case_5();
	if ((Case == -1) || (Case == 6)) test_case_6();
	if ((Case == -1) || (Case == 7)) test_case_7();
	if ((Case == -1) || (Case == 8)) test_case_8();
	if ((Case == -1) || (Case == 9)) test_case_9();
	*/
  }
private:
  template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

  void verify_case(int Case, const vector<int> &Expected, const vector<int> &Received) { 
	cerr << "Test Case #" << Case << "...";
	if (Expected == Received) cerr << "PASSED" << endl;
	else {
	  cerr << "FAILED" << endl;
	  cerr << "\tExpected: \"" << Expected << '\"' << endl; 
	  cerr << "\tReceived: \"" << Received << '\"' << endl;
	}
  }

  void test_case_0() { 
	int S_arr[] = { 52, 17, 39, 70, 19, 50, 1, 6, 96, 12,
					58, 31, 51, 15, 57, 76, 86, 66, 35, 59,
					15, 57, 43, 8, 6, 74, 87, 16, 42, 21,
					13, 33, 91, 19, 12, 47, 62, 37, 94, 28,
					46, 34, 53, 90, 32, 8, 22, 89, 76, 13 }; // K = 50
	vector<int> S(S_arr, S_arr + (sizeof(S_arr) / sizeof(S_arr[0])));
	int P = 101;//
	int M = 5;
	int E_arr[] = { 78, 46, 4, 73, 96 }; // K=50, M=5
	vector<int> Expected(E_arr, E_arr + (sizeof(E_arr) / sizeof(E_arr[0])));
	verify_case(0, Expected, crack(S, P, M));
  }
  void test_case_1() { 
	int S_arr[] = {0};
	vector<int> S(S_arr, S_arr + (sizeof(S_arr) / sizeof(S_arr[0])));
	int P = 36299;
	int M = 16;
	int E_arr[] = {0};
	vector<int> Expected(E_arr, E_arr + (sizeof(E_arr) / sizeof(E_arr[0])));
	verify_case(1, Expected, crack(S, P, M));
  }
// END CUT HERE
};

// BEGIN CUT HERE
int main(int argc, char *argv[]) {
  LaggedGenerator ___test;
  ___test.run_test( argc>=2 ? atoi(argv[1]):-1 );
}
// END CUT HERE


