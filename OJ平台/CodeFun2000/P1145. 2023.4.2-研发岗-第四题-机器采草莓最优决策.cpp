#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int max_n = 1e3 + 5;
const int inf = 0x3f3f3f3f;
ll arr[max_n][max_n];
ll dp[max_n][max_n];
int main(void) {
  int n, m, g;
  cin >> n >> m >> g;
  int ans = inf;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> arr[i][j];
      dp[i][j] = arr[i][j] + max(dp[i - 1][j], dp[i][j - 1]);
      if (dp[i][j] >= g) ans = min(ans, i + j - 2);
    }
  }
  cout << (ans == inf ? -1 : ans) << endl;
  return 0;
}