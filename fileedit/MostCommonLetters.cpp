#include <vector>
#include <string>
#include <sstream>
using namespace std;

class MostCommonLetters {
public:
  string listMostCommon(vector<string> text);
};

string
MostCommonLetters::listMostCommon(vector<string> text)
{
  int cnt[26];

  for (int i=0; i<26; i++) cnt[i] = 0;

  for (int i=0,size=text.size(); i<size; i++) {
	string s = text[i];
	for (int j=0,len=s.length(); j<len; j++) {
	  cnt[s.at(j) - 'a']++;
	}
  }

  int max = 0, max_at=-1;
  for (int i=0; i<26; i++) {
	if (cnt[i] > max) {
	  max = cnt[i]; max_at = i;
	}
  }

  stringstream sstr;
  for (int i=0; i<26; i++) {
	char buf[2] = { 0, 0 };
	if (cnt[i] == max) {
	  buf[0] = 'a' + i;
	  sstr << buf;
	}
  }

  return sstr.str();
}


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
