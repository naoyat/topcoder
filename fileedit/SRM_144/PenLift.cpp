#line 2 "PenLift.cpp"
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
#define tr(c,i)  for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); i++)
#define rep(var,n)  for(int var=0;var<(n);var++)
#define FOR(var,from,to) for(int var=(from);var<=(to);var++)
#define RFOR(var,from,to) for(int var=(to);var>=(from);var--)
#define found(s,e)  ((s).find(e)!=(s).end())
#define mset(arr,val)  memset(arr,val,sizeof(arr))
#define remove_(c,val) (c).erase(remove((c).begin(),(c).end(),(val)),(c).end())
#define lastc(str) (*((str).end()-1))

typedef pair<int,int> i_i;
typedef pair<ll,ll> ll_ll;
typedef pair<double,double> d_d;
typedef pair<int,pair<int,int> > i_ii;
#define cons(x,y) make_pair((x),(y))
#define car(x) ((x).first)
#define cdr(x) ((x).second)
#define caar(x) (x).first.first
#define cdar(x) (x).first.second
#define cadr(x) (x).second.first
#define cddr(x) (x).second.second

vector<string> split(string str, int delim=' ')
{
  vector<string> result;

  const char *s = str.c_str();
  if (delim == ' ') {
    for (const char *p=s; *p; p++) {
      if (*p == delim) s++;
      else break;
    }
    if (!*s) return result;

    for (const char *p=s; *p; p++) {
      if (*p == delim) {
        if (s < p) {
          string a(s,p-s);
          result.push_back(a);
        }
        s = p + 1;
      }
    }
    if (*s) result.push_back(s);
  } else {
    for (const char *p=s; *p; p++) {
      if (*p == delim) {
        string a(s,p-s);
        result.push_back(a);
        s = p + 1;
        if (*s == '\0') result.push_back("");
      }
    }
    if (*s) result.push_back(s);
  }

  return result;
}

vector<int> map_atoi(vector<string> nums)
{
  vector<int> vals(nums.size());
  for (int i=nums.size()-1; i>=0; i--) vals[i] = atoi(nums[i].c_str());
  return vals;
}

typedef pair<int,int> point;
typedef pair<point,point> segment;

vector<segment> segments;
vector<bool> deleted;
vector<int> dirs;

/**
int ccw(point p0, point p1, point p2)
{
  int dx1 = p1.first - p0.first, dy1 = p1.second - p0.second;
  int dx2 = p2.first - p0.first, dy2 = p2.second - p0.second;
  if (dx1*dy2 > dy1*dx2) return +1;
  if (dx1*dy2 < dy1*dx2) return -1;
  if ((dx1*dx2 < 0) || (dy1*dy2 < 0)) return -1;
  if ((dx1*dx1+dy1*dy1) < (dx2*dx2+dy2*dy2)) return +1;
  return 0;
}
bool intersect(int i,int j)
{
  segment s1 = segments[i], s2 = segments[j];
  return ((ccw(s1.first,s1.second, s2.first)*ccw(s1.first,s1.second, s2.second)) <= 0)
      && ((ccw(s2.first,s2.second, s1.first)*ccw(s2.first,s2.second, s1.second)) <= 0);
}
**/
int dir(const segment& s){
  point p1 = car(s), p2 = cdr(s);
  if (p1==p2) return -1;
  if (car(p1)==car(p2)) // x1=x2
    return (p2.second > p1.second)?1:3;
  else
    return (p2.first > p1.first)?0:2;
}
segment rev(const segment& s){
  return cons(cdr(s),car(s));
}

segment joint(int i, int j){
  segment s1 = segments[i], s2 = segments[j];
  int dir = dirs[i]; // assume dirs[i]=dirs[j]
  if (dir==0) { // horizontal
    int y = cdar(s1);
    int x0 = min( caar(s1),caar(s2) ),
        x1 = max( cadr(s1),cadr(s2) );
    return cons(cons(x0,y),cons(x1,y));
  } else {
    int x = caar(s1);
    int y0 = min( cdar(s1),cdar(s2) ),
        y1 = max( cddr(s1),cddr(s2) );
    return cons(cons(x,y0),cons(x,y1));
  }
}

