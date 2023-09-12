#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
int main(void) {
  ll n, m, q;
  cin >> n >> m >> q;
  set<ll> x, y;
  for (ll i = 0; i < q; i++) {
    ll t, c;
    cin >> t >> c;
    t == 0 ? x.insert(c) : y.insert(c);
  }
  ll sum = x.size() * m + y.size() * n - (x.size() * y.size());
  cout << n * m - sum << endl;
  return 0;
}