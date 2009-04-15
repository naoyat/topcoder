using namespace std;

#include "cout.h"

#include "bignum.h"
#include <gtest/gtest.h>

TEST(BignumTest, sdump)
{
  bignum num; vector<int> v(1,0);
  num.set(1,v); EXPECT_EQ("+0<1>", num.sdump());
  num.set(-1,v); EXPECT_EQ("+0<1>", num.sdump());
  
  v[0]=1;
  num.set(1,v); EXPECT_EQ("+1<1>", num.sdump());
  num.set(-1,v); EXPECT_EQ("-1<1>", num.sdump());

  v[0]=65535;
  num.set(1,v); EXPECT_EQ("+FFFF<1>", num.sdump());
  num.set(-1,v); EXPECT_EQ("-FFFF<1>", num.sdump());

  v.resize(2);
  v[0]=v[1]=0;
  num.set(1,v); EXPECT_EQ("+0<1>", num.sdump());
  num.set(-1,v); EXPECT_EQ("+0<1>", num.sdump());
  v[0]=65535; v[1]=1;
  num.set(1,v); EXPECT_EQ("+1:FFFF<2>", num.sdump());
  num.set(-1,v); EXPECT_EQ("-1:FFFF<2>", num.sdump());
  v[1]=65535;
  num.set(1,v); EXPECT_EQ("+FFFF:FFFF<2>", num.sdump());
  num.set(-1,v); EXPECT_EQ("-FFFF:FFFF<2>", num.sdump());

  v.resize(3);
  v[2]=1;
  num.set(1,v); EXPECT_EQ("+1:FFFF:FFFF<3>", num.sdump());
  num.set(-1,v); EXPECT_EQ("-1:FFFF:FFFF<3>", num.sdump());
  v[2]=65535;
  num.set(1,v); EXPECT_EQ("+FFFF:FFFF:FFFF<3>", num.sdump());
  num.set(-1,v); EXPECT_EQ("-FFFF:FFFF:FFFF<3>", num.sdump());
}

TEST(BignumTest, to_i)
{
  bignum num; EXPECT_EQ(0, num.to_i());
  num=1; EXPECT_EQ(1, num.to_i());
  num=2; EXPECT_EQ(2, num.to_i());
  num=-1; EXPECT_EQ(-1, num.to_i());
  num=-2; EXPECT_EQ(-2, num.to_i());

  num=65535; EXPECT_EQ(65535, num.to_i());
  num=-65535; EXPECT_EQ(-65535, num.to_i());
  num=65536; EXPECT_EQ(65536, num.to_i());
  num=-65536; EXPECT_EQ(-65536, num.to_i());
  num=65537; EXPECT_EQ(65537, num.to_i());
  num=-65537; EXPECT_EQ(-65537, num.to_i());
  
  num=INT_MAX; EXPECT_EQ(INT_MAX, num.to_i());
  num=-INT_MAX; EXPECT_EQ(-INT_MAX, num.to_i());
  num=INT_MIN; EXPECT_EQ(INT_MIN, num.to_i());
  // overflow case
  //...
}

TEST(BignumTest, ctor_from_signed_int)
{
  bignum num; EXPECT_EQ(0, num.to_i()); EXPECT_EQ("+0<1>", num.sdump());
  bignum num0(0); EXPECT_EQ(0, num0.to_i()); EXPECT_EQ("+0<1>", num0.sdump());

  bignum num1(1); EXPECT_EQ(1, num1.to_i()); EXPECT_EQ("+1<1>", num1.sdump());
  bignum num2(2); EXPECT_EQ(2, num2.to_i()); EXPECT_EQ("+2<1>", num2.sdump());
  bignum num_1(-1); EXPECT_EQ(-1, num_1.to_i()); EXPECT_EQ("-1<1>", num_1.sdump());
  bignum num_2(-2); EXPECT_EQ(-2, num_2.to_i()); EXPECT_EQ("-2<1>", num_2.sdump());

  bignum numIMAX(INT_MAX); EXPECT_EQ(INT_MAX, numIMAX.to_i()); EXPECT_EQ("+7FFF:FFFF<2>", numIMAX.sdump());
  bignum num_IMAX(-INT_MAX); EXPECT_EQ(-INT_MAX, num_IMAX.to_i()); EXPECT_EQ("-7FFF:FFFF<2>", num_IMAX.sdump());
  bignum numIMIN(INT_MIN); EXPECT_EQ(INT_MIN, numIMIN.to_i()); EXPECT_EQ("-8000:0<2>", numIMIN.sdump());
}

