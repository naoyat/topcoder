// BEGIN CUT HERE
/* SRM422 DIV1 1000pts
// PROBLEM STATEMENT
// You have recently bought a field containing gold and silver, and you want to hire some workers to gather the treasure and build beautiful things with it.  The field is divided into square cells of equal size.  You are given a vector <string> field, where the j-th character of the i-th element is the content of the cell at row i, column j.  A period ('.') represents grass, an uppercase 'X' represents rocks, and uppercase 'G' and 'S' represent gold and silver, respectively.  You have also built special workplace cells for your workers, each denoted by an uppercase 'W'.
Each worker must be assigned exactly one workplace, one gold cell and one silver cell.  None of these three cells can be assigned to any of the other workers.  Each worker will be transporting gold and silver from his cells to his workspace, and for efficiency reasons, you do not want workers to carry anything for more than K meters.  This means every worker's workplace must be at most K meters away from his gold cell and at most K meters away from his silver cell.  Distance is measured as follows.  From each cell, a worker can only move left, right, up or down to an adjacent cell (if one exists).  The distance between two consecutive cells is one meter.  Workers are only allowed to walk on grass when moving between their cells.
Return the largest number of workers you can hire while meeting these requirements.

DEFINITION
Class:WorkersOnPlane
Method:howMany
Parameters:vector <string>, int
Returns:int
Method signature:int howMany(vector <string> field, int K)


CONSTRAINTS
-field will contain between 1 and 30 elements, inclusive.
-Each element of field will contain between 1 and 30 characters, inclusive.
-Each element of field will contain the same number of characters.
-Each character in each element of field will be a period ('.'), an uppercase 'X', an uppercase 'G', an uppercase 'S' or an uppercase 'W'.
-K will be between 1 and 1000, inclusive.


EXAMPLES

0)
{ "G..X",
  "..XS",
  "W..." }
5

Returns: 1



1)
{ "GG..",
  "....",
  "..W.",
  "..W.",
  "SS.." }
4

Returns: 2



2)
{ "GG..",
  "XX..",
  "..W.",
  "..W.",
  "SS.." }
10

Returns: 1

We can hire only one worker, because the gold mine in the top left corner can't be reached from any of the workplaces.

3)
{"G.XXX.S",
 "G..WW.S"}
11

Returns: 0

If we hire a worker for the left workplace, he won't be able to reach any of the silver mines. Similarly, if we hire a worker for the right workplace, he won't be able to reach gold mines. So we can't hire anybody.

*/
// END CUT HERE

#line 73 "WorkersOnPlane.cpp"
#include <string>
#include <vector>
// BEGIN CUT HERE
#include <iostream>
#include "cout.h"
// END CUT HERE
#include <sstream>
#include <map>
#include <set>
#include <queue>
using namespace std;

#define tr(c,i)  for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); i++)
#define found(s,e)  ((s).find(e)!=(s).end())

