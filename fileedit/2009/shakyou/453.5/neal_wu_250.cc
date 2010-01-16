#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;
 
const int MAX = 55, INF = 1000000005;
 
int R, C, dist [MAX][MAX];
int front, back, rq [MAX * MAX], cq [MAX * MAX];
 
struct MazeMaker
{
    int longestPath (vector <string> maze, int startRow, int startCol, vector <int> moveRow, vector <int> moveCol)
    {
        R = maze.size ();
        C = maze [0].length ();
        memset (dist, 63, sizeof (dist));
        front = back = dist [startRow][startCol] = 0;
        rq [back] = startRow; cq [back] = startCol; back++;
 
        while (front < back)
        {
            int r = rq [front], c = cq [front]; front++;
 
            for (int i = 0; i < (int) moveRow.size (); i++)
            {
                int nr = r + moveRow [i], nc = c + moveCol [i];
 
                if (nr >= 0 && nr < R && nc >= 0 && nc < C && maze [nr][nc] == '.' && dist [r][c] + 1 < dist [nr][nc])
                {
                    dist [nr][nc] = dist [r][c] + 1;
                    rq [back] = nr; cq [back] = nc; back++;
                }
            }
        }
 
        int far = 0;
 
        for (int i = 0; i < R; i++)
            for (int j = 0; j < C; j++)
                if (maze [i][j] == '.')
                    far = max (far, dist [i][j]);
 
        return far < INF ? far : -1;
    }
};
