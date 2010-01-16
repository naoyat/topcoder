#include <string>
#include <vector>
#include <stack>
#include <sstream>
#include <iostream>
using namespace std;

class bignum {
  int sign;
  int size;
  vector<int> values;

  int default_radix_;
  int remainder_;

 public:
  bignum(int val=0){set(val);default_radix_=10;}
  bignum(string val, int radix=10){set(val,default_radix_=radix);}
  bignum(const bignum& num){set(num);}
  bignum(int sg,const vector<int> &vals,int radix=0){set(sg,vals,radix);}

  void operator=(int val){set(val);}
  void operator=(string val){set(val,default_radix_);}
  void operator=(const bignum& num){set(num);}

  void set(int val);
  void set(string val, int radix=10);
  void set(const bignum& num);
  void set(int sg,const vector<int> &vals,int radix=0);

 private:
  bool is_zero() const { return (size==1 && values[0]==0)? true : false; };
  void set_zero();
  void normalize();

  char enc(int n) const { return n<10 ? '0'+n : 'A'+(n-10); }
  int dec(int ch) const { return ch<='9' ? ch-'0' : 10+ch-'A'; }

 public:
  void set_default_radix(int radix){default_radix_=radix;}
  int get_default_radix(){return default_radix_;}

  string sdump() const;
  void dump() { cout << sdump(); }

  bignum abs() const;
  bignum minus() const;

  int cmp(const bignum &n) const;
  int cmp_abs(const bignum &n) const;

  int to_i();
  string to_s(int radix=10) const;

  bignum operator+(const bignum& rop){ bignum num(*this); num += rop; return num; }
  bignum operator-(const bignum& rop){ bignum num(*this); num += rop.minus(); return num; }
  bignum operator*(const bignum& rop){ bignum num(*this); num *= rop; return num; }

  bignum operator+(int rop){
    bignum num(*this); num += rop; return num; }
  bignum operator-(int rop){
    bignum num(*this); num -= rop; return num; }
  bignum operator*(int rop){
    bignum num(*this); num *= rop; return num; }
  bignum operator/(int rop){
    bignum num(*this); num /= rop; return num; }

  bool operator==(const bignum& rop) const { return cmp(rop)==0; }
  bool operator!=(const bignum& rop) const { return cmp(rop)!=0; }
  bool operator>(const bignum& rop) const { return cmp(rop)>0; }
  bool operator>=(const bignum& rop) const { return cmp(rop)>=0; }
  bool operator<(const bignum& rop) const { return cmp(rop)<0; }
  bool operator<=(const bignum& rop) const { return cmp(rop)<=0; }

  void operator+=(const bignum& num);
  void operator-=(const bignum& num){ operator+=(num.minus()); }
  void operator*=(const bignum& num);
  //void operator/=(const bignum& num);

  void operator+=(int n);
  void operator-=(int n){ operator+=(-n); }
  void operator*=(int n);
  void operator/=(int n);
  //void operator%=(int n);
  int remainder(){ return remainder_; }

  bignum add(const bignum& n){ bignum num(*this); num += n; return num; }
  bignum sub(const bignum& n){ bignum num(*this); num += n.minus(); return num; }
  bignum mul(const bignum& n){ bignum num(*this); num *= n; return num; }
  //bignum div(const bignum& n){ bignum num(*this); num /= n; return num; }

  bignum add(int n){ bignum num(*this); num += n; return num; }
  bignum sub(int n){ bignum num(*this); num += (-n); return num; }
  bignum mul(int n){ bignum num(*this); num *= n; return num; }
  bignum div(int n){ bignum num(*this); num /= n; return num; }
};
// BEGIN CUT HERE
/*
  bool equals(bignum val);
  bignum gcd(bignum val);

  bignum shiftleft(int n);
  bignum shiftright(int n);

  double toDouble();
  long long toLongLong();
*/
// END CUT HERE
void bignum::set(int val){
  if (val == INT_MIN) {
    values.resize(size = 2);
    sign = -1;
    values[0] = 0; values[1] = 0x8000;
  } else {
    if (val < 0) { sign = -1; val = -val; } else sign = 1;
    if (val >= 65536) {
      values.resize(size = 2);
      values[0] = val % 65536; values[1] = val >> 16;
    } else {
      values.resize(size = 1);
      values[0] = val;
    }
  }
}

void bignum::set_zero(){
  values.resize(size = 1);
  size = 1; sign = 1; values[0] = 0;
}

void bignum::set(const bignum& num){
  values.assign(num.values.begin(), num.values.end());
  sign = num.sign; size = num.size; default_radix_ = num.default_radix_;
}

void bignum::set(int sg,const vector<int> &vals,int radix){
  if (radix == 0) {
    size=1;
    for(int i=0,s=vals.size();i<s;i++) if (vals[i]>0) size=i+1;
    values.assign(vals.begin(), vals.begin()+size);
    sign = is_zero()? 1 : sg;
  } else {
    set_zero();
  }
}

int bignum::to_i() {
  switch(size){
    case 1:
      return sign * values[0];
    case 2:
      if (values[1]<=0x7fff)
        return sign * ((values[1]<<16) | values[0]);
      else if (values[1]==0x8000 && values[0]==0 && sign==-1)
        return INT_MIN;
      else
        ; // else ; thru
    default:
      return INT_MAX+1;
  }
}

