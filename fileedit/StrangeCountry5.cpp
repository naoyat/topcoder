#line 2 "StrangeCountry.cpp"
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
#define sz(a)  int((a).size())
#define pb  push_back
#define all(c)  (c).begin(),(c).end()
#define tr(c,i)  for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); i++)
#define rep(var,n)  for(int var=0;var<(n);var++)
#define found(s,e)  ((s).find(e)!=(s).end())

vector<int> isle(const vector<string>& plan, int connection='Y') {
  //template <typename T> vector<int> isle(vector<vector<T> >& plan, T connection) {
  int n=plan.size();
  vector<int> id(n,0); for(int i=0;i<n;i++) id[i]=i;
  for (int i=0;i<n-1;i++) {
    for (int j=i+1;j<n;j++) {
      if (plan[i][j]==connection) {
        int idi=id[i],idj=id[j];
        if (idi>idj) {
          replace(id.begin(),id.end(),idi,idj);
        } else if (idi<idj) {
          replace(id.begin(),id.end(),idj,idi);
        }
      }
    }
  }
  return id;
}
map<int,int> summary(const vector<int>& id)
{
  map<int,int> s;
  for(int i=id.size()-1;i>=0;i--){
    if(s.find(id[i])==s.end()) s[id[i]]=1;
    else s[id[i]]++;
  }
  return s;
}
vector<int> hands(const vector<string>& plan, const vector<int>& id, int connection='Y') {
  int n=plan.size();
  vector<int> hz(n,0);
  for (int i=0;i<n-1;i++) {
    for (int j=i+1;j<n;j++) {
      if (plan[i][j]==connection) hz[id[i]]++;
    }
  }
  return hz;
}

