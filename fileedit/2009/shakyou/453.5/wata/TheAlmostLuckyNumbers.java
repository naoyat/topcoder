import static java.lang.Math.*;
import static java.math.BigInteger.*;
import static java.util.Arrays.*;
import static java.util.Collections.*;
import java.math.*;
import java.util.*;

public class TheAlmostLuckyNumbers {
  int N = 2046;
  long[] L;
  void init() {
    L = new long[N];
    int n = 0;
    for (int len = 1; len <= 10; len++) {
      for (int i = 0; i < 1 << len; i++) {
        long v = 0;
        for (int j = 0; j < len; j++) {
          if ((i >> j & 1) == 0) v = v * 10 + 4;
          else v = v * 10 + 7;
        }
        L[n++] = -v;
      }
    }
    sort(L);
    for (int i = 0; i < N; i++) L[i] = -L[i];
  }
  class Entry implements Comparable<Entry> {
    long key, val;
    Entry(long key, long val) {
      this.key = key;
      this.val = val;
    }
    public int compareTo(Entry o) {
      if (key < o.key) return -1;
      if (key > o.key) return 1;
      return 0;
    }
  }
  public long count(long a, long b) {
    init();
    return calc(a - 1, b);
  }
  long calc(long n1, long n2) {
    return n2 - n1 - rec(0, 1, n1, n2);
  }
  long rec(int i, long v, long n1, long n2) {
    long res = n2 / v - n1 / v;
    for (int j = i; j < N; j++) if (L[j] / gcd(v, L[j]) <= n2 / v) {
      res -= rec(j + 1, v / gcd(v, L[j]) * L[j], n1, n2);
    }
    return res;
  }
  long gcd(long x, long y) {
    long t;
    while (y != 0) {
      t = x % y; x = y; y = t;
    }
    return abs(x);
  }
  void debug(Object...os) {
    System.err.println(deepToString(os));
  }
}
