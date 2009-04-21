// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// In a typical filesystem, there are files, representing complete units of data.  These files are contained in directories, and these directories, in turn, may be contained in other directories, and so on. A path is a pointer to a specific file or directory in this stucture. Most Unix-like OSes have a single root directory, that has all other directories and files directly or indirectly (via other directories) inside it. Such OSes use the following structure for file paths:
/<directory-name>/<directory-name>/.../<directory-name>/<file-name>
and, correspondingly, the following structure for directory paths:
/<directory-name>/<directory-name>/.../<directory-name>
For example, "/etc/passwd" (all quotes here and below are for clarity only) points to a file named "passwd" inside a directory named "etc" inside the root directory. Other valid file names might be "/home/user/pictures/me" or just "/file". In this problem, we allow only nonempty sequences of lowercase letters ('a'-'z') as file and directory names.
A special case is the root directory itself, which is referred to as just "/".
When a user works with such an OS, one of the directories is chosen as 'current'. Such a designation allows her to refer to the files in that directory without specifying the full path to the current directory. For example, if the current directory is "/home/user/pictures", then one might refer to the file "/home/user/pictures/me" as just "me" (note that such a short form can be easily spotted by the absence of the starting '/' character). Moreover, the files in subdirectories of the current directory can also be referred to in a short manner: "/home/user/pictures/others/she" can be referred to as "others/she".
And even more exciting is the ability to have short references for files outside the current folder. More specifically, ".." means "the directory one level above the current directory", "../.." means "the directory two levels above the current directory", and so on. For example, if the current directory is "/home/user/pictures", and you want to refer to "/home/top/data/file", you can express that as "../../top/data/file".
Given a string path, indicating the complete path to the file that needs to be referred to, and a string currentDir, indicating the current directory, return a String that contains the relative path to that file according to the above rules. You should choose the shortest of all possible relative paths (for example, if the current directory is "/home/user/pictures", you should use "../movies/title" and not "../../user/movies/title" as a pointer to "/home/user/movies/title").
Some files and/or directories may have coinciding names, but it is impossible to have two files or two directories or a file and a directory with the same name inside the same directory, so file and directory paths are not ambiguous. It is guaranteed that the given data describes a valid file and directory according to the above rules. In particular, they will not contradict - for example, path="/home/user/some" and currentDir="/home/user/some/other" are a contradiction, since it implies that a file and a directory both named "some" exist inside the directory "/home/user".

DEFINITION
Class:RelativePath
Method:makeRelative
Parameters:string, string
Returns:string
Method signature:string makeRelative(string path, string currentDir)


NOTES
-A file name never ends with the '/' character.  A directory name never ends with the '/' character, with the exception of the root directory, which is specified as just "/".


CONSTRAINTS
-path and currentDir will each contain between 1 and 50 characters, inclusive.
-Each character of path and currentDir will be '/', or a lowercase letter ('a'-'z').
-path will contain a valid file path according to the above rules.
-currentDir will contain a valid directory path according to the above rules.
-path and currentDir will not contradict (see the last paragraph of the statement).


EXAMPLES

0)
"/home/top/data/file"
"/home/user/pictures"

Returns: "../../top/data/file"

The example from the problem statement.

1)
"/home/user/movies/title"
"/home/user/pictures"

Returns: "../movies/title"

And another one from the statement.

2)
"/file"
"/"

Returns: "file"

Remember about the root directory.

3)
"/a/b/a/b/a/b"
"/a/b/a/a/b/a/b"

Returns: "../../../../b/a/b"

Some file and directory names may be the same.

4)
"/root/root/root"
"/root"

Returns: "root/root"

Some files and/or directories can be named "root" - but that doesn't make them root directories.

*/
// END CUT HERE

#line 81 "RelativePath.cpp"
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


class RelativePath {
public:
  string makeRelative(string path, string currentDir) {
    vector<string> vp = split(path,'/'), vcd = split(currentDir,'/');
    int lp=sz(vp), lcd=sz(vcd);
    int common=0;
    if(currentDir=="/") { lcd=1; common=0;}
    else
      for(int i=1;i<min(lp,lcd);i++){
        if(vp[i]!=vcd[i]) break;
        common++;
      }
    string dest=""; rep(i,lcd-1-common) dest+="../";
    for(int i=1+common;i<lp;i++) {dest+=vp[i];if(i<lp-1)dest+="/";}
    return dest;
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
	string path = "/home/top/data/file"; 
	string currentDir = "/home/user/pictures"; 
	string RetVal = "../../top/data/file"; 
	return verify_case(RetVal, RelativePath().makeRelative(path, currentDir)); }
int Test_(Case_<1>) {
	timer_clear();
	string path = "/home/user/movies/title"; 
	string currentDir = "/home/user/pictures"; 
	string RetVal = "../movies/title"; 
	return verify_case(RetVal, RelativePath().makeRelative(path, currentDir)); }
int Test_(Case_<2>) {
	timer_clear();
	string path = "/file"; 
	string currentDir = "/"; 
	string RetVal = "file"; 
	return verify_case(RetVal, RelativePath().makeRelative(path, currentDir)); }
int Test_(Case_<3>) {
	timer_clear();
	string path = "/a/b/a/b/a/b"; 
	string currentDir = "/a/b/a/a/b/a/b"; 
	string RetVal = "../../../../b/a/b"; 
	return verify_case(RetVal, RelativePath().makeRelative(path, currentDir)); }
int Test_(Case_<4>) {
	timer_clear();
	string path = "/root/root/root"; 
	string currentDir = "/root"; 
	string RetVal = "root/root"; 
	return verify_case(RetVal, RelativePath().makeRelative(path, currentDir)); }

template<int N> void Run_() { cerr << "Test Case #" << N << "..." << flush; Test_(Case_<N>()); Run_<sizeof(Test_(Case_<N+1>()))==1 ? -1 : N+1>(); }
template<>      void Run_<-1>() {}
int main() { Run_<0>(); }
// END CUT HERE

