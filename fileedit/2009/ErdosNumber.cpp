#line 2 "ErdosNumber.cpp"
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

class ErdosNumber {
 public:
  vector<string> calculateNumbers(vector<string> publications) {
// BEGIN CUT HERE
    //    cout << "IN " << publications;
// END CUT HERE
	int n=sz(publications);
    vector<string> res;
    vector<pair<string,string> > ps;
    set<pair<string,string> > pss;
    map<string,int> erdos;
    set<string> as;
    erdos["ERDOS"] = 0;
    rep(i,n){
      vector<string> authors=split(publications[i]);
      int m=sz(authors);
      rep(j,m){
        string a=authors[j];
        if (!found(erdos,a)) as.insert(a);
        rep(k,m){
          if(j!=k) {
            pair<string,string> jk=make_pair(authors[k],a);
            if(!found(pss,jk)) { ps.pb(jk); pss.insert(jk); }
          }
        }
      }
    }
// BEGIN CUT HERE
    //    cout << "ps:"<< ps << endl;
// END CUT HERE
    int pn = sz(ps);
    for(int en=0;;en++){
// BEGIN CUT HERE
      //      cout << "as:" << as << endl;
// END CUT HERE
      bool f=false;
      map<string,int> news;
      rep(i,pn){
        string a=ps[i].first; if(sz(a)==0) continue;
        string b=ps[i].second;
// BEGIN CUT HERE
        //        cout << ":: " << a << " " << b << endl;
// END CUT HERE
        if(found(erdos,a)) {
// BEGIN CUT HERE
          //          cout << "  ::found(" << a << "=" << erdos[a] << ") with " << b << endl;
// END CUT HERE
          if (!found(erdos,b)) {
            news[b] = en+1;
            f=true;
            as.erase(b);
          }
          ps[i].first = "";
        }
      }
      if (f){
        tr(news,it){
          erdos[it->first] = it->second;
        }
      }
      if (!f) break;
    }
// BEGIN CUT HERE
    //    cout << "erdos:" << erdos << endl;
// END CUT HERE
    vector<string> ans;
    tr(erdos,it){
      stringstream ss;
      ss << it->first << " " << it->second;
      ans.pb(ss.str());
    }
    tr(as,it){
      ans.pb(*it);
    }
    sort(all(ans));
    return ans;
  }
};

// BEGIN CUT HERE
#include <time.h>
clock_t start_time;
void timer_clear() { start_time = clock(); }
string timer() { clock_t end_time = clock(); double interval = (double)(end_time - start_time)/CLOCKS_PER_SEC; ostringstream os; os << " (" << interval*1000 << " msec)"; return os.str(); }

template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
int verify_case(const vector <string> &Expected, const vector <string> &Received) { if (Expected == Received) cerr << "PASSED" << timer() << endl; else { cerr << "FAILED" << timer() << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } return 0;}

template<int N> struct Case_ {};
char Test_(...);
int Test_(Case_<0>) {
	timer_clear();
	string publications_[] = {"ERDOS"};
	  vector <string> publications(publications_, publications_+sizeof(publications_)/sizeof(*publications_)); 
	string RetVal_[] = {"ERDOS 0" };
	  vector <string> RetVal(RetVal_, RetVal_+sizeof(RetVal_)/sizeof(*RetVal_)); 
	return verify_case(RetVal, ErdosNumber().calculateNumbers(publications)); }
int Test_(Case_<1>) {
	timer_clear();
	string publications_[] = {"KLEITMAN LANDER", "ERDOS KLEITMAN"};
	  vector <string> publications(publications_, publications_+sizeof(publications_)/sizeof(*publications_)); 
	string RetVal_[] = {"ERDOS 0", "KLEITMAN 1", "LANDER 2" };
	  vector <string> RetVal(RetVal_, RetVal_+sizeof(RetVal_)/sizeof(*RetVal_)); 
	return verify_case(RetVal, ErdosNumber().calculateNumbers(publications)); }
int Test_(Case_<2>) {
	timer_clear();
	string publications_[] = {"ERDOS A", "A B", "B AA C"};
	  vector <string> publications(publications_, publications_+sizeof(publications_)/sizeof(*publications_)); 
	string RetVal_[] = {"A 1", "AA 3", "B 2", "C 3", "ERDOS 0" };
	  vector <string> RetVal(RetVal_, RetVal_+sizeof(RetVal_)/sizeof(*RetVal_)); 
	return verify_case(RetVal, ErdosNumber().calculateNumbers(publications)); }
int Test_(Case_<3>) {
	timer_clear();
	string publications_[] = {"ERDOS B", "A B C", "B A E", "D F"};
	  vector <string> publications(publications_, publications_+sizeof(publications_)/sizeof(*publications_)); 
	string RetVal_[] = {"A 2", "B 1", "C 2", "D", "E 2", "ERDOS 0", "F" };
	  vector <string> RetVal(RetVal_, RetVal_+sizeof(RetVal_)/sizeof(*RetVal_)); 
	return verify_case(RetVal, ErdosNumber().calculateNumbers(publications)); }
