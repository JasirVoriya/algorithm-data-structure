#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1010;
int a[maxn], n;
int dp[maxn];
int fun(int i)
{
    int ans = 1;
    for (int j = i - 1; j >= 1; j--)
    {
        if (a[i] >= a[j])
            ans = max(ans, dp[i] + dp[j]);
    }
    return dp[i] = ans;
}
int solove()
{
    for (int i = 1; i <= n; i++)
        dp[i] = 1;
    int ans = 0;
    for (int i = 2; i <= n; i++)
    {
        ans = max(ans, fun(i));
    }
    return ans;
}
int main(void)
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    cout << solove() << endl;
    return 0;
}