class StrangeCountry {
 public:
  int transform(vector <string> g) {
    int N=sz(g);
    vi isle_ids=isle(g,'Y');
    map<int,int> s=summary(isle_ids);
    int dem=sz(s)-1, sup=0;
    vi hz = hands(g,isle_ids);
    tr(s,it) {
      if (it->second==1) return -1;
      sup += hz[it->first] - (it->second - 1);
    }
    return dem<=sup ? dem : -1;
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
	string g_[] = {"NY",
 "YN"};
	  vector <string> g(g_, g_+sizeof(g_)/sizeof(*g_)); 
	int RetVal = 0; 
	return verify_case(RetVal, StrangeCountry().transform(g)); }

int Test_(Case_<1>) {
	timer_clear();
	string g_[] = {"NYYNN",
 "YNYNN",
 "YYNNN",
 "NNNNY",
 "NNNYN"};
	  vector <string> g(g_, g_+sizeof(g_)/sizeof(*g_)); 
	int RetVal = 1; 
	return verify_case(RetVal, StrangeCountry().transform(g)); }

int Test_(Case_<2>) {
	timer_clear();
	string g_[] = {"NYYNNNN",
 "YNYNNNN",
 "YYNNNNN",
 "NNNNYYN",
 "NNNYNYY",
 "NNNYYNY",
 "NNNNYYN"};
	  vector <string> g(g_, g_+sizeof(g_)/sizeof(*g_)); 
	int RetVal = 1; 
	return verify_case(RetVal, StrangeCountry().transform(g)); }

int Test_(Case_<3>) {
	timer_clear();
	string g_[] = {"NYNYNNNNNNNN",
 "YNYNNNNNNNNN",
 "NYNYYNNNNNNN",
 "YNYNNNNNNNNN",
 "NNYNNYYNNNNN",
 "NNNNYNYNNNNN",
 "NNNNYYNNNNNN",
 "NNNNNNNNYYNN",
 "NNNNNNNYNYNN",
 "NNNNNNNYYNNN",
 "NNNNNNNNNNNY",
 "NNNNNNNNNNYN"};
	  vector <string> g(g_, g_+sizeof(g_)/sizeof(*g_)); 
	int RetVal = 2; 
	return verify_case(RetVal, StrangeCountry().transform(g)); }

int Test_(Case_<4>) {
	timer_clear();
	string g_[] = {"NYNNNN",
 "YNYNNN",
 "NYNYNN",
 "NNYNNN",
 "NNNNNY",
 "NNNNYN"};
	  vector <string> g(g_, g_+sizeof(g_)/sizeof(*g_)); 
	int RetVal = -1; 
	return verify_case(RetVal, StrangeCountry().transform(g)); }

int Test_(Case_<5>) { // 15
	timer_clear();
	string g_[] = {"NNNNNNNNNNNNNNNYNNNNNNNYNNYNNNNNNNNNNNNNNN", // 0
                   "NNNNNNNNNNNYNNNNNNNNNNNNNNNNNNYNNNNNNNNNNN",
                   "NNNNNNNYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN", // 2
                   "NNNNNNNNNNNYNNNNNNNNNNNNNNNNNNYNNNNNYNNNNN",
                   "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYNNNNNNNN", // 4
                   "NNNNNNNNNNNNNNYNYNNNNNNNNNNNNNNNNNNNNNNNNY",
                   "NNNNNNNNNYYNNNNNNNNNNNNNNNNNYNNNNNNNNNNNNN", // 6
                   "NNYNNNNNNNNNNNNNNYNNNNNNNNNYNNNNNNNNNNNNNN",
                   "NNNNNNNNNNNNNNNNNNNNNNNNNNNYNNNNNNNNNNNNNN", // 8
                   "NNNNNNYNNNYNNNNNNNNNNNNNNNNNYNNNNNNNNNNNNN",

                   "NNNNNNYNNYNNNNNNNNNNNNNNNNNNYNNNNNNNNNNNNN", // 10
                   "NYNYNNNNNNNNNNNNNNNNNNNNNNNNNNYNNNNNYNNNNN",
                   "NNNNNNNNNNNNNYNNNNYNNNNNNNNNNNNNNNNNNNNYNN", // 12
                   "NNNNNNNNNNNNYNNNNNYNNNNNNNNNNNNNNNNNNNNYNN",
                   "NNNNNYNNNNNNNNNNYNNNNNNNNNNNNNNNNNNNNNNNNY", // 14
                   "YNNNNNNNNNNNNNNNNNNNNNNYNNYNNNNNNNNNNNNNNN",
                   "NNNNNYNNNNNNNNYNNNNNNNNNNNNNNNNNNNNNNNNNNY", // 16
                   "NNNNNNNYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN",
                   "NNNNNNNNNNNNYYNNNNNNNNNNNNNNNNNNNNNYNNNYNN", // 18
                   "NNNNNNNNNNNNNNNNNNNNNYNNNNNNNNNNNNNNNYNNNN",

                   "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNYNYNNNNNNNNNN", // 20
                   "NNNNNNNNNNNNNNNNNNNYNNNNNNNNNNNNNNNNNNYNNN",
                   "NNNNNNNNNNNNNNNNNNNNNNNNYNNNNNNNNNNNNNNNNN", // 22
                   // 0123456789+123456789+123456789+123456789+1
                   "YNNNNNNNNNNNNNNYNNNNNNNNNNYNNNNNNNNNNNNNNN",
                   "NNNNNNNNNNNNNNNNNNNNNNYNNNNNNNNNNYNNNNNNNN", // 24
                   "NNNNNNNNNNNNNNNNNNNNNNNNNNNYNNNNNNNNNNNNNN",
                   "YNNNNNNNNNNNNNNYNNNNNNNYNNNNNNNNNNNNNNNNNN", // 26
                   "NNNNNNNYYNNNNNNNNNNNNNNNNYNNNNNNNNNNNNNNNN",
                   "NNNNNNYNNYYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN", // 28
                   "NNNNNNNNNNNNNNNNNNNNYNNNNNNNNNNNNNNNNNNNNN",

                   "NYNYNNNNNNNYNNNNNNNNNNNNNNNNNNNNNNNNYNNNNN", // 30
                   "NNNNNNNNNNNNNNNNNNNNYNNNNNNNNNNNYNYNNNNNYN",
                   "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYNNNNNNNNNN", // 32
                   "NNNNYNNNNNNNNNNNNNNNNNNNYNNNNNNNNNNNNNNNNN",
                   "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYNNNNNNNNNN", // 34
                   "NNNNNNNNNNNNNNNNNNYNNNNNNNNNNNNNNNNNNNNNNN",
                   "NNNYNNNNNNNYNNNNNNNNNNNNNNNNNNYNNNNNNNNNNN", // 36
                   "NNNNNNNNNNNNNNNNNNNYNNNNNNNNNNNNNNNNNNNNNN",
                   "NNNNNNNNNNNNNNNNNNNNNYNNNNNNNNNNNNNNNNNNNN", // 38
                   "NNNNNNNNNNNNYYNNNNYNNNNNNNNNNNNNNNNNNNNNNN",

                   "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYNNNNNNNNNN", // 40
                   "NNNNNYNNNNNNNNYNYNNNNNNNNNNNNNNNNNNNNNNNNN"};
    vector <string> g(g_, g_+sizeof(g_)/sizeof(*g_)); 
	int RetVal = 8; 
	return verify_case(RetVal, StrangeCountry().transform(g)); }

int Test_(Case_<6>) { // 18
	timer_clear();
	string g_[] = {"NNNNNNNNNNNNYNNNNNNNNNNYNNNYNNNNNNNNNNNN",
                   "NNYNNNNNNNNNNNYNNNNNYNNNNNNNNNNNNNNNNNNN",
                   "NYNNNNNNNNNNNNYNNNNNYNNNNNNNNNNNNNNNNNNN",
                   "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYNNNNNNN",
                   "NNNNNNNYNNNNNNNYNNNNNNNNYNNNNNNNNNNNYNNN",
                   "NNNNNNNNYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN",
                   "NNNNNNNNNNYNNNNNNNNNNNNNNNYNNNNNNNNNNYNN",
                   "NNNNYNNNNNNNNNNYNNNNNNNNYNNNNNNNNNNNYNNN",
                   "NNNNNYNNNNNNNNNNYNNNNNNNNNNNNNNNNNNNNNNN",
                   "NNNNNNNNNNNYNNNNNYNNNNNNNNNNNNNNNNNNNNYN",
                   
                   "NNNNNNYNNNNNNNNNNNNNNNNNNNYNNNNNNNNNNYNN",
                   "NNNNNNNNNYNNNNNNNYNNNNNNNNNNNNNNNNNNNNYN",
                   "YNNNNNNNNNNNNNNNNNNNNNNYNNNYNNNNNNNNNNNN",
                   "NNNNNNNNNNNNNNNNNNNNNYNNNNNNNNNNNNYNNNNY",
                   "NYYNNNNNNNNNNNNNNNNNYNNNNNNNNNNNNNNNNNNN",
                   "NNNNYNNYNNNNNNNNNNNNNNNNYNNNNNNNNNNNYNNN",
                   "NNNNNNNNYNNNNNNNNNNYNNNNNNNNNNNNNNNNNNNN",
                   "NNNNNNNNNYNYNNNNNNNNNNNNNNNNNNNNNNNNNNYN",
                   "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNYNNYNNNNNNN",
                   "NNNNNNNNNNNNNNNNYNNNNNNNNYNNNNNNNNNNNNNN",

                   "NYYNNNNNNNNNNNYNNNNNNNNNNNNNNNNNNNNNNNNN",
                   "NNNNNNNNNNNNNYNNNNNNNNNNNNNNNNNNNNYNNNNY",
                   "NNNNNNNNNNNNNNNNNNNNNNNNNNNNYNNNNNNNNNNN",
                   "YNNNNNNNNNNNYNNNNNNNNNNNNNNYNNNNNNNNNNNN",
                   "NNNNYNNYNNNNNNNYNNNNNNNNNNNNNNNNNNNNYNNN",
                   "NNNNNNNNNNNNNNNNNNNYNNNNNNNNNNYNNNNYNNNN",
                   "NNNNNNYNNNYNNNNNNNNNNNNNNNNNNNNNNNNNNYNN",
                   "YNNNNNNNNNNNYNNNNNNNNNNYNNNNNNNNNNNNNNNN",
                   "NNNNNNNNNNNNNNNNNNNNNNYNNNNNNNNNNYNNNNNN",
                   "NNNNNNNNNNNNNNNNNNYNNNNNNNNNNNNNNNNNNNNN",

                   "NNNNNNNNNNNNNNNNNNNNNNNNNYNNNNNNNNNNNNNN",
                   "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYNNNNNN",
                   "NNNYNNNNNNNNNNNNNNYNNNNNNNNNNNNNNNNNNNNN",
                   "NNNNNNNNNNNNNNNNNNNNNNNNNNNNYNNYNNNNNNNN",
                   "NNNNNNNNNNNNNYNNNNNNNYNNNNNNNNNNNNNNNNNY",
                   "NNNNNNNNNNNNNNNNNNNNNNNNNYNNNNNNNNNNNNNN",
                   "NNNNYNNYNNNNNNNYNNNNNNNNYNNNNNNNNNNNNNNN",
                   "NNNNNNYNNNYNNNNNNNNNNNNNNNYNNNNNNNNNNNNN",
                   "NNNNNNNNNYNYNNNNNYNNNNNNNNNNNNNNNNNNNNNN",
                   "NNNNNNNNNNNNNYNNNNNNNYNNNNNNNNNNNNYNNNNN"};
    vector <string> g(g_, g_+sizeof(g_)/sizeof(*g_)); 
	int RetVal = 8; 
	return verify_case(RetVal, StrangeCountry().transform(g)); }

template<int N> void Run_() { cerr << "Test Case #" << N << "..." << flush; Test_(Case_<N>()); Run_<sizeof(Test_(Case_<N+1>()))==1 ? -1 : N+1>(); }
template<>      void Run_<-1>() {}
int main() { Run_<0>(); }
// END CUT HERE


// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// There is a country with N cities, some of which are connected with bidirectional roads.  Your task is to reconfigure the roads so that it is possible to get from each city to every other city.  You must do this using the minimum possible number of transformations, where each transformation consists of the following steps:


Choose four different cities A, B, C and D, where roads (A, B) and (C, D) exist, but (A, C), (A, D), (B, C) and (B, D) do not exist.
Destroy roads (A, B) and (C, D).
Build two new roads - either (A, C) and (B, D), or (A, D) and (B, C).


The following images show an example of this transformation. From the first situation you can get the second one or the third one:

  

You are given a vector <string> g, where the j-th character of the i-th element is 'Y' if there is a road between cities i and j, and 'N' otherwise.  Return minimal number of transformations required to accomplish your task, or return -1 if it is impossible.

DEFINITION
Class:StrangeCountry
Method:transform
Parameters:vector <string>
Returns:int
Method signature:int transform(vector <string> g)


CONSTRAINTS
-g will contain between 2 and 50 elements, inclusive.
-Each element of g will contain exactly N characters 'Y' or 'N', where N is the number of elements in g.
-For each i and j, g[i][j] will be equal to g[j][i].
-For each i, g[i][i] will be equal to 'N'.


EXAMPLES

0)
{"NY",
 "YN"}

Returns: 0

This country is already connected.

1)
{"NYYNN",
 "YNYNN",
 "YYNNN",
 "NNNNY",
 "NNNYN"}

Returns: 1

 

2)
{"NYYNNNN",
 "YNYNNNN",
 "YYNNNNN",
 "NNNNYYN",
 "NNNYNYY",
 "NNNYYNY",
 "NNNNYYN"}

Returns: 1



3)
{"NYNYNNNNNNNN",
 "YNYNNNNNNNNN",
 "NYNYYNNNNNNN",
 "YNYNNNNNNNNN",
 "NNYNNYYNNNNN",
 "NNNNYNYNNNNN",
 "NNNNYYNNNNNN",
 "NNNNNNNNYYNN",
 "NNNNNNNYNYNN",
 "NNNNNNNYYNNN",
 "NNNNNNNNNNNY",
 "NNNNNNNNNNYN"}

Returns: 2



4)
{"NYNNNN",
 "YNYNNN",
 "NYNYNN",
 "NNYNNN",
 "NNNNNY",
 "NNNNYN"}

Returns: -1



*/
// END CUT HERE
