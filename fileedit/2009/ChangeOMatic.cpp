// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
The Change-O-Matic is a deterministic machine with a single goal: to provide change. That is, you throw in a banknote or a coin, and the machine throws out a bunch of smaller coins with the same total value.



More precisely, the Change-O-Matic operates as follows:



The machine contains several large stacks of coins. The values of these coins are given as a vector <int> outputValues. For the purpose of this problem we may assume that the
machine contains an infinite number of coins of each of these values. One of the available values is always 1.



The customer may throw in any coin or banknote with value greater than 1. The machine will output a set of at least two coins with the same total value. 
If there are multiple ways to satisfy this requirement, the machine prefers the one where the total number of output coins is minimized.
If there are still multiple ways, the machine prefers the one that is lexicographically maximal (see Notes for a precise definition).



You have a single banknote, and its value is given as a long long inputValue. You would like to change it into coins of value 1 each. 
Return the number of times you have to throw something into the machine.



DEFINITION
Class:ChangeOMatic
Method:howManyRounds
Parameters:vector <int>, long long
Returns:long long
Method signature:long long howManyRounds(vector <int> outputValues, long long inputValue)


NOTES
-Let A=(a1,...,aN) and B=(b1,...,bN) be two different but equally large sets of coins, with a1 >= a2 >= ... >= aN and b1 >= b2 >= ... >= bN. Let x be the smallest index such that ax != bx. If ax > bx, we say that the set A is lexicographically larger than the set B.
-Given a collection of different but equally large sets of coins, the lexicographically maximal set is the one that is lexicographically larger than each of the other sets. (Note that there is always exactly one such set.)


CONSTRAINTS
-outputValues will contain between 1 and 50 elements, inclusive.
-outputValues will be sorted in strictly ascending order. That is, for each i, outputValues[i] < outputValues[i+1].
-Each element of outputValues will be between 1 and 1,000, inclusive.
-Element 0 of outputValues will be equal to 1.
-inputValue will be between 2 and 10^15, inclusive.


EXAMPLES

0)
{1,5,10}
21

Returns: 7

The process of changing your money may look as follows:

You insert:    You get:      You then have:
21             10+10+1       10+10+1
10             5+5           10+5+5+1
5              1+1+1+1+1     10+5+1+1+1+1+1+1
10             5+5           5+5+5+1+1+1+1+1+1
5              1+1+1+1+1     5+5+(eleven times 1)
5              1+1+1+1+1     5+(sixteen times 1)
5              1+1+1+1+1     twenty-one coins worth 1 each



1)
{1,33,90,91,92,93,94,95,96,97,98}
99

Returns: 12

In each step, the machine minimizes the number of coins it throws out, not the number of steps you need to accomplish your task. In the first step it will output a coin worth 98 and a coin worth 1.

2)
{1,30,60}
50

Returns: 2

The value of the banknote may be less than the values of some coin types.

3)
{1,30,60,90}
60

Returns: 3

The value of the banknote may even be equal to the value of some coin type. Note that for any input the machine must always output at least two coins. Therefore if you throw in the banknote worth 60, you will get two coins worth 30 each.

4)
{1,8,9,11,12,100}
120

Returns: 37

In the first step the machine would output 100+12+8. (The combination 100+11+9 has the same number of coins, but 100+12+8 is lexicographically larger.)

*/
// END CUT HERE

#line 107 "ChangeOMatic.cpp"
#include <string>
#include <vector>
#include <queue>
// BEGIN CUT HERE
#include <iostream>
#include "cout.h"
// END CUT HERE
#include <sstream>
using namespace std;

template <typename T> T gcd(T m, T n)
{
  if (m == 0 || n == 0) return 0;
  if (m == 1 || n == 1) return 1;
  if (m == n) return m;
  while (1) {
	if (m == 0) return n; 
	if (n == 0) return m;
	if (m > n) m %= n; else n %= m;
  }
}
template <typename T> T lcm(T m, T n)
{
  if (m == 0 || n == 0) return 0;
  return (m / gcd(m,n)) * n;
}

