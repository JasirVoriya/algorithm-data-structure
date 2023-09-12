#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int max_n = 1e5 + 5;
int arr[max_n];
unordered_set<int> s;
int main(void) {
  ll n;
  cin >> n;
  ll maxn = 0;
  for (ll i = 1, x; i <= n; i++) {
    cin >> x;
    arr[x]++;
    maxn = max(maxn, x);
  }
  ll ans = 0;
  for (int i = 1; i <= maxn; i++) {
    while (arr[i] > 1) {
      int j = i;
      while (arr[j]) j++;
      arr[j]++;
      ans += j - i;
      arr[i]--;
    }
  }
  cout << ans << endl;
  return 0;
}
/*
0 0 1 0 1
1 5 5 8 8
*/