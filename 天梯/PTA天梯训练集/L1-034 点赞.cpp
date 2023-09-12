#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, string> P;
const int maxn = 1e3 + 5;
int book[maxn] = {0};
int main(void) {
  int n;
  cin >> n;
  while (n--) {
    int k;
    cin >> k;
    while (k--) {
      int x;
      cin >> x;
      book[x]++;
    }
  }
  int x = 0, y = 0;
  for (int i = 0; i < maxn; i++) {
    if (book[i] >= y) x = i, y = book[i];
  }
  cout << x << " " << y << endl;
  return 0;
}