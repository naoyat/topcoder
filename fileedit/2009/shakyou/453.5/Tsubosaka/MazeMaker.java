import java.util.*;

public class MazeMaker {
  class Point{
    int x  , y;
    Point(int a , int b){
      x = a;
      y = b;
    }
  }
  public int longestPath(String[] maze, int startRow, int startCol,
      int[] moveRow, int[] moveCol) {
    int H = maze.length;
    int W = maze[0].length();
    int map[][] = new int[H][W];
    for(int i = 0 ; i < H ; i++){
      Arrays.fill(map[i], -1);
    }
    Point init = new Point(startCol , startRow);
    Queue<Point> q = new LinkedList<Point>();
    q.add(init);
    map[startRow][startCol] = 0;
    while(!q.isEmpty()){
      Point cp = q.poll();
      int t = map[cp.y][cp.x];
      for(int k = 0 ; k < moveRow.length ; k++){
        int nx = cp.x + moveCol[k];
        int ny = cp.y + moveRow[k];
        if(nx < 0 || ny < 0 || nx >= W || ny >= H)
          continue;
        if(map[ny][nx] >= 0)
          continue;
        if(maze[ny].charAt(nx) == 'X')
          continue;
        map[ny][nx] = t + 1;
        q.add(new Point(nx , ny));
      }
    }    
//    System.err.println(Arrays.deepToString(map));
    int res = 0;
    for(int i = 0 ; i < H ; i++){
      for(int j = 0 ; j < W ; j++){
        if(maze[i].charAt(j) == 'X')
          continue;
        if(map[i][j] < 0)
          return -1;
        res = Math.max(res, map[i][j]);
      }
    }
    return res;
  }

} 
