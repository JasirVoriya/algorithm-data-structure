#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 5000 + 5;
const int INF = 0x3f3f3f3f;
typedef long long ll;
bool vis[MAX_N][MAX_N] = { false };
int r, c;
int fun(int x, int y, int dx, int dy)
{
    int ans = 0;
    while (x >= 1 && x <= r && y >= 1 && y <= c && vis[x][y]) {
        x += dx, y += dy;
        ans++;
    }
    if (x >= 1 && x <= r && y >= 1 && y <= c)
        return 0;
    return ans;
}
int solove(int x, int y)
{
    int ans = 0;
    for (int i = x; i <= r; i++) {
        for (int j = y + 1; j <= c; j++) {
            if (vis[i][j]) {
                int dx = i - x, dy = j - y;
                if (x - dx < 1 || y - dy < 1) {
                    ans = max(ans, fun(x, y, dx, dy));
                    ans = max(ans, fun(x, y, dx, -dy));
                }
            }
        }
    }
    return ans;
}
int main(void)
{
    // cout << __gcd(0, 5);
    cin >> r >> c;
    int n;
    cin >> n;
    for (int i = 1, x, y; i <= n; i++) {
        cin >> x >> y;
        vis[x][y] = true;
    }
    int ans = 0;
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            if (vis[i][j]) {
                ans = max(ans, solove(i, j));
            }
        }
    }
    cout << ans << endl;
    return 0;
}