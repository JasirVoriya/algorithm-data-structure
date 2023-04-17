#include <bits/stdc++.h>
#define INF ((unsigned(-1)) >> 1)
using namespace std;
#define PI acos(-1.0)
double cake[10100];
int n, f;
bool check(double mid)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        count += (int)(cake[i] / mid);
    }
    if (count >= f)
        return true;
    return false;
}
int main(void)
{
    int t;
    while (cin >> t)
    {
        while (t--)
        {
            double max = 0;
            cin >> n >> f;
            f++;
            for (int i = 0; i < n; i++)
            {
                double r;
                cin >> r;
                cake[i] = PI * r * r;
                max = max - cake[i] >= 1e-7 ? max : cake[i];
            }
            double l = 0, r = max, mid = (l + r) / 2;
            double ans = 0;
            for(int i=0;i<200;i++)
            {
                //cout << ans << endl;
                if (check(mid))
                {
                    ans = mid;
                    l = mid;
                }
                else
                    r = mid;
                mid = (l + r) / 2.0;
            }
            printf("%.6lf\n", ans);
        }
    }
    return 0;
}