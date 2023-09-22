#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int max_n = 1e5 + 5;
const int inf = 0x3f3f3f3f;
string s;
ll ans = 0, n;
int main(void) {
  cin >> s;
  n = s.size();
  int left = 0, i = 0;
  ll ans = 0;
  while (i < n) {
    if (s[i] == '(')
      left++;
    else if (s[i] == ')')
      left--;
    else if (s[i] != 'X') {
      ll val = 0;
      while (i < n && s[i] >= '0' && s[i] <= '9') {
        val = val * 10 + s[i] - '0';
        i++;
      }
      i--;
      ans += val * (left + 1);  //左括号数量代表深度
    }
    i++;
  }
  cout << ans << endl;
  return 0;
}