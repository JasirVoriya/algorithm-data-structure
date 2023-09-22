#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int max_n = 1e5 + 10;
const int inf = 0x3f3f3f3f;
int a[max_n], b[max_n];
void solve1() {
  //超时
  int n, m, k;
  cin >> n >> m >> k;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < m; i++) cin >> b[i];
  priority_queue<ll, vector<ll>, greater<ll>> que;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      que.push((ll)a[i] * b[j]);
      if (que.size() > k) que.pop();
    }
  }
  cout << que.top() << endl;
}
void solve2() {
  int n, m, k;
  cin >> n >> m >> k;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < m; i++) cin >> b[i];
  
  
}
int main(void) {
  solve1();
  return 0;
}