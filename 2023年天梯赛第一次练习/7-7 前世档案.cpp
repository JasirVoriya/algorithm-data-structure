#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> PII;
#define UM unordered_map
const int maxn = 5e2 + 5;
int main(void) {
  ll n, m;
  cin >> n >> m;
  while (m--) {
    string str;
    cin >> str;
    ll l = 1, r = 1 << n, mid = (l + r) >> 1;
    for (char c : str) {
      if (c == 'y')
        r = mid;
      else
        l = mid + 1;
      mid = (l + r) >> 1;
    }
    cout << mid << endl;
  }
  return 0;
}