#line 2 "WordFind.cpp"
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
#define all(c)  (c).begin(),(c).end()
#define mset(arr,val)  memset(arr,val,sizeof(arr))
#define tr(c,i)  for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); i++)
#define rep(var,n)  for(int var=0;var<(n);var++)
#define forr(var,from,to) for(int var=(from);var<=(to);var++) 
#define found(s,e)  ((s).find(e)!=(s).end())
#define remove_(c,val) (c).erase(remove((c).begin(),(c).end(),(val)),(c).end())
#define lastc(str) (*((str).end()-1))

class WordFind {
  string str(int y, int x){
    stringstream ss;
    ss << y << " " << x;
    return ss.str();
  }
 public:
  vector <string> findWords(vector <string> grid, vector <string> wordList) {
    int gw=sz(grid[0]),gh=sz(grid);
    int n=sz(wordList);
	vs ans(n,"");
    rep(i,n){
      vector<pair<int,int> > buf;
      string w=wordList[i]; char w0=w[0]; int l=sz(w);
      // yoko
      for(int y=0;y<gh;y++){
        for(int x=0;x<=gw-l;x++){
          if(grid[y][x]!=w0) goto fail1;
          for(int z=1;z<l;z++){
            if(grid[y][x+z]!=w[z]) goto fail1;
          }
          buf.pb(make_pair(y,x));
          // ans[i] = str(y,x);
          goto cont1; 
       fail1:;
        }
      }
   cont1:
      // tate
      for(int y=0;y<=gh-l;y++){
        for(int x=0;x<gw;x++){
          if(grid[y][x]!=w0) goto fail2;
          for(int z=1;z<l;z++){
            if(grid[y+z][x]!=w[z]) goto fail2;
          }
          buf.pb(make_pair(y,x));
          // ans[i] = str(y,x);
          goto cont2;
       fail2:;
        }
      }
   cont2:
      // naname
      for(int y=0;y<=gh-l;y++){
        for(int x=0;x<=gw-l;x++){
          if(grid[y][x]!=w0) goto fail3;
          for(int z=1;z<l;z++){
            if(grid[y+z][x+z]!=w[z]) goto fail3;
          }
          buf.pb(make_pair(y,x));
          // ans[i] = str(y,x);
          goto cont3;
       fail3:;
        }
      }
   cont3:
      sort(all(buf));
      if (sz(buf) > 0) ans[i] = str(buf[0].first, buf[0].second);
    }
    return ans;
  }
};

// BEGIN CUT HERE
#include <time.h>
clock_t start_time;
void timer_clear() { start_time = clock(); }
string timer() { clock_t end_time = clock(); double interval = (double)(end_time - start_time)/CLOCKS_PER_SEC; ostringstream os; os << " (" << interval*1000 << " msec)"; return os.str(); }

template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
int verify_case(const vector <string> &Expected, const vector <string> &Received) { if (Expected == Received) cerr << "PASSED" << timer() << endl; else { cerr << "FAILED" << timer() << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } return 0;}

template<int N> struct Case_ {};
char Test_(...);
int Test_(Case_<0>) {
	timer_clear();
	string grid_[] = {"TEST",
 "GOAT",
 "BOAT"};
	  vector <string> grid(grid_, grid_+sizeof(grid_)/sizeof(*grid_)); 
	string wordList_[] = {"GOAT", "BOAT", "TEST"};
	  vector <string> wordList(wordList_, wordList_+sizeof(wordList_)/sizeof(*wordList_)); 
	string RetVal_[] = { "1 0",
  "2 0",
  "0 0" };
	  vector <string> RetVal(RetVal_, RetVal_+sizeof(RetVal_)/sizeof(*RetVal_)); 
	return verify_case(RetVal, WordFind().findWords(grid, wordList)); }
int Test_(Case_<1>) {
	timer_clear();
	string grid_[] = {"SXXX",
 "XQXM",
 "XXLA",
 "XXXR"};
	  vector <string> grid(grid_, grid_+sizeof(grid_)/sizeof(*grid_)); 
	string wordList_[] = {"SQL", "RAM"};
	  vector <string> wordList(wordList_, wordList_+sizeof(wordList_)/sizeof(*wordList_)); 
	string RetVal_[] = { "0 0",
  "" };
	  vector <string> RetVal(RetVal_, RetVal_+sizeof(RetVal_)/sizeof(*RetVal_)); 
	return verify_case(RetVal, WordFind().findWords(grid, wordList)); }