string bignum::sdump() const {
  stringstream ss;
  ss << ((sign > 0) ? "+" : "-") << hex << uppercase;
  for (int i=0;i<size;i++) {
    if (i>0) ss << ":";
    ss << values[size-i-1];
  }
  ss << "<" << size << ">";
  return ss.str();
}

bignum bignum::abs() const {
  bignum num(*this);
  num.sign = 1;
  return num;
}

bignum bignum::minus() const {
  bignum num(*this);
  if (!is_zero()) num.sign = -num.sign;
  return num;
}

int bignum::cmp(const bignum &n) const {
  if(sign != n.sign) return (sign - n.sign)/2;
  return sign * cmp_abs(n);
}

int bignum::cmp_abs(const bignum &n) const {
  if(size!=n.size)
    return size - n.size;
  for(int i=size-1;i>=0;i--)
    if(values[i]!=n.values[i]) return values[i] - n.values[i];
  return 0;
}

void bignum::operator+=(const bignum &n){
  if(n.is_zero()) return;
  if(sign == n.sign) {
    if(size < n.size) {
      values.resize(n.size);
      for(int i=size;i<n.size;i++) values[i]=0;
      size = n.size;
    }
    // simple addition
    for(int i=0;i<n.size;i++) values[i] += n.values[i];
  } else {
    if(cmp_abs(n) >= 0) {
      for(int i=0;i<n.size;i++) {
        if (values[i] >= n.values[i]) {
          values[i] -= n.values[i];
        } else {
          int pl=i+1;
          for(int j=i+1;j<n.size;j++) if(values[j]>0){ pl=j; break; }
          for(int j=pl;j>i;j--) { values[j]--; values[j-1]+=65536; }
          values[i] -= n.values[i];
        }
      }
    } else {
      bignum t(n);
      set(t + *this);
    }
  }
  normalize();
}

void bignum::operator*=(const bignum &n){
  if(is_zero()) return;
  if(n.is_zero()){ set_zero(); return; }
  sign *= n.sign;

  vector<int> tmp(size + n.size, 0);
  for(int i=n.size-1;i>=0;i--){
    int ni = n.values[i];
    for(int j=size-1;j>=0;j--){
      unsigned int ij = (unsigned int)ni * values[j];
      tmp[i+j] += ij % 65536;
      tmp[i+j+1] += ij >> 16;
    }
  }
  values.assign(tmp.begin(), tmp.end());
  size += n.size;
  normalize();
}

void bignum::operator+=(int n){
  if (n==0) return;
  if (sign*n<0){
    int m=this->to_i();
    if (m!=INT_MAX+1){
      set(m + n);
      return;
    }
  }
  if(sign==-1) n=-n;
  values[0] += n;
  normalize();
}

void bignum::operator*=(int n){
  if(n==0){ set_zero(); return; }
  if(n==1){ return; }
  if(n==-1){ sign=-sign; return; }
  if(n<0){ sign=-sign; n=-n; }
  for(int i=0;i<size;i++) values[i]*=n;
  normalize();
}

void bignum::operator/=(int n){
  if(n==0){ set_zero(); return; } // NaN
  if(n==1){ return; }
  if(n==-1){ sign=-sign; return; }
  if(n<0){ sign=-sign; n=-n; }
  int r = 0;
  for(int i=size-1; i>=0; i--){
    int v = (r << 16) + values[i];
    r = v % n;
    values[i] = v / n;
  }
  normalize();
  remainder_ = r;
}

void bignum::normalize(){
  unsigned int overflown=0;
  int sz=1;
  for(int i=0;i<size;i++){
    if (values[i]>0) sz=i+1;
    if (values[i]<0) {
      if (i==size-1) {
        // underflow
        sign=-sign;
        values[i]=-values[i];
        for (int j=i-1;j>=0;j--){
          //...
        }
      } else {
        // borrowable
        int b=-values[i];
        values[i+1] -= (b >> 16);
        if (b&0xffff){
          values[i+1]--;
          values[i] = 65536 - b;
        } else {
          values[i] = 0;
        }
      }
    }
    if (values[i]>=65536){
      if (i==size-1) overflown = values[i] >> 16;
      else values[i+1] += values[i] >> 16;
      values[i] %= 65536;
    }
  }
  if (overflown == 0) {
    if (sz<size) values.resize(size=sz);
    if (is_zero()) sign=1;
  } else if (overflown < 65536){
    values.resize(size+1);
    values[size++] = overflown;
  } else {
    values.resize(size+2);
    values[size++] = overflown % 65536;
    values[size++] = overflown >> 16;
  }
}

string bignum::to_s(int radix) const {
  if (is_zero()) return "0";
  if (radix < 2 || 36 < radix) return "?";

  stack<char> s;
  bignum tmp(*this);
  while(!tmp.is_zero()){
    tmp /= radix;
    s.push(enc(tmp.remainder()));
  }
  stringstream ss;
  if (sign == -1) ss << "-";
  while(!s.empty()){
    ss << s.top();
    s.pop();
  }
  return ss.str();
}

void bignum::set(string val, int radix){
  set_zero();
  if (radix < 2 || 36 < radix) return;
  default_radix_ = radix;

  int l=val.size();
  int start=0, sg=1;
  if(val[0]=='-'){ sg = -1; start++; }
  else if(val[0]=='+') start++;
  for(int i=start,s=val.size();i<s;i++){
    operator*=( radix );
    operator+=( dec(val[i]) );
  }
  normalize();
  sign = sg;
}

/*** END ***/

