#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
typedef pair<int, int> PII;
PII arr[maxn], del[maxn], res[maxn];
bool vis[maxn];
int main() {
  int head, n;
  cin >> head >> n;
  for (int i = 0; i < n; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    arr[a] = PII(b, c);
  }
  int dh = maxn - 1, dt = maxn - 1;
  int rh = maxn - 1, rt = maxn - 1;
  del[dt].second = -1;
  res[rt].second = -1;
  for (int i = head; i != -1; i = arr[i].second) {
    int val = arr[i].first;
    if (!vis[abs(val)]) {
      vis[abs(val)] = true;
      rt = res[rt].second = i; 
      res[i].first = val;
      res[i].second = -1;
    } else {
      dt = del[dt].second = i;
      del[i].first = val;
      del[i].second = -1;
    }
  }
  for (int i = res[rh].second; i != -1; i = res[i].second)
    if (res[i].second == -1)
      printf("%05d %d %d\n", i, res[i].first, res[i].second);
    else
      printf("%05d %d %05d\n", i, res[i].first, res[i].second);
  for (int i = del[dh].second; i != -1; i = del[i].second)
    if (del[i].second == -1)
      printf("%05d %d %d\n", i, del[i].first, del[i].second);
    else
      printf("%05d %d %05d\n", i, del[i].first, del[i].second);
  return 0;
}