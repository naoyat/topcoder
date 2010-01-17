#include <gtest/gtest.h>
#include "Bits.h"
//#include <string>
//using namespace std;

TEST(Bits,ctor)
{
  Bits z(1), a(3,1), b(5,1), c(7,0), d(9), e(11,1);

  EXPECT_EQ("0", z.desc() );
  EXPECT_EQ("111", a.desc() );
  EXPECT_EQ("11111", b.desc() );
  EXPECT_EQ("0000000", c.desc() );
  EXPECT_EQ("000000000", d.desc() );
  EXPECT_EQ("11111111111", e.desc() );
}

TEST(Bits,set)
{
  Bits a(10);
  EXPECT_EQ("0000000000", a.desc() );
  for (int i=0; i<10; i+=2) a.set(i);
  EXPECT_EQ("1010101010", a.desc() );
  for (int i=0; i<10; i+=3) a.unset(i);
  EXPECT_EQ("0010100010", a.desc() );
  for (int i=0; i<10; i+=5) a.set(i,1);
  EXPECT_EQ("1010110010", a.desc() );
  for (int i=0; i<10; i+=2) a.set(i,0);
  EXPECT_EQ("0000010000", a.desc() );
}

TEST(Bits,and)
{
  Bits a(10), b(10);
  for (int i=0; i<10; i+=2) a.set(i);
  EXPECT_EQ("1010101010", a.desc() );
  for (int i=0; i<10; i+=3) b.set(i);
  EXPECT_EQ("1001001001", b.desc() );

  Bits a_and_b = a & b;
  EXPECT_EQ("1000001000", a_and_b.desc() );
  // a, b が不変であること
  EXPECT_EQ("1010101010", a.desc() );
  EXPECT_EQ("1001001001", b.desc() );

  a &= b;
  EXPECT_EQ("1000001000", a.desc() );
}

TEST(Bits,or)
{
  Bits a(10), b(10);
  for (int i=0; i<10; i+=2) a.set(i);
  EXPECT_EQ("1010101010", a.desc() );
  for (int i=0; i<10; i+=3) b.set(i);
  EXPECT_EQ("1001001001", b.desc() );

  Bits a_or_b = a | b;
  EXPECT_EQ("1011101011", a_or_b.desc() );
  // a, b が不変であること
  EXPECT_EQ("1010101010", a.desc() );
  EXPECT_EQ("1001001001", b.desc() );

  a |= b;
  EXPECT_EQ("1011101011", a.desc() );
}

TEST(Bits,xor)
{
  Bits a(10), b(10);
  for (int i=0; i<10; i+=2) a.set(i);
  EXPECT_EQ("1010101010", a.desc() );
  for (int i=0; i<10; i+=3) b.set(i);
  EXPECT_EQ("1001001001", b.desc() );

  Bits a_xor_b = a ^ b;
  EXPECT_EQ("0011100011", a_xor_b.desc() );
  // a, b が不変であること
  EXPECT_EQ("1010101010", a.desc() );
  EXPECT_EQ("1001001001", b.desc() );

  a ^= b;
  EXPECT_EQ("0011100011", a.desc() );
}

TEST(Bits,not)
{
  Bits a(10), b(10);
  for (int i=0; i<10; i+=2) a.set(i);
  EXPECT_EQ("1010101010", a.desc() );
  for (int i=0; i<10; i+=3) b.set(i);
  EXPECT_EQ("1001001001", b.desc() );

  Bits not_a = ~a, not_b = ~b;
  EXPECT_EQ("0101010101", not_a.desc() );
  EXPECT_EQ("0110110110", not_b.desc() );
}

TEST(Bits,concat)
{
  Bits a(10), b(10);
  for (int i=0; i<10; i+=2) a.set(i);
  EXPECT_EQ("1010101010", a.desc() );
  for (int i=0; i<10; i+=3) b.set(i);
  EXPECT_EQ("1001001001", b.desc() );

  Bits a_b = a + b, b_a = b + a;
  EXPECT_EQ("10101010101001001001", a_b.desc() );
  EXPECT_EQ("10010010011010101010", b_a.desc() );
  // a, b が不変であること
  EXPECT_EQ("1010101010", a.desc() );
  EXPECT_EQ("1001001001", b.desc() );

  a += b;
  EXPECT_EQ("10101010101001001001", a.desc() );
}

TEST(Bits,count)
{
  Bits a(10), b(10);
  for (int i=0; i<10; i+=2) a.set(i);
  // EXPECT_EQ("1010101010", a.desc() );
  for (int i=0; i<10; i+=3) b.set(i);
  // EXPECT_EQ("1001001001", b.desc() );

  EXPECT_EQ(10, a.size());
  EXPECT_EQ(10, b.size());

  Bits c1(1,1), c2(2,1), c3(3,1), c4(4,1), c5(5,1), c6(6,1), c7(7,1), c8(8,1), c9(9,1), d(2401,1);
  EXPECT_EQ(1, c1.size());
  EXPECT_EQ(2, c2.size());
  EXPECT_EQ(3, c3.size());
  EXPECT_EQ(4, c4.size());
  EXPECT_EQ(5, c5.size());
  EXPECT_EQ(6, c6.size());
  EXPECT_EQ(7, c7.size());
  EXPECT_EQ(8, c8.size());
  EXPECT_EQ(9, c9.size());
  EXPECT_EQ(2401, d.size());
}

TEST(Bits,popcount)
{
  Bits a(10), b(10);
  for (int i=0; i<10; i+=2) a.set(i);
  //EXPECT_EQ("1010101010", a.desc() );
  for (int i=0; i<10; i+=3) b.set(i);
  //EXPECT_EQ("1001001001", b.desc() );

  EXPECT_EQ(5, a.popcount());
  EXPECT_EQ(4, b.popcount());

  Bits c1(1,1), c2(2,1), c3(3,1), c4(4,1), c5(5,1), c6(6,1), c7(7,1), c8(8,1), c9(9,1), d(2401,1);
  EXPECT_EQ(1, c1.popcount());
  EXPECT_EQ(2, c2.popcount());
  EXPECT_EQ(3, c3.popcount());
  EXPECT_EQ(4, c4.popcount());
  EXPECT_EQ(5, c5.popcount());
  EXPECT_EQ(6, c6.popcount());
  EXPECT_EQ(7, c7.popcount());
  EXPECT_EQ(8, c8.popcount());
  EXPECT_EQ(9, c9.popcount());
  EXPECT_EQ(2401, d.popcount());
}





int main(int argc, char** argv)
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
