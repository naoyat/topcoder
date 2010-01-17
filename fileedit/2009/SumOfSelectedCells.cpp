#line 2 "SumOfSelectedCells.cpp"
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

vector<int> map_atoi(vector<string> nums)
{
  vector<int> vals(nums.size());
  for (int i=nums.size()-1; i>=0; i--) vals[i] = atoi(nums[i].c_str());
  return vals;
}
// BEGIN CUT HERE
long long c(int n, int r)
{
  if (n == 0 || r == 0 || r == n) return 1LL;
  if (r > n-r) r = n-r;
  return c(n-1,r-1) * n / r;
}

template <typename T>
  vector<vector<T> > combinations(const vector<T>& list, int r)
{
  int n = list.size();
  int nCr = c(n, r);
  vector<vector<T> > result(nCr);
  vector<int> curr(r); for (int i=0; i<r; i++) curr[i] = i;

  for (int idx=0; idx<nCr; idx++) {
	result[idx].resize(r);
	for (int i=0; i<r; i++) result[idx][i] = list[curr[i]];

	for (int i=r-1; i>=0; i--) {
	  if (curr[i] == n-(r-i)) {
		if (i == 0) return result;
		continue;
	  } else {
		int ofs = curr[i] - i + 1;
		for (int j=i; j<r; j++) curr[j] = j + ofs;
		break;
	  }
	}
  }
}
// END CUT HERE
class SumOfSelectedCells {
 public:
  string hypothesis(vector<string> table) {
    int h=sz(table);
    vector<vector<int> > t(h);
    rep(i,h) t[i]=map_atoi(split(table[i]));
    int w=sz(t[0]);
    //cout << "t:" << t << endl;
    if(w>h){
      vector<vector<int> > t_(w);
      rep(i,w) t_[i].resize(h);
      rep(i,w) rep(j,h) t_[i][j]=t[j][i];
      //cout << "t_:" << t_ << endl;
      t=t_;
      swap(w,h);
    }
    // w<=h

    map<int,int> memo;
    int mmax=1<<h;
    /*vector<vector<int> > pats(h+1);
    for(int i=0;i<mmax;i++)
    pats[__builtin_popcount(i)].pb(i);*/

    if(w==1){
      int z=t[0][0];
      for(int i=1;i<h;i++) if(z!=t[i][0]) goto incorrect;
      goto correct; //oops
    }
    if(h==2){
      if (t[0][0]+t[1][1] == t[1][0]+t[0][1])
        goto correct;
      else
        goto incorrect;
    }
    // nC2
    rep(x,h) {
      rep(i,h) {
        if(i==x) continue;
        rep(j,h) {
          if(j==x||i>=j) continue; //j>i
          int s_ij=t[i][0]+t[j][1],
              s_ji=t[j][0]+t[i][1];
          if(s_ij!=s_ji) goto incorrect;
          int m=(1<<i)|(1<<j);
          memo[m|(2<<h)]=s_ij;
        }
      }
    }
    if(w==2){
      if(h>w){
        int s=-1;
        tr(memo,it){
          int s_=it->second;
          if(s<0)s=s_;
          else if(s!=s_) goto incorrect;
        }
      }
      goto correct;
    }

    for(int d=3;d<=w;d++){
      //printf("d=%d\n",d);
      int b=d+(h-w);
      //tr(pats[b],it){
      //int m=*it;
      rep(m,mmax){
        if(__builtin_popcount(m)!=b) continue;
        int s=-1;
        rep(i,h){
          int x=1<<i;
          if((m&x)==0) continue;
          int m_=m-x;
          if(d==3 && b>3){
            //tr(pats[2],jt){
            //int m2=*jt;
            for(int m2=3;m2<mmax;m2++){
              if(__builtin_popcount(m2)!=2) continue;
              if((m_&m2)==m2){ m_=m2; break; }
            }
          }
          //printf("t[%d][%d]+memo[{%d,%d}]=...\n", i,d-1, m_,d-1);
          int s_=t[i][d-1]+memo[m_|((d-1)<<h)];
          if(s<0) s=s_;
          else if(s!=s_) goto incorrect;
        }
        memo[m|(d<<h)]=s;
      }
    }
    //cout << "memo:" << memo << endl;

 correct:
    return "CORRECT";
 incorrect:
    return "INCORRECT";
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
	string table_[] = {"5 6 6"};
    vector <string> table(table_, table_+sizeof(table_)/sizeof(*table_)); 
	string RetVal = "INCORRECT"; 
	return verify_case(RetVal, SumOfSelectedCells().hypothesis(table)); }
int Test_(Case_<1>) {
	timer_clear();
	string table_[] = {"11 12 13 14",
                       "21 22 23 24",
                       "31 32 33 34",
                       "41 42 43 44"};
    vector <string> table(table_, table_+sizeof(table_)/sizeof(*table_)); 
	string RetVal = "CORRECT"; 
	return verify_case(RetVal, SumOfSelectedCells().hypothesis(table)); }
int Test_(Case_<2>) {
	timer_clear();
	string table_[] = {"3 7",
                       "3 7",
                       "3 7"};
    vector <string> table(table_, table_+sizeof(table_)/sizeof(*table_)); 
	string RetVal = "CORRECT"; 
	return verify_case(RetVal, SumOfSelectedCells().hypothesis(table)); }
int Test_(Case_<3>) {
	timer_clear();
	string table_[] = {"1 2 3",
                       "4 5 6",
                       "9 8 7"};
    vector <string> table(table_, table_+sizeof(table_)/sizeof(*table_)); 
	string RetVal = "INCORRECT"; 
	return verify_case(RetVal, SumOfSelectedCells().hypothesis(table)); }
int Test_(Case_<4>) { // 19
	timer_clear();
	string table_[] = {"1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17",
                       "18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34"};
	  vector <string> table(table_, table_+sizeof(table_)/sizeof(*table_)); 
	string RetVal = "INCORRECT"; 
	return verify_case(RetVal, SumOfSelectedCells().hypothesis(table)); }
int Test_(Case_<5>) { // 21
	timer_clear();
	string table_[] = {"3 3 3 3 3 3 3 3 3 3 30 30 30 30 3 3 3 3",
                       "3 3 3 3 3 3 3 3 3 3 30 30 30 30 3 3 3 3"};
    vector <string> table(table_, table_+sizeof(table_)/sizeof(*table_)); 
	string RetVal = "INCORRECT"; 
	return verify_case(RetVal, SumOfSelectedCells().hypothesis(table)); }
int Test_(Case_<6>) { // 44
	timer_clear();
	string table_[] = {"23 24",
                       "24 23"};
    vector <string> table(table_, table_+sizeof(table_)/sizeof(*table_)); 
	string RetVal = "INCORRECT";
	return verify_case(RetVal, SumOfSelectedCells().hypothesis(table)); }
int Test_(Case_<7>) { // 6
	timer_clear();
	string table_[] = {"1 1"};
    vector <string> table(table_, table_+sizeof(table_)/sizeof(*table_)); 
	string RetVal = "CORRECT";
	return verify_case(RetVal, SumOfSelectedCells().hypothesis(table)); }
int Test_(Case_<8>) { // 37
	timer_clear();
	string table_[] = {"8 8 18 8 8 18 8 8 8 8 8 18 8 8 18 18 8 8 8 8",
                       "8 8 18 8 8 18 8 8 8 8 8 18 8 8 18 18 8 8 8 8",
                       "8 8 18 8 8 18 8 8 8 8 8 18 8 8 18 18 8 8 8 8",
                       "8 8 18 8 8 18 8 8 8 8 8 18 8 8 18 18 8 8 8 8",
                       "8 8 18 8 8 18 8 8 8 8 8 18 8 8 18 18 8 8 8 8",
                       "8 8 18 8 8 18 8 8 8 8 8 18 8 8 18 18 8 8 8 8",
                       "8 8 18 8 8 18 8 8 8 8 8 18 8 8 18 18 8 8 8 8",
                       "8 8 18 8 8 18 8 8 8 8 8 18 8 8 18 18 8 8 8 8",
                       "8 8 18 8 8 18 8 8 8 8 8 18 8 8 18 18 8 8 8 8",
                       "8 8 18 8 8 18 8 8 8 8 8 18 8 8 18 18 8 8 8 8",
                       "8 8 18 8 8 18 8 8 8 8 8 18 8 8 18 18 8 8 8 8",
                       "8 8 18 8 8 18 8 8 8 8 8 18 8 8 18 18 8 8 8 8",
                       "8 8 18 8 8 18 8 8 8 8 8 18 8 8 18 18 8 8 8 8",
                       "8 8 18 8 8 18 8 8 8 8 8 18 8 8 18 18 8 8 8 8",
                       "8 8 18 8 8 18 8 8 8 8 8 18 8 8 18 18 8 8 8 8",
                       "8 8 18 8 8 18 8 8 8 8 8 18 8 8 18 18 8 8 8 8",
                       "8 8 18 8 8 18 8 8 8 8 8 18 8 8 18 18 8 8 8 8",
                       "8 8 18 8 8 18 8 8 8 8 8 18 8 8 18 18 8 8 8 8",
                       "8 8 18 8 8 18 8 8 8 8 8 18 8 8 18 18 8 8 8 8",
                       "8 8 18 8 8 18 8 8 8 8 8 18 8 8 18 18 8 8 8 8"};
    vector <string> table(table_, table_+sizeof(table_)/sizeof(*table_)); 
	string RetVal = "CORRECT";
	return verify_case(RetVal, SumOfSelectedCells().hypothesis(table)); }


template<int N> void Run_() { cerr << "Test Case #" << N << "..." << flush; Test_(Case_<N>()); Run_<sizeof(Test_(Case_<N+1>()))==1 ? -1 : N+1>(); }
template<>      void Run_<-1>() {}
int main() { Run_<0>(); }
// END CUT HERE


// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// There is a rectangular table with an integer written in each cell.
Later, Jessie will come and select some cells in such a way that each row and each column contains no more than one selected cell. She will always select the maximum possible number of cells. However, there might be several possible selections of that size.
Larry suggested a hypothesis: "No matter what maximum selection Jessie choses, the sum of the numbers in the selected cells will always be the same."
Given a vector <string> table, check whether Larry's hypothesis is correct and return "CORRECT" or "INCORRECT" (quotes for clarity only).


DEFINITION
Class:SumOfSelectedCells
Method:hypothesis
Parameters:vector <string>
Returns:string
Method signature:string hypothesis(vector <string> table)


CONSTRAINTS
-table will contain between 1 and 20 elements, inclusive.
-Each element of table will be contain between 1 and 50 characters, inclusive.
-Each element of table will be a space-separated list of integers.
-Each element of table will contain the same number of entries.
-Each element of table will contain between 1 and 20 entries, inclusive.
-All numbers in the table will be between 1 and 50, inclusive, with no leading zeroes.


EXAMPLES

0)
{"5 6 6"}

Returns: "INCORRECT"

Jessie will select exactly one cell. The sum will be either 5 or 6.

1)
{"11 12 13 14",
 "21 22 23 24",
 "31 32 33 34",
 "41 42 43 44"}

Returns: "CORRECT"

There are 4! = 24 possible selections for Jessie, but it can be shown that each of them gives the sum of 1 + 2 + 3 + 4 + 10 + 20 + 30 + 40 = 110.

2)
{"3 7",
 "3 7",
 "3 7"}

Returns: "CORRECT"

Jessie will select exactly one 3 and exactly one 7 giving a total of 10.

3)
{"1 2 3",
 "4 5 6",
 "9 8 7"}

Returns: "INCORRECT"

Jessie can get 13 (2 + 4 + 7) or 15 (1 + 6 + 8) or 17 (3 + 5 + 9).

*/
// END CUT HERE
