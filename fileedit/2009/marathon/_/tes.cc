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

double qmid(double cx,double cy,double th_a,double th_b){
  th_a = fmod(th_a,pi*2);
  th_b = fmod(th_b,pi*2);
  if (th_b <= th_a) th_b += pi*2;
  //  printf("qmid( center:(%g,%g), theta:[%g..%g] )\n", cx,cy, th_a,th_b);
  double th_m = (th_a + th_b)/2;
  if (abs(th_a - th_b) < epsilon/100) return th_m;
  
  double d0 = dmax(cx,cy), d[3], ddmax=0;
  d[0] = d0 - dmax(cx+epsilon*cos(th_a), cy+epsilon*sin(th_a));
  d[1] = d0 - dmax(cx+epsilon*cos(th_m), cy+epsilon*sin(th_m));
  d[2] = d0 - dmax(cx+epsilon*cos(th_b), cy+epsilon*sin(th_b));

  int at=-1;
  rep(i,3) if(d[i]>ddmax){ ddmax=d[i]; at=i; }
  if (at==1) at = (d[0] >= d[2])? 0 : 2;
  switch (at) {
    case 0: return qmid(cx,cy,th_a,th_m);
    case 2: return qmid(cx,cy,th_m,th_b);
  }
}
double q(double cx,double cy,double eps){
  // double d0 = dmax(cx,cy);
  double theta = qmid(cx,cy,0,0);
  if (theta < 0) theta += pi*2;

  double ddmax = (dmax(cx,cy) - dmax(cx+eps*cos(theta), cy+eps*sin(theta)))/eps;
  // // rep(i,DDIV*4) if (d[i]==ddmax) printf(" = %d\n", i);
  // //ddmax /= epsilon;
  //printf("_ at %g=%g, ddmax=%g\n", theta,theta*180/pi, ddmax);

  //  //return (ddmax < epsilon)? -1 : at;
  return (ddmax < epsilon)? -1 : theta;
  // return at;//make_pair(at,dmin);
  /* double dx = -(d0x - d0)/epsilon, dy = -(d0y - d0)/epsilon;
  double r = hypot(dy,dx);
  double q = atan2(dy,dx)/pi * 2; // (r, -2..2)
  printf("_ (-dx:%2.9f-%2.9f=%2.9f:%2.9f -dy:%2.9f-%2.9f=%2.9f:%2.9f) => (r:%g q:%g)\n",
         d0x, d0, d0x-d0, -dx,
         d0y, d0, d0y-d0, -dy,
         r,q);
  return make_pair(r,q);
  */
}

bool quad1(double q){ return (q<0 || (0<=q && q<=pi/2+eps) || pi*2-eps<=q); }
bool quad2(double q){ return (q<0 || (pi/2-eps<=q && q<=pi+eps)); }
bool quad3(double q){ return (q<0 || (pi-eps<=q && q<=pi*3/2+eps)); }
bool quad4(double q){ return (q<=eps || (pi*3/2-eps<=q && q<=pi*2+eps)); }

double find_bottom(double &cx,double &cy,double xa,double ya, double xb,double yb, double w){
  if (w < epsilon) {
    cx = (xa+xb)/2; cy = (ya+yb)/2;
    //printf(" /bottom: (%g %g), %g\n", cx, cy, dmax(cx,cy));
    return dmax(cx,cy);
  }

  //  printf("find_bottom(%g,%g, %g,%g, w:%g)\n", xa,ya, xb,yb, w);

  double maxv = 0, at_x, at_y;
  
  double eps = w * 1e-5;
  for(double x=xa; x<xb; x+=w){
    for(double y=ya; y<yb; y+=w){
      double q0 = q(x,y,eps), q1 = q(x+w,y,eps), q2 = q(x+w,y+w,eps), q3 = q(x,y+w,eps);
      if (quad1(q0) && quad2(q1) && quad3(q2) && quad4(q3)) {
        //printf("[%g,%g x %g,%g] <w=%g>, [%g|%g|%g|%g]\n", x,y, x+w,y+w, w, q0,q1,q2,q3);
        //printf("  go further...\n");
        double cx_, cy_, d = find_bottom(cx_,cy_, x,y, x+w,y+w, w/2);
        if (d > maxv) {
          maxv = d; at_x = cx_; at_y = cy_;
        }
      }
    }
  }

  cx = at_x; cy = at_y;
  //printf(" bottom: (%g %g) %g\n", cx, cy, dmax(at_x,at_y));
  return dmax(at_x,at_y);

  /*  
  double xm = (xa+xb)/2, ym = (ya+yb)/2;
  if (w < 1e-6) {
    printf("bottom: %g at (%g, %g)\n", dmax(xm,ym), xm,ym);
    return dmax(xm,ym);
  }

  double d0 = dmax(xa,ya), d1 = dmax(xb,ya), d2 = dmax(xa,yb), d3 = dmax(xb,yb);
  bool left = d0<=d1 && d2<=d3, above = d0<=d2 && d1<=d3;
  if (left) {
    if (above) {
      return find_bottom(xa,ya, xm,ym, w/2);
    } else {
      return find_bottom(xa,ym, xm,yb, w/2);
    }
  } else {
    if (above) {
      return find_bottom(xm,ya, xb,ym, w/2);
    } else {
      return find_bottom(xm,ym, xb,yb, w/2);
    }
  }
  */
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

  double cx, cy, d = find_bottom(cx,cy, -100,-100, 100,100, 100);
  printf("%g at (%g,%g)\n", d,cx,cy);
  return 0;
}
