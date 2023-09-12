#include <stdio.h>
unsigned long long ans[100] = {0, 0, 1};
int main(void)
{
    for (int i = 3; i < 100; i++)
        ans[i] = (i - 1) * (ans[i - 1] + ans[i - 2]);
    int t;
    while (~scanf("%d", &t))
    {
        while (t--)
        {
            int n;
            scanf("%d", &n);
            printf("%llu\n", ans[n]);
        }
    }
}