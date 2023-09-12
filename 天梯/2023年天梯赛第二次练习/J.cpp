#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> PII;
const int maxn = 1e4 + 5;
int mid[maxn], pre[maxn], post[maxn];
struct node {
  int val;
  node *l = nullptr, *r = nullptr;
};
node *solve(const int *m, const int *p, int l) {
  if (l <= 0) return nullptr;
  auto val = p[l - 1];
  auto root = new node;
  root->val = val;
  int i = 0;
  while (m[i] != val) i++;
  // i 现在是左子树的长度
  root->l = solve(m, p, i);
  root->r = solve(m + i + 1, p + i, l - i - 1);
  return root;
}
int main(void) {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> mid[i];
  for (int i = 1; i <= n; i++) cin >> post[i];
  auto root = solve(mid, post, n);
  
  return 0;
}