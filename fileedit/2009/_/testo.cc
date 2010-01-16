#include <vector>
#include <string>
#include <iostream>
using namespace std;

#include "lib.h"
#include "split.h"

#include <gtest/gtest.h>

///////////
TEST(SplitTest, 1)
{
  vector<string> result;

  result = split("", "<>");
  EXPECT_EQ( 0, result.size() ); //?
  
  // "a","<>" => ["a"]
  result = split("a", "<>");
  EXPECT_EQ( 1, result.size() );
  EXPECT_EQ( "a", result[0] );
  
  // "a<>b<>c","<>" => ["a","b","c"]
  result = split("a<>b<>c", "<>");
  EXPECT_EQ( 3, result.size() );
  EXPECT_EQ( "a", result[0] );
  EXPECT_EQ( "b", result[1] );
  EXPECT_EQ( "c", result[2] );
  
  // "a<>b<>c<>","<>" => ["a","b","c",""]
  result = split("a<>b<>c<>", "<>");
  EXPECT_EQ( 4, result.size() );
  EXPECT_EQ( "a", result[0] );
  EXPECT_EQ( "b", result[1] );
  EXPECT_EQ( "c", result[2] );
  EXPECT_EQ( "" , result[3] );
  
  // "<>a<>b<>c","<>" => ["","a","b","c"]
  result = split("<>a<>b<>c", "<>");
  EXPECT_EQ( 4, result.size() );
  EXPECT_EQ( "" , result[0] );
  EXPECT_EQ( "a", result[1] );
  EXPECT_EQ( "b", result[2] );
  EXPECT_EQ( "c", result[3] );
  
  // "<>a<>","<>" => ["","a",""]
  result = split("<>a<>", "<>");
  EXPECT_EQ( 3, result.size() );
  EXPECT_EQ( "" , result[0] );
  EXPECT_EQ( "a", result[1] );
  EXPECT_EQ( "" , result[2] );
  
  // "a<><>b","<>" => ["a","","b"]
  result = split("a<><>b", "<>");
  EXPECT_EQ( 3, result.size() );
  EXPECT_EQ( "a", result[0] );
  EXPECT_EQ( "" , result[1] );
  EXPECT_EQ( "b", result[2] );
  
  // "<>","<>" => ["",""]
  result = split("<>", "<>");
  EXPECT_EQ( 2, result.size() );
  EXPECT_EQ( "", result[0] );
  EXPECT_EQ( "", result[1] );
  //
  result = split("", "");
  EXPECT_EQ( 0, result.size() );
  
  // 特殊用法 "abc".split('')
  result = split("abc", "");
  EXPECT_EQ( 3, result.size() );
  EXPECT_EQ( "a", result[0] );
  EXPECT_EQ( "b", result[1] );
  EXPECT_EQ( "c", result[2] );
  // EXPECT_TRUE_EQUAL( 2, 2 );
}

TEST(SplitTest, 2)
{
  // cout << "test_split()" << endl;
  // dump_vs(result);
  vector<string> result;

  // "" => []
  result = split("");
  EXPECT_EQ( 0, result.size() );
  // "a" => ["a"]
  result = split("a");
  EXPECT_EQ( 1, result.size() );
  EXPECT_EQ( "a", result[0] );
  // "a b c" => ["a","b","c"]
  result = split("a b c");
  EXPECT_EQ( 3, result.size() );
  EXPECT_EQ( "a", result[0] );
  EXPECT_EQ( "b", result[1] );
  EXPECT_EQ( "c", result[2] );
  // "a " => ["a"]
  result = split("a ");
  EXPECT_EQ( 1, result.size() );
  EXPECT_EQ( "a", result[0] );
  // " a" => ["a"]
  result = split(" a");
  EXPECT_EQ( 1, result.size() );
  EXPECT_EQ( "a", result[0] );
  // " a " => ["a"]
  result = split(" a ");
  EXPECT_EQ( 1, result.size() );
  EXPECT_EQ( "a", result[0] );
  // "a b" => ["a","b"]
  result = split("a b");
  EXPECT_EQ( 2, result.size() );
  EXPECT_EQ( "a", result[0] );
  EXPECT_EQ( "b", result[1] );
  // "a  b" => ["a","b"]
  result = split("a  b");
  EXPECT_EQ( 2, result.size() );
  EXPECT_EQ( "a", result[0] );
  EXPECT_EQ( "b", result[1] );
  
  // "a b c",'b' => ["a "," c"]
  result = split("a b c",'b');
  EXPECT_EQ( 2, result.size() );
  EXPECT_EQ( "a ", result[0] );
  EXPECT_EQ( " c", result[1] );
  
  // "a,b",',' => ["a","b"]
  result = split("a,b", ',');
  EXPECT_EQ( 2, result.size() );
  EXPECT_EQ( "a", result[0] );
  EXPECT_EQ( "b", result[1] );
  // "a,,b",',' => ["a","","b"]
  result = split("a,,b", ',');
  EXPECT_EQ( 3, result.size() );
  EXPECT_EQ( "a", result[0] );
  EXPECT_EQ( "" , result[1] );
  EXPECT_EQ( "b", result[2] );
  // ",a",',' => ["","a"]
  result = split(",a", ',');
  EXPECT_EQ( 2, result.size() );
  EXPECT_EQ( "" , result[0] );
  EXPECT_EQ( "a", result[1] );
  // "a,",',' => ["a",""]
  result = split("a,", ',');
  EXPECT_EQ( 2, result.size() );
  EXPECT_EQ( "a", result[0] );
  EXPECT_EQ( "" , result[1] );
  // ",a,",',' => ["","a",""]
  result = split(",a,", ',');
  EXPECT_EQ( 3, result.size() );
  EXPECT_EQ( "" , result[0] );
  EXPECT_EQ( "a", result[1] );
  EXPECT_EQ( "" , result[2] );
}

