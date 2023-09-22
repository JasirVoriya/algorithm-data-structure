#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int max_n = 1e5 + 5;
const int inf = 0x3f3f3f3f;
void solve() {
  string s;
  int k;
  cin >> s >> k;
  int ans = 0, dp[26] = {0}, n = s.size();

  for (int i = 0; i < n; i++) {
    int x = s[i] - 'a', res = 1;
    //遍历所有符合条件的字母
    for (int j = max(x - k, 0); j <= min(x + k, 25); j++) {
      // dp[j]表示：前i个字母里，以j结尾的子序列长度
      res = max(dp[j] + 1, res);
    }
    dp[x] = res;
    ans = max(ans, dp[x]);
  }
  cout << ans;
}
int dp[max_n];
unordered_map<int, int> idx;
void solve2() {
  string s;
  int k;
  cin >> s >> k;
  int n = s.size(), ans = 1;
  for (int i = 0; i < n; i++) {
    dp[i] = 1;
    int x = s[i] - 'a';
    for (int j = min(x + k, 25); j >= max(x - k, 0); j--) {
      if (idx.find(j) == idx.end()) continue;
      int id = idx[j];
      dp[i] = max(dp[id] + 1, dp[i]);
    }
    idx[x] = i;
    ans = max(ans, dp[i]);
  }
  cout << ans << endl;
}
int main(void) {
  solve();
  return 0;
}