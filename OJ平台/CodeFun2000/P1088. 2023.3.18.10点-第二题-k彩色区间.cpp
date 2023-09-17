#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int max_n = 1e5 + 5;
const int inf = 0x3f3f3f3f;
int arr[max_n];
int main(void) {
  int n, k;
  cin >> n >> k;
  for (int i = 1; i <= n; i++) cin >> arr[i];
  int l = 1, r = 1;
  unordered_map<int, int> cnt;
  int ans = 0;
  while (r <= n) {
    cnt[arr[r]]++;
    while (cnt.size() > k) {
      cnt[arr[l]]--;
      if (cnt[arr[l]] == 0) cnt.erase(arr[l]);
      l++;
    }
    ans = max(ans, r - l + 1);
    r++;
  }
  cout << ans << endl;
  return 0;
}