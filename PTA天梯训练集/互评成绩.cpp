#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 5;
double score[maxn];
bool cmp(double a, double b)
{
    return a - b >= 1e-6;
}
int main(void)
{
    int n, m, k;
    cin >> n >> k >> m;
    for (int i = 0, x; i < n; i++)
    {
        cin >> x;
        int min_x = x, max_x = x, sum = x;
        for (int i = 1, x; i < k; i++)
        {
            cin >> x;
            sum += x;
            if (x < min_x)
                min_x = x;
            else if (x > max_x)
                max_x = x;
        }
        sum -= min_x + max_x;
        score[i] = 1.0 * sum / (k - 2);
    }
    sort(score, score + n, cmp);
    printf("%.3lf", score[--m]);
    while (m--)
        printf(" %.3lf", score[m]);
    return 0;
}