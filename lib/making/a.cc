#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

#include "cout.cc"
#include "split.cc"

int atoi_(string s)
{
  return atoi(s.c_str());
}
vector<int> map_atoi_(const vector<string> &vs)
{
  vector<int> vi(vs.size());
  transform(vs.begin(),vs.end(),vi.begin(),atoi_);
  return vi;
}
main()
{
  vector<int> vi = map_atoi_( split("1 2 3 4 5") );
  cout << vi << endl;
}
