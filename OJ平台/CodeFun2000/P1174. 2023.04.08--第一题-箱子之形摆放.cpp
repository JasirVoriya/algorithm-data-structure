#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int max_n = 1e5 + 5;
const int inf = 0x3f3f3f3f;
int main(void) {
  string str;
  int n;
  cin >> str >> n;
  for (int i = 0, j = 2 * n - 1; i < n; i++, j--) {
    int k = 0;
    while (true) {
      int x = i + n * k, y = j + n * (k - 1);
      if (k % 2 == 0 && x >= str.size() || k % 2 == 1 && y >= str.size()) break;
      if (k % 2 == 0)
        cout << str[x];
      else
        cout << str[y];
      k++;
    }
    cout << endl;
  }
  /*
  5:
  0 9 10 19 20
  1 8 11 18 21
  2 7 12 17 22
  3 6 13 16 23
  4 5 14 15 24
  */

  return 0;
}