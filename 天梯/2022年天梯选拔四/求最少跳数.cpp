#include <bits/stdc++.h>
#define PI acos(-1)
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int MAX_N = 1e6;
bool vis[MAX_N];
using namespace std;
struct node {
    int x, step;
    node(int x, int s)
        : x(x)
        , step(s)
    {
    }
};
int main(void)
{
    int n, s, d;
    cin >> n >> s >> d;
    map<int, unordered_set<int>> m;
    for (int i = 1, v1, v2; i <= n; i++) {
        cin >> v1 >> v2;
        if (m.count(v1) == 0) {
            m[v1] = unordered_set<int>();
        }
        if (m.count(v2) == 0) {
            m[v2] = unordered_set<int>();
        }
        m[v1].insert(v2);
        m[v2].insert(v1);
    }
    queue<node> que;
    que.push(node(s, 0));
    vis[s] = true;
    while (que.size()) {
        node nd = que.front();
        que.pop();
        if (nd.x == d) {
            cout << nd.step << endl;
            return 0;
        }
        for (auto it = m[nd.x].begin(); it != m[nd.x].end(); it++) {
            if (vis[*it] == false) {
                que.push(node(*it, nd.step + 1));
                vis[*it] = true;
            }
        }
    }
    return 0;
}