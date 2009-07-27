#include <vector> // ベクタ、というか配列というか
#include <set> // 集合
#include <map> // ハッシュみたいだけど赤黒木実装だよん
#include <iostream>
using namespace std;

// ostream& operator<<(ostream &s, vector<string> ar)

template <typename T> void dump_vector(vector<T> ar)
{
  int items_cnt = ar.size();
  cout << "[ ";
  for (int i=0; i<items_cnt; i++) {
	if (i > 0) cout << ", ";
	cout << ar[i];
  }
  cout << " ]  // " << items_cnt << (items_cnt >= 2 ? " items" : " item") << endl;
}

void dump_vs(vector<string> ar)
{
  int items_cnt = ar.size();
  cout << "[ ";
  for (int i=0; i<items_cnt; i++) {
	if (i > 0) cout << ", ";
	cout << "\"" << ar[i] << "\"";
  }
  cout << " ]  // " << items_cnt << (items_cnt >= 2 ? " items" : " item") << endl;
}

template <typename T> void dump_set(set<T> s)
{
  int items_cnt = s.size();
  cout << "[ ";
  for (typeof(s.begin()) it=s.begin(); it!=s.end(); it++) {
	if (it != s.begin()) cout << ", ";
	cout << *it;
  }
  cout << " ]  // " << items_cnt << (items_cnt >= 2 ? " items" : " item") << endl;
}

template <typename T1, typename T2> void dump_map(map<T1,T2> s)
{
  int items_cnt = s.size();
  cout << "{ ";
  for (typeof(s.begin()) it=s.begin(); it!=s.end(); it++) {
	if (it != s.begin()) cout << ", ";
	cout << it->first << " => " << it->second;
  }
  cout << " }  // " << items_cnt << (items_cnt >= 2 ? " items" : " item") << endl;
}

template <typename T1, typename T2> void dump_vector_of_pair(vector< pair<T1,T2> > ar)
//void dump_ii_array(vector< pair<int,int> > ar)
{
  int items_cnt = ar.size();
  cout << "[ ";
  for (int i=0; i<items_cnt; i++) {
	if (i > 0) cout << ", ";
	cout << "(" << ar[i].first << "," << ar[i].second << ")";
  }
  cout << " ]  // " << items_cnt << (items_cnt >= 2 ? " items" : " item") << endl;
}
