#include &lt;vector>
#include &lt;algorithm>
using namespace std;

#define all(x)  (x).begin(),(x).end()

class TheTower {
public:
  vector&lt;int> count(vector&lt;int> x, vector&lt;int> y) {
    int n = x.size();
    int xmin = *min_element(all(x)), xmax = *max_element(all(x)),
      ymin = *min_element(all(y)), ymax = *max_element(all(y));
    vector&lt;int> m(n,INT_MAX); m[0] = 0;
    for (int x_=xmin; x_&lt;=xmax; x_++) {
      for (int y_=ymin; y_&lt;=ymax; y_++) {
        vector&lt;int> d(n);
        for (int i=0; i&lt;n; i++) d[i] = abs(x_ - x[i]) + abs(y_ - y[i]);
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
