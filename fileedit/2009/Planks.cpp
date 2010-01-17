// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// After a recent construction project, you have found that you have some wooden planks of various lengths left over. Knowing that wood is quite valuable, you are going to try to sell them. A local hardware store has offered to buy the planks, but in order to make a retail display they want all the planks they buy to be the same length and they want this length to be some integer value. A local workshop can cut the planks into different lengths for you, but they charge costPerCut for every cut they make. The hardware store will pay woodValue per unit length for the planks that they buy (i.e., if you bring them K planks, each L units long, then they'll pay you K * L * woodValue). Any leftover wood will be thrown away. What is the maximum amount of money that you can make?
You are given a vector <int> lengths, in which each element is the length of a single plank of wood. Return an int containing the maximum amount of money that you can make.


DEFINITION
Class:Planks
Method:makeSimilar
Parameters:vector <int>, int, int
Returns:int
Method signature:int makeSimilar(vector <int> lengths, int costPerCut, int woodValue)


CONSTRAINTS
-lengths will contain between 1 and 50 elements, inclusive.
-Each element of lengths will be between 1 and 10000, inclusive.
-woodValue and costPerCut will each be between 1 and 1000, inclusive.


EXAMPLES

0)
{26,103,59}
1
10

Returns: 1770

Here, wood is very valuable, while making cuts is very cheap. We can therefore make a large number of cuts to reduce the amount of wood wasted as much as possible. It is optimal to cut the planks into smaller planks of length 6. Cut the first plank into 4 pieces of length 6 and 1 of length 2, the second into 17 pieces of length 6 and 1 of length 1 and the the third into 9 pieces of length 6 and 1 of length 5. In total we have 30 pieces of length 6 that we can sell and have made 30 cuts. The total amount of money we make is therefore:
30 * 6 * 10 - 30 * 1
= 1770

1)
{26,103,59}
10
10

Returns: 1680

These are the same three planks, but now making a cut is far more expensive. It is now optimal to cut the planks to a common length of 25.

2)
{26,103,59}
100
10

Returns: 1230

Now making a cut is really expensive. Here it is optimal to throw the smallest plank away entirely. Cut the remaining two into 51 unit lengths.

3)
{5281,5297,5303,5309,5323,5333,5347,5351,5381,5387}
5
20

Returns: 1057260



4)
{31,73,127,179,181,191,283,353,359,1019} 
25
10

Returns: 25145



5)
{200,200,200,400}
1000
1

Returns: 600

Throw away the plank of length 400 and just sell the three planks of length 200.

*/
// END CUT HERE

#line 84 "Planks.cpp"
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

class Planks {
 public:
  int makeSimilar(vector<int> lengths, int costPerCut, int woodValue) {
	int n=sz(lengths);//1-50; each 1-10000;
    int maxl=*max_element(all(lengths));//all(lengths));
    int maxa=0;
    for(int u=1;u<=maxl;u++){
      int cost=0, value=0;
      rep(i,n){
        int li=lengths[i];
        int k=li/u, r=li%u, cut=r>0?k:(k-1);
        int c=costPerCut*cut, v=k*u*woodValue;
        if (c<v) {
          cost+=c; value+=v;
        }
      }
      int a=value-cost;
      maxa=max(a,maxa);
    }
    return maxa;
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
	int lengths_[] = {26,103,59};
	  vector <int> lengths(lengths_, lengths_+sizeof(lengths_)/sizeof(*lengths_)); 
	int costPerCut = 1; 
	int woodValue = 10; 
	int RetVal = 1770; 
	return verify_case(RetVal, Planks().makeSimilar(lengths, costPerCut, woodValue)); }
int Test_(Case_<1>) {
	timer_clear();
	int lengths_[] = {26,103,59};
	  vector <int> lengths(lengths_, lengths_+sizeof(lengths_)/sizeof(*lengths_)); 
	int costPerCut = 10; 
	int woodValue = 10; 
	int RetVal = 1680; 
	return verify_case(RetVal, Planks().makeSimilar(lengths, costPerCut, woodValue)); }
int Test_(Case_<2>) {
	timer_clear();
	int lengths_[] = {26,103,59};
	  vector <int> lengths(lengths_, lengths_+sizeof(lengths_)/sizeof(*lengths_)); 
	int costPerCut = 100; 
	int woodValue = 10; 
	int RetVal = 1230; 
	return verify_case(RetVal, Planks().makeSimilar(lengths, costPerCut, woodValue)); }
int Test_(Case_<3>) {
	timer_clear();
	int lengths_[] = {5281,5297,5303,5309,5323,5333,5347,5351,5381,5387};
	  vector <int> lengths(lengths_, lengths_+sizeof(lengths_)/sizeof(*lengths_)); 
	int costPerCut = 5; 
	int woodValue = 20; 
	int RetVal = 1057260; 
	return verify_case(RetVal, Planks().makeSimilar(lengths, costPerCut, woodValue)); }
int Test_(Case_<4>) {
	timer_clear();
	int lengths_[] = {31,73,127,179,181,191,283,353,359,1019} ;
	  vector <int> lengths(lengths_, lengths_+sizeof(lengths_)/sizeof(*lengths_)); 
	int costPerCut = 25; 
	int woodValue = 10; 
	int RetVal = 25145; 
	return verify_case(RetVal, Planks().makeSimilar(lengths, costPerCut, woodValue)); }
int Test_(Case_<5>) {
	timer_clear();
	int lengths_[] = {200,200,200,400};
	  vector <int> lengths(lengths_, lengths_+sizeof(lengths_)/sizeof(*lengths_)); 
	int costPerCut = 1000; 
	int woodValue = 1; 
	int RetVal = 600; 
	return verify_case(RetVal, Planks().makeSimilar(lengths, costPerCut, woodValue)); }

template<int N> void Run_() { cerr << "Test Case #" << N << "..." << flush; Test_(Case_<N>()); Run_<sizeof(Test_(Case_<N+1>()))==1 ? -1 : N+1>(); }
template<>      void Run_<-1>() {}
int main() { Run_<0>(); }
// END CUT HERE

