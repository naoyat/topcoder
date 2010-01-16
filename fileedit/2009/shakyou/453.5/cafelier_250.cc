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

    typedef pair<int,int> point;

    int cell = 0;
    for(int y=0; y<H; ++y)
      for(int x=0; x<W; ++x)
        if( maze[y][x] == '.' )
          ++cell;

    vector<point> q(1, point(startRow, startCol));
    set<point> visited; visited.insert(q[0]);

    for(int step=0 ;; ++step)
    {
      vector<point> q2;
      for(int i=0; i<q.size(); ++i)
        for(int j=0; j<moveRow.size(); ++j)
        {
          int yy = q[i].first+moveRow[j];
          int xx = q[i].second+moveCol[j];
          point pp( yy, xx );
          if( visited.count(pp) || yy<0 || H<=yy || xx<0 || W<=xx || maze[yy][xx]!='.' )
            continue;
          visited.insert(pp);
          q2.push_back(pp);
        }
      q.swap(q2);

      if( q.empty() )
        return (visited.size()==cell ? step : -1);
    }
    assert(false);
  }
};
