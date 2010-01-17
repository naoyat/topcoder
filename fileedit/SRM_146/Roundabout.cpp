// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// The purpose of a roundabout is to control the flow of traffic at a busy intersection. A roundabout has 4 entry points: from the North, East, South and West; and 4 exit points at the same locations (see Example 0 for a diagram).
Cars can enter, leave or move one position on the roundabout. Each of those events requires one second. All the events can take place simultaneously. So if there are two cars on the roundabout, one behind the other, then they can both move during the next second. A car decides whether to enter the roundabout based on its knowledge from the previous second. A car will always enter if it has the right to do so.
A car has the right to enter only if there are no cars to its immediate left (either on the roundabout or waiting to get on the roundabout) and it is the first car in line at the entry point (Example 1 demonstrates this). A special case occurs if there is a car at each of the 4 entry points. In this case, the car from the North will wait until there are no cars to its left on the roundabout and then will be the first to enter.
Once the car is on the roundabout, it moves counter-clockwise until it exits the roundabout. There are 4 positions on the roundabout. So for example, it would take 1 second to enter the roundabout, 2 seconds to complete half a lap and another 1 second to exit the roundabout.
Each parameter of the input is a second by second account of cars coming from that direction with their intended exit locations. Intended exit locations will be N (North), E (East), S (South) and W (West). A '-' means that no car arrived during that second at the given entry point. Thus, for example, character i of north represents the direction in which a car (if there is one) arriving from the north at time i will leave the roundabout.  So, at time i, this car will be added to the end of the line at the north entry point to the roundabout.  Cars will not be allowed to exit the roundabout at the point of their entry.
Given the lists of cars coming from the 4 directions, return the total time required for all cars to leave the roundabout.


DEFINITION
Class:Roundabout
Method:clearUpTime
Parameters:string, string, string, string
Returns:int
Method signature:int clearUpTime(string north, string east, string south, string west)


CONSTRAINTS
-north, east, south and west will contain between 0 and 50 characters inclusive.
-north, east, south and west must only contain 'N', 'W', 'S', 'E' and '-' characters.
-north will NOT contain the character 'N'.
-east will NOT contain the character 'E'.
-south will NOT contain the character 'S'.
-west will NOT contain the character 'W'.


EXAMPLES

0)
"--"
"--"
"WE"
"-S"

Returns: 6

Note for plugin users: this example contains an image.  Please view the problem in the applet to see the image.


At the start, a car approaches the roundabout from the South. At time = 1, the car going West enters the roundabout, another car approaches from the South and another one from the West. At time = 2, the car going West moves one position, the car going East must give way, the car going South enters the roundabout. At time = 3, the car going West moves one position, the car going East must still give way, the car going South moves one position. At time = 4, the car going West moves one position, the car going South exits the roundabout, the car going East enters the roundabout. At time = 5, the car going West exits the roundabout, the car going East moves one position. At time = 6, the car going East exits the roundabout. The method should return 6.

1)
"WWW"
"NNN"
"---"
"---"

Returns: 9

All the cars from the North must wait until the cars from the East exit the roundabout. Only then can they enter the roundabout.

2)
"SSS"
"WW-"
"N"
"S------"

Returns: 13

3)
"SSS-"
"--W---W"
"WE"
"-S"

Returns: 14

4)
"E"
"-N"
"W"
"-S"

Returns: 5

5)
""
""
""
""

Returns: 0

6)
"W"
""
"--E"
""

Returns: 6

Note: At time = 3, the car from the South does not enter the roundabout, because it has already decided not to enter, based on its knowledge from the previous second. Thus it enters at time = 4.

7)
"ES"
"N"
"E"
""

Returns: 9

8)
"E"
"SN"
"-N"
"S-E"

Returns: 12

*/
// END CUT HERE

#line 116 "Roundabout.cpp"
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
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<string> vs;
typedef vector<long long> vll;
#define sz(a)  int((a).size())
#define pb  push_back
#define FOR(var,from,to) for(int var=(from);var<=(to);var++)
#define rep(var,n)  for(int var=0;var<(n);var++)
#define all(c)  (c).begin(),(c).end()
#define tr(c,i)  for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); i++)
#define found(s,e)  ((s).find(e)!=(s).end())
#define mset(arr,val)  memset(arr,val,sizeof(arr))
#define remove_(c,val) (c).erase(remove((c).begin(),(c).end(),(val)),(c).end())
#define lastc(str) (*((str).end()-1))

