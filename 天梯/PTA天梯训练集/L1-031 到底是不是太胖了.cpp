#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, string> P;
int main(void) {
  int n;
  cin >> n;
  while (n--) {
    int h, w;
    cin >> h >> w;
    double x = (h - 100) * 1.8;
    if (w - x >= x * 0.1)
      cout << "You are tai pang le!" << endl;
    else if (w - x <= x * (-0.1))
      cout << "You are tai shou le!" << endl;
    else
      cout << "You are wan mei!" << endl;
    // if (fabs(w - x) < x * 0.1)
    // cout << "You are wan mei!" << endl;
    // else
    // cout << "You are tai shou le!" << endl;
  }
  return 0;
}