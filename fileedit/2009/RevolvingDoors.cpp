#line 2 "RevolvingDoors.cpp"
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

class RevolvingDoors {
  int w,h;
  
  inline int cell(int x,int y){return (y<<6)|x;}
  inline int cellx(int c){return c&63;}
  inline int celly(int c){return c>>6;}

  inline int left(int c){return c-1;}
  inline int right(int c){return c+1;}
  inline int up(int c){return c-64;}
  inline int down(int c){return c+64;}
 public:
  int turns(vector<string> m) {
    h=sz(m),w=sz(m[0]);

    vector<bool> road(4096,false);
    //vector<int> score(4096,INT_MAX);
    vector<vector<int> > score(4096);
    //rep(i,4096){set<int> s; visited[i]=s;}
    //vector<bool> door(4096,false);
    vector<int> doors, doormap(4096,-1), doorof(4096,-1);
    int doorcnt=0, start_cell=0, end_cell=0;

    // pass1
    rep(y,h){
      rep(x,w){
        int c=cell(x+1,y+1);
        switch(m[y][x]){
          case 'S': road[c]=true; start_cell=c; break;
          case 'E': road[c]=true; end_cell=c; break;
          case 'O': road[c]=false; doormap[c]=doorcnt++; doors.pb(c); break;
          case '-': road[c]=true; break;
          case '|': road[c]=true; break;
          case '#': road[c]=false; break;
          case ' ': road[c]=true; break;
        }
      }
    }
    
// BEGIN CUT HERE
    cout << "doorcnt:" << doorcnt << endl;
    rep(did,sz(doors)){
      int c=doors[did];
      printf("  c=%d, did#%d: (%d,%d)\n", c, did, cellx(c),celly(c) );
    }
// END CUT HERE
    int nm=1<<doorcnt;
    rep(i,4096){
      score[i].resize(nm); rep(j,nm) score[i][j]=INT_MAX;
    }
    
    int doorstat = 0;
    // pass2
    rep(y,h){
      rep(x,w){
        int c=cell(x+1,y+1), r,l,u,d,did=-1;
        switch(m[y][x]){
          case 'O': case '#': break;
          case '-':
            r=right(c),l=left(c);
            if(doormap[r]>=0) did=doormap[r];
            else if(doormap[l]>=0) did=doormap[l];
            doorof[c]=did;
            // doorstat |= (1 << did);
            break;
          case '|':
            u=up(c),d=down(c);
            if(doormap[u]>=0) did=doormap[u];
            else if(doormap[d]>=0) did=doormap[d];
            doorof[c]=did;
            doorstat |= (1 << did);
            break;
          case ' ': case 'S': case 'E':
            r=right(c),l=left(c),u=up(c),d=down(c);
            if(doormap[r]>=0) did=doormap[r];
            else if(doormap[l]>=0) did=doormap[l];
            else if(doormap[u]>=0) did=doormap[u];
            else if(doormap[d]>=0) did=doormap[d];
            doorof[c]=did;
            break;
        }
      }
    }
// BEGIN CUT HERE
    cout << endl;
    rep(y,h){
      cout << "|";
      rep(x,w) cout << m[y][x];
      cout << "|" << endl;
    }
    cout << "doormap:" << endl;
    rep(did,sz(doors)){
      //int did=doormap[c];
      int c=doors[did];
      printf("  #%d: (%d,%d):%c\n", did, cellx(c),celly(c), (doorstat & (1<<did))?'|':'-');
    }
    cout << endl;
// END CUT HERE

    // check impasse
    vector<bool> reach(4096,false);
    set<int> s0;
    s0.insert(start_cell); // reach[start_cell]=true;
    while(!s0.empty()){
      typeof(s0.begin()) it = s0.begin();
      int c=*it; s0.erase(it);
      reach[c]=true;
      if (c==end_cell) break;
      printf(" I %d %d\n", cellx(c),celly(c));
      int nxt[4] = { up(c), right(c), down(c), left(c) };
      rep(i,4){
        int c_=nxt[i];
        if(!road[c_]) continue;
        if(!reach[c_]) s0.insert(c_);
      }
    }
    if(!reach[end_cell]) return -1;

    priority_queue<pair<int,pair<int,int> > > pq; // -score,loc,doorstat
    pq.push(make_pair(0,make_pair(start_cell,doorstat)));

    vector<int> goaled; int goaled_min=INT_MAX;
    
    while(!pq.empty()){
      pair<int,pair<int,int> > p=pq.top(); pq.pop();
      int sc=-p.first, c=p.second.first, ds=p.second.second;
      if (sc>goaled_min) break;
      if (score[c][ds]<=sc) continue;
// BEGIN CUT HERE
      printf("c(%2d,%2d) score:%d doorstat:", cellx(c),celly(c), sc);
      for(int i=0,m=1;i<doorcnt;i++,m<<=1) putchar((ds & m)?'|':'-');
      cout << endl;
// END CUT HERE
      score[c][ds]=sc;
      if(c==end_cell) {
        if (sc<goaled_min) {
// BEGIN CUT HERE
          printf("END<score:%d>\n", sc);
// END CUT HERE
          goaled_min=sc; goaled.pb(sc); }
        continue;
      }
      int nxt[4] = { up(c), right(c), down(c), left(c) };
      rep(i,4){
        int c_=nxt[i];
        if(!road[c_]) continue;
// BEGIN CUT HERE
        printf("  %c:", "urdl"[i]);
// END CUT HERE
        int did=doorof[c_];
        if(did>=0){ // ドアな可能性あり
          int dcell=doors[did], ofs=c_-dcell; if(ofs<0) ofs=-ofs;
          int mask=1<<did;
          int st=ds & mask;
// BEGIN CUT HERE
          printf("door#%d dcell=(%d,%d),|ofs|=%d,stat=%c",
                 did,cellx(dcell),celly(dcell),ofs,st?'|':'-');
// END CUT HERE
          if(st && ofs==64) { // |
            if (c-c_ != c_-dcell){ //回転出来る
              pq.push(make_pair(-(sc+1),make_pair(c_,ds-mask)));
            }
          } else if(!st && ofs==1){ // -
            if (c-c_ != c_-dcell){ //回転出来る
              pq.push(make_pair(-(sc+1),make_pair(c_,ds+mask)));
            }
          } else {
            // ドアなし
            pq.push(make_pair(-sc,make_pair(c_,ds)));
          }
        }else{
          pq.push(make_pair(-sc,make_pair(c_,ds)));
        }
// BEGIN CUT HERE
        cout <<endl;
// END CUT HERE
      }
    }

    if(sz(goaled) > 0){
      sort(all(goaled));
// BEGIN CUT HERE
      cout << "GOALED: " << goaled << endl;
// END CUT HERE
      return goaled[0];
    } else {
      return -1;
    }
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
	string map_[] = { "    ### ",
  "    #E# ",
  "   ## # ",
  "####  ##",
  "# S -O-#",
  "# ###  #",
  "#      #",
  "########" };
	  vector <string> map(map_, map_+sizeof(map_)/sizeof(*map_)); 
	int RetVal = 2; 
	return verify_case(RetVal, RevolvingDoors().turns(map)); }
int Test_(Case_<1>) {
	timer_clear();
	string map_[] = { "#### ",
  "#S|##",
  "# O #",
  "##|E#",
  " ####" }
;
	  vector <string> map(map_, map_+sizeof(map_)/sizeof(*map_)); 
	int RetVal = -1; 
	return verify_case(RetVal, RevolvingDoors().turns(map)); }
int Test_(Case_<2>) {
	timer_clear();
	string map_[] = { " |  |  |     |  |  |  |  |  | ",
  " O  O EO -O- O  O  O  O  OS O ",
  " |  |  |     |  |  |  |  |  | " }
;
	  vector <string> map(map_, map_+sizeof(map_)/sizeof(*map_)); 
	int RetVal = 7; 
	return verify_case(RetVal, RevolvingDoors().turns(map)); }
int Test_(Case_<3>) {
	timer_clear();
	string map_[] = { "###########",
  "#    #    #",
  "#  S | E  #",
  "#    O    #",
  "#    |    #",
  "#         #",
  "###########" };
	  vector <string> map(map_, map_+sizeof(map_)/sizeof(*map_)); 
	int RetVal = 0; 
	return verify_case(RetVal, RevolvingDoors().turns(map)); }
int Test_(Case_<4>) {
	timer_clear();
	string map_[] = { "        E",
  "    |    ",
  "    O    ",
  "    |    ",
  " -O-S-O- ",
  "    |    ",
  "    O    ",
  "    |    ",
  "         " }
;
	  vector <string> map(map_, map_+sizeof(map_)/sizeof(*map_)); 
	int RetVal = -1; 
	return verify_case(RetVal, RevolvingDoors().turns(map)); }
int Test_(Case_<5>) {
	timer_clear();
	string map_[] = { "##E#   ",
  "#  ##  ",
  " -O-## ",
  " #  ## ",
  " ##  ##",
  "  -O-  ",
  "##  ## ",
  " # ### ",
  " #  S  " };
	  vector <string> map(map_, map_+sizeof(map_)/sizeof(*map_)); 
	int RetVal = 5; 
	return verify_case(RetVal, RevolvingDoors().turns(map)); }
int Test_(Case_<6>) {
	timer_clear();
	string map_[] = { "#############",
  "#  #|##|#   #",
  "#   O  O    #",
  "# E || || S #",
  "#    O  O   #",
  "#   #|##|#  #",
  "#############" };
	  vector <string> map(map_, map_+sizeof(map_)/sizeof(*map_)); 
	int RetVal = 4; 
	return verify_case(RetVal, RevolvingDoors().turns(map)); }
int Test_(Case_<7>) { // Test Case 26
	timer_clear();
	string map_[] = {
      "S                                                 ",
      "                                                  ",
      "                                                  ",
      "-O--O--O--O--O--O--O--O--O--O-                    ",
      "                                                  ",
      "                                                  ",
      "                                                  ",
      "                                                  ",
      "                                                  ",
      "                                                  ",
      "                                                  ",
      "                                                  ",
      "                                                  ",
      "                                                  ",
      "                                                  ",
      "                                                  ",
      "                                                  ",
      "                                                  ",
      "                                                  ",
      "                                                  ",
      "                                                  ",
      "                                                  ",
      "                                                  ",
      "                                                  ",
      "                                                  ",
      "                                                  ",
      "                                                  ",
      "                                                  ",
      "                                                  ",
      "                                                  ",
      "                                                  ",
      "                                                  ",
      "                                                  ",
      "                                                  ",
      "                                                  ",
      "                                                  ",
      "                                                  ",
      "                                                  ",
      "                                                  ",
      "                                                  ",
      "                                                  ",
      "                                                  ",
      "                                                  ",
      "                                                  ",
      "                                                  ",
      "                                                  ",
      "                                                  ",
      "                                                  ",
      "                                                 #",
      "                                                #E" };
    vector <string> map(map_, map_+sizeof(map_)/sizeof(*map_)); 
	int RetVal = -1; 
	return verify_case(RetVal, RevolvingDoors().turns(map)); }



template<int N> void Run_() { cerr << "Test Case #" << N << "..." << flush; Test_(Case_<N>()); Run_<sizeof(Test_(Case_<N+1>()))==1 ? -1 : N+1>(); }
template<>      void Run_<-1>() {}
int main() { Run_<0>(); }
// END CUT HERE


// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 

You are in a maze containing revolving doors.  The doors can be turned 90
degrees by pushing against them in either direction.  You are to find a
route from the start square to the end square that involves revolving as few
doors as possible.  Given a map of the maze, determine the fewest number of
door revolutions necessary to get from the start to the end.


In the map:



