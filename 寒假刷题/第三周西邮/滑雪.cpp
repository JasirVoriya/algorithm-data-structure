#include <cstdio>
#include <queue>
using namespace std;
const int maxn = 120;
int vis[maxn][maxn];
int dp[maxn][maxn];
int dx[4] = { -1, 0, 1, 0 }, dy[4] = { 0, 1, 0, -1 };
int r, c;
struct node {
    int x, y, step;
    node(int x = 0, int y = 0, int step = 0)
    {
        this->x = x;
        this->y = y;
        this->step = step;
    }
};
int solove(int x, int y)
{
    if (vis[x][y] != 0)
        return vis[x][y];
    int ans = 1;
    queue<node> que;
    que.push(node(x, y, 1));
    node temp;
    while (que.size()) {
        temp = que.front(), que.pop();
        int nx, ny, ns;
        for (int i = 0; i < 4; i++) {
            nx = temp.x + dx[i], ny = temp.y + dy[i];
            if (nx >= 1 && nx <= r && ny >= 1 && ny <= c && dp[nx][ny] < dp[temp.x][temp.y]) {
                if (vis[nx][ny] != 0) {
                    ns = temp.step + vis[nx][ny];
                    ans = max(ans, ns);
                } else {
                    ns = temp.step + 1;
                    que.push(node(nx, ny, ns));
                }
            }
        }
    }
    return vis[x][y] = max(ans, temp.step);
}
int main(void)
{
    //freopen("input.txt", "r", stdin);
    scanf("%d%d", &r, &c);
    for (int i = 1; i <= r; i++)
        for (int j = 1; j <= c; j++)
            scanf("%d", &dp[i][j]);
    int ans = 0;
    for (int i = 1; i <= r; i++)
        for (int j = 1; j <= c; j++)
            ans = max(ans, solove(i, j));
    printf("%d\n", ans);
    return 0;
}