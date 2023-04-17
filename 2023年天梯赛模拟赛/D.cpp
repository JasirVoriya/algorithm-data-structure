#include <bits/stdc++.h>
using namespace std;
int main(void) {
  int x, y;
  cin >> x >> y;
  int q = max(x, y);
  int z = x + y;
  printf("%d %d\n", q > 0 ? q : 0, z > 0 ? z : 0);
  if (z > 0)
    cout << "^_^" << endl;
  else if (x < 0 && y < 0)
    cout << "-_-" << endl;
  else if (z <= 0)
    cout << "T_T" << endl;
  return 0;
}