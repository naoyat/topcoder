#line 2 "DNADeletion.cpp"
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

class DNADeletion {
  map<string,int> amt;
  map<int,string> amtr;
  map<string,int> t;
  int amti;

  ll sub(string s){
    int l=sz(s);
    if(l<3) return 1;
    if(l==3) return found(t,s)?2:1;

    ll tot=0,lh,mh,rh;
    int h=l/2;

    lh=sub(s.substr(0,h));
    rh=sub(s.substr(h));
    tot += (lh*rh % 1000000007LL);;
    
    lh=sub(s.substr(0,h-1));
    mh=found(t,s.substr(h-1,3))?2:1;
    rh=sub(s.substr(h+2));
    tot += (lh*rh % 1000000007LL);;
    
    lh=sub(s.substr(0,h-2));
    mh=found(t,s.substr(h-2,3))?2:1;
    rh=sub(s.substr(h+1));
    tot += (lh*rh % 1000000007LL);;

    cout << "sub(" << s << ") = " << tot << endl;
    return tot % 1000000007LL;
  }
  set<list<int> > sub0(string s){
    int l=sz(s);
    set<list<int> > r;
    if(l<3) return r;
    if(l==3) {
      if(found(t,s)){
        list<int> li(1,t[s]);
        r.insert(li);
      }
      return r;
    }

    ll tot=0;
    int h=l/2;

    set<list<int> > lh,rh,th;
    lh=sub0(s.substr(0,h));
    rh=sub0(s.substr(h));
    tr(lh,lt){
      tr(rh,rt){
        list<int> li(*lt);
        li.insert(li.end(),all(*rt));
        th.insert(li);
      }
    }

    int mh=-1;
    lh=sub0(s.substr(0,h-1));
    if(found(t,s.substr(h-1,3))) mh=t[s.substr(h-1,3)];
    rh=sub0(s.substr(h+2));
    tot += (lh*rh % 1000000007LL);;
    
    lh=sub(s.substr(0,h-2));
    mh=found(t,s.substr(h-2,3))?2:1;
    rh=sub(s.substr(h+1));
    tot += (lh*rh % 1000000007LL);;

    cout << "sub(" << s << ") = " << tot << endl;
    return tot % 1000000007LL;
  }
 public:
  int differentProteins(vector<string> DNASequence, vector<string> codonTable) {
    string s;
    {
      stringstream ss;
      tr(DNASequence,it) ss << *it;
      s = ss.str();
      //cout << s << endl;
    }
    amti=0;
    tr(codonTable,it){
      string cd=it->substr(0,3),am=it->substr(4);
      int ami;
      if(found(amt,am)) ami=amt[am];
      else{ ami=amt[am]=amti++; amtr[ami]=am;}
      t[cd] = ami;
    }
    cout << t << endl;
    // cout << amtr << endl;

    int res=(int)(sub(s) - 1LL);
    if(res<0) res+=1000000007;
    return res;
  }
};

// BEGIN CUT HERE
#include <time.h>
clock_t start_time;
void timer_clear() { start_time = clock(); }
string timer() { clock_t end_time = clock(); double interval = (double)(end_time - start_time)/CLOCKS_PER_SEC; ostringstream os; os << " (" << interval*1000 << " msec)"; return os.str(); }

template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
int verify_case(const int &Expected, const int &Received) { if (Expected == Received) cerr << "PASSED" << timer() << endl; else { cerr << "FAILED" << timer() << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } return 0;}

template<int N> struct Case_ {};
char Test_(...);
int Test_(Case_<0>) {
	timer_clear();
	string DNASequence_[] = {"ACTG"};
	  vector <string> DNASequence(DNASequence_, DNASequence_+sizeof(DNASequence_)/sizeof(*DNASequence_)); 
	string codonTable_[] = {"ACT gua", "ACG cys", "ATG leu", "CTG thr"};
	  vector <string> codonTable(codonTable_, codonTable_+sizeof(codonTable_)/sizeof(*codonTable_)); 
	int RetVal = 4; 
	return verify_case(RetVal, DNADeletion().differentProteins(DNASequence, codonTable)); }