point cross(int i, int j){
  segment s1 = segments[i], s2 = segments[j];
  int d1 = dirs[i], d2 = dirs[j];
  if (d1==1 && d2==0) return cross(j,i);
// BEGIN CUT HERE
  //  if (dir(s1) > dir(s2)) swap(s1,s2);
  // dir(s1) <= dir(s2)
  cout << "cross: " << endl;
    cout << "  " << s1 << ", dir=" << d1 << endl;// 0
    cout << "  " << s2 << ", dir=" << d2 << endl;// 1
  // assumes d1=0, d2=1
// END CUT HERE
  int y=cdar(s1);
  if (cdar(s2) <= y && y <= cddr(s2)) {
    FOR(x,caar(s1),cadr(s1)) {
      // x,y
      if(x==caar(s2)) return cons(x,y);
    }
  }
  return cons(INT_MAX,INT_MAX);
}

bool oddp(int n){
  return (n & 1)? true : false;
}

class UnionFind {
  vector<int> data;
 public:  
  UnionFind(int size) : data(size, -1) { }
  
  bool unionSet(int x, int y) {
    x = root(x); y = root(y);
    if (x != y) {
      if (data[y] < data[x]) swap(x, y);
      data[x] += data[y]; data[y] = x;
    }
    return x != y;
  }
  bool findSet(int x, int y) {
    return root(x) == root(y);
  }
  int root(int x) {
    return data[x] < 0 ? x : data[x] = root(data[x]);
  }
  int size(int x) {
    return -data[root(x)];
  }
};

