#include <bits/stdc++.h>
typedef unsigned long long ull;
#define INF ((unsigned(-1)) >> 1)
const int maxn = 100100;
ull x[maxn];
int n, m;
using namespace std;
bool check(int mid)
{
    int count = 1;
    int begin = 0, end = 1;
    while (end < n)
    {
        while (end < n && x[end] - x[begin] < mid)
            end++;
        if (end < n && x[end] - x[begin] >= mid)
            count++;
        begin = end, end = end + 1;
    }
    if (count >= m)
        return true;
    return false;
}
int main(void)
{
    while (cin >> n >> m)
    {
        for (int i = 0; i < n; i++)
            scanf("%llu", x + i);
        sort(x, x + n);
        int l = 0, r = INF, mid = (l + r) / 2, ans = 0;
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
        cout << ans << endl;
    }
    return 0;
}