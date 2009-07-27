#line 2 "StrangeCountry.cpp"
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
using namespace std;
typedef long long ll;
typedef vector<int> vi;
#define sz(a)  int((a).size())
#define pb  push_back
#define all(c)  (c).begin(),(c).end()
#define tr(c,i)  for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); i++)
#define rep(var,n)  for(int var=0;var<(n);var++)
#define found(s,e)  ((s).find(e)!=(s).end())

class StrangeCountry {
 public:
  int transform(vector <string> g) {
	int N=sz(g);
    vi isle(N); rep(i,N) isle[i]=i;
    rep(i,N-1){
      for(int j=i+1;j<N;j++){
        if(g[i][j]=='Y'){
          //isle[j] = isle[i] = min(isle[j],isle[i]);
          int i_=isle[i],j_=isle[j],m_=min(i_,j_);
          rep(k,N) if(isle[k]==i_ || isle[k]==j_) isle[k]=m_;
        }
      }
    }
    vi cnt(N,0);
    rep(i,N) cnt[isle[i]]++;
    // cout << "isle: " << isle << endl;
    // cout << "cnt: " << cnt << endl;
    rep(i,N) if(cnt[i]==1) return -1;
    set<int> ic;
    rep(i,N) if(cnt[i]) ic.insert(i);
    vi hz(N,0);
    rep(i,N-1){
      for(int j=i+1;j<N;j++){
        if(g[i][j]=='Y') hz[isle[i]]++;
      }
    }
    vi ov(N,0);
    rep(i,N) ov[i]=hz[i]-(cnt[i]-1);
    int s=0,k=0;
    tr(ic,it){
      int i=*it;
      k++; s+=ov[i];
    }
    int nz=k-1;
    if(nz>s) return -1;
    return nz;
  }
};





// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003] customized by cafelier, timer support by naoya_t
// Powered by CodeProcessor
