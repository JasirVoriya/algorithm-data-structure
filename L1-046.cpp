#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int inf = 0x3f3f3f3f, maxN = 50005;

int main() {
  ll n, big = 1, cnt = 1;
  cin >> n;
  while (big < n) {
    big = big * 10 + 1;
    ++cnt;
  }
  while (big % n) {
    cout << big / n;
    // 模拟除法过程
    big %= n;
    big = big * 10 + 1;
    ++cnt;
  }
  cout << big / n;
  cout << " " << cnt << endl;
  return 0;
}