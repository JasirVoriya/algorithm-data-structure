#include <stdio.h>
#include <stdlib.h>
int cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}
int a[10000];
int main(void)
{
    int n;
    while (~scanf("%d", &n))
    {
        for (int i = 0; i < n; i++)
            scanf("%d", a + i);
        qsort(a, n, sizeof(int), cmp);
        for (int i = 0; i < n; i++)
            printf("%d ", a[i]);
        putchar('\n');
    }
}