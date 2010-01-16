import static java.lang.Math.*;
import static java.math.BigInteger.*;
import static java.util.Arrays.*;
import static java.util.Collections.*;
import java.math.*;
import java.util.*;

public class MazeMaker {
  public int longestPath(String[] maze, int startRow, int startCol, int[] moveRow, int[] moveCol) {
    int n = maze.length, m = maze[0].length(), k = moveRow.length;
    char[][] cs = new char[n][];
    for (int i = 0; i < n; i++) cs[i] = maze[i].toCharArray();
    Queue<Integer> qx = new LinkedList<Integer>();
    Queue<Integer> qy = new LinkedList<Integer>();
    qx.offer(startRow);
    qy.offer(startCol);
    cs[startRow][startCol] = 'X';
    int res = 0;
    int[][] time = new int[n][m];
    for (int i = 0; i < n; i++) fill(time[i], -1);
    time[startRow][startCol] = 0;
    while (!qx.isEmpty()) {
      int x = qx.poll();
      int y = qy.poll();
      res = time[x][y];
      for (int i = 0; i < k; i++) {
        int x2 = x + moveRow[i], y2 = y + moveCol[i];
        if (0 <= x2 && x2 < n && 0 <= y2 && y2 < m && cs[x2][y2] == '.') {
          cs[x2][y2] = 'X';
          qx.offer(x2);
          qy.offer(y2);
          time[x2][y2] = time[x][y] + 1;
        }
      }
    }
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) if (cs[i][j] == '.') return -1;
    return res;
  }
  void debug(Object...os) {
    System.err.println(deepToString(os));
  }
}
