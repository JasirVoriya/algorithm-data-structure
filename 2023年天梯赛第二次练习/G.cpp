#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;
const int maxn = 1e4 + 5;
struct node {
  int id, val, cnt;
  bool operator<(const node& x) {
    if (this->val != x.val) return this->val > x.val;
    return this->cnt > x.cnt;
  }
};
node arr[maxn];
int main(void) {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    arr[i].id = i;
    int k;
    cin >> k;
    for (int j = 0; j < k; j++) {
      int id, val;
      cin >> id >> val;
      arr[id].val += val;
      arr[id].cnt++;
      arr[i].val -= val;
    }
  }
  sort(arr + 1, arr + 1 + n);
  for (int i = 1; i <= n; i++) {
    printf("%d %.2lf\n", arr[i].id, arr[i].val / 100.0);
  }
  return 0;
}