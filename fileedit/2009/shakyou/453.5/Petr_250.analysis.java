import java.util.*;
 
public class MazeMaker {
    public int longestPath(String[] maze, int startRow, int startCol, int[] moveRow, int[] moveCol) {
      int height = sz(maze), width = sz(maze[0]);
      i_i q[height * width];
      int qh = 1;
      int qt = 0;

      q[0] = (startRow . startCol);

      int[][] mark = new int[height][width];
      mark[startRow][startCol] = 1;
      
      while (qt < qh) {
        (crow . ccol) = q[qt++];
        rep(i,sz(move)){
          (nrow . ncol) = (crow . ccol) + move[i]
              if (nrow >= 0 && nrow < height && ncol >= 0 && ncol < width) {
                if (maze[nrow][ncol] == '.' && mark[nrow][ncol] == 0) {
                  mark[nrow][ncol] = mark[crow][ccol] + 1;
                  q[qh++] = (nrow . ncol);
                }
              }
        }
      }

        int res = 0;
        rep(row,height) rep(col,width)
            if (maze[row].charAt(col) == '.') {
              if (mark[row][col] == 0) return -1;
              res = Math.max(res, mark[row][col] - 1);
            }
        return res;
    }
}
