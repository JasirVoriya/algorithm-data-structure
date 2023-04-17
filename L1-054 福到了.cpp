#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e2 + 5;
char arr[maxn][maxn];
int main(void) {
  char ch;
  int n;
  scanf("%c %d", &ch, &n);
  getchar();
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      scanf("%c", &arr[i][j]);
    }
    getchar();
  }
  bool flag = true;
  for (int i = 0; i <= n / 2; i++) {
    for (int j = 0; j < n; j++) {
      if (arr[i][j] != arr[n - 1 - i][n - 1 - j]) {
        flag = false;
      }
    }
  }
  if (flag) cout << "bu yong dao le" << endl;
  for (int i = n - 1; i >= 0; i--) {
    for (int j = n - 1; j >= 0; j--) {
      cout << (arr[i][j] == ' ' ? ' ' : ch);
    }
    cout << endl;
  }
  return 0;
}