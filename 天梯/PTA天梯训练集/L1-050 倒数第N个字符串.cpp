#include <bits/stdc++.h>
using namespace std;
int main(void) {
  int l, n;
  cin >> l >> n;
  int num = pow(26, l) - n;
  string str = "";
  while (l--) {
    str.insert(0, 1, 'a' + num % 26);
    num /= 26;
  }
  cout << str << endl;
  return 0;
}