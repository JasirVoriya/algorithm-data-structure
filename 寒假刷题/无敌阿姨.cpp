#include <stdio.h>
#include <string.h>
int main()
{
    char a[1010];
    int i, n, m;
    gets(a);
    int ans = 1;
    int len = strlen(a);
    for (i = 0; i < len - 1; i++)
    {
        int an = 1;
        if (a[i] == a[i + 1]) //偶
            n = i + 1, m = i, an++;
        else
            n = m = i;
        while (--m >= 0 && ++n < len && a[m] == a[n])
            an += 2;
        ans = ans > an ? ans : an;
    }
    printf("%d\n", ans);
}
