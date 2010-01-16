#include <vector>
#include <string>
#include <sstream>
using namespace std;

class Bignum {
  int sign;
  int size;
  vector<int> values;

  int default_radix_;
  int remainder_;

 public:
  Bignum(int val=0){set(val);default_radix_=10;}
  Bignum(string val, int radix=10){set(val,default_radix_=radix);}
  Bignum(const Bignum& num){set(num);}
  Bignum(int sg,const vector<int> &vals,int radix=0){set(sg,vals,radix);}

  Bignum& operator=(int val){ set(val); return *this; }
  Bignum& operator=(string val){ set(val,default_radix_); return *this; }
  Bignum& operator=(const Bignum& num){ set(num); return *this; }

  //  Bignum clone() { Bignum newone; set(*this); return newone; }

  void set( int val );
  void set( string val, int radix=10 );
  void set( const Bignum& num );
  void set( int sg, const vector<int> &vals, int radix=0 );

 private:
  bool is_zero() const { return (size==1 && values[0]==0)? true : false; };
  void set_zero();
  void normalize();

  char enc(int n) const { return n<10 ? '0'+n : 'A'+(n-10); }
  int dec(int ch) const { return ch<='9' ? ch-'0' : 10+ch-'A'; }

 public:
  void set_default_radix(int radix) { default_radix_=radix; }
  int get_default_radix() { return default_radix_; }

  string sdump() const;
  void dump() { cout << sdump(); }

  Bignum abs() const { Bignum num(*this); num.sign = 1; return num; }
  Bignum minus() const { Bignum num(*this); if (!is_zero()) num.sign = -num.sign; return num; }

  int cmp(const Bignum &n) const;
  int cmp_abs(const Bignum &n) const;

  int to_i();
  string to_s(int radix=10) const;

  Bignum operator+(const Bignum& rop) const { Bignum newnum(*this); newnum += rop; return newnum; }
  Bignum operator-(const Bignum& rop) const { Bignum newnum(*this); newnum += rop.minus(); return newnum; }
  Bignum operator*(const Bignum& rop) const { Bignum newnum(*this); newnum *= rop; return newnum; }
  Bignum operator/(const Bignum& rop) const { Bignum newnum(*this); newnum /= rop; return newnum; }

  Bignum operator-(){ return Bignum(this->minus()); }

  Bignum operator+(int rop) const { Bignum num(*this); num += rop; return num; }
  Bignum operator-(int rop) const { Bignum num(*this); num -= rop; return num; }
  Bignum operator*(int rop) const { Bignum num(*this); num *= rop; return num; }
  Bignum operator/(int rop) const { Bignum num(*this); num /= rop; return num; }
  Bignum operator%(int rop) const { Bignum num(*this); num %= rop; return num; }

  bool operator==(const Bignum& rop) const { return cmp(rop)==0; }
  bool operator!=(const Bignum& rop) const { return cmp(rop)!=0; }
  bool operator>(const Bignum& rop) const { return cmp(rop)>0; }
  bool operator>=(const Bignum& rop) const { return cmp(rop)>=0; }
  bool operator<(const Bignum& rop) const { return cmp(rop)<0; }
  bool operator<=(const Bignum& rop) const { return cmp(rop)<=0; }

  Bignum& operator+=(const Bignum& num);
  Bignum& operator-=(const Bignum& num){ return operator+=(num.minus()); }
  Bignum& operator*=(const Bignum& num);
  Bignum& operator/=(const Bignum& num);
  Bignum& operator%=(const Bignum& num);

  Bignum& operator+=(int n);
  Bignum& operator-=(int n){ return operator+=(-n); }
  Bignum& operator*=(int n);
  Bignum& operator/=(int n);
  Bignum& operator%=(int n);
  int remainder(){ return remainder_; }

  Bignum add(const Bignum& n){ Bignum num(*this); num += n; return num; }
  Bignum sub(const Bignum& n){ Bignum num(*this); num += n.minus(); return num; }
  Bignum mul(const Bignum& n){ Bignum num(*this); num *= n; return num; }
  Bignum div(const Bignum& n){ Bignum num(*this); num /= n; return num; }

