/*
#include <cppunit/BriefTestProgressListener.h>
#include <cppunit/CompilerOutputter.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestResultCollector.h>
*/
#include "split_test.cc"
#include <cppunit/TextTestRunner.h>

int main(int argc, char *argv[])
{
  CPPUNIT_TEST_SUITE_REGISTRATION( SplitTest );

  CppUnit::TextTestRunner runner;

  runner.addTest( SplitTest::suite() );
  runner.run("", false);
  return 0;
}
