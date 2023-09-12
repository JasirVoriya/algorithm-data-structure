#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAX_N = 1e5 + 5;
ll arr[MAX_N];
int main(void) {
  int n;
  cin >> n;
  ll sum = 0;
  for (int i = 1; i <= n; i++) cin >> arr[i], sum += arr[i];
  int idx = 0;
  for (int i = 1; i < n; i++) {
    if (arr[i] + arr[i + 1] < arr[i] * arr[i + 1]) {
      if (arr[idx] * arr[idx + 1] < arr[i] * arr[i + 1]) {
        idx = i;
      }
    }
  }
  if (idx) sum = sum - arr[idx] - arr[idx + 1] + arr[idx] * arr[idx + 1];
  cout << sum << endl;
  return 0;
}