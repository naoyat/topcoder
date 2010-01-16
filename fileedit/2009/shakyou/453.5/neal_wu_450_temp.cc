#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;
 
const int MAXN = 50005;
 
int dp [MAXN];
 
inline void update (int N, int cost)
{
    for (int i = 0; i + cost <= N; i++)
        if (dp [i] + 1 < dp [i + cost])
            dp [i + cost] = dp [i] + 1;
}
 
struct PlanarGraphShop
{
    int bestCount (int N)
    {
        memset (dp, 63, sizeof (dp));
        dp [0] = 0;
 
        for (int x = 1; x * x * x <= N; x++)
        {
            int end = 3 * x - 6;
 
            if (x == 1)
                end = 0;
            else if (x == 2)
                end = 1;
 
            for (int y = 0; y <= end; y++)
                update (N, x * x * x + y * y);
        }
 
        return dp [N];
    }
};
 
 
 
// Powered by FileEdit
// Powered by moj 4.11 [modified TZTester]
// Powered by CodeProcessor
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
