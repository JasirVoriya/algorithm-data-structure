#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 5e4 + 5;
int arr[MAX_N] = {0};
int cnt = 0;
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> arr[i];
  for (int i = 0; i < n; i++) {
    int nmin = arr[i], nmax = arr[i], nsum = arr[i];
    for (int j = i + 1; j < n; j++) {
      nmax = max(nmax, arr[j]);
      nmin = min(nmin, arr[j]);
      nsum += arr[j];
      if (nsum == (nmax + nmin) * (nmax - nmin + 1) / 2) {
        cnt++;
      }
    }
  }
  cout << cnt + n << endl;
  return 0;
}