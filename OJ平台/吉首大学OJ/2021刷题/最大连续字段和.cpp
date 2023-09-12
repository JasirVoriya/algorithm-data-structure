#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;
int a[maxn], b[maxn];
int n;
void fun(int i)
{
    if (i == n)
        return;
    b[i] = max(b[i - 1] + a[i], a[i]);
    fun(i + 1);
}
int main(void)
{
    while (cin >> n)
    {
        memset(b, 0, sizeof(b));
        for (int i = 0; i < n; i++)
            cin >> a[i];
        b[0] = a[0];
        fun(1);
        int ans = 0;
        for (int i = 0; i < n; i++)
            ans = max(ans, b[i]);
        cout << ans << endl;
    }
    return 0;
}