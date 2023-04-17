#include <bits/stdc++.h>
using namespace std;
const int maxv = 505;
const int INF = 0x3f3f3f3f3f3f3f3f;
int cost[maxv][maxv];
int path[maxv][maxv];
int n, m, s, d;
int main(void)
{
    while (cin >> n >> m)
    {
        if (n == 0 && m == 0)
            return 0;
        memset(cost, 0x3f, sizeof(cost));
        memset(path, 0, sizeof(path));
        for (int i = 1, x, y, z; i <= m; i++)
        {
            cin >> x >> y >> z;
            path[x][y] = x;
            path[y][x] = y;
            cost[x][x] = cost[y][y] = 0;
            if (z < cost[x][y])
                cost[y][x] = cost[x][y] = z;
        }
        s = 1, d = n;
        for (int k = 1; k <= n; k++)
            cost[s][d] = min(cost[s][d], cost[s][k] + cost[k][d]);
        cout << cost[s][d] << endl;
    }
    return 0;
}