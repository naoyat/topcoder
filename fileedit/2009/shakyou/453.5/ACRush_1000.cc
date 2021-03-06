#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

#define SIZE(X) ((int)(X.size()))
#define MP(X,Y) make_pair(X,Y)
typedef long long int64;
#define two(X) (1<<(X))
#define contain(S,X) (((S)&two(X))!=0)
template<class T> inline T gcd(T a,T b)
  {if(a<0)return gcd(-a,b);if(b<0)return gcd(a,-b);return (b==0)?a:gcd(b,a%b);}

const int GLAST[]={
1,2,4,4,8,16,16,16,32,60,
106,103,172,396,169,123,160,323,224,354,
435,154,217,271,424,152,624,159,202,552,
165,463,387,389,1573,117,478,121,364,283,
257,124,186,209,157,125,483,109,363,265,
184,112,854,3093,181,112,145,114,568,115,
456,220,1117,135,183,140,260,89,316,302,
265,1969,300,89,1137,89,402,297,517,85,
1939,288,146,2861,453,126,281,397,114,2147,
506,367,885,85,706,190,501,633,566,66,
98,251,126,66,1158,246,126,2280,145,328,
256,275,164,258,259,111,2644,255,849,261,
587,65,386,65,98,1045,39,43,453,90,
39,21,28,124,39,233,127,21,117,21,
28,21,277,2147,26,43,34,21,61,105,
146,44,26,61,34,21,164,90,34,21,
52,21,163,43,26,71,108,105,71,43,
34,21,26,61,214,21,26,21,108,21,
318,509,78,170,82,90,121,44,26,21,
48,18,90,18,22,18,21,18,22,33,
187,18,22,18,21,18,109,18,43,18,
22,117,21,78,44,18,21,33,22,78,
90,18,22,17,21,44,108,17,21,94,
47,17,43,17,22,33,21,17,145,17,
47,233,116,17,43,17,22,17,90,94,
141,17,21,33,8,8,40,18,8,8,
8,8,8,8,8,34,8,8,18,40,
87,255,8,8,8,8,8,34,8,18,
62,8,8,8,87,8,8,8,180,8,
8,8,8,18,18,8,8,32,8,8,
8,8,8,8,8,181,108,8,164,8,
8,8,205,37,40,18,8,8,8,8,
18,33,8,18,8,8,8,37,8,18,
8,8,8,8,8,8,8,8,8,34,
40,18,18,8,38,8,8,8,8,8,
8,8,8,8,8,8,18,8,8,40,
8,8,8,8,8,18,8,18,87,8,
8,8,8,261,8,8,34,8,224,8,
8,240,40,13,8,6,8,6,8,59,
8,6,8,6,18,6,40,6,8,6,
8,13,8,29,40,6,8,219,8,31,
87,6,18,6,8,6,18,29,62,13,
8,6,8,6,40,13,8,6,8,6,
8,59,8,6,34,6,8,13,87,6,
8,220,8,6,41,29,18,6,8,40,
8,6,87,6,8,13,8,6,40,6,
8,6,8,6,396,6,40,33,8,32,
8,6,8,13,41,221,8,44,8,424,
40,6,141,6,41,6,8,26,18,6,
8,13,230,6,181,6,8,6,43,6,
18,29,8,25,48,6,8,6,40,13,
17,3,32,3,4,3,30,17,4,3,
4,3,4,3,17,3,4,3,4,3,
4,13,4,24,4,3,4,3,17,4,
4,3,4,4,4,13,4,3,4,3,
4,3,17,3,4,3,4,3,4,13,
4,4,4,3,4,3,17,3,4,3,
48,3,4,13,43,3,4,3,4,348,
17,3,4,23,4,3,4,3,4,4,
4,4,4,3,17,3,4,3,4,3,
4,3,4,3,4,3,4,3,17,25,
4,3,4,3,4,4,18,3,4,24,
4,32,17,3,4,3,4,4,4,13,
4,116,4,4,4,3,17,3,4,3,
4,3,4,17,4,3,4,3,4,4,
17,3,4,3,43,9,33,3,4,3,
4,4,4,3,4,3,4,3,4,3,
4,13,4,3,226,3,4,3,17,25,
4,19,4,3,4,17,4,4,4,25,
4,3,31,9,4,3,42,3,4,13,
4,3,4,3,4,3,17,3,4,3,
4,19,4,3,21,4,4,3,4,3,
4,3,4,3,43,3,4,3,4,25,
4,9,4,4,17,3,4,4,4,3,
4,13,33,3,4,3,4,3,17,21,
4,3,4,31,4,13,4,3,4,4,
4,3,17,3,4,3,4,3,3,17,
4,3,3,3,4,3,13,3,4,3,
4,19,4,7,3,23,4,3,3,3,
17,41,3,3,18,3,3,7,4,3,
3,19,4,3,3,4,41,3,3,9,
4,3,3,3,43,3,3,3,4,3,
3,3,4,3,4,62,4,4,3,3,
4,19,17,3,4,4,3,3,4,3,
23,4,4,3,3,3,17,3,3,3,
4,3,24,17,43,3,3,3,4,3,
13,3,4,3,3,3,4,3,4,3,
4,3,3,3,21,31,3,4,4,4,
3,7,4,9,25,3,4,3,13,21,
4,3,3,3,4,17,9,3,4,3,
3,3,17,3,3,3,33,3,3,7,
4,3,3,4,4,3,3,3,4,3,
3,3,4,7,4,3,4,3,4,3,
4,4,3,3,4,3,3,17,4,3,
3,3,4,3,3,3,4,3,32,4,
48,7,3,3,43,3,3,3,17,3,
3,3,4,3,3,7,4,4,3,3,
4,3,52,3,4,3,4,3,19,17,
3,3,4,3,3,4,17,3,3,3,
4,3,3,7,4,3,3,22,4,3,
17,3,4,4,3,3,4,7,3,3,
4,3,4,3,17,3,3,3,4,3,
3,17,2,1,2,6,2,1,4,1,
2,1,7,1,2,1,2,3,2,13,
2,1,2,1,2,1,7,1,2,1,
4,1,2,6,4,68,2,1,2,1,
2,1,2,3,2,1,2,5,2,1,
2,1,4,1,2,3,2,1,2,1,
2,13,2,1,2,1,2,1,7,3,
2,1,2,1,2,1,8,1,2,1,
4,1,17,1,2,1,2,1,2,6,
2,3,2,1,2,1,7,1,2,1,
2,69,2,1,2,3,4,1,2,1,
2,1,2,1,2,1,2,6,4,1,
2,1,2,1,17,1,2,3,2,1,
2,6,2,1,18,1,2,1,7,1,
4,1,2,3,2,6,2,1,2,1,
2,1,4,5,2,1,2,1,2,6,
2,3,2,1,2,3,2,71,2,1,
2,1,2,6,2,1,4,1,4,1,
2,1,2,1,2,1,2,13,2,1,
2,1,2,1,7,3,2,1,2,1,
105,6,2,1,2,1,4,1,7,1,
2,1,2,3,2,6,2,1,2,1,
2,1,7,1,4,1,2,1,4,6,
2,3,2,73,2,1,7,3,2,1,
2,1,2,6,2,1,2,1,2,3,
17,1,2,1,2,1,2,6,2,1,
4,1,2,3,2,1,2,1,2,9,
2,1,2,1,2,1,2,1,2,1,
2,3,4,1,2,6,2,1,2,1,
2,1,2,1,2,1,4,1,2,74,
2,1,2,1,2,3,2,3,2,1,
2,1,2,1,2,1,2,1,4,1,
2,1,2,1,2,1,4,1,2,1,
2,1,4,1,2,3,2,1,2,1,
2,6,2,5,4,1,2,1,7,1,
2,1,2,3,2,1,2,3,2,1,
2,1,2,1,2,75,2,1,4,1,
4,1,2,1,2,1,2,1,2,3,
8,1,2,1,2,1,4,1,2,1,
2,1,2,1,2,3,2,6,2,1,
2,1,2,1,4,1,2,3,2,1,
2,6,2,3,47,1,2,1,2,1,
2,1,4,1,2,1,2,1,4,1,
2,3,2,1,2,1,2,1,8,1,
4,1,2,1,2,1,2,1,2,3,
2,1,2,6,2,1,2,3,4,1,
7,1,2,1,107,1,2,6,2,1,
4,1,2,1,7,1,4,1,2,3,
2,6,2,3,2,1,2,1,2,1,
2,5,2,1,4,1,2,77,2,1,
2,3,2,1,2,1,2,1,2,6,
2,1,4,1,2,1,6,1,2,1,
5,3,4,1,1,1,2,1,1,1,
7,1,1,1,4,1,1,1,2,1,
3,1,2,3,6,1,2,3,1,1,
2,1,1,1,2,1,1,1,4,1,
1,1,2,94,1,3,2,1,1,1,
2,1,6,1,2,1,3,1,2,1,
1,1,2,1,3,1,2,1,1,1,
2,1,1,3,2,3,95,1,2,1,
6,1,2,1,1,1,4,1,1,1,
4,1,1,1,2,1,1,1,2,3,
1,1,2,1,1,1,2,1,13,96,
2,3,1,1,2,1,1,3,2,1,
1,1,7,1,3,1,2,3,1,1,
2,1,1,3,2,1,6,1,2,1,
1,1,2,1,1,3,4,1,1,1,
7,1,5,1,2,1,1,1,2,1,
3,1,2,1,6,1,2,1,1,3,
2,3,1,1,2,97,1,1,7,1,
1,1,4,1,1,1,2,1,1,1,
4,1,6,1,2,1,3,1,2,3,
1,1,2,5,1,1,7,1,3,1,
2,1,1,1,2,1,1,3,2,1,
6,3,8,1,1,1,2,1,1,1,
2,1,3,1,17,1,1,1,2,1,
1,5,2,3,1,1,2,1,6,1,
2,1,1,3,2,1,1,1,2,1,
1,1,2,1,3,1,18,1,1,1,
2,1,1,1,2,3,6,1,2,1,
1,1,2,1,1,1,2,1,1,3,
4,1,1,1,2,1,1,1,2,1,
1,1,4,1,5,1,2,99,3,1,
2,3,1,1,2,1,3,1,2,3,
1,1,2,1,1,3,2,1,1,1,
2,1,6,1,2,1,1,3,4,1,
100,1,8,1,1,1,2,1,1,1,
2,1,3,1,2,1,1,5,2,1,
1,3,2,3,1,1,2,1,1,1,
2,1,1,101,4,1,1,1,2,3,
1,1,2,1,1,1,2,1,6,1,
4,1,1,1,2,1,1,3,2,1,
1,1,7,1,1,1,2,1,3,1,
2,1,3,1,2,9,1,1,2,1,
1,3,2,1,1,1,2,1,1,1,
2,1,1,3,4,1,1,1,2,102,
1,1,4,1,26,1,2,1,1,1,
2,3,1,1,2,1,1,1,7,1,
3,1,2,3,1,1,2,1,1,3,
2,1,6,1,2,1,1,1,4,1,
1,1,2,1,3,1,2,3,1,1,
2,1,1,1,2,1,3,1,2,1,
6,1,2,1,1,3};

