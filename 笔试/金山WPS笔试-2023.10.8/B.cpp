#include <bits/stdc++.h>
using namespace std;
const int max_n = 1e5 + 5;
int arr[max_n], dict[max_n];
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
    dict[arr[i]] = i;
  }
  bool one = true;
  for (int i = n; i >= 1; i--) {
    int index = dict[i];
    if (arr[index] < 0) continue;
    int flag = one ? -1 : -2;
    one = !one;
    arr[index] = flag;
    for (int i = 1, c = 0; index - i >= 1 && c < m; i++) {
      if (arr[index - i] < 0) continue;
      c++;
      arr[index - i] = flag;
    }
    for (int i = 1, c = 0; index + i <= n && c < m; i++) {
      if (arr[index + i] < 0) continue;
      c++;
      arr[index + i] = flag;
    }
  }
  for (int i = 1; i <= n; i++) {
    cout << (arr[i] == -1 ? "A" : "B");
  }
}