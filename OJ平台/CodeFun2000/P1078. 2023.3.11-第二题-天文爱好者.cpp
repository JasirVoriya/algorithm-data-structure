#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int max_n = 1e+5;
pii arr[max_n];
int cnt[max_n];
bool cmp(pii& a, pii& b) {
  if (a.first == b.first) return a.second < b.second;
  return a.first < b.first;
}
int main(void) {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> arr[i].first;
  for (int i = 0; i < n; i++) cin >> arr[i].second;
  return 0;
}