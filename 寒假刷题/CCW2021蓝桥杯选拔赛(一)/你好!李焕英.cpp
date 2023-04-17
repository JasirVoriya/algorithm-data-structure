#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dfs(ll num, ll *a, ll size)
{
    if (size == 0)
        return 0;
    ll sum = 0;
    for (ll i = 0; i < size; i++)
    {
        sum += a[i];
        if (sum > num)
            return 0;
        else if (sum == num)
            return dfs(num, a + i + 1, size - i - 1) + 1;
    }
    return 0;
}
ll solove(ll *a, ll size)
{
    if (size == 0)
        return 0;
    ll num = 0, ans = 0;
    for (ll i = 0; i < size; i++) //保证最低拆成两部分，最后一位不能累加
    {
        num += a[i];                                       //计算前n项和num，然后以num为相同的数字，向后面搜索。
        ans = max(ans, dfs(num, a + i + 1, size - i - 1)); //如果可以拆成若干个num，说明是超级数字
    }
    return ans;
}
int main(void)
{
    ll n;
    ll a[1100];
    scanf("%lld", &n);
    for (ll i = 0; i < n; i++)
        scanf("%lld", a + i);
    cout << solove(a, n);
}