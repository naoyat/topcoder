#line 2 "VendingMachine.cpp"
// med600 / 218.51
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <cctype>
#include <algorithm>
#include <string>
#include <vector>
#include <deque>
#include <stack>
#include <queue>
#include <list>
#include <map>
#include <set>
// BEGIN CUT HERE
#include "cout.h"
// END CUT HERE
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<string> vs;
typedef vector<long long> vll;
#define sz(a)  int((a).size())
#define pb  push_back
#define all(c)  (c).begin(),(c).end()
#define tr(c,i)  for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); i++)
#define rep(var,n)  for(int var=0;var<(n);var++)
#define FOR(var,from,to) for(int var=(from);var<=(to);var++)
#define RFOR(var,from,to) for(int var=(to);var>=(from);var--)
#define found(s,e)  ((s).find(e)!=(s).end())
#define mset(arr,val)  memset(arr,val,sizeof(arr))
#define remove_(c,val) (c).erase(remove((c).begin(),(c).end(),(val)),(c).end())
#define lastc(str) (*((str).end()-1))

typedef pair<int,int> i_i;
typedef pair<ll,ll> ll_ll;
typedef pair<double,double> d_d;
typedef pair<int,pair<int,int> > i_ii;
#define cons(x,y) make_pair((x),(y))
#define car(x) ((x).first)
#define cdr(x) ((x).second)
#define cadr(x) (x).second.first
#define cddr(x) (x).second.second

