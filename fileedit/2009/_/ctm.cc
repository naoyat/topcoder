#include <string>
#include <vector>
#include <set>
#include <list>
#include <queue>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <float.h> // DBL_MAX
using namespace std;

#define sz(a)   int((a).size())
#define pb      push_back
#define all(c)  (c).begin(),(c).end()
#define tr(c,i) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); i++)

double maxnum = DBL_MAX; // 平面が無限遠に伸びているので2000とか10000とかでは駄目です

class CatchTheMice {
public:
  double largestCage(vector<int> xp, vector<int> yp, vector<int> xv, vector<int> yv) {
    int n=xp.size(); // 1..50

    set<double> tx;
    tx.clear();

    // 全鼠総当たりで（高々1225通り）
    for (int i=0;i<n;i++) {
      for (int j=0;j<n;j++) {
        if (i < j)  {
          // x座標上で追い越し／追い越される時刻を得て
          if (xv[i] != xv[j]) {
            double t = (double)(xp[i] - xp[j]) / (double)(xv[j] - xv[i]);
            if (t > 0.0) tx.insert(t); // >0ならsetに放り込む。
          }
          // y座標上で追い越し／追い越される時刻を得て
          if (yv[i] != yv[j]) {
            double t = (double)(yp[i] - yp[j]) / (double)(yv[j] - yv[i]);
            if (t > 0.0) tx.insert(t); // 同様。重複はsetが良きに計らってくれる
          }
        }
      }
    }

    // t=0 における全鼠の座標と、wx=(x最大-x最小), wy=(y最大-y最小) を求めておく
    double wx_, wy_, t_ = 0.0; // ここでアンダーバーは「１つ前の値」マーク
    {
      double xmin = maxnum, xmax = -maxnum, ymin = maxnum, ymax = -maxnum;
      for (int i=0;i<n;i++) {
        double x = (double)xp[i];
        double y = (double)yp[i];
        if (x < xmin) xmin = x;
        if (x > xmax) xmax = x;
        if (y < ymin) ymin = y;
        if (y > ymax) ymax = y;
      }
      wx_ = xmax - xmin;
      wy_ = ymax - ymin;
    }
    double mmw = max(wx_,wy_); // 籠の大きさ

    // setに放り込んでおいた時刻をイテレータで順に取り出して
    // それぞれの時刻における全鼠の座標を算出し、
    // wx=(x最大-x最小), wy=(y最大-y最小) を求める。
    tr(tx,it) {
      double t = *it;
      double xmin = maxnum, xmax = -maxnum, ymin = maxnum, ymax = -maxnum;
      for (int i=0;i<n;i++) {
        double x = t*xv[i] + xp[i];
        double y = t*yv[i] + yp[i];
        if (x < xmin) xmin = x;
        if (x > xmax) xmax = x;
        if (y < ymin) ymin = y;
        if (y > ymax) ymax = y;
      }
      double wx = xmax - xmin;
      double wy = ymax - ymin;

      if (((wx_ < wy_ && wx > wy) || (wx_ > wy_ && wx < wy))) {
        // wx,wyの最大をとる座標軸が入れ替わる場合
        double dx = wx - wx_, dy = wy - wy_;
        double w = (wx_ * dy - wy_ * dx) / (dy - dx); // wはこの時刻における籠の大きさの最小値
        // printf("crossing between t=%g and t=%g... at %g\n", t_, t, (wx_ - wy_) / (dy - dx) );
        if (w < mmw) mmw = w;
      } else {
        // 入れ替わらない場合
        double w = max(wx,wy);
        if (w < mmw) mmw = w;
      }
      wx_ = wx;
      wy_ = wy;
      t_ = t;
    }

    return mmw;
  }
};