   ' ': empty space
   '#': wall
   'O': center of a revolving door (letter "oh", not zero)
   '-': horizontal door (always adjacent to a 'O')
   '|': vertical door (always adjacent to a 'O')
   'S': start square
   'E': end square



Each revolving door will always be oriented horizontally (with two horizontal segments) or vertically (with two vertical segments):


    |
    O  or  -O-
    |


Doors can be revolved 90 degrees by moving onto a door segment from any of the 4 squares diagonally adjacent to the door center, i.e., the 'X' characters below:


   X|X     X X
    O  or  -O-
   X|X     X X


Here is an example map:


        ###
        #E#
       ## #
    ####  ##
    # S -O-#
    # ###  #
    #      #
    ########


In this example, 2 door revolutions are necessary to get from 'S' to 'E'.  The first turn is shown here:


        ###         ###
        #E#         #E#
       ## #        ## #
    ####  ##    #### |##
    # S -O-#    # S  OX#
    # ### X#    # ###| #
    #      #    #      #
    ########    ########


And the second turn is shown here:


        ###         ###
        #E#         #E#
       ## #        ## #
    ####X|##    #### X##
    # S  O #    # S -O-#
    # ###| #    # ###  #
    #      #    #      #
    ########    ########



Your method should return an int, the minimum number of door revolutions necessary to get from the start square to the end square.
If there is no way to reach the end square, return -1.



DEFINITION
Class:RevolvingDoors
Method:turns
Parameters:vector <string>
Returns:int
Method signature:int turns(vector <string> map)


NOTES
-Assume that all squares off the edge of the map are walls.


CONSTRAINTS
-map will contain between 3 and 50 elements, inclusive.
-Each element of map will contain between 3 and 50 characters, inclusive.
-Each element of map will contain the same number of characters.
-Each character in map will be one of 'S', 'E', 'O', '-', '|', '#', and ' ' (space).
-There will be exactly one 'S' and one 'E' in map.
-There will be between 1 and 10 doors, inclusive, and they will be formatted in map as described in the problem statement.
-No two doors will be close enough for any part of them to occupy the same square.
-It is not allowed for a door to be blocked and unable to turn.  There will not be any walls in any of the 4 squares immediately adjacent to the center of a door, nor will a door be on the edge of the map.


EXAMPLES

0)
{ "    ### ",
  "    #E# ",
  "   ## # ",
  "####  ##",
  "# S -O-#",
  "# ###  #",
  "#      #",
  "########" }

