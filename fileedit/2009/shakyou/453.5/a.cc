#include <vector>
#include <algorithm>

#include "cout.h"

main()
{
  vector<int> a;
  for(int i=0;i<20;i++){
    a.push_back(i%7);
  }
  typeof(a.begin()) it;

  cout << a << endl;
  cout << (a.end() - a.begin()) << endl;

  it = unique(a.begin(),a.end());
  cout << "uniq: " << a << endl;
  //cout << it << endl;
  cout << (it - a.begin()) << endl;

  sort(a.begin(),a.end());
  cout << "sort: " << a << endl;
  cout << (a.end() - a.begin()) << endl;
  
  it = unique(a.begin(),a.end());
  cout << "sort.uniq: " << a << endl;
  //cout << it << endl;
  cout << (it - a.begin()) << endl;
}
