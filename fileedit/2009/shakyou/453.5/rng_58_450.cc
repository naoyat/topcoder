#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)

#define INF (1<<29)

vector <int> v;
int dp[50010];

class PlanarGraphShop{
  public:

  int bestCount(int N){
    int i,j;
    
    for(i=1;i*i*i<=N;i++){
      int maxe = (i - 2) * 3;
      if(i == 1) maxe = 0;
      if(i == 2) maxe = 1;
      REP(j,maxe+1) if(i*i*i+j*j <= N) v.push_back(i*i*i+j*j);
    }
    
    REP(i,N+1) dp[i] = INF;
    dp[0] = 0;
    REP(i,N+1) REP(j,v.size()) if(v[j] <= i) dp[i] = min(dp[i],dp[i-v[j]]+1);
    
    return dp[N];
  }

};
