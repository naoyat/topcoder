#include <vector>
using namespace std;
//
// Union Find  -- from http://www.prefield.com/algorithm/container/union_find.html


// union_set(x,y)
//    x が入っている集合と y が入っている集合を併合する．
// find_set(x,y)
//    x と y が同じ集合に入っているかどうかを判定する．
// make_set(x)
//    x のみが入る集合 {x} を作る． 
//
class UnionFind {
  vector<int> data;
 public:
  UnionFind(int size) : data(size, -1) { }
  bool unionSet(int x, int y) {
    x = root(x); y = root(y);
    if (x != y) {
      if (data[y] < data[x]) swap(x, y);
      data[x] += data[y]; data[y] = x;
    }
    return x != y;
  }
  bool findSet(int x, int y) { return root(x) == root(y); }
  int root(int x) { return data[x] < 0 ? x : data[x] = root(data[x]); }
  int size(int x) { return -data[root(x)]; }
};
/**
    UnionFind uf(sz(segments));

    tr(nodes,nt){
      set<int> arcs = nt->second;
      vector<int> av(all(arcs)); FOR(i,1,sz(av)-1) uf.unionSet(av[0],av[i]);
    }

    map<int,int> isles;
    rep(i,sz(segments)) {
      if (deleted[i]) continue;
      int root = uf.root(i);
      if (!found(isles,root)) isles[root] = 0;
    }

    // again
    tr(nodes,nt){
      point node = nt->first;
      set<int> arcs = nt->second;
      vector<int> av(all(arcs));
      int root = uf.root(av[0]);
      if (oddp(sz(arcs)*n)) isles[root]++;
    }
    tr(isles,it) { it->second /= 2; }
    int ans = sz(isles)-1;
    tr(isles,it) {
      if (it->second == 0) continue;
      ans += it->second - 1;
    }
   
    return ans;
  }
*/

