#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 1100;
int main(void)
{
    int a[maxn];
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        sort(a + 1, a + n + 1);
        int ans = 0;
        while (n > 3)
        {
            ans += min(2 * a[1] + a[n] + a[n - 1], a[1] + 2 * a[2] + a[n]);
            n -= 2;
        }
        if (n == 1)
            ans += a[1];
        else if (n == 2)
            ans += a[2];
        else
            ans += a[1] + a[2] + a[3];
        cout << ans << endl;
    }
    return 0;
}