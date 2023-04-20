#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e2 + 5;
typedef pair<int, int> PII;
typedef unordered_set<int> USI;
vector<USI> arr;
int main(void) {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int m, x;
    cin >> m;
    arr.push_back(USI());
    for (int j = 0; j < m; j++) {
      cin >> x;
      arr.back().insert(x);
    }
  }
  int k;
  cin >> k;
  while (k--) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    USI &x = arr[a], &y = arr[b];
    USI U = x, A;
    U.insert(y.begin(), y.end());
    for (int num : x) {
      if (y.count(num)) A.insert(num);
    }
    printf("%.2lf%c\n", 100.0 * A.size() / U.size(), '%');
  }
  return 0;
}