TEST(BignumTest, assign_signed_int)
{
  bignum num;
  num=0; EXPECT_EQ(0, num.to_i()); EXPECT_EQ("+0<1>", num.sdump());
  num=1; EXPECT_EQ(1, num.to_i()); EXPECT_EQ("+1<1>", num.sdump());
  num=2; EXPECT_EQ(2, num.to_i()); EXPECT_EQ("+2<1>", num.sdump());
  num=-1; EXPECT_EQ(-1, num.to_i()); EXPECT_EQ("-1<1>", num.sdump());
  num=-2; EXPECT_EQ(-2, num.to_i()); EXPECT_EQ("-2<1>", num.sdump());
  num=1000000; EXPECT_EQ(1000000, num.to_i()); EXPECT_EQ("+F:4240<2>", num.sdump());
  num=-1000000; EXPECT_EQ(-1000000, num.to_i()); EXPECT_EQ("-F:4240<2>", num.sdump());
  num=INT_MAX; EXPECT_EQ(INT_MAX, num.to_i()); EXPECT_EQ("+7FFF:FFFF<2>", num.sdump());
  num=-INT_MAX; EXPECT_EQ(-INT_MAX, num.to_i()); EXPECT_EQ("-7FFF:FFFF<2>", num.sdump());
  num=INT_MIN; EXPECT_EQ(INT_MIN, num.to_i()); EXPECT_EQ("-8000:0<2>", num.sdump());
}

TEST(BignumTest, abs)
{
  bignum num; EXPECT_EQ(0, num.abs().to_i()); EXPECT_EQ("+0<1>", num.abs().sdump());
  num=1; EXPECT_EQ(1, num.abs().to_i()); EXPECT_EQ("+1<1>", num.abs().sdump());
  num=2; EXPECT_EQ(2, num.abs().to_i()); EXPECT_EQ("+2<1>", num.abs().sdump());
  num=-1; EXPECT_EQ(1, num.abs().to_i()); EXPECT_EQ("+1<1>", num.abs().sdump());
  num=-2; EXPECT_EQ(2, num.abs().to_i()); EXPECT_EQ("+2<1>", num.abs().sdump());

  num=INT_MAX; EXPECT_EQ(INT_MAX, num.abs().to_i()); EXPECT_EQ("+7FFF:FFFF<2>", num.abs().sdump());
  num=-INT_MAX; EXPECT_EQ(INT_MAX, num.abs().to_i()); EXPECT_EQ("+7FFF:FFFF<2>", num.abs().sdump());
  num=INT_MIN; EXPECT_EQ(INT_MIN, num.abs().to_i()); EXPECT_EQ("+8000:0<2>", num.abs().sdump());

  vector<int> v(2,65535);
  num.set(1,v); EXPECT_EQ("+FFFF:FFFF<2>", num.abs().sdump());
  num.set(-1,v); EXPECT_EQ("+FFFF:FFFF<2>", num.abs().sdump());
}

