#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
int main() {
  int t;
  cin >> t;
  while (t--) {
    ll n, m;
    cin >> n >> m;
    ll ax, ay, bx, by;
    cin >> ax >> ay >> bx >> by;
    ll x = min(abs(ax - bx), n - abs(ax - bx));
    ll y = min(abs(ay - by), m - abs(ay - by));
    cout << x + y << endl;
  }
  return 0;
}