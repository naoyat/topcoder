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
#include "cout.h"

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

template <typename T1, typename T2> pair<T1,T2> operator+(pair<T1,T2> p1, pair<T1,T2> p2)
{
  return make_pair(p1.first+p2.first, p1.second+p2.second);
}
template <typename T1, typename T2> pair<T1,T2> operator+=(pair<T1,T2>& p1, pair<T1,T2> p2)
{
  p1.first += p2.first; p1.second += p2.second; return p1;
}
template <typename T1, typename T2> pair<T1,T2> operator-(pair<T1,T2> p1, pair<T1,T2> p2)
{
  return make_pair(p1.first-p2.first, p1.second-p2.second);
}
template <typename T1, typename T2> pair<T1,T2> operator-=(pair<T1,T2>& p1, pair<T1,T2> p2)
{
  p1.first -= p2.first; p1.second -= p2.second; return p1;
}
template <typename T1, typename T2, typename T3> pair<T1,T2> operator*(pair<T1,T2> p, T3 n)
{
  return make_pair(p.first*n, p.second*n);
}
template <typename T1, typename T2, typename T3> pair<T1,T2> operator*=(pair<T1,T2>& p, T3 n)
{
  p.first *= n; p.second *= n; return p;
}
template <typename T1, typename T2, typename T3> pair<T1,T2> operator/(pair<T1,T2> p, T3 n)
{
  return make_pair(p.first/n, p.second/n);
}
template <typename T1, typename T2, typename T3> pair<T1,T2> operator/=(pair<T1,T2>& p, T3 n)
{
  p.first /= n; p.second /= n; return p;
}

using namespace std;
main()
{
  pair<int,int> a(10,20), b(3,4);
  cout << "a: " << a << endl;
  cout << "b: " << a << endl;
  cout << "a+b: " << a+b << endl;
  cout << "a-b: " << a-b << endl;
  cout << "a*2: " << a*2 << endl;
  cout << "a/2: " << a/2 << endl;
}
