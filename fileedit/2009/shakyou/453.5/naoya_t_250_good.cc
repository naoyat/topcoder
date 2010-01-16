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
#include "cout.h"
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

vector<bool> ok;//(NM,false);

const int infty = INT_MAX;

template <typename T> T infsum(T a, T b){
  return (a == infty || b == infty)? infty : (a + b);
}

template <typename T> pair<vector<T>,vector<int> >
dijkstra_core(const vector<vector<T> >& arclength, int start_v)
{
  int N = arclength.size();

  set<int> S;
  vector<T> distance(N, infty); // inftyは適当な大きな数
  vector<int> predecessor(N, -1);

  S.insert(start_v);
  distance[start_v] = 0;

  rep(v,N){
    if (v == start_v) continue;
    if (arclength[start_v][v] == infty) continue;
    
    distance[v] = arclength[start_v][v];
    predecessor[v] = start_v;
  }

  while (S.size() < N) { // 各点へ
    // find v* from V\S with distance(v*) = min{distance(v):v from V\S}
    int v_ = -1;
    T d_ = infty;
    rep(v,N){
      if (found(S,v)) continue;
      if (distance[v] < d_) { d_ = distance[v]; v_ = v; }
    }
    if (v_==-1) break;
    S.insert(v_);

    rep(v,N){ // FOR ALL v from V\S DO
      if (found(S,v)) continue;
      T d_ = infsum(distance[v_], arclength[v_][v]);
      if (d_ < distance[v]) {
        distance[v] = d_;
        predecessor[v] = v_;
      }
    }
  }

  return make_pair(distance,predecessor);
}


class MazeMaker {
 public:
  int longestPath(vector <string> maze, int startRow, int startCol, vector <int> moveRow, vector <int> moveCol) {
    int N=sz(maze), M=sz(maze[0]), NM=N*M, Z=sz(moveRow);

    ok.resize(NM); rep(i,NM) ok[i]=false;
    rep(r,N)rep(c,M) if(maze[r][c]=='.') ok[M*r + c] = true;
    
    vector<vector<int> > ar(NM,vector<int>(NM,infty));
    int start=M*startRow + startCol;

    rep(ri,N)rep(ci,M){
      int i = M*ri + ci; if (!ok[i]) continue;
      rep(z,Z){
        int rj=ri+moveRow[z], cj=ci+moveCol[z];
        if(0<=rj && rj<N && 0<=cj && cj<M){
          int j = M*rj + cj; ar[i][j]=1;
        }
      }
    }

    pair<vector<int>,vector<int> > res = dijkstra_core(ar, start);
    vector<int> distances = res.first;
    int dmax=0;
    rep(i,NM){
      if (i==start || !ok[i]) continue;
      int d=distances[i]; if (d==infty) return -1;
      if (d>dmax) dmax=d;
    }
    return dmax;
  }
};
