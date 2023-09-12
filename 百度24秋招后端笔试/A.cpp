#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int max_n = 1e3 + 5;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    if ((n + m) % 2 == 0)
      cout << "No" << endl;
    else
      cout << "Yes" << endl;
  }
  return 0;
}