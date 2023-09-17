#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int max_n = 2e5 + 5;
const int inf = 0x3f3f3f3f;
int arr[max_n], idx[max_n];
int main(void) {
 	int n, k;
  cin >> n >> k;
  for (int i = 1, x; i <= n; i++) {
    scanf("%d", &x);
    arr[i] = arr[i - 1] + x;
  }
  int ans = inf;
  int l = 1, r = 1;
  while (r <= n) {
    while (arr[r] - arr[l - 1] >= k) {
      ans = min(ans, r - l + 1);
      l++;
    }
    r++;
  }
  cout << ans << endl;
  return 0;
}