  Bignum add(int n){ Bignum num(*this); num += n; return num; }
  Bignum sub(int n){ Bignum num(*this); num += (-n); return num; }
  Bignum mul(int n){ Bignum num(*this); num *= n; return num; }
  Bignum div(int n){ Bignum num(*this); num /= n; return num; }
};

ostream& operator<<(ostream &s, const Bignum& b)
{
  s << b.to_s(); return s;
}

///
void
Bignum::set(int val){
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

void
Bignum::set_zero(){
  values.resize(size = 1);
  size = 1; sign = 1; values[0] = 0;
}

void
Bignum::set(const Bignum& num){
  values.assign(num.values.begin(), num.values.end());
  sign = num.sign; size = num.size; default_radix_ = num.default_radix_;
}

void
Bignum::set(int sg,const vector<int> &vals,int radix){
  if (radix == 0) {
    size=1;
    for(int i=0,s=vals.size();i<s;i++) if (vals[i]>0) size=i+1;
    values.assign(vals.begin(), vals.begin()+size);
    sign = is_zero()? 1 : sg;
  } else {
    set_zero();
  }
}

int
Bignum::to_i() {
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

string
Bignum::sdump() const {
  stringstream ss;
  ss << ((sign > 0) ? "+" : "-") << hex << uppercase;
  for (int i=0;i<size;i++) {
    if (i>0) ss << ":";
    ss << values[size-i-1];
  }
  ss << "<" << size << ">";
  return ss.str();
}

int
Bignum::cmp(const Bignum &n) const {
  if(sign != n.sign) return (sign - n.sign)/2;
  return sign * cmp_abs(n);
}

int
Bignum::cmp_abs(const Bignum &n) const {
  if(size!=n.size)
    return size - n.size;
  for(int i=size-1;i>=0;i--)
    if(values[i]!=n.values[i]) return values[i] - n.values[i];
  return 0;
}

Bignum&
Bignum::operator+=(const Bignum &n){
  if(n.is_zero()) return *this;
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
      Bignum t(n);
      set(t + *this);
    }
  }
  normalize();
  return *this;
}

Bignum&
Bignum::operator*=(const Bignum &n){
  if(is_zero()) return *this;
  if(n.is_zero()){ set_zero(); return *this; }
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
  return *this;
}

Bignum&
Bignum::operator/=(const Bignum& num)
{
  //  cout << "Bignum::/= is not implemented yet..." << endl;
  Bignum quotient(0);
  Bignum _num = num.minus();
  while (sign == 1 && !is_zero()) { *this += _num; quotient+=1; }
  if (sign == -1) quotient-=1;

  set(quotient);
  return *this;
}
Bignum&
Bignum::operator%=(const Bignum& num)
{
  //cout << "Bignum::%= is not implemented yet..." << endl;
  // assert(this >= 0)
  // assert(num > 0)
  Bignum _num = num.minus();
  while (sign == 1 && !is_zero()) *this += _num;
  if (sign == -1) *this += num;
  return *this;
}

///
Bignum&
Bignum::operator+=(int n){
  if (n==0) return *this;
  if (sign*n<0){
    int m=this->to_i();
    if (m!=INT_MAX+1){
      set(m + n);
      return *this;
    }
  }
  if(sign==-1) n=-n;
  values[0] += n;
  normalize();
  return *this;
}

Bignum&
Bignum::operator*=(int n)
{
  if(n==0){ set_zero(); return *this; }
  if(n==1){ return *this; }
  if(n==-1){ sign=-sign; return *this; }
  if(n<0){ sign=-sign; n=-n; }
  for(int i=0;i<size;i++) values[i]*=n;
  normalize();
  return *this;
}

Bignum&
Bignum::operator/=(int n)
{
  if(n==0){ set_zero(); return *this; } // NaN
  if(n==1){ return *this; }
  if(n==-1){ sign=-sign; return *this; }
  if(n<0){ sign=-sign; n=-n; }
  int r = 0;
  for(int i=size-1; i>=0; i--){
    int v = (r << 16) + values[i];
    r = v % n;
    values[i] = v / n;
  }
  normalize();
  remainder_ = r;
  return *this;
}

void
Bignum::normalize()
{
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

string
Bignum::to_s(int radix) const {
  if (is_zero()) return "0";
  if (radix < 2 || 36 < radix) return "?";

  stack<char> s;
  Bignum tmp(*this);
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

void
Bignum::set(string val, int radix){
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
