// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// Mr. Agent has entered a government library where secret documents are stored.  Documents are stored in different rooms, and each document has a list of user groups that can access it.  In order to access a document, a person must have access to the room in which the document is stored and also be a member of at least one user group with access to the document.  Your task is to determine the number of documents Mr. Agent can access.

You are given a vector <string> userGroups, each element of which is the name of a user group in which Mr. Agent is a member.  You are also given a String[] roomRights, each element of which is the name of a room to which Mr. Agent has access.  The documents are given in the vector <string> records.  Each element of records is formatted "document_name room user_group" (quotes for clarity), where document_name is the name of a document, room is the name of the room where the document is located, and user_group is the name of a user group that has access to the document.  If multiple user groups have access to a document, there will be an entry in records for each group.  All documents have distinct names, all rooms have distinct names, and all user groups have distinct names.  Return the number of documents Mr. Agent can access.


DEFINITION
Class:Library
Method:documentAccess
Parameters:vector <string>, vector <string>, vector <string>
Returns:int
Method signature:int documentAccess(vector <string> records, vector <string> userGroups, vector <string> roomRights)


CONSTRAINTS
-records, userGroups and roomRights will each contain between 0 and 50 elements, inclusive.
-Each element of userGroups and roomRights will contain between 1 and 15 lowercase letters ('a'-'z').
-Each element of records will be formatted as "document_name room user_group" (quotes for clarity), where document_name, room and user_group each contain between 1 and 15 lowercase letters ('a'-'z').
-All elements of records with the same document_name will contain the same room.
-All elements of records will be distinct.
-All elements of userGroups will be distinct.
-All elements of roomRights will be distinct.


EXAMPLES

0)
{"diary computers editor","fairytale gardening editor","comix cars author","comix cars librarian"}
{"employee","editor","author"}
{"history","cars","computers"}

Returns: 2

Mr. Agent only has access to the documents "diary" and "comix".

1)
{"diary computers editor","fairytale gardening editor","comix cars author","comix cars librarian"}
{"employee","editor","author","librarian"}
{"history","cars","computers"}

Returns: 2

Three elements of records satisfy the conditions, but two of them are for the same document (comix).

2)
{"diary computers editor","fairytale gardening editor","comix cars author","comix cars librarian"}
{"employee","editor","author","librarian"}
{}

Returns: 0

Mr. Agent can not access any rooms.

3)
{"a b c","a b d","b b c","b b d","e c d","e c b","e c c","t d e"}
{"c","d","x"}
{"a","b","c"}

Returns: 3



*/
// END CUT HERE

#line 69 "Library.cpp"
#include <string>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <algorithm>
// BEGIN CUT HERE
#include <iostream>
#include "cout.h"
// END CUT HERE
#include <sstream>
#include <cmath>
using namespace std;

#define sz(a)  int((a).size())
#define pb  push_back
#define all(c)  (c).begin(),(c).end()
#define tr(c,i)  for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); i++)
#define rep(var,n)  for(int var=0;var<(n);var++)
#define found(s,e)  ((s).find(e)!=(s).end())
#define remove_(c,val) (c).erase(remove((c).begin(),(c).end(),(val)),(c).end())

vector<string> split(string str, int delim=' ')
{
  vector<string> result;

  const char *s = str.c_str();
  if (delim == ' ') {
    for (const char *p=s; *p; p++) {
      if (*p == delim)
        s++;
      else
        break;
    }
    if (!*s) return result;

    for (const char *p=s; *p; p++) {
      if (*p == delim) {
        if (s < p) {
          string a(s,p-s);
          result.push_back(a);
        }
        s = p + 1;
      }
    }
    if (*s) result.push_back(s);
  } else {
    for (const char *p=s; *p; p++) {
      if (*p == delim) {
        string a(s,p-s);
        result.push_back(a);
        s = p + 1;
        if (*s == '\0') result.push_back("");
      }
    }
    if (*s) result.push_back(s);
  }

  return result;
}

class Library {
 public:
  int documentAccess(vector <string> records, vector <string> userGroups, vector <string> roomRights) {
    map<string,int> ug, rr;
    int Nug=sz(userGroups), Nrr=sz(roomRights);
    rep(i,Nug) ug[userGroups[i]] = i; 
    rep(i,Nrr) rr[roomRights[i]] = i;

    set<string> books;
    tr(records,it){
      vector<string> rec = split(*it);
      //cout << rec << endl;
      if (!found(ug,rec[2])) continue;
      if (!found(rr,rec[1])) continue;
      books.insert(rec[0]);
    }
    return books.size();
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
	string records_[] = {"diary computers editor","fairytale gardening editor","comix cars author","comix cars librarian"};
	  vector <string> records(records_, records_+sizeof(records_)/sizeof(*records_)); 
	string userGroups_[] = {"employee","editor","author"};
	  vector <string> userGroups(userGroups_, userGroups_+sizeof(userGroups_)/sizeof(*userGroups_)); 
	string roomRights_[] = {"history","cars","computers"};
	  vector <string> roomRights(roomRights_, roomRights_+sizeof(roomRights_)/sizeof(*roomRights_)); 
	int RetVal = 2; 
	return verify_case(RetVal, Library().documentAccess(records, userGroups, roomRights)); }
int Test_(Case_<1>) {
	timer_clear();
	string records_[] = {"diary computers editor","fairytale gardening editor","comix cars author","comix cars librarian"};
	  vector <string> records(records_, records_+sizeof(records_)/sizeof(*records_)); 
	string userGroups_[] = {"employee","editor","author","librarian"};
	  vector <string> userGroups(userGroups_, userGroups_+sizeof(userGroups_)/sizeof(*userGroups_)); 
	string roomRights_[] = {"history","cars","computers"};
	  vector <string> roomRights(roomRights_, roomRights_+sizeof(roomRights_)/sizeof(*roomRights_)); 
	int RetVal = 2; 
	return verify_case(RetVal, Library().documentAccess(records, userGroups, roomRights)); }
int Test_(Case_<2>) {
	timer_clear();
	string records_[] = {"diary computers editor","fairytale gardening editor","comix cars author","comix cars librarian"};
	  vector <string> records(records_, records_+sizeof(records_)/sizeof(*records_)); 
	string userGroups_[] = {"employee","editor","author","librarian"};
	  vector <string> userGroups(userGroups_, userGroups_+sizeof(userGroups_)/sizeof(*userGroups_)); 
	vector <string> roomRights; 
	int RetVal = 0; 
	return verify_case(RetVal, Library().documentAccess(records, userGroups, roomRights)); }
int Test_(Case_<3>) {
	timer_clear();
	string records_[] = {"a b c","a b d","b b c","b b d","e c d","e c b","e c c","t d e"};
	  vector <string> records(records_, records_+sizeof(records_)/sizeof(*records_)); 
	string userGroups_[] = {"c","d","x"};
	  vector <string> userGroups(userGroups_, userGroups_+sizeof(userGroups_)/sizeof(*userGroups_)); 
	string roomRights_[] = {"a","b","c"};
	  vector <string> roomRights(roomRights_, roomRights_+sizeof(roomRights_)/sizeof(*roomRights_)); 
	int RetVal = 3; 
	return verify_case(RetVal, Library().documentAccess(records, userGroups, roomRights)); }

template<int N> void Run_() { cerr << "Test Case #" << N << "..." << flush; Test_(Case_<N>()); Run_<sizeof(Test_(Case_<N+1>()))==1 ? -1 : N+1>(); }
template<>      void Run_<-1>() {}
int main() { Run_<0>(); }
// END CUT HERE

