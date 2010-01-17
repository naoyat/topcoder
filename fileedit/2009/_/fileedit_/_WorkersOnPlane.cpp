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
	int rows = field.size();
	int cols = field[0].size();
	
	vector<pair<int,int> > W;
	
	map<pair<int,int>, int> G, S;
	int gcount = 0, scount = 0;
	
	for (int y=0; y<rows; y++) {
// BEGIN CUT HERE
	  cout << field[y] << endl;
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
	
	
	int nodes = wcount * 4 + 2; // start + G + W + W + S + end
	const int START = 0,
	  GSTART = 1,
	  WgSTART = GSTART + wcount,
	  WsSTART = WgSTART + wcount,
	  SSTART = WsSTART + wcount,
	  END = nodes - 1;
	
	vector<map<int,pair<int,int> > > arc(nodes);
	
	for (int i=0; i<wcount; i++) {
	  arc[START][GSTART+i] = make_pair(0,1);
	  arc[WgSTART+i][WsSTART+i] = make_pair(0,1);
	  arc[SSTART+i][END] = make_pair(0,1);
	}
	
	for (int i=0; i<wcount; i++) {
	  int y = W[i].first, x = W[i].second;
	  // printf("workplace #%d at (%d,%d)\n", i, x, y);
	  
	  vector<vector<bool> > p(rows); // painted
	  vector<vector<int> > d(rows); // distance
	  for (int y=0; y<rows; y++) {
		p[y].resize(cols, false);
		d[y].resize(cols, K+1);
	  }
	  priority_queue<pair<pair<int,int>,int> > pq;
	  
	  pq.push(make_pair(make_pair(y,x),0));
	  d[y][x] = 0;
	  
	  do {
		int y = pq.top().first.first;
		int x = pq.top().first.second;
		int d_ = pq.top().second;
		pq.pop();
		
		p[y][x] = true;
		
		switch (field[y][x]) {
		case 'W':
		  if (d_ != 0) break;
		  // fall through
		case '.':
		  d[y][x] = d_;
		  if (d_ < K) {
			if (x >= 1 && !p[y][x-1])
			  pq.push(make_pair(make_pair(y,x-1),d_+1));
			if (x+1 < cols && !p[y][x+1])
			  pq.push(make_pair(make_pair(y,x+1),d_+1));
			if (y >= 1 && !p[y-1][x])
			  pq.push(make_pair(make_pair(y-1,x),d_+1));
			if (y+1 < rows && !p[y+1][x])
			  pq.push(make_pair(make_pair(y+1,x),d_+1));
		  }
		  break;
		case 'G':
		  {
			d[y][x] = d_;
			int g = G[ make_pair(y,x) ];
			arc[GSTART+g][WgSTART+i] = make_pair(0,1);
		  }
		  break;
		case 'S':
		  {
			d[y][x] = d_;
			int s = S[ make_pair(y,x) ];
			arc[WsSTART+i][SSTART+s] = make_pair(0,1);
		  }
		  break;
		case 'X':
		  break;
		}
		
	  } while (!pq.empty());
	  
	}

	// remove unreachable Gs/Ss
	vector<bool> ss(wcount,false);
	for (int i=0; i<wcount; i++) {
	  if (arc[GSTART+i].size() == 0) {
// BEGIN CUT HERE
		cout << "unreachable G: " << i << endl;
// END CUT HERE
		arc[START].erase(GSTART+i);
	  }
	  tr(arc[WsSTART+i],st) { ss[st->first - SSTART] = true; }
	}
	for (int i=0; i<wcount; i++) {
	  if (!ss[i]) {
// BEGIN CUT HERE
		cout << "unreachable S: " << i << endl;
// END CUT HERE
		arc[SSTART+i].erase(END);
	  }
	}

	// initial
	vector<vector<int> > ways;
	for (int g_=0; g_<wcount; g_++) {
	  int g = GSTART+g_;
	  
	  bool viable = false;
	  tr(arc[g],at) {
		if (at->second.first == 1) continue;
		int w = at->first; // key
		//cout << g << " - " << w << " - " << arc[w] << endl;
		tr(arc[w+wcount],bt) {
		  if (bt->second.first == 1) continue;
		  int s = bt->first; // key
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
	cout << "ways: " << ways << endl;
// END CUT HERE
		
	// residual networks
	vector<map<int,int> > resid(nodes);
	for (int j=0; j<nodes; j++) {
	  tr(arc[j],at) {
		int k = at->first;
		resid[j][k] = arc[j][k].second - arc[j][k].first;
		resid[k][j] = arc[j][k].first;
	  }
	}
// BEGIN CUT HERE
	for (int j=0; j<nodes; j++) 
	  cout << "resid[" << j << "]: " << resid[j] << endl;
// END CUT HERE
	
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
	  cout << "found another way.." << endl;
// END CUT HERE
	  for (int node=END; node!=START; node=prev[node]) {
		int prev_node = prev[node];
		resid[prev_node][node]--;
		resid[node][prev_node]++;
	  }
	}
  }
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
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

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	WorkersOnPlane ___test;
	___test.run_test(-1);
}
// END CUT HERE
