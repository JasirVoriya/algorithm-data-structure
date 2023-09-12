#include <stdio.h>
int main(void)
{
    int n;
    while (~scanf("%d", &n))
    {
        int sign[2] = {0}, i, k;
        for (i = 0; i < n; i++)
        {
            scanf("%d", &k);
            if (!sign[1] || sign[0] == k)
                sign[0] = k, sign[1]++;
            else
                sign[1]--;
        }
        printf("%d\n", sign[0]);
    }
}