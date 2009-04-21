#line 2 "DigitsSwap.cpp"
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <cctype>
#include <algorithm>
#include <string>
#include <vector>
#include <deque>
#include <stack>
#include <queue>
#include <list>
#include <map>
#include <set>
// BEGIN CUT HERE
#include "cout.h"
// END CUT HERE
using namespace std;

#define sz(a)  int((a).size())
#define pb  push_back
#define all(c)  (c).begin(),(c).end()
#define mset(arr,val)  memset(arr,val,sizeof(arr))
#define tr(c,i)  for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); i++)
#define rep(var,n)  for(int var=0;var<(n);var++)
#define forr(var,from,to) for(int var=(from);var<=(to);var++) 
#define found(s,e)  ((s).find(e)!=(s).end())

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

  void operator+=(int n);
  void operator-=(int n){ operator+=(-n); }
  void operator*=(int n);
  void operator/=(int n);
  int remainder(){ return remainder_; }

  bignum add(const bignum& n){ bignum num(*this); num += n; return num; }
  bignum sub(const bignum& n){ bignum num(*this); num += n.minus(); return num; }
  bignum mul(const bignum& n){ bignum num(*this); num *= n; return num; }

  bignum add(int n){ bignum num(*this); num += n; return num; }
  bignum sub(int n){ bignum num(*this); num += (-n); return num; }
  bignum mul(int n){ bignum num(*this); num *= n; return num; }
  bignum div(int n){ bignum num(*this); num /= n; return num; }
};

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

//
class DigitsSwap {
 public:
  string maximalProduct(string x, string y, int swaps) {
    int swaps_0 = swaps;
    //cout << "----" << endl;
    //    printf("%s x %s, sw=%d\n", x.c_str(), y.c_str(), swaps);
    bignum bx=bignum(x), by=bignum(y);
	if (swaps==0){
      bignum m = bx*by;
      return m.to_s();
    }
    if(bx<by) swap(x,y);
    
    int keta=sz(x);
    vector<bool> fl(keta,false); rep(i,keta){ if(x[i]==y[i]) fl[i]=true; }
    int lim=keta-1, rev=0;
    if (swaps < keta) lim = swaps;

    int swapped=0, last_at=-1;
    bignum xy0 = bignum(x) * bignum(y);
    while(swapped<lim){
      bignum deltamax = bignum(0);
      int at=-1;//,in=0;
      for(int i=1;i<keta;i++){
        if (fl[i]) continue;
        swap(x[i],y[i]);
        bignum xy = bignum(x) * bignum(y);
        bignum delta = xy - xy0;
        if (delta > deltamax) {
          deltamax = delta;
          xy0 = xy;
          at = i;
        }
        swap(y[i],x[i]);
      }
      if (at >= 0) {
        // printf(" + changing #%d: %s x %s", at, x.c_str(), y.c_str());
        swap(x[at],y[at]);
        xy0 = bignum(x) * bignum(y);
        fl[at]=true; last_at = at;
        //printf(" => %s x %s\n", x.c_str(), y.c_str());
        swapped++;
      } else {
        break;
      }
    }

    int rest = (swaps - swapped) & 1;
    //printf("%d keta, swapped: %d / %d, rest=%d \n", keta, swapped, lim, rest);
    if (rest && (keta & 1)) {
      if (swapped >= keta/2) rest=0;
    }

    if (rest == 0) {
      return xy0.to_s();
    } else {
      //printf("!! rest=%d, last at=%d\n", rest, last_at);
      swap(x[last_at],y[last_at]);
      xy0 = bignum(x) * bignum(y);
      return xy0.to_s();
    }
  }
};

// BEGIN CUT HERE
#include <time.h>
clock_t start_time;
void timer_clear() { start_time = clock(); }
string timer() { clock_t end_time = clock(); double interval = (double)(end_time - start_time)/CLOCKS_PER_SEC; ostringstream os; os << " (" << interval*1000 << " msec)"; return os.str(); }

