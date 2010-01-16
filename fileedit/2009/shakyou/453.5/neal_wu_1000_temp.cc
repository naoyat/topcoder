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
 
const double EPS = 1e-9;
 
struct TheAlmostLuckyNumbers
{
    inline long long between (long long a, long long b, long long c)
    {
        return b / c - (a - 1) / c;
    }
 
    long long count (long long a, long long b)
    {
        long long total = 0;
        vector <long long> v, temp;
 
        for (int len = 1; len <= 10; len++)
            for (int m = 0; m < 1 << len; m++)
            {
                long long x = 0;
 
                for (int i = 0; i < len; i++)
                    x = x * 10 + ((m & 1 << i) == 0 ? 4 : 7);
 
                v.push_back (x);
            }
 
        sort (v.begin (), v.end ());
 
        for (int i = 0; i < (int) v.size (); i++)
        {
            bool good = true;
 
            for (int j = 0; j < i; j++)
                if (v [i] % v [j] == 0)
                    good = false;
 
            if (good)
                temp.push_back (v [i]);
        }
 
        v = temp;
        int N = v.size ();
 
        vector <pair <int, long long> > mask1, mask2;
 
        for (int i = 0; i < N; i++)
            mask1.push_back (make_pair (i, v [i]));
 
        bool sign = true;
 
        while (!mask1.empty ())
        {
            //printf ("%d\n", mask1.size ());
 
            for (int i = 0; i < (int) mask1.size (); i++)
                total += (sign ? 1 : -1) * between (a, b, mask1 [i].second);
 
            mask2.clear ();
 
            for (int i = 0; i < (int) mask1.size (); i++)
                for (int j = mask1 [i].first + 1; j < N; j++)
                {
                    if ((double) mask1 [i].second * v [j] > 1e15)
                        break;
 
                    long long g = __gcd (mask1 [i].second, v [j]);
 
                    if ((double) mask1 [i].second * v [j] <= 1e10 * g * (1 + EPS))
                        mask2.push_back (make_pair (j, mask1 [i].second / g * v [j]));
                }
 
            mask1 = mask2;
            sign = !sign;
        }
 
        return total;
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
int verify_case(const long long &Expected, const long long &Received) { if (Expected == Received) cerr << "PASSED" << timer() << endl; else { cerr << "FAILED" << timer() << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } return 0;}

template<int N> struct Case_ {};
char Test_(...);
int Test_(Case_<0>) {
	timer_clear();
	long long a = 1LL; 
	long long b = 10LL; 
	long long RetVal = 3LL; 
	return verify_case(RetVal, TheAlmostLuckyNumbers().count(a, b)); }
int Test_(Case_<1>) {
	timer_clear();
	long long a = 14LL; 
	long long b = 14LL; 
	long long RetVal = 1LL; 
	return verify_case(RetVal, TheAlmostLuckyNumbers().count(a, b)); }
int Test_(Case_<2>) {
	timer_clear();
	long long a = 1LL; 
	long long b = 100LL; 
	long long RetVal = 39LL; 
	return verify_case(RetVal, TheAlmostLuckyNumbers().count(a, b)); }
int Test_(Case_<3>) {
	timer_clear();
	long long a = 1234LL; 
	long long b = 4321LL; 
	long long RetVal = 1178LL; 
	return verify_case(RetVal, TheAlmostLuckyNumbers().count(a, b)); }
int Test_(Case_<4>) {
	timer_clear();
	long long a =  9999999999LL;
	long long b = 10000000000LL;
	long long RetVal = 1LL; 
	return verify_case(RetVal, TheAlmostLuckyNumbers().count(a, b)); }

template<int N> void Run_() { cerr << "Test Case #" << N << "..." << flush; Test_(Case_<N>()); Run_<sizeof(Test_(Case_<N+1>()))==1 ? -1 : N+1>(); }
template<>      void Run_<-1>() {}
int main() { Run_<0>(); }
// END CUT HERE


// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// A lucky number is a number whose decimal representation contains only the digits 4 and 7.  An almost lucky number is a number that is divisible by a lucky number.  For example, 14, 36 and 747 are almost lucky, but 2 and 17 are not. Note that a number can be both lucky and almost lucky at the same time (for example, 747).

You are given long longs a and b.  Return the number of almost lucky numbers between a and b, inclusive.

DEFINITION
Class:TheAlmostLuckyNumbers
Method:count
Parameters:long long, long long
Returns:long long
Method signature:long long count(long long a, long long b)


CONSTRAINTS
-a will be between 1 and 10,000,000,000, inclusive.
-b will be between a and 10,000,000,000, inclusive.


EXAMPLES

0)
1
10

Returns: 3

There are three almost lucky numbers less than or equal to ten - 4, 7 and 8.

1)
14
14

Returns: 1

14 is an almost lucky number.

2)
1
100

Returns: 39

3)
1234
4321

Returns: 1178

*/
