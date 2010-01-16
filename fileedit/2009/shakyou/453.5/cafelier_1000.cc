#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>
#include <iterator>
#include <functional>
#include <complex>
#include <queue>
#include <stack>
#include <cmath>
#include <cassert>
#include <cstring>
using namespace std;
typedef long long LL;
typedef complex<double> CMP;

LL gcd(LL a, LL b)
{
  while(a)
    swap(a, b%=a);
  return b;
}

LL lcm(LL a, LL b)
{
  return a/gcd(a,b)*b;
}

class TheAlmostLuckyNumbers { public:
  void genLuck(vector<LL>& v)
  {
    // lucky numbers
    vector<LL> u;
    for(int d=1; d<=10; ++d)
      genLuck(d, u);

    // filtering
    for(int i=0; i<u.size(); ++i)
    {
      for(int j=0; j<i; ++j)
        if( u[i] % u[j] == 0 )
          goto next;
      v.push_back( u[i] );
    next:;
    }
    sort(v.begin(), v.end());
    // 1199 lucky numbers are left...
  }

  void genLuck(int d, vector<LL>& v)
  {
    // d-digit lucky numbers
    for(int b=0; b<(1<<d); ++b)
    {
      LL n = 0;
      for(int i=0; i<d; ++i)
        n = n*10 + (b&(1<<i) ? 4 : 7);
      v.push_back(n);
    }
  }

  long long count(long long a, long long b) 
  {
    vector<LL> v;
    genLuck(v);

    static const int M = 16;

    // inclusion-exclusion
    LL cnt = 0;
    {
      for(int m=1; m<(1<<M); ++m)
      {
        int bc = 0;
        LL n = 1;
        for(int i=0; i<M; ++i)
          if( m & (1<<i) )
            ++bc, n=lcm(n, v[i]);
        cnt += (bc&1) ? (b/n-(a-1)/n) : -(b/n-(a-1)/n);
      }
    }

    // sieve
    vector<LL> aml;
    for(int i=M; i<v.size() && v[i]<=b; ++i)
    {
      LL u = v[i];
      for(LL s=a%u?(a/u+1)*u:a; s<=b; s+=u)
      {
        for(int k=0; k<M; ++k)
          if( s%v[k]==0 )
            goto next;
        aml.push_back(s);
      next:;
      }
      if( aml.size() > 10000000 ) {
        sort(aml.begin(), aml.end());
        aml.erase(unique(aml.begin(), aml.end()), aml.end());
      }
    }

        sort(aml.begin(), aml.end());
        aml.erase(unique(aml.begin(), aml.end()), aml.end());
    return cnt + aml.size();
  }
};
