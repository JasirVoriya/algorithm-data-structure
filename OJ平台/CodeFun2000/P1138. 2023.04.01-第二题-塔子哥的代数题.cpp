#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int max_n = 1e5 + 5;
const int inf = 0x3f3f3f3f;
int arr[max_n];
double calc(int x, int y, char o) {
  if (o == '+') return 1.0 * x + y;
  if (o == '-') return 1.0 * x - y;
  if (o == '*') return 1.0 * x * y;
  return 1.0 * x / y;
}
int main(void) {
  int n, sum = 0;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> arr[i], sum += arr[i];
  int m;
  cin >> m;
  for (int i = 0; i < m; i++) {
    int t;
    char o;
    cin >> t >> o;
    double val = calc(arr[t - 1], arr[t], o);
    printf("%.1lf ", val + sum - arr[t] - arr[t - 1]);
  }
  return 0;
}