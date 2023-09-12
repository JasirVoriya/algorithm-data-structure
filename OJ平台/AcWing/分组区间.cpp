// 区间分组
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> P;
void solve1() {
  int n;
  cin >> n;
  vector<P> arr(n);
  for (int i = 0; i < n; i++) cin >> arr[i].first >> arr[i].second;
  sort(arr.begin(), arr.end());
  priority_queue<int, vector<int>, greater<int>> heap;
  for (int i = 0; i < n; i++) {
    if (heap.empty() || heap.top() >= arr[i].first) {
      heap.push(arr[i].second);
    } else {
      heap.pop();
      heap.push(arr[i].second);
    }
  }
  cout << heap.size() << endl;
}
void solve2() {
	// 我们可以把所有开始时间和结束时间排序，遇到开始时间就把需要的教室加1，
	// 遇到结束时间就把需要的教室减1,在一系列需要的教室个数变化的过程中，
	// 峰值就是多同时进行的活动数，也是我们至少需要的教室数。
  int n;
  cin >> n;
  vector<int> arr(2 * n);
  int cnt = 0;
  for (int i = 0, x, y; i < n; i++) {
    cin >> x >> y;
    arr[cnt++] = 2 * x;
    arr[cnt++] = 2 * y + 1;
  }
  sort(arr.begin(), arr.end());
  int ans = 0, res = 0;
  for (auto x : arr) {
    if (x % 2 == 0)
      res++, ans = max(res, ans);
    else
      res--;
  }
  cout << ans << endl;
}
int main() {
  solve2();
  return 0;
}