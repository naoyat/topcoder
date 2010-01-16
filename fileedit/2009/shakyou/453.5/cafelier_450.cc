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

class PlanarGraphShop { public:
  int bestCount(int N) 
  {
    set<int> possible;
    possible.insert(1*1*1 + 0*0);
    possible.insert(2*2*2 + 0*0);
    possible.insert(2*2*2 + 1*1);
    for(int V=3,EMax=3; V*V*V<=N; ++V,EMax+=3)
      for(int E=0; V*V*V+E*E<=N && E<=EMax; ++E)
        possible.insert(V*V*V + E*E);
    vector<int> p(possible.rbegin(), possible.rend());

    vector<int> q(1, 0);
    vector<bool> visited(N+1);
    for(int step=0 ;; ++step)
    {
      vector<int> q2;
      for(int i=0; i!=q.size(); ++i)
      {
        if( q[i] == N ) 
          return step;

        for(int j=0; j<p.size(); ++j)
        {
          int next = q[i] + p[j];
          if( next>N || visited[next] )
            continue;
          visited[next] = true;
          q2.push_back(next);
        }
      }
      q.swap(q2);
    }
    assert(false);
  }
};
