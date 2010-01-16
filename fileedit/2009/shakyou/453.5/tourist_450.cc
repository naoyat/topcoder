#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
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
#include <ctime>
 
using namespace std;
 
class PlanarGraphShop {
public:
  int bestCount(int);
};
 
int f[50010];
 
int PlanarGraphShop::bestCount(int N) {
  int i, j, x, y, z, p;
  for (i=1;i<=N;i++) f[i] = 1000000000;
  f[0] = 0;
  for (x=1;x<=36;x++) {
    if (x == 1) y = 0; else
    if (x == 2) y = 1;
    else y = 3*x-6;
    for (z=0;z<=y;z++) {
      p = x*x*x+z*z;
      for (j=0;j<=N-p;j++)
        if (f[j]+1 < f[j+p]) f[j+p] = f[j]+1;
    }
  }
  return f[N];
}
