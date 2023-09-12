#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int n, k;
int a[maxn];
int vis[maxn];
int fun(int i)
{
    if (vis[i] != -1)
        return vis[i];
    if (i >= n)
        return 0;
    if (i == n - 2)
        return vis[i] = abs(a[i] - a[i + 1]);
    return vis[i] = min(abs(a[i] - a[i + 1]) + fun(i + 1), abs(a[i] - a[i + 2]) + fun(i + 2));
}
int main(void)
{
    memset(vis, -1, sizeof(vis));
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout << fun(0) << endl;
    return 0;
}