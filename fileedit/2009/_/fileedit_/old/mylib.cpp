int factorial(int x)
{
  int val = 1;
  for (int i=x; i>1; i--) val *= i;
  return val;
}

int c(int n, int m) // combination
{
  return factorial(n) / (factorial(m) * factorial(n - m));
}



class Stat {
public:
  int myUnits;
  int barHp;
  int hisUnits;
public:
  Stat(int m,int b,int h) {
	myUnits = m; barHp = b; hisUnits = h;
  }
  bool impossible() { return (barHp > 0 && hisUnits >= (myUnits << 1)) ? true : false; }
};

typedef struct StatCmp {
  bool operator () ( Stat* left, Stat* right) {
	if (left->myUnits == right->myUnits) {
	  return (left->barHp + left->hisUnits) > (right->barHp + right->hisUnits);
	} else {
	  return left->myUnits > right->myUnits;
	}
  }
} StatCmp;

typedef priority_queue<Stat*,vector<Stat*>,StatCmp> pqueue;

pqueue pq;
pq.push(new Stat(myUnits_, barHp_, hisUnits_));
while (!pq.empty()) {
  Stat* stat = pq.top();
  ...;
 }
pq.pop();
