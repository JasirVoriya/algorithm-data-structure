#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e2 + 10;
int G[maxn][maxn];
bool vis[maxn][maxn];
int n, m, ans;
int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};
void solove(int x, int y)
{
    if (vis[x][y])
        return;
    vis[x][y] = true;
    ans++;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && G[nx][ny] != 0 && vis[nx][ny] == false)
        {
            solove(nx, ny);
        }
    }
}
int main(void)
{
    int x, y;
    cin >> n >> m >> x >> y;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            scanf("%1d", &G[i][j]);
    ans = 0;
    solove(x, y);
    cout << ans << endl;
    return 0;
}