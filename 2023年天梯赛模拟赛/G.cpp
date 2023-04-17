#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
int main(void) {
  int n;
  cin >> n;
  getchar();
  while (n--) {
    string str;
    cin >> str;
    getline(cin, str);
    if (str.back() != '?') {
      cout << "enen" << endl;
      continue;
    }
    if (str.find_first_of("PTA") != string::npos) {
      cout << "Yes!" << endl;
    } else {
      cout << "No." << endl;
    }
  }
  return 0;
}