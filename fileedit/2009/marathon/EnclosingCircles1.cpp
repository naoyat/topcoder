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
#include "../cout.h"
// END CUT HERE

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
  // return (hypot(cx - px, cy - py) <= r);
  return ((cx-px)*(cx-px) + (cy-py)*(cy-py) <= r*r);
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
        M = 10;
        N = 512; pointX.resize(N); pointY.resize(N);
        rep(i,N) pointX[i] = pointY[i] = i; // (0,0),(1,1),(2,2),...,(510,510),(511,511)
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
    map<int,int> boss;
    vector<set<i_i> > group(M,set<i_i>());

    // #1,#2
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
// BEGIN CUT HERE
      /*
      printf("#1: #%d(%d,%d)\n", p1, pointX[p1], pointY[p1]);
      printf("#2: #%d(%d,%d), d=%g\n", p2, pointX[p2], pointY[p2], furthest);
      */
// END CUT HERE
    }
    // #3...
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
// BEGIN CUT HERE
      // printf("#%d: #%d(%d,%d), d=%g\n", 1+k, p, pointX[p], pointY[p], furthest);
// END CUT HERE
    }

    // grouping
    rep(j,N){
      if (found(boss,j)) continue;
      double nearest = 10000; int b;
      tr(boss,it){
        int i=it->first;
        if (ds[i][j] < nearest) { nearest = ds[i][j]; b = it->second; }
      }
// BEGIN CUT HERE
      /*
      printf("point #%d (%d,%d) belongs to boss #%d (%d,%d) with distance %g\n",
             j, pointX[j], pointY[j],
             b, pointX[b], pointY[b],
             nearest);
      */
// END CUT HERE
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
    //cout << group << endl;
    cx = 0.5*(xmin + xmax);
    cy = 0.5*(ymin + ymax);
    r = 0.5*hypot(xmax-xmin,ymax-ymin) + 1e-9;
    if (r < 0.1) r = 0.1;
    //printf("x:[%d..%d], y:%d..%d] -> (%g,%g)x%2.8f\n", xmin,xmax, ymin,ymax, cx,cy,r);
    //cout << " <<< \"" << circle(cx,cy,r) << "\"" << endl;
  }

};

// BEGIN CUT HERE
double tester(vector<int> pointX, vector<int> pointY, int M, vector<string> circles)
{
  int number_of_circles = sz(circles);
  if (number_of_circles > M) return 0;
  vector<double> cx(number_of_circles),cy(number_of_circles),r(number_of_circles);
  double area = 0;
  rep(i,number_of_circles){
    stringstream ss(circles[i]);
    ss >> cx[i] >> cy[i] >> r[i];
    // printf("circle #%d: (%g, %g), r=%g\n", i,cx[i],cy[i],r[i]);
    if (!valid_radius_p(r[i])) return 0;
    area += r[i]*r[i]*pi;
  }
  printf("area = %g\n", area);
  if (area >= 400000) {
    printf("!! area > 400000\n");
    return 0;
  }

  int number_of_points = sz(pointX);
  rep(i,number_of_points){
    int px = pointX[i], py = pointY[i];
    bool in_circle_p = false;
    rep(j,number_of_circles)
      if (inside_p(cx[j],cy[j],r[j],px,py)) { in_circle_p = true; break; }
    if (!in_circle_p) {
      printf("point#%d(%d,%d) is out!\n",i,px,py);
      return 0;
    }
  }
  return (400000.0 - area)/1000;
}

#include <time.h>
clock_t start_time;
void timer_clear() { start_time = clock(); }
string timer() { clock_t end_time = clock(); double interval = (double)(end_time - start_time)/CLOCKS_PER_SEC; ostringstream os; os << " (" << interval*1000 << " msec)"; return os.str(); }

template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
int verify_case(const double &Expected, const double &Received) { double diff = Expected - Received; if (diff < 0) diff = -diff; if (diff < 1e-9) cerr << "PASSED" << timer() << endl; else { cerr << "FAILED" << timer() << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } return 0;}

template<int N> struct Case_ {};
char Test_(...);

int Test__(int testNumber){
  EnclosingCircles ec;

  timer_clear();
  vector<int> testCase = ec.generateTestCase(testNumber);
  double point = 0;
  if (sz(testCase)>=2) {
    // cout << "test case: " << testCase << endl;
    int M = testCase[0], N = testCase[1];
    printf("M = %d, N = %d\n", M, N);
    vector<int> pointX(testCase.begin()+2,testCase.begin()+2+N);
    vector<int> pointY(testCase.begin()+2+N,testCase.begin()+2+N+N);
    // rep(i,N) printf(" // point #%d: (%d,%d)\n", i,pointX[i],pointY[i]);
    vector<string> circles = ec.placeCircles(pointX,pointY,M);
    // cout << "circles: " << circles << endl;
    point = tester(pointX,pointY,M,circles);
  } else {
    point = 0;
  }
  // cout << "point: " << point << endl;
  // return verify_case(retVal,
  return 0;
}

int Test_(Case_<0>) { return Test__(0); }
int Test_(Case_<1>) { return Test__(1); }

template<int N> void Run_() {
  cerr << "----" << endl;
  cerr << "Test Case #" << N << "..." << flush;
  Test_(Case_<N>());
  Run_<sizeof(Test_(Case_<N+1>()))==1 ? -1 : N+1>();
}
template<>      void Run_<-1>() {}
int main() { Run_<0>(); }
// END CUT HERE
