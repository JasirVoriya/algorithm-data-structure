#include <bits/stdc++.h>
using namespace std;
void solve(const char *m, const char *p, int l) {
	if(l<=0)return;
  auto val = p[l - 1];
  cout << val;
  int i = 0;
  while (val != m[i]) i++;
  //i 为左子树的长度
  solve(m, p, i);
  solve(m + i + 1, p + i, l - i - 1);
}
int main(void) {
  string mid, post;
  cin >> mid >> post;
  solve(mid.c_str(), post.c_str(), mid.size());
}