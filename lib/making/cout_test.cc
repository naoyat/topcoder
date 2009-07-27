#include "cout.cc"
#include "macro.h"

int main()
{
  vector<string> vs(4);
  vs[0] = "xyz", vs[1] = "def", vs[2] = "ghi", vs[3] = "abc";
  cout << vs << endl;

  sort(all(vs));
  cout << vs << endl;

  vector<int> vi(4);
  vi[0] = 2; vi[1] = 3; vi[2] = 5; vi[3] = 7;
  cout << vi << endl;

  set<int> s;
  s.insert(7);
  s.insert(5);
  s.insert(11);
  s.insert(9);
  s.insert(7);
  cout << s << endl;

  map<string,int> m;
  m["New York"] = 7;
  m["Los Angeles"] = 8;
  m["Boston"] = 10;
  m["Los Angeles"] = 3;
  cout << m << endl;

  vector< pair<int,int> > vii(5);
  vii[0] = make_pair(2,1);
  vii[1] = make_pair(4,3);
  vii[2] = make_pair(3,7);
  vii[3] = make_pair(3,5);
  vii[4] = make_pair(1,9);
  cout << vii << endl;

  sort(vii.begin(), vii.end());
  cout << vii << endl;
}
