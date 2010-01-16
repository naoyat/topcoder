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
 
class MazeMaker {
public:
  int longestPath(vector <string>, int, int, vector <int>, vector <int>);
};
 
int was[99][99];
int x[9999], y[9999], km[9999];
 
int MazeMaker::longestPath(vector <string> a, int sx, int sy, vector <int> hx, vector <int> hy) {
  int kh = hx.size(), n = a.size(), m = a[0].length(), i, j, e, xk, yk;
  memset(was,0,sizeof(was));
  x[1] = sx; y[1] = sy;
  km[1] = 0;
  was[sx][sy] = 1;
  i = 1; e = 1;
  while (i <= e) {
    for (j=0;j<kh;j++) {
      xk = x[i]+hx[j];
      yk = y[i]+hy[j];
      if (xk >= 0 && yk >= 0 && xk < n && yk < m) 
        if (a[xk][yk] == '.' && !was[xk][yk]) {
          e++;
          x[e] = xk;
          y[e] = yk;
          km[e] = km[i]+1;
          was[xk][yk] = 1;
        }
    }
    i++;
  }
  for (i=0;i<n;i++)
    for (j=0;j<m;j++)
      if (a[i][j] == '.' && !was[i][j]) return -1;
  return km[e];
}
