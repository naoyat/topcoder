#include <vector>
#include <string>
#include <iostream>
using namespace std;

typedef vector<int> vi;
//typedef vector<string> vs;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
#define sz(a)  int((a).size())
#define pb  push_back
#define all(c)  (c).begin(),(c).end()
#define tr(c,i)  for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); i++)
#define present(c,x)  ((c).find(x)!=(c).end())
#define cpresent(c,x)  (find(all(c),x)!=(c).end())
