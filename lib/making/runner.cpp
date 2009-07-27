/* Generated file, do not edit */

#ifndef CXXTEST_RUNNING
#define CXXTEST_RUNNING
#endif

#define _CXXTEST_HAVE_STD
#include <cxxtest/TestListener.h>
#include <cxxtest/TestTracker.h>
#include <cxxtest/TestRunner.h>
#include <cxxtest/RealDescriptions.h>
#include <cxxtest/ErrorPrinter.h>

int main() {
 return CxxTest::ErrorPrinter().run();
}
#include "MyTestSuite.h"

static MyTestSuite suite_MyTestSuite;

static CxxTest::List Tests_MyTestSuite = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_MyTestSuite( "MyTestSuite.h", 4, "MyTestSuite", suite_MyTestSuite, Tests_MyTestSuite );

static class TestDescription_MyTestSuite_testAddition : public CxxTest::RealTestDescription {
public:
 TestDescription_MyTestSuite_testAddition() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 10, "testAddition" ) {}
 void runTest() { suite_MyTestSuite.testAddition(); }
} testDescription_MyTestSuite_testAddition;

static class TestDescription_MyTestSuite_testMultiplication : public CxxTest::RealTestDescription {
public:
 TestDescription_MyTestSuite_testMultiplication() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 15, "testMultiplication" ) {}
 void runTest() { suite_MyTestSuite.testMultiplication(); }
} testDescription_MyTestSuite_testMultiplication;

#include <cxxtest/Root.cpp>
