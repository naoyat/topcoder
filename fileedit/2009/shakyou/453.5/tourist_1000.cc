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
 
class TheAlmostLuckyNumbers {
public:
  long long count(long long, long long);
};
 
long long a[10000], da[10000], b[10000], c[10000];
int last[10000], ls[10000];
 
long long TheAlmostLuckyNumbers::count(long long left, long long right) {
  int n = 0, d, t, i, j;
  long long x;
  for (d=1;d<=10;d++) {
    for (t=0;t<(1<<d);t++) {
      x = 0;
      for (i=d-1;i>=0;i--) {
        x = x*10+4;
        if (t & (1 << i)) x += 3;
      }
      for (i=0;i<n;i++)
        if (x % a[i] == 0) x = 0;
      if (x) a[n++] = x;
    }
  }
  long long ans = 0, aa, bb;
  for (i=0;i<n;i++) {
    if (a[i] > right) {
      n = i;
      break;
    }
    da[i] = right/a[i];
    ans += right/a[i]-(left-1)/a[i];
    last[i] = i;
  }
  int m, q, p;
  m = n;
  for (i=0;i<m;i++) b[i] = a[i];
  q = 1;
  while (m) {
    q = -q; p = 0;
    for (i=0;i<m;i++)
      for (j=last[i]+1;j<n;j++) {
        aa = b[i]; bb = a[j];
        while (aa && bb)
          if (aa > bb) aa %= bb;
          else bb %= aa;
        x = b[i]/(aa+bb);
        if (x > da[j]*10000000) break;
        if (x > da[j]) continue;
        x *= a[j];
        if (x <= right) {
          c[p] = x;
          ls[p++] = j;
        }
      }
    m = p;
    for (i=0;i<m;i++) {
      b[i] = c[i];
      last[i] = ls[i];
    }
    for (i=0;i<m;i++) ans += q*(right/b[i]-(left-1)/b[i]);
  }
  return ans;
}
