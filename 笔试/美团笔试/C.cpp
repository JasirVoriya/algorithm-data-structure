#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MAX_N = 1e3 + 5;
const ll INF = 0x3f3f3f3f;
ll arr[MAX_N][MAX_N];
ll pre[MAX_N][MAX_N];
int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> arr[i][j];
            pre[i][j] = pre[i][j - 1] + pre[i - 1][j] + arr[i][j] - pre[i - 1][j - 1];
        }
    }
    ll a = INF, b = INF;
    for (int i = 1; i <= n; i++) {
        a = min(a, abs((pre[i][m] << 1) - pre[n][m]));
    }
    for (int i = 1; i <= m; i++) {
        b = min(b, abs((pre[n][i] << 1) - pre[n][m]));
    }
    cout << min(a, b) << endl;
    return 0;
}
// 64 位输出请用 printf("%lld")