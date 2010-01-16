import static java.lang.Math.*;
import static java.math.BigInteger.*;
import static java.util.Arrays.*;
import static java.util.Collections.*;
import java.math.*;
import java.util.*;

public class PlanarGraphShop {
  int INF = 1 << 29;
  public int bestCount(int N) {
    int[] dp = new int[N + 1];
    for (int i = 0; i <= N; i++) dp[i] = i;
    for (int i = 8; i <= N; i++) dp[i] = dp[i - 8] + 1;
    for (int i = 9; i <= N; i++) dp[i] = min(dp[i], dp[i - 9] + 1);
    for (int v = 3; v * v * v <= N; v++) {
      for (int e = 0; e <= 3 * v - 6 && v * v * v + e * e <= N; e++) {
        int d = v * v * v + e * e;
        for (int i = d; i <= N; i++) {
          if (dp[i] > dp[i - d] + 1) dp[i] = dp[i - d] + 1;
        }
      }
    }
    return dp[N];
  }
  void debug(Object...os) {
    System.err.println(deepToString(os));
  }
}
