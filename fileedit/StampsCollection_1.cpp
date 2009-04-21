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
public:
  int sell(int n, vector<string> demand, vector<int> price) {
    // n[1..50] stamps : [0 .. n-1],
    // demand[i] 1..50 elements, 0..n-1 [space 0..n-1]
    // price: 1..1000000
    int buyers = demand.size();
    vector<bool> sold_out(n);
    int amount = 0;
    tr(sold_out,it) *it = false;

    vector< vector<pair<double,int> > > candidates(n);
    vector< pair<double,pair<int,vector<int> > > > demand_(buyers);
    for (int i=0; i<buyers; i++) {
      vector<int> buyer_wants = map_atoi( split(demand[i]) );
      int total_price = price[i];
      double unit_price = 1.0 * total_price / buyer_wants.size();
      
      tr(buyer_wants,it) candidates[*it].push_back( make_pair(-unit_price, i) );
      
      demand_[i] = make_pair( -unit_price,
                              make_pair( total_price, buyer_wants ));
    }
    sort(demand_.begin(), demand_.end());
    // cout << demand_ << endl;
    tr(candidates,it) sort(it->begin(), it->end());
    cout << candidates << endl;
    
    tr(demand_,it) {
      vector<int> buyer_wants = it->second.second;
      bool sellable = true;
      tr(buyer_wants,jt) {
        if (sold_out[*jt]) { sellable = false; break; }
      }
      if (sellable) {
        amount += it->second.first;
        tr(buyer_wants,jt) sold_out[*jt] = true;
      }
    }
    return amount;
  }
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) {
	  if ((Case == -1) || (Case == 0)) test_case_0();
	  if ((Case == -1) || (Case == 1)) test_case_1();
	  if ((Case == -1) || (Case == 2)) test_case_2();
	  if ((Case == -1) || (Case == 3)) test_case_3();
	  if ((Case == -1) || (Case == 4)) test_case_4();
	  if ((Case == -1) || (Case == 5)) test_case_5();
	}
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 10; string Arr1[] = {"0 4"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {3}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 3; verify_case(0, Arg3, sell(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 2; string Arr1[] = {"1 0","0"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {3,5}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 5; verify_case(1, Arg3, sell(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 3; string Arr1[] = {"0 1","0 2","1 2"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {10,11,12}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 12; verify_case(2, Arg3, sell(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 3; string Arr1[] = {"0","1 0","1 2"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {5,9,5}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 10; verify_case(3, Arg3, sell(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 20; string Arr1[] = {"0 1","1 2","2 3","3 0","4 5","5 6","6 4","8","8","9","9 10","10 11","11 12","12"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {3,7,4,1,3,3,1,5,6,5,18,10,1,5}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 40; verify_case(4, Arg3, sell(Arg0, Arg1, Arg2)); }
  void test_case_5() {
	int Arg0 = 7;
	string Arr1[] = {"0 1", "1 2", "2 3", "3 4", "4 5", "5 6", "6 0"}; 
	vector<string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
	int Arr2[] = {100, 61, 10, 10, 10, 10, 50}; 
	vector<int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
	int Arg3 = 121;
	verify_case(5, Arg3, sell(Arg0, Arg1, Arg2));
  }


// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	StampsCollection ___test;
	___test.run_test(-1);
}
// END CUT HERE
