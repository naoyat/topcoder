import java.util.*;
 
public class TheAlmostLuckyNumbers {
    public long count(long a, long b) {
        Set<Long> prev = new HashSet<Long>();
        for (int len = 1; len <= 10; ++len)
            for (int i = 0; i < (1 << len); ++i) {
                long z = 0;
                for (int j = 0; j < len; ++j) {
                    z = z * 10 + 4;
                    if ((i & (1 << j)) != 0)
                        z += 3;
                }
                boolean ok = true;
                for (long x : prev)
                    if (z % x == 0) {
                        ok = false;
                        break;
                    }
                if (ok)
                    prev.add(z);
            }
        Long[] data = prev.toArray(new Long[0]);
        Arrays.sort(data, new Comparator<Long>() {
            public int compare(Long aLong, Long aLong1) {
                if (aLong > aLong1)
                    return -1;
                else if (aLong < aLong1)
                    return 1;
                else
                    return 0;
            }
        });
        long[] dl = new long[data.length];
        for (int i = 0; i < data.length; ++i)
            dl[i] = data[i];
        return (b - get(dl, b, 1, 0)) - (a - 1 - get(dl, a - 1, 1, 0));
    }
 
    long gcd(long a, long b) {
        while (b > 0) {
            long t = a % b;
            a = b;
            b = t;
        }
        return a;
    }
 
    static final long MAX = 10000000000L;
 
    long lcm(long a, long b) {
        long z = a / gcd(a, b);
        if (MAX / z < b)
            return MAX + 1;
        else
            return b * z;
    }
 
    private long get(long[] d, long max, long cur, int at) {
        long res = max / cur;
        for (int nxt = at; nxt < d.length; ++nxt) {
            long ncur = lcm(cur, d[nxt]);
            if (ncur <= max) {
                res -= get(d, max, ncur, nxt + 1);
            }
        }
        return res;
    }
 
}
 
 
// Powered by FileEdit
// Powered by RETester [based on ExampleBuilder]
// Powered by CodeProcessor