class ChangeOMatic {
  int n;
  //  long long cn; // convert count
  vector<long long> ov;
  vector<int> times;
  /**
  long long curr_lcm(int since, long long limit)
  {
	long long lcm_ = 1;
	for (int i=since; i<n; i++) {
	  lcm_ = lcm(lcm_, ov[i]);
	  if (lcm_ > limit) break;
	}
// BEGIN CUT HERE
	//printf("LCM [%lld..%lld] = %lld\n", ov[since], ov[n-1], lcm_);
	vector<long long> pr(ov.begin()+since, ov.end());
	cout << "LCM of " << pr << " = " << lcm_ << endl;
// END CUT HERE
	return lcm_;
  }
  **/

  int max_under(long long v)
  {
	for (int i=0; i<n; i++) if (v >= ov[i]) return i;
	return n-1;
  }
  
  pair<long long,vector<long long> >
  dp(long long v, int since, long long limit)
  {
	for (int i=0; i<since; i++) printf("    "); printf(" >>>> ");
	printf("dp(v=%lld, since ov[%d]=%lld, limit=%lld)\n", v, since, ov[since], limit);
	// cout << " pat<orig> = " << pat << endl;
	// vector<long long> pat(n,0);

	vector<long long> pat(n,0);

	if (limit <= 0 || since == n - 1 || v < ov[n-2]) {
	  // printf("  v=%lld < ov[%d]=%lld; returning %lld\n", v, n-2, ov[n-2], limit);
	  // vector<long long> pat(n,0); //pat.begin(),pat.end());
	  pat[n-1] = v;
	  return make_pair(v, pat);
	}

	long long ov0 = ov[since];
	if (v % ov0 == 0) {
	  // vector<long long> pat(n,0);
	  pat[since] = v / ov0;
	  cout << " !! zero !! { " << v/ov0 << ", " << pat << " }" << endl;
	  return make_pair(v / ov0, pat);
	}

	//	  int since = 0;
	//	  for (int i=0; i<n; i++) if (ov[i] > v) since++;
	int min_at = 0;
	long long min_v = LONG_LONG_MAX;
	vector<long long> ref(n, -1);//LONG_LONG_MAX);
	ref[n-1] = v;
	// vector<long long> rv(n,0);
	for (int i=since; i<n-1; i++) {
	  long long refv = (v / ov[i]) + (v % ov[i]);
	  if (refv < min_v) {
		min_v = refv; min_at = i;

		for (int j=0; j<n; j++) pat[j] = 0;
		pat[i] = v / ov[i];
		pat[n-1] = v % ov[i];
	  }
	  ref[i] = refv;
	}
	// for (int i=since; i<n; i++) ref[i] = min(min_v,ref[i]);
	cout << "  ref: " << ref << ";  min=" << min_v << " at " << ov[min_at] << endl;
	cout << "  pat: " << pat << endl;
	// printf("v=%lld >= ov[%d] = %lld\n", v, since, ov[since]);
	// cout << "ref: " << ref << endl;

	long long min_retv = min(min_v, limit);
	bool found = false;
	vector<long long> pat_(n,0);
	for (long long rest=v%ov0,cnt=v/ov0; rest < v; rest+=ov0,cnt--) {
	  if (cnt > limit) continue;
	  printf("  calling dp, v = %lld, rest = %lld, ov0 = %lld, min_v = %lld, cnt = %lld\n", v, rest, ov0, min_v, cnt);
	  pair<long long, vector<long long> > r = dp(rest, max(since+1,max_under(rest)), min_v - cnt);
	  if (r.first < 0 || r.first > limit) continue;

	  long long v = cnt + r.first;
	  // cout << "  1) pat = " << pat << endl;
	  // cout << "  2) (car r) = " << r.first << ", (cdr r) = " << r.second << endl;
	  cout << "  v = " << cnt << " + " << r.first << " = " << v << ", min_retv = " << min_retv << endl;
	  if (v <= min_retv) {
		copy(r.second.begin(),r.second.end(), pat_.begin());
		pat_[since] += cnt;
		cout << "  3) pat = " << pat_ << endl;
		min_retv = v;
		found = true;
	  }
	  /*
	  printf(" :: (%lld *) %lld + dp(%lld, %d, %lld - %lld) = %lld\n",
			 ov0, cnt,
			 rest, max(since+1,max_under(rest)), min_v, cnt,
			 v);
	  */
	}
	//	for (int j=since+1; j<n-1; j++) {
	int j = since + 1;
	pair<long long, vector<long long> > r = dp(v, j, min_v);
	if (v <= min_retv) {
	  copy(r.second.begin(),r.second.end(), pat_.begin());
	  // rv[since+1] += cnt;
	  // pat_[j] += 0;
	  cout << "  3A) pat = " << pat_ << endl;
	  min_retv = v;
	  // return make_pair(min_retv, pat);
	  // found = true;
	}
	//	}

	if (found) {
	  copy(pat_.begin(),pat_.end(), pat.begin());
	  cout << "min_retv = " << min_retv << ", pat = " << pat << endl;
	  return make_pair(min_retv, pat);
	} else {
	  return make_pair(-1, pat);
	}
	
	// cout << "return { " << min_retv << ", " << rv << " }\n";
  }

public:
  long long howManyRounds(vector<int> outputValues, long long inputValue) {
// BEGIN CUT HERE
//	cout << "outputValues: " << outputValues << endl;
	cout << "inputValue: " << inputValue << endl;
// END CUT HERE
	ov.clear();
	for (int i=outputValues.size()-1; i>=0; i--) {
	  long long ovll = outputValues[i];
	  if (ovll < inputValue) ov.push_back(ovll);
	  // reverse_copy(outputValues.begin(), outputValues.end(), ov.begin());
	}
	n = ov.size();

	// それぞれのコインが１枚与えられた場合に、何回の両替で終わるか数えておく
	times.resize(n);
	times[n-1] = 0; times[n-2] = 1;

	cout << "coins: " << ov << endl;

	int since = 0;
	for (int i=0; i<n; i++) if (ov[i] > inputValue) since++;
	
	// cout << "::" <<  dp(inputValue, since, 0) << endl;
	vector<long long> pat(n,0);
	long long iv = inputValue, cnt = 0, mag = 1;
	// int safelock = 0;
	while (1) {
	  printf("LOOP rv = %lld * dp(inv=%lld, since=%d, ", mag, iv, since);
	  cout << pat;
	  printf(", limit=%lld\n", iv);

	  // vector<long long> p0(n,0);
	  pair<long long,vector<long long> > rv = dp(iv, since, /*p0,*/ iv);
	  cout << "returns: { " << rv.first << ", " << rv.second << " }\n";
	  cnt += mag;// * rv.first;
	  if (rv.second[n-1] == inputValue) return cnt;

	  for (int i=since; i<n; i++) pat[i] += rv.second[i] * mag;
	  cout << " => pat = " << pat << ", cnt = " << cnt << endl;

	  // copy(rv.second.begin(),rv.second.end(), pat.begin());
	  mag = 0;
	  for (int i=0; i<n-1; i++) {
		if (pat[i] > 0) {
		  mag = pat[i];
		  iv = ov[i];
		  since = i+1;
		  pat[i] = 0;
		  break;
		}
	  }

	  if (mag == 0) return cnt;
	}
  }
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) {
	  if ((Case == -1) || (Case == 0)) test_case_0();
	  if ((Case == -1) || (Case == 1)) test_case_1();
	  if ((Case == -1) || (Case == 2)) test_case_2();
	  if ((Case == -1) || (Case == 3)) test_case_3();
	  if ((Case == -1) || (Case == 4)) test_case_4();

	  if ((Case == -1) || (Case == 11)) test_case_11();
	  if ((Case == -1) || (Case == 12)) test_case_12();
	  if ((Case == -1) || (Case == 13)) test_case_13();
	  if ((Case == -1) || (Case == 20)) test_case_20();

	  // if ((Case == -1) || (Case == 101)) test_case_101();
	  // if ((Case == -1) || (Case == 102)) test_case_102();
	  // if ((Case == -1) || (Case == 103)) test_case_103();
	  // if ((Case == -1) || (Case == 104)) test_case_104();
	}
