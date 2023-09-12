#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 1e3;
const int INF = 0x3f3f3f3f;
typedef long long ll;
int arr[MAX_N][MAX_N];
int root[MAX_N];
void init()
{
    for (int i = 0; i < MAX_N; i++) {
        root[i] = i;
        for (int j = 0; j < MAX_N; j++) {
            arr[i][j] = i == j ? 0 : INF;
        }
    }
}
int find(int x)
{
    if (root[x] == x)
        return root[x];
    return root[x] = find(root[x]);
}
void union_set(int x, int y)
{
    root[find(x)] = root[find(y)];
}
bool is_set(int x, int y)
{
    return find(x) == find(y);
}
struct edge {
    int x, y, dis;
    bool operator<(edge& e)
    {
        return this->dis < e.dis;
    }
    edge(int x, int y, int dis)
        : x(x)
        , y(y)
        , dis(dis) {};
};
int main(void)
{
    init(); 
    int m, n;
    cin >> m >> n;
    vector<edge> vec;
    for (int i = 0; i < n; i++) {
        int x, y, dis;
        cin >> x >> y >> dis;
        vec.push_back(edge(x, y, dis));
    }
    sort(vec.begin(), vec.end());
    int ans = 0;
    for (auto e : vec) {
        if (is_set(e.x, e.y) == false) {
            ans += e.dis;
            union_set(e.x, e.y);
        }
    }
    bool success = true;
    for (int i = 2; i <= m; i++) {
        if (is_set(1, i) == false) {
            success = false;
            break;
        }
    }
    if (success)
        cout << ans << endl;
    else
        cout << -1 << endl;
    return 0;
}