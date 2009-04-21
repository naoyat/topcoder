// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// You have decided to sell your stamp collection, which consists of n stamps numbered 0 to n-1.  You have already found some buyers.  The i-th buyer wants to buy the stamps listed in demand[i].  This will be a space-separated list containing either one or two stamps.  He is willing to pay a total of price[i].  If he wants to buy two stamps, he will not agree to buy only one of them.

To make this task simpler, for each stamp, there will be no more than two buyers who want to buy it.  Return the maximum amount of money you can get from selling your stamps.

DEFINITION
Class:StampsCollection
Method:sell
Parameters:int, vector <string>, vector <int>
Returns:int
Method signature:int sell(int n, vector <string> demand, vector <int> price)


NOTES
-You don't have to sell all of your stamps.


CONSTRAINTS
-n will be between 1 and 50, inclusive.
-demand will contain between 1 and 50 elements, inclusive.
-price will contain the same number of elements as demand.
-Each element of demand will be a space-separated list of one or two distinct integers.
-All numbers in demand will be between 0 and n-1, inclusive, with no leading zeroes.
-All numbers in price will be between 1 and 1000000, inclusive.
-For each stamp, there will be at most 2 buyers who want to buy it.


EXAMPLES

0)
10
{"0 4"}
{3}

Returns: 3

There is only one buyer, so all we can do is to sell two stamps.

1)
2
{"1 0","0"}
{3,5}

Returns: 5

There are two buyers, but both want to buy stamp 0. 

2)
3
{"0 1","0 2","1 2"}
{10,11,12}

Returns: 12

Only one buyer can get what he wants - we choose the third one, who is willing to pay the most.

3)
3
{"0","1 0","1 2"}
{5,9,5}

Returns: 10

Although the second buyer will pay the most, it is better to choose the first and third buyers.

4)
20
{"0 1","1 2","2 3","3 0","4 5","5 6","6 4","8","8","9","9 10","10 11","11 12","12"}
{3,7,4,1,3,3,1,5,6,5,18,10,1,5}

Returns: 40



*/
// END CUT HERE

#line 81 "StampsCollection.cpp"
#include <string>
#include <vector>
#include <deque>
#include <map>
// BEGIN CUT HERE
#include <iostream>
#include "cout.h"
// END CUT HERE
#include <sstream>
using namespace std;

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

