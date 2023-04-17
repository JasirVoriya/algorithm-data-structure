#include <bits/stdc++.h>
#define PI acos(-1)
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int MAX_N = 1e3;
using namespace std;
bool is_prime(ll x)
{
    if (x < 2)
        return false;
    ll n = sqrt(x);
    for (ll i = 2; i <= n; i++) {
        if (x % i == 0)
            return false;
    }
    return true;
}
int arr[MAX_N];
int n, k;
int res = 0;
void solove(int begin, int cnt, int sum)
{
    if (cnt >= k) {
        res += is_prime(sum);
        return;
    }
    for (int i = begin; i < n; i++) {
        solove(i + 1, cnt + 1, sum + arr[i]);
    }
}
int main(void)
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    solove(0, 0, 0);
    cout << res << endl;
    return 0;
}