#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, string> P;
const int maxn = 1e3 + 5;
int main(void) {
  int n;
  cin >> n;
  while (n--) {
    char x;
    double h;
    cin >> x >> h;
    if (x == 'F') {
      printf("%.2lf\n", h * 1.09);
    } else {
      printf("%.2lf\n", h / 1.09);
    }
  }
  return 0;
}