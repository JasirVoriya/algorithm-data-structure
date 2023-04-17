#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 5;
int main(void) {
  string str, s;
  getline(cin, str);
  for (int i = 0; i < str.size(); i++) {
    if (str[i] == '6') {
      s.push_back('6');
      if (str[i + 1] != '6') {
        if (s.size() <= 3)
          cout << s;
        else if (s.size() <= 9)
          cout << 9;
        else
          cout << 27;
        s.erase();
      }
      continue;
    }
    cout << str[i];
  }
  return 0;
}