class PenLift {
 public:
  int numTimes(vector<string> segs, int n) {
    int N = sz(segs);
// BEGIN CUT HERE
    printf("numTimes(string[%d], %d)\n", N, n);
    //    vector<point> points;
    //map<point,int> pointset; // pointset[point] = point_id
    //    int point_id=0;
// END CUT HERE
    segments.resize(N);
    deleted.resize(N);
    dirs.resize(N);
    
	rep(i,N){ // segment_id
      vector<int> t = map_atoi(split(segs[i]));
      segment s = cons(cons(t[0],t[1]), cons(t[2],t[3]));
      if (dir(s) >= 2) s = rev(s);
      segments[i] = s; deleted[i] = false;
      dirs[i] = dir(s);
    }
    
    // joint
    UnionFind uf0(N); set<int> jointed;
    FOR(i,0,N-2){
      //if (deleted[i]) continue;
      FOR(j,i+1,N-1){
        //if (deleted[j]) continue;
        if (dirs[i]==dirs[j]) {
// BEGIN CUT HERE
          //          printf("(dir=%d) ",dirs[i]); cout << segments[i] << " x " << segments[j] << endl;
// END CUT HERE
          if (dirs[i]==0) { // h
            int yi = cdar(segments[i]), yj = cdar(segments[j]);
            if (yi != yj) continue;
            int x0 = caar(segments[i]), x1 = cadr(segments[i]),
                x2 = caar(segments[j]), x3 = cadr(segments[j]);
            if (x0>x2) { swap(x0,x2); swap(x1,x3); } // x0 <= x2
// BEGIN CUT HERE
            //            printf("  x:[ %d, %d, %d, %d ], y:%d\n", x0, x1, x2, x3, yi);
// END CUT HERE
            if (x2 <= x1) {
              uf0.unionSet(i,j);
              jointed.insert(i); jointed.insert(j);
// BEGIN CUT HERE
              //              printf(" ==> joined (%d + %d).\n", i, j);
// END CUT HERE
            }
          } else { // v
            int xi = caar(segments[i]), xj = caar(segments[j]);
            if (xi != xj) continue;
            int y0 = cdar(segments[i]), y1 = cddr(segments[i]),
                y2 = cdar(segments[j]), y3 = cddr(segments[j]);
            if (y0>y2) { swap(y0,y2); swap(y1,y3); } // y0 <= y2
// BEGIN CUT HERE
            //            printf("  x:%d, y:[ %d, %d, %d, %d ]\n", xi, y0, y1, y2, y3);
// END CUT HERE
            if (y2 <= y1) {
              uf0.unionSet(i,j);
              jointed.insert(i); jointed.insert(j);
// BEGIN CUT HERE
              //              printf(" ==> joined (%d + %d).\n", i, j);
// END CUT HERE
            }
          }
        }
      }
    }
    map<int,set<int> > joint_isle;
    tr(jointed,it){
      int root = uf0.root(*it);
      if (!found(joint_isle,root)) {
        set<int> s;
        joint_isle[root] = s;
      }
      //if (*it != root)
      joint_isle[root].insert(*it);
    }

    tr(joint_isle,it) {
      int root=it->first;
// BEGIN CUT HERE
      printf("going to joint, root#%d: ", root); cout << it->second << endl;
// END CUT HERE
      if (dirs[root] == 0) { // horizontal
        int y = cdar(segments[root]);
        int xmin = INT_MAX, xmax = INT_MIN;
        tr(it->second,jt) {
          segment s = segments[*jt];
          int x0 = caar(s), x1 = cadr(s);
          if (x0 > x1) swap(x0,x1);
          xmin = min(xmin,x0);
          xmax = max(xmax,x1);
          deleted[*jt] = true;
        }
        segments[root] = cons(cons(xmin,y),cons(xmax,y));
// BEGIN CUT HERE
        printf("segments[%d] = ", root); cout << segments[root] << endl;
// END CUT HERE
        deleted[root] = false;
      } else { // vertical
        int x = caar(segments[root]);
        int ymin = INT_MAX, ymax = INT_MIN;
        tr(it->second,jt) {
          segment s = segments[*jt];
          int y0 = cdar(s), y1 = cddr(s);
          if (y0 > y1) swap(y0,y1);
          ymin = min(ymin,y0);
          ymax = max(ymax,y1);
          deleted[*jt] = true;
        }
        segments[root] = cons(cons(x,ymin),cons(x,ymax));
// BEGIN CUT HERE
        printf("segments[%d] = ", root); cout << segments[root] << endl;
// END CUT HERE
        deleted[root] = false;
      }
    }
// BEGIN CUT HERE
    cout << "alives " << endl;
    rep(i,N){
      if (deleted[i]) continue;
      cout << "  >> " << segments[i] << endl;
    }
// END CUT HERE
    // cross
    vector<set<point> > seps(N,set<point>());
    FOR(i,0,N-2){
      if (deleted[i]) continue;
      
      FOR(j,i+1,N-1){
        if (deleted[j]) continue;
        
        if (dirs[i]!=dirs[j]) {

          point nx = cross(i,j);
          if (car(nx)==INT_MAX) continue;
// BEGIN CUT HERE
          cout << "  ==> " << nx << endl;
// END CUT HERE
          seps[i].insert(nx);
          seps[j].insert(nx);
// BEGIN CUT HERE
          //          deleted[i] = deleted[j] = true;
          //point ni1 = car(segments[i]), ni2 = cdr(segments[i]);
          //point nj1 = car(segments[j]), nj2 = cdr(segments[j]);
          //if (ni1!=nx) deleted[cons(ni1,nx)
          /**
          if(found(nodes,nx)) {
            nodes[nx].insert(i);
            nodes[nx].insert(j);
          } else {
            set<int> s; s.insert(i); s.insert(j);
            nodes[nx] = s;
          }
          **/
          //          cout << segments[i] << " and " << segments[j] << " crosses at: " << x << endl;
// END CUT HERE
        }
      }
    }

    rep(segment_id,N) {
      int sepsz = sz(seps[segment_id]);
// BEGIN CUT HERE
      // printf("segment_id=%d, sepsz=%d\n", segment_id, sepsz);
// END CUT HERE
      if (sepsz > 0) {
        deleted[segment_id] = true;
        
        if (dirs[segment_id]==0) { // horizontal
          int y = cdar(segments[segment_id]);
          set<int> xs;
          xs.insert(caar(segments[segment_id]));
          xs.insert(cadr(segments[segment_id]));
          tr(seps[segment_id],it) xs.insert(it->first);
          vector<int> xsv(all(xs));
          sort(all(xsv));
// BEGIN CUT HERE
          cout << " y : " << y << ", xs : " << xs << endl;
// END CUT HERE
          rep(k,sz(xsv)-1) {
            segment sk = cons(cons(xsv[k],y),cons(xsv[k+1],y));
// BEGIN CUT HERE
            //cout << " + segment#" << sz(segments) << " : " << car(sk) << " - " << cdr(sk) << endl;
// END CUT HERE
            segments.pb(sk); deleted.pb(false);
          }
        } else { // vertical
          int x = caar(segments[segment_id]);
          set<int> ys;
          ys.insert(cdar(segments[segment_id]));
          ys.insert(cddr(segments[segment_id]));
          tr(seps[segment_id],it) ys.insert(it->second);
          vector<int> ysv(all(ys));
          sort(all(ysv));
// BEGIN CUT HERE
          cout << " x : " << x << ", ys : " << ys << endl;
// END CUT HERE
          rep(k,sz(ysv)-1) {
            segment sk = cons(cons(x,ysv[k]),cons(x,ysv[k+1]));
// BEGIN CUT HERE
            //cout << " + segment#" << sz(segments) << " : " << car(sk) << " - " << cdr(sk) << endl;
// END CUT HERE
            segments.pb(sk); deleted.pb(false);
          }
        }
      }
    }

    // 両端登録
    map<point,set<int> > nodes; // points[point] = { segment_ids }

    rep(segment_id,sz(segments)){
      if (deleted[segment_id]) continue;
      vector<point> n(2);
      n[0]=car(segments[segment_id]);
      n[1]=cdr(segments[segment_id]);
// BEGIN CUT HERE
      cout << " + segment#" << segment_id << ": " << n[0] << " - " << n[1] << endl;
// END CUT HERE
      rep(node_id,2) {
        if(found(nodes,n[node_id])) {
          nodes[n[node_id]].insert(segment_id);
        } else {
          set<int> s; s.insert(segment_id);
          nodes[n[node_id]] = s;
        }
      }
    }

    UnionFind uf(sz(segments));

    tr(nodes,nt){
// BEGIN CUT HERE
      //point node = nt->first;
// END CUT HERE
      set<int> arcs = nt->second;
      vector<int> av(all(arcs)); FOR(i,1,sz(av)-1) uf.unionSet(av[0],av[i]);
// BEGIN CUT HERE
      //printf(" - node(%dx%d=%d): ", sz(arcs), n, sz(arcs)*n); cout << arcs << endl;
      //if (oddp(sz(arcs)*n)) odds++;
// END CUT HERE
    }

    map<int,int> isles;
    rep(i,sz(segments)) {
      if (deleted[i]) continue;
// BEGIN CUT HERE
      //      printf(" // root(%d) = %d\n", i,uf.root(i));
// END CUT HERE
      int root = uf.root(i);
      if (!found(isles,root)) isles[root] = 0;
// BEGIN CUT HERE
      // isles.insert();
// END CUT HERE
    }

// BEGIN CUT HERE
    //    cout << "isles : " << isles << endl;
// END CUT HERE

    // again
    tr(nodes,nt){
      point node = nt->first;
      set<int> arcs = nt->second;
      vector<int> av(all(arcs));
      int root = uf.root(av[0]);
// BEGIN CUT HERE
      printf(" - node(%dx%d=%d) at (%d,%d), in isle#%d: ",
             sz(arcs), n, sz(arcs)*n,
             car(node),cdr(node),
             root);
      cout << arcs << endl;
// END CUT HERE
      if (oddp(sz(arcs)*n)) isles[root]++;
    }
    tr(isles,it) { it->second /= 2; }
// BEGIN CUT HERE
    cout << "isles : " << isles << endl;
// END CUT HERE
    int ans = sz(isles)-1;
    tr(isles,it) {
      if (it->second == 0) continue;
      ans += it->second - 1;
    }
   
    return ans;
  }
};

