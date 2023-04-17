#include <bits/stdc++.h>
using namespace std;
const int maxv = 505;
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
            for (int i = 1; i <= n; i++)
                for (int j = 1; j <= n; j++)
                {
                    if (cost[i][j] > cost[i][k] + cost[k][j])
                    {
                        path[i][j] = k;
                        cost[i][j] = cost[i][k] + cost[k][j];
                    }
                }
        // cout << "cost:" << endl;
        // for (int i = 1; i <= n; i++)
        // {
        //     for (int j = 1; j <= n; j++)
        //         cout << cost[i][j] << " ";
        //     cout << endl;
        // }
        // cout << "path:" << endl;
        // for (int i = 1; i <= n; i++)
        // {
        //     for (int j = 1; j <= n; j++)
        //         cout << path[i][j] << " ";
        //     cout << endl;
        // }
        for (int i = s, j = d; i != j; j = path[i][j])
            cout << j << " ";
        cout << s << endl;
        cout << cost[s][d] << endl;
    }
    return 0;
}