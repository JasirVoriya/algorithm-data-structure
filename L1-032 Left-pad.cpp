#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, string> P;
int main(void) {
  int n;
  char ch;
  string str;
  cin >> n >> ch;
  getchar();
  getline(cin, str);
  // cout << str << endl;
  int x = n - str.size();
  if (x < 0) {
    cout << str.substr(-x) << endl;
  } else {
    for (int i = 0; i < x; i++) cout << ch;
    cout << str << endl;
  }
  return 0;
}