TEST(BignumTest, minus)
{
  bignum num; EXPECT_EQ(0, num.abs().to_i()); EXPECT_EQ("+0<1>", num.minus().sdump());
  num=1; EXPECT_EQ(-1, num.minus().to_i()); EXPECT_EQ("-1<1>", num.minus().sdump());
  num=2; EXPECT_EQ(-2, num.minus().to_i()); EXPECT_EQ("-2<1>", num.minus().sdump());
  num=-1; EXPECT_EQ(1, num.minus().to_i()); EXPECT_EQ("+1<1>", num.minus().sdump());
  num=-2; EXPECT_EQ(2, num.minus().to_i()); EXPECT_EQ("+2<1>", num.minus().sdump());

  num=INT_MAX; EXPECT_EQ(-INT_MAX, num.minus().to_i()); EXPECT_EQ("-7FFF:FFFF<2>", num.minus().sdump());
  num=-INT_MAX; EXPECT_EQ(INT_MAX, num.minus().to_i()); EXPECT_EQ("+7FFF:FFFF<2>", num.minus().sdump());
  num=INT_MIN; EXPECT_EQ(INT_MAX+1, num.minus().to_i()); EXPECT_EQ("+8000:0<2>", num.minus().sdump());

  vector<int> v(2,65535);
  num.set(1,v); EXPECT_EQ("-FFFF:FFFF<2>", num.minus().sdump());
  num.set(-1,v); EXPECT_EQ("+FFFF:FFFF<2>", num.minus().sdump());
}

TEST(BignumTest, to_s)
{
  bignum num; EXPECT_EQ("0", num.to_s());
  num=1; EXPECT_EQ("1", num.to_s());
  num=2; EXPECT_EQ("2", num.to_s());
  num=-1; EXPECT_EQ("-1", num.to_s());
  num=-2; EXPECT_EQ("-2", num.to_s());
  num=INT_MAX; EXPECT_EQ("2147483647", num.to_s());
  num=-INT_MAX; EXPECT_EQ("-2147483647", num.to_s());
  num=INT_MIN; EXPECT_EQ("-2147483648", num.to_s());

  num=15;
  EXPECT_EQ("15", num.to_s());
  EXPECT_EQ("1111", num.to_s(2));
  EXPECT_EQ("F", num.to_s(16));
  num=100;
  EXPECT_EQ("100", num.to_s());
  EXPECT_EQ("64", num.to_s(16));

  num=35;
  EXPECT_EQ("35", num.to_s());
  EXPECT_EQ("100011", num.to_s(2));
  EXPECT_EQ("23", num.to_s(16));
  EXPECT_EQ("Z", num.to_s(36));

  num=65537;
  EXPECT_EQ("65537", num.to_s());
  EXPECT_EQ("10000000000000001", num.to_s(2));
  EXPECT_EQ("10001", num.to_s(16));

  num=1; for(int i=0;i<30;i++) num*=10;
  EXPECT_EQ("1000000000000000000000000000000", num.to_s());
  num=1; for(int i=0;i<30;i++) num*=16;
  EXPECT_EQ("1000000000000000000000000000000", num.to_s(16));
}