vector<string> split(string str, int delim=' ')
{
  vector<string> result;

  const char *s = str.c_str();
  if (delim == ' ') {
    for (const char *p=s; *p; p++) {
      if (*p == delim) s++;
      else break;
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

int stoi(string s){ return atoi(s.c_str()); }

// BEGIN CUT HERE
/**
template <typename T> int max_at(vector<T>::forward_iterator begin, vector<T>::forward_iterator end)
{
  T max_val=*begin; int max_at_index=0;
  //  for (unsigned int i=1;i<sz(vec);i++) {
  for (vector<T>::iterator it=begin; it!=end; it++) {
    if (*it > max_val) { max_val = *it; max_at_index = it - begin; }
  }
  cout << "max_at( " << vector<T>(begin,end) << " ) = " << max_at_index << endl;
  return max_at_index;
}
**/
//////////
// END CUT HERE
class VendingMachine {
 public:
  int motorUse(vector <string> prices, vector <string> purchases) {
// BEGIN CUT HERE
    cout << "motorUse(" << prices << ", " << purchases << ")..." << endl;
// END CUT HERE
    int n_shelves=sz(prices), n_columns;
// BEGIN CUT HERE
    //printf("%d shelve, %d columns\n", n_shelves, n_columns);
// END CUT HERE
    vector<vector<int> > table(n_shelves);
    vector<int> pricesum;
    rep(sh,n_shelves){
      table[sh] = map_atoi(split(prices[sh])); // sh[i][s>=3] : 1..10000
      if (sh==0) {
        n_columns = sz(table[sh]);
        pricesum.resize(n_columns); rep(i,n_columns) pricesum[i]=0;
      }
// BEGIN CUT HERE
      cout << sh << " : " << table[sh] << endl;
// END CUT HERE
      rep(col,n_columns) pricesum[col] += table[sh][col];
    }

    int motorrun = 0;
    int last_t = 0;

    // autorot
    int curr_col = 0, new_col, diff;

    {
// BEGIN CUT HERE
      //new_col = max_at(all(pricesum));
      cout << "    pricesum: " << pricesum << endl;
// END CUT HERE
      vector<int>::iterator max_at = max_element(all(pricesum));
      new_col = max_at - pricesum.begin();
      diff = abs(new_col - curr_col);
// BEGIN CUT HERE
      printf("    ! autorot at beginning %d -> %d; diff=%d\n",
             curr_col, new_col,
             min(diff, n_columns-diff) );
// END CUT HERE
      motorrun += min(diff, n_columns-diff);
      curr_col = new_col;
    }

    set<i_i> boughts;
    rep(i,sz(purchases)){
      vector<string> a1 = split(purchases[i],':'), a0 = split(a1[0],',');
      int shelf=stoi(a0[0]), column=stoi(a0[1]), time=stoi(a1[1]);

      int lapse = time - last_t;
      if (lapse>=5) {
        // autorot at last_t
        vector<int>::iterator max_at = max_element(all(pricesum));
        new_col = max_at - pricesum.begin();
        diff = abs(new_col - curr_col);
// BEGIN CUT HERE
        printf("    ! autorot at t=%d, %d -> %d; diff=%d\n",
               last_t,
               curr_col, new_col,
               min(diff, n_columns-diff));
// END CUT HERE
        motorrun += min(diff, n_columns-diff);
        curr_col = new_col;
      }
// BEGIN CUT HERE
      printf("    purchasing (shelf %d, col %d) at t=%d\n", shelf,column,time);
// END CUT HERE
      {
        new_col = column;
        diff = abs(new_col - curr_col);
// BEGIN CUT HERE
        printf("    rot %d -> %d, diff=%d\n", curr_col, new_col, min(diff, n_columns-diff));
// END CUT HERE
        motorrun += min(diff, n_columns-diff);
        curr_col = new_col;
      }
      
      i_i key = cons(shelf,column);
      if (found(boughts,key)) return -1;
      boughts.insert(key);

      pricesum[column] -= table[shelf][column];
      table[shelf][column] = 0;
      
      last_t = time;
    }

    // last autorot
    {
      vector<int>::iterator max_at = max_element(all(pricesum));
      new_col = max_at - pricesum.begin();
      diff = abs(new_col - curr_col);
// BEGIN CUT HERE
      printf("    ! autorot at last, %d -> %d; diff=%d\n",
             curr_col, new_col,
             min(diff, n_columns-diff));
// END CUT HERE
      motorrun += min(diff, n_columns-diff);
      curr_col = new_col;
    }

// BEGIN CUT HERE
    printf("  => total motor run: %d\n", motorrun);
// END CUT HERE
    return motorrun;
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
	string prices_[] = {"100 100 100"};
	  vector <string> prices(prices_, prices_+sizeof(prices_)/sizeof(*prices_)); 
	string purchases_[] = {"0,0:0", "0,2:5", "0,1:10"};
	  vector <string> purchases(purchases_, purchases_+sizeof(purchases_)/sizeof(*purchases_)); 
	int RetVal = 4; 
	return verify_case(RetVal, VendingMachine().motorUse(prices, purchases)); }
int Test_(Case_<1>) {
	timer_clear();
	string prices_[] = {"100 200 300 400 500 600"};
	  vector <string> prices(prices_, prices_+sizeof(prices_)/sizeof(*prices_)); 
	string purchases_[] = {"0,2:0", "0,3:5", "0,1:10", "0,4:15"};
	  vector <string> purchases(purchases_, purchases_+sizeof(purchases_)/sizeof(*purchases_)); 
	int RetVal = 17; 
	return verify_case(RetVal, VendingMachine().motorUse(prices, purchases)); }
int Test_(Case_<2>) {
	timer_clear();
	string prices_[] = {"100 200 300 400 500 600"};
	  vector <string> prices(prices_, prices_+sizeof(prices_)/sizeof(*prices_)); 
	string purchases_[] = {"0,2:0", "0,3:4", "0,1:8", "0,4:12"};
	  vector <string> purchases(purchases_, purchases_+sizeof(purchases_)/sizeof(*purchases_)); 
	int RetVal = 11; 
	return verify_case(RetVal, VendingMachine().motorUse(prices, purchases)); }
int Test_(Case_<3>) {
	timer_clear();
	string prices_[] = {"100 100 100"};
	  vector <string> prices(prices_, prices_+sizeof(prices_)/sizeof(*prices_)); 
	string purchases_[] = {"0,0:10", "0,0:11"};
	  vector <string> purchases(purchases_, purchases_+sizeof(purchases_)/sizeof(*purchases_)); 
	int RetVal = -1; 
	return verify_case(RetVal, VendingMachine().motorUse(prices, purchases)); }
int Test_(Case_<4>) {
	timer_clear();
	string prices_[] = {"100 200 300",
 "600 500 400"};
	  vector <string> prices(prices_, prices_+sizeof(prices_)/sizeof(*prices_)); 
	string purchases_[] = {"0,0:0", "1,1:10", "1,2:20",
 "0,1:21", "1,0:22", "0,2:35"};
	  vector <string> purchases(purchases_, purchases_+sizeof(purchases_)/sizeof(*purchases_)); 
	int RetVal = 6; 
	return verify_case(RetVal, VendingMachine().motorUse(prices, purchases)); }

template<int N> void Run_() { cerr << "Test Case #" << N << "..." << flush; Test_(Case_<N>()); Run_<sizeof(Test_(Case_<N+1>()))==1 ? -1 : N+1>(); }
template<>      void Run_<-1>() {}
int main() { Run_<0>(); }
// END CUT HERE


// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
Note that in the following problem statement, all quotes and angle brackets are for clarity



A certain vending machine delves out its goods from a rotating cylinder, which can rotate around in both clockwise and counter-clockwise directions.  The cylinder has a number of shelves on it, and each shelf is divided into a number of columns.  On the front of the machine, there is a panel of doors that extends the entire height of the column.  There is one door for each shelf, which is the width of one column.  When a purchase is made, the user uses two buttons to rotate the cylinder so their purchase is located at a door.  They make their purchase by sliding the appropriate door open, and removing the item (there can only be one item per column on a particular shelf).  The cylinder can rotate in a complete circle, and so there are always two ways to get from a particular column to another column.



Because the vending machine company wants to sell the most expensive items possible, and the machine can only show one column at a time, the machine will always try to put forth the most expensive column available.  The price of a column is calculated by adding up all the prices of the remaining items in that column.  The most expensive column is defined to be the one with the maximum price.  If 5 minutes have elapsed since the last purchase was made, the machine rotates the cylinder to the most expensive column.  If, however, another purchase has been made before the 5 minutes are up, the rotation does not occur, and the 5 minute timer is reset.



Recently, some machines' rotating motors have been failing early, and the company wants to see if it is because the machines rotate to show their expensive column too often.  To determine this, they have hired you to simulate purchases and see how long the motor is running.



You will be given the prices of all the items in the vending machine in a vector <string>.  Each element of prices will be a single-space separated list of integers, which are the prices (in cents) of the items.  The Nth integer in the Mth element of prices represents the price of the Nth column in the Mth shelf in the cylinder.  You will also be given a vector <string> purchases.  Each element in purchases will be in the format: "<shelf>,<column>:<time>"
<shelf> is a 0-based integer which identifies the shelf that the item was purchased from.  <column> is a 0-based integer which identifies the column the item was purchased from.  <time> is an integer which represents the time, in minutes, since the machine was turned on.



In the simulation, the motor needs to run for 1 second in order to rotate to an adjacent column.  When the machine is turned on, column 0 is facing out, and it immediately rotates to the most expensive column, even if the first purchase is at time 0.  The machine also rotates to the most expensive column at the end of the simulation, after the last purchase.  Note that when an item is purchased, its price is no longer used in calculating the price of the column it is in.  When the machine rotates to the most expensive column, or when a user rotates the cylinder, the rotation is in the direction which takes the least amount of time.  For example, in a 4-column cylinder, if column 0 is displayed, and the cylinder is rotated to column 3, it can be rotated backwards, which takes 1 second, versus rotating forwards which takes 3 seconds.



If a user tries to purchase an item that was already purchased, this is an incorrect simulation, and your method should return -1.  Otherwise, your method should return how long the motor was running, in seconds.



DEFINITION
Class:VendingMachine
Method:motorUse
Parameters:vector <string>, vector <string>
Returns:int
Method signature:int motorUse(vector <string> prices, vector <string> purchases)


NOTES
-When rotating to the most expensive column, if two columns have the same price, rotate to the one with the lowest column number (see example 0).
-If two purchases are less than 5 minutes apart, the machine does not perform a rotation to the most expensive column between the purchases.  If two purchases are 5 or more minutes apart, the machine rotates to the most expensive column between the two purchases.


CONSTRAINTS
-prices will have between 1 and 50 elements, inclusive.
-Each element of prices will have between 5 and 50 characters, is a single-space separated list of integers, and has no leading or trailing spaces.
-Each element of prices will have the same number of integers in it.
-Each element of prices will have at least 3 integers in it.
-Each integer in prices will be between 1 and 10000, inclusive, and will not contain leading 0's.
-purchases will have between 1 and 50 elements, inclusive.
-Each element of purchases will be in the format "<shelf>,<column>:<time>" (angle brackets and quotes are for clarity only), where <shelf>, <column>, and <time> are all integers.
-In each element of purchases, <shelf> will be between 0 and M - 1, inclusive, where M is the number of elements in prices.
-In each element of purchases, <column> will be between 0 and N - 1, inclusive, where N is the number of integers in each element of prices.
-In each element of purchases, <time> will be between 0 and 1000, inclusive.
-In each element of purchases, <shelf>, <column>, and <time> will not contain extra leading 0's.
-purchases will be sorted in strictly ascending order by <time>.  This means that each purchase must occur later than all previous ones.


EXAMPLES

0)
{"100 100 100"}
{"0,0:0", "0,2:5", "0,1:10"}

Returns: 4


The vending machine has three columns, and only one row.  Since all three items are the same price, they are all the most expensive, and therefore, the lowest numbered column is rotated to.  Since the machine starts out at column 0, no rotation is performed before the first purchase.  The starting configuration is (*'s denote the currently displayed column):

 
+-----+-----+-----+
| 100 | 100 | 100 |
+*****+-----+-----+



In the first purchase, the customer does not rotate the cylinder because the item he wants is already displayed. The configuration of the vending machine is now:


+-----+-----+-----+
|  0  | 100 | 100 |
+*****+-----+-----+


Since the next purchase is at least 5 minutes away, the machine performs a rotation to the most expensive column.  Both column 1 and 2 are now 100 apiece, so it rotates to the smallest index of these, column 1.  The fastest way there is to rotate forward 1 column, yielding 1 second of motor use:


+-----+-----+-----+
|  0  | 100 | 100 |
+-----+*****+-----+



The next customer purchases the item in column 2, which is 1 column away, so add 1 second to the motor use.  Because another 5 minutes passes, the most expensive column is displayed, which is now column 1.  Add 1 more second for the rotation.  The configuration is now:


+-----+-----+-----+
|  0  | 100 |  0  |
+-----+*****+-----+



The final customer purchases from column 1, (which is already displayed), and the final most expensive column is rotated to.  Since all columns are the same price again (0), column 0 is displayed.  It takes 1 second to get back there, so add 1 more second.


1)
{"100 200 300 400 500 600"}
{"0,2:0", "0,3:5", "0,1:10", "0,4:15"}

Returns: 17


The most expensive column during this whole example is column 5.  Since all purchases are at least 5 minutes apart, the most expensive column is rotated to each time.



Before the purchases start, add 1 second for rotating to column 5.
The first purchase  is 3 columns away, so add 3 seconds to get there, and 3 seconds to get back to column 5
The second purchase is 2 columns away, so add 4 seconds to get there and back.
The third purchase is also 2 columns away, so add 4 more seconds.
The final purchase is only one column away, so add 2 more seconds.



The final configuration is:


+-----+-----+-----+-----+-----+-----+
| 100 |  0  |  0  |  0  |  0  | 600 |
+-----+-----+-----+-----+-----+*****+



2)
{"100 200 300 400 500 600"}
{"0,2:0", "0,3:4", "0,1:8", "0,4:12"}

Returns: 11


This is the same as example 1, except now, the purchases are all less than 5 minutes apart.


3)
{"100 100 100"}
{"0,0:10", "0,0:11"}

Returns: -1


The second purchase is illegal since the item was already purchased


4)
{"100 200 300",
 "600 500 400"}
{"0,0:0", "1,1:10", "1,2:20",
 "0,1:21", "1,0:22", "0,2:35"}

Returns: 6


A two-row example.  The configurations just before each purchase are:


purchase 1:
+-----+-----+-----+
| 100 | 200 | 300 |
+-----+-----+-----+
| 600 | 500 | 400 |
+*****+-----+-----+

purchase 2:
+-----+-----+-----+
|  0  | 200 | 300 |
+-----+-----+-----+
| 600 | 500 | 400 |
+-----+*****+-----+

purchase 3:
+-----+-----+-----+
|  0  | 200 | 300 |
+-----+-----+-----+
| 600 |  0  | 400 |
+-----+-----+*****+

purchase 4:
+-----+-----+-----+
|  0  | 200 | 300 |
+-----+-----+-----+
| 600 |  0  |  0  |
+-----+-----+*****+

purchase 5:
+-----+-----+-----+
|  0  |  0  | 300 |
+-----+-----+-----+
| 600 |  0  |  0  |
+-----+*****+-----+

purchase 6:
+-----+-----+-----+
|  0  |  0  | 300 |
+-----+-----+-----+
|  0  |  0  |  0  |
+-----+-----+*****+

final:
+-----+-----+-----+
|  0  |  0  |  0  |
+-----+-----+-----+
|  0  |  0  |  0  |
+*****+-----+-----+


*/
// END CUT HERE
