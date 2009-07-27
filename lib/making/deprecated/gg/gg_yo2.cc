#include <stdio.h>

char buf[8];

char *str(int x, int k)
{
  buf[k] = '\0';
  for (int i=k-1; i>=0; i--) {
	buf[i] = 'A' + (x % 26);
	x /= 26;
  }
  return buf;
}

char *excel(int x)
{
  for (int k=1,pow_k=26; k<=7,x>=0; k++,pow_k*=26) {
	// printf("x=%d, k=%d, pow_k=%d\n", x, k, pow_k);
	if (k == 7 || x < pow_k) return str(x, k);
	x -= pow_k;
  }
  return NULL;
}

int unexcel(const char *s)
{
  int offset = 0, x = 0;
  //printf("unexcel(%s) = ", s);
  for (; *s; s++) {
	//printf("[%c]{x=%d,ofs=%d}", *s, x, offset);
	x = x * 26 + (*s - 'A') + 1;
  }
  x--;
  // 0
  // 0 + 26 = 26n + 26
  // 0 + 26 + 26*26
  // 0 + 26 + 26*26 + 26*26*26
  // x = AAA = (A+1)*26*26 + (A+1)*26 + (A+1) - 1;;; A[0..25], (A+1)[1..26]
  //printf(" => %d\n", x);
  return x-1;
}
/*
 x+1 = 26*26*(A+1) + 26*(A+1) + 1*(A+1)
 x+1 in 26進法 
 0 => 
 25 => 25+1=10
 26 => 26+1=11 (AA);  51 => 51+1=20 => 1,-1=
*/

int test(int x)
{
  const char *s = excel(x);
  int ux = unexcel(s);
  printf("%10d => %s => %d ", x, s, ux);
  printf(" %s\n", (ux == x) ? "OK":"NG");
  return (ux == x) ? 1 : 0;
}

#define INT_MAX 2147483647
//  printf("FXSHRXX => %d\n", unexcel("FXSHRXX"));

int main()
{
  // 26 ** 0 = 1, ... , 26 ** 6 = 308915776, 26 ** 7 = 8031810176

  //  for (int i=0; i<10000; i++) test(i);
  for (int i=0; i<27; i++) test(i);
  for (int i=700; i<703; i++) test(i);
  // test(0);
  // test(INT_MAX);
  for (int i=INT_MAX-26; i<=INT_MAX; i++) test(i);
}

