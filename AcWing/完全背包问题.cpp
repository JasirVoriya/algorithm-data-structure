#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 1e3 + 5;
int ans[MAX_N];
int weight[MAX_N], value[MAX_N];
int dp[MAX_N][MAX_N];
int N, W, v, w;
void solve1() {
  cin >> N >> W;
  for (int i = 0; i < N; i++) {
    cin >> w >> v;
    // 从小到大遍历，可以继续沿用放完若干个第i个物品（当前物品）时的状态
    for (int j = w; j <= W; j++) {
      ans[j] = max(ans[j], ans[j - w] + v);
    }
  }
  cout << ans[W] << endl;
}
int solve2(int i, int w) {
  if (i == N || w == 0) return 0;
  if (dp[i][w] != -1) return dp[i][w];
  if (w >= weight[i]) {
    return dp[i][w] =
               max(solve2(i, w - weight[i]) + value[i], solve2(i + 1, w));
  }
  return dp[i][w] = solve2(i + 1, w);
}
void solve2() {
  cin >> N >> W;
  memset(dp, -1, sizeof(dp));
  for (int i = 0; i < N; i++) {
    cin >> weight[i] >> value[i];
  }
  cout << solve2(0, W) << endl;
}
int main(void) {
  solve2();
  return 0;
}