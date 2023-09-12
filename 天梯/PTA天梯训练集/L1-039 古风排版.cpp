#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, string> P;
const int maxn = 1e3 + 5;
int main(void) {
  //  8 4 0
  //  9 5 1
  // 10 6 2
  // 11 7 3
  int n;
  string str;
  cin >> n;
  getchar();
  getline(cin, str);
  int index = str.size() / n;
  index += (1.0 * str.size() / n - index > 0) - 1;
  index *= n;
  int y = str.size() / n;
  y += 1.0 * str.size() / n - y > 0;
  // cout << y << endl;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < y; j++) {
      ull x = index - (n * j) + i;
      // cout << x << " ";
      if (x >= str.size())
        cout << " ";
      else
        cout << str[x];
    }
    cout << endl;
  }
  return 0;
}