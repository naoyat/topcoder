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

d_d steepest_descent(double x, double y, double ax, double ay)
{
  while (1) {
    printf("steepest_descent(%g,%g, a:%g,%g)\n", x,y, ax,ay);
    
    //if (abs(alpha) < epsilon) break;

    double theta = qmid(x,y,0,0);
    if (theta < 0) break;
  
    if (theta > pi) theta -= pi*2;
    double v = (dmax(x,y) - dmax(x+epsilon*cos(theta),y+epsilon*sin(theta)))/epsilon;

    v *= 0.01;
    // double a = epsilon;//(dmax(cx,cy) - dmax(cx+epsilon*cos(theta),cy+epsilon*cos(theta)));
    x += ax; ax = (ax + v*cos(theta))/2;
    y += ay; ay = (ay + v*sin(theta))/2;
    // alpha += v;//(alpha + v)/2;
  }//    return steepest_descent(x+alpha*cos(theta), y+alpha*sin(theta), (alpha+v/10)/2);
  //printf(" bottom: (%g %g) %g\n", cx, cy, dmax(at_x,at_y));
  //return dmax(at_x,at_y);
  return make_pair(x,y);
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

  double theta = qmid(0,0,0,0);
  d_d bottom = steepest_descent(0, 0, 0, 0);//epsilon*cos(theta),epsilon*sin(theta));
  printf("%g at (%g,%g)\n", dmax(bottom.first,bottom.second), bottom.first, bottom.second);
  return 0;
}
