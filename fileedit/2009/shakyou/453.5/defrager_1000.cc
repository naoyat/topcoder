#include <assert.h> 
#include <ctype.h> 
#include <float.h> 
#include <math.h> 
#include <stdio.h> 
#include <string> 
#include <stdlib.h> 
#include <time.h> 
#include <algorithm> 
#include <numeric> 
#include <functional> 
#include <utility> 
#include <vector> 
#include <list> 
#include <set> 
#include <map> 
#include <queue> 
#include <stack> 
#include <sstream> 
#include <iostream> 

using namespace std;

#define rep(i,n) for(int i=0;i<(n);++i)
#define all(c) (c).begin(), (c).end() 
#define clr(a,b) memset(a,b,sizeof(a)); 
#define inf 1 << 29

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<string> vs;
typedef vector<int> vi;

const long long MAX_N =  10000000001LL;

ll gcd(ll a, ll b) 
{
  return b == 0 ? a : gcd(b, a % b); 
}

class TheAlmostLuckyNumbers 
{
  vector<long long> allNumbers;
public:
  void gen(long long cur)
  {
    if (cur > MAX_N)
      return;

    allNumbers.push_back(cur);

    gen(cur * 10 + 4);
    gen(cur * 10 + 7);
  }

  long long N;
  long long res;

  void cnt(int pos, long long cur, int total)
  {
    if (cur > N)
      return;

    if (cur != 1)
    {
      if (total & 1)
      {
        res += N / cur;
      }
      else
      {
        res -= N / cur;
      }
    }

    for (int i = pos; i <  allNumbers.size(); i++)
    {
      if (allNumbers[i] > N)
        break;
      if ((long double)cur * allNumbers[i] / 411107.0 > N)
        break;

      cnt(i + 1, cur * allNumbers[i] / gcd(cur, allNumbers[i]), total + 1);
    }
  }
  long long solve(long long b)
  {
    if (b == 0)
      return 0;

    N = b;

    res  = 0;
    cnt(0, 1, 0);

    return res;

  } 
  long long count(long long a, long long b) 
  {
	  allNumbers.clear();
    gen(4);
    gen(7);

    sort(all(allNumbers));

    for (int j = allNumbers.size() - 1; j >= 0; j--)
    {
      for (int i = j - 1; i >= 0; i--)
      {
        if ((allNumbers[j] % allNumbers[i]) == 0)
        {
          allNumbers.erase(allNumbers.begin() + j);
          break;
        }
      }
    }

    /*
    long long maxGcd = 0;
    for (int j = allNumbers.size() - 1; j >= 0; j--)
    {
      for (int i = j - 1; i >= 0; i--)
      {
        maxGcd = max(maxGcd, gcd(allNumbers[i], allNumbers[j]));
      }
    }*/
      
    return solve(b) - solve(a - 1);
  }
}; 
