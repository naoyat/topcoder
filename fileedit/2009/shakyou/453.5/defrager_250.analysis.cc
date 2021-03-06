#include <assert.h> 
#include <ctype.h> 
#include <float.h> 
#include <math.h> 
#include <stdio.h> 
#include <string> 
#include <stdlib.h> 
#include <time.h> 
#include <algorithm> 
#include <numeric> 
#include <functional> 
#include <utility> 
#include <vector> 
#include <list> 
#include <set> 
#include <map> 
#include <queue> 
#include <stack> 
#include <sstream> 
#include <iostream> 

using namespace std;

#define rep(i,n) for(int i=0;i<(n);++i)
#define all(c) (c).begin(), (c).end() 
#define clr(a,b) memset(a,b,sizeof(a)); 
#define inf 1 << 29

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<string> vs;
typedef vector<int> vi;

class MazeMaker 
{
public:
  int longestPath(vector<string> maze, int startRow, int startCol, vector<int> moveRow, vector<int> moveCol) 
  {
    int N = sz(maze), M=sz(maze[0]);
    vector<vector<int> > vis(N, vector<int>(M, -1)); // vis[N][M] = { ALL -1 }

    queue<i_i> q;
    q.push(cons(startRow, startCol));
    vis[startRow][startCol] = 0;

    while (!q.empty()){
      pii top = q.front(); q.pop();

      rep(i,sz(move)){
        int ny = top.first + moveRow[i];
        int nx = top.second + moveCol[i];
        if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;

        if (vis[ny][nx] != -1) continue; // ignore if visited
        if (maze[ny][nx] != '.') continue;

        q.push(cons(ny, nx));
        vis[ny][nx] = vis[top.first][top.second] + 1;
      }
    }

    int ans = 0;
    rep(i,N) rep(j,M){
      if (maze[i][j] != '.') continue;
      if (vis[i][j] == -1) return -1;
      ans = max(ans, vis[i][j]);
    }
  
    return ans;
  }
};
