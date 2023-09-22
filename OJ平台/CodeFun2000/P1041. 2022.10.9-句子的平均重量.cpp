#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int max_n = 1e3 + 5;
const int inf = 0x3f3f3f3f;
int arr[max_n][max_n];
vector<string> split(string str, char ch) {
  vector<string> ans;
  size_t index = 0, start = 0;
  while ((index = str.find_first_of(ch, start)) != string::npos) {
    if (index != start) ans.push_back(str.substr(start, index - start));
    start = index + 1;
  }
  if (start < str.size()) ans.push_back(str.substr(start, str.size() - start));
  return ans;
}
int main(void) {
  string str;
  getline(cin, str);
  auto ls = split(str, ' ');
  double ans = 0;
  for (auto s : ls) ans += s.size();
  ans /= ls.size();
  printf("%.2lf\n", ans);

  return 0;
}