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

#define sz(a)  int((a).size())
#define pb  push_back
#define all(c)  (c).begin(),(c).end()
#define mset(arr,val)  memset(arr,val,sizeof(arr))
#define tr(c,i)  for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); i++)
#define rep(var,n)  for(int var=0;var<(n);var++)
#define forr(var,from,to) for(int var=(from);var<=(to);var++) 
#define found(s,e)  ((s).find(e)!=(s).end())
#define remove_(c,val) (c).erase(remove((c).begin(),(c).end(),(val)),(c).end())
#define lastc(str) (*((str).end()-1))

class Underprimes
{
 public:
  int howMany(int A,int B){
    int cnt=0;
    for(int i=A;i<=B;i++){
      if (isunder(i))++cnt;
      return cnt;
    }
    Underprimes(){
      const int n=100000;
      bool s[n+1]={false};
      for(int i=2;i<n;i++){
        if(!s[i]){
          s[i]=true; p.pb(i); for(int j=i+1;j<n;j+=i) s[j]=true;
        }
      }
    }
    bool isunder(int x){
      int cnt=0;
      for(int i=0;i<sz(p)&&x!=1;++i){
        while(x%p[i]==0){
          cnt++; x/=p[i];
        }
      }
      return binary_search(all(p),cnt);
    }
  }
  vector<int> p;
}
