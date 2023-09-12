//给定n个数，求满足条件的子区间个数，条件为子区间的平均值为u/v
//（题目中说是有理数，且u,v的最大公因数为1
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int max_n = 1e5 + 5;
ll arr[max_n];
unordered_map<ll, int> tab;  //<S，前缀和为S的个数>
int main(void) {
  int n;
  ll u, v;
  scanf("%d%lld%lld", &n, &u, &v);
  for (ll i = 1, x; i <= n; i++) {
    scanf("%lld", &x);
    arr[i] = arr[i - 1] + x * v - u;
    tab[arr[i]]++;
  }
  int ans = tab[0];
  for (auto it = tab.begin(); it != tab.end(); it++) {
    int cnt = it->second;
    if (cnt < 2) continue;
    ans += cnt * (cnt - 1) / 2;
  }
  printf("%d\n", ans);
  return 0;
}