#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    int t;
    cin >> t;
    while (t--)
    {
        double a;
        double l, r, n;
        cin >> l >> r >> n;
        double ans = 0;
        n++;
        while (n)
        {
            cin >> a;
            a /= n;
            ans += a * (pow(r, n) - pow(l, n));
            n--;
        }
        printf("%.2lf\n", ans);
    }
    return 0;
}