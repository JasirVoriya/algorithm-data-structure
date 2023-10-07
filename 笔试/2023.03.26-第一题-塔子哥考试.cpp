#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int max_n = 1e4 + 5;
string cho[max_n], ans[max_n];
int check(string a, string b) {
  if (a == b) return 3;
  for (auto i : a) {
  	if(b.find_first_of(i)==string::npos)return 0;
  }
  return 1;
}
int main(void) {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> cho[i];
  int sc = 0;
  for (int i = 0; i < n; i++) {
    cin >> ans[i];
    sc += check(cho[i], ans[i]);
  }
  cout << sc << endl;
  return 0;
}