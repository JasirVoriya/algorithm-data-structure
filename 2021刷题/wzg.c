#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main()
{
    int i, j = 0, k = 0, l = 0, m = 1;
    char a[100000], x[10000], y[10000], z[10000];
    while (gets(a))
    {
        i = j = l = k = 0;
        while (a[i])
        {
            if (isalpha(a[i]))
                x[k++] = a[i++];
            else if (isalnum(a[i]))
                y[j++] = a[i++];
            else
                z[l++] = a[i++];
        }
        x[k] = y[j] = z[l] = '\0';
        printf("Case #%d:\n", m);
        printf("%s\n%s\n%s\n", x, y, z);
        m++;
    }
}
