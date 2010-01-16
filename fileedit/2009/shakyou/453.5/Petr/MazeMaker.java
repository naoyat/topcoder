import java.util.*;
 
public class MazeMaker {
    public int longestPath(String[] maze, int startRow, int startCol, int[] moveRow, int[] moveCol) {
        int height = maze.length;
        int width = maze[0].length();
        int[] qrow = new int[height * width];
        int[] qcol = new int[height * width];
        int qh = 1;
        int qt = 0;
        qrow[0] = startRow;
        qcol[0] = startCol;
        int[][] mark = new int[height][width];
        mark[startRow][startCol] = 1;
        while (qt < qh) {
            int crow = qrow[qt];
            int ccol = qcol[qt];
            ++qt;
            for (int i = 0; i < moveRow.length; ++i) {
                int nrow = crow + moveRow[i];
                int ncol = ccol + moveCol[i];
                if (nrow >= 0 && nrow < height && ncol >= 0 && ncol < width) {
                    if (maze[nrow].charAt(ncol) == '.' && mark[nrow][ncol] == 0) {
                        mark[nrow][ncol] = mark[crow][ccol] + 1;
                        qrow[qh] = nrow;
                        qcol[qh] = ncol;
                        ++qh;
                    }
                }
            }
        }
        int res = 0;
        for (int row = 0; row < height; ++row)
            for (int col = 0; col < width; ++col)
                if (maze[row].charAt(col) == '.') {
                    if (mark[row][col] == 0)
                        return -1;
                    res = Math.max(res, mark[row][col] - 1);
                }
        return res;
    }
}
