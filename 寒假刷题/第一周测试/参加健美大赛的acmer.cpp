#include <bits/stdc++.h>
using namespace std;
const int maxn = 6000000;
int a[maxn];
int n, m;
bool check(int mid)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        count += a[i] / mid + (a[i] % mid !=0);
    }
    if (count > m)
        return true;
    else
        return false;
}
int main(void)
{
    while (cin >> n >> m)
    {
        if (n == -1 && m == -1)
            break;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        int l = 0, r = 10000000, mid = l + r >> 1;
        int ans = 0;
        while (l <= r)
        {
            if (check(mid))
            {
                ans = mid;
                l = mid + 1;
            }
            else
                r = mid - 1;
            mid = l + r >> 1;
        }
        cout << l << endl;
    }
    return 0;
}