template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
int verify_case(const string &Expected, const string &Received) { if (Expected == Received) cerr << "PASSED" << timer() << endl; else { cerr << "FAILED" << timer() << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } return 0;}

template<int N> struct Case_ {};
char Test_(...);
int Test_(Case_<0>) {
	timer_clear();
	string x = "123"; 
	string y = "321"; 
	int swaps = 2; 
	string RetVal = "39483"; 
	return verify_case(RetVal, DigitsSwap().maximalProduct(x, y, swaps)); }
int Test_(Case_<1>) {
	timer_clear();
	string x = "4531"; 
	string y = "1332"; 
	int swaps = 0; 
	string RetVal = "6035292"; 
	return verify_case(RetVal, DigitsSwap().maximalProduct(x, y, swaps)); }
int Test_(Case_<2>) {
	timer_clear();
	string x = "13425"; 
	string y = "87694"; 
	int swaps = 99; 
	string RetVal = "1476187680"; 
	return verify_case(RetVal, DigitsSwap().maximalProduct(x, y, swaps)); }
int Test_(Case_<3>) {
	timer_clear();
	string x = "2872876342876443222"; 
	string y = "2309482482304823423"; 
	int swaps = 5; 
	string RetVal = "6669566046086333877050194232995188906"; 
	return verify_case(RetVal, DigitsSwap().maximalProduct(x, y, swaps)); }
int Test_(Case_<4>) {
	timer_clear();
	string x = "940948"; 
	string y = "124551"; 
	int swaps = 4893846; 
	string RetVal = "133434353148"; 
	return verify_case(RetVal, DigitsSwap().maximalProduct(x, y, swaps)); }
int Test_(Case_<5>) {
	timer_clear();
	string x = "56710852"; 
	string y = "18058360"; 
	int swaps = 1; 
	string RetVal = "1050671725722720"; 
	return verify_case(RetVal, DigitsSwap().maximalProduct(x, y, swaps)); }
int Test_(Case_<6>) {
	timer_clear();
	string x = "9"; 
	string y = "1"; 
	int swaps = 1000000000; 
	string RetVal = "9"; 
	return verify_case(RetVal, DigitsSwap().maximalProduct(x, y, swaps)); }

template<int N> void Run_() { cerr << "Test Case #" << N << "..." << flush; Test_(Case_<N>()); Run_<sizeof(Test_(Case_<N+1>()))==1 ? -1 : N+1>(); }
template<>      void Run_<-1>() {}
int main() { Run_<0>(); }
// END CUT HERE


// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// You are given two positive integers, x and y, whose decimal representations contain the same number of digits.  A digit-swap operation for an index i swaps the digits at the i-th positions in x and y.  After exactly swaps digit-swap operations, what is the maximal possible value of x*y?  Return the string representation of this maximal product with no leading zeroes.

DEFINITION
Class:DigitsSwap
Method:maximalProduct
Parameters:string, string, int
Returns:string
Method signature:string maximalProduct(string x, string y, int swaps)


CONSTRAINTS
-x and y will each contain between 1 and 50 characters, inclusive.
-x and y will contain only decimal digits ('0' to '9'), and will not start with a '0'.
-x and y will contain the same number of characters. 
-swaps will be between 0 and 1,000,000,000, inclusive. 


EXAMPLES

0)
"123"
"321"
2

Returns: "39483"

You can transform the numbers to "123", "321" (making two swaps at the same position) or to "321", "123" (making swaps at positions 0 and 2) to produce the product 39483.

1)
"4531"
"1332"
0

Returns: "6035292"

You are not allowed to make swaps, so the answer is just x * y.

2)
"13425"
"87694"
99

Returns: "1476187680"

The optimal answer is 17695 * 83424.

3)
"2872876342876443222"
"2309482482304823423"
5

Returns: "6669566046086333877050194232995188906"



4)
"940948"
"124551"
4893846

Returns: "133434353148"

5)
"56710852"
"18058360"
1

Returns: "1050671725722720"



6)
"9"
"1"
1000000000

Returns: "9"



*/
// END CUT HERE