private:
  template <typename T> string print_array(const vector<T> &V) {
	ostringstream os;
	os << "{ ";
	for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter)
	  os << '\"' << *iter << "\","; os << " }";
	return os.str();
  }

  void verify_case(int Case, const long long &Expected, const long long &Received) {
	cerr << "Test Case #" << Case << "...";
	if (Expected == Received) cerr << "PASSED" << endl;
	else {
	  cerr << "FAILED" << endl;
	  cerr << "\tExpected: \"" << Expected << '\"' << endl;
	  cerr << "\tReceived: \"" << Received << '\"' << endl;
	}
  }

  void test_case_0() { int Arr0[] = {1,5,10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 21LL; long long Arg2 = 7LL; verify_case(0, Arg2, howManyRounds(Arg0, Arg1)); }
  void test_case_1() { int Arr0[] = {1,33,90,91,92,93,94,95,96,97,98}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 99LL; long long Arg2 = 12LL; verify_case(1, Arg2, howManyRounds(Arg0, Arg1)); }
  void test_case_2() { int Arr0[] = {1,30,60}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 50LL; long long Arg2 = 2LL; verify_case(2, Arg2, howManyRounds(Arg0, Arg1)); }
  void test_case_3() { int Arr0[] = {1,30,60,90}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 60LL; long long Arg2 = 3LL; verify_case(3, Arg2, howManyRounds(Arg0, Arg1)); }
  void test_case_4() { int Arr0[] = {1,8,9,11,12,100}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 120LL; long long Arg2 = 37LL; verify_case(4, Arg2, howManyRounds(Arg0, Arg1)); }

  void test_case_11() {
	int Arr0[] = {1, 302, 402, 595, 596, 597, 598, 599, 600, 601, 602};
	vector<int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
	long long Arg1 = 6026026021206LL;
	long long Arg2 = 100100100013LL;
	verify_case(11, Arg2, howManyRounds(Arg0, Arg1));
  }
  void test_case_12() {
	int Arr0[] = {1, 999, 1000};
	vector<int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
	long long Arg1 = 997002LL;
	long long Arg2 = 999LL;
	verify_case(12, Arg2, howManyRounds(Arg0, Arg1));
  }
  void test_case_13() {
	int Arr0[] = {1, 999, 1000};
	vector<int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
	long long Arg1 = 999999999997002LL;
	long long Arg2 = 1999999998999LL;
	verify_case(13, Arg2, howManyRounds(Arg0, Arg1));
  }
  void test_case_20() {
	int Arr0[] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1000};
	vector<int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
	long long Arg1 = 987658765498765LL;
	long long Arg2 = 982720471671273LL;
	verify_case(20, Arg2, howManyRounds(Arg0, Arg1));
  }
  
  void test_case_101() {
	int Arr0[] = {1,8,9,11,12,100};
	vector<int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
	long long Arg1 = 1000000000000000LL;
	long long Arg2 = 311LL;
	verify_case(101, Arg2, howManyRounds(Arg0, Arg1));
  }
  void test_case_102() {
	int Arr0[] = {1,8,9,11,12,100};
	vector<int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
	long long Arg1 = 2LL;
	long long Arg2 = 1LL;
	verify_case(102, Arg2, howManyRounds(Arg0, Arg1));
  }
  void test_case_103() {
	int Arr0[] = {1,2,3,4,5,6,7,8,9,10,
				  11,12,13,14,15,16,17,18,19,20,
				  21,22,23,24,25,26,27,28,29,30,
				  31,32,33,34,35,36,37,38,39,40,
				  41,42,43,44,45,46,47,48,49,50};
	vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
	long long Arg1 = 1000000000LL;
	long long Arg2 = 980000001LL;
	verify_case(103, Arg2, howManyRounds(Arg0, Arg1));
  }
  void test_case_104() {
	int Arr0[] = {1,2,3,5,10,20,50,100,200,500,1000};
	vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
	long long Arg1 = 10000LL;
	long long Arg2 = 9771LL;
	verify_case(104, Arg2, howManyRounds(Arg0, Arg1));
  }

// END CUT HERE

};

// BEGIN CUT HERE
int main(int argc,char *argv[]) {
	ChangeOMatic ___test;
	___test.run_test(argc>=2 ? atoi(argv[1]):-1);
}
// END CUT HERE
