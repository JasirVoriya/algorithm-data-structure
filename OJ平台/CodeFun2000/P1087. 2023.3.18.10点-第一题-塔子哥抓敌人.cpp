#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int max_n = 1e3 + 5;
int vis[max_n][max_n];
int pre[max_n][max_n];
int mx, my, a, b;
int check(int i, int j) {
  int x = max(0, i - a - 1), y = max(0, j - b - 1);
  return pre[i][j] - pre[x][j] - pre[i][y] + pre[x][y];
}
int main(void) {
  int n;
  cin >> n >> a >> b;
  while (n--) {
    int x, y;
    cin >> x >> y;
    mx = max(mx, x);
    my = max(my, y);
    vis[x][y]++;
  }
  int ans = 0;
  for (int i = 1; i <= mx; i++) {
    for (int j = 1; j <= my; j++) {
      pre[i][j] = pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1] + vis[i][j];
      ans = max(ans, check(i, j));
    }
  }
  cout << ans << endl;
  return 0;
}