// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// You are planning to release a new product on the market and you want to find a strategy that will maximize your profit. That strategy will include fixing the optimal price for the product. You have made a customer list containing the maximum price each potential customer is willing to pay.  You also know how much it costs to deliver the product to each of those customers.  You are responsible for paying all the shipping costs, so if it's too expensive to deliver the product to a customer, you can choose not to sell to that customer.

You will be given vector <int>s price and cost, where price[i] is the maximum price customer i is willing to pay for the product and cost[i] is the cost of delivering the product to customer i.  Return the price for the product that maximizes profit. If there are multiple such prices, return the smallest among them. If it's impossible to achieve a positive profit, return 0.

DEFINITION
Class:SellingProducts
Method:optimalPrice
Parameters:vector <int>, vector <int>
Returns:int
Method signature:int optimalPrice(vector <int> price, vector <int> cost)


CONSTRAINTS
-price will contain between 1 and 50 elements, inclusive.
-Each element of price will be between 1 and 10^6, inclusive.
-cost will contain the same number of elements as price.
-Each element of cost will be between 0 and 10^6, inclusive.


EXAMPLES

0)
{13,22,35}
{0,0,0}

Returns: 22

If we sell the product at 13 then all three would buy it.(3x13=39)
If we sell the product at 22 then only two would buy it. (2x22=44)
If we sell the product at 35 then only one would buy it. (1x35=35)
So, 22 is the optimal price for our product.

1)
{13,22,35}
{5,15,30}

Returns: 13

If we sell the product at 13 then all three would buy it, but we would only sell to the first one.(13-5=8)
If we sell the product at 22 then only two would buy it, but we would only sell to the second one.(22-15=7).
If we sell the product at 35 then only one would buy it. (35-30=5)
So, 13 is the optimal price for our product.

2)
{13,22,35}
{15,30,40}

Returns: 0

Here it is too expensive to sell to anyone. So the optimal price is 0.

3)
{10,10,20,20,5}
{1,5,11,15,0}

Returns: 10

If we sell the product at 10 we gain 9 from the first customer and 5 from the second one(Total profit = 14). If we sell the product at 20 we gain 9 from the third customer and 5 from the fourth one(Total profit = 14). So both 10 and 20 are optimal prices but we must choose the smallest one.

4)
{13,17,14,30,19,17,55,16}
{12,1,5,10,3,2,40,19}

Returns: 17



*/
// END CUT HERE

#line 75 "SellingProducts.cpp"
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

class SellingProducts {
 public:
  int optimalPrice(vector<int> price, vector<int> cost) {
	int n=sz(price);
    vector<pair<int,int> > pc(n);
    rep(i,n){ pc[i]=make_pair(price[i],cost[i]);}
    sort(all(pc));
// BEGIN CUT HERE
    //cout << pc << endl;
// END CUT HERE
    int summax=0, the_price=0;
    rep(i,n){
      int p=pc[i].first;
// BEGIN CUT HERE
      //printf("price(%d)=%d\n", i,p);
// END CUT HERE
      int sum=0;
      for(int j=i;j<n;j++){
// BEGIN CUT HERE
        //printf("  considering #%d... ", j); cout<<pc[j]<<endl;
// END CUT HERE
        int d=(p - pc[j].second);
// BEGIN CUT HERE
        //printf("  => %d\n", d);
// END CUT HERE
        if(d>0) sum+=d;
      }
      if(sum>0){
        if(sum==summax) ;
        if(sum>summax){
          summax=sum;
          the_price=p;
        }
      }
    }
    return the_price;
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
	int price_[] = {13,22,35};
	  vector <int> price(price_, price_+sizeof(price_)/sizeof(*price_)); 
	int cost_[] = {0,0,0};
	  vector <int> cost(cost_, cost_+sizeof(cost_)/sizeof(*cost_)); 
	int RetVal = 22; 
	return verify_case(RetVal, SellingProducts().optimalPrice(price, cost)); }
int Test_(Case_<1>) {
	timer_clear();
	int price_[] = {13,22,35};
	  vector <int> price(price_, price_+sizeof(price_)/sizeof(*price_)); 
	int cost_[] = {5,15,30};
	  vector <int> cost(cost_, cost_+sizeof(cost_)/sizeof(*cost_)); 
	int RetVal = 13; 
	return verify_case(RetVal, SellingProducts().optimalPrice(price, cost)); }
int Test_(Case_<2>) {
	timer_clear();
	int price_[] = {13,22,35};
	  vector <int> price(price_, price_+sizeof(price_)/sizeof(*price_)); 
	int cost_[] = {15,30,40};
	  vector <int> cost(cost_, cost_+sizeof(cost_)/sizeof(*cost_)); 
	int RetVal = 0; 
	return verify_case(RetVal, SellingProducts().optimalPrice(price, cost)); }
int Test_(Case_<3>) {
	timer_clear();
	int price_[] = {10,10,20,20,5};
	  vector <int> price(price_, price_+sizeof(price_)/sizeof(*price_)); 
	int cost_[] = {1,5,11,15,0};
	  vector <int> cost(cost_, cost_+sizeof(cost_)/sizeof(*cost_)); 
	int RetVal = 10; 
	return verify_case(RetVal, SellingProducts().optimalPrice(price, cost)); }
int Test_(Case_<4>) {
	timer_clear();
	int price_[] = {13,17,14,30,19,17,55,16};
	  vector <int> price(price_, price_+sizeof(price_)/sizeof(*price_)); 
	int cost_[] = {12,1,5,10,3,2,40,19};
	  vector <int> cost(cost_, cost_+sizeof(cost_)/sizeof(*cost_)); 
	int RetVal = 17; 
	return verify_case(RetVal, SellingProducts().optimalPrice(price, cost)); }

template<int N> void Run_() { cerr << "Test Case #" << N << "..." << flush; Test_(Case_<N>()); Run_<sizeof(Test_(Case_<N+1>()))==1 ? -1 : N+1>(); }
template<>      void Run_<-1>() {}
int main() { Run_<0>(); }
// END CUT HERE

