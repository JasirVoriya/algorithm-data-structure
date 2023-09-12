#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MAX_N = 1e4 + 5;
const ll INF = 0x3f3f3f3f;
bool vis[MAX_N];
string str;
int off[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int ans = INF, cnt = 0, x, y;
int index(int i, int j) { return i * y + j; }
void dfs(int i, int j) {
  int idx = index(i, j);
  vis[idx] = true;
  for (int k = 0; k < 4; k++) {
    int dx = i + off[k][0], dy = j + off[k][1];
    if (dx >= 0 && dx < x && dy >= 0 && dy < y && vis[index(dx, dy)] == false &&
        str[index(dx, dy)] == str[idx]) {
      dfs(dx, dy);
    }
  }
}
void solve() {
  memset(vis, false, sizeof(vis));
  cnt = 0;
  for (int i = 0; i < x; i++) {
    for (int j = 0; j < y; j++) {
      if (vis[index(i, j)] == false) {
        dfs(i, j);
        cnt++;
      }
    }
  }
  ans = min(cnt, ans);
}
int main() {
  int n;
  cin >> n >> cin >> str;
  for (int i = 1; i <= n; i++) {
    if (n % i == 0) {
      x = i, y = n / i;
      solve();
    }
  }
  cout << ans << endl;
  return 0;
}