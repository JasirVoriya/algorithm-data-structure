#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int max_n = 1e5 + 5;
const int inf = 0x3f3f3f3f;
int arr[max_n];
pii v[max_n];
int main(void) {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> arr[i];
  sort(arr, arr + n, [](int a, int b) { return a > b; });
  for (int i = 0; i < m; i++) cin >> v[i].second >> v[i].first;
  sort(v, v + m, [](pii& a, pii& b) {
    if (a.first != b.first) return a.first > b.first;
    return a.second < b.second;
  });
  ll ans = 0;
  int i = 0, j = 0;
  while (i < n) {
    while (v[j].second > arr[i]) j++;
    ans += arr[i] - v[j].first;
    i++;
  }
  cout << ans << endl;
  return 0;
}