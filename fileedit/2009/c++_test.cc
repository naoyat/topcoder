using namespace std;

#include "cout.h"

#include <gtest/gtest.h>

TEST(PRELUDE, mod)
{
  EXPECT_EQ(1, 5%4);
  EXPECT_EQ(0, 4%4);
  EXPECT_EQ(3, 3%4);
  EXPECT_EQ(2, 2%4);
  EXPECT_EQ(1, 1%4);
  EXPECT_EQ(0, 0%4);
  EXPECT_EQ(-1, -1%4);
  EXPECT_EQ(-2, -2%4);
  EXPECT_EQ(-3, -3%4);
  EXPECT_EQ(0, -4%4);
  EXPECT_EQ(-1, -5%4);

  EXPECT_EQ(0, (unsigned)0%4);
  EXPECT_EQ(3, (unsigned)-1%4);
  EXPECT_EQ(2, (unsigned)-2%4);
  EXPECT_EQ(1, (unsigned)-3%4);
  EXPECT_EQ(0, (unsigned)-4%4);
  EXPECT_EQ(3, (unsigned)-5%4);
}

int main(int argc, char** argv)
{
  testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}

