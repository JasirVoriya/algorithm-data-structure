#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, string> P;
int main(void) {
  int n;
  cin >> n;
  deque<P> boys, girls;
  for (int i = 0; i < n; i++) {
    int sex;
    string name;
    cin >> sex >> name;
    if (sex == 0)
      girls.push_back(P(i, name));
    else
      boys.push_back(P(i, name));
  }
  while (boys.size()) {
    if (boys.front().first < girls.front().first) {
      cout << boys.front().second << " " << girls.back().second << endl;
      boys.pop_front();
      girls.pop_back();
    } else {
      cout << girls.front().second << " " << boys.back().second << endl;
      girls.pop_front();
      boys.pop_back();
    }
  }
  // for (int i = 0; i < n / 2; i++) {
  // if (boys[i].first < girls[i].first)
  // cout << boys[i].second << " " << girls[n / 2 - i - 1].second << endl;
  // else
  // cout << girls[i].second << " " << boys[n / 2 - i - 1].second << endl;
  // }
  return 0;
}