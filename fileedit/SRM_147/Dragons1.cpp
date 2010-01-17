#line 2 "Dragons.cpp"
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
#define sz(a)  int((a).size())
#define pb  push_back
#define FOR(var,from,to) for(int var=(from);var<=(to);var++)
#define rep(var,n)  for(int var=0;var<(n);var++)
#define all(c)  (c).begin(),(c).end()

//#include "Fraction.h"
ll gcd(ll m, ll n)
{
  if (m == 0 || n == 0) return 0;
  if (m == 1 || n == 1) return 1;
  if (m == n) return m;
  while (1) {
        if (m == 0) return n;
        if (n == 0) return m;
        if (m > n) m %= n; else n %= m;
  }
}
// BEGIN CUT HERE
ll lcm(ll m, ll n)
{
  return m / gcd(m,n) * n;
}
// END CUT HERE
class Fraction {
  ll numer, denom;
 public:
  Fraction(){ init(0,1); }
  Fraction(ll n, ll d=1){ init(n,d); }

  Fraction& init(ll n, ll d) {
    if (d < 0) n=-n, d=-d;
    ll g = (n == 0) ? 1 : gcd(n,d);
    numer = n / g, denom = d / g;
    return *this;
  }
  Fraction& init(const Fraction& other) {
    numer = other.numer, denom = other.denom;
    return *this;
  }

  Fraction operator+(const Fraction& other) const {
    ll g = gcd(denom, other.denom), l = denom / g * other.denom;
    ll n = numer * (other.denom / g) + other.numer * (denom / g);
    return Fraction(n, l);
  }
  Fraction operator/(ll n) const { return Fraction(numer, denom*n); }

  Fraction& operator=(const Fraction& other){ return init(other); }

  string desc() const {
    stringstream ss;
    ss << numer;
    if (numer != 0 && denom != 1) ss << "/" << denom;
    return ss.str();
  }
};

class Dragons {
 public:
  string snaug(vector<int> initialFood, int rounds) {
    vector<vector<Fraction> > bowl(2,vector<Fraction>(6));
    rep(i,6) {
      bowl[0][i].init(initialFood[i]);
      bowl[1][i].init(0,1);
    }
    enum { FR=0, BK,UP,DN,LF,RG };
    
    rep(r,rounds){
      int i0=r%2, i1=(r+1)%2;
// BEGIN CUT HERE
      //      cout << "#" << r << ": " << bowl[i0] << endl;
// END CUT HERE
      bowl[i1][FR] = (bowl[i0][UP] + bowl[i0][DN] + bowl[i0][LF] + bowl[i0][RG])/4;
      bowl[i1][BK] = (bowl[i0][UP] + bowl[i0][DN] + bowl[i0][LF] + bowl[i0][RG])/4;
      bowl[i1][UP] = (bowl[i0][FR] + bowl[i0][BK] + bowl[i0][LF] + bowl[i0][RG])/4;
      bowl[i1][DN] = (bowl[i0][FR] + bowl[i0][BK] + bowl[i0][LF] + bowl[i0][RG])/4;
      bowl[i1][LF] = (bowl[i0][FR] + bowl[i0][BK] + bowl[i0][UP] + bowl[i0][DN])/4;
      bowl[i1][RG] = (bowl[i0][FR] + bowl[i0][BK] + bowl[i0][UP] + bowl[i0][DN])/4;
    }
// BEGIN CUT HERE
    //    cout << "#" << rounds << ": " << bowl[rounds%2] << endl;
// END CUT HERE
    return bowl[rounds%2][UP].desc();
  }
};

// BEGIN CUT HERE
#include <time.h>
clock_t start_time;
void timer_clear() { start_time = clock(); }
string timer() { clock_t end_time = clock(); double interval = (double)(end_time - start_time)/CLOCKS_PER_SEC; ostringstream os; os << " (" << interval*1000 << " msec)"; return os.str(); }

template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
int verify_case(const string &Expected, const string &Received) { if (Expected == Received) cerr << "PASSED" << timer() << endl; else { cerr << "FAILED" << timer() << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } return 0;}

template<int N> struct Case_ {};
char Test_(...);
int Test_(Case_<0>) {
	timer_clear();
	int initialFood_[] = {0, 0, 4, 0, 0, 0};
	  vector <int> initialFood(initialFood_, initialFood_+sizeof(initialFood_)/sizeof(*initialFood_)); 
	int rounds = 2; 
	string RetVal = "1"; 
	return verify_case(RetVal, Dragons().snaug(initialFood, rounds)); }
int Test_(Case_<1>) {
	timer_clear();
	int initialFood_[] = {0, 0, 4, 0, 0, 0};
	  vector <int> initialFood(initialFood_, initialFood_+sizeof(initialFood_)/sizeof(*initialFood_)); 
	int rounds = 3; 
	string RetVal = "1/2"; 
	return verify_case(RetVal, Dragons().snaug(initialFood, rounds)); }
int Test_(Case_<2>) {
	timer_clear();
	int initialFood_[] = {1000, 1000, 1000, 1000, 1000, 1000};
	  vector <int> initialFood(initialFood_, initialFood_+sizeof(initialFood_)/sizeof(*initialFood_)); 
	int rounds = 45; 
	string RetVal = "1000"; 
	return verify_case(RetVal, Dragons().snaug(initialFood, rounds)); }
int Test_(Case_<3>) {
	timer_clear();
	int initialFood_[] = {1, 2, 3, 4, 5, 6};
	  vector <int> initialFood(initialFood_, initialFood_+sizeof(initialFood_)/sizeof(*initialFood_)); 
	int rounds = 45; 
	string RetVal = "7/2"; 
	return verify_case(RetVal, Dragons().snaug(initialFood, rounds)); }

int Test_(Case_<4>) {
	timer_clear();
	int initialFood_[] = {0,0,0,0,0,0};
	  vector <int> initialFood(initialFood_, initialFood_+sizeof(initialFood_)/sizeof(*initialFood_)); 
	int rounds = 10;
	string RetVal = "0"; 
	return verify_case(RetVal, Dragons().snaug(initialFood, rounds)); }

template<int N> void Run_() { cerr << "Test Case #" << N << "..." << flush; Test_(Case_<N>()); Run_<sizeof(Test_(Case_<N+1>()))==1 ? -1 : N+1>(); }
template<>      void Run_<-1>() {}
int main() { Run_<0>(); }
// END CUT HERE
