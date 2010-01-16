#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

#define SIZE(X) ((int)(X.size()))
#define LENGTH(X) ((int)(X.length()))
#define MP(X,Y) make_pair(X,Y)
template<class T> inline void checkmax(T &a,T b){if(b>a) a=b;}
typedef pair<int,int> ipair;

class MazeMaker
{
public:
  int longestPath(vector <string> G, int sX, int sY, vector <int> mX, vector <int> mY)
  {
    vector<ipair> Q;
    int D[60][60];
    memset(D,255,sizeof(D));
    int sizeX=SIZE(G);
    int sizeY=LENGTH(G[0]);
    D[sX][sY]=0;
    Q.push_back(MP(sX,sY));
    for (int cl=0;cl<SIZE(Q);cl++)
    {
      int x=Q[cl].first;
      int y=Q[cl].second;
      for (int i=0;i<SIZE(mX);i++)
      {
        int x2=x+mX[i];
        int y2=y+mY[i];
        if (x2>=0 && x2<sizeX && y2>=0 && y2<sizeY && D[x2][y2]<0 && G[x2][y2]=='.')
        {
          D[x2][y2]=D[x][y]+1;
          Q.push_back(MP(x2,y2));
        }
      }
    }
    int R=0;
    for (int i=0;i<sizeX;i++)
      for (int j=0;j<sizeY;j++) if (G[i][j]=='.')
        if (D[i][j]<0)
          return -1;
        else
          checkmax(R,D[i][j]);
    return R;
  }
};
