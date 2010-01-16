#include <vector>
using namespace std;

const long long H = 1234567891LL;

inline long long sub_(long long a, long long b) { return (a + H - (b % H)) % H; }
inline long long add_(long long a, long long b) { return (a + b) % H; }
inline long long mul_(long long a, long long b) { return ((a % H) * (b % H)) % H; }

long long fast_expt(long long r, long long n) { // r^n % H
  if (n == 1) return r;
  if (n % 2 == 0)
    return fast_expt(mul_(r,r), n/2);
  else
    return mul_(fast_expt(r,n-1), r);
}

inline long long div_(long long a, long long b) { return mul_(a, fast_expt(b,H-2)); }

long long geo(int r, int n) {
  // 1,r,r^2,...,r^n
  if (r == 1) return n % H;

  return div_(fast_expt(r,n+1)-1, r-1);
}

long long C(int n, int r)
{
  if (n == 0 || r == 0 || r == n) return 1;
  if (r > n-r) r = n-r;
  return C(n-1,r-1) * n / r;
}

long long fac_(int n) { // n !
  long long p = 1LL;
  for (int k=n; k>1; k--) p = mul_(p, k);
  return p;
}

vector<long long> coeffs_(int k) {
  vector<long long> cs(k+1, 1LL); cs[0] = 0;
  
  for (int j=1; j<=k; j++) {
    long long t = 0;
    for (int i=0,pm=1; i<=k-j; i++,pm=-pm) {
      t += C(26-j, i) * pm;
    }
    cs[j] = C(26, j) * t;
  }
  return cs;
}

class TheLongPalindrome {
  long long f_(int k, int len) {
    if (k == 1) return 1;
    if (k == len) return fac_(k);
    
    long long t = 0;
    for (int j=k,pm=1; j>=1; j--,pm=-pm) {
      if (pm >= 0)
        t = add_(t, fast_expt(j,len) * C(k,j));
      else
        t = sub_(t, fast_expt(j,len) * C(k,j));
    }
    return t;
  }

public:
  int count(int n, int k) {
    int h = (n + 1) / 2, m = n % 2;
    if (k > h) k = h;

    vector<long long> expts(k+1, 1LL); expts[0] = 0;
    vector<long long> coeffs = coeffs_(k);

    long long c = 0LL;
    for (int len=1; len<=k; len++) {
      int k_ = len;
      long long o = 0LL;
      for (int j=1; j<=k_; j++)
        o = add_(o, mul_(C(26,j), f_(j,len))); // o += 26Cj x f(j,len)
      c = (len == h && m == 1)? add_(c,o) : add_(c,o*2);
    }

    if (h > k) {
      long long o = 0LL;
      for (int r=1; r<=k; r++) {
        long long co = coeffs[r];

        if (co >= 0)
          o = add_(o, mul_(co, sub_(geo(r,h-1), geo(r,k))));
        else
          o = sub_(o, mul_(-co, sub_(geo(r,h-1), geo(r,k))));
      }
      c = add_(c, o*2);

      o = 0LL;
      for (int r=1; r<=k; r++) {
        long long co = coeffs[r];
        if (co >= 0)
          o = add_(o, mul_(co, fast_expt(r,h)));
        else
          o = sub_(o, mul_(-co, fast_expt(r,h)));
      }
      c = (m == 1) ? add_(c, o) : add_(c, o*2);
    }

    return (int)c;
  }
};
