#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>
#include <iterator>
#include <functional>
#include <complex>
#include <queue>
#include <stack>
#include <cmath>
#include <cassert>
#include <cstring>
using namespace std;
typedef long long LL;
typedef complex<double> CMP;

class MazeMaker { public:
  int longestPath(vector <string> maze, int startRow, int startCol, vector <int> moveRow, vector <int> moveCol) 
  {
    const int H = maze.size();
    const int W = maze[0].size();
    // constでいけるの？

    typedef pair<int,int> point; // i_i
    // てかこんなところにtypedef!!!

    int cell = 0; rep(y,H) rep(x,W) if(maze[y][x]=='.') ++cell; //空きセル数

    vector<point> q(1, point(startRow, startCol));
    set<point> visited; visited.insert(q[0]);

    for(int step=0 ;; ++step)
    {
      vector<point> q2;
      rep(i,sz(q)) rep(j,sz(moveRow)) {
          int yy = q[i].first+moveRow[j];
          int xx = q[i].second+moveCol[j]; // (yy,xx)=q[i] + move[j]
          point pp( yy, xx );
          if( visited.count(pp) // SET::count() returns always 0 or 1
              || yy<0 || H<=yy || xx<0 || W<=xx
              || maze[yy][xx]!='.' ) continue;
          visited.insert(pp);
          q2.pb(pp);
        }
      q.swap(q2); // q = q2

      if(q.empty()) //おわた
        return (sz(visited)==cell ? step : -1);
    }
    assert(false);
  }
};
