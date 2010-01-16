#include &lt;string>
#include &lt;vector>
#include &lt;map>
#include &lt;set>
#include &lt;queue>
using namespace std;

#define tr(c,i)  for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); i++)
#define found(s,e)  ((s).find(e)!=(s).end())

class WorkersOnPlane {
public:
  int howMany(vector&lt;string> field, int K) {
    int rows = field.size();
    int cols = field[0].size();
    
    vector&lt;pair&lt;int,int> > W;
    
    map&lt;pair&lt;int,int>, int> G, S;
    int gcount = 0, scount = 0;
    
    for (int y=0; y&lt;rows; y++) {
      for (int x=0; x&lt;cols; x++) {
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
    vector&lt;map&lt;int,pair&lt;int,int> > > arc(nodes);
    
    for (int g=0; g&lt;gcount; g++) arc[START][GSTART+g] = make_pair(0,1);
    for (int w=0; w&lt;wcount; w++) arc[WgSTART+w][WsSTART+w] = make_pair(0,1);
    for (int s=0; s&lt;scount; s++) arc[SSTART+s][END] = make_pair(0,1);
    
    for (int w=0; w&lt;wcount; w++) {
      int y = W[w].first, x = W[w].second;
      
      vector&lt;vector&lt;int> > d(rows); // distance
      for (int y=0; y&lt;rows; y++) {
        d[y].resize(cols);
        for (int x=0; x&lt;cols; x++) {
          d[y][x] = INT_MAX;
        }
      }
      priority_queue&lt;pair&lt;int,pair&lt;int,int> > > pq;
      
      pq.push(make_pair(0,make_pair(y,x)));
      
      do {
        int y = pq.top().second.first;
        int x = pq.top().second.second;
        int d_ = -pq.top().first;
        pq.pop();

        if (d_ >= d[y][x]) continue;
        
        switch (field[y][x]) {
        case 'W':
          if (d_ != 0) break;
          // fall through
        case '.':
          //if (!d[y][x]) {
            d[y][x] = d_; //min(d_, d[y][x]);
            if (d_ &lt; K) {
              if (x >= 1)// && !d[y][x-1])
                pq.push(make_pair(-d_-1,make_pair(y,x-1)));
              if (x+1 &lt; cols)// && !p[y][x+1])
                pq.push(make_pair(-d_-1,make_pair(y,x+1)));
              if (y >= 1)// && !p[y-1][x])
                pq.push(make_pair(-d_-1,make_pair(y-1,x)));
              if (y+1 &lt; rows)// && !p[y+1][x])
                pq.push(make_pair(-d_-1,make_pair(y+1,x)));
            }
            //}
          break;
        case 'G':
          {
            d[y][x] = d_;
            int g = G[ make_pair(y,x) ];
            arc[GSTART+g][WgSTART+w] = make_pair(0,1);
          }
          break;
        case 'S':
          {
            d[y][x] = d_;
            int s = S[ make_pair(y,x) ];
            arc[WsSTART+w][SSTART+s] = make_pair(0,1);
          }
          break;
        case 'X':
          break;
        }

        //p[y][x] = true;
        
      } while (!pq.empty());
      
    }

    // remove unreachable Gs/Ss
    for (int g=0; g&lt;gcount; g++) {
      if (arc[GSTART+g].size() == 0) {
        arc[START].erase(GSTART+g);
      }
    }
    vector&lt;bool> ss(scount,false);
    for (int w=0; w&lt;wcount; w++) {
      tr(arc[WsSTART+w],st) { ss[st->first - SSTART] = true; }
    }
    for (int s=0; s&lt;scount; s++) {
      if (!ss[s]) {
        arc[SSTART+s].erase(END);
      }
    }

    // initial
    vector&lt;vector&lt;int> > ways;
    for (int g_=0; g_&lt;gcount; g_++) {
      int g = GSTART+g_;
      
      bool viable = false;
      tr(arc[g],at) {
        if (at->second.first == 1) continue;
        int w = at->first; // key
        //cout &lt;&lt; g &lt;&lt; " - " &lt;&lt; w &lt;&lt; " - " &lt;&lt; arc[w] &lt;&lt; endl;
        if (arc[w][w+wcount].first == 1) continue; //oops
        tr(arc[w+wcount],bt) {
          // bt = arc[ws][s]
          if (bt->second.first == 1) continue;
          int s = bt->first; // key
          if (arc[s][END].first == 1) continue; //oops
          int way_[6] = { START, g, w, w+wcount, s, END };
          vector&lt;int> way(way_, way_+6);
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

    // residual networks
    vector&lt;map&lt;int,int> > resid(nodes);
    for (int j=0; j&lt;nodes; j++) {
      tr(arc[j],at) {
        int k = at->first;
        resid[j][k] = arc[j][k].second - arc[j][k].first;
        resid[k][j] = arc[j][k].first;
      }
    }
    
    if (ways.size() == arc[START].size()) return ways.size();

    // find another way
    for (int i=0; ;i++) {
      bool another_way = false;

      vector&lt;int> prev(nodes,INT_MAX);
      queue&lt;pair&lt;int,int> > q;

      q.push(make_pair(START,-1));

      while (!q.empty()) {
        pair&lt;int,int> p = q.front();
        int node = p.first, prev_node = p.second;
        q.pop();

        prev[node] = prev_node;
        if (node == END) {
          another_way = true;
          break;
        }
        
        tr(resid[node],rt) {
          if (rt->second == 0) continue;
          if (prev[rt->first] &lt; INT_MAX) continue;
          q.push(make_pair(rt->first, node));
        }
      }
      // no more ways
      if (!another_way) return ways.size() + i;

      for (int node=END; node!=START; node=prev[node]) {
        int prev_node = prev[node];
        resid[prev_node][node]--;
        resid[node][prev_node]++;
      }
    }

    return 0;
  }
};
