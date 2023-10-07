#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int max_n = 1e5 + 5;
const int inf = 0x3f3f3f3f;
int main(void) {
  int n;
  cin >> n;
  int ans = 0;
  priority_queue<int, vector<int>, greater<int>> que;
  for (int i = 0, x; i < n; i++) {
    cin >> x;
    ans += x;
    if (x < 0) que.push(x);
  }
  for (int i = 0; que.size() && i < 2; i++) {
    ans -= que.top();
    que.pop();
  }
  cout << ans << endl;
  return 0;
}