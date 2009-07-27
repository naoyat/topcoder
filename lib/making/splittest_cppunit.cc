#include "split.cc"

//#include <cppunit/TestCase.h>
#include <cppunit/extensions/HelperMacros.h>

class SplitTest : public CppUnit::TestFixture {
  CPPUNIT_TEST_SUITE( SplitTest );
  CPPUNIT_TEST( test_split1 );
  CPPUNIT_TEST( test_split2 );
  CPPUNIT_TEST( test_map_atoi );
  CPPUNIT_TEST( test_split_atoi );
  CPPUNIT_TEST_SUITE_END();

public:
  void setUp() {}
  void tearDown() {}

public:
  void test_split1() {
	vector<string> result;

	result = split("", "<>");
	CPPUNIT_ASSERT( result.size() == 0);

	// "a","<>" => ["a"]
	result = split("a", "<>");
	//	CPPUNIT_ASSERT( result.size() == 1);
	//	CPPUNIT_ASSERT( result[0] == "a");
	CPPUNIT_ASSERT_EQUAL( (size_t)1, result.size() );
	CPPUNIT_ASSERT_EQUAL( (string)"a", result[0] );

	// "a<>b<>c","<>" => ["a","b","c"]
	result = split("a<>b<>c", "<>");
	CPPUNIT_ASSERT( result.size() == 3);
	CPPUNIT_ASSERT( result[0] == "a");
	CPPUNIT_ASSERT( result[1] == "b");
	CPPUNIT_ASSERT( result[2] == "c");

	// "a<>b<>c<>","<>" => ["a","b","c",""]
	result = split("a<>b<>c<>", "<>");
	CPPUNIT_ASSERT( result.size() == 4);
	CPPUNIT_ASSERT( result[0] == "a");
	CPPUNIT_ASSERT( result[1] == "b");
	CPPUNIT_ASSERT( result[2] == "c");
	CPPUNIT_ASSERT( result[3] == "");

	// "<>a<>b<>c","<>" => ["","a","b","c"]
	result = split("<>a<>b<>c", "<>");
	CPPUNIT_ASSERT( result.size() == 4);
	CPPUNIT_ASSERT( result[0] == "");
	CPPUNIT_ASSERT( result[1] == "a");
	CPPUNIT_ASSERT( result[2] == "b");
	CPPUNIT_ASSERT( result[3] == "c");

	// "<>a<>","<>" => ["","a",""]
	result = split("<>a<>", "<>");
	CPPUNIT_ASSERT( result.size() == 3);
	CPPUNIT_ASSERT( result[0] == "");
	CPPUNIT_ASSERT( result[1] == "a");
	CPPUNIT_ASSERT( result[2] == "");

	// "a<><>b","<>" => ["a","","b"]
	result = split("a<><>b", "<>");
	CPPUNIT_ASSERT( result.size() == 3);
	CPPUNIT_ASSERT( result[0] == "a");
	CPPUNIT_ASSERT( result[1] == "");
	CPPUNIT_ASSERT( result[2] == "b");

	// "<>","<>" => ["",""]
	result = split("<>", "<>");
	CPPUNIT_ASSERT( result.size() == 2);
	CPPUNIT_ASSERT( result[0] == "");
	CPPUNIT_ASSERT( result[1] == "");
	//
	result = split("", "");
	CPPUNIT_ASSERT( result.size() == 0);

	// 特殊用法 "abc".split('')
	result = split("abc", "");
	CPPUNIT_ASSERT( result.size() == 3);
	CPPUNIT_ASSERT( result[0] == "a");
	CPPUNIT_ASSERT( result[1] == "b");
	CPPUNIT_ASSERT( result[2] == "c");
  }
  void test_split2() {
	// cout << "test_split()" << endl;
	// dump_vs(result);
	vector<string> result;

	// "" => []
	result = split("");
	CPPUNIT_ASSERT( result.size() == 0);
	// "a" => ["a"]
	result = split("a");
	CPPUNIT_ASSERT( result.size() == 1);
	CPPUNIT_ASSERT( result[0] == "a");
	// "a b c" => ["a","b","c"]
	result = split("a b c");
	CPPUNIT_ASSERT( result.size() == 3);
	CPPUNIT_ASSERT( result[0] == "a");
	CPPUNIT_ASSERT( result[1] == "b");
	CPPUNIT_ASSERT( result[2] == "c");
	// "a " => ["a"]
	result = split("a ");
	CPPUNIT_ASSERT( result.size() == 1);
	CPPUNIT_ASSERT( result[0] == "a");
	// " a" => ["a"]
	result = split(" a");
	CPPUNIT_ASSERT( result.size() == 1);
	CPPUNIT_ASSERT( result[0] == "a");
	// " a " => ["a"]
	result = split(" a ");
	CPPUNIT_ASSERT( result.size() == 1);
	CPPUNIT_ASSERT( result[0] == "a");
	// "a b" => ["a","b"]
	result = split("a b");
	CPPUNIT_ASSERT( result.size() == 2);
	CPPUNIT_ASSERT( result[0] == "a");
	CPPUNIT_ASSERT( result[1] == "b");
	// "a  b" => ["a","b"]
	result = split("a  b");
	CPPUNIT_ASSERT( result.size() == 2);
	CPPUNIT_ASSERT( result[0] == "a");
	CPPUNIT_ASSERT( result[1] == "b");

	// "a b c",'b' => ["a "," c"]
	result = split("a b c",'b');
	CPPUNIT_ASSERT( result.size() == 2);
	CPPUNIT_ASSERT( result[0] == "a ");
	CPPUNIT_ASSERT( result[1] == " c");

	// "a,b",',' => ["a","b"]
	result = split("a,b", ',');
	CPPUNIT_ASSERT( result.size() == 2);
	CPPUNIT_ASSERT( result[0] == "a");
	CPPUNIT_ASSERT( result[1] == "b");
	// "a,,b",',' => ["a","","b"]
	result = split("a,,b", ',');
	CPPUNIT_ASSERT( result.size() == 3);
	CPPUNIT_ASSERT( result[0] == "a");
	CPPUNIT_ASSERT( result[1] == "");
	CPPUNIT_ASSERT( result[2] == "b");
	// ",a",',' => ["","a"]
	result = split(",a", ',');
	CPPUNIT_ASSERT( result.size() == 2);
	CPPUNIT_ASSERT( result[0] == "");
	CPPUNIT_ASSERT( result[1] == "a");
	// "a,",',' => ["a",""]
	result = split("a,", ',');
	CPPUNIT_ASSERT( result.size() == 2);
	CPPUNIT_ASSERT( result[0] == "a");
	CPPUNIT_ASSERT( result[1] == "");
	// ",a,",',' => ["","a",""]
	result = split(",a,", ',');
	CPPUNIT_ASSERT( result.size() == 3);
	CPPUNIT_ASSERT( result[0] == "");
	CPPUNIT_ASSERT( result[1] == "a");
	CPPUNIT_ASSERT( result[2] == "");
  }

