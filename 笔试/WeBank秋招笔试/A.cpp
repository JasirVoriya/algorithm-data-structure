#include <bits/stdc++.h>
using namespace std;
const int max_n = 1e5;
int arr[max_n];
unordered_set<int> s;
int main(void) {
  int n;
  cin >> n;
  for (int i = 1, x; i <= n; i++) {
    cin >> x;
    if (s.count(x)) break;
    s.insert(x);
  }
  cout << s.size() << endl;
  return 0;
}