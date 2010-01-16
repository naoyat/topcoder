#include <string>
#include <vector>
//#include <sstream>
#include <iostream>
using namespace std;

class bignum {
  int sign; //:2 1 / -1
  unsigned int size; // :30
  vector<unsigned int> values;

 public:
  bignum(int val=0);
  bignum(string val, int radix=10);
  bignum(const bignum& num);

  void operator=(const bignum& num);

  void dump();

  bignum abs();

  int toInt();
  string toString(int radix=10);
/*
  bignum add(bignum val);
  bignum sub(bignum val);
  bignum mul(bignum val);
  bignum div(bignum val);
  bignum mod(bignum val);

  bool equals(bignum val);
  int cmp(bignum val);
  bignum gcd(bignum val);

  bignum shiftleft(int n);
  bignum shiftright(int n);

  double toDouble();
  long long toLongLong();
  */
};

bignum::bignum(int val) {
  values.resize(size = 1);
  if (val == INT_MIN) {
    sign = -1;
    values[0] = (unsigned int)INT_MAX+1;
  } else if (val < 0) {
    sign = -1;
    values[0] = -val;
  } else {
    sign = 1;
    values[0] = val;
  }
}
bignum::bignum(string val, int radix) {
  size = 0;
}
bignum::bignum(const bignum& num) {
  sign = num.sign;
  size = num.size;
  values.assign(num.values.begin(), num.values.end());
}
void bignum::operator=(const bignum& num){
  sign = num.sign;
  size = num.size;
  values.assign(num.values.begin(), num.values.end());
}

int bignum::toInt() {
  if (size == 1 && values[0] <= INT_MAX) {
    if (sign > 0) return values[0];
    else return -values[0];
  } else {
    return INT_MAX+1;
  }
}
void bignum::dump() {
  // stringstream ss;
  cout << "?" << sign << "." << size;
  for (int i=0;i<size;i++) {
    cout << ":" << values[size-i-1];
  }
  //return ss.str();
}

bignum bignum::abs() {
  bignum num(*this);// = new bignum(this);
  num.sign = 1;
  return num;
}

string bignum::toString(int radix) {
  return "";
}

