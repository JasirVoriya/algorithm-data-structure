#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000;
int c[maxn], v[maxn];
int n, s;
int dp[maxn][maxn];
int max(int a, int b)
{
    return a > b ? a : b;
}
int fun(int i, int s)
{
    if (i == n)
        return 0;
    if (dp[i][s])
        return dp[i][s];
    if (c[i] > s)
        return dp[i][s] = fun(i + 1, s);
    return dp[i][s] = max(fun(i + 1, s), fun(i + 1, s - c[i]) + v[i]);
}
int main(void)
{
    int t;
    cin>>t;
    while (t--)
    {
        memset(dp,0,sizeof(dp));
        cin >> n >> s;
        for (int i = 0; i < n; i++)
            cin >> v[i];
        for (int i = 0; i < n; i++)
            cin >> c[i];
        cout << fun(0, s) << endl;
    }
    return 0;
}