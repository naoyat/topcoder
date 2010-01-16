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
#include "cout.h"
#include <time.h>
clock_t start_time;
void timer_clear() { start_time = clock(); }
string timer() { clock_t end_time = clock(); double interval = (double)(end_time - start_time)/CLOCKS_PER_SEC; ostringstream os; os << " (" << interval*1000 << " msec)"; return os.str(); }

template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
int verify_case(const long long &Expected, const long long &Received) { if (Expected == Received) cerr << "PASSED" << timer() << endl; else { cerr << "FAILED" << timer() << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } return 0;}

template<int N> struct Case_ {};
char Test_(...);
int Test_(Case_<0>) {
	timer_clear();
	long long a = 1LL; 
	long long b = 10LL; 
	long long RetVal = 3LL; 
	return verify_case(RetVal, TheAlmostLuckyNumbers().count(a, b)); }
int Test_(Case_<1>) {
	timer_clear();
	long long a = 14LL; 
	long long b = 14LL; 
	long long RetVal = 1LL; 
	return verify_case(RetVal, TheAlmostLuckyNumbers().count(a, b)); }
int Test_(Case_<2>) {
	timer_clear();
	long long a = 1LL; 
	long long b = 100LL; 
	long long RetVal = 39LL; 
	return verify_case(RetVal, TheAlmostLuckyNumbers().count(a, b)); }
int Test_(Case_<3>) {
	timer_clear();
	long long a = 1234LL; 
	long long b = 4321LL; 
	long long RetVal = 1178LL; 
	return verify_case(RetVal, TheAlmostLuckyNumbers().count(a, b)); }
int Test_(Case_<4>) {
	timer_clear();
	long long a =  9999999999LL;
	long long b = 10000000000LL;
	long long RetVal = 1LL; 
	return verify_case(RetVal, TheAlmostLuckyNumbers().count(a, b)); }

template<int N> void Run_() { cerr << "Test Case #" << N << "..." << flush; Test_(Case_<N>()); Run_<sizeof(Test_(Case_<N+1>()))==1 ? -1 : N+1>(); }
template<>      void Run_<-1>() {}
int main() { Run_<0>(); }

