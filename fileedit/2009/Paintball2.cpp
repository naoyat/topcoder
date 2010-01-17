#line 2 "Paintball.cpp"
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

class Paintball {
 public:
  vector<string> getLeaderboard(vector<string> players, vector<string> messages) {
    map<string,int> ppoint,tpoint;
    map<string,string> team;
    tr(players,it){
      vector<string> s=split(*it);
      string p=s[0], t=s[1];
      team[p]=t;
      ppoint[p]=tpoint[t]=0;
    }
    tr(messages,it){
      vector<string> s=split(*it);
      string p1=s[0], p2=s[2];
      string t1=team[p1], t2=team[p2];
      if(p1==p2){
        ppoint[p1]--;
        tpoint[t1]--;
      }else{
        if(t1==t2){
          ppoint[p1]--;
          tpoint[t1]--;
        }else{
          ppoint[p1]++;
          tpoint[t1]++;
          ppoint[p2]--;
          tpoint[t2]--;
        }
      }
    }
    vector<pair<int,string> > tx;
    tr(tpoint,it) tx.pb(make_pair(-it->second,it->first));
    sort(all(tx));

    vector<string> res;
    tr(tx,it){
      stringstream sst;
      sst << it->second << " " << -(it->first);
      res.pb(sst.str());

      vector<pair<int,string> > px;
      tr(team,jt) if(jt->second==it->second) px.pb(make_pair(-ppoint[jt->first],jt->first));
      sort(all(px));
      tr(px,jt){
        stringstream ssp;
        ssp << "  " << jt->second << " " << -(jt->first);
        res.pb(ssp.str());
      }
    }
    return res;
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
	string players_[] = {"A RED", "B BLUE"};
	  vector <string> players(players_, players_+sizeof(players_)/sizeof(*players_)); 
	string messages_[] = {"A SPLATTERED B"};
	  vector <string> messages(messages_, messages_+sizeof(messages_)/sizeof(*messages_)); 
	string RetVal_[] = {"RED 1", "  A 1", "BLUE -1", "  B -1" };
	  vector <string> RetVal(RetVal_, RetVal_+sizeof(RetVal_)/sizeof(*RetVal_)); 
	return verify_case(RetVal, Paintball().getLeaderboard(players, messages)); }
int Test_(Case_<1>) {
	timer_clear();
	string players_[] = {"LISA RED", "BART RED", "HOMER BLUE", "MARGE BLUE", "MAGGIE GREEN"};
	  vector <string> players(players_, players_+sizeof(players_)/sizeof(*players_)); 
	string messages_[] = {"MAGGIE SPLATTERED HOMER", "MAGGIE SPLATTERED MARGE"};
	  vector <string> messages(messages_, messages_+sizeof(messages_)/sizeof(*messages_)); 
	string RetVal_[] = {"GREEN 2", "  MAGGIE 2", "RED 0", "  BART 0", "  LISA 0", "BLUE -2", "  HOMER -1", "  MARGE -1" };
	  vector <string> RetVal(RetVal_, RetVal_+sizeof(RetVal_)/sizeof(*RetVal_)); 
	return verify_case(RetVal, Paintball().getLeaderboard(players, messages)); }
int Test_(Case_<2>) {
	timer_clear();
	string players_[] = {"TODD STRIKEFORCE",
 "BART OMEGA",
 "DATA STRIKEFORCE",
 "MILHOUSE OMEGA",
 "NELSON DISCOVERYCHANNEL",
 "MARTIN DISCOVERYCHANNEL"};
	  vector <string> players(players_, players_+sizeof(players_)/sizeof(*players_)); 
	string messages_[] = {"BART SPLATTERED MARTIN","TODD SPLATTERED MARTIN"};
	  vector <string> messages(messages_, messages_+sizeof(messages_)/sizeof(*messages_)); 
	string RetVal_[] = {"OMEGA 1", "  BART 1", "  MILHOUSE 0", "STRIKEFORCE 1", "  TODD 1", "  DATA 0", "DISCOVERYCHANNEL -2", "  NELSON 0", "  MARTIN -2" };
	  vector <string> RetVal(RetVal_, RetVal_+sizeof(RetVal_)/sizeof(*RetVal_)); 
	return verify_case(RetVal, Paintball().getLeaderboard(players, messages)); }
int Test_(Case_<3>) {
	timer_clear();
	string players_[] = {"DR COHO", "ST COHO", "PE COHO"};
	  vector <string> players(players_, players_+sizeof(players_)/sizeof(*players_)); 
	string messages_[] = {"DR SPLATTERED ST",
 "ST SPLATTERED PE"};
	  vector <string> messages(messages_, messages_+sizeof(messages_)/sizeof(*messages_)); 
	string RetVal_[] = {"COHO -2", "  PE 0", "  DR -1", "  ST -1" };
	  vector <string> RetVal(RetVal_, RetVal_+sizeof(RetVal_)/sizeof(*RetVal_)); 
	return verify_case(RetVal, Paintball().getLeaderboard(players, messages)); }
int Test_(Case_<4>) {
	timer_clear();
	string players_[] = {"A B", "AA AA", "AAA AAA"};
	  vector <string> players(players_, players_+sizeof(players_)/sizeof(*players_)); 
	string messages_[] = {"A SPLATTERED AAA", "A SPLATTERED AAA", "A SPLATTERED AAA", 
"AA SPLATTERED AAA", "AA SPLATTERED AAA"};
	  vector <string> messages(messages_, messages_+sizeof(messages_)/sizeof(*messages_)); 
	string RetVal_[] = {"B 3", "  A 3", "AA 2", "  AA 2", "AAA -5", "  AAA -5" };
	  vector <string> RetVal(RetVal_, RetVal_+sizeof(RetVal_)/sizeof(*RetVal_)); 
	return verify_case(RetVal, Paintball().getLeaderboard(players, messages)); }

template<int N> void Run_() { cerr << "Test Case #" << N << "..." << flush; Test_(Case_<N>()); Run_<sizeof(Test_(Case_<N+1>()))==1 ? -1 : N+1>(); }
template<>      void Run_<-1>() {}
int main() { Run_<0>(); }
// END CUT HERE


// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
For his birthday, Bart received the brand new video game "Paintball!".  In this game, a person plays on teams over the Internet against various competitors, attempting to hit their opponents with paint balls.  Each player earns a point each time that they "splatter" an opponent with a paintball, and lose a point for each time they get "splattered".  Due to the way that the game is played, it is also possible to accidentally splatter yourself or a teammate.  In that case, the shooter loses a point, and the person who was splattered (if not the shooter) does not lose any points.  A team's score is simply the sum of the scores of its players.

Although Bart loves the game, he is disappointed that the game does not provide a leaderboard during gameplay.  However, it does provide the list of players, formatted as "NAME TEAM" (where NAME is the player's name, and TEAM is his team), and a series of messages, each formatted as "NAME1 SPLATTERED NAME2" (all quotes for clarity), where NAME1 indicates the name of the person who shot the paintball, and NAME2 indicates the name of the person who got splattered.  Bart would like to have an updated scoreboard, and that is where you come in.

All teams will receive a rank number from 1 to M (the total number of teams), based on the team scores (with 1 corresponding to the highest score).  If multiple teams have the same score, then the team with the name that comes first alphabetically will receive a lower rank number.  For each team (in order from 1 to M), its leaderboard entry will be formatted as follows:

The first line will be "TEAM SCORE" (quotes for clarity), where TEAM is the team name, and SCORE is the team score (with no extra leading zeroes).
Let N be the number of players on the team.  Assign rank numbers to the N players from 1 to N, giving a lower rank number to a higher score.  If multiple players have the same score, assign the player whose name comes first alphabetically to the lower rank number.
From the player with rank 1 to rank N, output a line with 2 spaces, the player's name, a single space, and then the player's score (with no extra leading zeroes).  

Thus, if player A from team RED splatters player B from team BLUE (and they are the only players in the game), the leaderboard will be:

RED 1
  A 1
BLUE -1
  B -1

You are to generate the leaderboard and return it.


DEFINITION
Class:Paintball
Method:getLeaderboard
Parameters:vector <string>, vector <string>
Returns:vector <string>
Method signature:vector <string> getLeaderboard(vector <string> players, vector <string> messages)


NOTES
-A SCORE of 0 should be output as 0, not as -0.


CONSTRAINTS
-players will contain between 1 and 50 elements, inclusive.
-Each element of players will contain between 3 and 50 characters, inclusive.
-Each element of players will be formatted as "NAME TEAM" (quotes for clarity).
-In each element of players, NAME will consist of uppercase characters ('A'-'Z') and will contain at least 1 character.
-There will be no duplicate NAMEs in players.
-In each element of players, TEAM will consist of uppercase characters ('A'-'Z') and will contain at least 1 character.
-messages will contain between 1 and 50 elements, inclusive.
-Each element of messages will contain between 14 and 50 characters, inclusive.
-Each element of messages will be formatted as described in the problem statement.
-In each element of messages, NAME1 and NAME2 will be NAMEs found in players.


EXAMPLES

0)
{"A RED", "B BLUE"}
{"A SPLATTERED B"}

Returns: {"RED 1", "  A 1", "BLUE -1", "  B -1" }

The example from the statement.

1)
{"LISA RED", "BART RED", "HOMER BLUE", "MARGE BLUE", "MAGGIE GREEN"}
{"MAGGIE SPLATTERED HOMER", "MAGGIE SPLATTERED MARGE"}

