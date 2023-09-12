#include <stdio.h>
char str[10000 + 100];
int main(void)
{
    int t;
    scanf("%d", &t), getchar();
    while (t--)
    {
        int stone[256] = {0}, i, sign;
        scanf("%s",str);
        for (i = 0; str[i]; i++)
            stone[str[i]]++;
        for (i = sign = 0; i < 256; i++)
        {
            if (stone[i] % 2)
                sign++;
            if (sign > 1)
                break;
        }
        if (i < 256)
            puts("NO");
        else
            puts("YEs");
    }
}