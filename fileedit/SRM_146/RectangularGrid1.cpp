#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <cctype>
#include <algorithm>
#include <string>
#include <vector>
#include <deque>
#include <stack>
#include <queue>
#include <list>
#include <map>
#include <set>
// BEGIN CUT HERE
#include "cout.h"
// END CUT HERE
using namespace std;

typedef long long ll;
#define FOR(var,from,to) for(int var=(from);var<=(to);var++)
using namespace std;
// 18:59:00-
class RectangularGrid {

 public:
  long long countRectangles(int width, int height) {
    ll cnt = 0LL;
    FOR(w,1,width){
      FOR(h,1,height){
        if (w!=h) cnt += (1LL+width-w) * (1LL+height-h);
      }
    }
    return cnt;
  }
  // 19:00:12 ... 272.31 with debug code
};


void test(int case_no, int width, int height, long long expected) {
  RectangularGrid rg;
  long long result = rg.countRectangles(width,height);
  printf("test case #%d: %s ... (%d,%d) => %lld, expected %lld\n",
         case_no, (result == expected)?"OK":"NG", width, height, result, expected);
}

main(){
  test(0, 3,3, 22);
  test(1, 5,2, 31);
  test(3, 1,1, 0);
  test(4, 592,964, 81508708664LL);
}
