#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
#define INF ((unsigned(-1)) >> 1)
using namespace std;
const int maxn = 100100;
ll x[maxn];
bool cmp(ll &a, ll &b)
{
    return b < a;
}
int main(void)
{
    ll n;
    cin >> n;
    for (ll i = 1; i <= n; i++)
        scanf("%lld", x + i);
    sort(x + 1, x + n + 1, cmp);
    ll size = n * (n - 1) / 2;
    ll ans = size / 2;
    if (size % 2 == 1)
        ans++;
    ll i = 1, a = n - 1, b = n - 1;
    while (i * (a + b) / 2 < ans)
        i++, b--;
    //循环结束，i是ans那行的高度，b是第i行的元素。
    //所以我们推到ans的下一层。
    i--, b++;
    ll j = 1;
    while (i * (a + b) / 2 + j != ans)
        j++;
    i++;
    j += i;
    cout << "i: " << i << " j: " << j << endl;
    printf("%lld\n", x[i] - x[j]);
    return 0;
}