class StampsCollection {
  map<long long,int> m;

private:
  //  int sub(vector< pair<int,long long> > price_and_mask, int sum) {//, int cut=0) {
  int sub(deque<pair<int,pair<long long, long long> > > price_and_mask, long long signature, int sum) {//, int cut=0) {
    int size = price_and_mask.size();
    if (size == 0) return 0;
    if (size == 1) return -(price_and_mask.front().first);
    if (m.find( signature ) != m.end()) return m[ signature ];

    // take #0
    long long sold_out = price_and_mask.front().second.second;
    deque< pair<int,pair<long long, long long> > > price_sub1;
    long long new_signature = 0;
    int sum1 = 0;
    tr(price_and_mask,it) {
      if ((sold_out & it->second.second) == 0) {
        price_sub1.push_back( *it );
        new_signature |= it->second.first;
        sum1 -= it->first;
      }
    }
    int amount1 = - price_and_mask.front().first + sub(price_sub1, new_signature, sum1);

    // don't take #0
    sum -= price_and_mask.front().first;
    if (sum < amount1) {
      m[ signature ] = amount1;
      return amount1;
    } 

    new_signature = signature - price_and_mask.front().second.first;
    price_and_mask.pop_front();
    int amount = max(amount1, sub(price_and_mask, new_signature, sum));
    m[ signature ] = amount;
    return amount;
  }

public:
  int sell(int n, vector<string> demand, vector<int> price) {
    m.clear();
    // n[1..50] stamps : [0 .. n-1],
      // demand[i] 1..50 elements, 0..n-1 [space 0..n-1]
      // price: 1..1000000
    long long n_mask = ((long long)1 << n) - 1;

    int buyers_cnt = demand.size();
    long long signature = ((long long)1 << buyers_cnt) - 1;
    vector< pair<int,pair<long long,long long> > > price_and_mask_v(buyers_cnt);
    int sum = 0;
    for (int i=0; i<buyers_cnt; i++) {
      vector<int> demand_i = map_atoi( split(demand[i]) );
      long long mask = 0;
      tr(demand_i,it) mask |= ((long long)1 << *it);
      mask &= n_mask;
      price_and_mask_v[i] = make_pair(-price[i], make_pair((long long)1 << i, mask));
      sum += price[i];
    }
    sort(price_and_mask_v.begin(), price_and_mask_v.end());
    deque< pair<int,pair<long long, long long> > > price_and_mask(price_and_mask_v.begin(), price_and_mask_v.end());
    
    return sub(price_and_mask,signature,sum);
  }
    
// BEGIN CUT HERE
    public:
    void run_test(int Case) {
      if ((Case == -1) || (Case == 0)) test_case_0();
      if ((Case == -1) || (Case == 1)) test_case_1();
      if ((Case == -1) || (Case == 2)) test_case_2();
      if ((Case == -1) || (Case == 3)) test_case_3();
      if ((Case == -1) || (Case == 4)) test_case_4();

	  if ((Case == -1) || (Case == 6)) test_case_6();
	  if ((Case == -1) || (Case == 8)) test_case_8();
	  if ((Case == -1) || (Case == 11)) test_case_11();
	  if ((Case == -1) || (Case == 22)) test_case_22();
	  if ((Case == -1) || (Case == 22)) test_case_31();
      //*/
    }

private:
  template <typename T> string print_array(const vector<T> &V) {
	ostringstream os;
	os << "{ ";
	for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\",";
	os << " }";
	return os.str(); }

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
  void verify_case(int Case, const int &Expected, const int &Received) {
	cerr << "Test Case #" << Case << "...";
	if (Expected == Received)
	  cerr << "PASSED" << timer() << endl;
	else {
	  cerr << "FAILED" << timer() << endl;
	  cerr << "\tExpected: \"" << Expected << '\"' << endl;
	  cerr << "\tReceived: \"" << Received << '\"' << endl;
	}
  }

