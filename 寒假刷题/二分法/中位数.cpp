#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
#define INF ((unsigned(-1)) >> 1)
using namespace std;
const int maxn = 100100;
ll x[maxn];
ll n, size, Count;
bool check(ll mid)
{
    int c = 0;
    for (int i = 1, j = 2; i < n; i++)
    {
        while (j <= n && x[j] - x[i] < mid)
            j++;
        c += j - i - 1; //统计 mid 前面有多少个数
    }
    //cout << "mid: " << mid << " c: " << c << endl;
    if (c < Count)
        return true;
    return false;
}
int main(void)
{
    while (cin >> n)
    {
        for (ll i = 1; i <= n; i++)
            scanf("%lld", x + i);
        sort(x + 1, x + n + 1);
        //
        size = n * (n - 1) / 2;
        Count = (size + 1) / 2;
        //
        ll l = 0, r = x[n] - x[1], mid = l + r >> 1;
        ll ans = 0;
        while (l <= r)
        {
            if (check(mid))
            {
                ans = mid;
                l = mid + 1;
            }
            else
                r = mid - 1;
            mid = l + r >> 1;
        }
        cout << ans << endl;
    }
    return 0;
}