#line 2 "BusinessTasks.cpp"
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
#define rep(var,n)  for(int var=0;var<(n);var++)

class BusinessTasks {
 public:
  string getTask(vector<string> list, int n) {
    n--;
    for(int N=sz(list),cur=0;N>1;N--){
      cur=(cur+n)%N;
      list.erase(list.begin()+cur);
    }
    return list[0];
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
	string list_[] = {"a","b","c","d"};
	  vector <string> list(list_, list_+sizeof(list_)/sizeof(*list_)); 
	int n = 2; 
	string RetVal = "a"; 
	return verify_case(RetVal, BusinessTasks().getTask(list, n)); }
int Test_(Case_<1>) {
	timer_clear();
	string list_[] = {"a","b","c","d","e"};
	  vector <string> list(list_, list_+sizeof(list_)/sizeof(*list_)); 
	int n = 3; 
	string RetVal = "d"; 
	return verify_case(RetVal, BusinessTasks().getTask(list, n)); }
int Test_(Case_<2>) {
	timer_clear();
	string list_[] = {"alpha","beta","gamma","delta","epsilon"};
	  vector <string> list(list_, list_+sizeof(list_)/sizeof(*list_)); 
	int n = 1; 
	string RetVal = "epsilon"; 
	return verify_case(RetVal, BusinessTasks().getTask(list, n)); }
int Test_(Case_<3>) {
	timer_clear();
	string list_[] = {"a","b"};
	  vector <string> list(list_, list_+sizeof(list_)/sizeof(*list_)); 
	int n = 1000; 
	string RetVal = "a"; 
	return verify_case(RetVal, BusinessTasks().getTask(list, n)); }
int Test_(Case_<4>) {
	timer_clear();
	string list_[] = {"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t",
"u","v","w","x","y","z"};
	  vector <string> list(list_, list_+sizeof(list_)/sizeof(*list_)); 
	int n = 17; 
	string RetVal = "n"; 
	return verify_case(RetVal, BusinessTasks().getTask(list, n)); }
int Test_(Case_<5>) {
	timer_clear();
	string list_[] = {"zlqamum","yjsrpybmq","tjllfea","fxjqzznvg","nvhekxr","am","skmazcey","piklp",
"olcqvhg","dnpo","bhcfc","y","h","fj","bjeoaxglt","oafduixsz","kmtbaxu",
"qgcxjbfx","my","mlhy","bt","bo","q"};
	  vector <string> list(list_, list_+sizeof(list_)/sizeof(*list_)); 
	int n = 9000000; 
	string RetVal = "fxjqzznvg"; 
	return verify_case(RetVal, BusinessTasks().getTask(list, n)); }

template<int N> void Run_() { cerr << "Test Case #" << N << "..." << flush; Test_(Case_<N>()); Run_<sizeof(Test_(Case_<N+1>()))==1 ? -1 : N+1>(); }
template<>      void Run_<-1>() {}
int main() { Run_<0>(); }
// END CUT HERE


// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// A busy businessman has a number of equally important tasks which he must accomplish.  To decide which of the tasks to perform first, he performs the following operation.

He writes down all his tasks in the form of a circular list, so the first task is adjacent to the last task. He then thinks of a positive number. This number is the random seed, which he calls n. Starting with the first task, he moves clockwise (from element 1 in the list to element 2 in the list and so on), counting from 1 to n. When his count reaches n, he removes that task from the list and starts counting from the next available task. He repeats this procedure until one task remains. It is this last task that he chooses to execute.

Given a vector <string> list representing the tasks and an int n, return the task which the businessman chooses to execute.


DEFINITION
Class:BusinessTasks
Method:getTask
Parameters:vector <string>, int
Returns:string
Method signature:string getTask(vector <string> list, int n)


CONSTRAINTS
-list will contain between 2 and 50 elements inclusive.
-Each element in list will contain between 1 and 50 characters inclusive.
-Each element in list will contain only characters 'a'-'z'.
-n will be between 1 and 10000000 inclusive.


EXAMPLES

0)
{"a","b","c","d"}
2

Returns: "a"

We start counting from a. So a is 1, b is 2. We remove b, so list is now {a,c,d}. We continue from c. So c is 1, d is 2. We remove d, so list is now {a,c}. We continue from a. So a is 1, c is 2. We remove c, and now we are left with the last task a.

1)
{"a","b","c","d","e"}
3

Returns: "d"

We start counting from a. So a is 1, b is 2, c is 3. We remove c, now list = {a,b,d,e}. We continue from d. So d is 1, e is 2, a is 3. We remove a, now list = {b,d,e}. We continue from b. So b is 1, d is 2, e is 3. We remove e, now list = {b,d}. We continue from b. So b is 1, d is 2 and finally b is 3. We remove b, and now we are left with just one task d.

2)
{"alpha","beta","gamma","delta","epsilon"}
1

Returns: "epsilon"

3)
{"a","b"}
1000

Returns: "a"

4)
{"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t",
"u","v","w","x","y","z"}
17

Returns: "n"

5)
{"zlqamum","yjsrpybmq","tjllfea","fxjqzznvg","nvhekxr","am","skmazcey","piklp",
"olcqvhg","dnpo","bhcfc","y","h","fj","bjeoaxglt","oafduixsz","kmtbaxu",
"qgcxjbfx","my","mlhy","bt","bo","q"}
9000000

Returns: "fxjqzznvg"

*/
// END CUT HERE
