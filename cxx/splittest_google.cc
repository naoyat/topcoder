#include "split.cc"
#include <gtest/gtest.h>

// テストケースを単体の関数として実装する
TEST(SplitTest, Split1)
{
  vector<string> result;

  result = split("", "<>");
  EXPECT_EQ( 1, result.size() );
  
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

TEST(SplitTest, Split2)
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

int main(int argc, char** argv)
{
  testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}
