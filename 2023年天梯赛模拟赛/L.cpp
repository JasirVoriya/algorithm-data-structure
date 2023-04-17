#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unordered_set<int> USI;
typedef unordered_set<string> USS;
const int maxn = 1e2 + 5;
int arr[maxn];
map<string, string> x;
map<string, int> y;
map<string, USS> z;
bool is_num(string& str) {
  for (auto c : str) {
    if (!(c >= '0' && c <= '9')) return false;
  }
  return true;
}
int Q(string& s) {
  //先查直属病人
  int sum = y[s];
  //查底下的分部
  for (string str : z[s]) sum += Q(str);
  return sum;
}
int main(void) {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    string a, b;
    cin >> a >> b;
    if (is_num(a)) {
      //构造老人和机构的关系
      //老人a->机构b
      x[a] = b;
      // 机构b人数++
      y[b]++;
    } else {
      //机构和机构的关系
      if (z.count(b) == 0) z[b] = USS();
      // 机构a->机构b
      z[b].insert(a);
    }
  }
  char a;
  while (cin >> a, a != 'E') {
    string id, s;
    if (a == 'T') {
      //如果 指令 为 T，则表示有老人要入院或转院
      cin >> id >> s;
      y[s]++;
      if (x.count(id)) {
        string name = x[id];
        y[name]--;
        x.erase(id);
      }
      x[id] = s;
    } else if (a == 'Q') {
      cin >> s;
      cout << Q(s) << endl;
    }
  }
  return 0;
}