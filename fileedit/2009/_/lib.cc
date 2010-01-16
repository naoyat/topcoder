#include <iostream>
using namespace std;
#include <gtest/gtest.h>

int c(int n, int r)
{
  if (n == 0 || r == 0 || r == n) return 1;
  if (r > n-r) r = n-r;
  return n * c(n-1,r-1) / r;
}

TEST(CombinationTest, 0Cr)
{
  EXPECT_EQ( 1, c(0,0) );
}
TEST(CombinationTest, 1Cr)
{
  EXPECT_EQ( 1, c(1,0) );
  EXPECT_EQ( 1, c(1,1) );
}
TEST(CombinationTest, 2Cr)
{
  EXPECT_EQ( 1, c(2,0) );
  EXPECT_EQ( 2, c(2,1) );
  EXPECT_EQ( 1, c(2,2) );
}
TEST(CombinationTest, 3Cr)
{
  EXPECT_EQ( 1, c(3,0) );
  EXPECT_EQ( 3, c(3,1) );
  EXPECT_EQ( 3, c(3,2) );
  EXPECT_EQ( 1, c(3,3) );
}
TEST(CombinationTest, 4Cr)
{
  EXPECT_EQ( 1, c(4,0) );
  EXPECT_EQ( 4, c(4,1) );
  EXPECT_EQ( 6, c(4,2) );
  EXPECT_EQ( 4, c(4,3) );
  EXPECT_EQ( 1, c(4,4) );
}
TEST(CombinationTest, 5Cr)
{
  EXPECT_EQ( 1, c(5,0) );
  EXPECT_EQ( 5, c(5,1) );
  EXPECT_EQ( 10, c(5,2) );
  EXPECT_EQ( 10, c(5,3) );
  EXPECT_EQ( 5, c(5,4) );
  EXPECT_EQ( 1, c(5,5) );
}
TEST(CombinationTest, xCr)
{
  EXPECT_EQ( 252, c(10,5) );
  // EXPECT_EQ( 20744505, c(100,50) );
  // EXPECT_EQ( 100*99*98*20744505, c(100,50) );
  // 8*9*11*13*17*19*53*59*61*67*71*73*79*83*87*89*93*97
}

int main(int argc, char** argv)
{
  testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}

