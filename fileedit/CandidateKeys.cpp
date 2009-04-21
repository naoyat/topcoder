// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// A database table consists of a set of columns called attributes, and a set of rows called entries.  A superkey is a set of attributes such that each entry's values for those attributes forms a unique ordered set. That is, for any superkey, each pair of entries differs in at least one of the attributes contained within the superkey.  A candidate superkey is a superkey such that no proper subset of its attributes forms a superkey.

Return a vector <int> with exactly two elements.  The first element should be the number of attributes in the smallest candidate superkey of the table, and the second element should be the number of attributes in the largest candidate superkey of the table.  If there is no valid candidate superkey, return an empty vector <int> instead.

The input is described by a vector <string> table.  Each string in table represents one entry, while characters contained in the string are attribute values for that entry.

DEFINITION
Class:CandidateKeys
Method:getKeys
Parameters:vector <string>
Returns:vector <int>
Method signature:vector <int> getKeys(vector <string> table)


NOTES
-A proper subset of a superkey is a set of attributes that is formed by removing one or more attributes from the superkey.


CONSTRAINTS
-table will contain between 2 and 50 elements, inclusive.
-Each element of table will contain between 1 and 10 characters, inclusive.
-Each element of table will contain the same number of characters.
-Each character in table will be an uppercase letter ('A'-'Z').


EXAMPLES

0)
{
"ABC",
"ABC",
"ABC"
}

Returns: { }

Since all entries are the same, there is no set of attributes that can differentiate between them.  Therefore, this table has no candidate superkeys.

1)
{
"ABC",
"ABD",
"ABE"
}

Returns: {1, 1 }

There are four superkeys here:
{column 0, column 1, column 2}
{column 0, column 2}
{column 1, column 2}
{column 2}

Note that the fourth superkey is a subset of all the other superkeys, so it is the only candidate superkey.


2)
{
"ABC",
"ACD",
"BBE"
}

Returns: {1, 2 }



3)
{"A","B"}

Returns: {1, 1 }



4)
{
"AABB",
"BABA",
"CAAB",
"DAAA",
"EBBB",
"FBBA",
"GBAB",
"HBAA"
}

Returns: {1, 3 }



*/
// END CUT HERE

#line 98 "CandidateKeys.cpp"
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
#define found(s,e)  ((s).find(e)!=(s).end())
#define remove_(c,val) (c).erase(remove((c).begin(),(c).end(),(val)),(c).end())

class CandidateKeys {
  string mask(string orig, int m){
    //printf("mask(%s, %d)", orig.c_str(), m);
    char buf[11];
    int j=0;
    rep(i,orig.length()) {
      if (m==0) break;
      if (m&1) buf[j++] = orig[i];
      m/=2;
    }
    buf[j]=0;
    //printf(" => %s\n", buf);
    string s = buf;
    return s;
  }
 public:
  vector<int> getKeys(vector<string> table) {
    vector<int> ans;
    int smallest=INT_MAX, largest=0;

    int l=table[0].length();
    set<string> ts(all(table));
    int n=sz(ts); // <2-50, 1-10
    if (n==1) return ans;

    vector<int> superkeys;
    set<int> candidate_keys;
    //map<int,int> superkeys;
    int pmax = (1<<l)-1;
    for (int p=1;p<=pmax;p++) {
      set<string> s;
      tr(ts,it){
        s.insert(mask(*it,p));
      }
      if (sz(s)==sz(ts)) superkeys.pb(p);
    }
    cout << "superkeys: " << superkeys << endl;
    for(int i=0,c=sz(superkeys); i<c; i++) {
      int pi=superkeys[i];
      int cnt=0;
      for(int j=0; j<i; j++) {
        if (i==j) continue;
        int pj=superkeys[j];
        /*
        printf("if (%d & %d) = %d == %d : %s\n", pi,pj,pi&pj, pj,
               ((pi&pj) == pj)? "yes": "no");
        */
        if ((pi & pj) == pj) cnt++;
      }
      if (cnt==0) candidate_keys.insert(__builtin_popcount(pi));
    }
    if (sz(candidate_keys)==0) return ans;

    tr(candidate_keys,it){
      if(*it <smallest) smallest=*it;
      if(*it >largest) largest=*it;
    }
    //    cout << candidate_keys << endl;
    //return ans;
    ans.pb(smallest); ans.pb(largest); return ans;
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
	string table_[] = {
"ABC",
"ABC",
"ABC"
};
	  vector <string> table(table_, table_+sizeof(table_)/sizeof(*table_)); 
	vector <int> RetVal; 
	return verify_case(RetVal, CandidateKeys().getKeys(table)); }
int Test_(Case_<1>) {
	timer_clear();
	string table_[] = {
"ABC",
"ABD",
"ABE"
};
	  vector <string> table(table_, table_+sizeof(table_)/sizeof(*table_)); 
	int RetVal_[] = {1, 1 };
	  vector <int> RetVal(RetVal_, RetVal_+sizeof(RetVal_)/sizeof(*RetVal_)); 
	return verify_case(RetVal, CandidateKeys().getKeys(table)); }
int Test_(Case_<2>) {
	timer_clear();
	string table_[] = {
"ABC",
"ACD",
"BBE"
};
	  vector <string> table(table_, table_+sizeof(table_)/sizeof(*table_)); 
	int RetVal_[] = {1, 2 };
	  vector <int> RetVal(RetVal_, RetVal_+sizeof(RetVal_)/sizeof(*RetVal_)); 
	return verify_case(RetVal, CandidateKeys().getKeys(table)); }
int Test_(Case_<3>) {
	timer_clear();
	string table_[] = {"A","B"};
	  vector <string> table(table_, table_+sizeof(table_)/sizeof(*table_)); 
	int RetVal_[] = {1, 1 };
	  vector <int> RetVal(RetVal_, RetVal_+sizeof(RetVal_)/sizeof(*RetVal_)); 
	return verify_case(RetVal, CandidateKeys().getKeys(table)); }
int Test_(Case_<4>) {
	timer_clear();
	string table_[] = {
"AABB",
"BABA",
"CAAB",
"DAAA",
"EBBB",
"FBBA",
"GBAB",
"HBAA"
};
	  vector <string> table(table_, table_+sizeof(table_)/sizeof(*table_)); 
	int RetVal_[] = {1, 3 };
	  vector <int> RetVal(RetVal_, RetVal_+sizeof(RetVal_)/sizeof(*RetVal_)); 
	return verify_case(RetVal, CandidateKeys().getKeys(table)); }
int Test_(Case_<5>) {
	timer_clear();
	string table_[] = {
      "AABAA", "ABABA", "ABBAA", "BBBAA", "BBBAB", "ABBBB", "BBBAA", "AAABB" };
	  vector <string> table(table_, table_+sizeof(table_)/sizeof(*table_)); 
	int RetVal_[] = {};
	  vector <int> RetVal(RetVal_, RetVal_+sizeof(RetVal_)/sizeof(*RetVal_)); 
	return verify_case(RetVal, CandidateKeys().getKeys(table)); }

template<int N> void Run_() { cerr << "Test Case #" << N << "..." << flush; Test_(Case_<N>()); Run_<sizeof(Test_(Case_<N+1>()))==1 ? -1 : N+1>(); }
template<>      void Run_<-1>() {}
int main() { Run_<0>(); }
// END CUT HERE

