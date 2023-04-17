#include <bits/stdc++.h>
using namespace std;
const int MAX_W = 5e4 + 5;
int dp[MAX_W];
int main(void)
{
    // 拿和不拿的价值谁更大
    // 利用前i-1个物品拿或不拿的最优状态，
    // 来更新前i个物品拿货不拿的最优状态。
    int N, W;
    cin >> N >> W;
    // 遍历所有物品
    for (int i = 1, w, p, c; i <= N; i++) {
        cin >> w >> p >> c;
        // 遍历背包的所有大小，拿和不拿当前的物品，
        // 来更新放前i个物品，在背包大小为v时的最大价值
        for (int v = W; v > 0; v--) {
            // 遍历当前类型物品的数量
            for (int j = 1; j <= c && j * w <= v; j++) {
                dp[v] = max(dp[v], dp[v - j * w] + j * p);
            }
        }
    }
    cout << dp[W] << endl;
    return 0;
}