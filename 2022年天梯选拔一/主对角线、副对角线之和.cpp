#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 1e2;
const int INF = 0x3f3f3f3f;
typedef long long ll;
int main(void)
{
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int x, j = 0; j < n; j++) {
            cin >> x;
            if (i == j || j + i == n - 1)
                ans += x;
        }
    }
    cout << ans;
    return 0;
}