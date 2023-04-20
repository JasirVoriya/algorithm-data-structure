#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> PII;
typedef unordered_set<int> USI;
#define US unordered_set
#define UM unordered_map
const int maxn = 1e4 + 5;
const int inf = 0x3f3f3f3f;
string str;
int check(int l, int r) {
  int ans = 0;
  while (l < r && str[l] == str[r]) {
    l++, r--;
    ans += 2;
  }
  return l < r ? 0 : ans + (l == r);
}
int main(void) {
  getline(cin, str);
  int ans = 0;
  for (int i = 0; i < str.size(); i++) {
    for (int j = str.size() - 1; j >= i; j--) {
      if (str[i] == str[j]) ans = max(ans, check(i, j));
    }
  }
  cout << ans << endl;
  return 0;
}