#line 2 "MNS.cpp"
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
#define mset(arr,val)  memset(arr,val,sizeof(arr))
#define tr(c,i)  for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); i++)
#define rep(var,n)  for(int var=0;var<(n);var++)
#define forr(var,from,to) for(int var=(from);var<=(to);var++) 
#define found(s,e)  ((s).find(e)!=(s).end())
#define remove_(c,val) (c).erase(remove((c).begin(),(c).end(),(val)),(c).end())
#define lastc(str) (*((str).end()-1))

class MNS {
 public:
  int combos(vector<int> ns) {
    set<vector<int> > ans;
    int sum=0;
	rep(i,9) sum+=ns[i];
    if(sum%3) return 0;
    sort(all(ns));
    int rowsum=sum/3;
    for(int i=0;i<7;i++){
      for(int j=i+1;j<8;j++){
        for(int k=j+1;k<9;k++){
          vector<int> as(3); as[0]=ns[i]; as[1]=ns[j]; as[2]=ns[k];
          if (as[0]+as[1]+as[2] == rowsum) {
            ns.erase(ns.begin()+k);
            ns.erase(ns.begin()+j);
            ns.erase(ns.begin()+i);
            for(int u=0;u<4;u++){
              for(int v=u+1;v<5;v++){
                for(int w=v+1;w<6;w++){
                  vector<int> bs(3); bs[0]=ns[u]; bs[1]=ns[v]; bs[2]=ns[w];
                  if (bs[0]+bs[1]+bs[2] == rowsum) {
                    ns.erase(ns.begin()+w);
                    ns.erase(ns.begin()+v);
                    ns.erase(ns.begin()+u);

                    do {
                      do {
                        do {
                          if ( (as[0]+bs[0]+ns[0] == rowsum)
                               && (as[1]+bs[1]+ns[1] == rowsum)
                               && (as[2]+bs[2]+ns[2] == rowsum) ) {
                            int a_[9] = { as[0],as[1],as[2], bs[0],bs[1],bs[2], ns[0],ns[1],ns[2] };
                            vector<int> a(a_, a_+sizeof(a_)/sizeof(*a_));
                            ans.insert(a);
                          }
                        } while (next_permutation(all(ns)));
                      } while (next_permutation(all(bs)));
                    } while (next_permutation(all(as)));

                    ns.pb(bs[0]); ns.pb(bs[1]); ns.pb(bs[2]);
                    sort(all(ns));
                    // cout << ns << endl;
                  }
                }
              }
            }
            ns.pb(as[0]); ns.pb(as[1]); ns.pb(as[2]);
            sort(all(ns));
          }
        }
      }
    }
    // 9c3 = 987/32 = 347=84pat
    return sz(ans);
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
	int ns_[] = {1,2,3,3,2,1,2,2,2};
	  vector <int> ns(ns_, ns_+sizeof(ns_)/sizeof(*ns_)); 
	int RetVal = 18; 
	return verify_case(RetVal, MNS().combos(ns)); }
int Test_(Case_<1>) {
	timer_clear();
	int ns_[] = {4,4,4,4,4,4,4,4,4};
	  vector <int> ns(ns_, ns_+sizeof(ns_)/sizeof(*ns_)); 
	int RetVal = 1; 
	return verify_case(RetVal, MNS().combos(ns)); }
int Test_(Case_<2>) {
	timer_clear();
	int ns_[] = {1,5,1,2,5,6,2,3,2};
	  vector <int> ns(ns_, ns_+sizeof(ns_)/sizeof(*ns_)); 
	int RetVal = 36; 
	return verify_case(RetVal, MNS().combos(ns)); }
int Test_(Case_<3>) {
	timer_clear();
	int ns_[] = {1,2,6,6,6,4,2,6,4};
	  vector <int> ns(ns_, ns_+sizeof(ns_)/sizeof(*ns_)); 
	int RetVal = 0; 
	return verify_case(RetVal, MNS().combos(ns)); }

template<int N> void Run_() { cerr << "Test Case #" << N << "..." << flush; Test_(Case_<N>()); Run_<sizeof(Test_(Case_<N+1>()))==1 ? -1 : N+1>(); }
template<>      void Run_<-1>() {}
int main() { Run_<0>(); }
// END CUT HERE


// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
9 ns need to be arranged in a magic number square.  A magic number square is a square of ns that is arranged such that every row and column has the same sum.  For example:


1 2 3
3 2 1
2 2 2


Create a class MNS containing a method combos which takes as an argument a vector <int> ns and returns the number of distinct ways those ns can be arranged in a magic number square.  Two magic number squares are distinct if they differ in value at one or more positions.  For example, there is only one magic number square that can be made of 9 instances of the same number.


DEFINITION
Class:MNS
Method:combos
Parameters:vector <int>
Returns:int
Method signature:int combos(vector <int> ns)


NOTES
-Unlike some versions of the magic number square, the ns do not have to be unique.


CONSTRAINTS
-ns will contain exactly 9 elements.
-each element of ns will be between 0 and 9, inclusive.


EXAMPLES

0)
{1,2,3,3,2,1,2,2,2}

Returns: 18

1)
{4,4,4,4,4,4,4,4,4}

Returns: 1

2)
{1,5,1,2,5,6,2,3,2}

Returns: 36

3)
{1,2,6,6,6,4,2,6,4}

Returns: 0

*/
// END CUT HERE
