// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// You've just qualified for the on-site round of a major coding tournament! You now need to sort out a visa to allow you to travel to the event. You know that this is likely to be a long process, but are determined to sort it out as quickly as possible, even if it means working day and night. The process involves filling out a series of forms, which then have to be approved by the embassy. When the last form is approved your visa is granted. The approval process is very quick (instantaneous for the purpose of this problem), but there is a catch: each form has to be approved by the embassy before they will give you the next form to fill out. The embassy opens at exactly the same time each day and remains open for openTime time units. By the non-standard embassy clocks, a day is dayLength time units long, so the embassy then remains closed for dayLength - openTime time units before it opens the next day. Forms can be approved at any point in time between the time that the embassy opens and the time it closes, inclusive. However, if you finish filling in a form when the embassy is closed, you have to wait until it opens again before the form can be approved. The length of time it takes you to fill out form i is forms[i] units and the forms must be completed in the order they are given in forms. You already have the first form in your possession and can start filling it out at any time. Return the minimum length of time between starting to fill out the first form and getting your visa granted.

DEFINITION
Class:Embassy
Method:visaApplication
Parameters:vector <int>, int, int
Returns:int
Method signature:int visaApplication(vector <int> forms, int dayLength, int openTime)


CONSTRAINTS
-forms will contain between 1 and 50 elements, inclusive.
-Each element of forms will be between 1 and 1,000,000 (10^6), inclusive.
-dayLength will be between 1 and 1,000,000 (10^6), inclusive.
-openTime will be between 1 and dayLength, inclusive.


EXAMPLES

0)
{4,4,4}
24
8

Returns: 12

The embassy is open for 8 hours out of a 24 hour day. Each of the three forms takes 4 hours to fill in. If you start filling in the first form 4 hours before the embassy opens, you can get it approved just as the embassy opens. The embassy will still be open 4 hours later to approve the second form and the third form can be approved just as the embassy shuts. Since you never have to wait, the total time is 12 hours.

1)
{4,4,4,4}
24
8

Returns: 28

Now there is an additional form to fill in. You can't complete the process in a single day.

2)
{2,2,2,2}
24
1

Returns: 73

The embassy is only open for one hour each day, so you can only get one form approved per day.

3)
{25,500,630,2500,1000,350,22,58,100,400,500,5000}
1440
360

Returns: 16945

Time is now measured in minutes. It/s optimal to start filling in the first form 335 minutes after the embassy first opens.

*/
// END CUT HERE

#line 63 "Embassy.cpp"
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

class Embassy {
public:
  int visaApplication(vector<int> forms, int dayLength, int openTime) {
	int N = forms.size();//1-50
	// forms[i] : 1 - 1000000
	// dayLength : 1 - 1000000
	// openTime : 1 - dayLength
	int closeTime = dayLength - openTime;
	cout << "forms: " << forms << ", dayLength: " << dayLength << ", openTime: " << openTime << ", closeTime: " << closeTime << endl;

	// 初日
	int total=forms[0], sum=0, till = 0;
	for (int i=1; i<N; i++) {
	  if (sum + forms[i] <= openTime) {
		sum += forms[i]; till++;
	  }
	  else break;
	}
	total += sum;

	cout << "#0 の開始時刻は初日の終わりから " << total << " 時間前 " << endl;
	cout << "#0 をやって、初日は次の " << till << " 枚を " << sum << " 時間で " << endl;
	if (till == N-1) return total;
	  
	while (till < N) {
	  //初日の夜 - ２日目
	  int days = forms[till] / dayLength, rem = forms[till] % dayLength;
	  if (rem < closeTime) rem = closeTime;
	  
	  cout << "#" << till << " は " << days << " 日と " << rem << " 時間 " << endl;
	  total += days * dayLength + rem;

	  till++;
	}

	return total;
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
	int forms_[] = {4,4,4};
	  vector <int> forms(forms_, forms_+sizeof(forms_)/sizeof(*forms_)); 
	int dayLength = 24; 
	int openTime = 8; 
	int RetVal = 12; 
	return verify_case(RetVal, Embassy().visaApplication(forms, dayLength, openTime)); }
int Test_(Case_<1>) {
	timer_clear();
	int forms_[] = {4,4,4,4};
	  vector <int> forms(forms_, forms_+sizeof(forms_)/sizeof(*forms_)); 
	int dayLength = 24; 
	int openTime = 8; 
	int RetVal = 28; 
	return verify_case(RetVal, Embassy().visaApplication(forms, dayLength, openTime)); }
int Test_(Case_<2>) {
	timer_clear();
	int forms_[] = {2,2,2,2};
	  vector <int> forms(forms_, forms_+sizeof(forms_)/sizeof(*forms_)); 
	int dayLength = 24; 
	int openTime = 1; 
	int RetVal = 73; 
	return verify_case(RetVal, Embassy().visaApplication(forms, dayLength, openTime)); }
int Test_(Case_<3>) {
	timer_clear();
	int forms_[] = {25,500,630,2500,1000,350,22,58,100,400,500,5000};
	  vector <int> forms(forms_, forms_+sizeof(forms_)/sizeof(*forms_)); 
	int dayLength = 1440; 
	int openTime = 360; 
	int RetVal = 16945; 
	return verify_case(RetVal, Embassy().visaApplication(forms, dayLength, openTime)); }

template<int N> void Run_() { cerr << "Test Case #" << N << "..." << flush; Test_(Case_<N>()); Run_<sizeof(Test_(Case_<N+1>()))==1 ? -1 : N+1>(); }
template<>      void Run_<-1>() {}
int main() { Run_<0>(); }
// END CUT HERE