TEST(BignumTest, add_eq_signed_int) // testing operator +=
{
  bignum num;
  num=0; num+=2; EXPECT_EQ("+2<1>", num.sdump());
  num=0; num+=-2; EXPECT_EQ("-2<1>", num.sdump());

  num=1; num+=2; EXPECT_EQ("+3<1>", num.sdump());
  num=1; num+=-2; EXPECT_EQ("-1<1>", num.sdump());
  num=-1; num+=2; EXPECT_EQ("+1<1>", num.sdump());
  num=-1; num+=-2; EXPECT_EQ("-3<1>", num.sdump());

  num=50000; num+=50000;
  EXPECT_EQ(100000, num.to_i()); EXPECT_EQ("+1:86A0<2>", num.sdump());
  num=50000; num+=-50000;
  EXPECT_EQ(0, num.to_i()); EXPECT_EQ("+0<1>", num.sdump());
  num=-50000; num+=50000;
  EXPECT_EQ(0, num.to_i()); EXPECT_EQ("+0<1>", num.sdump());
  num=-50000; num+=-50000;
  EXPECT_EQ(-100000, num.to_i()); EXPECT_EQ("-1:86A0<2>", num.sdump());

  num=567890; num+=432100;
  EXPECT_EQ(999990, num.to_i()); EXPECT_EQ("+F:4236<2>", num.sdump());
  num=567890; num+=-432100;
  EXPECT_EQ(135790, num.to_i()); EXPECT_EQ("+2:126E<2>", num.sdump());
  num=-567890; num+=432100;
  EXPECT_EQ(-135790, num.to_i()); EXPECT_EQ("-2:126E<2>", num.sdump());
  num=-567890; num+=-432100;
  EXPECT_EQ(-999990, num.to_i()); EXPECT_EQ("-F:4236<2>", num.sdump());
  
  num=567890; num+=567889;
  EXPECT_EQ(1135779, num.to_i()); EXPECT_EQ("+11:54A3<2>", num.sdump());
  num=567890; num+=-567889;
  EXPECT_EQ(1, num.to_i()); EXPECT_EQ("+1<1>", num.sdump());
  num=-567890; num+=567889;
  EXPECT_EQ(-1, num.to_i()); EXPECT_EQ("-1<1>", num.sdump());
  num=-567890; num+=-567889;
  EXPECT_EQ(-1135779, num.to_i()); EXPECT_EQ("-11:54A3<2>", num.sdump());

  num=432100; num+=567890; EXPECT_EQ("+F:4236<2>", num.sdump());
  num=432100; num+=-567890; EXPECT_EQ("-2:126E<2>", num.sdump());
  num=-432100; num+=567890; EXPECT_EQ("+2:126E<2>", num.sdump());
  num=-432100; num+=-567890; EXPECT_EQ("-F:4236<2>", num.sdump());
}

TEST(BignumTest, sub_eq_signed_int) // testing operator -=
{
  bignum num;
  num=0; num-=2; EXPECT_EQ("-2<1>", num.sdump());
  num=0; num-=-2; EXPECT_EQ("+2<1>", num.sdump());

  num=1; num-=2; EXPECT_EQ("-1<1>", num.sdump());
  num=1; num-=-2; EXPECT_EQ("+3<1>", num.sdump());
  num=-1; num-=2; EXPECT_EQ("-3<1>", num.sdump());
  num=-1; num-=-2; EXPECT_EQ("+1<1>", num.sdump());

  num=50000; num-=50000; EXPECT_EQ("+0<1>", num.sdump());
  num=50000; num-=-50000; EXPECT_EQ("+1:86A0<2>", num.sdump());
  num=-50000; num-=50000; EXPECT_EQ("-1:86A0<2>", num.sdump());
  num=-50000; num-=-50000; EXPECT_EQ("+0<1>", num.sdump());

  num=567890; num-=432100; EXPECT_EQ("+2:126E<2>", num.sdump());
  num=567890; num-=-432100; EXPECT_EQ("+F:4236<2>", num.sdump());
  num=-567890; num-=432100; EXPECT_EQ("-F:4236<2>", num.sdump());
  num=-567890; num-=-432100; EXPECT_EQ("-2:126E<2>", num.sdump());

  num=567890; num-=567889; EXPECT_EQ("+1<1>", num.sdump());
  num=567890; num-=-567889; EXPECT_EQ("+11:54A3<2>", num.sdump());
  num=-567890; num-=567889; EXPECT_EQ("-11:54A3<2>", num.sdump());
  num=-567890; num-=-567889; EXPECT_EQ("-1<1>", num.sdump());

  num=432100; num-=567890; EXPECT_EQ("-2:126E<2>", num.sdump());
  num=432100; num-=-567890; EXPECT_EQ("+F:4236<2>", num.sdump());
  num=-432100; num-=567890; EXPECT_EQ("-F:4236<2>", num.sdump());
  num=-432100; num-=-567890; EXPECT_EQ("+2:126E<2>", num.sdump());
}

