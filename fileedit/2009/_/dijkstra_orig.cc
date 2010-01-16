#include <string>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <algorithm>
// BEGIN CUT HERE
#include <iostream>
#include "cout.h"
// END CUT HERE
#include <sstream>
#include <cmath>
using namespace std;

#define sz(a)  int((a).size())
#define pb  push_back
#define all(c)  (c).begin(),(c).end()
#define tr(c,i)  for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); i++)

#define exists(s,e) ((s).find(e)!=(s).end())

pair<int,list<int> > dijkstra(vector<vector<int> > arclength, int s, int z)
{
  int N = arclength.size();
  vector<int> distance(N,-1);
  vector<int> predecessor(N,-1);

  set<int> S; S.insert(s);
  distance[s] = 0;

  for (int v=0; v<N; v++) {
	if (v == s) continue;
	distance[v] = arclength[s][v];
	predecessor[v] = s;
  }

  while (!exists(S,z)) {
	int distance_min = INT_MAX;
	int distance_min_at = -1;
	for (int v=0; v<N; v++) {
	  if (exists(S,v)) continue; // V-S
	  if (distance[v] < distance_min) {
		distance_min = distance[v];
		distance_min_at = v;
	  }
	}
	int v_ = distance_min_at;
	S.insert(v_);
	for (int v=0; v<N; v++) {
	  if (exists(S,v)) continue;
	  if (distance[v_] + arclength[v_][v] < distance[v]) {
		distance[v] = distance[v_] + arclength[v_][v];
		predecessor[v] = v_;
	  }
	}
  }

  list<int> path;
  for (int p=z; p!=s; p=predecessor[p]) path.push_front(p);
  path.push_front(s);
  return make_pair(distance[z],path);
}

#define S 0
#define A 1
#define B 2
#define C 3
#define D 4
#define E 5
#define F 6
#define Z 7

main()
{
  vector<vector<int> > arclength(8);
  tr(arclength,a) { a->resize(8); tr(*a,b) *b = 10000; } // 適当な大きい数値

  arclength[S][A] = 3;
  arclength[S][B] = 5;

  arclength[A][B] = 1;
  arclength[A][C] = 10;
  arclength[A][D] = 11;

  arclength[B][A] = 3;
  arclength[B][C] = 2;
  arclength[B][D] = 3;

  arclength[C][D] = 2;
  arclength[C][E] = 7;
  arclength[C][F] = 12;

  arclength[D][A] = 15;
  arclength[D][B] = 7;
  arclength[D][F] = 2;

  arclength[E][D] = 11;
  arclength[E][Z] = 2;

  arclength[F][E] = 3;
  arclength[F][Z] = 2;

  pair<int,list<int> > ans = dijkstra(arclength, S, Z);

  cout << ans.first << endl;
  cout << ans.second << endl;
}
