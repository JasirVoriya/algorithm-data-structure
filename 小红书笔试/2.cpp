#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int const MAX_N = 5e2 + 5;
ll dp[MAX_N][MAX_N];
int main(void) {
    int n;
    cin >> n;
    int T, H;
    cin >> T >> H;
    for (int i = 0; i < n; i++) {
        int t, h, a;
        cin >> t >> h >> a;
        for (int j = T; j >= t; j--) {
            for (int k = H; k >= h; k--) {
                dp[j][k] = max(dp[j][k], dp[j - t][k - h] + a);
            }
        }
    }
    cout << dp[T][H] << endl;
    return 0;
}