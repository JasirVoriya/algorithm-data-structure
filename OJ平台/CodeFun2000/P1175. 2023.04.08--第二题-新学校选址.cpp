#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int max_n = 1e5 + 5;
const int inf = 0x3f3f3f3f;
int arr[max_n];
int main(void) {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> arr[i];
  sort(arr, arr + n);
  cout << arr[(n - 1) / 2] << endl;
  return 0;
}