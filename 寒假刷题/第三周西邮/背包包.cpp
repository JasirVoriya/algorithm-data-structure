#include <bits/stdc++.h>
using namespace std;
const int maxn = 1100;
int dp[maxn][maxn];
bool cmp(pair<int, int> &a, pair<int, int> &b)
{
    return a.second > b.second;
}
int main(void)
{
    int t;
    cin >> t;
    int n, V;
    while (t--)
    {
        pair<int, int> obj[maxn];
        memset(dp, 0, sizeof(dp));
        scanf("%d%d", &n, &V);
        for (int i = 0; i < n; i++)
            scanf("%d", &obj[i].first);
        for (int i = 0; i < n; i++)
            scanf("%d", &obj[i].second);
        sort(obj, obj + n, cmp);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j <= V; j++)
            {
                if (j < obj[i].second)
                    dp[i + 1][j] = dp[i][j];
                else
                {
                    dp[i + 1][j] = max(dp[i][j], dp[i][j - obj[i].second] + obj[i].first);
                }
            }
        }
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= V; j++)
                cout << dp[i][j] << ' ';
            cout << endl;
        }
        int ans=dp[n][V];
        while(dp[n][V]==ans)V--;
        V++;
        printf("%d %d\n",ans,V);
    }
    return 0;
}