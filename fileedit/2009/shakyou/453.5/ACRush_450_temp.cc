#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

template<class T> inline void checkmin(T &a,T b){if(b<a) a=b;}

class PlanarGraphShop
{
public:
  int f[50005];
  int calc(int n)
  {
    if (n==1) return 0;
    if (n==2) return 1;
    if (n==3) return 3;
    return 3*n-6;
  }
  int bestCount(int n)
  {
    for (int i=0;i<=n;i++) f[i]=i;
    for (int a=1;a*a*a<=n;a++)
      for (int mb=calc(a),b=0;a*a*a+b*b<=n && b<=mb;b++)
      {
        int d=a*a*a+b*b;
        for (int i=d;i<=n;i++)
          checkmin(f[i],f[i-d]+1);
      }
    return f[n];
  }
};
#include "cout.h"
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
	int N = 36; 
	int RetVal = 1; 
	return verify_case(RetVal, PlanarGraphShop().bestCount(N)); }
int Test_(Case_<1>) {
	timer_clear();
	int N = 7; 
	int RetVal = 7; 
	return verify_case(RetVal, PlanarGraphShop().bestCount(N)); }
int Test_(Case_<2>) {
	timer_clear();
	int N = 72; 
	int RetVal = 2; 
	return verify_case(RetVal, PlanarGraphShop().bestCount(N)); }
int Test_(Case_<3>) {
	timer_clear();
	int N = 46; 
	int RetVal = 3; 
	return verify_case(RetVal, PlanarGraphShop().bestCount(N)); }
int Test_(Case_<4>) {
	timer_clear();
	int N = 1; 
	int RetVal = 1; 
	return verify_case(RetVal, PlanarGraphShop().bestCount(N)); }
int Test_(Case_<5>) { // #40
	timer_clear();
	int N = 100; 
	int RetVal = 1; 
	return verify_case(RetVal, PlanarGraphShop().bestCount(N)); }
int Test_(Case_<6>) {
	timer_clear();
	int N = 50000; 
	int RetVal = 2; 
	return verify_case(RetVal, PlanarGraphShop().bestCount(N)); }
int Test_(Case_<7>) {
	timer_clear();
	int N = 100; 
	int RetVal = 1; 
	return verify_case(RetVal, PlanarGraphShop().bestCount(N)); }
template<int N> void Run_() { cerr << "Test Case #" << N << "..." << flush; Test_(Case_<N>()); Run_<sizeof(Test_(Case_<N+1>()))==1 ? -1 : N+1>(); }
template<>      void Run_<-1>() {}
int main() { Run_<0>(); }
