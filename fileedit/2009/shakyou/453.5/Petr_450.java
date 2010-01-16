import java.util.*;
 
public class PlanarGraphShop {
    public int bestCount(int N) {
        boolean[] can = new boolean[N + 1];
        for (int x = 1; x * x * x <= N; ++x) {
            int max = getMax(x);
            for (int y = 0; y <= max; ++y) {
                int z = x * x * x + y * y;
                if (z > N)
                    break;
                can[z] = true;
            }
        }
        int[] best = new int[N + 1];
        Arrays.fill(best, Integer.MAX_VALUE / 2);
        best[0] = 0;
        for (int i = 1; i <= N; ++i)
            if (can[i])
                for (int j = 0; j + i <= N; ++j)
                    best[i + j] = Math.min(best[i + j], best[j] + 1);
        return best[N];
    }
 
    private int getMax(int x) {
        switch (x) {
            case 1:
                return 0;
            case 2:
                return 1;
            default:
                return 3 * x - 6;
        }
    }
 
}
 
 
// Powered by FileEdit
// Powered by RETester [based on ExampleBuilder]
// Powered by CodeProcessor