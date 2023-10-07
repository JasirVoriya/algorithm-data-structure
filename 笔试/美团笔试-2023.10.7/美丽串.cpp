/*
小美定义一个字符串是“美丽串”，当且仅当该字符电包含“mei"连续子串。
例如"meimei"、"xiaomeichan"都是美丽串，而"meeii“则不是美丽串
现在小美拿到了一个字符串，她准备删除一些字符，但不能删除两个连续字符
小美希望最终字符串变成美丽串，她想知道有多少种删除方案?

输入描述
一个仅包含小写字母的字符串，长度不超过 20.
输出描述
删除的方案数。

例1
输入
meili
输出
3
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int max_n = 1e4 + 5;
string str;
// xyxyxyxyx mxexi xyxyxyxyx
int res = 0;
void check() {
  string s = str;
  size_t i = 0;
  while ((i = s.find_first_of('#')) != string::npos) {
    s.erase(i, 1);
  }
  if (s.find("mei") != string::npos) {
    res++;
  }
}
void dfs(size_t i, bool del) {
  if (i == str.size()) {
    check();
    return;
  }
  if (del) {
    char ch = str[i];
    str[i] = '#';
    dfs(i + 1, false);
    str[i] = ch;
  }
  dfs(i + 1, true);
}

int main() {
  cin >> str;
  dfs(0, true);
  cout << res << endl;
  return 0;
}