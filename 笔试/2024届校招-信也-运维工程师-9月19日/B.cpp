#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
const int max_n = 1e5 + 5;
int arr[max_n];
vector<string> split(string& str, char ch) {
  vector<string> ans;
  size_t index = 0, start = 0;
  while ((index = str.find_first_of(ch, start)) != string::npos) {
    if (index != start) ans.push_back(str.substr(start, index - start));
    start = index + 1;
  }
  if (index == string::npos)
    ans.push_back(str.substr(start, str.size() - start));
  return ans;
}
int get_array(string& str) {
  str.pop_back();
  str = str.substr(1, str.size() - 1);
  auto sl = split(str, ',');
  for (size_t i = 0; i < sl.size(); i++) arr[i] = stoi(sl[i]);
  return sl.size();
}
int main() {
  string str;
  cin >> str;
  int k, n = get_array(str);
  cin >> k;
  unordered_map<int, int> idx;
  for (int i = 0; i < n; i++) idx[arr[i]] = i;
  set<pii> ans;
  for (int i = 0; i < n; i++) {
    int t = k - arr[i];
    if (idx.find(t) != idx.end() && idx[t] != i) {
      printf("[%d, %d]", min(idx[t], i), max(idx[t], i));
      return 0;
    }
  }
  return 0;
}
// 64 位输出请用 printf("%lld")