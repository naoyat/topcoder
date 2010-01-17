#include "myset.h"

main()
{
  vector<char> chars(5);
  rep(i,5) chars[i] = 'A'+i;
  string s;
  s.assign(all(chars));
  cout << s << endl;

  string s2(all(chars));
  cout << s2 << endl;

  vector<char> c2(all(s2));
  cout << c2 << endl;
}
