#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAX_N = 1e6 + 5;
ll arr[MAX_N];
ll pre[MAX_N];
int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        pre[i] = pre[i - 1] + arr[i];
    }
    int x, y;
    cin >> x >> y;
    if (x > y)swap(x, y);
    ll a = pre[y - 1] - pre[x - 1];//正面走
    ll b = pre[n] - a;//反面走
    // cout << a << " " << b << endl;
    cout << min(a, b) << endl;
    return 0;
}
// 64 位输出请用 printf("%lld")