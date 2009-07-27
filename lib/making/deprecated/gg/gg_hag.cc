//#include <stack>

#include <vector> // ベクタ、というか配列というか
#include <set> // 集合
#include <hash_map> // key,value; map<s,i> = set<s>
//#include <hash>

#include <iostream>
using namespace std;


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


bool addx(int x, vector<int> a)
{
  hash_map<int,bool> m;
  for (typeof(a.begin()) it=a.begin(); it!=a.end(); it++) {
	m[x - *it] = true;
  }
  for (typeof(a.begin()) it=a.begin(); it!=a.end(); it++) {
	if (m[*it]) return true;
  }
  return false;
  /*
  set<int> s;
  for (typeof(a.begin()) it=a.begin(); it!=a.end(); it++) {
	s.insert(x - *it);
  }
  dump_set(s);

  for (typeof(a.begin()) it=a.begin(); it!=a.end(); it++) {
	if (s.find(*it) != s.end()) return true;
  }
  return false;
  */
}

int main()
{
  vector<int> a(5);
  a[0] = 5; a[1] = 35; a[2] = 40; a[3] = 75; a[4] = 100;

  cout << addx(105, a) << endl;
  cout << addx(106, a) << endl;
}
