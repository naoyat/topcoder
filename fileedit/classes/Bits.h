#include <string>
#include <iostream>
#include <sstream>
using namespace std;

class Bits {
  unsigned char *data;
  int data_bytesize;
  int data_size;

public:
  Bits() { data = NULL; data_size = 0; }
  Bits( int size, int initial_value=0 ) { data = NULL; init(size,initial_value); }
  Bits( const Bits& bits ) { data = NULL; init(bits); }
  virtual ~Bits() { dealloc_data(); }

  const int size() { return data_size; }
  const int popcount();

  void dealloc_data() { if (data) { free((void*)data); data = NULL; } }

  Bits &init( int size, int initial_value=0 );
  Bits &init( const Bits& bits );
  Bits &operator=( const Bits& bits ) { dealloc_data(); return init( bits ); }

  void set( int offset, int value=1 );
  void unset( int offset );
  int get( int offset );

  Bits &operator&=(const Bits& other);
  Bits &operator|=(const Bits& other);
  Bits &operator^=(const Bits& other);

  Bits &operator+=(const Bits& other); //concat

  Bits operator&(const Bits& other) { Bits result(*this); result &= other; return result; }
  Bits operator|(const Bits& other) { Bits result(*this); result |= other; return result; }
  Bits operator^(const Bits& other) { Bits result(*this); result ^= other; return result; }
  Bits operator~();

  Bits operator+(const Bits& other) { Bits result(*this); result += other; return result; }

  string desc();
};

const int
Bits::popcount()
{
  int cnt = 0;
  int fullsize = data_size >> 3;
  for (int i=0; i<fullsize; i++)
    cnt += __builtin_popcount(data[i]);
  if (fullsize < data_bytesize) {
    int rest_bitsize = data_size % 8; // 1..7
    int mask = 127 >> (7 - rest_bitsize); // 1...127
    cnt += __builtin_popcount((int)data[fullsize] & mask);
  }
  return cnt;
}

Bits &
Bits::init( int size, int initial_value )
{
  dealloc_data();
  data_size = size; data_bytesize = (size + 7) >> 3;
  data = (unsigned char *)malloc( data_bytesize );
  memset( data, initial_value ? 255 : 0, data_bytesize );
  return *this;
}
Bits &
Bits::init( const Bits& bits )
{
  dealloc_data();
  data_size = bits.data_size; data_bytesize = bits.data_bytesize;
  data = (unsigned char *)malloc( data_bytesize );
  memcpy( data, bits.data, data_bytesize );
  return *this;
}

void
Bits::set( int offset, int value )
{
  if (offset < 0 || data_size <= offset) return; // invalid.
  if (!data) return;

  int byteofs = offset >> 3, bitofs = offset % 8;
  if (value)
    data[byteofs] |= (1 << bitofs);
  else
    data[byteofs] &= (~(1 << bitofs));
}
void
Bits::unset( int offset )
{
  if (offset < 0 || data_size <= offset) return; // invalid.
  if (!data) return;

  int byteofs = offset >> 3, bitofs = offset % 8;
  data[byteofs] &= (~(1 << bitofs));
}
int
Bits::get( int offset )
{
  if (offset < 0 || data_size <= offset) return -1; // invalid.
  if (!data) return -1;

  int byteofs = offset >> 3, bitofs = offset % 8;
  return (data[byteofs] & (1 << bitofs)) ? 1 : 0;
}

Bits &
Bits::operator&=(const Bits& other)
{
  if (data_size < other.data_size) {
    // 自分.size < 相手.size
    for (int i=0; i<data_bytesize; i++) data[i] &= other.data[i];
    // 残りは捨てられる
  } else {
    // 自分.size >= 相手.size
    int fullsize = other.data_size >> 3;
    for (int i=0; i<fullsize; i++)
      data[i] &= other.data[i];
    if (fullsize < other.data_bytesize) {
      int rest_bitsize = other.data_size & 7;
      int mask = 127 >> (7 - rest_bitsize);
      int rest = other.data[fullsize] & mask;
      data[fullsize++] &= rest;
    }
    // 足りない分はzero
    for (int i=fullsize; i<data_bytesize; i++) data[i] = 0; // data[i] &= 0;
  }
  return *this;
}

Bits &
Bits::operator|=(const Bits& other)
{
  if (data_size < other.data_size) {
    // 自分.size < 相手.size
    for (int i=0; i<data_bytesize; i++) data[i] |= other.data[i];
    // 残りは捨てられる
  } else {
    // 自分.size >= 相手.size
    int fullsize = other.data_size >> 3;
    for (int i=0; i<fullsize; i++)
      data[i] |= other.data[i];
    if (fullsize < other.data_bytesize) {
      int rest_bitsize = other.data_size % 8;
      int mask = 127 >> (7 - rest_bitsize);
      int rest = other.data[fullsize] & mask;
      data[fullsize++] |= rest;
    }
    // 足りない分は放置
    // for (int i=fullsize; i<data_bytesize; i++) data[i] |= 0;
  }
  return *this;
}

Bits &
Bits::operator^=(const Bits& other)
{
  if (data_size < other.data_size) {
    // 自分.size < 相手.size
    for (int i=0; i<data_bytesize; i++) data[i] ^= other.data[i];
    // 残りは捨てられる
  } else {
    // 自分.size >= 相手.size
    int fullsize = other.data_size >> 3;
    for (int i=0; i<fullsize; i++)
      data[i] ^= other.data[i];
    if (fullsize < other.data_bytesize) {
      int rest_bitsize = other.data_size % 8;
      int mask = 127 >> (7 - rest_bitsize);
      int rest = other.data[fullsize] & mask;
      data[fullsize++] ^= rest;
    }
    // 足りない分は放置
    // for (int i=fullsize; i<data_bytesize; i++) data[i] ^= 0;
  }
  return *this;
}

Bits
Bits::operator~()
{
  Bits not_this(*this);
  for (int i=0; i<data_bytesize; i++) not_this.data[i] = ~not_this.data[i];
  return not_this;
}

Bits &
Bits::operator+=(const Bits& other)
{
  unsigned char *old_data = data; data = NULL;
  int old_data_size = data_size, old_data_bytesize = data_bytesize;
  init( old_data_size + other.data_size );
  memcpy( data, old_data, old_data_bytesize );
  for (int i=0; i<other.data_size; i++)
    set( old_data_size + i, ((Bits)other).get(i) );
  free( (void*)old_data );
  return *this;
}

string
Bits::desc()
{
  stringstream s;
  for (int i=0; i<data_size; i++) s << get(i);
  return s.str();
}

ostream& operator<<(ostream &s, Bits bits)
{
  s << bits.desc();
  return s;
}
