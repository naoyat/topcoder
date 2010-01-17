#line 101 "CatchTheMice.cpp"
#include <string>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <cmath>
#include <float.h>
using namespace std;

#define sz(a)  int((a).size())
#define pb  push_back
#define all(c)  (c).begin(),(c).end()
#define tr(c,i)  for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); i++)

double maxnum = DBL_MAX;

class CatchTheMice {
public:
  double largestCage(vector <int> xp, vector <int> yp, vector <int> xv, vector <int> yv) {
	int n=xp.size();

	set<double> tx;
	tx.clear();

	for (int i=0;i<n;i++) {
	  for (int j=0;j<n;j++) {
		if (i < j)  {
		  if (xv[i] != xv[j]) {
			double t = (double)(xp[i] - xp[j]) / (double)(xv[j] - xv[i]);
			if (t >= 0.0) tx.insert(t);
		  }
		  if (yv[i] != yv[j]) {
			double t = (double)(yp[i] - yp[j]) / (double)(yv[j] - yv[i]);
			if (t >= 0.0) tx.insert(t);
		  }
		}
	  }
	}

	double wx_, wy_, t_ = 0.0;
	{
	  double xmin = maxnum, xmax = -maxnum, ymin = maxnum, ymax = -maxnum;
	  for (int i=0;i<n;i++) {
		double x = (double)xp[i];
		double y = (double)yp[i];
		if (x < xmin) xmin = x;
		if (x > xmax) xmax = x;
		if (y < ymin) ymin = y;
		if (y > ymax) ymax = y;
	  }
	  wx_ = xmax - xmin;
	  wy_ = ymax - ymin;
	}
	double mmw = max(wx_,wy_);

	tr(tx,it) {
	  double t = *it;
	  double xmin = maxnum, xmax = -maxnum, ymin = maxnum, ymax = -maxnum;
	  for (int i=0;i<n;i++) {
		double x = t*xv[i] + xp[i];
		double y = t*yv[i] + yp[i];
		if (x < xmin) xmin = x;
		if (x > xmax) xmax = x;
		if (y < ymin) ymin = y;
		if (y > ymax) ymax = y;
	  }

	  double wx = xmax - xmin;
	  double wy = ymax - ymin;
	  if (t > 0 && ((wx_ < wy_ && wx > wy) || (wx_ > wy_ && wx < wy))) {
		double dx = wx - wx_, dy = wy - wy_;
		double w = (wx_ * dy - wy_ * dx) / (dy - dx);
		if (w < mmw) mmw = w;
	  } else {
		double w = max(wx,wy);
		if (w < mmw) mmw = w;
	  }
	  wx_ = wx;
	  wy_ = wy;
	  t_ = t;
	}
	return mmw;
  }

};

// BEGIN CUT HERE
#include <time.h>
clock_t start_time;
void timer_clear() { start_time = clock(); }
string timer() { clock_t end_time = clock(); double interval = (double)(end_time - start_time)/CLOCKS_PER_SEC; ostringstream os; os << " (" << interval*1000 << " msec)"; return os.str(); }

template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
int verify_case(const double &Expected, const double &Received) { double diff = Expected - Received; if (diff < 0) diff = -diff; if (diff < 1e-9) cerr << "PASSED" << timer() << endl; else { cerr << "FAILED" << timer() << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } return 0;}

template<int N> struct Case_ {};
char Test_(...);
int Test_(Case_<0>) {
	timer_clear();
	int xp_[] = {0,10};
	  vector <int> xp(xp_, xp_+sizeof(xp_)/sizeof(*xp_)); 
	int yp_[] = {0,10};
	  vector <int> yp(yp_, yp_+sizeof(yp_)/sizeof(*yp_)); 
	int xv_[] = {10,-10};
	  vector <int> xv(xv_, xv_+sizeof(xv_)/sizeof(*xv_)); 
	int yv_[] = {0,0};
	  vector <int> yv(yv_, yv_+sizeof(yv_)/sizeof(*yv_)); 
	double RetVal = 10.0; 
	return verify_case(RetVal, CatchTheMice().largestCage(xp, yp, xv, yv)); }
int Test_(Case_<1>) {
	timer_clear();
	int xp_[] = {0,10,0};
	  vector <int> xp(xp_, xp_+sizeof(xp_)/sizeof(*xp_)); 
	int yp_[] = {0,0,10};
	  vector <int> yp(yp_, yp_+sizeof(yp_)/sizeof(*yp_)); 
	int xv_[] = {1,-6,4};
	  vector <int> xv(xv_, xv_+sizeof(xv_)/sizeof(*xv_)); 
	int yv_[] = {4,5,-4};
	  vector <int> yv(yv_, yv_+sizeof(yv_)/sizeof(*yv_)); 
	double RetVal = 3.0; 
	return verify_case(RetVal, CatchTheMice().largestCage(xp, yp, xv, yv)); }
