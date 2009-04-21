#include "split.cc"
#include <cxxtest/TestSuite.h>

class splittest_cxxtest : public CxxTest::TestSuite
{
 public:
  void setUp() {} // mkdir( "playground" ); }
  void tearDown() {} // system( "rm -Rf playground"); }
  //	TS_ASSERT( 1 + 1 > 1 );
  //	TS_ASSERT_EQUALS( 1 + 1, 2 );

  void testSplit1( void )
  {
	vector<string> result;
	
	result = split("", "<>");
	TS_ASSERT_EQUALS( 10, result.size() );
	
	// "a","<>" => ["a"]
	result = split("a", "<>");
	TS_ASSERT_EQUALS( 1, result.size() );
	TS_ASSERT_EQUALS( "a", result[0] );
	
	// "a<>b<>c","<>" => ["a","b","c"]
	result = split("a<>b<>c", "<>");
	TS_ASSERT_EQUALS( 3, result.size() );
	TS_ASSERT_EQUALS( "a", result[0] );
	TS_ASSERT_EQUALS( "b", result[1] );
	TS_ASSERT_EQUALS( "c", result[2] );
	
	// "a<>b<>c<>","<>" => ["a","b","c",""]
	result = split("a<>b<>c<>", "<>");
	TS_ASSERT_EQUALS( 4, result.size() );
	TS_ASSERT_EQUALS( "a", result[0] );
	TS_ASSERT_EQUALS( "b", result[1] );
	TS_ASSERT_EQUALS( "c", result[2] );
	TS_ASSERT_EQUALS( "" , result[3] );
	
	// "<>a<>b<>c","<>" => ["","a","b","c"]
	result = split("<>a<>b<>c", "<>");
	TS_ASSERT_EQUALS( 4, result.size() );
	TS_ASSERT_EQUALS( "" , result[0] );
	TS_ASSERT_EQUALS( "a", result[1] );
	TS_ASSERT_EQUALS( "b", result[2] );
	TS_ASSERT_EQUALS( "c", result[3] );
	
	// "<>a<>","<>" => ["","a",""]
	result = split("<>a<>", "<>");
	TS_ASSERT_EQUALS( 3, result.size() );
	TS_ASSERT_EQUALS( "" , result[0] );
	TS_ASSERT_EQUALS( "a", result[1] );
	TS_ASSERT_EQUALS( "" , result[2] );
  
	// "a<><>b","<>" => ["a","","b"]
	result = split("a<><>b", "<>");
	TS_ASSERT_EQUALS( 3, result.size() );
	TS_ASSERT_EQUALS( "a", result[0] );
	TS_ASSERT_EQUALS( "" , result[1] );
	TS_ASSERT_EQUALS( "b", result[2] );
	
	// "<>","<>" => ["",""]
	result = split("<>", "<>");
	TS_ASSERT_EQUALS( 2, result.size() );
	TS_ASSERT_EQUALS( "", result[0] );
	TS_ASSERT_EQUALS( "", result[1] );
	//
	result = split("", "");
	TS_ASSERT_EQUALS( 0, result.size() );
	
	// 特殊用法 "abc".split('')
	result = split("abc", "");
	TS_ASSERT_EQUALS( 3, result.size() );
	TS_ASSERT_EQUALS( "a", result[0] );
	TS_ASSERT_EQUALS( "b", result[1] );
	TS_ASSERT_EQUALS( "c", result[2] );
	// EXPECT_TRUE_EQUAL( 2, 2 );
  }
  
