// 区间覆盖
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> P;
int main(void) {
  int s, t, n;
  cin >> s >> t >> n;
  vector<P> arr(n);
  for (auto &x : arr) cin >> x.first >> x.second;
  sort(arr.begin(), arr.end());
  int res = 0;
  for (int i = 0; i < n; i++) {
    int j = i, r = -2e9;
    while (j < n && arr[j].first <= s) {
      r = max(r, arr[j].second);
      j++;
    }
    if (r < s) {
      cout << -1 << endl;
      return 0;
    }
    res++;
    s = r;
    i = j - 1;
    if (s >= t) {
      cout << res << endl;
      return 0;
    }
  }
  cout << -1 << endl;
  return 0;
}