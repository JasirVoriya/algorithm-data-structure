#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> PII;
typedef unordered_set<int> USI;
#define US unordered_set
#define UM unordered_map
const int maxn = 1e3 + 5;
const int inf = 0x3f3f3f3f;
// id->资产
UM<int, PII> ps;
// id->家庭成员id
UM<int, USI *> hs;
struct node {
  int id, p;
  double cnt, area;
  bool operator<(const node &n) {
    if (this->area != n.area) return this->area > n.area;
    return this->id < n.id;
  }
};
vector<node> arr;
int main(void) {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    vector<int> ids(2);
    int id, k;
    cin >> id >> ids[0] >> ids[1] >> k;
    if (hs.count(id) == 0) {
      hs[id] = new USI;
      hs[id]->insert(id);
    }
    USI *hx = hs[id];
    //输入孩子id
    while (k--) {
      int cid;
      cin >> cid;
      ids.push_back(cid);
    }
    //输入资产
    int cnt, area;
    cin >> cnt >> area;
    ps[id] = PII(cnt, area);

    for (int i : ids) {
      if (i == -1) continue;
      //属于一个家庭
      if (hx->count(i)) continue;
      if (hs.count(i) == 0) {
        hx->insert(i);
        // i索引新家庭
        hs[i] = hx;
      } else {
        //合并两个家庭
        hx->insert(hs[i]->begin(), hs[i]->end());
        //老家庭所有成员索引新家庭
        for (int num : *hs[i]) hs[num] = hx;
      }
    }
  }
  //家庭去重
  US<USI *> uhs;
  for (auto h : hs) {
    uhs.insert(h.second);
  }
  cout << uhs.size() << endl;
  for (USI *h : uhs) {
    int id = inf, cnt = 0, area = 0;
    for (int i : *h) {
      if (ps.count(i)) {
        cnt += ps[i].first;
        area += ps[i].second;
      }
      id = min(i, id);
    }
    arr.push_back(node());
    arr.back().id = id;
    arr.back().p = h->size();
    arr.back().cnt = 1.0 * cnt / h->size();
    arr.back().area = 1.0 * area / h->size();
  }
  sort(arr.begin(), arr.end());
  for (node n : arr) {
    printf("%04d %d %.3lf %.3lf\n", n.id, n.p, n.cnt, n.area);
  }
  return 0;
}