class WorkersOnPlane {
public:
  int howMany(vector<string> field, int K) {
// BEGIN CUT HERE
//	printf("howMany(field, K=%d)\n", K);
// END CUT HERE
	int rows = field.size();
	int cols = field[0].size();
	
	vector<pair<int,int> > W;
	
	map<pair<int,int>, int> G, S;
	int gcount = 0, scount = 0;
	
	for (int y=0; y<rows; y++) {
// BEGIN CUT HERE
//	  cout << field[y] << endl;
// END CUT HERE
	  for (int x=0; x<cols; x++) {
		int c = field[y][x];
		switch (c) {
		case 'W': W.push_back( make_pair(y,x) ); break;
		case 'G': G[ make_pair(y,x) ] = gcount++; break;
		case 'S': S[ make_pair(y,x) ] = scount++; break;
		default: break;
		}
	  }
	}
	int wcount = W.size();
	
	
	int nodes = 1 + gcount + wcount * 2 + scount + 1;
	const int START = 0,
	  GSTART = 1,
	  WgSTART = GSTART + gcount,
	  WsSTART = WgSTART + wcount,
	  SSTART = WsSTART + wcount,
	  END = nodes - 1; // SSTART + scount
// BEGIN CUT HERE
//	printf("gcount = %d, wcount = %d, scount = %d\n", gcount, wcount, scount);
// END CUT HERE	
	vector<map<int,pair<int,int> > > arc(nodes);
	
	for (int g=0; g<gcount; g++) arc[START][GSTART+g] = make_pair(0,1);
	for (int w=0; w<wcount; w++) arc[WgSTART+w][WsSTART+w] = make_pair(0,1);
	for (int s=0; s<scount; s++) arc[SSTART+s][END] = make_pair(0,1);
	
	for (int w=0; w<wcount; w++) {
	  int y = W[w].first, x = W[w].second;
	  
	  vector<vector<int> > d(rows); // distance
	  for (int y=0; y<rows; y++) {
		d[y].resize(cols);
		for (int x=0; x<cols; x++) {
		  d[y][x] = INT_MAX;
		}
	  }
	  priority_queue<pair<int,pair<int,int> > > pq;
	  
	  pq.push(make_pair(0,make_pair(y,x)));
	  //	  d[y][x] = 0;
	  
	  do {
		int y = pq.top().second.first;
		int x = pq.top().second.second;
		int d_ = -pq.top().first;
// BEGIN CUT HERE
//		printf("pq.top(): %d at (y=%d,x=%d)\n", d_, y, x);
// END CUT HERE
		pq.pop();

		if (d_ >= d[y][x]) continue;
		
		switch (field[y][x]) {
		case 'W':
		  if (d_ != 0) break;
		  // fall through
		case '.':
		  //if (!d[y][x]) {
			d[y][x] = d_; //min(d_, d[y][x]);
			if (d_ < K) {
			  if (x >= 1)// && !d[y][x-1])
				pq.push(make_pair(-d_-1,make_pair(y,x-1)));
			  if (x+1 < cols)// && !p[y][x+1])
				pq.push(make_pair(-d_-1,make_pair(y,x+1)));
			  if (y >= 1)// && !p[y-1][x])
				pq.push(make_pair(-d_-1,make_pair(y-1,x)));
			  if (y+1 < rows)// && !p[y+1][x])
				pq.push(make_pair(-d_-1,make_pair(y+1,x)));
			}
			//}
		  break;
		case 'G':
		  {
			d[y][x] = d_;
			int g = G[ make_pair(y,x) ];
// BEGIN CUT HERE
			//printf("w#%d: found G#%d(%d,%d) at %d\n", w,g,x,y, d_);
// END CUT HERE
			arc[GSTART+g][WgSTART+w] = make_pair(0,1);
		  }
		  break;
		case 'S':
		  {
			d[y][x] = d_;
			int s = S[ make_pair(y,x) ];
// BEGIN CUT HERE
			//printf("w#%d: found S#%d(%d,%d) at %d\n", w,s,x,y, d_);
// END CUT HERE
			arc[WsSTART+w][SSTART+s] = make_pair(0,1);
		  }
		  break;
		case 'X':
		  break;
		}

		//p[y][x] = true;
		
	  } while (!pq.empty());
	  
	}
// BEGIN CUT HERE
/*
	for (int j=0; j<nodes; j++) 
	  cout << "arc[" << j << "]: " << arc[j] << endl;
*/
// END CUT HERE

	// remove unreachable Gs/Ss
	for (int g=0; g<gcount; g++) {
	  if (arc[GSTART+g].size() == 0) {
// BEGIN CUT HERE
//		cout << "unreachable G: " << g << endl;
// END CUT HERE
		arc[START].erase(GSTART+g);
	  }
	}
	vector<bool> ss(scount,false);
	for (int w=0; w<wcount; w++) {
	  tr(arc[WsSTART+w],st) { ss[st->first - SSTART] = true; }
	}
	for (int s=0; s<scount; s++) {
	  if (!ss[s]) {
// BEGIN CUT HERE
//		cout << "unreachable S: " << s << endl;
// END CUT HERE
		arc[SSTART+s].erase(END);
	  }
	}

	// initial
	vector<vector<int> > ways;
	for (int g_=0; g_<gcount; g_++) {
	  int g = GSTART+g_;
	  
	  bool viable = false;
	  tr(arc[g],at) {
		if (at->second.first == 1) continue;
		int w = at->first; // key
		//cout << g << " - " << w << " - " << arc[w] << endl;
		if (arc[w][w+wcount].first == 1) continue; //oops
		tr(arc[w+wcount],bt) {
		  // bt = arc[ws][s]
		  if (bt->second.first == 1) continue;
		  int s = bt->first; // key
		  if (arc[s][END].first == 1) continue; //oops
		  int way_[6] = { START, g, w, w+wcount, s, END };
		  vector<int> way(way_, way_+6);
// BEGIN CUT HERE
		  //cout << "(way) "<< way << endl;
// END CUT HERE
		  ways.push_back(way);
		  arc[START][g].first = 1; // START - G
		  arc[g][w].first = 1; // G - Wg
		  arc[w][w+wcount].first = 1; // Wg - Ws
		  arc[w+wcount][s].first = 1; // Ws - S
		  arc[s][END].first = 1; // S - END
		  viable = true;
		  break;
		}
		if (viable) break;
	  }
	}

// BEGIN CUT HERE
/*
	int w_=0;
	tr(ways,wt) {
   	  cout << "way[" << w_ << "]: " << *wt << endl;
	  w_++;
	}
	cout << nodes << " nodes.\n";
*/
// END CUT HERE
		
	// residual networks
	vector<map<int,int> > resid(nodes);
	/*
	vector<vector<int> > resid(nodes);
	for (int j=0; j<nodes; j++) {
	  resid[j].resize(nodes,-1);
	}
	*/
	for (int j=0; j<nodes; j++) {
	  tr(arc[j],at) {
		int k = at->first;
		resid[j][k] = arc[j][k].second - arc[j][k].first;
		resid[k][j] = arc[j][k].first;
	  }
	}
// BEGIN CUT HERE
//	for (int j=0; j<nodes; j++) 
//	  cout << "resid[" << j << "]: " << resid[j] << endl;
// END CUT HERE
	
	// return ways.size();
	if (ways.size() == arc[START].size()) return ways.size();

	// find another way
	for (int i=0; ;i++) {
	  bool another_way = false;

	  vector<int> prev(nodes,INT_MAX);
	  queue<pair<int,int> > q;

	  q.push(make_pair(START,-1));

	  while (!q.empty()) {
		pair<int,int> p = q.front();
		int node = p.first, prev_node = p.second;
		q.pop();

		prev[node] = prev_node;
		if (node == END) {
		  another_way = true;
		  break;
		}
		
		tr(resid[node],rt) {
		  if (rt->second == 0) continue;
		  if (prev[rt->first] < INT_MAX) continue;
		  q.push(make_pair(rt->first, node));
		}
	  }
	  // no more ways
	  if (!another_way) return ways.size() + i;

// BEGIN CUT HERE
//	  cout << "found another way.." << endl;
// END CUT HERE
	  for (int node=END; node!=START; node=prev[node]) {
		int prev_node = prev[node];
		resid[prev_node][node]--;
		resid[node][prev_node]++;
	  }
	}

	return 0;
  }
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) {
	  if ((Case == -1) || (Case == 0)) test_case_0();
	  if ((Case == -1) || (Case == 1)) test_case_1();
	  if ((Case == -1) || (Case == 2)) test_case_2();
	  if ((Case == -1) || (Case == 3)) test_case_3();

	  if ((Case == -1) || (Case == 6)) test_case_6();
	}
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = { "G..X",
  "..XS",
  "W..." }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; int Arg2 = 1; verify_case(0, Arg2, howMany(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = { "GG..",
  "....",
  "..W.",
  "..W.",
  "SS.." }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; int Arg2 = 2; verify_case(1, Arg2, howMany(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = { "GG..",
  "XX..",
  "..W.",
  "..W.",
  "SS.." }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; int Arg2 = 1; verify_case(2, Arg2, howMany(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"G.XXX.S",
 "G..WW.S"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 11; int Arg2 = 0; verify_case(3, Arg2, howMany(Arg0, Arg1)); }

  void test_case_6() {
	string Arr0[] = { "G...WWWGG.SW..WWG.G...WSW.SGW.",
					  ".S.G..W.S.GSWSW..G...GGG.W.WW.",
					  "W.G.SS..WW.S..GWSS....W..GGS.G",
					  "GW.SSS.W....SSGW.SW.WGG.S..WGG",
					  "GG.SW.WSS..S..S...SWG.WSW.G.S.",
					  "..S.S.GW.GWW.G.S..GWS.G...G...",
					  "GWW..GW.WWGSS..SSG.W.GWW..G.WG",
					  ".WS.G.WW...S...G.G...GW.SSGWSW",
					  "....WWWS.W..GSGG..S.W.G...W...",
					  "..WWWG......WGG.......G.WGGSG.",
					  "..G.W..WWGW....W....SGW.SGSS.W",
					  "W..SWGGG..G.GW..GWS.W.GGS...G.",
					  ".SGS...SS..SS..S..S..GWSWS...W",
					  "..G.GG..GW..S....SS...S....SG.",
					  "WG.SS.GW....WWW.G..G...G.WG...",
					  "........SW.S..W.WWGGGS.....SSW",
					  "..G.S..SGG.WG..W....W..SSS.G.S",
					  ".G..SGS...G..W.GS.SWW.S..SS.WW",
					  "GS.G.SG..GWS........WSWS..S..W",
					  "......SG.WS.W.S....S.G..G.G...",
					  ".W..W.GWGG.S..W..W..SSWGSG...G",
					  "S..W...W..W.SSG..W.G.SS..SWS..",
					  "..SSSS.W.S...W.G....W...W.GWW.",
					  "..G.S.SWGS..GSWSG.WG..W..SG.SG",
					  "S.....GW.S...SSS.W.SSW.S....S.",
					  "....SSG.W..WW....GSWWW..GG..WG",
					  "SS..WW...S..WG.W..SWGGGW...G..",
					  "S...SSSWG...S.SS.GGWSGG.G.....",
					  "...G..G.G.G.W..G..WSS.S....G.S",
					  ".W.SGW..W...G...SG..S..G..WSSG" };
	vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
	int Arg1 = 86;
	verify_case(6, 120, howMany(Arg0, Arg1));
  }

// END CUT HERE

};

// BEGIN CUT HERE
int main(int argc, char *argv[]) {
	WorkersOnPlane ___test;
	___test.run_test(argc == 2 ? atoi(argv[1]) : -1);
}
// END CUT HERE
