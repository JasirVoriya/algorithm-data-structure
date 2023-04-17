#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int things[maxn][3];
int vis[maxn][3];
int n;
int fun(int height, int flag)
{
    if (height == n)
        return 0;
    if (vis[height][flag] != 0)
        return vis[height][flag];
    int ans = 0;
    for (int i = 0; i < 3; i++)
        if (i != flag)
            ans = max(ans, things[height][i] + fun(height + 1, i));
    return vis[height][flag] = ans;
}
int main(void)
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> things[i][0] >> things[i][1] >> things[i][2];
    int ans = 0;
    for (int i = 0; i < 3; i++)
    {
        ans = max(ans, fun(0, i));
    }
    cout << ans << endl;
    return 0;
}