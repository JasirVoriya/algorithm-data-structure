#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int max_n = 2e5 + 10;
const int inf = 0x3f3f3f3f;
int a[max_n], b[max_n], idx[max_n];
int main(void) {
  ll n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    idx[a[i]] = i;
  }
  for (int i = 0; i < n; i++) cin >> b[i];
  ll i=0,ans = n * n + n;
  while (i < n) {
    ll j = idx[b[i]], x = 0;
    while (i + x < n && j + x < n && b[i + x] == a[j + x]) x++;
    ans -= (x + 1) * x / 2;
    i += x;
  }
  cout << ans << endl;
  return 0;
}