#include <vector>

//
// リスト操作
//
#define remove_(c,val) (c).erase(remove((c).begin(),(c).end(),(val)),(c).end())

//
// 順列・組合せ
//

long long c(int n, int r)
{
  if (n == 0 || r == 0 || r == n) return 1LL;
  if (r > n-r) r = n-r;
  return c(n-1,r-1) * n / r;
}

template <typename T>
  vector<vector<T> > combinations(const vector<T>& list, int r)
{
  int n = list.size();
  int nCr = c(n, r);
  vector<vector<T> > result(nCr);
  vector<int> curr(r); for (int i=0; i<r; i++) curr[i] = i;

  for (int idx=0; idx<nCr; idx++) {
	result[idx].resize(r);
	for (int i=0; i<r; i++) result[idx][i] = list[curr[i]];

	for (int i=r-1; i>=0; i--) {
	  if (curr[i] == n-(r-i)) {
		if (i == 0) return result;
		continue;
	  } else {
		int ofs = curr[i] - i + 1;
		for (int j=i; j<r; j++) curr[j] = j + ofs;
		break;
	  }
	}
  }
}

//
// 最大公約数、最小公倍数
//
int gcd(int m, int n)
{
  if (m == 0 || n == 0) return 0;
  if (m == 1 || n == 1) return 1;
  if (m == n) return m;
  while (1) {
        if (m == 0) return n;
        if (n == 0) return m;
        if (m > n) m %= n; else n %= m;
  }
}
int lcm(int m, int n)
{
  return m / gcd(m,n) * n;
}

//
// 累乗、階乗
//
template <typename T> T expt(T x, int n) // x^n
{
  T y=1; for(int i=0;i<n;i++) y*=x; return y;
}
template <typename T> T factorial(T x) // x!
{
  T val = 1;
  for (T i=x; i>1; i--) val *= i;
  return val;
}
/*
int factorial(int x)
{
  int val = 1;
  for (int i=x; i>1; i--) val *= i;
  return val;
}
*/


//
string to_lower(string s)
{
  stringstream ss;
  for(int i=0,c=s.size();i<c;i++) ss << (char)tolower(s[i]);
  return ss.str();
}
string to_upper(string s)
{
  stringstream ss;
  for(int i=0,c=s.size();i<c;i++) ss << (char)toupper(s[i]);
  return ss.str();
}

// 回転
pair<int,int> turn(pair<int,int> dir, int deg){
  // 時計回りにdeg度回転

  // degの正規化
  if (deg < 0) deg = 360 - ((-deg)%360);
  deg %= 360;
  // printf("turn(<%d,%d>,%d)...\n", dir.first, dir.second, deg);
  switch(deg){
    case 0: default:
      return dir;
    case 90:
      return make_pair(-dir.second, dir.first);
    case 180:
      return make_pair(-dir.first, -dir.second);
    case 270:
      return make_pair(dir.second, -dir.first);
  }
}