int Test_(Case_<2>) {
	timer_clear();
	int xp_[] = {50,10,30,15};
	  vector <int> xp(xp_, xp_+sizeof(xp_)/sizeof(*xp_)); 
	int yp_[] = {-10,30,20,40};
	  vector <int> yp(yp_, yp_+sizeof(yp_)/sizeof(*yp_)); 
	int xv_[] = {-5,-10,-15,-5};
	  vector <int> xv(xv_, xv_+sizeof(xv_)/sizeof(*xv_)); 
	int yv_[] = {40,-10,-1,-50};
	  vector <int> yv(yv_, yv_+sizeof(yv_)/sizeof(*yv_)); 
	double RetVal = 40.526315789473685; 
	return verify_case(RetVal, CatchTheMice().largestCage(xp, yp, xv, yv)); }
int Test_(Case_<3>) {
	timer_clear();
	int xp_[] = {0,10,10,0};
	  vector <int> xp(xp_, xp_+sizeof(xp_)/sizeof(*xp_)); 
	int yp_[] = {0,0,10,10};
	  vector <int> yp(yp_, yp_+sizeof(yp_)/sizeof(*yp_)); 
	int xv_[] = {1,0,-1,0};
	  vector <int> xv(xv_, xv_+sizeof(xv_)/sizeof(*xv_)); 
	int yv_[] = {0,1,0,-1};
	  vector <int> yv(yv_, yv_+sizeof(yv_)/sizeof(*yv_)); 
	double RetVal = 10.0; 
	return verify_case(RetVal, CatchTheMice().largestCage(xp, yp, xv, yv)); }
int Test_(Case_<4>) {
	timer_clear();
	int xp_[] = {13,50,100,40,-100};
	  vector <int> xp(xp_, xp_+sizeof(xp_)/sizeof(*xp_)); 
	int yp_[] = {20,20,-150,-40,63};
	  vector <int> yp(yp_, yp_+sizeof(yp_)/sizeof(*yp_)); 
	int xv_[] = {4,50,41,-41,-79};
	  vector <int> xv(xv_, xv_+sizeof(xv_)/sizeof(*xv_)); 
	int yv_[] = {1,1,1,3,-1};
	  vector <int> yv(yv_, yv_+sizeof(yv_)/sizeof(*yv_)); 
	double RetVal = 212.78688524590163; 
	return verify_case(RetVal, CatchTheMice().largestCage(xp, yp, xv, yv)); }
int Test_(Case_<5>) {
	timer_clear();
	int xp_[] = {0,10};
	  vector <int> xp(xp_, xp_+sizeof(xp_)/sizeof(*xp_)); 
	int yp_[] = {0,0};
	  vector <int> yp(yp_, yp_+sizeof(yp_)/sizeof(*yp_)); 
	int xv_[] = {5,5};
	  vector <int> xv(xv_, xv_+sizeof(xv_)/sizeof(*xv_)); 
	int yv_[] = {3,3};
	  vector <int> yv(yv_, yv_+sizeof(yv_)/sizeof(*yv_)); 
	double RetVal = 10.0; 
	return verify_case(RetVal, CatchTheMice().largestCage(xp, yp, xv, yv)); }
int Test_(Case_<6>) {
	timer_clear();
	int xp_[] = {-49,-463,-212,-204,-557,-67,-374,-335,-590,-4};
	  vector <int> xp(xp_, xp_+sizeof(xp_)/sizeof(*xp_)); 
	int yp_[] = {352,491,280,355,129,78,404,597,553,445};
	  vector <int> yp(yp_, yp_+sizeof(yp_)/sizeof(*yp_)); 
	int xv_[] = {-82,57,-23,-32,89,-72,27,17,100,-94};
	  vector <int> xv(xv_, xv_+sizeof(xv_)/sizeof(*xv_)); 
	int yv_[] = {-9,-58,9,-14,56,75,-32,-98,-81,-43};
	  vector <int> yv(yv_, yv_+sizeof(yv_)/sizeof(*yv_)); 
	double RetVal = 25.467532467532468; 
	return verify_case(RetVal, CatchTheMice().largestCage(xp, yp, xv, yv)); }

template<int N> void Run_() { cerr << "Test Case #" << N << "..." << flush; Test_(Case_<N>()); Run_<sizeof(Test_(Case_<N+1>()))==1 ? -1 : N+1>(); }
template<>      void Run_<-1>() {}
int main() { Run_<0>(); }
// END CUT HERE


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
