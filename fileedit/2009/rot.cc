#include <vector>
using namespace std;

pair<int,int> turn(pair<int,int> dir, int deg){
  // 時計回りにdeg度回転
  if (deg<0) deg=360-((-deg)%360);
  else deg%=360;
  switch(deg){
    case 0: case 360: default:
      return dir;
    case 180:
      dir.first = -dir.first;
      dir.second = -dir.second;
      return dir;
    case 90:
      dir.first = -dir.second;
      dir.second = dir.first;
      return dir;
    case 270:
      dir.first = dir.second;
      dir.second = -dir.first;
      return dir;
  }
}
