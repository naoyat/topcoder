#include &lt;string>
#include &lt;vector>
using namespace std;

#define sz(a)  int((a).size())
#define pb  push_back
#define all(c)  (c).begin(),(c).end()
#define tr(c,i)  for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); i++)

class PiecesMover {
  vector&lt;pair&lt;int,int> > pattern(int x)
  {
    vector&lt;pair&lt;int,int> > ms(__builtin_popcount(x));
    int msi = 0;
    for (int i=0,m=1&lt;&lt;24; i&lt;25; i++,m>>=1)
      if (x & m) ms[msi++] = make_pair(i/5,i%5);
    return ms;
  }

  bool is_possible_pattern(const vector&lt;pair&lt;int,int> > &ms)
  {
    int n = sz(ms);
    vector&lt;bool> ok(n,false),ck(n,false);
    ok[0] = true;
    int okc = 1;

    bool om[7][7]; for (int i=1;i&lt;=5;i++) for (int j=1;j&lt;=5;j++) om[i][j] = 0;

    while (1) {
      int cx = -1;
      for (int i=0;i&lt;n;i++) if (ok[i] && !ck[i]) { cx=i; break; }
      if (cx == -1) break;//return false;

      ck[cx] = true;

      int x = 1+ms[cx].first, y = 1+ms[cx].second;
      om[x-1][y] = om[x+1][y] = om[x][y-1] = om[x][y+1] = true;

      for (int i=/* 0 */1;i&lt;n;i++) {
        if (!ok[i]) {
          int x = 1+ms[i].first, y = 1+ms[i].second;
          if (om[x][y]) { ok[i]=true; okc++; }
        }
      }
    }
    return (okc == n);
  }

  int distance(pair&lt;int,int> p1, pair&lt;int,int> p2)
  {
    return abs(p1.first - p2.first) + abs(p1.second - p2.second);
  }
public:
  int getMinimumMoves(vector&lt;string> board) {
    vector&lt;pair&lt;int,int> > pieces;
    for(int r=0;r&lt;5;r++)
      for (int c=0;c&lt;5;c++)
        if (board[r][c]=='*') pieces.pb(make_pair(r,c));

    int N = sz(pieces);

    vector&lt;vector&lt;pair&lt;int,int> > > ppat;
    for (int i=(1&lt;&lt;25)-1; i>=0; i--) {
      if (__builtin_popcount(i) != N) continue;
      vector&lt;pair&lt;int,int> > pat = pattern(i);
      if (is_possible_pattern(pat)) ppat.pb(pat);
    }
    if (is_possible_pattern(pieces)) return 0;

    int Nx = 1; for(int i=2;i&lt;=N;i++) Nx*=i;
    
    int minimum_distance = INT_MAX;
    tr(ppat,p) {
      vector&lt;int> v(N); for(int i=0;i&lt;N;i++) v[i]=i;
      for (int i=0; i&lt;Nx; i++) {
        int total_distance = 0;
        for (int j=0;j&lt;N;j++) total_distance += distance(pieces[j], (*p)[v[j]]);
        if (total_distance &lt; minimum_distance) minimum_distance = total_distance;
        next_permutation(all(v));
      }
    }
    return minimum_distance;
  }
};
