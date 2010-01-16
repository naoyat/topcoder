#include <assert.h> 
#include <ctype.h> 
#include <float.h> 
#include <math.h> 
#include <stdio.h> 
#include <string> 
#include <stdlib.h> 
#include <time.h> 
#include <algorithm> 
#include <numeric> 
#include <functional> 
#include <utility> 
#include <vector> 
#include <list> 
#include <set> 
#include <map> 
#include <queue> 
#include <stack> 
#include <sstream> 
#include <iostream> 

using namespace std;

#define rep(i,n) for(int i=0;i<(n);++i)
#define all(c) (c).begin(), (c).end() 
#define clr(a,b) memset(a,b,sizeof(a)); 
#define inf 1 << 29

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<string> vs;
typedef vector<int> vi;

bool canMake[50001];
int lst[50001];

int total[50001];

class PlanarGraphShop 
{
public:
  int bestCount(int N) 
  {
    memset(canMake, false, sizeof(canMake));
    for (int i = 1; i * i * i <= N; i++)
    {
      int max = i == 1 ? 0 : i == 2 ? 1 : 3 * i - 6;

      for (int j = 0; j <= max; j++)
      {
        int e = i * i * i + j * j;
        if (e > N)
          break;

        canMake[e] = true;
      }
    }
    if (canMake[N])
      return 1;

    int listCount = 0;

    for (int i = 0; i <= N; i++)
      if (canMake[i])
      {
        lst[listCount++] = i;
      }

    memset(total,60, sizeof(total));
    total[0] = 0;

    for (int j = 1; j <= N; j++)
    {
      for (int k = 0; k < listCount; k++)
      {
        int x = lst[k];
        if (j >= x)
        {
          total[j] = min(total[j], total[j - x] + 1);
        }

      }
    }

    return total[N];
  }
};
