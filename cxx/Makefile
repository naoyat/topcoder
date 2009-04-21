all: cppunit cxxtest google boost

# cppunit
cppunit: splittest_cppunit.cc
	g++ -o splittest_cppunit splittest_cppunit.cc -lcppunit
	./splittest_cppunit

cppunit-qt: splittest_cppunit-qt.cc
	g++ -o splittest_cppunit-qt splittest_cppunit-qt.cc -lcppunit \
		-framework QtCore -framework QtGui
	./splittest_cppunit-qt

# cxxtest
cxxtest: splittest_cxxtest.h
	cxxtestgen.pl --error-printer -o splittest_cxxtest.cpp splittest_cxxtest.h
	g++ -I/usr/local/cxxtest -o splittest_cxxtest splittest_cxxtest.cpp
	./splittest_cxxtest

cxxtest-x11: splittest_cxxtest.h ## 消えるのが早すぎてダメ
	cxxtestgen.pl --gui=X11Gui -o splittest_cxxtest-x11.cpp splittest_cxxtest.h
	g++ -o splittest_cxxtest-x11 -I/usr/local/cxxtest -L/usr/X11R6/lib splittest_cxxtest-x11.cpp -lX11
	./splittest_cxxtest-x11 ## -keep

cxxtest-qt: splittest_cxxtest.h ## 消えるのが早すぎてダメ
	cxxtestgen.pl --gui=QtGui -o splittest_cxxtest-qt.cpp splittest_cxxtest.h
	g++ -o splittest_cxxtest-qt \
		-I/usr/local/cxxtest -I/Library/Frameworks/QtCore.framework/Headers -I/Library/Frameworks/QtGui.framework/Headers \
		-L/usr/X11R6/lib splittest_cxxtest-qt.cpp \
		-framework QtCore -framework QtGui
#		-framework /Library/Frameworks/QtCore.framework -framework /Library/Frameworks/QtGui.framework
	./splittest_cxxtest-qt ## -keep

# googletest
google: splittest_google.cc # described
	g++ -o splittest_google -lgtest splittest_google.cc
	./splittest_google

bignum: bignumtest.cc bignum.cc
	g++ -o bignumtest -lgtest bignumtest.cc
	./bignumtest

# boost.test
boost: splittest_boost.cc # described
	g++ -o splittest_boost splittest_boost.cc /usr/local/lib/libboost_unit_test_framework-xgcc40-mt.a
	./splittest_boost

clean:
	rm -f *~ runner tests *.o

