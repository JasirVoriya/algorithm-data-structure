#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
int main(void) {
  int n;
  string str;
  cin >> n;
  getchar();
  getline(cin, str);
  //  8 4 0
  //  9 5 1
  // 10 6 2
  //    7 3
  int m = str.size() / n + (str.size() % n != 0);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      size_t index = n * (m - 1 - j) + i;
      cout << (index >= str.size() ? ' ' : str[index]);
    }
    cout << endl;
  }
  return 0;
}