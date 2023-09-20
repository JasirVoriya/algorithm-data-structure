#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using ll = long long;
const int max_n = 3e5 + 5;
const int inf = 0x3f3f3f3f;
pii arr[max_n];
ll pre[max_n];
int n, k;
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++) {
      scanf("%d", &arr[i].first);
      arr[i].second = i;
    }
    sort(arr, arr + n);
    sort(arr, arr + k, [](pii &a, pii &b) { return a.second < b.second; });
    memset(pre, 0, sizeof(pre));
    for (int i = 0; i < k; i++) pre[i + 1] = arr[i].first + pre[i];
    ll ans = inf;
    for (int i = 1; i <= k; i++) {
      ans = min(ans, max(pre[i], pre[k] - pre[i]));
    }
    cout << ans << endl;
  }
  return 0;
}
// 64 位输出请用 printf("%lld")