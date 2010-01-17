#include <iostream>
#include <fstream>
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
#include "../cout.h"
// END CUT HERE

using namespace std;

typedef long long ll;
typedef pair<int,int> i_i;
typedef pair<double,double> d_d;
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
  // return (hypot(cx - px, cy - py) <= r);
  return ((cx-px)*(cx-px) + (cy-py)*(cy-py) <= r*r);
}

int ccw(i_i p0, i_i p1, i_i p2){
  int dx1 = p1.first - p0.first, dy1 = p1.second - p0.second,
      dx2 = p2.first - p0.first, dy2 = p2.second - p0.second;
  int a = dx1*dy2, b = dy1*dx2;
  if (a > b) return 1; if (a < b) return -1;
  if (dx1*dx2 < 0 || dy1*dy2 < 0) return -1;
  if (dx1*dx1+dy1*dy1 < dx2*dx2+dy2*dy2) return 1;
  return 0;
}

double dd_distance(d_d p1, d_d p2){
  return hypot(p2.first - p1.first, p2.second - p1.second);
}
d_d dd_midpoint(d_d p1, d_d p2){
  return make_pair((p1.first + p2.first)/2, (p1.second + p2.second)/2);
}
d_d dd_midpoint(i_i p1, i_i p2){
  return make_pair(0.5*(p1.first + p2.first), 0.5*(p1.second + p2.second));
}
d_d dd_sub(d_d p1, d_d p2){ // p1 - p2
  return make_pair(p1.first - p2.first, p1.second - p2.second);
}
double dd_abs(d_d v){ // |v|
  return hypot(v.first,v.second);
}
d_d dd_u(d_d v){ // length=1
  double a = dd_abs(v);
  if (a==0)
    return make_pair(0,0);
  else
    return make_pair(v.first/a, v.second/a);
}

class EnclosingCircles {
  string circle(double centerX, double centerY, double radius) {
    char buf[40];
    sprintf(buf,"%1.8f %1.8f %1.8f", centerX, centerY, radius + 1e-8);
    return string(buf);
    // stringstream os;
    // os << centerX << " " << centerY << " " << (radius + 1e-4);
    // return os.str();
  }
  
