#include <string>
#include <vector>
using namespace std;

vector<string> split(string str, int delim=' ')
{
  vector<string> result;

  const char *s = str.c_str();
  if (delim == ' ') {
    for (const char *p=s; *p; p++) {
      if (*p == delim) s++;
      else break;
    }
    if (!*s) return result;

    for (const char *p=s; *p; p++) {
      if (*p == delim) {
        if (s < p) {
          string a(s,p-s);
          result.push_back(a);
        }
        s = p + 1;
      }
    }
    if (*s) result.push_back(s);
  } else {
    for (const char *p=s; *p; p++) {
      if (*p == delim) {
        string a(s,p-s);
        result.push_back(a);
        s = p + 1;
        if (*s == '\0') result.push_back("");
      }
    }
    if (*s) result.push_back(s);
  }

  return result;
}

vector<int> map_atoi(vector<string> nums)
{
  vector<int> vals(nums.size());
  for (int i=nums.size()-1; i>=0; i--) vals[i] = atoi(nums[i].c_str());
  return vals;
}

string join(vector<string> strs, const string &delim="")
{
  int n=strs.size(); if (n==0) return "";
  stringstream ss;
  ss << strs[0];
  for(int i=1;i<n;i++) { ss << delim << strs[i]; }
  return ss.str();
}

/** 文字列をdelimにする版。使ったことない **/
vector<string> split(string str, string delim)
{
  vector<string> result;

  if (str.length() == 0) return result;

  if (delim.length() == 0) {
    int len = str.length();
    result.resize(len);
    for (int i=0; i<len; i++) result[i] = str.substr(i,1);
    return result;
  }

  int since = 0, at;
  while ((at = str.find(delim, since)) != string::npos) {
    result.push_back(str.substr(since, at-since));
    since = at + delim.length();
  }
  result.push_back(str.substr(since));

  return result;
}
