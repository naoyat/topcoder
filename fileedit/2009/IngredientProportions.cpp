// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// Your friend has invented a splendid cocktail consisting of N ingredients.  However, she has forgotten the amount of each ingredient that goes into the recipe.

For N-1 pairs of ingredients, she remembers the proportion in which the ingredients within each pair should be added to the cocktail. Fortunately, these N-1 proportions are sufficient to restore the recipe of the entire cocktail.

You are given a vector <string> proportions containing the N-1 proportions. Each element is formatted "# and # as :<q>" (quotes for clarity), which means that the mass of ingredient  divided by the mass of ingredient  in the cocktail must be equal to /<q> (all ingredients are 0-indexed). Return a vector <int> containing exactly N elements, where the i-th element is the mass of ingredient i, such that all the given proportions are satisfied and the total mass is as small as possible.  The total mass must be greater than 0.

DEFINITION
Class:IngredientProportions
Method:getMasses
Parameters:vector <string>
Returns:vector <int>
Method signature:vector <int> getMasses(vector <string> proportions)


CONSTRAINTS
-proportions will contain between 1 and 9 elements, inclusive.
-proportions will contain exactly N-1 elements, where N is the number of ingredients in the cocktail.
-Each element of proportions will contain exactly 16 characters.
-Each element of proportions will be formatted as described in the statement.
-Each  will be between 0 and N-1, inclusive.
-Each  will be between 0 and N-1, inclusive.
-Each  will be between 1 and 9, inclusive.
-Each <q> will be between 1 and 9, inclusive.
-The information given in proportions will be sufficient to restore the recipe of the cocktail uniquely up to a constant factor.


EXAMPLES

0)
{"#0 and #1 as 6:4"}

Returns: {3, 2 }

Taking 6 units of ingredient #0 and 4 units of ingredient #1 would satisfy the proportion, but it wouldn't give the smallest possible total mass. To minimize the total mass, divide the masses by 2.

1)
{"#0 and #1 as 9:8","#1 and #2 as 9:8"}


Returns: {81, 72, 64 }



2)
{"#4 and #0 as 1:1", "#4 and #1 as 3:1", "#4 and #2 as 5:1", "#4 and #3 as 7:1"}

Returns: {105, 35, 21, 15, 105 }

The mass of ingredient #4 should be divisible by 3, 5 and 7. The smallest such number is 105.

3)
{"#2 and #3 as 6:8", "#0 and #1 as 9:3", "#3 and #0 as 7:5"}

Returns: {60, 20, 63, 84 }



*/
// END CUT HERE

#line 65 "IngredientProportions.cpp"
#include <string>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <algorithm>
// BEGIN CUT HERE
#include <iostream>
#include "cout.h"
// END CUT HERE
#include <sstream>
#include <cmath>
using namespace std;

#define sz(a)  int((a).size())
#define pb  push_back
#define all(c)  (c).begin(),(c).end()
#define tr(c,i)  for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); i++)

long long gcd(long long m, long long n)
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

