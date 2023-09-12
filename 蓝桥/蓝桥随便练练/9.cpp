#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long int ll;
const ll maxn = 1e5 + 10;
ll a[maxn];
ll n, m;
bool check(ll mid)
{
    ll sum = 0;
    ll count = 1;
    // std::cout << "mid:" << mid << std::endl;
    for (int i = 0; i < n; i++)
    {
        if (sum + a[i] > mid)
        {
            // std::cout << " " << sum << std::endl;
            count++;
            sum = a[i];
        }
        else
            sum += a[i];
    }
    // std::cout << " " << sum << std::endl;
    return count <= m;
}
int main(void)
{
    while (~scanf("%lld%lld", &n, &m))
    {
        ll l = 0, r = 0;
        for (ll i = 0; i < n; i++)
            scanf("%lld", a + i), r += a[i], l = max(l, a[i]);
        ll mid = (l + r) / 2;
        ll ans = 0;
        while (l <= r)
        {
            if (check(mid))
                r = mid - 1, ans = mid;
            else
                l = mid + 1;
            mid = (l + r) / 2;
        }
        printf("%lld\n", ans);
    }
    return 0;
}