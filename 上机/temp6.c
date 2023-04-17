#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int n, *data = NULL;
    scanf("%d", &n);
    data = (int *)malloc(sizeof(int) * (n+1));
    for (int i = 1; i <= n; i++)
        scanf("%d", data + i);
    int i;
    for (i = 1; i <= n; i++)
    {
        if (data[i] <= n && data[data[i]] == i)
            break;
    }
    i <= n ? puts("YES") : puts("NO");
    free(data);
}