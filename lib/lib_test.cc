using namespace std;

#include "cout.h"

#include "lib.h"
#include <gtest/gtest.h>

TEST(LIST, remove_)
{
}

TEST(MATH, c)
{
}
TEST(MATH, combinations)
{
}
TEST(MATH, gcd)
{
}
TEST(MATH, lcm)
{
}
TEST(MATH, expt)
{
  // 累乗
  // 0^n
  // EXPECT_EQ(1, expt(0,0)); // これは単に実装的な仕様
  EXPECT_EQ(0, expt(0,1));
  EXPECT_EQ(0, expt(0,2));
  // 1^n
  EXPECT_EQ(1, expt(1,0));
  EXPECT_EQ(1, expt(1,1));
  EXPECT_EQ(1, expt(1,2));
  // 2^n
  EXPECT_EQ(1, expt(2,0));
  EXPECT_EQ(2, expt(2,1));
  EXPECT_EQ(4, expt(2,2));
  EXPECT_EQ(65536, expt(2,16));
  EXPECT_EQ(1073741824, expt(2,30));
  // int
  EXPECT_EQ(-2147483648, expt(2,31));
  // unsigned int
  EXPECT_EQ(2147483648u, expt(2u,31));
  // long long
  EXPECT_EQ(2147483648LL, expt(2LL,31));
}
TEST(MATH, factorial)
{
  // 階乗
  EXPECT_EQ(1, factorial(1));
  EXPECT_EQ(2, factorial(2));
  EXPECT_EQ(6, factorial(3));
  EXPECT_EQ(24, factorial(4));
  EXPECT_EQ(120, factorial(5));
  EXPECT_EQ(720, factorial(6));
}

TEST(BINARY, to_bin)
{
}
TEST(BINARY, bin_to_num)
{
}
TEST(BINARY, binstr)
{
  EXPECT_EQ("0", binstr(0));
  EXPECT_EQ("0", binstr(0,1));
  EXPECT_EQ("00", binstr(0,2));
  EXPECT_EQ("000", binstr(0,3));

  EXPECT_EQ("1", binstr(1));
  EXPECT_EQ("1", binstr(1,1));
  EXPECT_EQ("01", binstr(1,2));
  EXPECT_EQ("001", binstr(1,3));

  EXPECT_EQ("10", binstr(2));
  EXPECT_EQ("10", binstr(2,1));
  EXPECT_EQ("10", binstr(2,2));
  EXPECT_EQ("010", binstr(2,3));
}

TEST(PRIME, fast_prime)
{
  // not enough
  EXPECT_EQ(false, fast_prime(0));
  EXPECT_EQ(false, fast_prime(1));
  EXPECT_EQ(true, fast_prime(2));
  EXPECT_EQ(true, fast_prime(3));
  EXPECT_EQ(false, fast_prime(4));
}

TEST(STRING, to_lower)
{
  EXPECT_EQ("",to_lower(""));
  EXPECT_EQ("abc",to_lower("abc"));
  EXPECT_EQ("abc",to_lower("Abc"));
  EXPECT_EQ("abc",to_lower("aBc"));
  EXPECT_EQ("abc",to_lower("abC"));
  EXPECT_EQ("abc",to_lower("ABC"));
}
TEST(STRING, to_upper)
{
  EXPECT_EQ("",to_upper(""));
  EXPECT_EQ("ABC",to_upper("abc"));
  EXPECT_EQ("ABC",to_upper("Abc"));
  EXPECT_EQ("ABC",to_upper("aBc"));
  EXPECT_EQ("ABC",to_upper("abC"));
  EXPECT_EQ("ABC",to_upper("ABC"));
}

TEST(GEOMETRY, turn)
{
  pair<int,int>
      o = make_pair(0,0),
      d0 = make_pair(1,0),
      d1 = make_pair(0,1),
      d2 = make_pair(-1,0),
      d3 = make_pair(0,-1);

  // 正常系
  EXPECT_EQ(d3, turn(d0,-450));
  EXPECT_EQ(d0, turn(d0,-360));
  EXPECT_EQ(d1, turn(d0,-270));
  EXPECT_EQ(d2, turn(d0,-180));
  EXPECT_EQ(d3, turn(d0,-90));
  EXPECT_EQ(d0, turn(d0,0));
  EXPECT_EQ(d1, turn(d0,90));
  EXPECT_EQ(d2, turn(d0,180));
  EXPECT_EQ(d3, turn(d0,270));
  EXPECT_EQ(d0, turn(d0,360));
  EXPECT_EQ(d1, turn(d0,450));

  EXPECT_EQ(d0, turn(d1,-450));
  EXPECT_EQ(d1, turn(d1,-360));
  EXPECT_EQ(d2, turn(d1,-270));
  EXPECT_EQ(d3, turn(d1,-180));
  EXPECT_EQ(d0, turn(d1,-90));
  EXPECT_EQ(d1, turn(d1,0));
  EXPECT_EQ(d2, turn(d1,90));
  EXPECT_EQ(d3, turn(d1,180));
  EXPECT_EQ(d0, turn(d1,270));
  EXPECT_EQ(d1, turn(d1,360));
  EXPECT_EQ(d2, turn(d1,450));

  EXPECT_EQ(d1, turn(d2,-450));
  EXPECT_EQ(d2, turn(d2,-360));
  EXPECT_EQ(d3, turn(d2,-270));
  EXPECT_EQ(d0, turn(d2,-180));
  EXPECT_EQ(d1, turn(d2,-90));
  EXPECT_EQ(d2, turn(d2,0));
  EXPECT_EQ(d3, turn(d2,90));
  EXPECT_EQ(d0, turn(d2,180));
  EXPECT_EQ(d1, turn(d2,270));
  EXPECT_EQ(d2, turn(d2,360));
  EXPECT_EQ(d3, turn(d2,450));

  EXPECT_EQ(d2, turn(d3,-450));
  EXPECT_EQ(d3, turn(d3,-360));
  EXPECT_EQ(d0, turn(d3,-270));
  EXPECT_EQ(d1, turn(d3,-180));
  EXPECT_EQ(d2, turn(d3,-90));
  EXPECT_EQ(d3, turn(d3,0));
  EXPECT_EQ(d0, turn(d3,90));
  EXPECT_EQ(d1, turn(d3,180));
  EXPECT_EQ(d2, turn(d3,270));
  EXPECT_EQ(d3, turn(d3,360));
  EXPECT_EQ(d0, turn(d3,450));

  // 異常系
  EXPECT_EQ(d0, turn(d0,199));
  EXPECT_EQ(d1, turn(d1,199));
  EXPECT_EQ(d2, turn(d2,199));
  EXPECT_EQ(d3, turn(d3,199));

  // (0,0)
  EXPECT_EQ(o, turn(o,0));
  EXPECT_EQ(o, turn(o,90));
  EXPECT_EQ(o, turn(o,180));
  EXPECT_EQ(o, turn(o,270));
}

int main(int argc, char** argv)
{
  testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}