TEST(BignumTest, mul_eq_signed_int) // testing operator *=
{
  bignum num;
  num=0; num*=2; EXPECT_EQ("+0<1>", num.sdump());
  num=0; num*=-2; EXPECT_EQ("+0<1>", num.sdump());

  num=1; num*=2; EXPECT_EQ("+2<1>", num.sdump());
  num=1; num*=-2; EXPECT_EQ("-2<1>", num.sdump());
  num=-1; num*=2; EXPECT_EQ("-2<1>", num.sdump());
  num=-1; num*=-2; EXPECT_EQ("+2<1>", num.sdump());

  num=3; num*=5; EXPECT_EQ("+F<1>", num.sdump());
  num=3; num*=-5; EXPECT_EQ("-F<1>", num.sdump());
  num=-3; num*=5; EXPECT_EQ("-F<1>", num.sdump());
  num=-3; num*=-5; EXPECT_EQ("+F<1>", num.sdump());

  num=1000; num*=1000; EXPECT_EQ("+F:4240<2>", num.sdump());
  num=1000; num*=-1000; EXPECT_EQ("-F:4240<2>", num.sdump());
  num=-1000; num*=1000; EXPECT_EQ("-F:4240<2>", num.sdump());
  num=-1000; num*=-1000; EXPECT_EQ("+F:4240<2>", num.sdump());
}

TEST(BignumTest, div_eq_signed_int) // testing operator /=
{
  bignum num;
  num=0; num/=2;
  EXPECT_EQ("+0<1>", num.sdump()); EXPECT_EQ(0, num.remainder());
  num=0; num/=-2;
  EXPECT_EQ("+0<1>", num.sdump()); //EXPECT_EQ(0, num.remainder());

  num=1; num/=2;
  EXPECT_EQ("+0<1>", num.sdump()); EXPECT_EQ(1, num.remainder());
  num=1; num/=-2;
  EXPECT_EQ("+0<1>", num.sdump()); //EXPECT_EQ(1, num.remainder());
  num=-1; num/=2;
  EXPECT_EQ("+0<1>", num.sdump()); //EXPECT_EQ(1, num.remainder());
  num=-1; num/=-2;
  EXPECT_EQ("+0<1>", num.sdump()); //EXPECT_EQ(1, num.remainder());

  num=13; num/=5;
  EXPECT_EQ("+2<1>", num.sdump()); EXPECT_EQ(3, num.remainder());
  num=13; num/=-5;
  EXPECT_EQ("-2<1>", num.sdump()); //EXPECT_EQ(3, num.remainder());
  num=-13; num/=5;
  EXPECT_EQ("-2<1>", num.sdump()); //EXPECT_EQ(3, num.remainder());
  num=-13; num/=-5;
  EXPECT_EQ("+2<1>", num.sdump()); //EXPECT_EQ(3, num.remainder());

  num=1000000; num/=1000;
  EXPECT_EQ("+3E8<1>", num.sdump()); EXPECT_EQ(0, num.remainder());
  num=1000000; num/=-1000;
  EXPECT_EQ("-3E8<1>", num.sdump()); EXPECT_EQ(0, num.remainder());
  num=-1000000; num/=1000;
  EXPECT_EQ("-3E8<1>", num.sdump()); EXPECT_EQ(0, num.remainder());
  num=-1000000; num/=-1000;
  EXPECT_EQ("+3E8<1>", num.sdump()); EXPECT_EQ(0, num.remainder());
}