int Test_(Case_<2>) {
	timer_clear();
	string grid_[] = {"EASYTOFINDEAGSRVHOTCJYG",
 "FLVENKDHCESOXXXXFAGJKEO",
 "YHEDYNAIRQGIZECGXQLKDBI",
 "DEIJFKABAQSIHSNDLOMYJIN",
 "CKXINIMMNGRNSNRGIWQLWOG",
 "VOFQDROQGCWDKOUYRAFUCDO",
 "PFLXWTYKOITSURQJGEGSPGG"};
	  vector <string> grid(grid_, grid_+sizeof(grid_)/sizeof(*grid_)); 
	string wordList_[] = {"EASYTOFIND", "DIAG", "GOING", "THISISTOOLONGTOFITINTHISPUZZLE"};
	  vector <string> wordList(wordList_, wordList_+sizeof(wordList_)/sizeof(*wordList_)); 
	string RetVal_[] = { "0 0",
  "1 6",
  "0 22",
  "" };
	  vector <string> RetVal(RetVal_, RetVal_+sizeof(RetVal_)/sizeof(*RetVal_)); 
	return verify_case(RetVal, WordFind().findWords(grid, wordList)); }

int Test_(Case_<3>) {//4
	timer_clear();
	string grid_[] =
        {"HWKJMQJYLBROBVMVKNPIPHSDBHQUEBCEXHNCXNGOSTXW", "IOYPXYSVWHLXCKSDLICXQQAAAPWFCKNEWOVHSONIIXNU", "YFCUBURDZIQTWTNCCLJBUTKDLTXNAAGYGAPJBKCCMWEA", "LWLIHEFHDAZFPXOAZQYOLIYPLBQXQNKLVXYCECULWHVT", "SMHNHOWTDMZCHRPSBUDRASINHPYEALGXHVYQXTGSUXLN", "PCHRFBCJBGVUDBKESKMTXJFBWBLOZZDNJIXZQTDEZJTB", "HXACWCWNBNXLGMRMGEUTREVTXGYUUAJLGNMPPJPJHRVK", "AWGQBVHXOQGEMYKUOCZDPIQHXFBKDGTRHCMEAKIPBONJ", "ZGGYIMWHUTGXULLUCRLVBDPFQGSNDWWNWPGUCDHALEDA", "IABTTISOIVXZKVFHWLPURJFBWXOOAZZJOWGJQPHNDDRO", "XNQOIFAIYZWKSSXABQRNLVFUFXAKNYFEQSTBLDJGGWBM", "RMRNDMXFCWGGCRQVOETXEWJIJAXTBJOXTDCHSZNBMVRW", "THYKFSPZZIEDAVZZYYCJANMLKNHSSSSTTERXOLBNQNBC", "NLWCLANMLPBERMZVSISDPTSWPIKRRWTVVVUGBXOZDGFP", "CIJCPQXDVJSAKFWQPTBAAUCQHCALBJCWDKGEJNPXAMOA", "YBUNYQSJDIAITZRPGXCDLDKRBYBPQMZMITLNGVNLEIVO", "YYIBTSMQKYPGSSPJGTUBNECTCVHYEQWLJKTMQTMKRFQP", "IVLKJTTLOHAKXZUOEFJDOURNXWJSSJGJYCXVNVQHNYMP", "ITUXFZQVCLYVOAMQCUHFQNHVHLGGKBVNUMBQHUYRLVIB"};
	  vector <string> grid(grid_, grid_+sizeof(grid_)/sizeof(*grid_)); 
	string wordList_[] = {"XBHHFW", "NAPJ", "VIELNVG", "J", "NBTHFBUILWQRT", "GXFFVE", "XG", "AWR", "ZGGYIMWHUTGXULLUCRLVBDPFQGSNDWWNWPGUCDHA", "PM", "PGXCDLDKRBYBPQMZMIT", "R", "NAB", "FBQFYOAN", "EAIGK", "WLPURJFBW", "PLRSTKO", "JPC", "FBPI", "CZBSGOCWBOYSPGG", "C", "DU", "MZMQPBYBRKDLDCXGPRZTIAIDJSQYN", "JGTUBNECTCVHYEQWLJKTMQTMKRF", "BG", "R", "VIBUREYVW", "BITIDFLPY", "AOXP", "EBHLYGUZAZ", "CCXZMCWJFJSRAYCN", "DNSG", "J", "NPACT"};
	  vector <string> wordList(wordList_, wordList_+sizeof(wordList_)/sizeof(*wordList_)); 
      string RetVal_[] = {"1 4", "", "", "0 3", "4 23", "", "6 1", "", "8 0", "12 6", "15 15", "0 10", "2 14", "", "13 11", "9 16", "", "", "", "2 16", "0 30", "", "", "16 15", "5 8", "0 10", "", "7 4", "", "", "", "", "0 3", ""};
	  vector <string> RetVal(RetVal_, RetVal_+sizeof(RetVal_)/sizeof(*RetVal_)); 
	return verify_case(RetVal, WordFind().findWords(grid, wordList)); }


