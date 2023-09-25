/*
有一个长度无限长的自然数序列 A，下标从0开始。初始时所有数均为 0。
先进行 n 次修，然后进行 m次查询。每次修改给出三个数l，r，x，将
 Al，Al+1 ... Ar，中的每一个数变成它与x的异或值,每次查询给出一个
 数字p表示查询Ap的值。
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll const max_n = 1e4 + 5;
struct node {
  ll l, r;
  int x;
};
node arr[max_n];
int main(void) {
  int n, m;
  cin >> n >> m;
  for (ll i = 0; i < n; i++) {
    cin >> arr[i].l >> arr[i].r >> arr[i].x;
  }
  for (ll p; m; m--) {
    cin >> p;
    int ans = 0;
    for (int i = 0; i < n; i++) {
      if (p >= arr[i].l && p <= arr[i].r) ans ^= arr[i].x;
    }
    cout << ans << endl;
  }
  return 0;
}