TEST(BignumTest, add_eq_bignum) // +=
{
  bignum a, b;

  a=0, b=0; a+=b; EXPECT_EQ(0, a.to_i());
  a=0, b=2; a+=b; EXPECT_EQ(2, a.to_i());
  a=2, b=0; a+=b; EXPECT_EQ(2, a.to_i());

  a=1, b=2; a+=b; EXPECT_EQ(3, a.to_i());
  a=1, b=-2; a+=b; EXPECT_EQ(-1, a.to_i());
  a=-1, b=2; a+=b; EXPECT_EQ(1, a.to_i());
  a=-1, b=-2; a+=b; EXPECT_EQ(-3, a.to_i());

  a=50000, b=50000; a+=b; EXPECT_EQ(100000, a.to_i());
  a=50000, b=-50000; a+=b; EXPECT_EQ(0, a.to_i());
  a=-50000, b=50000; a+=b; EXPECT_EQ(0, a.to_i());
  a=-50000, b=-50000; a+=b; EXPECT_EQ(-100000, a.to_i());

  a=567890, b=432100; a+=b; EXPECT_EQ(999990, a.to_i());
  a=567890, b=-432100; a+=b; EXPECT_EQ(135790, a.to_i());
  a=-567890, b=432100; a+=b; EXPECT_EQ(-135790, a.to_i());
  a=-567890, b=-432100; a+=b; EXPECT_EQ(-999990, a.to_i());

  a=567890, b=567889; a+=b; EXPECT_EQ(1135779, a.to_i());
  a=567890, b=-567889; a+=b; EXPECT_EQ(1, a.to_i());
  a=-567890, b=567889; a+=b; EXPECT_EQ(-1, a.to_i());
  a=-567890, b=-567889; a+=b; EXPECT_EQ(-1135779, a.to_i());

  a=432100, b=567890; a+=b; EXPECT_EQ(999990, a.to_i());
  a=432100, b=-567890; a+=b; EXPECT_EQ(-135790, a.to_i());
  a=-432100, b=567890; a+=b; EXPECT_EQ(135790, a.to_i());
  a=-432100, b=-567890; a+=b; EXPECT_EQ(-999990, a.to_i());
}

TEST(BignumTest, mul_eq_bignum) // testing operator *=
{
  bignum a, b;

  a=0; b=0; a*=b; EXPECT_EQ(0, a.to_i());
  a=0; b=2; a*=b; EXPECT_EQ(0, a.to_i());
  a=2; b=0; a*=b; EXPECT_EQ(0, a.to_i());
  a=1; b=1; a*=b; EXPECT_EQ(1, a.to_i());
  a=1; b=2; a*=b; EXPECT_EQ(2, a.to_i());
  a=2; b=1; a*=b; EXPECT_EQ(2, a.to_i());
  a=2; b=2; a*=b; EXPECT_EQ(4, a.to_i());
  a=3; b=-2; a*=b; EXPECT_EQ(-6, a.to_i());
  a=-3; b=2; a*=b; EXPECT_EQ(-6, a.to_i());
  a=-3; b=-2; a*=b; EXPECT_EQ(6, a.to_i());

  a=10000; b=10000; a*=b; EXPECT_EQ(100000000, a.to_i());
  a=100000000; b=100000000; a*=b; EXPECT_EQ("10000000000000000", a.to_s());
  a=65535; b=65535; a*=b; EXPECT_EQ("FFFE0001", a.to_s(16));
  a=65536; b=65536; a*=b; EXPECT_EQ("100000000", a.to_s(16));
}

TEST(BignumTest, add) // +
{
  bignum a, b;

  a=0, b=0; EXPECT_EQ(0, (a+b).to_i());
  a=0, b=2; EXPECT_EQ(2, (a+b).to_i());
  a=2, b=0; EXPECT_EQ(2, (a+b).to_i());

  a=1, b=2; EXPECT_EQ(3, (a+b).to_i()); EXPECT_EQ(1, a.to_i()); EXPECT_EQ(2, b.to_i());
  a=1, b=-2; EXPECT_EQ(-1, (a+b).to_i());
  a=-1, b=2; EXPECT_EQ(1, (a+b).to_i());
  a=-1, b=-2; EXPECT_EQ(-3, (a+b).to_i());

  a=50000, b=50000; EXPECT_EQ(100000, (a+b).to_i());
  a=50000, b=-50000; EXPECT_EQ(0, (a+b).to_i());
  a=-50000, b=50000; EXPECT_EQ(0, (a+b).to_i());
  a=-50000, b=-50000; EXPECT_EQ(-100000, (a+b).to_i());

  a=567890, b=432100; EXPECT_EQ(999990, (a+b).to_i());
  a=567890, b=-432100; EXPECT_EQ(135790, (a+b).to_i());
  a=-567890, b=432100; EXPECT_EQ(-135790, (a+b).to_i());
  a=-567890, b=-432100; EXPECT_EQ(-999990, (a+b).to_i());

  a=567890, b=567889; EXPECT_EQ(1135779, (a+b).to_i());
  a=567890, b=-567889; EXPECT_EQ(1, (a+b).to_i());
  a=-567890, b=567889; EXPECT_EQ(-1, (a+b).to_i());
  a=-567890, b=-567889; EXPECT_EQ(-1135779, (a+b).to_i());

  a=432100, b=567890; EXPECT_EQ(999990, (a+b).to_i());
  a=432100, b=-567890; EXPECT_EQ(-135790, (a+b).to_i());
  a=-432100, b=567890; EXPECT_EQ(135790, (a+b).to_i());
  a=-432100, b=-567890; EXPECT_EQ(-999990, (a+b).to_i());
}

