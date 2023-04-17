#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 1e3 + 5;
int value[MAX_N], weight[MAX_N];
int dp[MAX_N][MAX_N];
int n, v;
int solve1(int i, int v) {
    if (i == n || v == 0) return 0;
    if (dp[i][v] != -1) return dp[i][v];
    if (v >= weight[i]) {
        return dp[i][v] = max(solve1(i + 1, v - weight[i]) + value[i],
                              solve1(i + 1, v));
    }
    return dp[i][v] = solve1(i + 1, v);
}
int solve2(int v) {
    int ans[MAX_N] = {0};
    for (int i = 0; i < n; i++) {
        // 从大到小遍历，是为了沿用放完第i-1个物品（上一个物品）时的状态
        for (int j = v; j >= weight[i]; j--) {
            ans[j] = max(ans[j], ans[j - weight[i]] + value[i]);
        }
    }
    return ans[v];
}
int main(void) {
    ifstream fin("./test.in");
    cin.rdbuf(fin.rdbuf());
    memset(dp, -1, sizeof(dp));
    cin >> n >> v;
    for (int i = 0; i < n; i++) {
        cin >> weight[i] >> value[i];
    }
    // cout << solve1(0, v) << endl;
    cout << solve2(v) << endl;
    return 0;
}