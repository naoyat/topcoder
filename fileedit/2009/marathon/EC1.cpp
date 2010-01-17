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
typedef pair<int,int> i_i;
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
#define for_(var,from,to) for(int var=(from);var<=(to);var++)
#define forr(var,from,to) for(int var=(to);var>=(from);var--)
#define found(s,e)  ((s).find(e)!=(s).end())
#define remove_(c,val) (c).erase(remove((c).begin(),(c).end(),(val)),(c).end())
#define lastc(str) (*((str).end()-1))
const double pi = 3.141592653589793238462643383279;
inline bool valid_radius_p(double r) { return (r >= 0.1); }
inline bool inside_p(double cx, double cy, double r, int px, int py) {
  return ((cx-px)*(cx-px) + (cy-py)*(cy-py) <= r*r);
}
class EnclosingCircles {
  string circle(double centerX, double centerY, double radius) {
    char buf[40];
    sprintf(buf,"%1.8f %1.8f %1.8f", centerX, centerY, radius + 1e-8);
    return string(buf);
  }
  
 public:
  vector<int> generateTestCase(int testNumber) {
    int M, N;
    vector<int> pointX, pointY;
    
    switch (testNumber) {
      case 0:
        M = 10;
        N = 512; pointX.resize(N); pointY.resize(N);
        rep(i,N) pointX[i] = pointY[i] = i;
        break;
      case 1:
        M = 12;
        N = 12; pointX.resize(N); pointY.resize(N);
        pointX[0] = pointX[4] = pointX[6] = pointX[8] = 0;
        pointX[1]                         = pointX[9] = 170;
        pointX[2]                         = pointX[10] = 341;
        pointX[3] = pointX[5] = pointX[7] = pointX[11] = 511;
        pointY[0] = pointY[1] = pointY[2] = pointY[3] = 0;
        pointY[4]                         = pointY[5] = 170;
        pointY[6]                         = pointY[7] = 341;
        pointY[8] = pointY[9] = pointY[10] = pointY[11] = 511;
        break;
      case 2: case 3: case 4: case 5: case 6: case 7: case 8: case 9:
      case 10:
      default:
        {
          vector<int> empty_case;
          return empty_case;
        }
        break;
    }
    
    vector<int> res(2+N+N);
    res[0] = M; res[1] = N;
    rep(i,N) res[2+i] = pointX[i], res[2+N+i] = pointY[i];
    return res;
  }
  
  vector<string> placeCircles(vector<int> pointX, vector<int> pointY, int M) {
    int N = sz(pointX);
    if (M > N) M = N;
    vector<string> res;
    vector<vector<double> > ds(N,vector<double>(N,10000));
    map<int,int> boss;
    vector<set<i_i> > group(M,set<i_i>());
    {
      double furthest = -1; int p0, p1;
      for_(i,0,N-1) {
        for_(j,i+1,N-1) {
          double d = hypot(pointX[i]-pointX[j], pointY[i]-pointY[j]);
          ds[i][j] = ds[j][i] = d;
          if (d > furthest) { furthest = d; p0 = i; p1 = j; }
        }
      }
      boss[p0]=0; group[0].insert(make_pair(pointX[p0],pointY[p0]));
      boss[p1]=1; group[1].insert(make_pair(pointX[p1],pointY[p1]));
    }
    for_(k,2,M-1) {
      double furthest = -1; int p;
      rep(j,N){
        if (found(boss,j)) continue;
        double nearest = 10000;
        tr(boss,it){
          int i=it->first;
          if (ds[i][j] < nearest) nearest = ds[i][j];
        }
        if (nearest > furthest) { furthest = nearest; p = j; }
      }
      
      boss[p]=k; group[k].insert(make_pair(pointX[p],pointY[p]));
    }
    rep(j,N){
      if (found(boss,j)) continue;
      double nearest = 10000; int b;
      tr(boss,it){
        int i=it->first;
        if (ds[i][j] < nearest) { nearest = ds[i][j]; b = it->second; }
      }
      group[b].insert(make_pair(pointX[j],pointY[j]));
    }
    rep(i,M){
      double cx, cy, r;
      get_wrapper(cx,cy,r, group[i]);
      res.pb(circle(cx,cy,r));
    }
    return res;
  }
  
  void get_wrapper(double &cx,double &cy,double &r, set<i_i> group) {
    int xmin=10000,xmax=-1, ymin=10000,ymax=-1;
    tr(group,it){
      int x=it->first, y=it->second;
      if (x<xmin) xmin=x; if (x>xmax) xmax=x;
      if (y<ymin) ymin=y; if (y>ymax) ymax=y;
    }
    cx = 0.5*(xmin + xmax);
    cy = 0.5*(ymin + ymax);
    r = 0.5*hypot(xmax-xmin,ymax-ymin) + 1e-9;
    if (r < 0.1) r = 0.1;
  }
};
