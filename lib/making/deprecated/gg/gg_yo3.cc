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
/*
char *excel2(int x)
{
  // x+1 = (A+1)*26^(k-1) + ... + (A+1)*26^2 + (A+1)*26^1 + (A+1)*26^0
  // A+1 : [0..25]+1 = [1..26]
  x++;
  int k = 0;
  while (x > 0) {
	
  }
  for (int k=1,pow_k=26; k<=7,x>=0; k++,pow_k*=26) {
	// printf("x=%d, k=%d, pow_k=%d\n", x, k, pow_k);
	if (k == 7 || x < pow_k) return str(x, k);
	x -= pow_k;
  }
  return NULL;
}
*/
int unexcel(const char *s)
{
  int x = 0;
  for (; *s; s++) {
	x = x * 26 + (*s - 'A') + 1;
  }
  return x-1;
}

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

