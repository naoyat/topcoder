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

int pow26(int n)
{
  if (n == 0) return 1;
  return 26 * pow26(n - 1);
}

char *excel(int x)
{
  //  int k = 1;
  for (int k=1,pow_k=26; k<=7,x>=0; k++,pow_k*=26) {
	//  while (x >= 0) {
	//	int pow_k = pow26(k);
	// printf("x=%d, k=%d, pow_k=%d\n", x, k, pow_k);
	if (k == 7 || x < pow_k) return str(x, k);
	x -= pow_k;
	//	k++;
  }
  return NULL;
}

int main()
{
  // INT_MAX = 2147483647 =
  // 26 ** 0 = 1, ... , 26 ** 6 = 308915776, 26 ** 7 = 8031810176
  /*
  for (int i=0; i<20; i++) {
	printf("26 ** %d = %d\n", i, pow26(i));
  }
  */

  printf("0 => %s\n", excel(0));
  printf("INT_MAX:2147483647 => %s\n", excel(2147483647));
  /*
  for (int i=0; i<100; i++) {
	printf("%10d => %s\n", i, excel(i));
  }
  */
}

