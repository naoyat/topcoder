class NextNumber {
public:
  int getNextNumber(int N);
};

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
NextNumber::getNextNumber(int N)
{
  int w = weight(N);
  for (int j=N+1; j>0; j++) {
	if (weight(j) == w) return j;
  }
  return -1;
}