TEST(BignumTest, sub) // -
{
  bignum a, b;

  a=0, b=0; EXPECT_EQ(0, (a-b).to_i());
  a=0, b=2; EXPECT_EQ(-2, (a-b).to_i());
  a=2, b=0; EXPECT_EQ(2, (a-b).to_i());

  a=1, b=2; EXPECT_EQ(-1, (a-b).to_i()); EXPECT_EQ(1, a.to_i()); EXPECT_EQ(2, b.to_i());
  a=1, b=-2; EXPECT_EQ(3, (a-b).to_i());
  a=-1, b=2; EXPECT_EQ(-3, (a-b).to_i());
  a=-1, b=-2; EXPECT_EQ(1, (a-b).to_i());

  a=50000, b=50000; EXPECT_EQ(0, (a-b).to_i());
  a=50000, b=-50000; EXPECT_EQ(100000, (a-b).to_i());
  a=-50000, b=50000; EXPECT_EQ(-100000, (a-b).to_i());
  a=-50000, b=-50000; EXPECT_EQ(0, (a-b).to_i());

  a=567890, b=432100; EXPECT_EQ(135790, (a-b).to_i());
  a=567890, b=-432100; EXPECT_EQ(999990, (a-b).to_i());
  a=-567890, b=432100; EXPECT_EQ(-999990, (a-b).to_i());
  a=-567890, b=-432100; EXPECT_EQ(-135790, (a-b).to_i());

  a=567890, b=567889; EXPECT_EQ(1, (a-b).to_i());
  a=567890, b=-567889; EXPECT_EQ(1135779, (a-b).to_i());
  a=-567890, b=567889; EXPECT_EQ(-1135779, (a-b).to_i());
  a=-567890, b=-567889; EXPECT_EQ(-1, (a-b).to_i());

  a=432100, b=567890; EXPECT_EQ(-135790, (a-b).to_i());
  a=432100, b=-567890; EXPECT_EQ(999990, (a-b).to_i());
  a=-432100, b=567890; EXPECT_EQ(-999990, (a-b).to_i());
  a=-432100, b=-567890; EXPECT_EQ(135790, (a-b).to_i());

  a.set("H",36); b.set("H",36); EXPECT_EQ("0", (a-b).to_s(36));
  a.set("HZ",36); b.set("HE",36); EXPECT_EQ("L", (a-b).to_s(36));
  a.set("HZL",36); b.set("HEL",36); EXPECT_EQ("L0", (a-b).to_s(36));
  a.set("HZLO",36); b.set("HELO",36); EXPECT_EQ("L00", (a-b).to_s(36));
  a.set("HZLLO",36); b.set("HELLO",36); EXPECT_EQ("L000", (a-b).to_s(36));
}