// BEGIN CUT HERE
#include <time.h>
clock_t start_time;
void timer_clear() { start_time = clock(); }
string timer() { clock_t end_time = clock(); double interval = (double)(end_time - start_time)/CLOCKS_PER_SEC; ostringstream os; os << " (" << interval*1000 << " msec)"; return os.str(); }

template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
int verify_case(const int &Expected, const int &Received) { if (Expected == Received) cerr << "PASSED" << timer() << endl; else { cerr << "FAILED" << timer() << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } return 0;}

template<int N> struct Case_ {};
char Test_(...);
int Test_(Case_<0>) {
	timer_clear();
	string segments_[] = {"-10 0 10 0","0 -10 0 10"};
	  vector <string> segments(segments_, segments_+sizeof(segments_)/sizeof(*segments_)); 
	int n = 1; 
	int RetVal = 1; 
	return verify_case(RetVal, PenLift().numTimes(segments, n)); }
int Test_(Case_<1>) {
	timer_clear();
	string segments_[] = {"-10 0 0 0","0 0 10 0","0 -10 0 0","0 0 0 10"};
	  vector <string> segments(segments_, segments_+sizeof(segments_)/sizeof(*segments_)); 
	int n = 1; 
	int RetVal = 1; 
	return verify_case(RetVal, PenLift().numTimes(segments, n)); }
