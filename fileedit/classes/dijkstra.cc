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

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<string> vs;
typedef vector<long long> vll;
#define sz(a)  int((a).size())
#define pb  push_back
#define all(c)  (c).begin(),(c).end()
#define mset(arr,val)  memset(arr,val,sizeof(arr))
#define tr(c,i)  for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); i++)
#define rep(var,n)  for(int var=0;var<(n);var++)
#define FOR(var,from,to) for(int var=(from);var<=(to);var++)
#define RFOR(var,from,to) for(int var=(to);var>=(from);var--)
#define found(s,e)  ((s).find(e)!=(s).end())

typedef pair<int,int> i_i;
typedef pair<int,pair<int,int> > i_ii;
#define cons(x,y) make_pair((x),(y))
#define car(x) ((x).first)
#define cdr(x) ((x).second)
#define cadr(x) (x).second.first
#define cddr(x) (x).second.second
//////////////////////////////////////////////////////////
// using rep(),found()

const int DIJKSTRA_1 = 1;
const int DIJKSTRA   = 2;
const int PRIM       = 4;

const int infty = INT_MAX;

template <typename T> T infsum(T a, T b){
  return (a == infty || b == infty)? infty : (a + b);
}

list<int> follow_predecessor(const vector<int>& predecessor, int start_v, int goal_v)
{
  list<int> ans;
  for(int v=goal_v; v!=start_v; v=predecessor[v]) ans.push_back(v);
  ans.push_back(start_v);
  reverse(ans.begin(), ans.end());
  return ans;
}

template <typename T> vector<vector<T> >
arcs_to_edges(vector<vector<T> > arclength)
{
  int N = arclength.size();
  vector<vector<T> > edgelength(N,vector<int>(N,infty));
  for (int i=0; i<N-1; i++){
    for (int j=i+1; j<N; j++){
      T a_ij = arclength[i][j], a_ji = arclength[j][i];
      edgelength[i][j] = edgelength[j][i] = min(a_ij, a_ji);
    }
  }
  return edgelength;
}

//
// dijkstra__(arclength, start_v[, goal_v])
//
//   Input: 弧の長さ arclength[i][j], スタート地点、ゴール地点を与える
//  Output: distance[], predecessor[]
//
template <typename T> pair<vector<T>,vector<int> >
dijkstra_prim_core(int algo, vector<vector<T> > arclength, int start_v, int goal_v=-1)
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
  
  while (((algo & 1) && !found(S, goal_v)) // 指定されたゴールへ
         || ((algo & 6) && S.size() < N)) { // 各点へ
    // find v* from V\S with distance(v*) = min{distance(v):v from V\S}
    int v_ = -1;
    T d_ = infty;
    rep(v,N){
      if (found(S,v)) continue;
      if (distance[v] < d_) { d_ = distance[v]; v_ = v; }
    }
    if (v_ == -1) break;
    S.insert(v_);

    rep(v,N){ // FOR ALL v from V\S DO
      if (found(S,v)) continue;
      T d_; // distance[v]
      switch (algo) {
        case DIJKSTRA: case DIJKSTRA_1:
          d_ = infsum(distance[v_], arclength[v_][v]); break;
        case PRIM:
          d_ = arclength[v_][v]; break;
      }
      if (d_ < distance[v]) {
        distance[v] = d_;
        predecessor[v] = v_;
      }
    }
  }

  return make_pair(distance,predecessor);
}

//
// dijkstra1(arclength, start_v, goal_v)
//
//   Input: 弧の長さ arclength[i][j], スタート地点、ゴール地点を与える
//  Output: スタート地点からゴール地点への経路と距離、のペア
//
template <typename T> pair<list<int>,T>
dijkstra1(vector<vector<T> > arclength, int start_v, int goal_v)
{
  pair<vector<T>,vector<int> > res = dijkstra_prim_core(DIJKSTRA_1, arclength, start_v, goal_v);

  list<int> lis = follow_predecessor(res.second, start_v, goal_v);
  return make_pair(lis, res.first[goal_v]);
}

//
// dijkstra(arclength, start_v)
//
//   Input: 弧の長さ arclength[i][j], スタート地点を与える
//  Output: スタート地点から各点への経路と距離のペア、のベクタ
//
template <typename T> vector<pair<list<int>,T> >
dijkstra(vector<vector<T> > arclength, int start_v)
{
  pair<vector<T>,vector<int> > res = dijkstra_prim_core(DIJKSTRA, arclength, start_v);

  int N = arclength.size();
  vector<pair<list<int>,T> > ans(N);
  rep(v,N){
    list<int> lis = follow_predecessor(res.second, start_v, v);
    ans[v] = make_pair(lis, res.first[v]);
  }
  return ans;
}

/////////////
//
// 最小全域木 - Primのアルゴリズム
//
template <typename T> vector<int>
prim(vector<vector<T> > edgelength, int start_v)
{
  return dijkstra_prim_core(PRIM, edgelength, start_v).second;
}
