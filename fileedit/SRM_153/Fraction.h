#include <vector>
#include <string>
#include <sstream>
using namespace std;

template <typename T> T gcd(T m, T n)
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

template <typename T> T lcm(T m, T n)
{
  return m / gcd(m,n) * n;
}

template <typename T> class Fraction {
  T numer, denom;

public:
  Fraction(){ init(0,1); }
  Fraction(T n, T d=1){ init(n,d); }
  Fraction(const Fraction<T>& other){ init(other); }

  T numerator() { return numer; }
  T denominator() { return denom; }

  Fraction<T>& init(T n, T d); // impl.below
  Fraction<T>& init(const Fraction<T>& other); // impl.below

  Fraction<T> operator+(const Fraction<T>& other) const; // impl.below
  Fraction<T> operator-(const Fraction<T>& other) const; // impl.below
  Fraction<T> operator*(const Fraction<T>& other) const; // impl.below
  Fraction<T> operator/(const Fraction<T>& other) const; // impl.below

  Fraction<T> operator+(T n) const { return Fraction<T>(numer+denom*n, denom); }
  Fraction<T> operator-(T n) const { return Fraction<T>(numer-denom*n, denom); }
  Fraction<T> operator*(T n) const { return Fraction<T>(numer*n, denom); }
  Fraction<T> operator/(T n) const { return Fraction<T>(numer, denom*n); }

  Fraction<T>& operator=(const Fraction<T>& other){ return init(other); }
  Fraction<T>& operator+=(const Fraction<T>& other); // impl.below
  Fraction<T>& operator-=(const Fraction<T>& other); // impl.below
  Fraction<T>& operator*=(const Fraction<T>& other) {
    return init(numer * other.numer, denom * other.denom); }
  Fraction<T>& operator/=(const Fraction<T>& other) {
    return init(numer * other.denom, denom * other.numer); }

  Fraction<T>& operator+=(T n){ return init(numer+denom*n, denom); }
  Fraction<T>& operator-=(T n){ return init(numer-denom*n, denom); }
  Fraction<T>& operator*=(T n){ return init(numer*n, denom); }
  Fraction<T>& operator/=(T n){ return init(numer, denom*n); }

  string desc() const; // impl.below
};

/// implementation
template <typename T> Fraction<T>&
Fraction<T>::init(T n, T d)
{
  //printf("init(%lld,%lld)", n, d);
  if (d < 0) n=-n, d=-d;
  if (n==0) {
    numer = 0, denom = 1;
  } else {
    T g = gcd(n,d);
    numer = n / g, denom = d / g;
  }
  //printf(" => %lld / %lld\n", numer,denom);
  return *this;
}

template <typename T> Fraction<T>&
Fraction<T>::init(const Fraction<T>& other){
  numer = other.numer, denom = other.denom;
  return *this;
}

template <typename T> Fraction<T>
Fraction<T>::operator+(const Fraction<T>& other) const
{
  T g = gcd(denom, other.denom), l = denom / g * other.denom;
  T n = numer * (other.denom / g) + other.numer * (denom / g);
  return Fraction(n, l);
}

template <typename T> Fraction<T>
Fraction<T>::operator-(const Fraction<T>& other) const
{
  T g = gcd(denom, other.denom), l = denom / g * other.denom;
  T n = numer * (other.denom / g) - other.numer * (denom / g);
  return Fraction(n, l);
}

template <typename T> Fraction<T>
Fraction<T>::operator*(const Fraction<T>& other) const
{
  T n = numer*other.numer, l = denom*other.denom;
  return Fraction(n,l);
}

template <typename T> Fraction<T>
Fraction<T>::operator/(const Fraction<T>& other) const
{
  T n = numer*other.denom, l = denom*other.numer;
  return Fraction(n,l);
}

template <typename T> Fraction<T>&
Fraction<T>::operator+=(const Fraction<T>& other)
{
  T g = gcd(denom, other.denom), l=denom/g*other.denom;// l=denomm*other.denom/gcd
  T n = numer*(other.denom/g) + other.numer*(denom/g);
  return init(n,l);
}

template <typename T> Fraction<T>&
Fraction<T>::operator-=(const Fraction<T>& other)
{
  T g = gcd(denom, other.denom), l = denom/g*other.denom;// l=denomm*other.denom/gcd
  T n = numer*(other.denom/g) - other.numer*(denom/g);
  return init(n,l);
}

template <typename T> string
Fraction<T>::desc() const
{
  stringstream ss;
  ss << numer;
  if (denom != 1) ss << "/" << denom;
  return ss.str();
}

template <typename T> ostream& operator<<(ostream &s, Fraction<T> fr)
{
  s << fr.desc(); return s;
}
