#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> PII;
const int maxn = 1e4 + 5;
int mid[maxn], post[maxn], pre[maxn], level[maxn];
struct node {
  int val;
  node *l = nullptr, *r = nullptr;
};
node* create(const int* p, const int* m, int l) {
  if (l <= 0) return nullptr;
  int val = p[0];
  node* r = new node;
  r->val = val;
  int i = 0;
  while (i < l && val != m[i]) i++;
  r->l = create(p + 1, m, i);
  r->r = create(p + i + 1, m + i + 1, l - i - 1);
  return r;
}
void solve(node* r) {
  queue<node*> que;
  que.push(r);
  int i = 0;
  while (que.size()) {
    auto n = que.front();
    que.pop();
    level[i++] = n->val;
    if (n->r) que.push(n->r);
    if (n->l) que.push(n->l);
  }
}
int main(void) {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> mid[i];
  for (int i = 0; i < n; i++) cin >> pre[i];
  solve(create(pre, mid, n));
  cout << level[0];
  for (int i = 1; i < n; i++) cout << " " << level[i];
  return 0;
}