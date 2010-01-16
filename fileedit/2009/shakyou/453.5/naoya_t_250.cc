#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <cctype>
#include <algorithm>
#include <string>
#include <vector>
#include <deque>
#include <stack>
#include <queue>
#include <list>
#include <map>
#include <set>
// BEGIN CUT HERE
#include "cout.h"
// END CUT HERE
using namespace std;
#define sz(a)  int((a).size())
#define pb  push_back
#define all(c)  (c).begin(),(c).end()
#define tr(c,i)  for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); i++)
#define rep(var,n)  for(int var=0;var<(n);var++)
#define found(s,e)  ((s).find(e)!=(s).end())

typedef pair<int,int> i_i;
typedef pair<int,pair<int,int> > i_ii;
#define cons(x,y) make_pair((x),(y))
#define car(x) ((x).first)
#define cdr(x) ((x).second)
#define cadr(x) (x).second.first
#define cddr(x) (x).second.second

class MazeMaker {
 public:
  int longestPath(vector <string> maze, int startRow, int startCol, vector <int> moveRow, vector <int> moveCol) {
    int N=sz(maze), M=sz(maze[0]), NM=0, Z=sz(moveRow);
    rep(r,N)rep(c,M) if(maze[r][c]=='.')NM++;
    vector<vector<int> > vd(N,vector<int>(M,INT_MAX)); int vdc=0;
    vector<vector<i_i> > v(2,vector<i_i>(0));
    v[0].pb( cons(startRow,startCol) );
    for(int i=0;;i++){
      int i0=i%2, i1=(i+1)%2;
      v[i1].clear();
      tr(v[i0],it){
        int r=it->first, c=it->second;
        if (maze[r][c]=='X') continue;
        if (vd[r][c]<i) continue;
        if (vd[r][c]==INT_MAX) vdc++;
        vd[r][c]=i;
        if (vdc == NM) break;
        rep(z,Z){
          int r2 = r + moveRow[z]; if (r2 < 0 || N <= r2) continue;
          int c2 = c + moveCol[z]; if (c2 < 0 || M <= c2) continue;
          v[i1].pb( cons(r2,c2) );
        }
      }
      if (sz(v[i1])==0) break;
    }
    if (vdc < NM) return -1;
    int mx=0;
    rep(r,N)rep(c,M) {
      if (vd[r][c]==INT_MAX) continue;
      if (vd[r][c]>mx)mx=vd[r][c];
    }
    return mx<INT_MAX ? mx : -1;
  }
};
