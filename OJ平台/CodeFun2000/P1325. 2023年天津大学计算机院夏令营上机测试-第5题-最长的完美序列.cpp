#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int max_n = 1e5 + 5;
const int inf = 0x3f3f3f3f;
int pow(int x, int y) {
  int ans = 1, base = x;
  while (y) {
    if (y & 1) ans *= base;
    y >>= 1, base *= base;
  }
  return ans;
}
int arr[max_n];
int main(void) {
  // cout << pow(3, 3) << endl;
  // cout << pow(3, 4) << endl;
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
  int n, k;
  cin >> n >> k;
  for (int i = 1; i <= n; i++) cin >> arr[i];
  int l = 1, r = 1, ans = 0;
  multiset<int> pri;
  while (r <= n) {
  pri.insert(arr[r]);
  while (*pri.rbegin() - *pri.begin() > k) pri.erase(pri.find(arr[l++]));
  ans = max(ans, r - l + 1);
  r++;
  }
  cout << ans << endl;
  }
  return 0;
}