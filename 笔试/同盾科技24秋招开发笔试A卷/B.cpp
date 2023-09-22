#include <bits/stdc++.h>
using namespace std;
const int max_n = 2e4 + 5;
int dp[max_n];
int main() {
    int v, n;
    cin >> v >> n;
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        for (int j = v; j - x >= 0; j--) {
            dp[j] = max(dp[j], dp[j - x] + x);
        }
    }
    cout << v - dp[v] << endl;
}
// 64 位输出请用 printf("%lld")