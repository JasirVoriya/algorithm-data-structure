#include <cstdio>
#include <cstring>
#include<bits/stdc++.h>
using namespace std;
const int maxn = 505;
int cost[maxn][maxn];
int main(void)
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n, m, w;
        scanf("%d%d%d", &n, &m, &w);
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
                cost[i][j] = 10005;
            cost[i][i] = 0;
        }
        //输入正边
        for (int i = 0, x, y, c; i < m; i++)
        {
            scanf("%d%d%d", &x, &y, &c);
            if (c < cost[x][y])
                cost[x][y] = cost[y][x] = c;
        }
        //输入负边
        for (int i = 0, x, y, c; i < w; i++)
        {
            scanf("%d%d%d", &x, &y, &c);
            if (-c < cost[x][y])
                cost[x][y] = -c;
        }
        for (int k = 1; k <= n; k++)
            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= n; j++)
                    if (cost[i][j] > cost[i][k] + cost[k][j])
                        cost[i][j] = cost[i][k] + cost[k][j];
                if (cost[i][i] < 0)
                {
                    puts("YES");
                    goto end;
                }
            }
        puts("NO");
    end:;
    }
    return 0;
}