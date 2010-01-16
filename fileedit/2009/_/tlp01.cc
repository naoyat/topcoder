#include &lt;vector>
using namespace std;

const long long H = 1234567891LL;
inline long long sub_(long long a, long long b) { return (a + H - (b % H)) % H; }
inline long long add_(long long a, long long b) { return (a + b) % H; }
inline long long mul_(long long a, long long b) { return ((long long)(a % H) * (b % H)) % H; }

long long c_(int n, int r)
{
  if (n == 0 || r == 0 || r == n) return 1;
  if (r > n-r) r = n-r;
  return (c_(n-1,r-1) * n / r) % H;
}
long long expt_(int n, int k) { // n ^ k
  long long p = 1LL;
  for (int i=0; i&lt;k; i++) p = mul_(p, n);
  return p;
}
long long fac_(int n) { // n !
  long long p = 1LL;
  for (int k=n; k>1; k--) p = mul_(p, k);
  return p;
}

class TheLongPalindrome {
  long long f_(int k, int len) {
    if (k == 1) return 1;
    if (k == len) return fac_(k);
    long long t = 0;
    for (int j=k,pm=1; j>=1; j--,pm=-pm)
      t = (t + pm * expt_(j,len) * c_(k,j)) % H;
    return t;
  }

public:
  int count(int n, int k) {
    vector&lt;int> expts(27,1);

    int h = (n + 1) / 2, m = n % 2;
    if (k > h) k = h;

    long long c = 0LL;
    for (int len=1; len&lt;=h; len++) {
      // i:何文字長？
      int k_ = min(len,k); // 字種数
      long long o = 0LL;
      for (int j=1; j&lt;=k_; j++)
        o = add_(o, mul_(c_(26,j), f_(j,len))); // o += 26Cj x f(j,len)
      c = (len == h && m == 1)? add_(c,o) : add_(c,o*2);
    }
    return (int)c;
  }
};