int Test_(Case_<2>) {
	timer_clear();
	string segments_[] = {"-10 0 0 0","0 0 10 0","0 -10 0 0","0 0 0 10"};
	  vector <string> segments(segments_, segments_+sizeof(segments_)/sizeof(*segments_)); 
	int n = 4; 
	int RetVal = 0; 
	return verify_case(RetVal, PenLift().numTimes(segments, n)); }
int Test_(Case_<3>) {
	timer_clear();
	string segments_[] = {"0 0 1 0",   "2 0 4 0",   "5 0 8 0",   "9 0 13 0",
 "0 1 1 1",   "2 1 4 1",   "5 1 8 1",   "9 1 13 1",
 "0 0 0 1",   "1 0 1 1",   "2 0 2 1",   "3 0 3 1",
 "4 0 4 1",   "5 0 5 1",   "6 0 6 1",   "7 0 7 1",
 "8 0 8 1",   "9 0 9 1",   "10 0 10 1", "11 0 11 1",
 "12 0 12 1", "13 0 13 1"};
	  vector <string> segments(segments_, segments_+sizeof(segments_)/sizeof(*segments_)); 
	int n = 1; 
	int RetVal = 6; 
	return verify_case(RetVal, PenLift().numTimes(segments, n)); }
int Test_(Case_<4>) {
	timer_clear();
	string segments_[] = {"-2 6 -2 1",  "2 6 2 1",  "6 -2 1 -2",  "6 2 1 2",
 "-2 5 -2 -1", "2 5 2 -1", "5 -2 -1 -2", "5 2 -1 2",
 "-2 1 -2 -5", "2 1 2 -5", "1 -2 -5 -2", "1 2 -5 2",
 "-2 -1 -2 -6","2 -1 2 -6","-1 -2 -6 -2","-1 2 -6 2"};
	  vector <string> segments(segments_, segments_+sizeof(segments_)/sizeof(*segments_)); 
	int n = 5; 
	int RetVal = 3; 
	return verify_case(RetVal, PenLift().numTimes(segments, n)); }
