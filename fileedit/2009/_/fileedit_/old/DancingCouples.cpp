#include <vector>
#include <string>
#include <set>
#include <iostream>
using namespace std;

class DancingCouples {
public:
  int countPairs(vector<string> canDance, int K);
};

int c(int n, int r)
{
  int x = 1;
  for (int i=n; i>1; i--) x *= i;
  for (int i=r; i>1; i--) x /= i;
  for (int i=n-r; i>1; i--) x /= i;
  return x;
}

int weight(int x) /* 32-bit integer */
{
  x = (x & 0x55555555) + ((x >> 1) & 0x55555555);
  x = (x & 0x33333333) + ((x >> 2) & 0x33333333);
  x = (x & 0x0f0f0f0f) + ((x >> 4) & 0x0f0f0f0f);
  x = (x & 0x00ff00ff) + ((x >> 8) & 0x00ff00ff);
  x = (x & 0x0000ffff) + ((x >>16) & 0x0000ffff);
  return x;
}

int 
DancingCouples::countPairs(vector<string> canDance, int K)
{
  int N = canDance.size(); // 1-10
  if (K > N) return 0;
  int M = canDance[0].length(); // 1-10
  if (K > M) return 0;

  bool table[N][M];

  for (int i=0; i<N; i++) {
	string s = canDance[i];
	for (int j=0; j<M; j++) {
	  table[i][j] = (s.at(j) == 'Y') ? true : false;
	}
  }

  long l = 1;
  for (int i=0; i<N; i++) l *= M;
  l--;

  int count = 0;
  set<long> sa;
  for (; l>=0; l--) {
	bool tmp[N][M];
	for (int i=0; i<N; i++) {
	  for (int j=0; j<M; j++) {
		tmp[i][j] = table[i][j];
	  }
	}

	set<long> s;
	long t = l, m = 1;
	for (int i=0; i<N; i++) {
	  int j = t % M; t /= M;
	  if (tmp[i][j]) {
		s.insert(j * M);
		for (int p=0; p<N; p++) tmp[p][j] = false;
		for (int q=0; q<M; q++) tmp[i][q] = false;
	  }
	  m *= M;
	}
	
	/*
	int ssize = s.size();
	if (ssize >= K) {
	  int m = 1 << ssize;
	  int n = 0;
	  for (int i=0; i<m; i++) {
		if (weight(i) == K) {
		  for (int j=1; j<ssize; j++) {
			if ((i & 1<<j) == 1) n += s.at(i);
		  }
		}
	  }
	  // choose K items from s
	  sa.insert(n);
	}
	*/
	sa.insert(l);
  }
  return sa.size();
}

int main()
{
  DancingCouples dc;

  vector<string> test0(3);
  test0[0] = "YYYY";
  test0[1] = "YYYY";
  test0[2] = "YYYY";
  cout << dc.countPairs(test0, 3) << "\n";

  vector<string> test1(3);
  test1[0] = "YYNN";
  test1[1] = "NYYN";
  test1[2] = "NNYY";
  cout << dc.countPairs(test1, 3) << "\n";

  vector<string> test2(3);
  test2[0] = "YY";
  test2[1] = "YY";
  test2[2] = "YY";
  cout << dc.countPairs(test2, 3) << "\n";

  vector<string> test3(6);
  test3[0] = "YYNNNN";
  test3[1] = "NYYNNN";
  test3[2] = "NNYYNN";
  test3[3] = "NNNYYN";
  test3[4] = "NNNNYY";
  test3[5] = "YNNNNY";
  cout << dc.countPairs(test3, 3) << "\n";
}
