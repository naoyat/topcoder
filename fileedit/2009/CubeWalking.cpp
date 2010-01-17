#line 2 "CubeWalking.cpp"
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
#define sz(a)  int((a).size())

class CubeWalking {
 private:
  int dir(int x,int y){
    switch(x){
      case 1: return 0;
      case -1: return 2;
      default: return (y==1)?1:3;
    }
  }
  int x(int d){
    switch(d){
      case 0: return 1;
      case 1: return 0;
      case 2: return -1;
      case 3: return 0;
    }
  }
  int y(int d){
    switch(d){
      case 0: return 0;
      case 1: return 1;
      case 2: return 0;
      case 3: return -1;
    }
  }
 public:
  string finalPosition(string movement) {
    int n=sz(movement);

    int dx=1,dy=0;
    int ox=0,oy=0;
    int d=0;
    for(int i=0;i<n;i++){
      switch(movement[i]){
        case 'L':
          d=(dir(dx,dy)+1)%4;
          dx=x(d); dy=y(d); break;
       case 'R':
          d=(dir(dx,dy)+3)%4;
          dx=x(d); dy=y(d); break;
        case 'W':
          ox+=dx;
          if (ox==2) ox=-1;
          else if (ox==-2) ox=1;
          oy+=dy;
          if (oy==2) oy=-1;
          else if (oy==-2) oy=1;
          break;
      }
    }
    if (ox*oy) return "RED";
    if (ox+oy) return "BLUE";
    return "GREEN";
  }
};

// BEGIN CUT HERE
#include <time.h>
clock_t start_time;
void timer_clear() { start_time = clock(); }
string timer() { clock_t end_time = clock(); double interval = (double)(end_time - start_time)/CLOCKS_PER_SEC; ostringstream os; os << " (" << interval*1000 << " msec)"; return os.str(); }

template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
int verify_case(const string &Expected, const string &Received) { if (Expected == Received) cerr << "PASSED" << timer() << endl; else { cerr << "FAILED" << timer() << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } return 0;}

template<int N> struct Case_ {};
char Test_(...);
int Test_(Case_<0>) {
	timer_clear();
	string movement = "LLRR"; 
	string RetVal = "GREEN"; 
	return verify_case(RetVal, CubeWalking().finalPosition(movement)); }
int Test_(Case_<1>) {
	timer_clear();
	string movement = "WWWWWWWWWWWW"; 
	string RetVal = "GREEN"; 
	return verify_case(RetVal, CubeWalking().finalPosition(movement)); }
int Test_(Case_<2>) {
	timer_clear();
	string movement = "WLWRW"; 
	string RetVal = "RED"; 
	return verify_case(RetVal, CubeWalking().finalPosition(movement)); }
int Test_(Case_<3>) {
	timer_clear();
	string movement = "WWLLWRWLWLLRWW"; 
	string RetVal = "BLUE"; 
	return verify_case(RetVal, CubeWalking().finalPosition(movement)); }

template<int N> void Run_() { cerr << "Test Case #" << N << "..." << flush; Test_(Case_<N>()); Run_<sizeof(Test_(Case_<N+1>()))==1 ? -1 : N+1>(); }
template<>      void Run_<-1>() {}
int main() { Run_<0>(); }
// END CUT HERE


// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
Consider the 3x3x3 cube shown above.  There are nine squares on each of its six faces, and each face is colored using the following pattern:
	
		The four corner squares are red.
		The center square is green.
		The remaining four squares are blue.
	
There is a robot standing in the green square of the top face of the cube, facing one of the blue squares.  It receives a sequence of commands.  Each command is one of the following:
	
		'L': Stay in the current square and turn left 90 degrees.
		'R': Stay in the current square and turn right 90 degrees.
		'W': Walk forward in the current direction to the next square.
	
Note that the robot can cross an edge of the cube into another face.  When that happens, the cube will rotate automatically to keep the robot on the top face.
You are given a string movement containing the sequence of commands received by the robot.  The robot will execute all of the commands in order.  Return the color of the robot's final landing square - "RED", "GREEN" or "BLUE" (all quotes for clarity).

DEFINITION
Class:CubeWalking
Method:finalPosition
Parameters:string
Returns:string
Method signature:string finalPosition(string movement)


NOTES
-The answer does not depend on the initial direction of the robot.


CONSTRAINTS
-movement will contain between 1 and 50 characters, inclusive.
-Each character in movement will be 'L', 'R' or 'W'.


EXAMPLES

0)
"LLRR"

Returns: "GREEN"

In this example, the robot only turns left or right without ever moving to a different square.

1)
"WWWWWWWWWWWW"

Returns: "GREEN"

Walking 12 squares forward in the same direction will lead the robot back to its original position.

2)
"WLWRW"

Returns: "RED"



3)
"WWLLWRWLWLLRWW"

Returns: "BLUE"



*/
// END CUT HERE
