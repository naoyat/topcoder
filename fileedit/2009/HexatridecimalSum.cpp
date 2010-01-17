#line 2 "HexatridecimalSum.cpp"
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
#define tr(c,i)  for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); i++)
#define rep(var,n)  for(int var=0;var<(n);var++)

class bignum {
  int sign; //:2 1 / -1
  int size; // :30
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

  bignum operator+(const bignum& rop){
    bignum num(*this); num += rop; return num; }
  bignum operator-(const bignum& rop){
    bignum num(*this); num += rop.minus(); return num; }

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
  //void operator*=(const bignum& num);
  //void operator/=(const bignum& num);
  void operator+=(int n);
  void operator-=(int n){ operator+=(-n); }
  void operator*=(int n);
  void operator/=(int n);
  //void operator%=(int n);
  int remainder(){ return remainder_; }

  bignum add(const bignum& n){ bignum num(*this); num += n; return num; }
  bignum sub(const bignum& n){ bignum num(*this); num += n.minus(); return num; }
  //bignum mul(const bignum& n){ bignum num(*this); num *= n; return num; }
  //bignum div(const bignum& n){ bignum num(*this); num /= n; return num; }

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
  bignum num(*this);// = new bignum(this);
  num.sign = 1;
  return num;
}
bignum bignum::minus() const {
  bignum num(*this);// = new bignum(this);
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
void bignum::operator*=(int n){
  if(n==0){ set_zero(); return; }
  if(n==1){ return; }
  if(n==-1){ sign=-sign; return; }
  if(n<0){ sign=-sign; n=-n; }
  for(int i=0;i<size;i++) values[i]*=n;
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
void bignum::normalize(){
  int overflown=0;
  int sz=1;
  for(int i=0;i<size;i++){
    if (values[i]>0) sz=i+1;
    if (values[i]<0) {
      //if (values[i]<0) {
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
      //sz=i+1;
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
  set_zero(); default_radix_ = radix;

  int start=0, sg=1;
  if(val[0]=='-'){ sg = -1; start++; }
  else if(val[0]=='+') start++;
  for(int i=start,s=val.size();i<s;i++){
    operator*=( radix );
    operator+=( dec(val[i]) );
  }
  //cout << "[set]";
  normalize();
  sign = sg;
}


string replace(const string s, int a, int b){
  stringstream ss;
  int l=s.size();
  for(int i=0;i<l;i++){
    int c=s[i]; ss << (char)((c==a)? b : c);
  }
  return ss.str();
}

class HexatridecimalSum {
  /*
  int de(char c){
    if('0'<=c && c<='9') return c-'0';
    else return 10+(c-'A');
  }
  */
  char en(int c){
    if (c<10) return '0'+c;
    else return 'A'+(c-10);
  }
 public:
  string maximizeSum(vector<string> numbers, int k) {
    vector<bignum> ofs(36); rep(i,36) ofs[i]=0;
    bignum sum;
    tr(numbers,it){
      string orig = *it;
      bignum b(orig,36); sum += b;
      rep(i,36){
        bignum b_(replace(orig,en(i),'Z'),36);
        ofs[i] += (b_ - b);
      }
    }
    sort(all(ofs)); reverse(all(ofs));
    rep(i,k) sum += ofs[i];
    return sum.to_s(36);
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
	string numbers_[] = {"HELLO"};
	  vector <string> numbers(numbers_, numbers_+sizeof(numbers_)/sizeof(*numbers_)); 
	int k = 2; 
	string RetVal = "ZZLLO"; 
	return verify_case(RetVal, HexatridecimalSum().maximizeSum(numbers, k)); }
int Test_(Case_<1>) {
	timer_clear();
	string numbers_[] = {"500", "POINTS", "FOR", "THIS", "PROBLEM"};
	  vector <string> numbers(numbers_, numbers_+sizeof(numbers_)/sizeof(*numbers_)); 
	int k = 5; 
	string RetVal = "1100TC85"; 
	return verify_case(RetVal, HexatridecimalSum().maximizeSum(numbers, k)); }
int Test_(Case_<2>) {
	timer_clear();
	string numbers_[] = {"TO", "BE", "OR", "NOT", "TO", "BE"};
	  vector <string> numbers(numbers_, numbers_+sizeof(numbers_)/sizeof(*numbers_)); 
	int k = 0; 
	string RetVal = "QNO"; 
	return verify_case(RetVal, HexatridecimalSum().maximizeSum(numbers, k)); }
int Test_(Case_<3>) {
	timer_clear();
	string numbers_[] = {"KEQUALS36"};
	  vector <string> numbers(numbers_, numbers_+sizeof(numbers_)/sizeof(*numbers_)); 
	int k = 36; 
	string RetVal = "ZZZZZZZZZ"; 
	return verify_case(RetVal, HexatridecimalSum().maximizeSum(numbers, k)); }
int Test_(Case_<4>) {
	timer_clear();
	string numbers_[] = {"GOOD", "LUCK", "AND", "HAVE", "FUN"};
	  vector <string> numbers(numbers_, numbers_+sizeof(numbers_)/sizeof(*numbers_)); 
	int k = 7; 
	string RetVal = "31YUB"; 
	return verify_case(RetVal, HexatridecimalSum().maximizeSum(numbers, k)); }

template<int N> void Run_() { cerr << "Test Case #" << N << "..." << flush; Test_(Case_<N>()); Run_<sizeof(Test_(Case_<N+1>()))==1 ? -1 : N+1>(); }
template<>      void Run_<-1>() {}
int main() { Run_<0>(); }
// END CUT HERE


// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// Hexatridecimal notation is base 36 notation.  The digits are '0' to '9' (with values 0 to 9) and 'A' to 'Z' (with values 10 to 35).

You are given a vector <string> numbers, where each element represents a positive integer in hexatridecimal notation.  You must select exactly k digits (from the set of all digits - '0' to '9' and 'A' to 'Z') and replace all of their occurrences in all of the numbers with 'Z'.  Then, calculate the sum of all the numbers.

Return the maximal possible sum you can get.  The return value must be in hexatridecimal format with no leading zeroes.

DEFINITION
Class:HexatridecimalSum
Method:maximizeSum
Parameters:vector <string>, int
Returns:string
Method signature:string maximizeSum(vector <string> numbers, int k)


CONSTRAINTS
-numbers will contain between 1 and 50 elements, inclusive.
-Each element of numbers will contain between 1 and 50 characters, inclusive.
-Each element of numbers will contain only characters '0' to '9' and 'A' to 'Z'.
-Each element of numbers will not start with '0'.
-k will be between 0 and 36, inclusive.


EXAMPLES

0)
{"HELLO"}
2

Returns: "ZZLLO"

It is optimal to change the two most significant digits in the given number.

1)
{"500", "POINTS", "FOR", "THIS", "PROBLEM"}
5

Returns: "1100TC85"



2)
{"TO", "BE", "OR", "NOT", "TO", "BE"}
0

Returns: "QNO"

k = 0 means that you're not allowed to change any digits, so the answer is the sum of the given numbers.

3)
{"KEQUALS36"}
36

Returns: "ZZZZZZZZZ"

k = 36 means that you have to replace all the letters with 'Z'.

4)
{"GOOD", "LUCK", "AND", "HAVE", "FUN"}
7

Returns: "31YUB"



*/
// END CUT HERE