Returns: 2

This is the example from the problem statement.

1)
{ "#### ",
  "#S|##",
  "# O #",
  "##|E#",
  " ####" }


Returns: -1

There is no way to reach the end square.

2)
{ " |  |  |     |  |  |  |  |  | ",
  " O  O EO -O- O  O  O  O  OS O ",
  " |  |  |     |  |  |  |  |  | " }


Returns: 7

The optimal path involves turning the 3rd door twice, and the 5th, 6th, 7th, 8th, and 9th doors once each (counting from the left).  Note that the 'S' and 'E' do not block doors, and in fact you must turn the 3rd door twice to end up on the 'E'.


3)
{ "###########",
  "#    #    #",
  "#  S | E  #",
  "#    O    #",
  "#    |    #",
  "#         #",
  "###########" }

Returns: 0

4)
{ "        E",
  "    |    ",
  "    O    ",
  "    |    ",
  " -O-S-O- ",
  "    |    ",
  "    O    ",
  "    |    ",
  "         " }


Returns: -1

You are stuck, unable to move or turn any doors from this position.

5)
{ "##E#   ",
  "#  ##  ",
  " -O-## ",
  " #  ## ",
  " ##  ##",
  "  -O-  ",
  "##  ## ",
  " # ### ",
  " #  S  " }

Returns: 5

6)
{ "#############",
  "#  #|##|#   #",
  "#   O  O    #",
  "# E || || S #",
  "#    O  O   #",
  "#   #|##|#  #",
  "#############" }

Returns: 4

After all the doors have been turned, the map looks like this:


    #############
    #  # ## #   #
    #  -O--O-   #
    # E       S #
    #   -O--O-  #
    #   # ## #  #
    #############


*/
// END CUT HERE
