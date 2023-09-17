#include <bits/stdc++.h>
using namespace std;
const int max_n = 2e5 + 5;
const int inf = 0x3f3f3f3f;
int arr[max_n], idx[max_n];
int main(void) {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (int i = 0, x; i < n; i++) {
      cin >> x;
      idx[x] = i;
    }
    int l = inf, r = 0, ans = 0;
    for (int i = 1; i <= n; i++) {
      l = min(l, idx[i]);//最小下标
      r = max(r, idx[i]);//最大下标
      if (r - l + 1 == i) ans++;
    }
    cout << ans << endl;
  }
  return 0;
}