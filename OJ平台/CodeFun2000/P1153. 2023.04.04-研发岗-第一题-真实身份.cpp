#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int max_n = 1e+5;
int main() {
  int n, q;
  string str;
  cin >> n >> str >> q;
  while (q--) {
    int x, y;
    cin >> x >> y;
    x--,y--;
    char cor = str[x] == 'H' ? 'H' : 'L';
    if (str[y] == cor)
      cout << "honester" << endl;
    else
      cout << "liar" << endl;
  }
  return 0;
}