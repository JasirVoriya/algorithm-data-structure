// 萝卜的冒泡排序
#include <bits/stdc++.h>
using namespace std;
const int max_n = 1e2 + 5;
int arr[max_n];
int main() {
  int n;
  cin >> n;
  int ans = 0;
  for (int i = 0; i < n; i++) cin >> arr[i];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j + 1 < n - i; j++) {
      if (arr[j] > arr[j + 1]) {
        int t = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = t;
        ans++;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    int x = 1;
    while (arr[i] == arr[i + x]) x++;
    x--;
    ans += (x + 1) * x / 2;
    i += x;
  }
  cout << ans << endl;
  return 0;
}