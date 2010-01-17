#line 2 "TheBlackJackDivOne.cpp"
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
#define sz(a)  int((a).size())
#define pb  push_back
#define all(c)  (c).begin(),(c).end()
#define mset(arr,val)  memset(arr,val,sizeof(arr))
#define tr(c,i)  for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); i++)
#define rep(var,n)  for(int var=0;var<(n);var++)
#define found(s,e)  ((s).find(e)!=(s).end())

class TheBlackJackDivOne {
  vector<int> rest;
  
  int cval(int c){
    if ('0'<=c &&c<='9')return c-'0';
    switch(c){
      case 'T':case'J':case'Q':case 'K': return 10;
      case 'A': return 11;
    }
  }
    
 public:
  double sb(double r,int re,int to,int ma){
    double d=0;
    //cout << r ;
    //printf(" sb(re=%d,to=%d,ma=%d) ", re,to,ma); cout << rest << endl;
    for(int i=1;i<=11;i++){
      if(rest[i]==0) continue;

      double m_ = 1.0*rest[i]/re;
      int to_ = to - i;

      if(to_<=0) { d += r*ma*m_; continue; }

      rest[i]--;
      d += sb(r*m_,re-1,to_,ma+1);
      rest[i]++;
    }
    return d;
  }
  
  double expected(vector<string> cards) {
    int i;
    rest.resize(12); rep(i,12) rest[i]=0;
    for(i=2;i<=9;i++) rest[i]+=4;
    rest[10]+=16; rest[11]+=4;
    
    int n=sz(cards);
    //cout << rest << endl;
    vector<int> v(n);
    int sc=0;
    rep(i,n){
      int c = cval(cards[i][0]);
      v[i] = c;
      rest[c]--;
      sc+=c;
      //      if(sc>21) return 0.0;
      if(sc>=21) return 0.0;
    }

    return sb(1.0, 52-n,21-sc,1);
  }
};





// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003] customized by cafelier, timer support by naoya_t
// Powered by CodeProcessor
