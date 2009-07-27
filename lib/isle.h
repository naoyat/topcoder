#include <algorithm>
#include <string>
#include <vector>
#include <map>
using namespace std;

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
vector<int> isle(const vector<string>& plan, int connection='Y') {
  int n=plan.size();
  vector<int> id(n,0); for(int i=0;i<n;i++) id[i]=i;
  for (int i=0;i<n-1;i++) {
    for (int j=i+1;j<n;j++) {
      if (plan[i][j]==connection) {
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
vector<int> hands(const vector<string>& plan, const vector<int>& id, int connection='Y') {
  int n=plan.size();
  vector<int> hz(n,0);
  for (int i=0;i<n-1;i++) {
    for (int j=i+1;j<n;j++) {
      if (plan[i][j]==connection) hands[id[i]]++;
    }
  }
  return hz;
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
