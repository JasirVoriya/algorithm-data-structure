#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
ull a[15], b[15];
ull n;
void solove(ull &x, ull &y)
{
    ull nx, ny;
    ull t;
    for (ull i = n - 1; i >= 1; i--)
    {
        nx = b[i] * y;     //新的分子 等于 上一次的分母*b[i]
        ny = a[i] * y + x; //新的分母 等于 上一次的分子+a[i]*上一次的分母
        ull t = __gcd(nx, ny);
        x = nx / t, y = ny / t;
    }
}
int main(void)
{
    ull t;
    cin >> t;
    for (ull j = 1; j <= t; j++)
    {
        cin >> n;
        for (ull i = 1; i <= n; i++)
            cin >> a[i];
        for (ull i = 1; i <= n; i++)
            cin >> b[i];
        ull x = b[n], y = a[n];
        solove(x, y);
        int t = __gcd(x, y);
        cout << "Case #" << j << ": " << x / t << " " << y / t << endl;
    }
    return 0;
}