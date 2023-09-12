#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
bool isPrime(ll n) {
  if (n < 2) return false;
  for (ll i = 2; i * i <= n; i++) {
    if (n % i == 0) return false;
  }
  return true;
}
int main(void) {
  int n;
  cin >> n;
  while (n--) {
    ll num;
    cin >> num;
    cout << (isPrime(num) ? "Yes" : "No") << endl;
  }
  return 0;
}