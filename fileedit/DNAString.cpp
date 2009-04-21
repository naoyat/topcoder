// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// A string of length L is called periodic with period p if the i-th character is equal to the (i+p)-th character for all i between 0 and L-p-1, inclusive.  For example, the strings "CATCATC", "CATCAT", "ACTAC" and "ACT" are all periodic with period 3.

You are given a vector <string> dna.  Concatenate the elements of dna and return the minimum number of replacements needed to make the resulting string periodic with period less than or equal to maxPeriod.  Each replacement consists of changing a single character from one letter to any other letter.

DEFINITION
Class:DNAString
Method:minChanges
Parameters:int, vector <string>
Returns:int
Method signature:int minChanges(int maxPeriod, vector <string> dna)


CONSTRAINTS
-dna will contain between 1 and 50 elements, inclusive.
-Each element of dna will contain between 1 and 50 characters, inclusive.
-Each character in dna will be 'A','C','G' or 'T'.
-maxPeriod will be between 1 and n, inclusive, where n is the number of characters in the concatenated string.


EXAMPLES

0)
3
{"ATAGATA"}

Returns: 1

Here, we only need one replacement to make the string periodic with period 2.  Replace the 'G' with a 'T': "ATATATA".


1)
2
{"ACGTGCA"}

Returns: 3

With 3 replacements we get the string ACACACA with period 2.

2)
13
{"ACGCTGACAGATA"}

Returns: 0

Here there is no need to change anything since our string already has period 13.

3)
1
{"AAAATTTCCG"}

Returns: 6

The best way to do this is to replace all non-'A' characters with 'A's.

4)
12
{"ACGTATAGCATGACA","ACAGATATTATG","ACAGATGTAGCAGTA","ACCA","GAC"}

Returns: 20



*/
// END CUT HERE

#line 70 "DNAString.cpp"
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

class DNAString {
public:
  int acgt(int ch) {
	switch(ch) {
	case 'A': return 0;
	case 'C': return 1;
	case 'G': return 2;
	case 'T': return 3;
	}
  }
  int minChanges(int maxPeriod, vector<string> dna) {//42937
	string dnac = ""; tr(dna,it) dnac += *it; int n=dnac.length();
	int minch = INT_MAX;
	for(int p=1;p<=maxPeriod;p++) {
	  vector<vector<int> > st(p);
	  int changes=0;
	  tr(st,it) { it->resize(4); fill(all(*it),0);}
	  rep(i,n) st[i%p][acgt(dnac[i])]++;
	  rep(i,p) {
		int maxc=0,totc=0;
		rep(j,4) {
		  totc+=st[i][j]; if(st[i][j]>maxc) maxc=st[i][j];
		}
		changes+=totc-maxc;
	  }
	  if (minch>changes)minch=changes;
	}
	return minch;
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
	int maxPeriod = 3; 
	string dna_[] = {"ATAGATA"};
	  vector <string> dna(dna_, dna_+sizeof(dna_)/sizeof(*dna_)); 
	int RetVal = 1; 
	return verify_case(RetVal, DNAString().minChanges(maxPeriod, dna)); }
int Test_(Case_<1>) {
	timer_clear();
	int maxPeriod = 2; 
	string dna_[] = {"ACGTGCA"};
	  vector <string> dna(dna_, dna_+sizeof(dna_)/sizeof(*dna_)); 
	int RetVal = 3; 
	return verify_case(RetVal, DNAString().minChanges(maxPeriod, dna)); }
int Test_(Case_<2>) {
	timer_clear();
	int maxPeriod = 13; 
	string dna_[] = {"ACGCTGACAGATA"};
	  vector <string> dna(dna_, dna_+sizeof(dna_)/sizeof(*dna_)); 
	int RetVal = 0; 
	return verify_case(RetVal, DNAString().minChanges(maxPeriod, dna)); }
int Test_(Case_<3>) {
	timer_clear();
	int maxPeriod = 1; 
	string dna_[] = {"AAAATTTCCG"};
	  vector <string> dna(dna_, dna_+sizeof(dna_)/sizeof(*dna_)); 
	int RetVal = 6; 
	return verify_case(RetVal, DNAString().minChanges(maxPeriod, dna)); }
int Test_(Case_<4>) {
	timer_clear();
	int maxPeriod = 12; 
	string dna_[] = {"ACGTATAGCATGACA","ACAGATATTATG","ACAGATGTAGCAGTA","ACCA","GAC"};
	  vector <string> dna(dna_, dna_+sizeof(dna_)/sizeof(*dna_)); 
	int RetVal = 20; 
	return verify_case(RetVal, DNAString().minChanges(maxPeriod, dna)); }

template<int N> void Run_() { cerr << "Test Case #" << N << "..." << flush; Test_(Case_<N>()); Run_<sizeof(Test_(Case_<N+1>()))==1 ? -1 : N+1>(); }
template<>      void Run_<-1>() {}
int main() { Run_<0>(); }
// END CUT HERE

