#line 2 "WeirdRooks.cpp"
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

#define rep_(var,n)  for(int var=-1;var<(n);var++)

string join(vector<string> strs, const string &delim="")
{
  int n=strs.size(); if (n==0) return "";
  stringstream ss;
  ss << strs[0];
  for(int i=1;i<n;i++) { ss << delim << strs[i]; }
  return ss.str();
}

class WeirdRooks {
 public:
  string describe(vector<int> cols) {
    //cout << "cols=" << cols << endl;
    set<pair<int,int> > ans;
    int R=sz(cols); //1-8
    int W=*max_element(all(cols));

    int M=0; rep(i,R) M+=cols[i];
    // ans.insert(make_pair(0,M));
    set<pair<int,vector<int> > > pat;
    int k=0;
    vector<int> m(W,-1);
    rep_(i0,cols[0]){
      if(i0>=0){
        k++; m[i0]=0;
      }
      if(R>=2) rep_(i1,cols[1]){
          if(i1>=0){
            if(m[i1]>=0) continue;
            k++; m[i1]=1;
          }
          if(R>=3) rep_(i2,cols[2]){
              if(i2>=0){
                if(m[i2]>=0) continue;
                k++; m[i2]=2;
              }
              if(R>=4) rep_(i3,cols[3]){
                  if(i3>=0){
                    if(m[i3]>=0) continue;
                    k++; m[i3]=3;
                  }
                  if(R>=5) rep_(i4,cols[4]){
                      if(i4>=0){
                        if(m[i4]>=0) continue;
                        k++; m[i4]=4;
                      }
                      if(R>=6) rep_(i5,cols[5]){
                          if(i5>=0){
                            if(m[i5]>=0) continue;
                            k++; m[i5]=5;
                          }
                          if(R>=7) rep_(i6,cols[6]){
                              if(i6>=0){
                                if(m[i6]>=0) continue;
                                k++; m[i6]=6;
                              }
                              if(R==8) rep_(i7,cols[7]){
                                  if(i7>=0){
                                    if(m[i7]>=0) continue;
                                    k++; m[i7]=7;
                                  }
                                  if(R==8) pat.insert(make_pair(k,m));
                                  if(i7>=0){ k--; m[i7]=-1; }
                                }//7
                              if(R==7) pat.insert(make_pair(k,m));
                              if(i6>=0){ k--; m[i6]=-1; }
                            }//6
                          if (R==6) pat.insert(make_pair(k,m));
                          if(i5>=0){ k--; m[i5]=-1; }
                        }//5
                      if (R==5) pat.insert(make_pair(k,m));
                      if(i4>=0){ k--; m[i4]=-1; }
                    }//4
                  if (R==4) pat.insert(make_pair(k,m));
                  if(i3>=0){ k--; m[i3]=-1; }
                }//3
              if (R==3) pat.insert(make_pair(k,m));
              if(i2>=0){ k--; m[i2]=-1; }
            }//2
          if (R==2) pat.insert(make_pair(k,m));
          if(i1>=0){ k--; m[i1]=-1; }
        }//1
      if (R==1) pat.insert(make_pair(k,m));
      if(i0>=0){ k--; m[i0]=-1; }
    }//0

    tr(pat,it){
      int k=it->first;
      vector<int> m=it->second;
      vector<vector<bool> > sp(R,vector<bool>(W,false));
      rep(r,R) rep(c,cols[r]) sp[r][c]=true;
      rep(c,W){
        if(m[c]>=0) { // (c,m[i])
          int r=m[c];
          for(int j=0;j<=c;j++) sp[r][j]=false;
          for(int j=0;j<=r;j++) sp[j][c]=false;
        }
      }
      int sc=0;
      rep(r,R) rep(c,cols[r]) if(sp[r][c])sc++;
      ans.insert(make_pair(k,sc));
    }
    
    vector<string> vs;
    tr(ans,it){
      char buf[6]; sprintf(buf,"%d,%d",it->first,it->second); vs.pb(buf);
    }
    return join(vs," ");
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
	int cols_[] = {3,3,3};
	  vector <int> cols(cols_, cols_+sizeof(cols_)/sizeof(*cols_)); 
	string RetVal = "0,9 1,4 1,5 1,6 1,7 1,8 2,1 2,2 2,3 2,4 2,5 2,6 3,0 3,1 3,2 3,3"; 
	return verify_case(RetVal, WeirdRooks().describe(cols)); }
int Test_(Case_<1>) {
	timer_clear();
	int cols_[] = {1,2,3};
	  vector <int> cols(cols_, cols_+sizeof(cols_)/sizeof(*cols_)); 
	string RetVal = "0,6 1,3 1,4 1,5 2,1 2,2 2,3 3,0"; 
	return verify_case(RetVal, WeirdRooks().describe(cols)); }
int Test_(Case_<2>) {
	timer_clear();
	int cols_[] = {1};
	  vector <int> cols(cols_, cols_+sizeof(cols_)/sizeof(*cols_)); 
	string RetVal = "0,1 1,0"; 
	return verify_case(RetVal, WeirdRooks().describe(cols)); }
int Test_(Case_<3>) {
	timer_clear();
	int cols_[] = {2,9};
	  vector <int> cols(cols_, cols_+sizeof(cols_)/sizeof(*cols_)); 
	string RetVal = "0,11 1,2 1,3 1,4 1,5 1,6 1,7 1,8 1,9 1,10 2,0 2,1 2,2 2,3 2,4 2,5 2,6 2,7 2,8"; 
	return verify_case(RetVal, WeirdRooks().describe(cols)); }

template<int N> void Run_() { cerr << "Test Case #" << N << "..." << flush; Test_(Case_<N>()); Run_<sizeof(Test_(Case_<N+1>()))==1 ? -1 : N+1>(); }
template<>      void Run_<-1>() {}
int main() { Run_<0>(); }
// END CUT HERE


// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// On a weird chess board, each row can have a different number of columns.  Element k of cols will give the number of columns in row k.  Each row is flush left, so the right side can look quite ragged.  In a valid assignment of n rooks to the weird chess board, no two rooks can share a row or column.  In such an assignment, an unoccupied square is considered special if there is no rook to its right in the same row and no rook below in the same column (element 0 of cols describes the highest row).  You are going to return a string containing a single-space delimited list of pairs.  The pair (quotes for clarity) "r,f" should appear in the final string if and only if there is a valid assignment with r rooks such that f squares are special.  The pairs should be sorted in nondecreasing order by r values.  If a tie occurs, the lower f value should come first.  The returned value should contain no repeated pairs.  See the examples for further clarifications.

DEFINITION
Class:WeirdRooks
Method:describe
Parameters:vector <int>
Returns:string
Method signature:string describe(vector <int> cols)


CONSTRAINTS
-cols will contain between 1 and 8 elements inclusive.
-Each element of cols will be between between 1 and 10 inclusive.
-cols will be sorted in non-descending order.


EXAMPLES

0)
{3,3,3}

Returns: "0,9 1,4 1,5 1,6 1,7 1,8 2,1 2,2 2,3 2,4 2,5 2,6 3,0 3,1 3,2 3,3"

If no rooks are placed on the board, all 9 squares are special.  The following diagram depicts the scenario where 3 rooks are placed, and no squares are special.  
  R..
  .R.
  ..R 

1)
{1,2,3}

Returns: "0,6 1,3 1,4 1,5 2,1 2,2 2,3 3,0"

The case with 2 rooks and 3 special squares is depicted below.
  R
  .R
  ...

2)
{1}

Returns: "0,1 1,0"

3)
{2,9}

Returns: "0,11 1,2 1,3 1,4 1,5 1,6 1,7 1,8 1,9 1,10 2,0 2,1 2,2 2,3 2,4 2,5 2,6 2,7 2,8"

*/
// END CUT HERE
