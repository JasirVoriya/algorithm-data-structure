#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    int a[110] = {0};
    int n, m, k;
    cin >> n >> m >> k;
    m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int x = 1;
    while (true)
    {
        if (m - x >= 1)
        {
            if (a[m - x] != 0 && a[m - x] <= k)
            {
                // cout << a[m - x] << endl;
                cout << 10 * x << endl;
                return 0;
            }
        }
        if (m + x <= n)
        {
            if (a[m + x] != 0 && a[m + x] <= k)
            {
                // cout << a[m + x] << endl;
                cout << 10 * x << endl;
                return 0;
            }
        }
        x++;
    }
    return 0;
}