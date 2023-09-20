#include <bits/stdc++.h>
using namespace std;
int main() {
  string s, p;
  cin >> s >> p;
  vector<string> px;
  for (size_t i = 0; i < p.size(); i++) {
    if (p[i] == '.') {
      px.emplace_back(".");
      continue;
    }
    if (p[i] != '*') {
      if (i + 1 < p.size() && p[i + 1] == '*')
        px.push_back(p.substr(i, 2));
      else
        px.push_back(p.substr(i, 1));
    }
  }
  size_t l = 0;
  size_t i = 0;
  while (i < px.size() && l < s.size()) {
    if (l == s.size()) break;
    if (px[i] == ".")
      l++;
    else if (px[i].size() == 2)
      while (s[l] == px[i][0]) l++;
    else if (s[l] == px[i][0])
      l++;
    else {
      cout << 0 << endl;
      return 0;
    }
    i++;
  }
  cout << (l == s.size()) << endl;
  return 0;
  // 64 位输出请用 printf("%lld")
}