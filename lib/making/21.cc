//#include <stack>

#include <vector> // ベクタ、というか配列というか
#include <set> // 集合
#include <map> // ハッシュ

#include <iostream>
/*
typedef vector<int> vi;
typedef vector<vi> vvi;
#define sz(a) int((a).size())
typedef pair<int,int> ii;
#define pb push_back
#define all(c) c.begin(),c.end()
#define tr(container,it) \
  for(typeof(container.begin()) it=container.begin(); it!=container.end(); it++)
*/
#include "dump.cc"

using namespace std;
/*
vector<int> emptyVector()
{
  vector<int> v;
  return v;
}
*/

void learn_vector()
{
  vector<int> N;

  vector< vector<int> > CorrectDefinition;
  //  vector<vector<int>> WrongDefinition;
  
  vector<int> v1(10);
  cout << v1.size() << endl;
  for(int i=0; i<10; i++) v1[i] = (i+1) * (i+1);
  for(int i=9; i>0; i--) v1[i] -= v1[i-1];

  //  vector<int> v2 = emptyVector();
  //  cout << "size() = " << v2.size() << ", empty() = " << v2.empty() << endl;
  // non-empty は !v.empty() みたいに調べる。size()は必ずしもO(1)ではない

  vector<int> v3[10]; // これは vector<int>[10] な型
  //  cout << v3.size() << endl;

  vector<int> c(50,1); // [1,1,1,1,1,...,1]
  // 次の２つは同じ
  cout << c[5] << endl;
  cout << c.at(5) << endl;

  vector<int> a(10,1);
  dump_vector(a); // [1,1,1,1,1,1,1,1,1,1]

  a.push_back(2);
  dump_vector(a); // [1,1,1,1,1,1,1,1,1,1,<2>]

  a.resize(15);
  dump_vector(a); // [1,1,1,1,1,1,1,1,1,1,2,0,0,0,0]

  for (int i=0; i<7; i++) a.pop_back();
  dump_vector(a); // [1,1,1,1,1,1,1,1]

  cout << a.size() << endl; // must show 8
  cout << a.back() << endl; // returns 1=a[7], but dont remove
  cout << a.size() << endl; // must show 8
  a.clear();
  cout << a.size() << endl; // must show 0
  dump_vector(a); // [ ]

  vector<int> b(10,1); // [1,1,1,1,1,1,1,1,1,1]
  b.push_back(2); // [1,1,1,1,1,1,1,1,1,1,<2>]
  b.resize(15); // [1,1,1,1,1,1,1,1,1,1,2,0,0,0,0]
  // cout << b.at(9) << "," << b.at(10) << "," << b.at(11) << endl; // 1,2,0
  dump_vector(b);

  //  sort(&b[0], &b[15]);
  sort(b.begin(), b.end());
  // => [0,0,0,0,1,1,1,1,1,1,1,1,1,1,2]
  //cout << b.at(9) << "," << b.at(10) << "," << b.at(11) << endl; // 1,1,1
  dump_vector(b);

}
/*
// less_than operatorを定義する
bool operator<(const MyStruct &a, const MyStruct &b)
{
  // return true if A<B; false if A>=B
}
*/
 //#include <pair>

void learn_pair()
{
  int N,x,y;
  vector< pair<int,int> > a;
  cin >> N;
  for (int i=0; i<N; i++) {
	cin >> x >> y;
	a.push_back( make_pair(x,y) );
	// a.push_back(pair<int,int>(x,y));
  }
  dump_vector_of_pair(a);

  sort(a.begin(), a.end()); // first then second
  dump_vector_of_pair(a);
}

void learn_set()
{
  set<int> a;
  a.insert(2);
  a.insert(7);
  a.insert(2);
  a.insert(5);
  a.insert(3);
  dump_set(a); // [2,3,5,7]

  a.erase(5); // remove integer 5 if exists
  dump_set(a); // [2,3,7]

  if (a.find(7) != a.end())
	cout << "7 found." << endl; // Integer 7 exists in the set
  else
	cout << "7 not found." << endl; // Integer 7 does not exist in the set

  set<int> b, un, in, di;
  b.insert(1); b.insert(3); b.insert(5); b.insert(7); b.insert(9);
  dump_set(a); // [ 2, 3, 7 ]
  dump_set(b); // [ 1, 3, 5, 7, 9 ]
  set_union( a.begin(), a.end(), b.begin(), b.end(), insert_iterator<set<int> >(un,un.begin()) );
  dump_set(un); // [ 1, 2, 3, 5, 7, 9 ]
  set_intersection( a.begin(), a.end(), b.begin(), b.end(), insert_iterator<set<int> >(in,in.begin()) );
  dump_set(in); // [ 3, 7 ]
  set_difference( a.begin(), a.end(), b.begin(), b.end(), insert_iterator<set<int> >(di,di.begin()) );
  dump_set(di); // [ 2 ]
  
  a.clear();
  dump_set(a); // [ ]

  cout << "Conversions:" << endl;
  vector<int> v0(3);
  v0[0] = 9; v0[1] = 4; v0[2] = 1; //= { 9, 4, 1 };
  dump_vector(v0);

  set<int> s0(v0.begin(), v0.end()); // vector --> set
  dump_set(s0);
}

void doit(const int &t) { cout << t << endl; }
void learn_map()
{
  map<string,int> a;
  a["New York"] = 7;
  a["Los Angeles"] = 8;
  a["Boston"] = 10;
  a["Los Angeles"] = 3;
  dump_map(a);

  cout << a["Los Angeles"] << endl; // prints 3
  cout << a["San Francisco"] << endl; // prints 0
  dump_map(a); // SFが追加されている
  /*
  set<int> u;
  map<string,string> v;
  
  for (set<int>::iterator i=u.begin(); i!=u.end(); i++) {
	cout << *i << endl;
  }
  for (map<string,string>::iterator i=v.begin(); i!=v.end(); i++) {
	cout << i->first << " => " << i->second << endl;
  }
  */
  set<int> b;
  b.insert(3); b.insert(2); b.insert(2);
  for_each(b.begin(), b.end(), doit);
}

int main()
{
  // learn_vector();
  // learn_pair();
  // learn_set();
  learn_map();
}
