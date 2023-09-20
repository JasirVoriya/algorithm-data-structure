#include <bits/stdc++.h>
using namespace std;
int main() {
  string st;
  cin >> st;
  unordered_set<char> chs(st.begin(), st.end());
  int n = st.size();
  for (char ch : chs) {
    for (int i = 0; i < n; i++) {
      int j = i;
      while (j < n && st[j] == ch) j++;
      if (j - i >= 3) {
        int k = j - i;
        while (j < n) st[j - k] = st[j], j++;
        i--, n -= k;
      }
    }
  }
  cout << st.substr(0, n) << endl;
  return 0;
  // 64 位输出请用 printf("%lld")
}