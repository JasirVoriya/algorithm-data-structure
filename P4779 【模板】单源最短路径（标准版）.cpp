#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;
const int maxn = 1e5 + 5;
const int inf = 0x3f3f3f3f;
vector<PII> arr[maxn];
int dis[maxn];
bool vis[maxn];
void dj(int start) {
  memset(dis, 0x3f, sizeof(dis));
  dis[start] = 0;

  priority_queue<PII, vector<PII>, greater<PII>> que;
  que.push(PII(dis[start], start));

  while (!que.empty()) {
    int u = que.top().second;
    que.pop();
    //会有重复加入的情况，假如被重复加入的节点为A，
    //因为当时节点A还没有被访问，可能是A被其他节点更新过了多次，
	//所以A也被多次加入到优先队列（当时A还没有被访问），这样子队列里面
	//就会存在多个A（每个A到起点的距离不一样），因为是优先队列，所以先取出来的
	//距离肯定是最小的（取出最小A的时候，标记A被访问），之后如果再次取到A，
	//这个A其实不是最优解了（因为最小的A在它之前已经被取出过了），所以就跳过
    if (vis[u]) continue;
    vis[u] = true;
    for (auto &edge : arr[u]) {
      int v = edge.first, w = edge.second;
      if (dis[v] > dis[u] + w) {
        dis[v] = dis[u] + w;
        que.push(PII(dis[v], v));
      }
    }
  }
}
int main(void) {
  int n, m, s;
  cin >> n >> m >> s;
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    arr[u].push_back(PII(v, w));
  }
  dj(s);
  for (int i = 1; i <= n; i++) {
    cout << dis[i] << " ";
  }
  return 0;
}