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