vector<string> split(string str, int delim=' ')
{
  vector<string> result;

  const char *s = str.c_str();
  if (delim == ' ') {
    for (const char *p=s; *p; p++) {
      if (*p == delim)
        s++;
      else
        break;
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

class IngredientProportions {
  long long mll[10];
  bool from[10][10];
  int N;
  
  void h(int id, long long n, long long d) {
	vector<bool> chk(N,false);
	chk[id] = true;
	for (int i=0;i<N;i++) if (i==id || mll[id]<0) chk[i]=true;

// BEGIN CUT HERE
//	printf("h(%d, %lld,%lld)\n", id,n,d);
// END CUT HERE
	if (n == d) return;

	priority_queue<int> pq;
	pq.push(id);

	while (!pq.empty()) {
	  int i = pq.top();
	  pq.pop();

	  mll[i] = mll[i] * n / d; // bにつながるやつ全部q/gb倍！
	  chk[i] = true;

	  for (int j=0; j<N; j++) {
		if (chk[j]) continue;
		if (from[i][j]) {
		  pq.push(j);
		  //mll[i] = mll[i] * n / d;
		  //chk[i] = true; h(i,n,d);
		}
	  }
	  
	}
  }

public:
  vector<int> getMasses(vector<string> proportions) {
// BEGIN CUT HERE
	// 1-9 + 1 ;; 16
// END CUT HERE
	N = proportions.size() + 1;
	//vector<long long> mll(N,-1LL);
	//vector<vector<bool> > from(N);
	for(int i=0;i<N;i++) {
	  mll[i] = -1;
	  for(int j=0;j<N;j++) from[i][j] = false;
	}

	tr(proportions,it) {
	  vector<string> ps = split(*it); // #0 and #1 as 6:4
	  int a = atoi(ps[0].c_str()+1), b = atoi(ps[2].c_str()+1);
	  vector<string> qs = split(ps[4],':');
	  int p = atoi(qs[0].c_str()), q = atoi(qs[1].c_str()), g = gcd(p,q);
	  p /= g; q /= g;
// BEGIN CUT HERE
//	  printf("#(%d) and #(%d) as (%d):(%d) \n", a,b,p,q);
//	  for (int i=0;i<N;i++) printf(" %lld",mll[i]); printf("\n");
// END CUT HERE

	  if (mll[a] < 0 && mll[b] < 0) {
		mll[a] = p; mll[b] = q;
	  } else if (mll[a] < 0) {
		mll[a] = mll[b] * p;
		h(b, q,1);
	  } else if (mll[b] < 0) {
		mll[b] = mll[a] * q;
		h(a, p,1);
	  } else {
		long long mga = mll[b] * p, mgb = mll[a] * q;
		long long g = gcd(mga,mgb);
		mga /= g; mgb /= g;
		h(a, mga, 1);
		h(b, mgb, 1);
// BEGIN CUT HERE
//		cout << "<3> ";
//		for (int i=0;i<N;i++) printf(" %lld",mll[i]); printf("\n");
// END CUT HERE
	  }
	  from[a][b] = from[b][a] = true;
	}
	
	long long g = mll[0];
	for (int i=1;i<N;i++) g = gcd(g,mll[i]);

	vector<int> masses(N);
	for (int i=0;i<N;i++) masses[i] = (int)(mll[i]/g);
	return masses;
  }
};

// BEGIN CUT HERE
#include <time.h>
clock_t start_time;
void timer_clear() { start_time = clock(); }
string timer() { clock_t end_time = clock(); double interval = (double)(end_time - start_time)/CLOCKS_PER_SEC; ostringstream os; os << " (" << interval*1000 << " msec)"; return os.str(); }

template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
int verify_case(const vector <int> &Expected, const vector <int> &Received) { if (Expected == Received) cerr << "PASSED" << timer() << endl; else { cerr << "FAILED" << timer() << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } return 0;}

template<int N> struct Case_ {};
char Test_(...);
int Test_(Case_<0>) {
	timer_clear();
	string proportions_[] = {"#0 and #1 as 6:4"};
	  vector <string> proportions(proportions_, proportions_+sizeof(proportions_)/sizeof(*proportions_)); 
	int RetVal_[] = {3, 2 };
	  vector <int> RetVal(RetVal_, RetVal_+sizeof(RetVal_)/sizeof(*RetVal_)); 
	return verify_case(RetVal, IngredientProportions().getMasses(proportions)); }
int Test_(Case_<1>) {
	timer_clear();
	string proportions_[] = {"#0 and #1 as 9:8","#1 and #2 as 9:8"}
;
	  vector <string> proportions(proportions_, proportions_+sizeof(proportions_)/sizeof(*proportions_)); 
	int RetVal_[] = {81, 72, 64 };
	  vector <int> RetVal(RetVal_, RetVal_+sizeof(RetVal_)/sizeof(*RetVal_)); 
	return verify_case(RetVal, IngredientProportions().getMasses(proportions)); }
int Test_(Case_<2>) {
	timer_clear();
	string proportions_[] = {"#4 and #0 as 1:1", "#4 and #1 as 3:1", "#4 and #2 as 5:1", "#4 and #3 as 7:1"};
	  vector <string> proportions(proportions_, proportions_+sizeof(proportions_)/sizeof(*proportions_)); 
	int RetVal_[] = {105, 35, 21, 15, 105 };
	  vector <int> RetVal(RetVal_, RetVal_+sizeof(RetVal_)/sizeof(*RetVal_)); 
	return verify_case(RetVal, IngredientProportions().getMasses(proportions)); }
int Test_(Case_<3>) {
	timer_clear();
	string proportions_[] = {"#2 and #3 as 6:8", "#0 and #1 as 9:3", "#3 and #0 as 7:5"};
	  vector <string> proportions(proportions_, proportions_+sizeof(proportions_)/sizeof(*proportions_)); 
	int RetVal_[] = {60, 20, 63, 84 };
	  vector <int> RetVal(RetVal_, RetVal_+sizeof(RetVal_)/sizeof(*RetVal_)); 
	return verify_case(RetVal, IngredientProportions().getMasses(proportions)); }
int Test_(Case_<4>) {
	timer_clear();
	string proportions_[] = {"#2 and #3 as 6:8", "#3 and #0 as 7:5", "#0 and #1 as 9:3"};
	  vector <string> proportions(proportions_, proportions_+sizeof(proportions_)/sizeof(*proportions_)); 
	int RetVal_[] = {60, 20, 63, 84 };
	  vector <int> RetVal(RetVal_, RetVal_+sizeof(RetVal_)/sizeof(*RetVal_)); 
	return verify_case(RetVal, IngredientProportions().getMasses(proportions)); }
int Test_(Case_<5>) {
	timer_clear();
	string proportions_[] = {"#0 and #1 as 8:9", "#0 and #2 as 4:5"};
	  vector <string> proportions(proportions_, proportions_+sizeof(proportions_)/sizeof(*proportions_)); 
	  int RetVal_[] = {8,9,10};
	  vector <int> RetVal(RetVal_, RetVal_+sizeof(RetVal_)/sizeof(*RetVal_)); 
	return verify_case(RetVal, IngredientProportions().getMasses(proportions)); }
int Test_(Case_<6>) {
	timer_clear();
	string proportions_[] = {"#0 and #1 as 8:9",
							 "#1 and #2 as 8:9",
							 "#2 and #3 as 8:9",
							 "#4 and #3 as 8:9",
							 "#4 and #5 as 8:9",
							 "#6 and #5 as 8:9",
							 "#6 and #7 as 8:9",
							 "#7 and #8 as 8:9",
							 "#8 and #9 as 8:9" };
	  vector <string> proportions(proportions_, proportions_+sizeof(proportions_)/sizeof(*proportions_)); 
	  int RetVal_[] = { 32768,36864,41472,46656,41472,46656,41472,46656,52488,59049};
	  vector <int> RetVal(RetVal_, RetVal_+sizeof(RetVal_)/sizeof(*RetVal_)); 
	return verify_case(RetVal, IngredientProportions().getMasses(proportions)); }
int Test_(Case_<9>) {
	timer_clear();
	string proportions_[] = {"#0 and #1 as 9:9",
							 "#1 and #2 as 9:9",
							 "#2 and #3 as 9:9",
							 "#4 and #3 as 9:9",
							 "#4 and #5 as 9:9",
							 "#6 and #5 as 9:9",
							 "#6 and #7 as 9:9",
							 "#7 and #8 as 9:9",
							 "#8 and #9 as 9:9" };
	  vector <string> proportions(proportions_, proportions_+sizeof(proportions_)/sizeof(*proportions_));
	  int RetVal_[] = { 1,1,1,1,1,1,1,1,1,1 };
	  vector <int> RetVal(RetVal_, RetVal_+sizeof(RetVal_)/sizeof(*RetVal_)); 
	return verify_case(RetVal, IngredientProportions().getMasses(proportions)); }
int Test_(Case_<10>) {
	timer_clear();
	string proportions_[] = {"#0 and #1 as 9:8",
							 "#1 and #2 as 9:8",
							 "#2 and #3 as 9:8",
							 "#3 and #4 as 9:8",
							 "#4 and #5 as 9:8",
							 "#5 and #6 as 9:8",
							 "#6 and #7 as 9:8",
							 "#7 and #8 as 9:8",
							 "#8 and #9 as 9:8" };
	  vector <string> proportions(proportions_, proportions_+sizeof(proportions_)/sizeof(*proportions_));
	  int RetVal_[] = { 1,1,1,1,1,1,1,1,1,1 };
	  vector <int> RetVal(RetVal_, RetVal_+sizeof(RetVal_)/sizeof(*RetVal_)); 
	return verify_case(RetVal, IngredientProportions().getMasses(proportions)); }
int Test_(Case_<7>) {
	timer_clear();
	string proportions_[] = {"#0 and #1 as 1:1"};
	  vector <string> proportions(proportions_, proportions_+sizeof(proportions_)/sizeof(*proportions_)); 
	  int RetVal_[] = {1,1};
	  vector <int> RetVal(RetVal_, RetVal_+sizeof(RetVal_)/sizeof(*RetVal_)); 
	return verify_case(RetVal, IngredientProportions().getMasses(proportions)); }
int Test_(Case_<8>) {
	timer_clear();
	string proportions_[] = {"#0 and #1 as 9:9"};
	  vector <string> proportions(proportions_, proportions_+sizeof(proportions_)/sizeof(*proportions_)); 
	  int RetVal_[] = {1,1};
	  vector <int> RetVal(RetVal_, RetVal_+sizeof(RetVal_)/sizeof(*RetVal_)); 
	return verify_case(RetVal, IngredientProportions().getMasses(proportions)); }

template<int N> void Run_() { cerr << "Test Case #" << N << "..." << flush; Test_(Case_<N>()); Run_<sizeof(Test_(Case_<N+1>()))==1 ? -1 : N+1>(); }
template<>      void Run_<-1>() {}
int main() { Run_<0>(); }
// END CUT HERE

