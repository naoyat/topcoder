#include &lt;vector>
#include &lt;algorithm>
using namespace std;

#define tr(c,i)  for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); i++)
#define all(x)  (x).begin(),(x).end()

class TheTower {
public:
  vector&lt;int> count(vector&lt;int> x, vector&lt;int> y) {
    int n = x.size();
    vector&lt;int> xs(all(x)); sort(all(xs));
    vector&lt;int> ys(all(y)); sort(all(ys));
    vector&lt;int> m(n,INT_MAX); m[0] = 0;
    tr(xs,x_) {
      tr(ys,y_) {
        vector&lt;int> d(n);
        for (int i=0; i&lt;n; i++) d[i] = abs(*x_ - x[i]) + abs(*y_ - y[i]);
        sort(all(d));
        int a = d[0];
        for (int i=1;i&lt;n;i++) {
          a += d[i];
          if (a &lt; m[i]) m[i] = a;
        }
      }
    }
    return m;
  }
};
