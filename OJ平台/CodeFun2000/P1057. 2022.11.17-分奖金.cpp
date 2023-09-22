#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int max_n = 2e5 + 10;
const int inf = 0x3f3f3f3f;
int arr[max_n], ans[max_n];
void solve1() {
  //暴力 O(N²)
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> arr[i];
  for (int i = 0; i < n; i++) {
    int j = i + 1;
    while (j < n && arr[j] <= arr[i]) j++;
    if (j == n)
      cout << arr[i] << " ";
    else
      cout << (j - i) * (arr[j] - arr[i]) << " ";
  }
  cout << endl;
}
void solve2() {
  //单调栈 O(N)
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> arr[i];
  stack<int> s;
  memset(ans, -1, sizeof(ans));
  for (int i = 0; i < n; i++) {
    //维护单调栈，入栈元素如果比栈顶大，则弹出
    while (s.size() && arr[s.top()] < arr[i]) {
      //此时栈内元素肯定是在arr[i]前面，
      //然后arr[i]肯定就是栈顶元素遇到的第一个比它大的。
      ans[s.top()] = (i - s.top()) * (arr[i] - arr[s.top()]);
      s.pop();
    }
    s.push(i);
  }
  while (s.size()) ans[s.top()] = arr[s.top()], s.pop();
  for (int i = 0; i < n; i++) cout << ans[i] << " ";
  cout << endl;
}
int main(void) {
  solve2();
  return 0;
}