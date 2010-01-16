#include "cout.h"

#define ar_all(ar) (ar),(ar)+(sizeof(ar)/sizeof((ar)[0]))


int main()
{
  string foo_[] = {"1","2","3"}, bar_[] = {"A","B","C"};
  vector<string> foo(ar_all(foo_));
  vector<string> bar(ar_all(bar_));
  
  cout << foo << endl;
  cout << bar << endl;
}
