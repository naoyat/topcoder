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

typedef pair<int,int> i_i;
typedef pair<double,double> d_d;

const double pi = 3.141592653589793238462643383279;
const double epsilon = 1.0e-7, epsilon2 = epsilon * sqrt(2), eps = epsilon*8;//epsilon*10;//1.0e-6;

int N = 3;
vector<double> px(N), py(N);

double dmax(double cx,double cy){
  double dmax_=0;
  rep(i,N){
    double d = hypot(px[i]-cx,py[i]-cy);
    if (d>dmax_) dmax_=d;
  }
  // printf("dmax(%g,%g) = %g\n", cx,cy,res);
  return dmax_;
}

/*d_d rd(double cx,double cy){
  return make_pair( dmax(cx+1e-9,cy) - dmax(cx,cy),
                    dmax(cx,cy+1e-9) - dmax(cx,cy) );
                    }*/
#define DDIV 16

double dd(double cx,double cy,double theta){
  return -(dmax(cx+epsilon*cos(theta), cy+epsilon*sin(theta)) - dmax(cx,cy))/epsilon;
}

double qmid(double cx,double cy,double th_a,double th_b){
  th_a = fmod(th_a,pi*2);
  th_b = fmod(th_b,pi*2);
  if (th_b < th_a) th_b += pi*2;
  //  printf("qmid( center:(%g,%g), theta:[%g..%g] )\n", cx,cy, th_a,th_b);
  double th_m = (th_a + th_b)/2;
  if (th_b - th_a < epsilon/8) return th_m;
  
  double d[3], ddmax=0;
  d[0] = dd(cx,cy,th_a);
  d[1] = dd(cx,cy,th_m);
  d[2] = dd(cx,cy,th_b);

  int at=-1;
  rep(i,3) if(d[i]>=ddmax){ ddmax=d[i]; at=i; }
  if (at==1) at = (d[0] >= d[2])? 0 : 2;
  switch (at) {
    case 0: return qmid(cx,cy,th_a,th_m);
    case 2: return qmid(cx,cy,th_m,th_b);
    default: return -1;//printf("at=%d ... th(%g,%g,%g)\n",at, th_a,th_m,th_b); return -1;
  }
}

double qm(double cx,double cy){
  double th0 = qmid(cx,cy, 0,pi), dm0 = dd(cx,cy,th0);
  double th1 = qmid(cx,cy, pi,pi*2), dm1 = dd(cx,cy,th1);
  return (dm0 < dm1)? th1 : th0;
}

d_d halve(double x0,double x1, double y0,double y1, int dir)
{
  double eps = epsilon * 5;
  switch (dir) {
    case 0: // horizontal break
      {
        double ym = (y0+y1)/2;
        printf("horizontal break: x:[%g..%g], y:[%g..%g], ym:%g\n", x0,x1, y0,y1,ym);
        if (y1 - y0 < epsilon) return make_pair((x0+x1)/2,ym);
        
        int c0=0, c1=0;
        for (double x=x0; x<=x1; x+=(x1-x0)/12){
          double th = qm(x,ym);
          if (th >= 0) {
            if (th > pi) th -= pi*2;
            printf("  (%g,%g): %g\n", x,ym, th);
            if (0+eps < th && th < pi-eps) c0++;
            else if (-pi+eps < th && th < 0-eps) c1++;
          }
        }
        printf("  c0:%d, c1:%d\n", c0, c1);
        if (c0 + c1 == 0) return halve(x0,x1, ym,ym, 0);
        if (c0 < c1) return halve(x0,x1, y0,ym, 1);
        else         return halve(x0,x1, ym,y1, 1);
      }
      break;
    case 1: // vertical break
      {
        double xm = (x0+x1)/2;
        printf("vertical break: x:[%g..%g], xm:%g, y:[%g..%g]\n", x0,x1,xm, y0,y1);
        if (x1 - x0 < epsilon) return make_pair(xm,(y0+y1)/2);

        int c0=0, c1=0;
        for (double y=y0; y<=y1; y+=(y1-y0)/12){
          double th = qm(xm,y);
          if (th >= 0) {
            if (th > pi) th -= pi*2;
            printf("  (%g,%g): %g\n", xm,y, th);
            if (0+eps < th && th < pi-eps) c0++;
            else if (-pi+eps < th && th < 0-eps) c1++;
          }
        }
        printf("  c0:%d, c1:%d\n", c0, c1);
        if (c0 + c1 == 0) return halve(xm,xm, y0,y1, 1);
        if (c0 < c1) return halve(x0,xm, y0,y1, 0);
        else         return halve(xm,x1, y0,y1, 0);
      }
      break;
  }
}

main(){
  rep(i,N) {
    // double th = 3.14159265358979323846*2*i/N;
    double th = pi*2*i/(N+2);
    px[i] = cos(th)*100;
    py[i] = sin(th)*100;
    printf(" (%g,%g)", px[i],py[i]);
  }
  cout << endl;
  // printf("px: %d - %d\n", *min_element(all(px)), *max_element(all(px)) );
  // printf("py: %d - %d\n", *min_element(all(py)), *max_element(all(py)) );

  double theta = qm(0,0);
  d_d bottom = halve(-100,100, -100,100, 0);//epsilon*cos(theta),epsilon*sin(theta));
  printf("%g at (%g,%g)\n", dmax(bottom.first,bottom.second), bottom.first, bottom.second);
  return 0;
}
