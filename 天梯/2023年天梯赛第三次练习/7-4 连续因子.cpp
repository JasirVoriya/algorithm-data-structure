#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> PII;
const int maxn = 1e4 + 5;
int check(int x, int y) {
  int i = y;
  while (x % i == 0) x /= i, i++;
  return i - y;
}
int main(void) {
  int n;
  while (cin >> n) {
    int x = sqrt(n);
    PII s(1, n);
    for (int i = 2; i <= x; i++) {
      if (n % i == 0) {
        int l = check(n, i);
        if (l == 1 && s.second == n) s = PII(l, i);
        if (l > s.first) s = PII(l, i);
      }
    }
    cout << s.first << endl;
    cout << s.second;
    for (int i = 1; i < s.first; i++) {
      cout << "*" << s.second + i;
    }
    cout << endl;
  }
  return 0;
}