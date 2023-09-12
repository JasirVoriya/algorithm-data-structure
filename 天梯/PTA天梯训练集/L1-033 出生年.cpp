#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, string> P;
bool check(int y, int n) {
  int arr[4] = {0};
  int book[10] = {0};
  for (auto &x : arr) {
    x = y % 10;
    y /= 10;
    book[x]++;
  }
  int sum = 0;
  for (auto x : book) sum += x != 0;
  return sum == n;
}
int main(void) {
  int y, n;
  cin >> y >> n;
  for (int i = 0; true; i++) {
    if (check(y + i, n)) {
      printf("%d %04d\n", i, y + i);
      return 0;
    }
  }
  return 0;
}