#include <vector>
#include <string>
#include <set>
#include <iostream>
using namespace std;

class ReversedSum {
public:
  int getReversedSum(int x, int y);
};

int rev(int x)
{
  int r = 0;
  while (x > 0) {
	r *= 10;
	r += (x % 10);
	x /= 10;
  }
  return r;
}

int
ReversedSum::getReversedSum(int x, int y)
{
  return rev(rev(x) + rev(y));
}
