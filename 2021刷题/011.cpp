#include <stdio.h>
int main(void)
{
    int i, j, n, t, sum;
    while (scanf("%d", &n),n>0)
    {
        for (i = 0, t = 1; n; n--, i++, t += i)
        {
            for (sum = t, j = 0; j < n; sum += j + 2 + i, j++)
            {
                printf("%d ", sum);
            }
            putchar('\n');
        }
    }
}