#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(void) {
  int q;
  cin >> q;
  while (q--) {
    ll m, x;
    cin >> m >> x;
    cout << (x - 1) % m + 1 << endl;
  }
  return 0;
}