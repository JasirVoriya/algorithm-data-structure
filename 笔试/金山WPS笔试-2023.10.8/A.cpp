#include <bits/stdc++.h>
using namespace std;
int main() {
  string str;
  cin >> str;
  int a = 0;
  for (auto ch : str) {
    if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') a++;
  }
  int b = str.size() - a;
  if (b <= str.size() / 2)
    cout << str.size() << endl;
  else
    cout << 2 * a + 1 << endl;
}