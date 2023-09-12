#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 5;
int main(void) {
  int n;
  cin >> n;
  vector<pair<string, int>> arr(n);
  double sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> arr[i].first >> arr[i].second;
    sum += arr[i].second;
  }
  double avg = sum / n;
  double dx = 999999;
  int index = 0;
  for (int i = 0; i < n; i++) {
    double x = fabs(arr[i].second - avg/2);
    if (x < dx) {
      index = i;
      dx = x;
    }
  }
  cout << int(avg / 2) << " " << arr[index].first << endl;
  return 0;
}