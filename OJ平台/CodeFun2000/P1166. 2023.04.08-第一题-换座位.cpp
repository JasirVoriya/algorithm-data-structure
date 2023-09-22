#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int max_n = 1e3 + 5;
const int inf = 0x3f3f3f3f;
int arr[max_n][max_n];
int bin(int x) {
  int cnt = 0;
  while (x) cnt += x & 1, x >>= 1;
  return cnt;
}
int get(string& s) {
  int res = 0;
  for (auto c : s) res = (res << 1) + c - '0';
  return res;
}
int main(void) {
  int n, m, a;
  cin >> n >> m >> a;
  string s;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> s;
      arr[i][j] = get(s);
    }
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      ans += bin(arr[i][j] ^ arr[(i + 1) % n][(j + 1) % m]);
    }
  }
  cout << ans << endl;
  return 0;
}