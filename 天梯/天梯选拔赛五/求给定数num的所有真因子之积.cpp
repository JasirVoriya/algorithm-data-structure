#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll Pow(ll x, ll n)
{
    ll ans = 1;
    while (n)
    {
        if (n & 1)
            ans *= x;
        n >>= 1;
        x *= x;
    }
    return ans;
}
ll fun(ll n)
{
    ll cnt = 0;
    ll i = 2;
    while (i * i < n)
    {
        if (n % i == 0)
            cnt++;
        i++;
    }
    if (i * i == n)
        return Pow(n, cnt) * i;
    return Pow(n, cnt);
}
int main(void)
{
    ll n;
    cin >> n;
    cout << fun(n) << endl;
    return 0;
}