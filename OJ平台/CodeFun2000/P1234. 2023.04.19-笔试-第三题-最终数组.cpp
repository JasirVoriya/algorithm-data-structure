#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int max_n = 1e3 + 5;
int main() {
  unordered_map<string, vector<int>> dict;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    string str;
    cin >> str;
    dict[str].push_back(i);
    if (str == "NORTH" || str == "SOUTH") {
      if (dict["NORTH"].size() && dict["SOUTH"].size()) {
        dict["NORTH"].pop_back();
        dict["SOUTH"].pop_back();
      }
    } else {
      if (dict["WEST"].size() && dict["EAST"].size()) {
        dict["WEST"].pop_back();
        dict["EAST"].pop_back();
      }
    }
  }
  vector<pair<int, string>> arr;
  for (auto &it : dict) {
    for (auto i : it.second) {
      arr.push_back({i, it.first});
    }
  }
  sort(arr.begin(), arr.end());
  for (auto &it : arr) cout << it.second << " ";
  cout << endl;
  return 0;
}