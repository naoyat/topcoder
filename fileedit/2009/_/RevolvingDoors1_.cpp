#line 2 "RevolvingDoors.cpp"
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
typedef vector<vector<int> > vvi;
typedef vector<string> vs;
typedef vector<long long> vll;
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

class RevolvingDoors {
  int w,h;
  
  inline int cell(int x,int y){return (y<<6)|x;}
  inline int cellx(int c){return c&63;}
  inline int celly(int c){return c>>6;}

  inline int left(int c){return c-1;}
  inline int right(int c){return c+1;}
  inline int up(int c){return c-64;}
  inline int down(int c){return c+64;}
 public:
  int turns(vector<string> m) {
    h=sz(m),w=sz(m[0]);

    vector<bool> road(4096,false);
    //vector<int> score(4096,INT_MAX);
    vector<vector<int> > score(4096);
    //rep(i,4096){set<int> s; visited[i]=s;}
    //vector<bool> door(4096,false);
    vector<int> doors, doormap(4096,-1), doorof(4096,-1);
    int doorcnt=0, start_cell=0, end_cell=0;

    // pass1
    rep(y,h){
      rep(x,w){
        int c=cell(x+1,y+1);
        switch(m[y][x]){
          case 'S': road[c]=true; start_cell=c; break;
          case 'E': road[c]=true; end_cell=c; break;
          case 'O': road[c]=false; doormap[c]=doorcnt++; doors.pb(c); break;
          case '-': road[c]=true; break;
          case '|': road[c]=true; break;
          case '#': road[c]=false; break;
          case ' ': road[c]=true; break;
        }
      }
    }
    
    int nm=1<<doorcnt;
    rep(i,4096){
      score[i].resize(nm); rep(j,nm) score[i][j]=INT_MAX;
    }
    
    int doorstat = 0;
    // pass2
    rep(y,h){
      rep(x,w){
        int c=cell(x+1,y+1), r,l,u,d,did=-1;
        switch(m[y][x]){
          case 'O': case '#': break;
          case '-':
            r=right(c),l=left(c);
            if(doormap[r]>=0) did=doormap[r];
            else if(doormap[l]>=0) did=doormap[l];
            doorof[c]=did;
            // doorstat |= (1 << did);
            break;
          case '|':
            u=up(c),d=down(c);
            if(doormap[u]>=0) did=doormap[u];
            else if(doormap[d]>=0) did=doormap[d];
            doorof[c]=did;
            doorstat |= (1 << did);
            break;
          case ' ': case 'S': case 'E':
            r=right(c),l=left(c),u=up(c),d=down(c);
            if(doormap[r]>=0) did=doormap[r];
            else if(doormap[l]>=0) did=doormap[l];
            else if(doormap[u]>=0) did=doormap[u];
            else if(doormap[d]>=0) did=doormap[d];
            doorof[c]=did;
            break;
        }
      }
    }

    priority_queue<pair<int,pair<int,int> > > pq; // -score,loc,doorstat
    pq.push(make_pair(0,make_pair(start_cell,doorstat)));

    vector<int> goaled; int goaled_min=INT_MAX;
    
    while(!pq.empty()){
      pair<int,pair<int,int> > p=pq.top(); pq.pop();
      int sc=-p.first, c=p.second.first, ds=p.second.second;
      if (sc>goaled_min) break;
      if (score[c][ds]<=sc) continue;
      score[c][ds]=sc;
      if(c==end_cell) {
        if (sc<goaled_min) {
          goaled_min=sc; goaled.pb(sc); }
        continue;
      }
      int nxt[4] = { up(c), right(c), down(c), left(c) };
      rep(i,4){
        int c_=nxt[i];
        if(!road[c_]) continue;
        int did=doorof[c_];
        if(did>=0){ // ドアな可能性あり
          int dcell=doors[did], ofs=c_-dcell; if(ofs<0) ofs=-ofs;
          int mask=1<<did;
          int st=ds & mask;
          if(st && ofs==64) { // |
            if (c-c_ != c_-dcell){ //回転出来る
              pq.push(make_pair(-(sc+1),make_pair(c_,ds-mask)));
            }
          } else if(!st && ofs==1){ // -
            if (c-c_ != c_-dcell){ //回転出来る
              pq.push(make_pair(-(sc+1),make_pair(c_,ds+mask)));
            }
          } else {
            // ドアなし
            pq.push(make_pair(-sc,make_pair(c_,ds)));
          }
        }else{
          pq.push(make_pair(-sc,make_pair(c_,ds)));
        }
      }
    }

    if(sz(goaled) > 0){
      sort(all(goaled));
      return goaled[0];
    } else {
      return -1;
    }
  }
};





// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003] customized by cafelier, timer support by naoya_t
// Powered by CodeProcessor