  void test_map_atoi() {
	vector<string> as(3);//({"1","2","3"});
	as[0] = "1"; as[1] = "2"; as[2] = "3";
	vector<int> is = map_atoi(as);
	CPPUNIT_ASSERT( is.size() == as.size());
	CPPUNIT_ASSERT( is[0] == 1);
	CPPUNIT_ASSERT( is[1] == 2);
	CPPUNIT_ASSERT( is[2] == 3);
  }
  void test_split_atoi() {
	vector<int> vals = map_atoi( split("2 3 5 7 11 13") );
	CPPUNIT_ASSERT( vals.size() == 6);
	CPPUNIT_ASSERT( vals[0] == 2);
	CPPUNIT_ASSERT( vals[1] == 3);
	CPPUNIT_ASSERT( vals[2] == 5);
	CPPUNIT_ASSERT( vals[3] == 7);
	CPPUNIT_ASSERT( vals[4] == 11);
	CPPUNIT_ASSERT( vals[5] == 13);
  }
};

// CPPUNIT_TEST_SUITE_REGISTRATION( SplitTest );

#include <cppunit/TextTestRunner.h>

int main(int argc, char *argv[])
{
  CPPUNIT_TEST_SUITE_REGISTRATION( SplitTest );

  CppUnit::TextTestRunner runner;

  runner.addTest( SplitTest::suite() );
  runner.run("", false);
  return 0;
}
