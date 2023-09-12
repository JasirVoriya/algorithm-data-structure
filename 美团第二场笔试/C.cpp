#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAX_N = 1e5 + 5;
string str;
int n;
int cnt(int begin, int size) {
  bool vis[MAX_N] = {false};
  int ans = 0;
  for (int i = 0; i < size; i++) vis[i] = str[begin + i] - '0';
  for (int i = 1; i < size; i++) {
    if (vis[i - 1] == vis[i]) vis[i] = !vis[i], cnt++;
  }
  
}
int solve(int size) {
  int ans = 0;
  for (int i = 0; i + size <= str.szie(); i++) {
    ans += cnt(i, size);
  }
  return ans;
}
int main(void) {
  cin >> str;
  str = str;
  int ans = 0;
  for (int i = 2; i <= str.size(); i++) {
    ans += solve(i);
  }
  return 0;
}