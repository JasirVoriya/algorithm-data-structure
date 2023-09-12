// 区间选点
// 最大不相交区间数量
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> P;
void solve1() {
  // 右端点排序
  int n;
  cin >> n;
  vector<P> arr(n);
  for (int i = 0; i < n; i++) cin >> arr[i].second >> arr[i].first;
  sort(arr.begin(), arr.end());
  int ans = 1;
  P res = arr[0];
  for (int i = 1; i < n; i++) {
    if (res.first < arr[i].second) {
      res = arr[i];
      ans++;
    }
  }
  cout << ans << endl;
}
void solve2() {
  // 左端点排序
  int n;
  cin >> n;
  vector<P> arr(n);
  for (int i = 0; i < n; i++) cin >> arr[i].first >> arr[i].second;
  sort(arr.begin(), arr.end());
  int ans = 1;
  P res = arr[0];
  for (int i = 1; i < n; i++) {
    if (res.second < arr[i].first) {
      res = arr[i];
      ans++;
    } else if (res.second >= arr[i].second) { //区间重合，保留最小的那个右边界
      res = arr[i];
    }
  }
  cout << ans << endl;
}
int main() {
  solve1();
  return 0;
}