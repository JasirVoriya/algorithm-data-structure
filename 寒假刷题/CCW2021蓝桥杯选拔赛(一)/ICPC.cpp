#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int main(void)
{
    long long q;
    cin >> q;
    while (q--)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        ll ans = min(min(a, b), c);
        a -= ans, b -= ans, c -= ans;
        if (a < b)
            swap(a, b);
        c += a - b;
        a = b;
        ans += min(b, c);
        a -= min(b, c), b -= min(b, c), c -= min(b, c);
        ans += (a + b) / 3;
        cout << ans << endl;
    }

    return 0;
}