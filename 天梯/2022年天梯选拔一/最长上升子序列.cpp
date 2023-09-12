#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 1e2;
const int INF = 0x3f3f3f3f;
typedef long long ll;
int main(void)
{
    int arr[MAX_N];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int res[MAX_N] = { 1 };
    int ans = 1;
    for (int i = 1; i < n; i++) {
        res[i] = 1;
        for (int j = i - 1; j >= 0; j--) {
            if (arr[j] < arr[i]) {
                res[i] = max(res[i], res[j] + 1);
                ans = max(ans, res[i]);
            }
        }
    }
    cout << ans;
    return 0;
}