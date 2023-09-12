#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 1e3 + 5;
int ans[MAX_N];
int weight[MAX_N], value[MAX_N];
int dp[MAX_N][MAX_N];
int N, W;
void solve1() {
    int v, w, s;
    cin >> N >> W;
    for (int i = 0; i < N; i++) {
        cin >> w >> v >> s;
        while (s--) {
            for (int j = W; j >= w; j--) {
                ans[j] = max(ans[j], ans[j - w] + v);
            }
        }
    }
    cout << ans[W] << endl;
}
int main(void) {
    solve1();
    return 0;
}