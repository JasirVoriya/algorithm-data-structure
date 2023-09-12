#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  string str = "helloworld";
  int index = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      index %= str.size();
      cout << str[index++];
    }
    cout << endl;
  }
  return 0;
}