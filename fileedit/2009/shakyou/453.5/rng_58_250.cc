#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)

#define INF (1<<29)
int dist[60][60];

class MazeMaker{
  public:

  int longestPath(vector <string> maze, int startRow, int startCol, vector <int> moveRow, vector <int> moveCol){
    int m=maze.size(),n=maze[0].length(),i,j;
    
    REP(i,m) REP(j,n) dist[i][j] = INF;
    dist[startRow][startCol] = 0;
    
    queue <pair <int, int> > q;
    q.push(make_pair(startRow,startCol));
    
    while(!q.empty()){
      int x=q.front().first,y=q.front().second; q.pop();
      REP(i,moveRow.size()){
        int x2 = x + moveRow[i];
        int y2 = y + moveCol[i];
        if(x2 >= 0 && x2 < m && y2 >= 0 && y2 < n && maze[x2][y2] == '.' && dist[x2][y2] == INF){
          q.push(make_pair(x2,y2));
          dist[x2][y2] = dist[x][y] + 1;
        }
      }
    }
    
    int ans = 0;
    REP(i,m) REP(j,n) if(maze[i][j] == '.') ans = max(ans,dist[i][j]);
    if(ans == INF) return -1;
    return ans;
  }

};
