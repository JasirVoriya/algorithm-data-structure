#include <bits/stdc++.h>
using namespace std;
double max(double a, double b)
{
    return a > b ? a : b;
}
struct obj
{
    int s;
    double p;
};
int main(void)
{
    double t;
    int v, k;
    obj a[110];
    double dp[110000] = {0};
    cin >> t >> k;
    v = t * 100;
    for (int i = 1; i <= k; i++)
    {
        cin >> t >> a[i].p;
        a[i].s = t * 100;
    }

    for (int i = 1; i <= k; i++)
        for (int j = v; j > 0; j--)
            if (j >= a[i].s)
                dp[j] = max(dp[j], dp[j - a[i].s] + a[i].p);

    printf("%lf\n", dp[v]);
    return 0;
}