TEST(SplitTest, MapAtoi)
{
  vector<string> as(3);//({"1","2","3"});
  as[0] = "1"; as[1] = "2"; as[2] = "3";
  vector<int> is = map_atoi(as);
  EXPECT_EQ( is.size(), as.size() );
  EXPECT_EQ( 1, is[0] );
  EXPECT_EQ( 2, is[1] );
  EXPECT_EQ( 3, is[2] );
}
TEST(SplitTest, SplitAtoi)
{
  vector<int> is = map_atoi( split("2 3 5 7 11 13") );
  EXPECT_EQ( 6, is.size() );
  EXPECT_EQ( 2, is[0] );
  EXPECT_EQ( 3, is[1] );
  EXPECT_EQ( 5, is[2] );
  EXPECT_EQ( 7, is[3] );
  EXPECT_EQ( 11, is[4] );
  EXPECT_EQ( 13, is[5] );
}

///////////
TEST(nCrTest, 0Cr)
{
  EXPECT_EQ( 1, c(0,0) );
}
TEST(nCrTest, 1Cr)
{
  EXPECT_EQ( 1, c(1,0) );
  EXPECT_EQ( 1, c(1,1) );
}
TEST(nCrTest, 2Cr)
{
  EXPECT_EQ( 1, c(2,0) );
  EXPECT_EQ( 2, c(2,1) );
  EXPECT_EQ( 1, c(2,2) );
}
TEST(nCrTest, 3Cr)
{
  EXPECT_EQ( 1, c(3,0) );
  EXPECT_EQ( 3, c(3,1) );
  EXPECT_EQ( 3, c(3,2) );
  EXPECT_EQ( 1, c(3,3) );
}
TEST(nCrTest, 4Cr)
{
  EXPECT_EQ( 1, c(4,0) );
  EXPECT_EQ( 4, c(4,1) );
  EXPECT_EQ( 6, c(4,2) );
  EXPECT_EQ( 4, c(4,3) );
  EXPECT_EQ( 1, c(4,4) );
}
TEST(nCrTest, 5Cr)
{
  EXPECT_EQ( 1, c(5,0) );
  EXPECT_EQ( 5, c(5,1) );
  EXPECT_EQ( 10, c(5,2) );
  EXPECT_EQ( 10, c(5,3) );
  EXPECT_EQ( 5, c(5,4) );
  EXPECT_EQ( 1, c(5,5) );
}
TEST(nCrTest, xCr)
{
  EXPECT_EQ( 252, c(10,5) );
  // EXPECT_EQ( 20744505, c(100,50) );
  // EXPECT_EQ( 100*99*98*20744505, c(100,50) );
  // 8*9*11*13*17*19*53*59*61*67*71*73*79*83*87*89*93*97
}

///////////
TEST(CombinationTest, 10)
{
  int n = 10, r = 5;
  vector<int> data(n); for (int i=0;i<n;i++) data[i] = i+1;

  vector<vector<int> > cs;
  cs = combinations(data, 0);
  EXPECT_EQ( 1, cs.size() ); // C(10,0)
  cs = combinations(data, 1);
  EXPECT_EQ( 10, cs.size() ); // C(10,1)
  cs = combinations(data, 2);
  EXPECT_EQ( 45, cs.size() ); // C(10,2)
  cs = combinations(data, 3);
  EXPECT_EQ( 120, cs.size() ); // C(10,3)
  cs = combinations(data, 4);
  EXPECT_EQ( 210, cs.size() ); // C(10,4)
  cs = combinations(data, 5);
  EXPECT_EQ( 252, cs.size() ); // C(10,5)

  EXPECT_EQ( 6, cs[c(n,r)-1][0] ); // [6,7,8,9,10]
}

///////////
///////////
int main(int argc, char** argv)
{
  testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}

