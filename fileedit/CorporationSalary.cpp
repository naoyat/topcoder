// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// You are working in the HR department of a huge corporation. Each employee may have several direct managers and/or several direct subordinates. Of course, his subordinates may also have their own subordinates, and his direct managers may have their own managers. We say employee X is a boss of employee Y if there exists a sequence of employees A, B, ..., D, such that X is the manager of A, A is the manager of B, and so on, and D is the manager of Y (of course, if X is a direct manager of employee Y, X will be a boss of employee Y). If A is a boss of B, then B can not be a boss of A. According to the new company policy, the salary of an employee with no subordinates is 1. If an employee has any subordinates, then his salary is equal to the sum of the salaries of his direct subordinates.

You will be given a vector <string> relations, where the j-th character of the i-th element is 'Y' if employee i is a direct manager of employee j, and 'N' otherwise. Return the sum of the salaries of all the employees.

DEFINITION
Class:CorporationSalary
Method:totalSalary
Parameters:vector <string>
Returns:long long
Method signature:long long totalSalary(vector <string> relations)


CONSTRAINTS
-relations will contain between 1 and 50 elements, inclusive. 
-Each element of relations will contain the same number of characters, which is equal to number of elements in relations.
-Each element of relations will contain only 'Y' or 'N'.
-Character i of element i of relations will be 'N' for each i. 
-If A is a boss of B, then B will not be a boss of A.

EXAMPLES

0)
{"N"}

Returns: 1

Here we've got only one employee so the answer is 1.

1)
{"NNYN",
 "NNYN",
 "NNNN",
 "NYYN"}

Returns: 5

There are 4 employees here. 0, 1 and 3 are managers of 2, and also 3 is a manager of 1. So:
salary(2) = 1 
salary(0) = salary(2) = 1
salary(1) = salary(2) = 1 
salary(3) = salary(2) + salary(1) = 2

2)
{"NNNNNN",
 "YNYNNY",
 "YNNNNY",
 "NNNNNN",
 "YNYNNN",
 "YNNYNN"}

Returns: 17


3)
{"NYNNYN",
 "NNNNNN",
 "NNNNNN",
 "NNYNNN",
 "NNNNNN",
 "NNNYYN"}

Returns: 8



4)
{"NNNN",
 "NNNN",
 "NNNN",
 "NNNN"}

Returns: 4



*/
// END CUT HERE

#line 85 "CorporationSalary.cpp"
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
#define rep(var,n)  for(int var=0;var<(n);var++)

//
class CorporationSalary {
  int N;
  vector<long long> salary;
  vector<vector<bool> > t;

  long long decide_salary(int id){
	if (salary[id] > 0) return salary[id];
	long long s=0LL;
	rep(j,N){
	  if(t[id][j]) s+=decide_salary(j);
	}
	if (s==0LL) s=1LL;
	return salary[id] = s;
  }
public:
  long long totalSalary(vector<string> relations) {
	N = relations.size();//1-50

	t.resize(N); tr(t,it) it->resize(N);
	rep(i,N) rep(j,N) t[i][j]=(relations[i][j]=='Y');

	salary.resize(N); tr(salary,it) *it=0;

	long long total=0LL;
	rep(i,N) total+=decide_salary(i);
	return total;
  }
};

// BEGIN CUT HERE
#include <time.h>
clock_t start_time;
void timer_clear() { start_time = clock(); }
string timer() { clock_t end_time = clock(); double interval = (double)(end_time - start_time)/CLOCKS_PER_SEC; ostringstream os; os << " (" << interval*1000 << " msec)"; return os.str(); }

template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
int verify_case(const long long &Expected, const long long &Received) { if (Expected == Received) cerr << "PASSED" << timer() << endl; else { cerr << "FAILED" << timer() << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } return 0;}

template<int N> struct Case_ {};
char Test_(...);
int Test_(Case_<0>) {
	timer_clear();
	string relations_[] = {"N"};
	  vector <string> relations(relations_, relations_+sizeof(relations_)/sizeof(*relations_)); 
	long long RetVal = 1LL; 
	return verify_case(RetVal, CorporationSalary().totalSalary(relations)); }
int Test_(Case_<1>) {
	timer_clear();
	string relations_[] = {"NNYN",
 "NNYN",
 "NNNN",
 "NYYN"};
	  vector <string> relations(relations_, relations_+sizeof(relations_)/sizeof(*relations_)); 
	long long RetVal = 5LL; 
	return verify_case(RetVal, CorporationSalary().totalSalary(relations)); }
int Test_(Case_<2>) {
	timer_clear();
	string relations_[] = {"NNNNNN",
 "YNYNNY",
 "YNNNNY",
 "NNNNNN",
 "YNYNNN",
 "YNNYNN"};
	  vector <string> relations(relations_, relations_+sizeof(relations_)/sizeof(*relations_)); 
	long long RetVal = 17LL; 
	return verify_case(RetVal, CorporationSalary().totalSalary(relations)); }
int Test_(Case_<3>) {
	timer_clear();
	string relations_[] = {"NYNNYN",
 "NNNNNN",
 "NNNNNN",
 "NNYNNN",
 "NNNNNN",
 "NNNYYN"};
	  vector <string> relations(relations_, relations_+sizeof(relations_)/sizeof(*relations_)); 
	long long RetVal = 8LL; 
	return verify_case(RetVal, CorporationSalary().totalSalary(relations)); }
int Test_(Case_<4>) {
	timer_clear();
	string relations_[] = {"NNNN",
 "NNNN",
 "NNNN",
 "NNNN"};
	  vector <string> relations(relations_, relations_+sizeof(relations_)/sizeof(*relations_)); 
	long long RetVal = 4LL; 
	return verify_case(RetVal, CorporationSalary().totalSalary(relations)); }

template<int N> void Run_() { cerr << "Test Case #" << N << "..." << flush; Test_(Case_<N>()); Run_<sizeof(Test_(Case_<N+1>()))==1 ? -1 : N+1>(); }
template<>      void Run_<-1>() {}
int main() { Run_<0>(); }
// END CUT HERE

