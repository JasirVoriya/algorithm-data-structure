#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e2 + 5;
unordered_set<string> arr[maxn];
int main(void) {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int k;
    string id;
    cin >> k;
    while (k--) {
      cin >> id;
      arr[i].insert(id);
    }
  }
  int m;
  vector<string> ans;
  unordered_set<string> vis;
  cin >> m;
  while (m--) {
    string id;
    cin >> id;
    if (vis.count(id)) continue;
    vis.insert(id);
    bool flag = true;
    for (int i = 0; i < n; i++) {
      if (arr[i].count(id) && arr[i].size() > 1) {
        flag = false;
        break;
      }
    }
    if (flag) ans.push_back(id);
  }
  if (ans.size() == 0) {
    cout << "No one is handsome" << endl;
    return 0;
  }
  cout << ans[0];
  for (int i = 1; i < ans.size(); i++) cout << " " << ans[i];
  return 0;
}