  void test_case_0() {
	timer_clear();
	int Arg0 = 10; string Arr1[] = {"0 4"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {3}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 3; verify_case(0, Arg3, sell(Arg0, Arg1, Arg2)); }
  void test_case_1() {
	timer_clear();
	int Arg0 = 2; string Arr1[] = {"1 0","0"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {3,5}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 5; verify_case(1, Arg3, sell(Arg0, Arg1, Arg2)); }
  void test_case_2() {
	timer_clear();
	int Arg0 = 3; string Arr1[] = {"0 1","0 2","1 2"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {10,11,12}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 12; verify_case(2, Arg3, sell(Arg0, Arg1, Arg2)); }
  void test_case_3() {
	timer_clear();
	int Arg0 = 3; string Arr1[] = {"0","1 0","1 2"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {5,9,5}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 10; verify_case(3, Arg3, sell(Arg0, Arg1, Arg2)); }
  void test_case_4() {
	timer_clear();
	int Arg0 = 20; string Arr1[] = {"0 1","1 2","2 3","3 0","4 5","5 6","6 4","8","8","9","9 10","10 11","11 12","12"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {3,7,4,1,3,3,1,5,6,5,18,10,1,5}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 40; verify_case(4, Arg3, sell(Arg0, Arg1, Arg2)); }

  void test_case_6() {
	timer_clear();
	int Arg0 = 25;
	string Arr1 [] = {"0", "0", "1", "1", "2", "2", "3", "3", "4", "4", "5", "5", "6", "6", "7", "7", "8", "8", "9", "9", "10", "10", "11", "11", "12", "12", "13", "13", "14", "14", "15", "15", "16", "16", "17", "17", "18", "18", "19", "19", "20", "20", "21", "21", "22", "22", "23", "23", "24", "24"};
	vector<string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
	int Arr2[] = {100, 99, 100, 99, 100, 99, 100, 99, 100, 99, 100, 99, 100, 99, 100, 99, 100, 99, 100, 99, 100, 99, 100, 99, 100, 99, 100, 99, 100, 99, 100, 99, 100, 99, 100, 99, 100, 99, 100, 99, 100, 99, 100, 99, 100, 99, 100, 99, 100, 99};
	vector<int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
	int Arg3 = 2500;
	verify_case(6, Arg3, sell(Arg0, Arg1, Arg2));
  }
  void test_case_8() {
	timer_clear();
	int Arg0 = 7;
	string Arr1[] = {"0 1", "1 2", "2 3", "3 4", "4 5", "5 6", "6 0"}; 
	vector<string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
	int Arr2[] = {100, 61, 10, 10, 10, 10, 50}; 
	vector<int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
	int Arg3 = 121;
	verify_case(8, Arg3, sell(Arg0, Arg1, Arg2));
  }
  void test_case_11() {
	timer_clear();
	int Arg0 = 50;
	string Arr1[] = {"0", "1", "1", "2", "2 3", "3", "4", "4 5", "5 6", "6", "7", "7 8", "8 9", "9 10", "10", "11", "11 12", "12 13", "13 14", "14 15", "15", "16", "16 17", "17 18", "18 19"};
	vector<string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
	int Arr2[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
	vector<int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
	int Arg3 = 14;
	verify_case(11, Arg3, sell(Arg0, Arg1, Arg2));
  }
  void test_case_22() {
	timer_clear();
	int Arg0 = 50;
	string Arr1[] = {"31 14", "47 9", "24 18", "22 20", "45 49", "28 7", "41 44", "35", "29 19", "32 36", "40 18", "32 15", "42 41", "26 13", "49 10", "3 42", "12 28", "6", "43 33", "14", "40 12", "26 46", "31 39", "45 15", "16", "5 34", "46 7", "5 3", "34 20", "23 29", "9 10", "6 13", "27 22", "25 30", "17 0", "38 47", "33 19", "17 48", "4 2", "44 27", "30 16", "4 35", "25 36", "24 8", "21 0", "39 38", "8 43", "11", "21 23", "48 37"};
	vector<string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
	int Arr2[] = {1, 4, 3, 2, 1, 4, 3, 1, 4, 4, 5, 4, 1, 1, 3, 5, 3, 3, 3, 4, 2, 1, 5, 4, 4, 5, 4, 1, 5, 1, 3, 1, 1, 2, 2, 2, 1, 2, 4, 1, 5, 3, 4, 3, 5, 1, 4, 2, 5, 2};
	vector<int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
	int Arg3 = 87;
	verify_case(22, Arg3, sell(Arg0, Arg1, Arg2));
  }
  void test_case_31() {
	timer_clear();
	int Arg0 = 50;
	string Arr1[] = {"46 8", "28 37", "1 0", "42 34", "14 8", "7 16", "4 42", "32 43", "9 46", "16 26", "12 35", "43 22", "48 47", "41 31", "7 41", "15 10", "21 2", "3 47", "14 30", "26", "45 40", "29 36", "27 35", "20 17", "30 10", "45", "20 39", "22 19", "38", "15 44", "37 5", "44 34", "25 13", "31 36", "33 11", "9 32", "4 27", "39", "33 1", "17 18", "0 28", "13 12", "5 21", "19 18", "48 3", "6 25", "40 11", "49 29", "49 23", "24 2"};
	vector<string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
	int Arr2[] = {4, 2, 2, 4, 1, 2, 4, 3, 3, 5, 5, 2, 5, 2, 5, 5, 2, 3, 5, 2, 5, 1, 3, 3, 2, 4, 3, 5, 1, 2, 2, 1, 5, 5, 4, 3, 1, 2, 5, 5, 3, 1, 2, 4, 2, 1, 3, 1, 5, 4};
	int Arg3 = 92;
	vector<int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
	verify_case(31, Arg3, sell(Arg0, Arg1, Arg2));
  }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	StampsCollection ___test;
	___test.run_test(-1);
}
// END CUT HERE
