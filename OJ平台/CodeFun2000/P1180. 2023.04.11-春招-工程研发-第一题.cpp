#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int max_n = 1e+5;
int main() {
  int n;
  cin >> n;
  unordered_map<ll, int> cnt;
  for (ll i = 0, x; i < n; i++) {
    cin >> x;
    cnt[x]++;
  }
  int ans = 0;
  for (auto &it : cnt) {
    if (it.first % 2 && it.second % 2) ans+=it.second;
  }
  cout << ans << endl;
  return 0;
}