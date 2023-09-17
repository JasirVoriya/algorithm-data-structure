#include <bits/stdc++.h>
using namespace std;

int main(void) {
  string str;
  cin >> str;
  int l = 0;
  unordered_set<char> que;
  size_t ans = 1;
  for (auto ch : str) {
    while (que.find(ch) != que.end()) que.erase(str[l++]);
    que.insert(ch);
    ans = max(ans, que.size());
  }
  cout << ans << endl;
  return 0;
}