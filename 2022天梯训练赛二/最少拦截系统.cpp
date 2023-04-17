#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 1e2 + 5;
const int INF = 0x3f3f3f3f;
typedef long long ll;
typedef unsigned long long ull;
int main(void)
{
    int n;
    while (cin >> n) {
        int arr[MAX_N] = { 0 };
        bool vis[MAX_N] = { 0 };
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int cnt = n;
        int ans = 0;
        while (cnt) {
            int dis[MAX_N] = { 0 };
            int pre[MAX_N] = { 0 };
            memset(pre, -1, sizeof(int) * MAX_N);
            int tail = -1;
            int len = 0;
            for (int i = 0; i < n; i++) {
                if (vis[i])
                    continue;
                for (int j = i + 1; j < n; j++) {
                    if (vis[j])
                        continue;
                    if (arr[j] < arr[i]) {
                        if (dis[j] < dis[i] + 1) {
                            dis[j] = dis[i] + 1;
                            pre[j] = i;
                            if (dis[j] > len) {
                                tail = j;
                                len = dis[j];
                            }
                        }
                    }
                }
            }
            if (tail == -1) {
                ans += cnt;
                break;
            }
            while (tail != -1) {
                // cout << arr[tail] << "(" << tail << ") ";
                vis[tail] = true;
                tail = pre[tail];
                cnt--;
            }
            // cout << endl;
            ans++;
        }
        cout << ans << endl;
    }
    return 0;
}