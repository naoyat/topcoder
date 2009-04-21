#include <vector>
#include <string>
#include <set>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;

class TemplateMatching {
public:
  string bestMatch(string text, string prefix, string suffix);
};

int match_prefix(string text, string prefix)
{
  int text_len = text.length(), pref_len = prefix.length();
  for (int sub_len=prefix.length(); sub_len > 0; sub_len--) {
	if (sub_len > text_len) continue;

	string pref_sub = prefix.substr(pref_len - sub_len, string::npos);
	string text_sub = text.substr(0, sub_len);
	if (pref_sub == text_sub) return sub_len;
  }
  return 0;
}
int match_suffix(string text, string suffix)
{
  int text_len = text.length(), suff_len = suffix.length();
  for (int sub_len=suff_len; sub_len > 0; sub_len--) {
	if (sub_len > text_len) continue;

	string suff_sub = suffix.substr(0, sub_len);
	string text_sub = text.substr(text_len - sub_len, string::npos);
	if (suff_sub == text_sub) return sub_len;
  }
  return 0;
}

string
TemplateMatching::bestMatch(string text, string prefix, string suffix)
{
  // Sの最初のn文字がprefixの最後のn文字と同じで同じ順序(n>=0)
  // Sの最後のm文字がsuffixの最初のm文字と同じで同じ順序(m>=0)
  map<string,int> M;

  int max_score = 0;
  string max_str = "";

  int text_len = text.length();
  for (int i=0; i<text_len; i++) {
	for (int j=i+1; j<=text_len; j++) {
	  string s = text.substr(i, j-i);
	  int n = match_prefix(s, prefix);
	  int m = match_suffix(s, suffix);
	  int score = n + m;
	  if (score >= max_score) {
		max_score = score;
		max_str = s;
		M[s] = score;
	  }
	}
  }

  set<string> result;

  map<string,int>::const_iterator it = M.begin();
  while (it != M.end()) {
	if (it->second == max_score) {
	  result.insert(it->first);
	}
	it++;
  }

  for (set<string>::const_iterator it = result.begin(); it != result.end(); it++) {
	return *it;
  }

  return text.substr(text_len-1, string::npos); // "*"
}

main()
{
  TemplateMatching tm;

  cout << tm.bestMatch("something", "awesome", "ingenious") << "\n"; // something OK
  cout << tm.bestMatch("havka","eto","papstvo") << "\n"; // a
  cout << tm.bestMatch("havkj","eto","papstvo") << "\n"; // a
  cout << tm.bestMatch("abracadabra","habrahabr","bracket") << "\n"; // abrac OK
  cout << tm.bestMatch("mississippi","promise","piccolo") << "\n"; // ippi XX why
  cout << tm.bestMatch("a a a a a a","a a","a") << "\n"; // a a OK
  cout << tm.bestMatch("ab","b","a") << "\n"; // a OK
}
