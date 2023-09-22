#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int max_n = 2e3 + 5;
const int inf = 0x3f3f3f3f;
int arr[max_n][max_n];
int main(void) {
  string d;
  int n, m, i, j;
  cin >> n >> m >> i >> j >> d;
  int dx = d[0] == 'D' ? 1 : -1, dy = d[1] == 'R' ? 1 : -1;
  int x = i, y = j, ans = 0;
  do {
    x += dx, y += dy;
    ans++;
    if (x == n || x == 1) dx *= -1;//撞墙反转
    if (y == m || y == 1) dy *= -1;//撞墙反转
  } while (x != i || y != j);
  cout << ans << endl;
  return 0;
}