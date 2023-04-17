#include <bits/stdc++.h>
#define INF ((unsigned(-1)) >> 1)
using namespace std;
const int maxn = 10010;
int n, k;
double L[maxn];
bool check(double ans)
{
    int count = 0;
    for (int i = 0; i < n; i++)
        count += (int)L[i] / (int)ans;
    if (count >= k)
        return true;
    return false;
}
int main(void)
{
    while (cin >> n >> k)
    {
        double l = 0, r = INF, mid = (l + r) / 2, ans = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> L[i];
            L[i] *= 100;
        }
        while (l <= r)
        {
            if (check(mid))
            {
                ans = mid;
                l = mid + 1;
            }
            else
                r = mid - 1;
            mid = (l + r) / 2;
        }
        printf("%.2lf\n", ans / 100);
    }
    return 0;
}