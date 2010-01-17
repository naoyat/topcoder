#line 42 "Time.cpp"
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
using namespace std;

class Time {
	public:
	string whatTime(int seconds) {
	  int minutes = seconds / 60;
	  int hours = minutes / 60;
	  int s = seconds % 60;
	  int m = minutes % 60;
	  //  int h = hours % 24;
	  stringstream ss;
	  ss << hours << ":" << m << ":" << s;
	  return ss.str();
	}
	

};



// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