TEST(BignumTest, mul) // *
{
  bignum a, b;

  a=0; b=0; EXPECT_EQ(0, (a*b).to_i());
  a=0; b=2; EXPECT_EQ(0, (a*b).to_i());
  a=2; b=0; EXPECT_EQ(0, (a*b).to_i());
  a=1; b=1; EXPECT_EQ(1, (a*b).to_i());
  a=1; b=2; EXPECT_EQ(2, (a*b).to_i());
  a=2; b=1; EXPECT_EQ(2, (a*b).to_i());
  a=2; b=2; EXPECT_EQ(4, (a*b).to_i());
  a=3; b=-2; EXPECT_EQ(-6, (a*b).to_i());
  a=-3; b=2; EXPECT_EQ(-6, (a*b).to_i());
  a=-3; b=-2; EXPECT_EQ(6, (a*b).to_i());

  a=10000; b=10000; EXPECT_EQ(100000000, (a*b).to_i());
  a=100000000; b=100000000; EXPECT_EQ("10000000000000000", (a*b).to_s());
  a=65535; b=65535; EXPECT_EQ("FFFE0001", (a*b).to_s(16));
  a=65536; b=65536; EXPECT_EQ("100000000", (a*b).to_s(16));
}

TEST(BignumTest, comparison) // == != < <= > >=
{
  bignum a, b;

  a= 0, b= 0;
  EXPECT_TRUE(a==b); EXPECT_FALSE(a!=b);
  EXPECT_FALSE(a>b); EXPECT_TRUE(a>=b); EXPECT_FALSE(a<b); EXPECT_TRUE(a<=b);
  a= 1, b= 1;
  EXPECT_TRUE(a==b); EXPECT_FALSE(a!=b);
  EXPECT_FALSE(a>b); EXPECT_TRUE(a>=b); EXPECT_FALSE(a<b); EXPECT_TRUE(a<=b);
  a=-1, b=-1;
  EXPECT_TRUE(a==b); EXPECT_FALSE(a!=b);
  EXPECT_FALSE(a>b); EXPECT_TRUE(a>=b); EXPECT_FALSE(a<b); EXPECT_TRUE(a<=b);
  a= 1, b=-1;
  EXPECT_FALSE(a==b); EXPECT_TRUE(a!=b);
  EXPECT_TRUE(a>b); EXPECT_TRUE(a>=b); EXPECT_FALSE(a<b); EXPECT_FALSE(a<=b);
  a=-1, b= 1;
  EXPECT_FALSE(a==b); EXPECT_TRUE(a!=b);
  EXPECT_FALSE(a>b); EXPECT_FALSE(a>=b); EXPECT_TRUE(a<b); EXPECT_TRUE(a<=b);
  a=1, b=0;
  EXPECT_FALSE(a==b); EXPECT_TRUE(a!=b);
  EXPECT_TRUE(a>b); EXPECT_TRUE(a>=b); EXPECT_FALSE(a<b); EXPECT_FALSE(a<=b);
  a=10000000, b=0;
  EXPECT_FALSE(a==b); EXPECT_TRUE(a!=b);
  EXPECT_TRUE(a>b); EXPECT_TRUE(a>=b); EXPECT_FALSE(a<b); EXPECT_FALSE(a<=b);
}

TEST(BignumTest, assign_by_string)
{
  bignum num;
  num.set(""); EXPECT_EQ(0, num.to_i());
  num.set("0"); EXPECT_EQ(0, num.to_i());

  num.set("1"); EXPECT_EQ(1, num.to_i());
  num.set("-1"); EXPECT_EQ(-1, num.to_i());

  num.set("111"); EXPECT_EQ(111, num.to_i());
  num.set("111",2); EXPECT_EQ(7, num.to_i());
  num.set("-111"); EXPECT_EQ(-111, num.to_i());
  num.set("-111",2); EXPECT_EQ(-7, num.to_i());

  num.set("12"); EXPECT_EQ(12, num.to_i());
  num.set("-12"); EXPECT_EQ(-12, num.to_i());

  num.set("12",16); EXPECT_EQ(18, num.to_i());
  num.set("-12",16); EXPECT_EQ(-18, num.to_i());

  num.set("ZZ",36); EXPECT_EQ(1295, num.to_i());
  num.set("-ZZ",36); EXPECT_EQ(-1295, num.to_i());
}

int main(int argc, char** argv)
{
  testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}
