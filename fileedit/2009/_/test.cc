#include <iostream>
using namespace std;

#include <cmath>
#include <float.h>

double find_max(double a, double b, double f(double)) {
  const double r = 2 / (3 + sqrt(5));
  double c = a + r * (b - a), d = b - r * (b - a);
  double fc = f(c), fd = f(d);
  while (d - c > DBL_MIN) {
    if (fc < fd) { // '<': maximum, '>': minimum
      a = c; c = d; d = b - r * (b - a);
      fc = fd; fd = f(d);
    } else {
      b = d; d = c; c = a + r * (b - a);
      fd = fc; fc = f(c);
    }
  }
  return c;
}

template <typename T> T expt(T x, int n) // x^n, pow
{
  T y=1; for(int i=0;i<n;i++) y*=x; return y;
}

main()
{
  cout << expt(2,32) << endl;
  cout << expt(2LL,32) << endl;
  string s="abc";
  cout << s.substr(0,1) << ", " << s.substr(1,0) << endl;
}
