#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int max_n = 1e5 + 5;
bool vis[max_n];
bool is_prime(int n) {
  if (n <= 1) return false;
  int x = sqrt(n);
  for (int i = 2; i <= x; i++) {
    if (n % i == 0) return false;
  }
  return true;
}
int main() {
  int n;
  cin >> n;
  int cnt = n, i = 0, j = 0;
  while (cnt != 1) {
    if (vis[i] == false) {
      j++;
      if (is_prime(j)) {
        cnt--;
        vis[i] = true;
      }
    }
    i = (i + 1) % n;
  }
  cout << find(vis, vis + n, false) - vis + 1 << endl;
  return 0;
}