template<int N> void Run_() { cerr << "Test Case #" << N << "..." << flush; Test_(Case_<N>()); Run_<sizeof(Test_(Case_<N+1>()))==1 ? -1 : N+1>(); }
template<>      void Run_<-1>() {}
int main() { Run_<0>(); }
// END CUT HERE


// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// You have been given a "word search" puzzle, which consists of a rectangular grid of letters, in which several words are hidden.  Each word may begin anywhere in the puzzle, and may be oriented in any straight line horizontally, vertically, or diagonally.  However, the words must all go down, right, or down-right.  (see examples)

You are given a vector <string>, grid, indicating the letters in the grid to be searched.  Character j of element i of grid is the letter at row i, column j.  You are also given a vector <string>, wordList, indicating the words to be found in the grid.  You are to return a vector <string> indicating the locations of each word within the grid.

The return value should have the same number of elements as wordList.  Each element of wordList corresponds to the element of the return value with the same index.

Each element of the return value should be formatted as "row col" (quotes added for clarity), where row is the 0-based row in which the first letter of the word is found, and col is the 0-based column in which the first letter of the word is found.  If the same word can be found more than once, the location in the lowest-indexed row should be returned.  If there is still a tie, return the location with the lowest-indexed column.  If a word cannot be found in the grid, return an empty string for that element.



DEFINITION
Class:WordFind
Method:findWords
Parameters:vector <string>, vector <string>
Returns:vector <string>
Method signature:vector <string> findWords(vector <string> grid, vector <string> wordList)


CONSTRAINTS
-grid will contain between 1 and 50 elements, inclusive.
-Each element of grid will contain between 1 and 50 characters, inclusive.
-Each element of grid will contain the same number of characters.
-Each character of each element of grid will be 'A'-'Z'.
-wordList will contain between 1 and 50 elements, inclusive.
-Each element of wordList will contain between 1 and 50 characters, inclusive.
-Each character of each element of wordList will be 'A'-'Z'.


EXAMPLES

0)
{"TEST",
 "GOAT",
 "BOAT"}
{"GOAT", "BOAT", "TEST"}

Returns: { "1 0",
  "2 0",
  "0 0" }

These words are pretty easy to find.

1)
{"SXXX",
 "XQXM",
 "XXLA",
 "XXXR"}
{"SQL", "RAM"}

Returns: { "0 0",
  "" }

While "RAM" may be found going up at "3 3", we are only allowing words that go down and right.

2)
{"EASYTOFINDEAGSRVHOTCJYG",
 "FLVENKDHCESOXXXXFAGJKEO",
 "YHEDYNAIRQGIZECGXQLKDBI",
 "DEIJFKABAQSIHSNDLOMYJIN",
 "CKXINIMMNGRNSNRGIWQLWOG",
 "VOFQDROQGCWDKOUYRAFUCDO",
 "PFLXWTYKOITSURQJGEGSPGG"}
{"EASYTOFIND", "DIAG", "GOING", "THISISTOOLONGTOFITINTHISPUZZLE"}

Returns: { "0 0",
  "1 6",
  "0 22",
  "" }

*/
// END CUT HERE
