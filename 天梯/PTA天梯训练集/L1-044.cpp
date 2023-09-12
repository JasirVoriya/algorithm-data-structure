#include <bits/stdc++.h>
using namespace std;
int main(void) {
  int k, cnt = 0;
  cin >> k;
  string str;
  map<string, string> m;
  m["ChuiZi"] = "Bu";
  m["JianDao"] = "ChuiZi";
  m["Bu"] = "JianDao";
  while (cin >> str, str != "End") {
    cnt++;
    if (cnt % (k + 1) == 0) {
      cout << str << endl;
      continue;
    }
    cout << m[str] << endl;
  }
  return 0;
}