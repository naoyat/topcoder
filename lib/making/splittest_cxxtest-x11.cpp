/* Generated file, do not edit */

#ifndef CXXTEST_RUNNING
#define CXXTEST_RUNNING
#endif

#include <cxxtest/TestListener.h>
#include <cxxtest/TestTracker.h>
#include <cxxtest/TestRunner.h>
#include <cxxtest/RealDescriptions.h>
#include <cxxtest/StdioPrinter.h>
#include <cxxtest/X11Gui.h>

int main( int argc, char *argv[] ) {
 return CxxTest::GuiTuiRunner<CxxTest::X11Gui, CxxTest::StdioPrinter>( argc, argv ).run();
}
#include "splittest_cxxtest.h"

static splittest_cxxtest suite_splittest_cxxtest;

static CxxTest::List Tests_splittest_cxxtest = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_splittest_cxxtest( "splittest_cxxtest.h", 4, "splittest_cxxtest", suite_splittest_cxxtest, Tests_splittest_cxxtest );

static class TestDescription_splittest_cxxtest_testSplit1 : public CxxTest::RealTestDescription {
public:
 TestDescription_splittest_cxxtest_testSplit1() : CxxTest::RealTestDescription( Tests_splittest_cxxtest, suiteDescription_splittest_cxxtest, 12, "testSplit1" ) {}
 void runTest() { suite_splittest_cxxtest.testSplit1(); }
} testDescription_splittest_cxxtest_testSplit1;

static class TestDescription_splittest_cxxtest_testSplit2 : public CxxTest::RealTestDescription {
public:
 TestDescription_splittest_cxxtest_testSplit2() : CxxTest::RealTestDescription( Tests_splittest_cxxtest, suiteDescription_splittest_cxxtest, 79, "testSplit2" ) {}
 void runTest() { suite_splittest_cxxtest.testSplit2(); }
} testDescription_splittest_cxxtest_testSplit2;

static class TestDescription_splittest_cxxtest_testMapAtoi : public CxxTest::RealTestDescription {
public:
 TestDescription_splittest_cxxtest_testMapAtoi() : CxxTest::RealTestDescription( Tests_splittest_cxxtest, suiteDescription_splittest_cxxtest, 156, "testMapAtoi" ) {}
 void runTest() { suite_splittest_cxxtest.testMapAtoi(); }
} testDescription_splittest_cxxtest_testMapAtoi;

static class TestDescription_splittest_cxxtest_testSplitAtoi : public CxxTest::RealTestDescription {
public:
 TestDescription_splittest_cxxtest_testSplitAtoi() : CxxTest::RealTestDescription( Tests_splittest_cxxtest, suiteDescription_splittest_cxxtest, 167, "testSplitAtoi" ) {}
 void runTest() { suite_splittest_cxxtest.testSplitAtoi(); }
} testDescription_splittest_cxxtest_testSplitAtoi;

static class TestDescription_splittest_cxxtest_testManyTimes : public CxxTest::RealTestDescription {
public:
 TestDescription_splittest_cxxtest_testManyTimes() : CxxTest::RealTestDescription( Tests_splittest_cxxtest, suiteDescription_splittest_cxxtest, 178, "testManyTimes" ) {}
 void runTest() { suite_splittest_cxxtest.testManyTimes(); }
} testDescription_splittest_cxxtest_testManyTimes;

#include <cxxtest/Root.cpp>
