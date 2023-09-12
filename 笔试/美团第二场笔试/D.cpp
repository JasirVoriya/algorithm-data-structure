#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
ll vis[505][105];
ll arr[MAX_N];

ll solve(int s, int n) {
  if (s == n || n == 1) return vis[s][n] = 1;
  ll sum = 1, x;
  for (int i = n; i <= s - 1; i++) {
    x = vis[i][n - 1] ? vis[i][n - 1] : solve(i, n - 1);
    sum = (sum + x) % MOD;
  }
  return vis[s][n] = sum;
}
int main(void) {
  int n, sum = 0;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> arr[i], sum += 0;
  ll ans = solve(sum, n);
  cout << ans - 1 << endl;
  return 0;
}