int Test_(Case_<5>) {
	timer_clear();
	string segments_[] = {"-252927 -1000000 -252927 549481","628981 580961 -971965 580961",
"159038 -171934 159038 -420875","159038 923907 159038 418077",
"1000000 1000000 -909294 1000000","1000000 -420875 1000000 66849",
"1000000 -171934 628981 -171934","411096 66849 411096 -420875",
"-1000000 -420875 -396104 -420875","1000000 1000000 159038 1000000",
"411096 66849 411096 521448","-971965 580961 -909294 580961",
"159038 66849 159038 -1000000","-971965 1000000 725240 1000000",
"-396104 -420875 -396104 -171934","-909294 521448 628981 521448",
"-909294 1000000 -909294 -1000000","628981 1000000 -909294 1000000",
"628981 418077 -396104 418077","-971965 -420875 159038 -420875",
"1000000 -1000000 -396104 -1000000","-971965 66849 159038 66849",
"-909294 418077 1000000 418077","-909294 418077 411096 418077",
"725240 521448 725240 418077","-252927 -1000000 -1000000 -1000000",
"411096 549481 -1000000 549481","628981 -171934 628981 923907",
"-1000000 66849 -1000000 521448","-396104 66849 -396104 1000000",
"628981 -1000000 628981 521448","-971965 521448 -396104 521448",
"-1000000 418077 1000000 418077","-1000000 521448 -252927 521448",
"725240 -420875 725240 -1000000","-1000000 549481 -1000000 -420875",
"159038 521448 -396104 521448","-1000000 521448 -252927 521448",
"628981 580961 628981 549481","628981 -1000000 628981 521448",
"1000000 66849 1000000 -171934","-396104 66849 159038 66849",
"1000000 66849 -396104 66849","628981 1000000 628981 521448",
"-252927 923907 -252927 580961","1000000 549481 -971965 549481",
"-909294 66849 628981 66849","-252927 418077 628981 418077",
"159038 -171934 -909294 -171934","-252927 549481 159038 549481"};
	  vector <string> segments(segments_, segments_+sizeof(segments_)/sizeof(*segments_)); 
	int n = 824759; 
	int RetVal = 19; 
	return verify_case(RetVal, PenLift().numTimes(segments, n)); }

template<int N> void Run_() { cerr << "Test Case #" << N << "..." << flush; Test_(Case_<N>()); Run_<sizeof(Test_(Case_<N+1>()))==1 ? -1 : N+1>(); }
template<>      void Run_<-1>() {}
int main() { Run_<0>(); }
// END CUT HERE


// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// NOTE: There are images in the examples section of this problem statement that help describe the problem. Please view the problem statement in the HTML window to view them.

Given a picture composed entirely of horizontal and vertical line segments, calculate the minimum number of times you must lift your pen to trace every line segment in the picture exactly n times.

Each line segment will be of the form "<x1> <y1> <x2> <y2>" (quotes for clarity), representing a segment from (x1,y1) to (x2,y2).  Segments may cross each other.  Segments may also overlap, in which case you should count the overlapping region as appearing in the drawing only once.  For example, say the drawing were composed of two lines: one from (6,4) to (9,4), and one from (8,4) to (14,4).  Even though they overlap from (8,4) to (9,4), you should treat the drawing as if it were a single line from (6,4) to (14,4).  You would not need to lift your pen at all to trace this drawing.

DEFINITION
Class:PenLift
Method:numTimes
Parameters:vector <string>, int
Returns:int
Method signature:int numTimes(vector <string> segments, int n)


NOTES
-The pen starts on the paper at a location of your choice.  This initial placement does not count toward the number of times that the pen needs to be lifted.


CONSTRAINTS
-segments will contain between 1 and 50 elements, inclusive.
-Each element of segments will contain between 7 and 50 characters, inclusive.
-Each element of segments will be in the format "<X1>_<Y1>_<X2>_<Y2>" (quotes for clarity).  The underscore character represents exactly one space.  The string will have no leading or trailing spaces.
-<X1>, <Y1>, <X2>, and <Y2> will each be between -1000000 and 1000000, inclusive, with no unnecessary leading zeroes.
-Each element of segments will represent a horizontal or vertical line segment.  No line segment will reduce to a point.
-n will be between 1 and 1000000, inclusive.


EXAMPLES

0)
{"-10 0 10 0","0 -10 0 10"}
1

Returns: 1

This picture looks like a plus sign centered at the origin.  One way to trace this image is to start your pen at (-10,0), move right to (10,0), lift your pen and place it at (0,-10), and then move up to (0,10).  There is no way to trace the picture without lifting your pen at all, so the method returns 1.

1)
{"-10 0 0 0","0 0 10 0","0 -10 0 0","0 0 0 10"}
1

Returns: 1

The picture is the same as the previous example, except that it has been described with four line segments instead of two.  Therefore, the method still returns 1.

2)
{"-10 0 0 0","0 0 10 0","0 -10 0 0","0 0 0 10"}
4

Returns: 0

