import java.util.*;

public class PlanarGraphShop {
  public int bestCount(int N) {
    int res = 0;
    Set<Integer> set = new HashSet<Integer>();
    for(int X = 1 ; ; ++X){
      if(X * X * X > N)
        break;
      for(int Y = 0 ; Y <= X * (X - 1) / 2 ; ++Y){
        if(X * X * X + Y * Y > N)
          break;
        if(X < 3 || (Y <= 3 * X - 6)){
//          System.err.println(X+ " " + Y+" "+(X * X * X + Y * Y));
          set.add(X * X * X + Y * Y);
        }
      }
    }
    List<Integer> canBuy = new ArrayList<Integer>(set);
    Collections.sort(canBuy);
//    System.err.println(canBuy.size());
    int dp[] = new int[N + 1];
    Arrays.fill(dp, 1 << 20);
    dp[0] = 0;
    for(int v : canBuy){
      for(int i = 0 ; i < dp.length ; i++){
        if(i + v >= dp.length)break;
        dp[i + v] = Math.min(dp[i + v], dp[i] + 1);
      }
    }
//    System.err.println(Arrays.toString(dp));
    return dp[N];
  }

}

