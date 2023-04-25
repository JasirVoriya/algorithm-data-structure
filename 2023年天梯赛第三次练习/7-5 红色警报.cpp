#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> PII;
#define UM unordered_map
const int maxn = 5e2 + 5;
bool arr[maxn][maxn], vis[maxn];
int n, m;
void dfs(int x) {
  vis[x] = true;
  for (int i = 0; i < n; i++)
    if (!vis[i] && arr[x][i]) dfs(i);
}
int solve() {
  memset(vis, false, sizeof(vis));
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (!vis[i]) {
      dfs(i);
      ans++;
    }
  }
  return ans;
}
int main(void) {
  cin >> n >> m;
  for (int i = 0, x, y; i < m; i++) {
    cin >> x >> y;
    arr[x][y] = arr[y][x] = true;
  }
  int x = solve();
  int k, c;
  cin >> k;
  for (int i = 0; i < k; i++) {
    cin >> c;
    for (int j = 0; j < n; j++) arr[c][j] = arr[j][c] = false;
    int y = solve();
    if (y <= x + 1)
      printf("City %d is lost.\n", c);
    else
      printf("Red Alert: City %d is lost!\n", c);
    x = y;
  }
  if (k == n) cout << "Game Over." << endl;
  return 0;
}