class TheAlmostLuckyNumbers
{
public:
  int n;
  int64 A[10000];
  vector<pair<int64,int64> > Q;
  map<int64,int64> M;
  int64 count(int64 a, int64 b)
  {
    n=0;
    for (int L=1;L<=10;L++)
      for (int set=0;set<two(L);set++)
      {
        int64 key=0;
        for (int i=0;i<L;i++)
          if (contain(set,i))
            key=key*10+4;
          else
            key=key*10+7;
        A[n++]=key;
      }
    sort(A,A+n);
    a--;
    Q.clear();
    M.clear();
    Q.push_back(MP(1,1));
    M[1]+=1;
    for (int step=0;step<n;step++)
    {
      for (int i=0;i<GLAST[step];i++)
      {
        int64 state=Q[i].first;
        int64 multiply=Q[i].second;
        int64 v1=state;
        int64 v2=A[step]/gcd(A[step],state);
        if (v1<=100000LL*100000LL/v2)
          M[v1*v2]-=multiply;
      }
      Q.clear();
      for (map<int64,int64>::iterator it=M.begin();it!=M.end();++it)
        if (it->second!=0)
          Q.push_back(*it);
    }
    int64 R=0;
    for (int i=SIZE(Q)-1;i>=0;i--)
    {
      int64 state=Q[i].first;
      int64 multiply=Q[i].second;
      R+=multiply*(b/state-a/state);
    }
    R=(b-a)-R;
    return R;
  }
};