int Test_(Case_<1>) {
	timer_clear();
	string DNASequence_[] = {"AAACCC"};
	  vector <string> DNASequence(DNASequence_, DNASequence_+sizeof(DNASequence_)/sizeof(*DNASequence_)); 
	string codonTable_[] = {"AAA thr", "CCC cys"};
	  vector <string> codonTable(codonTable_, codonTable_+sizeof(codonTable_)/sizeof(*codonTable_)); 
	int RetVal = 3; 
	return verify_case(RetVal, DNADeletion().differentProteins(DNASequence, codonTable)); }
int Test_(Case_<2>) {
	timer_clear();
	string DNASequence_[] = {"AAATCCC"};
	  vector <string> DNASequence(DNASequence_, DNASequence_+sizeof(DNASequence_)/sizeof(*DNASequence_)); 
	string codonTable_[] = {"AAA gua","TCC dop","AAT dop","CCC gua"};
	  vector <string> codonTable(codonTable_, codonTable_+sizeof(codonTable_)/sizeof(*codonTable_)); 
	int RetVal = 5; 
	return verify_case(RetVal, DNADeletion().differentProteins(DNASequence, codonTable)); }
int Test_(Case_<3>) {
	timer_clear();
	string DNASequence_[] = {"ATGCGCATTAACCTCCTACCATGGAAGGGACGTAACCCGGCAATTTGATC",
 "CTGATGACGGCATAAGCTACCCCTAGAGGTAAAAATGCATACTGCGTGCT",
 "ATGCAG"};
	  vector <string> DNASequence(DNASequence_, DNASequence_+sizeof(DNASequence_)/sizeof(*DNASequence_)); 
	string codonTable_[] = {"AAC RpjZt","AAT ZeiC","GCA ChZwh","TCC RpjZt","GAA I",
 "TAG ZeiC","CTG dVK","GAG ZeiC","GTG I","AAG q","ATT dVK",
 "AGA cJEjM","GGG KONUd","GTC ZRV","GGC ZeiC","TTA KONUd",
 "GAC q","CCA q","GCC ZRV","GCG RpjZt","CCT ZRV","ATG dVK",
 "ATC ChZwh","CTC cJEjM","CCC q","ATA dWjz","TTG DkEG",
 "CAG q","CAA ZRV","ACT dVK","TCG dVK","ACC I","CGC dVK"};
	  vector <string> codonTable(codonTable_, codonTable_+sizeof(codonTable_)/sizeof(*codonTable_)); 
	int RetVal = 455985264; 
	return verify_case(RetVal, DNADeletion().differentProteins(DNASequence, codonTable)); }

template<int N> void Run_() { cerr << "Test Case #" << N << "..." << flush; Test_(Case_<N>()); Run_<sizeof(Test_(Case_<N+1>()))==1 ? -1 : N+1>(); }
template<>      void Run_<-1>() {}
int main() { Run_<0>(); }
// END CUT HERE


// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// In genetics, a DNA sequence is a sequence of nucleotides (A, C, G or T).  Some DNA sequences translate to proteins, which are non-empty sequences of amino acids.  Let's examine the DNA translation process::

From left to right, split the DNA sequence into consecutive, non-overlapping triples of nucleotides.  Each triple is called a codon.  There may be one or two nucleotides left over at the end - those should be ignored.  For example, the DNA sequence "ACCTGTACG" will produce the codon sequence "ACC", "TGT", "ACG".  The DNA sequence "ACCTGTAC" will produce the codon sequence "ACC", "TGT" ("AC" is left over and ignored).
You are given a codon table that maps codons to their associated amino acids.  From left to right, look up each codon in the sequence generated above and replace it with its associated amino acid.  Every codon in the sequence must have an associated amino acid - otherwise, the DNA sequence does not translate to a protein.  For example, if "ACC" and "ACG" each map to threonin ("thr") and "TGT" maps to cysteine ("cys"), the DNA sequence "ACCTGTACG" will translate to the protein "thr cys thr".

