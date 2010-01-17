test: test_Bits test_Bignum

test_Bits: Bits.h Bits_test.cc
	g++ -o test_Bits Bits_test.cc -lgtest
	./test_Bits

test_Bignum: Bignum.h Bignum_test.cc
	g++ -o test_Bignum Bignum_test.cc -lgtest
	./test_Bignum

clean:
	rm -f test_* *~ *.o core

