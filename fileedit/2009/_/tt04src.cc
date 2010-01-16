#include &lt;string>
#include &lt;vector>
#include &lt;map>
#include &lt;algorithm>
#include &lt;cmath>
using namespace std;

#define sz(a)  int((a).size())
#define pb  push_back
#define all(c)  (c).begin(),(c).end()
#define tr(c,i)  for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); i++)
#define rep(var,n)  for(int var=0;var&lt;(n);var++)

inline int get_at(long long arcs, int idx)
{
  return (arcs >> (idx * 2)) & 0x3;
}
inline long long set_at(long long arcs, int idx, int val)
{
  long long mask = 3LL &lt;&lt; (idx * 2);
  long long vall = (long long)val &lt;&lt; (idx * 2);
  return (arcs & (~mask)) | vall;
}

class TwinTowns {
  int n, maxP;
  int distance[10][10];
  bool available[10][10];

  map&lt;long long,int> memo;

private:
  int findMaximum(long long arcs, int till) {
    if (till == 0) return 0;

    long long key = (arcs &lt;&lt; 4) | till;
    if (memo.find(key) != memo.end()) return memo[key];

    int pmax = 0, dmin = INT_MAX;//D_INFTY;
    int count = get_at(arcs,till);

    long long arcs_ = arcs;

    int pat_max = (1 &lt;&lt; till) - 1;
    int c_max = maxP - count;

    int arcs_mask = (1 &lt;&lt; (till*2)) - 1;

    for (int pat=0; pat&lt;=pat_max; pat++) {
      int c = __builtin_popcount(pat);
      if (c > c_max) continue;

      int d = 0;
      for (int i=0,m=1;i&lt;till;i++,m&lt;&lt;=1) {
        if ((pat & m) == 0) continue;
        if (! available[till][i]) goto next_pat;
        if (get_at(arcs_,i) == maxP) goto next_pat;

        arcs_ = set_at(arcs_, i, get_at(arcs_,i) + 1);
        d += distance[till][i];
      }

      {
        int ans = findMaximum(arcs_ & arcs_mask, till-1);
        int ans_p = c + (ans & 31), ans_d = d + (ans >> 5);
        if (ans_p > pmax) {
          pmax = ans_p; dmin = ans_d;
        } else if (ans_p == pmax) {
          if (ans_d &lt; dmin) dmin = ans_d;
        }
      }
    next_pat:
      arcs_ = arcs;
    }

    int ans = (dmin &lt;&lt; 5) | pmax;
    memo[key] = ans;
    return ans;
  }
  
public:
  vector&lt;int> optimalTwinTowns(vector&lt;int> x, vector&lt;int> y, int maxPartners, int minDistance) {
    n = x.size();
    if (n == 1) {
      vector&lt;int> ans(2,0);
      return ans;
    }

    maxP = min(maxPartners,n-1);
    rep(i,n) rep(j,n) available[i][j] = false;

    rep(j,n) {
      rep(i,n) {
        if (i == j) continue;
        int dist = abs(x[i]-x[j]) + abs(y[i]-y[j]); // 1-2000
        if (dist >= minDistance) {
          distance[i][j] = distance[j][i] = dist;
          available[i][j] = available[j][i] = true;
        }
      }
    }

    int a = findMaximum(0, n-1);
    vector&lt;int> ans(2,0);
    ans[0] = a & 31; ans[1] = a >> 5;
    return ans;
  }
};
