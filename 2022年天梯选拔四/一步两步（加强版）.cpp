#include <bits/stdc++.h>
#define PI acos(-1)
typedef long long ll;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const ll MAX_N = 1e3;
const ll MOD = 1e9 + 7;
using namespace std;
int main(void)
{
    ll n;
    cin >> n;
    ll f1 = 1, f2 = 1, f3 = f1 + f2;
    for (ll i = 1; i <= n; i++) {
        f3 = (f1 + f2) % MOD;
        f1 = f2, f2 = f3;
    }
    cout << f3 << endl;
    return 0;
}