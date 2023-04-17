#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, string> P;
const int maxn = 1e3 + 5;
int main(void) {
  int a, b;
  cin >> a >> b;
  if (b == 0) {
    printf("%d/0=Error\n", a);
  } else if (b < 0) {
    printf("%d/(%d)=%.2lf\n", a, b, 1.0 * a / b);
  }else{
  	printf("%d/%d=%.2lf\n", a, b, 1.0 * a / b);
  }
  return 0;
}