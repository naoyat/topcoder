#include "cout.cc"
#include "macro.h"

int main()
{
  vi v;

  for (int i=0;i<6;i++) v.pb(i);
  // cout << v << endl;
  do {
	cout << v << endl;
  } while(next_permutation(all(v)));
}
