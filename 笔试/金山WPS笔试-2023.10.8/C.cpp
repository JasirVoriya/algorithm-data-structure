#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;
ll mypow(ll x, ll y) {
  ll ans = 1, base = x;
  while (y) {
    if (y & 1) ans = (ans * base) % mod;
    y >>= 1;
    base = (base * base) % mod;
  }
  return ans;
}
int main() {
  int h, x;
  cin >> h >> x;
  ll ans = 0;
  for (ll i = 1, a; i <= h; i++) {
    cin >> a;
    ll res = mypow(x, i);
    ans = (ans + (a * res) % mod) % mod;
  }
  cout << ans << endl;
}