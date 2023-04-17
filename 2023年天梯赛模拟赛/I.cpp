#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int maxn = 1e2 + 5;
int arr[maxn];
map<string, string> x, y;
int main(void) {
  x["ChuiZi"] = "JianDao";
  x["JianDao"] = "Bu";
  x["Bu"] = "ChuiZi";

  y["JianDao"] = "ChuiZi";
  y["Bu"] = "JianDao";
  y["ChuiZi"] = "Bu";
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> arr[i];
  string str;
  int index = 0;
  int cnt = 0;
  while (cin >> str, str != "End") {
    cnt++;
    if (cnt == arr[index] + 1) {
      cnt = 0;
      index = (index + 1) % n;
      cout << x[str] << endl;
      continue;
    }
    cout << y[str] << endl;
  }
  return 0;
}