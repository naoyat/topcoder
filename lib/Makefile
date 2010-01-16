#all: cppunit cxxtest google boost

isle: isle_test.cc isle.h
	g++ -o isle_test -lgtest isle_test.cc
	./isle_test

bignum: bignum_test.cc bignum.h
	g++ -o bignum_test -lgtest bignum_test.cc
	./bignum_test


#clean:
#	rm -f *~ runner tests *.o

