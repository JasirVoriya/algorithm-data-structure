#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4;
const int INF = unsigned(-1) >> 1;
int n, m, s, d;
struct Edge
{
    int x, y, cost;
};
Edge es[maxn];
int cost[maxn];
void solove(int s)
{
    for (int i = 0; i < n; i++)
        cost[i] = INF;
    cost[s] = 0;
    while (true)
    {
        bool updata = false;
        for (int i = 0; i < m; i++)
        {
            Edge e = es[i];
            if (cost[e.x] > cost[e.y])
                swap(e.x, e.y);
            if (cost[e.x] != INF)
            {
                if (cost[e.x] + e.cost < cost[e.y])
                {
                    cost[e.y] = cost[e.x] + e.cost;
                    updata = true;
                }
            }
        }
        if (updata == false)
            break;
    }
}
int main(void)
{
    cin >> n >> m >> s >> d;
    for (int i = 0; i < m; i++)
        cin >> es[i].x >> es[i].y >> es[i].cost;
    solove(s);
    cout << cost[d] << endl;
    return 0;
}