typedef pair<int,int> i_i;
typedef pair<ll,ll> ll_ll;
typedef pair<double,double> d_d;
typedef pair<int,pair<int,int> > i_ii;
#define cons(x,y) make_pair((x),(y))
#define car(x) ((x).first)
#define cdr(x) ((x).second)
#define cadr(x) (x).second.first
#define cddr(x) (x).second.second

class Roundabout {
	public:
	int clearUpTime(string north, string east, string south, string west) {
		
	}
};

// BEGIN CUT HERE
#include <time.h>
clock_t start_time;
void timer_clear() { start_time = clock(); }
string timer() { clock_t end_time = clock(); double interval = (double)(end_time - start_time)/CLOCKS_PER_SEC; ostringstream os; os << " (" << interval*1000 << " msec)"; return os.str(); }

template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
int verify_case(const int &Expected, const int &Received) { if (Expected == Received) cerr << "PASSED" << timer() << endl; else { cerr << "FAILED" << timer() << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } return 0;}

template<int N> struct Case_ {};
char Test_(...);
int Test_(Case_<0>) {
	timer_clear();
	string north = "--"; 
	string east = "--"; 
	string south = "WE"; 
	string west = "-S"; 
	int RetVal = 6; 
	return verify_case(RetVal, Roundabout().clearUpTime(north, east, south, west)); }
int Test_(Case_<1>) {
	timer_clear();
	string north = "WWW"; 
	string east = "NNN"; 
	string south = "---"; 
	string west = "---"; 
	int RetVal = 9; 
	return verify_case(RetVal, Roundabout().clearUpTime(north, east, south, west)); }
int Test_(Case_<2>) {
	timer_clear();
	string north = "SSS"; 
	string east = "WW-"; 
	string south = "N"; 
	string west = "S------"; 
	int RetVal = 13; 
	return verify_case(RetVal, Roundabout().clearUpTime(north, east, south, west)); }
int Test_(Case_<3>) {
	timer_clear();
	string north = "SSS-"; 
	string east = "--W---W"; 
	string south = "WE"; 
	string west = "-S"; 
	int RetVal = 14; 
	return verify_case(RetVal, Roundabout().clearUpTime(north, east, south, west)); }
int Test_(Case_<4>) {
	timer_clear();
	string north = "E"; 
	string east = "-N"; 
	string south = "W"; 
	string west = "-S"; 
	int RetVal = 5; 
	return verify_case(RetVal, Roundabout().clearUpTime(north, east, south, west)); }
int Test_(Case_<5>) {
	timer_clear();
	string north = ""; 
	string east = ""; 
	string south = ""; 
	string west = ""; 
	int RetVal = 0; 
	return verify_case(RetVal, Roundabout().clearUpTime(north, east, south, west)); }
int Test_(Case_<6>) {
	timer_clear();
	string north = "W"; 
	string east = ""; 
	string south = "--E"; 
	string west = ""; 
	int RetVal = 6; 
	return verify_case(RetVal, Roundabout().clearUpTime(north, east, south, west)); }
int Test_(Case_<7>) {
	timer_clear();
	string north = "ES"; 
	string east = "N"; 
	string south = "E"; 
	string west = ""; 
	int RetVal = 9; 
	return verify_case(RetVal, Roundabout().clearUpTime(north, east, south, west)); }
int Test_(Case_<8>) {
	timer_clear();
	string north = "E"; 
	string east = "SN"; 
	string south = "-N"; 
	string west = "S-E"; 
	int RetVal = 12; 
	return verify_case(RetVal, Roundabout().clearUpTime(north, east, south, west)); }

template<int N> void Run_() { cerr << "Test Case #" << N << "..." << flush; Test_(Case_<N>()); Run_<sizeof(Test_(Case_<N+1>()))==1 ? -1 : N+1>(); }
template<>      void Run_<-1>() {}
int main() { Run_<0>(); }
// END CUT HERE

