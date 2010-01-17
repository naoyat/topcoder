#line 2 "HealthFood.cpp"
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
#define forr(var,from,to) for(int var=(from);var<=(to);var++) 
#define found(s,e)  ((s).find(e)!=(s).end())
#define remove_(c,val) (c).erase(remove((c).begin(),(c).end(),(val)),(c).end())
#define lastc(str) (*((str).end()-1))

class HealthFood {
 public:
  vector <int> selectMeals(vector <int> protein,
                           vector <int> carbs,
                           vector <int> fat,
                           vector <string> dietPlans) {
    int n=sz(dietPlans), m=sz(protein);
    vector<int> ans(n);
    rep(i,n){
      ll p=0,c=0,f=0,t=0;
      string dp = dietPlans[i]; // 0-4 [CcPpFfTt]
      int dpl=sz(dp);
      rep(k,dpl){
        ll mag=1LL << ((3-k)*11);
        switch(dp[k]){
          case 'C': if (!c) c=-mag; break;
          case 'c': if (!c) c=mag; break;
          case 'P': if (!p) p=-mag; break;
          case 'p': if (!p) p=mag; break;
          case 'F': if (!f) f=-mag; break;
          case 'f': if (!f) f=mag; break;
          case 'T': if (!t) t=-mag; break;
          case 't': if (!t) t=mag; break;
        }
      }
      vector<pair<ll,int> > pt(m);
      rep(j,m){
        int calories=9*fat[j] + 5*(protein[j] + carbs[j]); // 1400 < 2048
        ll score = c*carbs[j] + p*protein[j] + f*fat[j] + t*calories;
        pt[j] = make_pair(score,j);
      }
      sort(all(pt));
      ans[i] = pt[0].second;
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
int verify_case(const vector <int> &Expected, const vector <int> &Received) { if (Expected == Received) cerr << "PASSED" << timer() << endl; else { cerr << "FAILED" << timer() << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } return 0;}

template<int N> struct Case_ {};
char Test_(...);
int Test_(Case_<0>) {
	timer_clear();
	int protein_[] = {3, 4};
	  vector <int> protein(protein_, protein_+sizeof(protein_)/sizeof(*protein_)); 
	int carbs_[] = {2, 8};
	  vector <int> carbs(carbs_, carbs_+sizeof(carbs_)/sizeof(*carbs_)); 
	int fat_[] = {5, 2};
	  vector <int> fat(fat_, fat_+sizeof(fat_)/sizeof(*fat_)); 
	string dietPlans_[] = {"P", "p", "C", "c", "F", "f", "T", "t"};
	  vector <string> dietPlans(dietPlans_, dietPlans_+sizeof(dietPlans_)/sizeof(*dietPlans_)); 
	int RetVal_[] = { 1,  0,  1,  0,  0,  1,  1,  0 };
	  vector <int> RetVal(RetVal_, RetVal_+sizeof(RetVal_)/sizeof(*RetVal_)); 
	return verify_case(RetVal, HealthFood().selectMeals(protein, carbs, fat, dietPlans)); }
int Test_(Case_<1>) {
	timer_clear();
	int protein_[] = {3, 4, 1, 5};
	  vector <int> protein(protein_, protein_+sizeof(protein_)/sizeof(*protein_)); 
	int carbs_[] = {2, 8, 5, 1};
	  vector <int> carbs(carbs_, carbs_+sizeof(carbs_)/sizeof(*carbs_)); 
	int fat_[] = {5, 2, 4, 4};
	  vector <int> fat(fat_, fat_+sizeof(fat_)/sizeof(*fat_)); 
	string dietPlans_[] = {"tFc", "tF", "Ftc"};
	  vector <string> dietPlans(dietPlans_, dietPlans_+sizeof(dietPlans_)/sizeof(*dietPlans_)); 
	int RetVal_[] = { 3,  2,  0 };
	  vector <int> RetVal(RetVal_, RetVal_+sizeof(RetVal_)/sizeof(*RetVal_)); 
	return verify_case(RetVal, HealthFood().selectMeals(protein, carbs, fat, dietPlans)); }
int Test_(Case_<2>) {
	timer_clear();
	int protein_[] = {18, 86, 76,  0, 34, 30, 95, 12, 21};
	  vector <int> protein(protein_, protein_+sizeof(protein_)/sizeof(*protein_)); 
	int carbs_[] = {26, 56,  3, 45, 88,  0, 10, 27, 53};
	  vector <int> carbs(carbs_, carbs_+sizeof(carbs_)/sizeof(*carbs_)); 
	int fat_[] = {93, 96, 13, 95, 98, 18, 59, 49, 86};
	  vector <int> fat(fat_, fat_+sizeof(fat_)/sizeof(*fat_)); 
	string dietPlans_[] = {"f", "Pt", "PT", "fT", "Cp", "C", "t", "",
 "cCp", "ttp", "PCFt", "P", "pCt", "cP", "Pc"}
;
	  vector <string> dietPlans(dietPlans_, dietPlans_+sizeof(dietPlans_)/sizeof(*dietPlans_)); 
	int RetVal_[] = { 2,  6,  6,  2,  4,  4,  5,  0,  5,  5,  6,  6,  3,  5,  6 };
	  vector <int> RetVal(RetVal_, RetVal_+sizeof(RetVal_)/sizeof(*RetVal_)); 
	return verify_case(RetVal, HealthFood().selectMeals(protein, carbs, fat, dietPlans)); }

template<int N> void Run_() { cerr << "Test Case #" << N << "..." << flush; Test_(Case_<N>()); Run_<sizeof(Test_(Case_<N+1>()))==1 ? -1 : N+1>(); }
template<>      void Run_<-1>() {}
int main() { Run_<0>(); }
// END CUT HERE


// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// Your favorite local restaurant has caught onto the health food trend, and has begun publishing basic nutritional information for all of their most popular menu selections.  This is excellent timing, since your doctor has recently recommended various diet plans for you and several of your friends.

You are given vector <int> protein, vector <int> carbs, and vector <int> fat, representing the number of grams of protein, carbs, and fat in each of the available menu items.  Elements from each vector <int> correspond to the elements of the other vector <int>s with the same index.

You are also given a vector <string> dietPlans, indicating the doctor's recommendation for how each person should make their meal selection.  Each element of dietPlans describes the diet plan for an individual.  Each character of each element of dietPlans specifies, in order of importance, a selection criteria, defined in the following way:

'C' = high carbs
'c' = low carbs
'P' = high protein
'p' = low protein
'F' = high fat
'f' = low fat
'T' = high calorie
't' = low calorie



As an example, the diet plan "tf" means the doctor recommends a meal with the lowest possible calories, and if more than one is tied, the one with less fat should be selected.  Whenever more than one meal is tied according to the diet plan, then the one with a lower index should be selected.

The restaurant sloppily neglected to list the total calorie count on the menu.  Fortunately, you happen to remember from days gone by that one gram of fat contains 9 calories, and one gram of carbs or protein contains 5 calories.

You are to return a vector <int> indicating the indexes of the menu selections that best suit each person's diet plan (indexed from 0).  The return vector <int> should have the same number of elements as dietPlans, and each value of the return vector <int> should correspond to the element of dietPlans with the same index.


DEFINITION
Class:HealthFood
Method:selectMeals
Parameters:vector <int>, vector <int>, vector <int>, vector <string>
Returns:vector <int>
Method signature:vector <int> selectMeals(vector <int> protein, vector <int> carbs, vector <int> fat, vector <string> dietPlans)


NOTES
-When no diet plan is specified, the default should be the menu selection with the lowest index (0).


CONSTRAINTS
-carbs will contain between 1 and 50 elements, inclusive
-protein will contain between 1 and 50 elements, inclusive
-fat will contain between 1 and 50 elements, inclusive.
-carbs, protein, and fat will each contain the same number of elements.
-Each element of carbs, protein, and fat will be between 0 and 100, inclusive.
-dietPlans will contain between 1 and 50 elements, inclusive.
-Each element of dietPlans will be between 0 and 4 characters in length, inclusive, and will contain only the characters "CcPpFfTt".


EXAMPLES

0)
{3, 4}
{2, 8}
{5, 2}
{"P", "p", "C", "c", "F", "f", "T", "t"}

Returns: { 1,  0,  1,  0,  0,  1,  1,  0 }

This is a simple menu, with only two selections.  We see each of the simplest diet plans here.

1)
{3, 4, 1, 5}
{2, 8, 5, 1}
{5, 2, 4, 4}
{"tFc", "tF", "Ftc"}

Returns: { 3,  2,  0 }

Note here that lowest total calories is tied between items 2 and 3.  Note also that both of those items are tied for fat content.  So, when we have lowest carbs as a tie-breaker, item 3 is selected.  When there is no further tiebreaker, we select the one with lowest index.  Note also that if highest fat is the first requirement, then the tiebreaker is irrelevant since item 0 has more fat than items 2 or 3.

2)
{18, 86, 76,  0, 34, 30, 95, 12, 21}
{26, 56,  3, 45, 88,  0, 10, 27, 53}
{93, 96, 13, 95, 98, 18, 59, 49, 86}
{"f", "Pt", "PT", "fT", "Cp", "C", "t", "",
 "cCp", "ttp", "PCFt", "P", "pCt", "cP", "Pc"}


Returns: { 2,  6,  6,  2,  4,  4,  5,  0,  5,  5,  6,  6,  3,  5,  6 }

*/
// END CUT HERE
