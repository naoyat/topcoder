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