Returns: {"GREEN 2", "  MAGGIE 2", "RED 0", "  BART 0", "  LISA 0", "BLUE -2", "  HOMER -1", "  MARGE -1" }



2)
{"TODD STRIKEFORCE",
 "BART OMEGA",
 "DATA STRIKEFORCE",
 "MILHOUSE OMEGA",
 "NELSON DISCOVERYCHANNEL",
 "MARTIN DISCOVERYCHANNEL"}
{"BART SPLATTERED MARTIN","TODD SPLATTERED MARTIN"}

Returns: {"OMEGA 1", "  BART 1", "  MILHOUSE 0", "STRIKEFORCE 1", "  TODD 1", "  DATA 0", "DISCOVERYCHANNEL -2", "  NELSON 0", "  MARTIN -2" }



3)
{"DR COHO", "ST COHO", "PE COHO"}
{"DR SPLATTERED ST",
 "ST SPLATTERED PE"}

Returns: {"COHO -2", "  PE 0", "  DR -1", "  ST -1" }

Don't shoot your teammates!

4)
{"A B", "AA AA", "AAA AAA"}
{"A SPLATTERED AAA", "A SPLATTERED AAA", "A SPLATTERED AAA", 
"AA SPLATTERED AAA", "AA SPLATTERED AAA"}

Returns: {"B 3", "  A 3", "AA 2", "  AA 2", "AAA -5", "  AAA -5" }



*/
// END CUT HERE
