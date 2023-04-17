#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAX_N = 3e7 + 5;
int prime[MAX_N];
void init()
{
    for (ll i = 2; i < MAX_N; i++) {
        if (prime[i] == 0)
            for (ll j = i * i; j < MAX_N; j += i) {
                // cout << "A" << endl;
                if (prime[j] == 0)
                    prime[j] = i;
            }
    }
}
int main(void)
{
    init();
    ll n;
    cin >> n;
    ll ans = 0;
    for (ll i = 2; i <= n; i++) {
        if (i % 2 == 0)
            ans += 2;
        else if (prime[i] == 0)
            ans += i;
        else
            ans += prime[i];
    }
    cout << ans << endl;
    return 0;
}