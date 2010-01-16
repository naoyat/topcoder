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
