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

  vector<long long> change(long long iv, int since)
  {
// BEGIN CUT HERE
	printf("%lld => ", iv);
// END CUT HERE
	int least_at = -1;
	long long least_count = LONG_LONG_MAX;//0x7fffffffffffffffLL;

	if (since == n-1) {
	  vector<long long> pat(n,0); pat[n-1] = iv;
// BEGIN CUT HERE
	  cout << "since = 1; " << pat << endl;
// END CUT HERE
	  return pat;
	}

	vector<vector<long long> > pats(n);
	for (int i=since; i<n; i++) {
	  pats[i].resize(n); for (int j=0;j<n;j++) pats[i][j] = 0LL;
	  // [since .. n-1] でできるペア
	  int max_at = n-1;
	  long long v = iv, lim = ov[i];
	  long long cnt = 0;
	  while (v > 0) {
		for (int j=i; j<n; j++) if (ov[j] <= lim) { max_at = j; break; }
		cnt += pats[i][max_at] = v / ov[max_at];
		v %= ov[max_at];
		lim = min(v,lim);
	  }
	  if (cnt < least_count) { least_at = i; least_count = cnt; }
	}
// BEGIN CUT HERE
	cout << "least count " << least_count << " at " << ov[least_at] << ", " << pats[least_at] << endl;
// END CUT HERE
	vector<long long> maxc(n,0);
	for (int i=0; i<n-1; i++) {
	  maxc[i] = min(least_count, iv / ov[i]);
	}
// BEGIN CUT HERE
	cout << "  // maxc for " << iv << ": " << maxc << endl;
	cout << "since " << since << " ... " << endl;
	// (-count, ( list, ( head, rest ) ) )
// END CUT HERE
	priority_queue<pair<long long,pair<vector<long long>,pair<int,long long> > > > pq;

	long long count = 0LL;
	vector<long long> ini(n, 0LL);
	long long cl = curr_lcm(0, INT_MAX);
// BEGIN CUT HERE
	// cout << "LCM= " << curr_lcm(0, INT_MAX) << endl;
// END CUT HERE
	if (iv > cl) {
	  long long mag = iv / cl;
	  long long u0 = cl / ov[0];
	  ini[0] += mag * u0;
	  count++;
	  iv %= cl;
	}
	pq.push(make_pair(-count, make_pair(ini, make_pair(-since, iv))));

	while (!pq.empty()) {
// BEGIN CUT HERE
	  // cnt,lis,head,rest = pq.top();
// END CUT HERE
	  long long cnt = -pq.top().first;
	  vector<long long> lis = pq.top().second.first;
	  int head = -pq.top().second.second.first;
	  long long rest = pq.top().second.second.second;
	  pq.pop();
// BEGIN CUT HERE
	  cout << "  >pop> cnt=" << cnt << ", lis=" << lis << ", head=" << head << ", rest=" << rest << endl;
// END CUT HERE

	  if (rest == 0) {
// BEGIN CUT HERE
		cout << "  lis = " << lis << endl;
// END CUT HERE
		return lis;
	  }

	  while (head < n-1 && rest < ov[head]) head++;
	  if (head >= n) continue;

	  long long k = rest / ov[head];
	  for (long long j=k; j>=0; j--) {
		vector<long long> next(lis.begin(),lis.end());
		next[head] = j;
		pq.push(make_pair(-cnt-j, make_pair(next, make_pair(-head-1, rest-ov[head]*j ))));
// BEGIN CUT HERE
		/// cout << "  <push< cnt=" << cnt+j << ", lis=" << next << ", head=" << head+1 << ", rest=" << rest-ov[head]*j << endl;
// END CUT HERE
	  }
	}
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

	for (int i=n-3; i>=0; i--) {
// BEGIN CUT HERE
	  printf("countRounds(%d, since %d)\n", ov[i]);
// END CUT HERE
	  vector<long long> changed = change(ov[i], i+1);
	  int rounds = 1;
	  for (int j=i+1; j<n-1; j++) rounds += changed[j] * times[j];
	  times[i] = rounds;
	}

// BEGIN CUT HERE
	cout << "coins: " << ov << endl;
	cout << "times: " << times << endl;
// END CUT HERE

	long long rounds = 1;

	vector<long long> changed = change(inputValue, 0);
	for (int j=0; j<n-1; j++) rounds += changed[j] * times[j];
	return rounds;
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
