#line 2 "BrokenButtons.cpp"
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
#define sz(a)  int((a).size())
#define pb  push_back
#define all(c)  (c).begin(),(c).end()
#define tr(c,i)  for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); i++)
#define rep(var,n)  for(int var=0;var<(n);var++)

class BrokenButtons {
 public:
  int minPresses(int page, vector<int> broken) {
    if(page==100) return 0;
    int bn=sz(broken);
    if(bn==10) return abs(page-100);

    vector<int> ps(1000000,INT_MAX);
    ps[100]=0;
    
    set<int> bk(all(broken));
    vector<bool> btns(10,true);
    tr(broken,it) btns[*it]=false;
    //cout << broken << " => " << btns << endl;
    int k=6;
    rep(a,10){ if(!btns[a])continue;
      rep(b,10){ if(!btns[b])continue;
        rep(c,10){ if(!btns[c])continue;
          rep(d,10){ if(!btns[d])continue;
            rep(e,10){ if(!btns[e])continue;
              rep(f,10){ if(!btns[f])continue;
                int n=a*100000 + b*10000 + c*1000 + d*100 + e*10 + f;
                if(n<10) k=1;
                else if(n<100) k=2;
                else if(n<1000) k=3;
                else if(n<10000) k=4;
                else if(n<100000) k=5;
                else k=6;
                ps[n] = k;
              }
            }
          }
        }
      }
    }

    if(ps[page]!=INT_MAX) return ps[page];
    
    int bmin=INT_MAX;
    for(int i=page-1;i>=0;i--){
      if(ps[i]!=INT_MAX){
        int b=ps[i]+(page-i);
        if(b<bmin) bmin=b;
      }
    }
    for(int i=page+1;i<1000000;i++){
      if(ps[i]!=INT_MAX){
        int b=ps[i]+(i-page);
        if(b<bmin) bmin=b;
      }
    }
    return bmin;
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
	int page = 5457; 
	int broken_[] = { 6, 7, 8 };
	  vector <int> broken(broken_, broken_+sizeof(broken_)/sizeof(*broken_)); 
	int RetVal = 6; 
	return verify_case(RetVal, BrokenButtons().minPresses(page, broken)); }
int Test_(Case_<1>) {
	timer_clear();
	int page = 100; 
	int broken_[] = { 1, 0, 5 };
	  vector <int> broken(broken_, broken_+sizeof(broken_)/sizeof(*broken_)); 
	int RetVal = 0; 
	return verify_case(RetVal, BrokenButtons().minPresses(page, broken)); }
int Test_(Case_<2>) {
	timer_clear();
	int page = 14124; 
	vector <int> broken; 
	int RetVal = 5; 
	return verify_case(RetVal, BrokenButtons().minPresses(page, broken)); }
int Test_(Case_<3>) {
	timer_clear();
	int page = 1; 
	int broken_[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	  vector <int> broken(broken_, broken_+sizeof(broken_)/sizeof(*broken_)); 
	int RetVal = 2; 
	return verify_case(RetVal, BrokenButtons().minPresses(page, broken)); }
int Test_(Case_<4>) {
	timer_clear();
	int page = 80000; 
	int broken_[] = { 8, 9 };
	  vector <int> broken(broken_, broken_+sizeof(broken_)/sizeof(*broken_)); 
	int RetVal = 2228; 
	return verify_case(RetVal, BrokenButtons().minPresses(page, broken)); }

template<int N> void Run_() { cerr << "Test Case #" << N << "..." << flush; Test_(Case_<N>()); Run_<sizeof(Test_(Case_<N+1>()))==1 ? -1 : N+1>(); }
template<>      void Run_<-1>() {}
int main() { Run_<0>(); }
// END CUT HERE


// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// You want to see some page on the teletext (information service on TV where we refer to pages of information by numbers). Unfortunately, some of the digit buttons on the remote control are broken. But you have an idea! If you can't enter the number of the page you want to see, you could enter some other number and with the buttons '+' and '-' (which are not broken) navigate to the desired page. Button '+' increases the number by 1 and button '-' decreases the number by 1. You are initially at page 100. To go to a different page, you may enter the page number using the digit buttons that aren't broken. Then, press the '+' and '-' buttons to navigate to your desired page.

You will be given an int page, the page you want to see, and a vector <int> broken, the list of broken digit buttons.  Return the minimum number of button presses required to navigate to the page.

DEFINITION
Class:BrokenButtons
Method:minPresses
Parameters:int, vector <int>
Returns:int
Method signature:int minPresses(int page, vector <int> broken)


CONSTRAINTS
-page will be between 0 and 500,000, inclusive.
-broken will contain between 0 and 10 elements, inclusive.
-Each element of broken will be between 0 and 9, inclusive.
-All elements of broken will be distinct.


EXAMPLES

0)
5457
{ 6, 7, 8 }

Returns: 6

You can go to page 5457 either by pressing "5455++" or "5459--".

1)
100
{ 1, 0, 5 }

Returns: 0

If you don't enter anything you'll get page 100.

2)
14124
{ }

Returns: 5



3)
1
{1, 2, 3, 4, 5, 6, 7, 8, 9}

Returns: 2

We can enter page 0.

4)
80000
{ 8, 9 }

Returns: 2228



*/
// END CUT HERE
