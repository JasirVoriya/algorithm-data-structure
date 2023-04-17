#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
int main(void) {
  ll a, b;
  cin >> a >> b;
  ll n = a + b;
  ll sum = 1;
  for (int i = 2; i <= n; i++) sum *= i;
  cout << sum << endl;
  return 0;
}