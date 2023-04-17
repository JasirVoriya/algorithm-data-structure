#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> PII;
const int maxn = 1e4 + 5;
int pre[maxn];
vector<int> arr;
bool check(int val, const int *arr, int l, bool s) {
  for (int i = 0; i < l; i++) {
    if ((arr[i] < val) != s) return false;
  }
  return true;
}
struct node { 
  int val;
  node *l = nullptr, *r = nullptr;
};
bool scs = true;
node *solve(const int *p, int l, bool s) {
  if (l <= 0) return nullptr;
  int val = p[0];
  auto root = new node;
  root->val = val;
  int i = 1;
  while (i < l && (p[i] < val) == s) i++;
  // p[i] >= val
  //!(左子树全部<val && 右子树全部>=val)
  bool cl = check(val, p + 1, i - 1, s), cr = check(val, p + i, l - i, !s);
  if (!(cl && cr)) {
    scs = false;
    return nullptr;
  }
  //构造搜索树
  root->l = solve(p + 1, i - 1, s);
  root->r = solve(p + i, l - i, s);
  return root;
}
void post(node *root) {
  if (root == nullptr) return;
  post(root->l);
  post(root->r);
  arr.push_back(root->val);
}
int main(void) {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> pre[i];
  auto root = solve(pre, n, pre[1] < pre[0]);
  if (scs) {
    cout << "YES" << endl;
    post(root);
    cout << arr[0];
    for (int i = 1; i < n; i++) {
      cout << " " << arr[i];
    }
  } else {
    cout << "NO" << endl;
  }
  return 0;
}