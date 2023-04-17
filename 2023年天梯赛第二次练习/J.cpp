#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> PII;
const int maxn = 1e4 + 5;
char mid[maxn], pre[maxn], post[maxn];
struct node {
  int val;
  node *l = nullptr, *r = nullptr;
};
void solve(const char *m, const char *p, int l) {
  if (l <= 0)
    return;
  auto val = p[l - 1];
  cout << val;
  int i = 0;
  while (m[i] != val)
    i++;
  // i 现在是左子树的长度
  solve(m, p, i);
  solve(m + i + 1, p + i, l - i - 1);
}
int main(void) {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> mid[i];
  for (int i = 1; i <= n; i++)
    cin >> post[i];

  return 0;
}