 public:
  vector<int> generateTestCase(int testNumber) {
    // とりあえず空でも許されるが、できれば実装することをお勧めしたいとな
    int M, N;
    vector<int> pointX, pointY;
    
    switch (testNumber) {
      case 0:
        M = 20;
        N = 512; pointX.resize(N); pointY.resize(N);
        rep(i,N) pointX[i] = pointY[i] = i; // (0,0),(1,1),(2,2),...,(510,510),(511,511)
        break;
      case 1:
        M = 10;
        N = 60; pointX.resize(N); pointY.resize(N);
        pointX[0] = pointX[4] = pointX[6] = pointX[8] = 0;
        pointX[1]                         = pointX[9] = 167;
        pointX[2]                         = pointX[10] = 334;
        pointX[3] = pointX[5] = pointX[7] = pointX[11] = 501;
        pointY[0] = pointY[1] = pointY[2] = pointY[3] = 0;
        pointY[4]                         = pointY[5] = 167;
        pointY[6]                         = pointY[7] = 334;
        pointY[8] = pointY[9] = pointY[10] = pointY[11] = 501;
        for_(i,1,4){
          rep(j,12){
            pointX[12*i+j] = pointX[j] + 6 - i;
            pointY[12*i+j] = pointY[j] + 6 - i;
          }
        }
        break;
      case 2:
        M = 10;
        N = 148; pointX.resize(N); pointY.resize(N);
        rep(i,74){
          int j=7*i;
          pointX[i*2]   = j;     pointY[i*2]   = j;
          pointX[i*2+1] = 511-j; pointY[i*2+1] = j;
        }
        break;
      case 3:
        M = 10;
        N = 54; pointX.resize(N); pointY.resize(N);
        rep(i,9){
          int bx=50*i, by=bx, c=7+i*11;
          pointX[i*6]    = bx+111-c; pointY[i*6]   = by;
          pointX[i*6+1]  = bx+111;   pointY[i*6+1] = by+c;
          pointX[i*6+2]  = bx;       pointY[i*6+2] = by+111-c;
          pointX[i*6+3]  = bx+c;     pointY[i*6+3] = by+111;
          pointX[i*6+4]  = bx+53;    pointY[i*6+4] = by+53;
          pointX[i*6+5]  = bx+49;    pointY[i*6+5] = by+49;
        }
        break;
      case 4:
        M = 10;
        N = 108; pointX.resize(N); pointY.resize(N);
        rep(r,3){
          int by=250*r+5;
          rep(h,6){
            int bx=100*h+5;
            int i=6*r+h;
            pointX[i*6]   = bx,   pointY[i*6]   = by-5;
            pointX[i*6+1] = bx+6, pointY[i*6+1] = by;
            pointX[i*6+2] = bx-5, pointY[i*6+2] = by+6;
            pointX[i*6+3] = bx,   pointY[i*6+3] = by;
            pointX[i*6+4] = bx+1, pointY[i*6+1] = by+1;
            pointX[i*6+5] = bx-3, pointY[i*6+2] = by-2;
          }
        }
        break;
      case 5: case 6: case 7: case 8: case 9:
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
    // uniq
    set<i_i> uni;
    rep(i,N) uni.insert(make_pair(pointX[i],pointY[i]));
    N = sz(uni); // pointX.resize(N); pointY.resize(N);
    vector<d_d> point;
    tr(uni,it) point.pb(make_pair((double)it->first,(double)it->second));
    
    if (M > N) M = N; // ??
    // (点の数)N: 50 .. 1000
    // (点の座標)X[],Y[]: 0..511
    // (使っていい円の数)M: 10 .. [N/10]  =>[10..100]

    vector<string> res;

    // AREA>=400000なら0point
    // AREA<400000なら (AREA-400000)/1000
    // 400000ってどのくらいかというとr=356.8ですわ
    // 絶対に一発で収まる(255.5,255.5,361.33=255.5√2) だと410167でアウトですね
    // double maxr = sqrt(400000); // これを超えると0ポイント

    vector<vector<double> > ds(N,vector<double>(N,10000));
    set<int> boss;
    vector<vector<i_i> > group(M,vector<i_i>());
    vector<pair<d_d,double> > centre;

    // #1,#2
    {
      double furthest = -1; int p0, p1;
      for_(i,0,N-1) {
        for_(j,i+1,N-1) {
          double d = dd_distance(point[i],point[j]);
          ds[i][j] = ds[j][i] = d;
          if (d > furthest) { furthest = d; p0 = i; p1 = j; }
        }
      }
      boss.insert(p0); group[0].pb(point[p0]); centre.pb(make_pair(point[p0], 0.1));
      boss.insert(p1); group[1].pb(point[p1]); centre.pb(make_pair(point[p1], 0.1));
    }
    // #3...
    for_(k,2,M-1) {
      double furthest = -1; // max nearest
      int p; 
      rep(j,N){
        if (found(boss,j)) continue;
        double nearest = 10000;
        tr(boss,it){
          int i=*it; // point#
          if (ds[i][j] < nearest) nearest = ds[i][j];
        }
        if (nearest > furthest) { furthest = nearest; p = j; }
      }
      boss.insert(p); group[k].pb(point[p]); centre.pb(make_pair(point[p], 0.1));
    }

    // rep(i,M) centre[i] = make_pair(point[boss[i]], 0.1);
    //  cout << "centre: " << centre << endl;
    // printf("size of centre[] = %d, M = %d\n", sz(centre), M);

    // grouping
    rep(j,N){ // point[j]
      if (found(boss,j)) continue;
      double min_diff = 10000000; int b=-1;
      rep(i,M){ // boss#i
        double da = centre[i].second;
        double dz = dd_distance(centre[i].first, point[j]);
        if (dz <= da) {
          b = i; break;
          // group[i].pb(point[j]); goto next;
        } else {
          double diff = dz*dz - da*da; // * pi
          if (diff < min_diff) { min_diff = diff; b = i; }
        }
      }
        // printf("b=%d, group[b] << point[j=%d]:(%g,%g)\n", b, j, point[j].first, point[j].second);
      group[b].pb(point[j]);
      //cout << centre[b] ;
      {
        //cout << "gb: " << group[b] << endl;
        vector<i_i> convex = get_convex_hull(group[b]);
        //cout << "  : " << convex << endl;
        double cx, cy, r;
        smallest_enclosing_circle(cx,cy,r, convex);
        centre[b] = make_pair(make_pair(cx,cy), r);
      }
    }
// BEGIN CUT HERE
    /*
    rep(i,M-1){
      pair<d_d,double> ci = centre[i]; double ri = ci.second;
      if (ri == 0) continue;
      for_(j,i+1,M-1){
        pair<d_d,double> cj = centre[i]; double rj = cj.second;
        if (rj == 0) continue;
        double d = dd_distance(ci.first, cj.first);
        if (d < ri || d < rj) {
          vector<i_i> merged;
          tr(group[i],it) merged.pb(*it);
          tr(group[j],it) merged.pb(*it);
          
          vector<i_i> convex = get_convex_hull(merged);
          double cx, cy, r;
          smallest_enclosing_circle(cx,cy,r, convex);
          //centre[b] = make_pair(make_pair(cx,cy), r);
          if (r*r < ri*ri + rj*rj) {
            centre[i] = make_pair(make_pair(cx,cy),r);
            group[i] = merged;
            centre[j] = make_pair(make_pair(0,0),0);
            group[j] = vector<i_i>();
          }
        }
      }
    }
    */
// END CUT HERE
    // output
    rep(i,M){
// BEGIN CUT HERE
      /*
      vector<i_i> convex = get_convex_hull(group[i]);
      double cx, cy, r;
      smallest_enclosing_circle(cx,cy,r, convex);
      res.pb(circle(cx,cy,r));
      */
// END CUT HERE
      if (centre[i].second == 0) continue;
      res.pb(circle(centre[i].first.first, centre[i].first.second, centre[i].second));
    }
    return res;
  }
  
  vector<i_i> get_convex_hull(vector<i_i> group)
  {
    // void get_wrapper(double &cx,double &cy,double &r, set<i_i> group) {
    int xmin=10000,xmax=-1, ymin=10000,ymax=-1;
    /*vector<i_i> gv(all(group));*/ int n=sz(group), base=-1;
    rep(i,n){
      int x=group[i].first, y=group[i].second;
      if (x<xmin) xmin=x; if (x>xmax) xmax=x;
      if (y<ymin) ymin=y; if (y>ymax) ymax=y;
      if (y==ymin && x==xmax) { base=i; }
    }

    i_i p0 = group[base];
    priority_queue<pair<double,pair<double,i_i> > > pq;
    pq.push(make_pair(0.0, make_pair(0.0, p0)));
    rep(i,n){
      if (i==base) continue;
      i_i p = group[i];
      int dx=p.first-p0.first, dy=p.second-p0.second;
      double theta = atan2(dy,dx), distance = hypot(dx,dy);
      if (theta < 0) theta += pi*2;
      pq.push(make_pair(-theta,make_pair(distance,p)));
    }

    set<double> passed;
    vector<i_i> edges(1);
    // edges.pb(p0);
    int N=0;
    while(!pq.empty()){
      double theta = pq.top().first;
      if (!found(passed,theta)) {
        i_i p = pq.top().second.second;
        // cout << " - " << p << endl;
        edges.pb(p); N++;
        passed.insert(theta);
      }
      pq.pop();
    }
    edges[0] = edges[N];
    // cout << "original: " << vector<i_i>(edges.begin()+1,edges.end()) << ", N=" << N << endl;

    int m;
    if (N <= 2) {
      // do nothing
      m = N;
    } else {
      m = 3;
      for_(i,4,N){
        // printf("// i=%d, m=%d\n", i, m);
        while (ccw(edges[m],edges[m-1],edges[i]) >= 0) m--;
        m++; /*printf("[swap %d<>%d]\n", i,m); */ swap(edges[i],edges[m]);
      }
    }

    vector<i_i> res(m);
    rep(i,m) res[i] = edges[1+i];
    // cout << " => " << res << ", m=" << m << endl;
    return res;
  }


  double bs(d_d e0,d_d u, double r0, double r1, vector<i_i> convex) { // r0:ng r1:ok
    int n = sz(convex), cnt=0;
    double rm = (r0 + r1)/2;
    if (r1 - r0 < 1e-9) return r0;
    d_d cm = make_pair(e0.first + u.first * rm, e0.second + u.second * rm);

    rep(i,n) if (dd_distance(convex[i],cm) <= rm) cnt++;

    if (cnt == n)
      return bs(e0,u, r0,rm, convex);
    else
      return bs(e0,u, rm,r1, convex);
  }
  double bs2(d_d d, d_d c0,d_d u, double t0,double t1, vector<i_i> convex) {
    int n = sz(convex), cnt=0;
    double tm= (t0 + t1)/2;
    if (t1 - t0 < 1e-9) return t0;
    d_d cm = make_pair(c0.first + u.first * tm, c0.second + u.second * tm);
    double rd = dd_distance(d, cm);

    rep(i,n) if (dd_distance(convex[i],cm) <= rd) cnt++;

    if (cnt == n)
      return bs2(d, c0,u, t0,tm, convex);
    else
      return bs2(d, c0,u, tm,t1, convex);
  }


  void smallest_enclosing_circle(double &cx,double &cy,double &r, vector<i_i> convex) {
    int n = sz(convex);
    if (n == 1) {
      cx = convex[0].first; cy = convex[0].second; r = 0.1;
      return;
    } else if (n == 2) {
      cx = 0.5 * (convex[0].first + convex[1].first);
      cy = 0.5 * (convex[0].second + convex[1].second);
      r = 0.5 * hypot(convex[0].first - convex[1].first,
                      convex[0].second - convex[1].second) + 1e-9;
      if (r < 0.1) r = 0.1;
      return;
    }

    // 仮の中心と半径を求める
    int xmin=10000,xmax=-1, ymin=10000,ymax=-1;
    rep(i,n){
      int x=convex[i].first, y=convex[i].second;
      if (x<xmin) xmin=x; if (x>xmax) xmax=x;
      if (y<ymin) ymin=y; if (y>ymax) ymax=y;
    }

    cx = 0.5*(xmin + xmax);
    cy = 0.5*(ymin + ymax);
    r = 0.5*hypot(xmax-xmin,ymax-ymin);// + 1e-9;
    if (r < 0.1) { r = 0.1; return; }

    double dmax = 0;
    int cnt = 0, at=-1;
    rep(i,n){
      double d = hypot(cx-convex[i].first, cy-convex[i].second);
      if (d == dmax) cnt++;
      else if (d > dmax) { dmax = d; at = i; cnt=1; }
    }

    if (dmax < r) {
// BEGIN CUT HERE
      //printf("(%g,%g), r:%g -> %g (cnt=%d)\n", cx,cy, r,dmax, cnt);
// END CUT HERE
      r = dmax;
    } else {
// BEGIN CUT HERE
      //printf("(%g,%g), r:%g stay (cnt=%d at %d)\n", cx,cy, r, cnt,at);
// END CUT HERE
    }
    
    if (cnt == 1) {
      double r_ = r;
      d_d c = make_pair(cx,cy);
      d_d e0 = make_pair((double)convex[at].first,(double)convex[at].second);
      d_d uvec = dd_u(dd_sub(c,e0));
      r = bs(e0,uvec, 0,dmax, convex);
      cx = e0.first + uvec.first * r;
      cy = e0.second + uvec.second * r;

      // 180度以上離れている所があったら...
      int cnt_ = 0;
      double dmax_ = 0;
      priority_queue<pair<double,int> > thq;
      rep(i,n){
        double d = hypot(cx-convex[i].first, cy-convex[i].second);
        if (d >= dmax_ - 1e-9) {
          double th = atan2((double)convex[i].second-cy, (double)convex[i].first-cx);
          thq.push(make_pair(th,i));
          cnt_++;
        }
        else if (d > dmax_) {
          double th = atan2((double)convex[i].second-cy, (double)convex[i].first-cx);
          thq.push(make_pair(th,i));
          dmax_ = d; cnt_=1;
        }
      }
      vector<pair<double,int> > thv;
      while(!thq.empty()) { thv.pb(thq.top()); thq.pop(); } // pi .. 0 .. -pi
      int thv_sz = sz(thv);
      thv.pb(make_pair(thv[0].first-pi*2,thv[0].second));
      double vac_max=0; int vac_max_a = -1, vac_max_b = -1;
      rep(i,thv_sz) {
        double vac = thv[i].first - thv[i+1].first;
        if (vac > vac_max) {
          vac_max = vac; vac_max_a = thv[i].second; vac_max_b = thv[i+1].second;
        }
      }
      if (vac_max > pi) {
// BEGIN CUT HERE
        //printf("vac_max = %g at (#%d .. #%d) > pi...\n", vac_max, vac_max_a, vac_max_b);
// END CUT HERE
        d_d c0 = dd_midpoint(convex[vac_max_a],convex[vac_max_b]),
            c1 = make_pair(cx,cy),
            uvec = dd_u(dd_sub(c1,c0));
        double u = bs2(convex[vac_max_a], c0,uvec, 0,dd_distance(c1,c0), convex);
        cx = c0.first + uvec.first*u;
        cy = c0.second + uvec.second*u;
        r = dd_distance(convex[vac_max_a],make_pair(cx,cy));
      }
    }

    r += 1e-9; if (r < 0.1) r = 0.1;
  }
};

// BEGIN CUT HERE
int main()
{
  int M, N;
  cin >> M;
  cin >> N;
  vector<int> pointX(N), pointY(N);
  rep(i,N) cin >> pointX[i];
  rep(i,N) cin >> pointY[i];

  EnclosingCircles ec;
  vector<string> circles = ec.placeCircles(pointX,pointY,M);
  cout << circles.size() << endl;
  tr(circles,it) cout << *it << endl;
}
// END CUT HERE
