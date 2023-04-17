#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e2 + 5;
typedef pair<int, int> PII;
vector<PII> arr[maxn];
int p[maxn], dis[maxn], pre[maxn];
int cnt[maxn], sum[maxn];
bool vis[maxn];
void dj(int s) {
  memset(dis, 0x3f, sizeof(dis));
  memset(pre, -1, sizeof(pre));
  dis[s] = 0, cnt[s] = 1, sum[s] = p[s];
  priority_queue<PII, vector<PII>, greater<PII>> que;
  que.push(PII(dis[s], s));
  while (!que.empty()) {
    int u = que.top().second;
    que.pop();
    if (vis[u]) continue;
    vis[u] = true;
    for (auto e : arr[u]) {
      int v = e.first, w = e.second;
      if (dis[v] > dis[u] + w) {
        dis[v] = dis[u] + w;
        cnt[v] = cnt[u];
        sum[v] = sum[u] + p[v];
        pre[v] = u;
        que.push(PII(dis[v], v));
        //相等说明有多条距离一样的路径
      } else if (dis[v] == dis[u] + w) {
        cnt[v] += cnt[u];
        if (sum[v] < sum[u] + p[v]) {
          sum[v] = sum[u] + p[v];
          pre[v] = u;
        }
      }
    }
  }
}
int main(void) {
  int n, m, s, d;
  cin >> n >> m >> s >> d;
  for (int i = 0; i < n; i++) cin >> p[i];
  for (int i = 0; i < m; i++) {
    int a, b, x;
    cin >> a >> b >> x;
    arr[a].push_back(PII(b, x));
    arr[b].push_back(PII(a, x));
  }
  dj(s);
  cout << cnt[d] << " " << sum[d] << endl;
  vector<int> path;
  for (int i = d; i != -1; i = pre[i]) path.push_back(i);
  cout << path.back();
  for (int i = path.size() - 2; i >= 0; i--) cout << " " << path[i];
  return 0;
}