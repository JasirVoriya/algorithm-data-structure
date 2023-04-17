#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6;
int a[maxn], n;
double sum[maxn];
int main(void)
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", a + i);
        sum[i] = sum[i - 1] + a[i];
    }
    double mid = sum[n] / 2;
    auto it = lower_bound(sum + 1, sum + n + 1, mid);
    // cout << mid << ' ' << *it << ' ' << it - sum << endl;
    if (*it == mid)
    {
        cout << it - sum << ' ' << it - sum << endl;
        return 0;
    }
    auto a = it - 1, b = it + 1;
    int sa = *a, sb = sum[n] - *it;
    // cout << sa << ' ' << sb << endl;
    int x = a - sum, y = n - x - 1;
    // cout << x << ' ' << y << endl;
    if (sa <= sb)
        x++;
    else
        y++;
    cout << x << ' ' << y;
    return 0;
}