#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAX_N = 1e9 + 5;
// bool m[MAX_N] = {false};
int main(void)
{
    ll t;
    scanf("%lld", &t);
    map<int, int> m;
    while (t--)
    {
        ll n;
        scanf("%lld", &n);
        // memset(m, 0, sizeof(m));
        m.clear();
        for (ll x, i = 0; i < n; i++)
        {
            scanf("%lld", &x);
            if (m.count(x))
                m.erase(x);
            else
                m[x] = 1;
        }
        cout << m.begin()->first << endl;
    }
    return 0;
}