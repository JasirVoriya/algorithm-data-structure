#include <stdio.h>
long long fun(int n)
{
    if (n == 1 || n == 2)
        return 1;
    return fun(n - 1) + fun(n - 2);
}
int main(void)
{
    int n;
    while (~scanf("%d", &n))
    {
        for (int i = 0; i < n; i++)
        {
            printf("0 ");
            for (int j = 1; j <= i; j++)
                printf("%lld %lld ", fun(2*j-1),fun(2*j));
            putchar('\n');
        }
    }
}