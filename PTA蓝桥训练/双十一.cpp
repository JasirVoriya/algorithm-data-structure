#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
const ull INF = unsigned(-1) >> 3;
const ull maxn = 1e2 + 10;
ull n, m;

ull dp[maxn][maxn];
int main(void)
{
    while (cin >> n >> m)
    {
        memset(dp, -1, sizeof(dp));
        ull cost[maxn] = {0}, x, y, c;
        for (int i = 0; i < m; i++)
        {
            cin >> x >> y >> c;
            dp[x][y] = dp[y][x] = c;
            dp[x][x] = dp[y][y] = 0;
        }
        for (int k = 0; k < n; k++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cost[i] += dp[i][j];
        int ans = 0;
        for (int i = 1; i < n; i++)
            ans = cost[ans] > cost[i] ? i : ans;
        cout << ans << endl;
    }
    return 0;
}