int Test_(Case_<4>) {
	timer_clear();
	string publications_[] = {"ERDOS KLEITMAN", "CHUNG GODDARD KLEITMAN WAYNE", "WAYNE GODDARD KLEITMAN", 
 "ALON KLEITMAN", "DEAN GODDARD WAYNE KLEITMAN STURTEVANT"};
	  vector <string> publications(publications_, publications_+sizeof(publications_)/sizeof(*publications_)); 
	string RetVal_[] = {"ALON 2", "CHUNG 2", "DEAN 2", "ERDOS 0", "GODDARD 2", "KLEITMAN 1", "STURTEVANT 2", "WAYNE 2" };
	  vector <string> RetVal(RetVal_, RetVal_+sizeof(RetVal_)/sizeof(*RetVal_)); 
	return verify_case(RetVal, ErdosNumber().calculateNumbers(publications)); }

template<int N> void Run_() { cerr << "Test Case #" << N << "..." << flush; Test_(Case_<N>()); Run_<sizeof(Test_(Case_<N+1>()))==1 ? -1 : N+1>(); }
template<>      void Run_<-1>() {}
int main() { Run_<0>(); }
// END CUT HERE


// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// The Erdos number is a way of describing the "collaborative distance" between a scientist and Paul Erdos
by authorship of scientific publications.

Paul Erdos is the only person who has an Erdos number equal to zero.
To be assigned a finite Erdos number, a scientist must publish a paper in co-authorship
with a scientist with a finite Erdos number. The Erdos number of a scientist is the lowest
Erdos number of his coauthors + 1.
The order of publications and numbers assignment doesn't matter, i.e., after each publication 
the list of assigned numbers is updated accordingly.

You will be given a vector <string> publications, each element of which describes 
the list of authors of a single publication and is formatted as "AUTHOR_1 AUTHOR_2 ... AUTHOR_N"
(quotes for clarity only). Paul Erdos will be given as "ERDOS".

Return the list of Erdos numbers which will be assigned to the authors of the listed publications.
Each element of your return should be formatted as "AUTHOR NUMBER" if AUTHOR can be assigned
a finite Erdos number, and just "AUTHOR" otherwise. 
The authors in your return must be ordered lexicographically.

DEFINITION
Class:ErdosNumber
Method:calculateNumbers
Parameters:vector <string>
Returns:vector <string>
Method signature:vector <string> calculateNumbers(vector <string> publications)


NOTES
-All authors mentioned in the list must be present in your return.
-Assume that all publications of mentioned authors are given in publications.
-String S is lexicographically before string T if S is a proper prefix of T, or if S has an earlier character at the first position where the strings differ.


CONSTRAINTS
-publications will contain between 1 and 50 elements, inclusive.
-Each element of publications will contain between 1 and 50 characters, inclusive.
-An author is a string of between 1 and 50 uppercase letters ('A'-'Z'), inclusive.
-Each element of publications will be a list of authors, separated by single spaces.
-The authors in each element of publication will be distinct.
-There will be at most 100 distinct authors in all publications.
-Paul Erdos will be given as "ERDOS", and at least one publication will list him as one of the authors.


EXAMPLES

0)
{"ERDOS"}

Returns: {"ERDOS 0" }

The only author is Erdos himself, with Erdos number equal to 0.

1)
{"KLEITMAN LANDER", "ERDOS KLEITMAN"}

Returns: {"ERDOS 0", "KLEITMAN 1", "LANDER 2" }

publications[1] defines Kleitman's number as 1, and publications[0] defines Lander's number as 2.

2)
{"ERDOS A", "A B", "B AA C"}

Returns: {"A 1", "AA 3", "B 2", "C 3", "ERDOS 0" }



3)
{"ERDOS B", "A B C", "B A E", "D F"}

Returns: {"A 2", "B 1", "C 2", "D", "E 2", "ERDOS 0", "F" }

E has coauthors B (Erdos number 1) and A (Erdos number 2), so his Erdos number is defined through the coauthor with the lowest Erdos number. D and F aren't connected to Erdos and thus have no numbers assigned.

4)
{"ERDOS KLEITMAN", "CHUNG GODDARD KLEITMAN WAYNE", "WAYNE GODDARD KLEITMAN", 
 "ALON KLEITMAN", "DEAN GODDARD WAYNE KLEITMAN STURTEVANT"}

Returns: {"ALON 2", "CHUNG 2", "DEAN 2", "ERDOS 0", "GODDARD 2", "KLEITMAN 1", "STURTEVANT 2", "WAYNE 2" }



*/
// END CUT HERE
