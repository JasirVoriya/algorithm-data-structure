#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
const int max_n = 1e6 + 5;
pii arr[max_n];
int nums[max_n];
bool vis[max_n];
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    memset(vis, false, sizeof(vis));
    for (int i = 1; i <= n; i++) {
      cin >> arr[i].first >> arr[i].second;
      vis[arr[i].second] = true;
    }
    int head = 1;
    while (head < n && vis[head]) head++;
    stack<int> s;
    int i = 0;
    while (head != 0) {
      nums[i++] = arr[head].first;
      head = arr[head].second;
    }
    while (--n >= 0) cout << nums[n] << " ";
    cout << endl;
  }
}
// 64 位输出请用 printf("%lld")