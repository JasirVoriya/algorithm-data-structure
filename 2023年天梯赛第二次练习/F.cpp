#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
string str;
int ans = 0;
int cnt(int i, int j) {
  int res = 0;
  while (i < j && str[i] == str[j]) {
    res += 2;
    i++, j--;
  }
  return i < j ? 0 : res + (i == j);
}
int main(void) {
  getline(cin, str);
  for (int i = 0; i < str.size(); i++) {
    for (int j = str.size() - 1; j >= i; j--) {
      ans = max(cnt(i, j), ans);
    }
  }
  cout << ans << endl;
  return 0;
}