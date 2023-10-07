#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int max_n = 1e4 + 5;
string arr[max_n];
int check(int i, int j) {
  int y = 0, o = 0, u = 0;
  for (int a = 0; a < 2; a++)
    for (int b = 0; b < 2; b++) {
      y += arr[i+a][j+b] == 'y';
      o += arr[i+a][j+b] == 'o';
      u += arr[i+a][j+b] == 'u';
    }
  return y && o && u;
}
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> arr[i];
  int ans = 0;
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < m - 1; j++) {
      ans += check(i, j);
    }
  }
  cout << ans << endl;
  return 0;
}