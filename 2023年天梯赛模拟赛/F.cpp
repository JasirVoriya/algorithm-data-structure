#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
int arr[6];
int main(void) {
  for (int i = 0; i < 6; i++) cin >> arr[i];
  int n;
  cin >> n;
  // 1、每个骰子摇出的点数都跟它之前任何一次出现的点数不同；
  // 2、在满足条件 1 的前提下，每次都能让每个骰子得到可能得到的最大点数。
  for (int i = 0; i < 6; i++) {
    int x = 7 - n;
    char sep = ' ';
    if (arr[i] >= x) x--;
    if (i == 5) sep = '\n';
    cout << x << sep;
  }

  return 0;
}