#include <bits/stdc++.h>
using namespace std;
string str;
const int maxn = 1e3 + 5;
int vis[maxn][maxn];
int solove(int i, int j)
{
    if (i >= j)
        return 0;
    if (vis[i][j] != -1)
        return vis[i][j];
    if (str[i] != str[j])
        return vis[i][j] = min(solove(i + 1, j) + 1, solove(i, j - 1) + 1);
    else
        return vis[i][j] = solove(i + 1, j - 1);
}
int main(void)
{
    memset(vis, -1, sizeof(vis));
    cin >> str;
    int i = 0, j = str.size() - 1;
    int ans = 0;
    cout << solove(i, j);
    return 0;
}