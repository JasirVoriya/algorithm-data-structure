#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> PII;
typedef unordered_set<int> USI;
#define US unordered_set
#define UM unordered_map
const int maxn = 1e4 + 5;
const int inf = 0x3f3f3f3f;
int fa[maxn];
PII p[maxn];
USI ids;
struct node {
  int id, p;
  double cnt, area;
  bool operator<(const node& n) {
    if (this->area != n.area) return this->area > n.area;
    return this->id < n.id;
  }
};
void clean() {
  for (int i = 0; i < maxn; i++) fa[i] = i;
}
int find(int x) {
  while (x != fa[x]) x = fa[x] = fa[fa[x]];
  return x;
}
void add(int x, int y) { fa[find(x)] = find(y); }

int main(void) {
  clean();
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int id, k;
    vector<int> cids(2);
    cin >> id >> cids[0] >> cids[1] >> k;
    ids.insert(id);
    while (k--) {
      int x;
      cin >> x;
      cids.push_back(x);
    }
    cin >> p[id].first >> p[id].second;
    for (int num : cids) {
      if (num == -1) continue;
      add(id, num);
      ids.insert(num);
    }
  }
  UM<int, USI> home;
  for (int id : ids) {
    int r = find(id);
    if (home.count(r) == 0) home[r] = USI();
    home[r].insert(id);
  }
  cout << home.size() << endl;
  vector<node> ans;
  for (auto h : home) {
    int id = inf, cnt = 0, area = 0;
    for (int i : h.second) {
      id = min(id, i);
      cnt += p[i].first;
      area += p[i].second;
    }
    ans.push_back(node());
    ans.back().id = id;
    ans.back().p = h.second.size();
    ans.back().cnt = 1.0 * cnt / h.second.size();
    ans.back().area = 1.0 * area / h.second.size();
  }
  sort(ans.begin(), ans.end());
  for (auto n : ans) {
    printf("%04d %d %.3lf %.3lf\n", n.id, n.p, n.cnt, n.area);
  }
  return 0;
}