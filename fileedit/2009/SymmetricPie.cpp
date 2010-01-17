// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// You've collected data in a vector <int> dogs which describes how many dogs are present in each neighborhood of your city, and you wish to represent this data in a pie chart.  The total number of dogs in your city is exactly 100, so if a neighborhood has 15 dogs, it will form a solid region in the chart with an area equal to 15% of the whole pie chart.

Given a pie chart, a dividing line is a line that passes through the center of the chart and doesn't pass through the interior of any solid region of the chart.  For example, the chart on the left has two dividing lines, while the chart on the right has only one dividing line (see examples 0 and 1 for the data that forms these two charts).



Note that there may be several ways to create a pie chart from the same data.  Return the maximum number of dividing lines in a pie chart that can be made from the data.

DEFINITION
Class:SymmetricPie
Method:getLines
Parameters:vector <int>
Returns:int
Method signature:int getLines(vector <int> dogs)


CONSTRAINTS
-dogs will contain between 1 and 8 elements, inclusive.
-Each element of dogs will be between 1 and 100, inclusive.
-The sum of all elements of dogs will be exactly 100.


EXAMPLES

0)
{10,40,10,40}

Returns: 2

This is the left pie chart in the problem statement's diagram.

1)
{10,50,40}

Returns: 1

This is the right pie chart in the problem statement's diagram.

2)
{50,50}

Returns: 1

The only line here divides the chart through the center.

3)
{1,48,1,1,48,1}

Returns: 3

The best solution here is to put the regions in the order (1,1,48,1,1,48), giving us 3 dividing lines.

4)
{2,2,96}

Returns: 0



*/
// END CUT HERE

#line 67 "SymmetricPie.cpp"
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

class SymmetricPie {
public:
  int getLines(vector<int> dogs) {
    int N=sz(dogs);
    sort(all(dogs));
    int maxcnt=0;
    while(1) {
      int cnt=0;
      //cout<<dogs<<endl;
      vector<int> ac(N+1,0); ac[0]=0;
      for(int i=0;i<N;i++) ac[i+1]=ac[i]+dogs[i];
      for(int i=0;i<N;i++) {
        if (ac[i]<50){
          for(int j=i+1;j<=N;j++) {
            if (ac[j]-ac[i]==50) cnt++;
          }
        }
      }
      if (maxcnt<cnt) maxcnt=cnt;

      if (!next_permutation(all(dogs))) break;
    }
    return maxcnt;
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
	int dogs_[] = {10,40,10,40};
	  vector <int> dogs(dogs_, dogs_+sizeof(dogs_)/sizeof(*dogs_)); 
	int RetVal = 2; 
	return verify_case(RetVal, SymmetricPie().getLines(dogs)); }
int Test_(Case_<1>) {
	timer_clear();
	int dogs_[] = {10,50,40};
	  vector <int> dogs(dogs_, dogs_+sizeof(dogs_)/sizeof(*dogs_)); 
	int RetVal = 1; 
	return verify_case(RetVal, SymmetricPie().getLines(dogs)); }
int Test_(Case_<2>) {
	timer_clear();
	int dogs_[] = {50,50};
	  vector <int> dogs(dogs_, dogs_+sizeof(dogs_)/sizeof(*dogs_)); 
	int RetVal = 1; 
	return verify_case(RetVal, SymmetricPie().getLines(dogs)); }
int Test_(Case_<3>) {
	timer_clear();
	int dogs_[] = {1,48,1,1,48,1};
	  vector <int> dogs(dogs_, dogs_+sizeof(dogs_)/sizeof(*dogs_)); 
	int RetVal = 3; 
	return verify_case(RetVal, SymmetricPie().getLines(dogs)); }
int Test_(Case_<4>) {
	timer_clear();
	int dogs_[] = {2,2,96};
	  vector <int> dogs(dogs_, dogs_+sizeof(dogs_)/sizeof(*dogs_)); 
	int RetVal = 0; 
	return verify_case(RetVal, SymmetricPie().getLines(dogs)); }

template<int N> void Run_() { cerr << "Test Case #" << N << "..." << flush; Test_(Case_<N>()); Run_<sizeof(Test_(Case_<N+1>()))==1 ? -1 : N+1>(); }
template<>      void Run_<-1>() {}
int main() { Run_<0>(); }
// END CUT HERE