You are now required to trace each segment exactly 4 times.  You can do so without lifting your pen at all.  Start at (0,0).  Move your pen left to (-10,0), then back right to (0,0), then left again to (-10,0), then right again to (0,0).  You have now traced the first line segment 4 times.  Repeat this process for the other three segments as well.  Since no pen lifts were required, the method returns 0.

3)
{"0 0 1 0",   "2 0 4 0",   "5 0 8 0",   "9 0 13 0",
 "0 1 1 1",   "2 1 4 1",   "5 1 8 1",   "9 1 13 1",
 "0 0 0 1",   "1 0 1 1",   "2 0 2 1",   "3 0 3 1",
 "4 0 4 1",   "5 0 5 1",   "6 0 6 1",   "7 0 7 1",
 "8 0 8 1",   "9 0 9 1",   "10 0 10 1", "11 0 11 1",
 "12 0 12 1", "13 0 13 1"}
1

Returns: 6

The picture looks like this:



To trace the picture using the minimum number of pen lifts, refer to the following diagram:



Start by placing your pen at the yellow dot.  Trace the yellow square.  Now lift your pen and place it on the red dot.  Move downward, tracing the vertical line segment, and then around the perimeter of the red rectangle.  Lift your pen again and place it on the green dot.  Trace the green lines using the same method as you did for the red lines.  Lift your pen a third time, placing it on the magenta dot.  Trace the magenta lines in a similar fashion.  You will need to lift your pen three more times to trace each of the leftover white segments, for a grand total of 6 pen lifts.

4)
{"-2 6 -2 1",  "2 6 2 1",  "6 -2 1 -2",  "6 2 1 2",
 "-2 5 -2 -1", "2 5 2 -1", "5 -2 -1 -2", "5 2 -1 2",
 "-2 1 -2 -5", "2 1 2 -5", "1 -2 -5 -2", "1 2 -5 2",
 "-2 -1 -2 -6","2 -1 2 -6","-1 -2 -6 -2","-1 2 -6 2"}
5

Returns: 3

This is an example of overlap.  Once all the segments are drawn, the picture looks like this:



You would need to lift your pen 3 times to trace every segment in this drawing exactly 5 times.

5)
{"-252927 -1000000 -252927 549481","628981 580961 -971965 580961",
"159038 -171934 159038 -420875","159038 923907 159038 418077",
"1000000 1000000 -909294 1000000","1000000 -420875 1000000 66849",
"1000000 -171934 628981 -171934","411096 66849 411096 -420875",
"-1000000 -420875 -396104 -420875","1000000 1000000 159038 1000000",
"411096 66849 411096 521448","-971965 580961 -909294 580961",
"159038 66849 159038 -1000000","-971965 1000000 725240 1000000",
"-396104 -420875 -396104 -171934","-909294 521448 628981 521448",
"-909294 1000000 -909294 -1000000","628981 1000000 -909294 1000000",
"628981 418077 -396104 418077","-971965 -420875 159038 -420875",
"1000000 -1000000 -396104 -1000000","-971965 66849 159038 66849",
"-909294 418077 1000000 418077","-909294 418077 411096 418077",
"725240 521448 725240 418077","-252927 -1000000 -1000000 -1000000",
"411096 549481 -1000000 549481","628981 -171934 628981 923907",
"-1000000 66849 -1000000 521448","-396104 66849 -396104 1000000",
"628981 -1000000 628981 521448","-971965 521448 -396104 521448",
"-1000000 418077 1000000 418077","-1000000 521448 -252927 521448",
"725240 -420875 725240 -1000000","-1000000 549481 -1000000 -420875",
"159038 521448 -396104 521448","-1000000 521448 -252927 521448",
"628981 580961 628981 549481","628981 -1000000 628981 521448",
"1000000 66849 1000000 -171934","-396104 66849 159038 66849",
"1000000 66849 -396104 66849","628981 1000000 628981 521448",
"-252927 923907 -252927 580961","1000000 549481 -971965 549481",
"-909294 66849 628981 66849","-252927 418077 628981 418077",
"159038 -171934 -909294 -171934","-252927 549481 159038 549481"}
824759

Returns: 19

*/
// END CUT HERE
