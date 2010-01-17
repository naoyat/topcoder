#include <vector>
using namespace std;

//
// 二進数
//
vector<int> to_bin( long long x )
{
  vector<int> bin;
  while (x > 0) {
	bin.push_back(x & 1); x >>= 1;
  }
  return bin;
}

long long bin_to_num( const vector<int> &vec )
{
  long long num = 0;
  for (int i=vec.size()-1; i>=0; i--) num = num * 2 + vec[i];
  return num;
}

string binstr( long long x, int len_min=1 )
{
  char buf[65], *p = buf+64;
  *p = 0;

  while (x > 0 || len_min > 0) {
    *(--p) = '0' + (x & 1);
    x >>= 1;
    len_min--;
  }
  return string(p)
}
