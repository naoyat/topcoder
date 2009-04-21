#include "split.cc"
// #include <boost/unit_test_suite.hpp>
#include <boost/test/unit_test.hpp>
using namespace boost::unit_test_framework;

// テストケースを単体の関数として実装する
void test_split1()
{
  vector<string> result;

  result = split("", "<>");
  BOOST_CHECK( result.size() == 0);
  
  // "a","<>" => ["a"]
  result = split("a", "<>");
  BOOST_CHECK( result.size() == 1);
  BOOST_CHECK( result[0] == "a");
  BOOST_CHECK_EQUAL( 1, result.size() );
  BOOST_CHECK_EQUAL( "a", result[0] );
  
  // "a<>b<>c","<>" => ["a","b","c"]
  result = split("a<>b<>c", "<>");
  BOOST_CHECK( result.size() == 3);
  BOOST_CHECK( result[0] == "a");
  BOOST_CHECK( result[1] == "b");
  BOOST_CHECK( result[2] == "c");
  
  // "a<>b<>c<>","<>" => ["a","b","c",""]
  result = split("a<>b<>c<>", "<>");
  BOOST_CHECK( result.size() == 4);
  BOOST_CHECK( result[0] == "a");
  BOOST_CHECK( result[1] == "b");
  BOOST_CHECK( result[2] == "c");
  BOOST_CHECK( result[3] == "");
  
  // "<>a<>b<>c","<>" => ["","a","b","c"]
  result = split("<>a<>b<>c", "<>");
  BOOST_CHECK( result.size() == 4);
  BOOST_CHECK( result[0] == "");
  BOOST_CHECK( result[1] == "a");
  BOOST_CHECK( result[2] == "b");
  BOOST_CHECK( result[3] == "c");
  
  // "<>a<>","<>" => ["","a",""]
  result = split("<>a<>", "<>");
  BOOST_CHECK( result.size() == 3);
  BOOST_CHECK( result[0] == "");
  BOOST_CHECK( result[1] == "a");
  BOOST_CHECK( result[2] == "");
  
  // "a<><>b","<>" => ["a","","b"]
  result = split("a<><>b", "<>");
  BOOST_CHECK( result.size() == 3);
  BOOST_CHECK( result[0] == "a");
  BOOST_CHECK( result[1] == "");
  BOOST_CHECK( result[2] == "b");
  
  // "<>","<>" => ["",""]
  result = split("<>", "<>");
  BOOST_CHECK( result.size() == 2);
  BOOST_CHECK( result[0] == "");
  BOOST_CHECK( result[1] == "");
  //
  result = split("", "");
  BOOST_CHECK( result.size() == 0);
  
  // 特殊用法 "abc".split('')
  result = split("abc", "");
  BOOST_CHECK( result.size() == 3);
  BOOST_CHECK( result[0] == "a");
  BOOST_CHECK( result[1] == "b");
  BOOST_CHECK( result[2] == "c");
  // BOOST_CHECK_EQUAL( 2, 2 );
}

void test_split2()
{
  // cout << "test_split()" << endl;
  // dump_vs(result);
  vector<string> result;

  // "" => []
  result = split("");
  BOOST_CHECK( result.size() == 0);
  // "a" => ["a"]
  result = split("a");
  BOOST_CHECK( result.size() == 1);
  BOOST_CHECK( result[0] == "a");
  // "a b c" => ["a","b","c"]
  result = split("a b c");
  BOOST_CHECK( result.size() == 3);
  BOOST_CHECK( result[0] == "a");
  BOOST_CHECK( result[1] == "b");
  BOOST_CHECK( result[2] == "c");
  // "a " => ["a"]
  result = split("a ");
  BOOST_CHECK( result.size() == 1);
  BOOST_CHECK( result[0] == "a");
  // " a" => ["a"]
  result = split(" a");
  BOOST_CHECK( result.size() == 1);
  BOOST_CHECK( result[0] == "a");
  // " a " => ["a"]
  result = split(" a ");
  BOOST_CHECK( result.size() == 1);
  BOOST_CHECK( result[0] == "a");
  // "a b" => ["a","b"]
  result = split("a b");
  BOOST_CHECK( result.size() == 2);
  BOOST_CHECK( result[0] == "a");
  BOOST_CHECK( result[1] == "b");
  // "a  b" => ["a","b"]
  result = split("a  b");
  BOOST_CHECK( result.size() == 2);
  BOOST_CHECK( result[0] == "a");
  BOOST_CHECK( result[1] == "b");
  
  // "a b c",'b' => ["a "," c"]
  result = split("a b c",'b');
  BOOST_CHECK( result.size() == 2);
  BOOST_CHECK( result[0] == "a ");
  BOOST_CHECK( result[1] == " c");
  
  // "a,b",',' => ["a","b"]
  result = split("a,b", ',');
  BOOST_CHECK( result.size() == 2);
  BOOST_CHECK( result[0] == "a");
  BOOST_CHECK( result[1] == "b");
  // "a,,b",',' => ["a","","b"]
  result = split("a,,b", ',');
  BOOST_CHECK( result.size() == 3);
  BOOST_CHECK( result[0] == "a");
  BOOST_CHECK( result[1] == "");
  BOOST_CHECK( result[2] == "b");
  // ",a",',' => ["","a"]
  result = split(",a", ',');
  BOOST_CHECK( result.size() == 2);
  BOOST_CHECK( result[0] == "");
  BOOST_CHECK( result[1] == "a");
  // "a,",',' => ["a",""]
  result = split("a,", ',');
  BOOST_CHECK( result.size() == 2);
  BOOST_CHECK( result[0] == "a");
  BOOST_CHECK( result[1] == "");
  // ",a,",',' => ["","a",""]
  result = split(",a,", ',');
  BOOST_CHECK( result.size() == 3);
  BOOST_CHECK( result[0] == "");
  BOOST_CHECK( result[1] == "a");
  BOOST_CHECK( result[2] == "");
}

void test_map_atoi()
{
  vector<string> as(3);//({"1","2","3"});
  as[0] = "1"; as[1] = "2"; as[2] = "3";
  vector<int> is = map_atoi(as);
  BOOST_CHECK( is.size() == as.size());
  BOOST_CHECK( is[0] == 1);
  BOOST_CHECK( is[1] == 2);
  BOOST_CHECK( is[2] == 3);
}
void test_split_atoi()
{
  vector<int> vals = map_atoi( split("2 3 5 7 11 13") );
  BOOST_CHECK( vals.size() == 6);
  BOOST_CHECK( vals[0] == 2);
  BOOST_CHECK( vals[1] == 3);
  BOOST_CHECK( vals[2] == 5);
  BOOST_CHECK( vals[3] == 7);
  BOOST_CHECK( vals[4] == 11);
  BOOST_CHECK( vals[5] == 13);
}

test_suite* init_unit_test_suite( int argc, char* argv[] )
{
  //  boost::unit_test::progress_monitor.set_stream( std::ostream& );

  test_suite* test = BOOST_TEST_SUITE( "Example" );

  test->add( BOOST_TEST_CASE( &test_split1 ) );
  test->add( BOOST_TEST_CASE( &test_split2 ) );
  test->add( BOOST_TEST_CASE( &test_map_atoi ) );
  test->add( BOOST_TEST_CASE( &test_split_atoi ) );

  return test;
}
