#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int max_n = 2e5 + 5;
const int inf = 0x3f3f3f3f;
int arr[max_n], idx[max_n];
int main(void) {
  int n, x;
  cin >> n >> x;
  for (int i = 1; i <= n; i++) {
    scanf("%d", arr + i);
  }
  int l = 1, r = 1;
  unordered_map<int, int> cnt;
  int ans = 0;
  while (r <= n) {
    cnt[arr[r]]++;//每次都是push的arr[r]，所以
    //此时arr[r]出现的次数，在arr[l,r]区间内，肯定是次数最多的
    //且最大次数也只是x
    while (cnt[arr[r]] == x) {
      ans += n - r + 1;
      cnt[arr[l++]]--;//左区间弹出
    }
    r++;
  }
  cout << ans << endl;
  return 0;
}