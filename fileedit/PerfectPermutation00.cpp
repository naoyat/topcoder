#line 2 "PerfectPermutation.cpp"
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
typedef vector<int> vi;
typedef vector<string> vs;
#define sz(a)  int((a).size())
#define pb  push_back
#define tr(c,i)  for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); i++)
#define rep(var,n)  for(int var=0;var<(n);var++)

vector<int> isle(const vector<vector<bool> >& plan) {
  int n=plan.size();
  vector<int> id(n,0); for(int i=0;i<n;i++) id[i]=i;
  for (int i=0;i<n-1;i++) {
    for (int j=i+1;j<n;j++) {
      if (plan[i][j]==true) {
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

class PerfectPermutation {
 public:
  int reorder(vector<int> P) {
    int n=sz(P);
	vector<vector<bool> > a(n,vector<bool>(n,false));
    rep(i,n) a[i][P[i]] = a[P[i]][i] = true;
    map<int,int> isles = summary(isle(a));
    int s = sz(isles);
    return (s==1)?0:s;
  }
};





// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003] customized by cafelier, timer support by naoya_t
// Powered by CodeProcessor
