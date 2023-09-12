#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> PII;
#define UM unordered_map
const int maxn = 1e5 + 5;
const int inf = 0x3f3f3f3f;
set<int> chan;
int arr[maxn];
int main(void) {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> arr[i];
  for (int i = 0; i < n; i++) {
    auto it = chan.upper_bound(arr[i]);
    if (it != chan.end()) chan.erase(it);
    chan.insert(arr[i]);
  }
  cout << chan.size() << endl;
  return 0;
}