  void testSplit2( void )
  {
	// cout << "test_split()" << endl;
	// dump_vs(result);
	vector<string> result;
	
	// "" => []
	result = split("");
	TS_ASSERT_EQUALS( 0, result.size() );
	// "a" => ["a"]
	result = split("a");
	TS_ASSERT_EQUALS( 1, result.size() );
	TS_ASSERT_EQUALS( "a", result[0] );
	// "a b c" => ["a","b","c"]
	result = split("a b c");
	TS_ASSERT_EQUALS( 3, result.size() );
	TS_ASSERT_EQUALS( "a", result[0] );
	TS_ASSERT_EQUALS( "b", result[1] );
	TS_ASSERT_EQUALS( "c", result[2] );
	// "a " => ["a"]
	result = split("a ");
	TS_ASSERT_EQUALS( 1, result.size() );
	TS_ASSERT_EQUALS( "a", result[0] );
	// " a" => ["a"]
	result = split(" a");
	TS_ASSERT_EQUALS( 1, result.size() );
	TS_ASSERT_EQUALS( "a", result[0] );
	// " a " => ["a"]
	result = split(" a ");
	TS_ASSERT_EQUALS( 1, result.size() );
	TS_ASSERT_EQUALS( "a", result[0] );
	// "a b" => ["a","b"]
	result = split("a b");
	TS_ASSERT_EQUALS( 2, result.size() );
	TS_ASSERT_EQUALS( "a", result[0] );
	TS_ASSERT_EQUALS( "b", result[1] );
	// "a  b" => ["a","b"]
	result = split("a  b");
	TS_ASSERT_EQUALS( 2, result.size() );
	TS_ASSERT_EQUALS( "a", result[0] );
	TS_ASSERT_EQUALS( "b", result[1] );
	
	// "a b c",'b' => ["a "," c"]
	result = split("a b c",'b');
	TS_ASSERT_EQUALS( 2, result.size() );
	TS_ASSERT_EQUALS( "a ", result[0] );
	TS_ASSERT_EQUALS( " c", result[1] );
	
	// "a,b",',' => ["a","b"]
	result = split("a,b", ',');
	TS_ASSERT_EQUALS( 2, result.size() );
	TS_ASSERT_EQUALS( "a", result[0] );
	TS_ASSERT_EQUALS( "b", result[1] );
	// "a,,b",',' => ["a","","b"]
	result = split("a,,b", ',');
	TS_ASSERT_EQUALS( 3, result.size() );
	TS_ASSERT_EQUALS( "a", result[0] );
	TS_ASSERT_EQUALS( "" , result[1] );
	TS_ASSERT_EQUALS( "b", result[2] );
	// ",a",',' => ["","a"]
	result = split(",a", ',');
	TS_ASSERT_EQUALS( 2, result.size() );
	TS_ASSERT_EQUALS( "" , result[0] );
	TS_ASSERT_EQUALS( "a", result[1] );
	// "a,",',' => ["a",""]
	result = split("a,", ',');
	TS_ASSERT_EQUALS( 2, result.size() );
	TS_ASSERT_EQUALS( "a", result[0] );
	TS_ASSERT_EQUALS( "" , result[1] );
	// ",a,",',' => ["","a",""]
	result = split(",a,", ',');
	TS_ASSERT_EQUALS( 3, result.size() );
	TS_ASSERT_EQUALS( "" , result[0] );
	TS_ASSERT_EQUALS( "a", result[1] );
	TS_ASSERT_EQUALS( "" , result[2] );
  }
  
  void testMapAtoi( void )
  {
	vector<string> as(3);//({"1","2","3"});
	as[0] = "1"; as[1] = "2"; as[2] = "3";
	vector<int> is = map_atoi(as);
	TS_ASSERT_EQUALS( is.size(), as.size() );
	TS_ASSERT_EQUALS( 1, is[0] );
	TS_ASSERT_EQUALS( 2, is[1] );
	TS_ASSERT_EQUALS( 3, is[2] );
  }

  void testSplitAtoi( void )
  {
	vector<int> is = map_atoi( split("2 3 5 7 11 13") );
	TS_ASSERT_EQUALS( 6, is.size() );
	TS_ASSERT_EQUALS( 2, is[0] );
	TS_ASSERT_EQUALS( 3, is[1] );
	TS_ASSERT_EQUALS( 5, is[2] );
	TS_ASSERT_EQUALS( 7, is[3] );
	TS_ASSERT_EQUALS( 11, is[4] );
	TS_ASSERT_EQUALS( 13, is[5] );
  }
};

