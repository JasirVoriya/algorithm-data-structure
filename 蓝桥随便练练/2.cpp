#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    int n, a[3];
    cin >> n >> a[0] >> a[1] >> a[2];
    sort(a, a + 3);
    int maxn = n / a[0];
    int ans = 0;
    for (int x = 0; x <= maxn; x++)
    {
        for (int y = 0; y <= maxn - x; y++)
        {
            if (a[0] * x + a[1] * y > n)
                break;
            if ((n - (a[0] * x + a[1] * y)) % a[2] == 0)
            {
                int z = (n - (a[0] * x + a[1] * y)) / a[2];
                ans = max(ans, x + y + z);
            }
        }
    }
    cout << ans << endl;
    return 0;
}