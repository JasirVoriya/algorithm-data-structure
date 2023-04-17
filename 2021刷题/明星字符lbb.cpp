//思路清奇，强！
#include <stdio.h>
int main()
{
    char s[100];
    while (gets(s) != NULL)
    {
        int count[256] = {0}, i, max;
        for (i = 0; s[i] != '\0'; i++)
        {
            if (s[i] <= 'Z' && s[i] >= 'A')
                s[i] = s[i] + 32;
            count[s[i]]++;
        }
        max = s[0];
        for (i = 0; i < 256; i++)
        {
            if (count[i] > count[max])
            {
                count[max] = count[i];
                max = i;
            }
        }
        printf("%c %d\n", max, count[max]);
    }
}
