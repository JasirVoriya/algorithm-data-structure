#include <stdio.h>
int main()
{
    int x, y, m, i;
    int a[1000] = {0};

    scanf("%d", &x);
    while (x--)
    {
        int n = 0, max = 0;
        int b[1000] = {0};
        scanf("%d", &y);
        for (i = 0; i < y; i++)
            scanf("%d", &a[i]);
        for (i = 0; i < y; i++)
        {
            if (a[i] == 8)
            {
                b[n] = b[n] + 1;\
                if (a[i] != 8)
                {
                    n++;
                    continue;
                }
            }
        }
        for (i = 0; i <= n; i++)
        {
            if (b[max] < b[i])
                b[max] = b[i];
        }
        printf("%d", b[max]);
        printf("\n");
    }
}
