#include <stdio.h>
int max(int a, int b)
{
    return a > b ? a : b;
}
int a[30], v, n;
int fun(int i, int v)
{
    if (i == n)
        return 0;
    if (v < a[i])
        return fun(i + 1, v);
    return max(fun(i + 1, v), fun(i + 1, v - a[i]) + a[i]);
}
int main(void)
{
    scanf("%d%d", &v, &n);
    for (int i = 0; i < n; i++)
        scanf("%d", a + i);
    printf("%d\n", v - fun(0, v));
    return 0;
}