#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int const MAX_N = 1e4 + 5;
bool line[MAX_N][MAX_N];
bool red[MAX_N];
ll arr[MAX_N];
bool is_prime(ll num) {
    if (num <= 1) return false;
    double x = sqrt(num);
    for (int i = 2; i <= x; i++) {
        if (num % i == 0) return false;
    }
    return true;
}
int ans = 0, cnt = 0, n;
void solve(int a, int b) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (line[i][j] && red[i] == false && red[j] == false) {
                if (is_prime(arr[i] + arr[j])) {
                    cnt++;
                    ans = max(ans, cnt);
                    // 染i or 染j？
                    red[i] = true;
                    solve(0, 0);
                    red[i] = false;

                    red[j] = true;
                    solve(0, 0);
                    red[j] = false;
                          
                    cnt--;
                    goto end;
                }
            }
        }
    }
    end:;
}
int main(void) {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    for (int i = 0, u, v; i < n - 1; i++) {
        cin >> u >> v;
        line[u][v] = line[v][u] = true;
    }
    solve(0, 0);
    cout << ans << endl;
    return 0;
}