Sometimes, after replication, one or more nucleotides in a DNA sequence go missing.  This situation is called deletion.  After a deletion, a DNA sequence can become any of its subsequences.  For example, "ACTG" may become "ACG" or "CG".

You are given a vector <string> DNASequence containing a DNA sequence.  Concatenate the elements of DNASequence to obtain the DNA sequence.  You are also given a vector <string> codonTable containing the codon table.  Each element is formatted "CODON AMINOACID" (quotes for clarity), where AMINOACID is the name of the amino acid associated with codon CODON.  Compute the number of different possible proteins that the given DNA sequence can translate to after undergoing zero or more deletions.  Since this number can be quite large, return its value modulo 1000000007.  Remember that only nonempty amino acid sequences are considered proteins.


DEFINITION
Class:DNADeletion
Method:differentProteins
Parameters:vector <string>, vector <string>
Returns:int
Method signature:int differentProteins(vector <string> DNASequence, vector <string> codonTable)


CONSTRAINTS
-DNASequence will contain between 1 and 50 elements, inclusive.
-Every element of DNASequence will contain between 1 and 50 characters, inclusive.
-Every element of DNASequence will contain only characters 'A', 'C', 'T', 'G'.
-codonTable will contain between 1 and 50 elements, inclusive.
-Every element of codonTable will contain a codon, followed by a single space, followed by an amino acid.
-Every codon in codonTable will contain exactly 3 characters.
-Every codon in codonTable will contain only characters 'A', 'C', 'T', 'G'.
-Every codon in codonTable will be unique.
-Every amino acid in codonTable will contain between 1 and 20 characters.
-Every amino acid in codonTable will contain only letters ('a'-'z', 'A'-'Z').


EXAMPLES

0)
{"ACTG"}
{"ACT gua", "ACG cys", "ATG leu", "CTG thr"}

Returns: 4

You can get proteins:
"gua" (deletion of 'G' or no deletion),
"cys" (deletion of 'T'),
"leu" (deletion of 'C'),
"thr" (deletion of 'A').
Other deletions do not result in proteins.

1)
{"AAACCC"}
{"AAA thr", "CCC cys"}

Returns: 3

You can get proteins: "thr", "cys" and "thr cys".

2)
{"AAATCCC"}
{"AAA gua","TCC dop","AAT dop","CCC gua"}

Returns: 5

You can get proteins:
"gua",
"dop",
"gua dop" (from sequence "AAATCC"),
"dop gua" (from sequence "AATCCC"),
"gua gua" (from sequence "AAACCC").

3)
{"ATGCGCATTAACCTCCTACCATGGAAGGGACGTAACCCGGCAATTTGATC",
 "CTGATGACGGCATAAGCTACCCCTAGAGGTAAAAATGCATACTGCGTGCT",
 "ATGCAG"}
{"AAC RpjZt","AAT ZeiC","GCA ChZwh","TCC RpjZt","GAA I",
 "TAG ZeiC","CTG dVK","GAG ZeiC","GTG I","AAG q","ATT dVK",
 "AGA cJEjM","GGG KONUd","GTC ZRV","GGC ZeiC","TTA KONUd",
 "GAC q","CCA q","GCC ZRV","GCG RpjZt","CCT ZRV","ATG dVK",
 "ATC ChZwh","CTC cJEjM","CCC q","ATA dWjz","TTG DkEG",
 "CAG q","CAA ZRV","ACT dVK","TCG dVK","ACC I","CGC dVK"}

Returns: 455985264

Be sure to concatenate the elements of DNASequence.

*/
// END CUT HERE
