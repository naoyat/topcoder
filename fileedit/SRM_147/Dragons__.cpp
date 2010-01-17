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
#define sz(a)  int((a).size())
#define pb  push_back
#define FOR(var,from,to) for(int var=(from);var<=(to);var++)
#define rep(var,n)  for(int var=0;var<(n);var++)
#define all(c)  (c).begin(),(c).end()

#include "Fraction.h"

enum { FR=0, BK,UP,DN,LF,RG };

main()
{
  vector<vector<Fraction<ll> > > bowl(2,vector<Fraction<ll> >(6));

  ll max_denom = 0LL;

  const int tmax = 4; // 1..1000
  const int rounds = 45 + 10;
  
  rep(j0,tmax) rep(j1,tmax) rep(j2,tmax) rep(j3,tmax) rep(j4,tmax) rep(j5,tmax) {
    bowl[0][0].init(j0,1);
    bowl[0][1].init(j1,1);
    bowl[0][2].init(j2,1);
    bowl[0][3].init(j3,1);
    bowl[0][4].init(j4,1);
    bowl[0][5].init(j5,1);
    /*
    rep(i,6) bowl[1][i].init(0,1);
    printf("%d,%d,%d,%d,%d,%d: ", j0,j1,j2,j3,j4,j5);
    cout << bowl[0] << endl;
    */
    rep(r,rounds){
      int i0=r%2, i1=(r+1)%2;
      bowl[i1][FR] = (bowl[i0][UP] + bowl[i0][DN] + bowl[i0][LF] + bowl[i0][RG])/4;
      bowl[i1][BK] = (bowl[i0][UP] + bowl[i0][DN] + bowl[i0][LF] + bowl[i0][RG])/4;
      bowl[i1][UP] = (bowl[i0][FR] + bowl[i0][BK] + bowl[i0][LF] + bowl[i0][RG])/4;
      bowl[i1][DN] = (bowl[i0][FR] + bowl[i0][BK] + bowl[i0][LF] + bowl[i0][RG])/4;
      bowl[i1][LF] = (bowl[i0][FR] + bowl[i0][BK] + bowl[i0][UP] + bowl[i0][DN])/4;
      bowl[i1][RG] = (bowl[i0][FR] + bowl[i0][BK] + bowl[i0][UP] + bowl[i0][DN])/4;

      rep(i,6) max_denom = max(max_denom, bowl[45%2][i].denominator());
    }
  }
  
  cout << max_denom << endl;
}

